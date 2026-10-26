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
import sys
from collections import defaultdict
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
        if ctor in self._vptr:
            return self._vptr[ctor]
        self._vptr[ctor] = None
        if ctor not in self.funcs:
            return None
        ins_by = self.insns(ctor)
        this = {"rdi"}
        regs: dict[str, int] = {}
        last, pc, steps = None, ctor, 0
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
                elif m == "add" and src.type == X86_OP_IMM and d in regs:
                    regs[d] += src.imm
                else:
                    regs.pop(d, None)
                    this.discard(d)
            elif len(ops) == 2 and m == "mov" and ops[0].type == X86_OP_MEM and ops[1].type == X86_OP_REG:
                dst = ops[0]
                base = ins.reg_name(dst.mem.base) if dst.mem.base else None
                v = regs.get(ins.reg_name(ops[1].reg))
                if base in this and dst.mem.disp == 0 and not dst.mem.index and v is not None and self.in_relro(v):
                    last = v
            elif ops and ops[0].type == X86_OP_REG and m not in ("cmp", "test"):
                d = ins.reg_name(ops[0].reg)
                regs.pop(d, None)
                this.discard(d)
        self._vptr[ctor] = last
        return last

    def registrations(self, addr: int, size: int):
        """-> [(site, record, type name, address point or None, ctor or None)]
        for the type-info records this function fills."""
        regs: dict[str, int] = {}
        slots: dict[int, int] = {}            # rbp/rsp displacement -> the finish constructor run on it
        names: dict[int, str] = {}            # record address -> type name stored at +0
        pending: dict[str, int] = {}          # register -> ctor whose object's vptr it holds
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
                elif rec + disp - 0x20 in names or (disp == 0x20 and rec in names):
                    rec0 = rec + disp - 0x20
                    v = regs.get(sreg)
                    if isinstance(v, int) and self.in_relro(v):
                        out.append((ins.address, rec0, names[rec0], v, None))
                    elif sreg in pending:
                        out.append((ins.address, rec0, names[rec0], self.vptr_of(pending[sreg]), pending[sreg]))
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


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--md", action="store_true", help="print a Markdown summary")
    ap.add_argument("--no-write", action="store_true", help="do not write config/vtables.<slug>.txt")
    a = ap.parse_args(argv)
    elf = BaseElf(REPO_ROOT)
    hits = collect(elf)
    by_name: dict[str, dict[int, list[str]]] = defaultdict(lambda: defaultdict(list))
    untraced = []
    for site, _rec, name, point, ctor in hits:
        if point is None:
            untraced.append((name, site, ctor))
            continue
        # an address point is preceded by the offset-to-top and the (absent) RTTI pointer, both zero
        if point % 8 or elf.read(point - 0x10, 0x10) != bytes(0x10):
            raise SystemExit(f"vtable_names: 0x{point:x} stored for {name} at 0x{site:x} is not a vtable address point")
        by_name[name][point - 0x10].append(f"typeinfo 0x{site:x}" + (f" ctor FUN_{ctor:08x}" if ctor else ""))
    rows, unmangled, conflicts = [], [], []
    for name, vts in sorted(by_name.items(), key=lambda kv: min(kv[1])):
        if len(vts) > 1:
            conflicts.append((name, {hex(v): ss for v, ss in vts.items()}))
            continue
        (vt, sites), = vts.items()
        sym = mangle_vtable(name)
        if sym is None:
            unmangled.append((name, vt, sites[0]))
            continue
        rows.append((sym, vt, name, sites[0]))
    shared = defaultdict(list)
    for sym, vt, name, _ in rows:
        shared[vt].append(name)
    out = config_path(REPO_ROOT, elf.version, "vtables", "txt")
    lines = [
        "# Vtables the executable names: `<vtable symbol> <vtable address> <class name> typeinfo",
        "# <store site>`. Written by tools/vtable_names.py from each reflected class's type-info",
        "# registration (its docstring has the rule); regenerate, never edit. The address is",
        "# the start of the `_ZTV` object; a constructed object's vptr holds it + 0x10.",
        f"# {len(rows)} classes; {len(unmangled)} names the tool cannot mangle (below, `?`);",
        f"# {len(conflicts)} names registered with two vtables (below, not written);",
        f"# {len(untraced)} registrations whose constructor's vptr store the walk cannot find (below);",
        f"# {sum(1 for v in shared.values() if len(v) > 1)} vtables registered by more than one class.",
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
    lines += [f"{sym} 0x{vt:x} {name} {ev}" for sym, vt, name, ev in rows]
    if not a.no_write:
        out.write_text("\n".join(lines) + "\n")
    if a.md:
        print(f"| type-info vtable stores | {len(hits)} |")
        print(f"| classes with a named vtable | {len(rows)} |")
        print(f"| names not mangled (templates) | {len(unmangled)} |")
        print(f"| names with two vtables | {len(conflicts)} |")
        print(f"| constructor vptr not traced | {len(untraced)} |")
    else:
        print(f"vtable_names: {len(rows)} rows, {len(unmangled)} unmangled, {len(conflicts)} conflicts, "
              f"{len(untraced)} untraced "
              f"-> {out.relative_to(REPO_ROOT)}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
