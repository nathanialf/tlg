#!/usr/bin/env python3
"""tools/vtable_names.py [--md] [--no-write]: which class each vtable belongs
to, where the executable says so.

The executable is stripped and built without RTTI, so a vtable has no name
of its own. Havok's reflection gives one: each reflected class's static
initializer fills an `hkTypeInfo` record in .bss with six fields, the type
name at +0, the scoped name at +8, the finish and cleanup callbacks at +0x10
and +0x18, the vtable address point (the value a constructed object's vptr
holds, `_ZTV<class> + 0x10`) at +0x20 and the object size at +0x28
(hkTypeInfo in Common/Base/Reflection/hkTypeInfo.h). The initializer gets
the address point one of two ways: a `lea` of the vtable (the block at 0x50f
of FUN_000003f0, an inline finish constructor), or the vptr of a temporary
it constructs on its stack through the class's out-of-line finish
constructor (0x6b757 of FUN_0006b6d0 calls 0x3c540 on `[rbp-0x50]` and
stores `[rbp-0x50]` at +0x20). This tool walks every function of the table
tracking the values RIP-relative `lea`s and immediate `add`s put in
registers and stack slots, follows a finish constructor to the last vtable
it stores in its object (the derived class's, after its bases', Itanium
ABI), and at each store into the +0x20 slot of a record whose +0 slot took
a string writes the row

    <vtable symbol> <vtable address> <class name> typeinfo <store site> [ctor <function>]

to config/vtables.<slug>.txt, where the vtable address is the start of the
`_ZTV` object (address point - 0x10), the symbol is the name mangled as the
compiler will reference it from a constructor's vptr store, and `ctor`
names the finish constructor the vptr was read through. A type name the
tool cannot mangle (a template) is listed with `?` in place of the symbol;
a name two sites give different vtables, and a registration whose
constructor's vptr the walk cannot find, are listed in the comment block and
not written.

The rows are facts about the base and are regenerated, never edited. The
gate reads them (tools/base_elf.py `address_of`): a relocation against
`_ZTV<class>` resolves to the row's address, and the base's operand must
agree, like a `D_<hex>` label (docs/DECISIONS.md D12).
"""
from __future__ import annotations

import argparse
import re
import struct
import sys
from collections import Counter, defaultdict
from pathlib import Path

from capstone import CS_ARCH_X86, CS_MODE_64, Cs
from capstone.x86 import X86_OP_IMM, X86_OP_MEM, X86_OP_REG, X86_REG_RIP

REPO_ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO_ROOT / "tools"))
from base_elf import BaseElf  # noqa: E402
from tlg_version import config_path  # noqa: E402

CALLER_SAVED = {"rax", "rcx", "rdx", "rsi", "rdi", "r8", "r9", "r10", "r11"}
NAME_RE = re.compile(r"^[A-Za-z_][A-Za-z0-9_]*(::[A-Za-z_][A-Za-z0-9_]*)*$")


def mangle_vtable(name: str) -> str | None:
    """`_ZTV` + the Itanium encoding of a plain or namespace-qualified class
    name; None for anything else (templates, operators)."""
    if not NAME_RE.match(name):
        return None
    parts = name.split("::")
    enc = "".join(f"{len(p)}{p}" for p in parts)
    return "_ZTV" + (enc if len(parts) == 1 else f"N{enc}E")


def c_string(elf: BaseElf, va: int, limit: int = 256) -> str | None:
    try:
        raw = elf.read(va, limit)
    except ValueError:
        return None
    end = raw.find(b"\0")
    if end <= 0:
        return None
    s = raw[:end]
    if not all(0x20 <= c < 0x7F for c in s):
        return None
    return s.decode()


class Walker:
    """Register and stack-slot values along one path of a function."""

    def __init__(self, elf: BaseElf):
        self.elf = elf
        self.md = Cs(CS_ARCH_X86, CS_MODE_64)
        self.md.detail = True
        self.text = elf.text_bytes()
        self.text_va = elf.text["vaddr"]
        relro = next(p for p in elf.loaded_segments() if p["type"] == elf.PT_SCE_RELRO)
        self.relro = (relro["vaddr"], relro["vaddr"] + relro["filesz"])
        rw = [p for p in elf.loaded_segments() if p["flags"] & 2]
        self.bss = (max(p["vaddr"] + p["filesz"] for p in rw), max(p["vaddr"] + p["memsz"] for p in rw))
        self.funcs = {a: (sz, n) for a, sz, n in elf.functions}
        self._vptr: dict[int, int | None] = {}
        self._hkclass: dict[int, str] | None = None
        self.parents: dict[int, int] = {}

    def in_relro(self, v: int) -> bool:
        return self.relro[0] <= v < self.relro[1]

    def insns(self, addr: int):
        sz = self.funcs[addr][0]
        lo = addr - self.text_va
        return {i.address: i for i in self.md.disasm(self.text[lo:lo + sz], addr)}

    def vptr_of(self, ctor: int) -> int | None:
        """The vtable address point a finish constructor leaves in its object:
        the last store of a read-only-data address into `[this]` along the
        fall-through path (the derived class's vptr follows its bases')."""
        if ctor not in self._vptr:
            seq = self._walk(ctor)
            self._vptr[ctor] = seq[-1] if seq else None
        return self._vptr[ctor]

    def vptr_stores(self, fn: int) -> set[int]:
        """Every vtable address point the function stores into its `this`
        object along the fall-through path (a constructor: its bases' then
        its own)."""
        return set(self._walk(fn, fresh=True))

    def _walk(self, ctor: int, fresh: bool = False) -> list[int]:
        """The vtable address points stored into `this` along the fall-through
        path. With `fresh`, the pointer a call returns (`rax`) is an object
        too: a create function news its object and constructs it inline
        (`call operator new; mov [rax], vptr`), the form D14 rows cite when
        a class has no constructor of its own. vptr_of keeps `this` alone, so
        a constructor that news a member after its own vptr store still
        reports its own vtable last."""
        if ctor not in self.funcs:
            return []
        ins_by = self.insns(ctor)
        this = {"rdi"}
        regs: dict[str, int] = {}
        seq: list[int] = []
        pc, steps = ctor, 0
        while pc in ins_by and steps < 2000:
            steps += 1
            ins = ins_by[pc]
            pc = ins.address + ins.size
            ops = ins.operands
            m = ins.mnemonic
            if m == "ret":
                break
            if m == "jmp":
                if ops[0].type == X86_OP_IMM and ctor <= ops[0].imm < ctor + self.funcs[ctor][0]:
                    pc = ops[0].imm
                    continue
                break                                   # a tail call: the callee's stores are not seen
            if m.startswith("j") or m in ("nop", "push", "pop", "cmp", "test"):
                continue
            if m == "call":
                for r in CALLER_SAVED:
                    regs.pop(r, None)
                    this.discard(r)
                if fresh:
                    this.add("rax")
                continue
            if len(ops) == 2 and ops[0].type == X86_OP_REG:
                d = ins.reg_name(ops[0].reg)
                src = ops[1]
                if m == "mov" and src.type == X86_OP_REG:
                    sname = ins.reg_name(src.reg)
                    if sname in this:
                        this.add(d)
                    else:
                        this.discard(d)
                    if sname in regs:
                        regs[d] = regs[sname]
                    else:
                        regs.pop(d, None)
                elif m == "lea" and src.type == X86_OP_MEM and src.mem.base == X86_REG_RIP:
                    regs[d] = ins.address + ins.size + src.mem.disp
                    this.discard(d)
                elif m == "lea" and src.type == X86_OP_MEM and not src.mem.index \
                        and src.mem.base and ins.reg_name(src.mem.base) in regs:
                    # the address point formed from the vtable's start in
                    # another register (`lea rax, [rip+V]; lea rcx, [rax+0x10]`,
                    # a class with a second vtable, whose other address point
                    # is `add rax, 0x58`)
                    regs[d] = regs[ins.reg_name(src.mem.base)] + src.mem.disp
                    this.discard(d)
                elif m == "add" and src.type == X86_OP_IMM and d in regs:
                    regs[d] += src.imm
                else:
                    regs.pop(d, None)
                    this.discard(d)
            elif len(ops) == 2 and m == "mov" and ops[0].type == X86_OP_MEM and ops[1].type == X86_OP_REG:
                dst = ops[0]
                base = ins.reg_name(dst.mem.base) if dst.mem.base else None
                v = regs.get(ins.reg_name(ops[1].reg))
                if base in this and dst.mem.disp == 0 and not dst.mem.index and v is not None \
                        and self.in_relro(v) and self.is_address_point(v):
                    seq.append(v)
            elif ops and ops[0].type == X86_OP_REG and m not in ("cmp", "test"):
                d = ins.reg_name(ops[0].reg)
                regs.pop(d, None)
                this.discard(d)
        return seq

    def is_address_point(self, v: int) -> bool:
        """Two zero quadwords (offset-to-top, no RTTI) precede an address
        point, and its first slot is a text address or null (a pure virtual
        slot the linker left empty)."""
        if v % 8 or v - 0x10 < self.relro[0] or v + 8 > self.relro[1]:
            return False
        if self.elf.read(v - 0x10, 0x10) != bytes(0x10):
            return False
        s0 = struct.unpack("<Q", self.elf.read(v, 8))[0]
        return s0 == 0 or self.text_va <= s0 < self.text_va + len(self.text)

    def hkclass_records(self) -> dict[int, str]:
        """hkClass record address -> class name, from every call of the
        hkClass constructor FUN_000041a0 (`rdi` the record, `rsi` the name,
        `rdx` the parent's record, kept in `self.parents`)."""
        if self._hkclass is not None:
            return self._hkclass
        ctor = self.elf.func_by_name.get("FUN_000041a0", (None,))[0]
        out: dict[int, str] = {}
        self._hkclass = out
        self.parents = {}
        if ctor is None:
            return out
        for addr, (size, _n) in self.funcs.items():
            regs: dict[str, int] = {}
            for ins in self.md.disasm(self.text[addr - self.text_va:addr - self.text_va + size], addr):
                ops = ins.operands
                if ins.mnemonic == "call":
                    if ops and ops[0].type == X86_OP_IMM and ops[0].imm == ctor \
                            and isinstance(regs.get("rdi"), int) and isinstance(regs.get("rsi"), int):
                        name = c_string(self.elf, regs["rsi"])
                        if name:
                            out[regs["rdi"]] = name
                            if isinstance(regs.get("rdx"), int):
                                self.parents[regs["rdi"]] = regs["rdx"]
                    for r in CALLER_SAVED:
                        regs.pop(r, None)
                elif len(ops) == 2 and ops[0].type == X86_OP_REG:
                    d = ins.reg_name(ops[0].reg)
                    src = ops[1]
                    if ins.mnemonic == "lea" and src.type == X86_OP_MEM and src.mem.base == X86_REG_RIP:
                        regs[d] = ins.address + ins.size + src.mem.disp
                    elif ins.mnemonic == "mov" and src.type == X86_OP_REG and ins.reg_name(src.reg) in regs:
                        regs[d] = regs[ins.reg_name(src.reg)]
                    else:
                        regs.pop(d, None)
                elif ops and ops[0].type == X86_OP_REG and ins.mnemonic not in ("cmp", "test", "push"):
                    regs.pop(ins.reg_name(ops[0].reg), None)
        return out

    def registrations(self, addr: int, size: int):
        """-> [(site, record, (type name, scoped name), address point or None,
        ctor or None, base ctor or None)] for the type-info records this
        function fills; `base ctor` is the out-of-line constructor an inlined
        derived constructor called on the temporary before storing its own
        vptr over the slot (0x7cf9c calls hkpConstraintData's 0x82850, then
        0x7cfb3 stores hkpPrismaticConstraintData's vtable)."""
        regs: dict[str, int] = {}
        slots: dict[int, int] = {}            # rbp/rsp displacement -> the finish constructor run on it
        names: dict[int, str] = {}            # record address -> type name stored at +0
        scoped: dict[int, str] = {}           # record address -> scoped name stored at +8
        pending: dict[str, int] = {}          # register -> ctor whose object's vptr it holds
        overwrote: dict[int, int] = {}        # vptr stored over a slot -> the base constructor called on it before
        out = []
        lo = addr - self.text_va
        for ins in self.md.disasm(self.text[lo:lo + size], addr):
            ops = ins.operands
            m = ins.mnemonic
            if m == "call":
                if ops[0].type == X86_OP_IMM and "rdi" in regs and isinstance(regs["rdi"], tuple):
                    slots[regs["rdi"]] = ("ctor", ops[0].imm)
                for r in CALLER_SAVED:
                    regs.pop(r, None)
                    pending.pop(r, None)
                continue
            if m in ("ret", "jmp"):
                regs.clear()
                pending.clear()
                continue
            if m.startswith("j") or m in ("nop", "push", "pop", "cmp", "test"):
                continue
            if len(ops) == 2 and ops[0].type == X86_OP_REG:
                d = ins.reg_name(ops[0].reg)
                src = ops[1]
                if m == "add" and src.type == X86_OP_IMM:
                    if isinstance(regs.get(d), int):
                        regs[d] += src.imm
                    else:
                        regs.pop(d, None)
                    pending.pop(d, None)
                    continue
                regs.pop(d, None)
                pending.pop(d, None)
                if m == "lea" and src.type == X86_OP_MEM and src.mem.base == X86_REG_RIP:
                    regs[d] = ins.address + ins.size + src.mem.disp
                elif m == "lea" and src.type == X86_OP_MEM and src.mem.base and not src.mem.index:
                    regs[d] = (ins.reg_name(src.mem.base), src.mem.disp)      # a stack slot's address
                elif m == "mov" and src.type == X86_OP_REG:
                    sname = ins.reg_name(src.reg)
                    if sname in regs:
                        regs[d] = regs[sname]
                    if sname in pending:
                        pending[d] = pending[sname]
                elif m == "mov" and src.type == X86_OP_MEM and src.mem.base and not src.mem.index:
                    key = (ins.reg_name(src.mem.base), src.mem.disp)
                    if isinstance(slots.get(key), int):
                        regs[d] = slots[key]
                    elif key in slots:
                        pending[d] = slots[key][1]
            elif len(ops) == 2 and m == "mov" and ops[0].type == X86_OP_MEM and ops[1].type == X86_OP_REG:
                dst = ops[0]
                if dst.mem.index:
                    continue
                sreg = ins.reg_name(ops[1].reg)
                if dst.mem.base == X86_REG_RIP:
                    rec, disp = ins.address + ins.size + dst.mem.disp, 0
                else:
                    bname = ins.reg_name(dst.mem.base) if dst.mem.base else None
                    if bname in ("rbp", "rsp"):
                        # a store into a stack slot: the vptr an inlined derived
                        # constructor writes over the one its base's call stored
                        key = (bname, dst.mem.disp)
                        if isinstance(regs.get(sreg), int):
                            if isinstance(slots.get(key), tuple):
                                overwrote[regs[sreg]] = slots[key][1]      # a base's constructor ran on this slot first
                            slots[key] = regs[sreg]
                        elif sreg in pending:
                            slots[key] = ("ctor", pending[sreg])
                        else:
                            slots.pop(key, None)
                        continue
                    base = regs.get(bname) if bname else None
                    if not isinstance(base, int):
                        continue
                    rec, disp = base, dst.mem.disp
                if disp == 0 and self.bss[0] <= rec < self.bss[1] and isinstance(regs.get(sreg), int):
                    s = c_string(self.elf, regs[sreg])
                    if s:
                        names[rec] = s
                elif disp == 8 and rec in names and isinstance(regs.get(sreg), int):
                    s = c_string(self.elf, regs[sreg])
                    if s:
                        scoped[rec] = s
                elif rec + disp - 0x20 in names or (disp == 0x20 and rec in names):
                    rec0 = rec + disp - 0x20
                    v = regs.get(sreg)
                    nm = (names[rec0], scoped.get(rec0, names[rec0]))
                    if isinstance(v, int) and self.in_relro(v):
                        out.append((ins.address, rec0, nm, v, None, overwrote.get(v)))
                    elif sreg in pending:
                        out.append((ins.address, rec0, nm, self.vptr_of(pending[sreg]), pending[sreg], None))
            elif ops and ops[0].type == X86_OP_REG and m not in ("cmp", "test"):
                d = ins.reg_name(ops[0].reg)
                regs.pop(d, None)
                pending.pop(d, None)
        return out


def collect(elf: BaseElf):
    w = Walker(elf)
    hits = []
    for addr, size, _name in elf.functions:
        if addr - w.text_va < 0 or addr - w.text_va + size > len(w.text):
            continue
        hits += w.registrations(addr, size)
    return hits


def mangled_name(flat: str, scoped: str) -> tuple[str | None, str]:
    """The class as the developer spelled it: the scoped name when it is a
    plain or namespace-qualified identifier (`hkcdPlanarSolid::NodeStorage`),
    else the flat type name; a scoped name ending in `_typename` is Havok's
    typedef of a template instance, whose template spelling the executable
    does not give, so the flat name stands. -> (symbol, class)."""
    scoped = scoped.lstrip("!")                 # Havok writes the scoped name with a leading '!'
    cands = [flat] if scoped.endswith("_typename") else [scoped, flat]
    for cand in cands:                          # `_typename` is the typedef of a template instance
        sym = mangle_vtable(cand)
        if sym:
            return sym, cand
    return None, flat


def unnamed_vtables(elf: BaseElf, w: Walker, named: set[int]):
    """Every vtable address point some function stores into its object that
    no type info names, with the evidence at hand: the storing functions,
    the hkClass its slot 3 returns when that getter is this vtable's alone,
    and the storing functions' home files."""
    stores: dict[int, set[str]] = defaultdict(set)
    for addr, (sz, name) in w.funcs.items():
        for v in w.vptr_stores(addr):
            stores[v].add(name)
    hkclass = w.hkclass_records()
    homes: dict[str, str] = {}
    hp = config_path(REPO_ROOT, elf.version, "homes", "txt")
    if hp.exists():
        for line in hp.read_text().splitlines():
            s = line.split()
            if s and not line.startswith("#"):
                homes[s[0]] = s[1].rsplit("/", 1)[-1]
    getter: dict[int, tuple[int, str]] = {}
    for v in stores:
        s3 = struct.unpack("<Q", elf.read(v + 24, 8))[0]
        if s3 in w.funcs:
            ins = list(w.md.disasm(w.text[s3 - w.text_va:s3 - w.text_va + w.funcs[s3][0]], s3))
            if len(ins) == 2 and ins[0].mnemonic == "lea" and ins[1].mnemonic == "ret" \
                    and ins[0].operands[1].mem.base == X86_REG_RIP:
                rec = ins[0].address + ins[0].size + ins[0].operands[1].mem.disp
                if rec in hkclass:
                    getter[v] = (s3, hkclass[rec])
    shared = Counter(g[0] for g in getter.values())
    out = []
    for v in sorted(stores):
        if v in named:
            continue
        ev = []
        if v in getter and shared[getter[v][0]] == 1:
            ev.append(f"hkClass {getter[v][1]} (slot 3 0x{getter[v][0]:x})")
        hs = sorted({homes[f] for f in stores[v] if f in homes})
        if hs:
            ev.append("home " + " ".join(hs))
        out.append((v - 0x10, sorted(stores[v]), ev))
    return out


def parent_rows(w: Walker, base_calls: dict[int, set[str]], known: set[int], known_names: set[str]):
    """Vtables of classes with no type info of their own (abstract bases),
    named through their children: a derived class's inlined finish
    constructor calls the base's out-of-line finish constructor F on the
    temporary, F stores vtable V, and V is not the derived class's. V belongs
    to an ancestor of the derived class on its hkClass parent chain (the
    hkClass constructor's `rdx`); when every derived class that calls F
    agrees on exactly one ancestor whose vtable is still unknown, that
    ancestor's name is V's. Rows carry `parent <derived> ctor <F>`."""
    hk = w.hkclass_records()
    by_name = {n: r for r, n in hk.items()}
    out = []
    for f, derived in sorted(base_calls.items()):
        v = w.vptr_of(f)
        if v is None or v - 0x10 in known:
            continue
        cands = None
        for d in derived:
            rec = by_name.get(d)
            chain, seen = [], set()
            while rec in w.parents and rec not in seen:
                seen.add(rec)
                rec = w.parents[rec]
                if rec in hk:
                    chain.append(hk[rec])
            cands = set(chain) if cands is None else cands & set(chain)
        cands = {c for c in (cands or set()) if mangle_vtable(c) and c not in known_names}
        if len(cands) == 1:
            name = cands.pop()
            out.append((mangle_vtable(name), v - 0x10, name, f"parent {' '.join(sorted(derived))} ctor FUN_{f:08x}"))
    return out


def check_derived(elf: BaseElf) -> list[str]:
    """Every row of config/vtables.derived.<slug>.txt against its evidence."""
    errors = []
    for sym in list(elf._derived):
        try:
            elf._verify_derived(sym)
        except ValueError as e:
            errors.append(str(e))
    return errors


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--md", action="store_true", help="print a Markdown summary")
    ap.add_argument("--no-write", action="store_true", help="do not write config/vtables.<slug>.txt")
    ap.add_argument("--check", action="store_true", help="verify config/vtables.derived.<slug>.txt only")
    a = ap.parse_args(argv)
    elf = BaseElf(REPO_ROOT)
    if a.check:
        errs = check_derived(elf)
        for e in errs:
            print(e, file=sys.stderr)
        print(f"vtable_names: {len(elf._derived)} derived rows, {len(errs)} failing")
        return 1 if errs else 0
    w = Walker(elf)
    hits = []
    for addr, (size, _name) in w.funcs.items():
        if addr - w.text_va >= 0 and addr - w.text_va + size <= len(w.text):
            hits += w.registrations(addr, size)
    by_name: dict[tuple, dict[int, list[str]]] = defaultdict(lambda: defaultdict(list))
    untraced = []
    base_calls: dict[int, set[str]] = defaultdict(set)   # base ctor -> {derived type names that called it}
    for site, _rec, nm, point, ctor, base_ctor in hits:
        if base_ctor is not None:
            base_calls[base_ctor].add(nm[0])
        if point is None:
            untraced.append((nm[0], site, ctor))
            continue
        # an address point is preceded by the offset-to-top and the (absent) RTTI pointer, both zero
        if not w.is_address_point(point):
            raise SystemExit(f"vtable_names: 0x{point:x} stored for {nm[0]} at 0x{site:x} is not a vtable address point")
        by_name[nm][point - 0x10].append(f"typeinfo 0x{site:x}" + (f" ctor FUN_{ctor:08x}" if ctor else ""))
    rows, unmangled, conflicts = [], [], []
    for nm, vts in sorted(by_name.items(), key=lambda kv: min(kv[1])):
        flat, scoped = nm
        if len(vts) > 1:
            conflicts.append((flat, {hex(v): ss for v, ss in vts.items()}))
            continue
        (vt, sites), = vts.items()
        sym, cls = mangled_name(flat, scoped)
        if sym is None:
            unmangled.append((flat, vt, sites[0]))
            continue
        note = f' scoped "{scoped.lstrip("!")}"' if cls != scoped.lstrip("!") else ""
        rows.append((sym, vt, cls, sites[0] + note))
    rows += parent_rows(w, base_calls, {vt for _, vt, _, _ in rows}, {name for _, _, name, _ in rows})
    shared = defaultdict(list)
    for sym, vt, name, _ in rows:
        shared[vt].append(name)
    named_points = {vt + 0x10 for _, vt, _, _ in rows} | {v + 0x10 for v, _, _ in elf._derived.values()}
    unnamed = unnamed_vtables(elf, w, named_points)
    derived_errors = check_derived(elf)
    out = config_path(REPO_ROOT, elf.version, "vtables", "txt")
    lines = [
        "# Vtables the executable names: `<vtable symbol> <vtable address> <class name> typeinfo",
        "# <store site> [ctor <function>] [scoped \"<name>\"]`. Written by tools/vtable_names.py",
        "# from each reflected class's type-info registration (its docstring has the rule);",
        "# regenerate, never edit. The address is the start of the `_ZTV` object; a constructed",
        "# object's vptr holds it + 0x10. The class is the type info's scoped name when that is",
        "# an identifier (a nested class is written nested), else its flat type name, with the",
        "# scoped name noted. Vtables named by ruling are in vtables.derived.<slug>.txt (D14).",
        f"# {len(rows)} classes; {len(unmangled)} names the tool cannot mangle (below, `?`);",
        f"# {len(conflicts)} names registered with two vtables (below, not written);",
        f"# {len(untraced)} registrations whose constructor's vptr store the walk cannot find (below);",
        f"# {sum(1 for v in shared.values() if len(v) > 1)} vtables registered by more than one class;",
        f"# {len(unnamed)} vtables stored by a constructor that no type info names (below, with",
        "# the evidence at hand; a ruling names one in vtables.derived.<slug>.txt).",
        "#",
        "# Vtables registered by more than one class (the derived class keeps the base's):",
    ]
    lines += [f"#   0x{vt:x} {' '.join(ns)}" for vt, ns in sorted(shared.items()) if len(ns) > 1]
    lines += ["#", "# Names the tool cannot mangle:"]
    lines += [f"#   ? 0x{vt:x} {name} {ev}" for name, vt, ev in unmangled]
    lines += ["#", "# Names registered with two vtables:"]
    lines += [f"#   {name} {d}" for name, d in conflicts]
    lines += ["#", "# Registrations whose finish constructor's vptr store the walk cannot find:"]
    lines += [f"#   {name} typeinfo 0x{site:x} ctor FUN_{ctor:08x}" for name, site, ctor in untraced]
    lines += ["#", "# Vtables no type info names: `<vtable address> stored by <functions> [hkClass <name>",
              "# (slot 3 <getter>)] [home <files>]`:"]
    lines += [f"#   0x{vt:x} stored by {' '.join(fs)}" + (f" | {'; '.join(ev)}" if ev else "") for vt, fs, ev in unnamed]
    lines += [f"{sym} 0x{vt:x} {name} {ev}" for sym, vt, name, ev in rows]
    if not a.no_write:
        out.write_text("\n".join(lines) + "\n")
    for e in derived_errors:
        print(e, file=sys.stderr)
    if a.md:
        print(f"| type-info vtable stores | {len(hits)} |")
        print(f"| classes with a named vtable | {len(rows)} |")
        print(f"| names not mangled (templates) | {len(unmangled)} |")
        print(f"| names with two vtables | {len(conflicts)} |")
        print(f"| constructor vptr not traced | {len(untraced)} |")
        print(f"| vtables named by ruling | {len(elf._derived)} |")
        print(f"| vtables stored by a constructor, unnamed | {len(unnamed)} |")
    else:
        print(f"vtable_names: {len(rows)} rows, {len(unmangled)} unmangled, {len(conflicts)} conflicts, "
              f"{len(untraced)} untraced, {len(elf._derived)} derived, {len(unnamed)} unnamed -> {out.relative_to(REPO_ROOT)}")
    return 1 if derived_errors else 0


if __name__ == "__main__":
    sys.exit(main())
