#!/usr/bin/env python3
"""
match_check.py: how far a compiled function is from the base executable's.

The compiled object (a TU built by tools/compile_cpp.sh) holds the function
as a symbol with its .text bytes and relocations. The base executable holds
the linked bytes at the function's address (config/functions.<slug>.txt).
Both are disassembled (capstone) and compared instruction by instruction;
where the object's instruction carries a relocation, the field the linker
fills (a RIP-relative displacement, a call target, a GOT or PLT slot) is
masked on both sides, and nothing else is; a GOT load of a symbol the
executable defines is first relaxed to the `lea` the linker made of it
(docs/DECISIONS.md D10). The score is the share of
instructions equal after masking, over the longer of the two streams: 1.0 is
a match. The masked fields are then checked for real where the base can
place the symbol: a call to FUN_x must encode, in the base, the address of
FUN_x; a reference to D_<hex> that address; a call to an import its PLT
stub. A wrong target fails the function whatever the score (tools/base_elf.py).

    match_check.py --tu src/x/y.cpp --func <name> [--symbol <mangled>] [--diff]
    match_check.py --tu src/x/y.cpp --all          every function the TU defines
                                                  that config/functions lists
    match_check.py --obj build/base/obj/x/y.o ...  an object already built

<name> is the function's row in config/functions.<slug>.txt (FUN_<addr>, or
its real name); --symbol is the object's symbol when it differs (a mangled
C++ name behind a FUN_ row). With --diff the first difference is printed
with five instructions of context on each side.

Exit 0 when every checked function scores 1.0, 1 otherwise, 2 on a usage
error. --json prints the results as one JSON object per line.
"""
from __future__ import annotations

import argparse
import json
import re
import os
import subprocess
import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(Path(__file__).resolve().parent))
from tlg_version import baseelf_path, build_dir, config_path, detect_version  # noqa: E402
from survey_elf import read_phdrs, vaddr_to_off  # noqa: E402
from base_elf import BaseElf  # noqa: E402

# R_X86_64_* relocation types -> field width in bytes.
RELOC_WIDTH = {1: 8, 2: 4, 3: 4, 4: 4, 5: 8, 6: 8, 7: 8, 8: 8, 9: 4, 10: 4, 11: 4,
               12: 2, 13: 2, 14: 1, 15: 1, 16: 8, 17: 8, 18: 8, 19: 4, 20: 4, 21: 4,
               22: 4, 23: 4, 24: 8, 25: 8, 26: 4, 27: 4, 28: 8, 29: 4, 30: 4, 31: 4,
               32: 8, 33: 4, 34: 4, 35: 4, 36: 4, 41: 4, 42: 4}


def load_functions(ver: str) -> dict[str, tuple[int, int]]:
    out = {}
    p = config_path(REPO_ROOT, ver, "functions", "txt")
    for line in p.read_text().splitlines():
        s = line.split("#", 1)[0].split()
        if len(s) >= 3:
            out[s[2]] = (int(s[0], 16), int(s[1], 16))
    return out


def generate_tables_of(tu: str, ver: str) -> None:
    """Write build/<slug>/gen/D_<hex>.inc for every table the TU claims
    (config/data_schema.<slug>.txt, tools/gen_data_inc.py, D18), so a compile
    outside ninja sees the current rows."""
    try:
        from gen_data_inc import schema_rows
        rows = schema_rows(ver)
    except Exception:  # noqa: BLE001  (no schema file, or an error ninja will report)
        return
    for ident, row in rows.items():
        if row.get("tu") == tu:
            subprocess.run([sys.executable, "-I", str(REPO_ROOT / "tools" / "gen_data_inc.py"), ident],
                           cwd=REPO_ROOT, check=True, env={**os.environ, "VERSION": ver})


def compile_tu(tu: str, ver: str) -> Path:
    """The TU's object, recompiled when the TU or any header its depfile
    lists (tools/compile_cpp.sh writes <obj>.d) is newer than it."""
    obj = build_dir(REPO_ROOT, ver) / "obj" / (tu + ".o")
    src = REPO_ROOT / tu
    generate_tables_of(tu, ver)
    if obj.exists() and obj.stat().st_mtime >= src.stat().st_mtime:
        dep = obj.with_name(obj.name + ".d")
        # ninja (deps = gcc) consumes the depfile it was given, so an object
        # ninja built has no .d beside it and its headers cannot be checked:
        # it is recompiled (round 31's note: a header change was not seen).
        if dep.exists():
            text = dep.read_text().replace("\\\n", " ")
            deps = [Path(d) for d in text.split(":", 1)[1].split()] if ":" in text else []
            stale = [d for d in deps if not d.exists() or d.stat().st_mtime > obj.stat().st_mtime]
            if not stale:
                return obj
    subprocess.run([str(REPO_ROOT / "tools" / "compile_cpp.sh"), tu, str(obj.relative_to(REPO_ROOT))],
                   cwd=REPO_ROOT, check=True)
    return obj


class Reloc:
    """One relocation inside a function of a compiled object."""
    __slots__ = ("offset", "width", "type", "symbol", "addend", "sym_section", "sym_value", "sym_size")

    def __init__(self, offset, width, type_, symbol, addend, sym_section, sym_value, sym_size):
        self.offset, self.width, self.type = offset, width, type_
        self.symbol, self.addend = symbol, addend
        self.sym_section, self.sym_value, self.sym_size = sym_section, sym_value, sym_size

    def __iter__(self):  # (offset, width, type), the shape compare() masks with
        yield self.offset
        yield self.width
        yield self.type


def named_locals(syms) -> dict[int, list[tuple[int, int, str]]]:
    """The object's named local data and function symbols by section index:
    a `static` object or function, or a namespace-scope const, which the
    assembler references as its section plus an offset (docs/DECISIONS.md
    D17). Assembler temporaries (`.L...`) are not in the symbol table."""
    out: dict[int, list[tuple[int, int, str]]] = {}
    for s in syms:
        info = s["st_info"]
        if info["bind"] != "STB_LOCAL" or info["type"] not in ("STT_OBJECT", "STT_FUNC") or not s.name:
            continue
        out.setdefault(s["st_shndx"], []).append((s["st_value"], s["st_size"], s.name))
    return out


def reloc_symbol(elf, locals_by_sec, sym, addend, tail=0) -> tuple[str, int, int, int]:
    """(name, addend, value, size) for a relocation's symbol. A section symbol
    is attributed to the named local whose extent holds the target offset,
    the reference the assembler rewrote as section + offset; a string literal
    or a constant-pool entry keeps the section's name, and the resolver finds
    its bytes in the base. `tail` is the distance from the field to the end
    of its instruction, which a PC-relative addend subtracts (an absolute
    field or a data slot has none)."""
    if sym["st_info"]["type"] != "STT_SECTION":
        return sym.name, addend, sym["st_value"], sym["st_size"]
    shndx = sym["st_shndx"]
    target = addend + tail
    for value, size, name in locals_by_sec.get(shndx, []):
        if value <= target < value + max(size, 1):
            return name, addend - value, value, size
    return elf.get_section(shndx).name, addend, sym["st_value"], sym["st_size"]


PCREL_TYPES = (2, 4, 9, 41, 42)      # PC32, PLT32, GOTPCREL, GOTPCRELX, REX_GOTPCRELX


def field_tails(code: bytes, offsets: list[int]) -> dict[int, int]:
    """offset of a relocated field -> bytes from the field to the end of its
    instruction, by disassembling the function once (4 where the decoder
    stops short)."""
    import capstone
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    want = sorted(offsets)
    out = {o: 4 for o in want}
    i = 0
    for ins in md.disasm(code, 0):
        end = ins.address + ins.size
        while i < len(want) and want[i] < end:
            if want[i] >= ins.address:
                out[want[i]] = end - want[i]
            i += 1
        if i >= len(want):
            break
    return out


def object_functions(obj: Path) -> dict[str, tuple[bytes, list[Reloc]]]:
    """symbol -> (bytes, [Reloc]) for every STT_FUNC the object defines."""
    from elftools.elf.elffile import ELFFile
    from elftools.elf.relocation import RelocationSection
    out = {}
    with obj.open("rb") as f:
        elf = ELFFile(f)
        symtab = elf.get_section_by_name(".symtab")
        syms = list(symtab.iter_symbols())
        locs = named_locals(syms)
        raw_by_sec: dict[int, list] = {}
        for sec in elf.iter_sections():
            if isinstance(sec, RelocationSection):
                for r in sec.iter_relocations():
                    raw_by_sec.setdefault(sec["sh_info"], []).append(
                        (r["r_offset"], r["r_info_type"], syms[r["r_info_sym"]],
                         r["r_addend"] if "r_addend" in r.entry else 0))
        for sym in syms:
            if sym["st_info"]["type"] != "STT_FUNC" or sym["st_shndx"] in ("SHN_UNDEF", "SHN_ABS"):
                continue
            shndx = sym["st_shndx"]
            sec = elf.get_section(shndx)
            lo, size = sym["st_value"], sym["st_size"]
            data = sec.data()[lo:lo + size]
            raw = [x for x in raw_by_sec.get(shndx, []) if lo <= x[0] < lo + size]
            tails = field_tails(data, [off - lo for off, ty, _s, _a in raw if ty in PCREL_TYPES])
            rl = []
            for off, ty, rsym, addend in raw:
                name, addend, value, ssize = reloc_symbol(elf, locs, rsym, addend, tails.get(off - lo, 0))
                rl.append(Reloc(off - lo, RELOC_WIDTH.get(ty, 4), ty, name, addend, rsym["st_shndx"], value, ssize))
            out[sym.name] = (data, sorted(rl, key=lambda r: r.offset))
    return out


def object_bytes_of(obj: Path, section_index: int, value: int, size: int) -> bytes:
    """The bytes a local data symbol (a string literal) covers in the object."""
    from elftools.elf.elffile import ELFFile
    with obj.open("rb") as f:
        elf = ELFFile(f)
        sec = elf.get_section(section_index)
        d = sec.data()
        if size == 0:  # a section symbol: the literal runs to the next NUL
            end = d.find(b"\0", value)
            size = (end + 1 if end >= 0 else len(d)) - value
        return d[value:value + size]


def resolve_symbol(objfuncs: dict, fn: str, sym: str) -> str | None:
    """The object's symbol for a row: `sym` itself, or, failing that, the one
    Itanium-mangled symbol whose base identifier is `fn` (a free function or
    a member whose last component is the FUN_ placeholder), so a FUN_<addr>
    row needs no symbol column while its signature is a guess."""
    if sym in objfuncs:
        return sym
    from base_elf import BaseElf
    hits = [s for s in objfuncs if BaseElf.base_identifier(s) == fn]
    return hits[0] if len(hits) == 1 else None


GOTPCREL_TYPES = (9, 41, 42)        # R_X86_64_GOTPCREL, GOTPCRELX, REX_GOTPCRELX


def relaxable_got_load(code: bytes, r) -> bool:
    """True when `r` is a GOTPCREL relocation on `mov r64, [rip+disp32]`
    (REX.W 8B /r with mod=00 rm=101), the form the linker relaxed to
    `lea r64, [rip+disp32]` for every symbol defined in the executable
    (docs/DECISIONS.md D10)."""
    k = r.offset
    return (r.type in GOTPCREL_TYPES and k >= 3 and code[k - 2] == 0x8B
            and (code[k - 1] & 0xC7) == 0x05 and (code[k - 3] & 0xF8) == 0x48)


def relax_got_loads(code: bytes, relocs, base) -> tuple[bytes, set]:
    """The linker's mov-to-lea relaxation applied to the object: a GOT load of
    a symbol that is not an import (the base has GOT slots for imports only)
    becomes the lea the base holds. Returns the relaxed bytes and the offsets
    of the relocations that now verify as PC32."""
    out = bytearray(code)
    relaxed = set()
    if base is None:
        return code, relaxed
    slots = base.got_slots()
    for r in relocs:
        if relaxable_got_load(code, r) and r.symbol not in slots:
            out[r.offset - 2] = 0x8D
            relaxed.add(r.offset)
    return bytes(out), relaxed


R_X86_64_TLSGD, R_X86_64_GOTTPOFF = 19, 22
TLS_GD_LEA = bytes.fromhex("66488d3d")                     # data16 lea rdi, [rip+x@tlsgd]
TLS_GD_CALL = bytes.fromhex("666648e8")                    # data16 data16 rex.W call __tls_get_addr
TLS_IE_FORM = bytes.fromhex("64488b042500000000480305")    # mov rax, fs:[0]; add rax, [rip+x@gottpoff]


def relax_tls_gd(code: bytes, relocs: list) -> tuple[bytes, list]:
    """The linker's GD-to-IE relaxation applied to the object (docs/DECISIONS.md
    D23): the 16-byte general-dynamic sequence the compiler emits for a
    thread-local (`data16 lea rdi, [rip+x@tlsgd]; data16 data16 rex.W call
    __tls_get_addr`) becomes the initial-exec form the base holds in the same
    16 bytes (`mov rax, fs:[0]; add rax, [rip+x@gottpoff]`), the x86-64 psABI's
    GD to IE code transition. The TLSGD and PLT32 relocations are replaced by
    one GOTTPOFF relocation on the add's displacement, against the variable;
    verify_targets and layout_link resolve it to the base's GOT slot holding
    the thread-pointer offset. A TLSGD relocation on another form is left
    alone (it will not match the base, which holds no such form)."""
    by_off = {r.offset: r for r in relocs}
    out = bytearray(code)
    drop, added = set(), []
    for r in relocs:
        k = r.offset
        c = by_off.get(k + 8)
        if (r.type == R_X86_64_TLSGD and k >= 4 and code[k - 4:k] == TLS_GD_LEA
                and code[k + 4:k + 8] == TLS_GD_CALL and c is not None and c.type == 4
                and c.symbol == "__tls_get_addr"):
            out[k - 4:k + 12] = TLS_IE_FORM + b"\0\0\0\0"
            drop.update((k, k + 8))
            added.append(Reloc(k + 8, 4, R_X86_64_GOTTPOFF, r.symbol, -4, r.sym_section, r.sym_value, r.sym_size))
    if not drop:
        return code, relocs
    return bytes(out), sorted([r for r in relocs if r.offset not in drop] + added, key=lambda r: r.offset)


def disasm(code: bytes, base: int):
    from capstone import Cs, CS_ARCH_X86, CS_MODE_64
    md = Cs(CS_ARCH_X86, CS_MODE_64)
    return list(md.disasm(code, base))


def verify_targets(relocs, base_bytes: bytes, base_addr: int, base,
                   relaxed: set | None = None) -> tuple[list[str], int]:
    """For every relocation whose symbol the base can place (a function of the
    table, a D_<hex> label, an import's PLT stub), compute the target the
    base's own displacement encodes and compare. Returns (mismatches,
    unverified count). PC-relative: S + A - P = disp, so S = disp + P - A."""
    import struct as _st
    bad, unverified = [], 0
    for r in relocs:
        if r.width != 4 or r.offset + 4 > len(base_bytes):
            unverified += 1
            continue
        expected = base.address_of(r.symbol) if base is not None else None
        if expected is None:
            unverified += 1
            continue
        P = base_addr + r.offset
        disp = _st.unpack_from("<i", base_bytes, r.offset)[0]
        if r.type in (2, 4) or (relaxed and r.offset in relaxed):   # PC32, PLT32, relaxed GOT load
            actual = disp + P - r.addend
        elif r.type in GOTPCREL_TYPES:  # GOTPCREL*: the GOT slot, not the symbol
            slot = base.got_slots().get(r.symbol)
            if slot is None:
                unverified += 1
                continue
            expected, actual = slot, disp + P - r.addend
        elif r.type in (10, 11):        # 32, 32S: absolute
            actual = disp - r.addend
        elif r.type == R_X86_64_GOTTPOFF:   # the relaxed TLS access: the GOT slot holding the offset (D23)
            slot = base.tls_got_slot(r.symbol)
            if slot is None:
                bad.append(f"{r.symbol}: no single GOT slot of the base holds its thread-pointer offset "
                           f"(reloc at +0x{r.offset:x})")
                continue
            expected, actual = slot, disp + P - r.addend
        else:
            unverified += 1
            continue
        if actual != expected:
            bad.append(f"{r.symbol}: base refers to 0x{actual:x}, source to 0x{expected:x} "
                       f"(reloc at +0x{r.offset:x})")
    return bad, unverified


def compare(obj_bytes: bytes, relocs, base_bytes: bytes, base_addr: int, base=None) -> dict:
    obj_bytes, relocs = relax_tls_gd(obj_bytes, relocs)
    obj_bytes, relaxed = relax_got_loads(obj_bytes, relocs, base)
    a = disasm(obj_bytes, 0)
    b = disasm(base_bytes, base_addr)
    n = max(len(a), len(b))
    equal = 0
    first_diff = None
    rows = []
    for i in range(n):
        ia = a[i] if i < len(a) else None
        ib = b[i] if i < len(b) else None
        ok = False
        if ia is not None and ib is not None and ia.size == ib.size:
            ba, bb = bytearray(ia.bytes), bytearray(ib.bytes)
            for roff, width, _ in relocs:
                if ia.address <= roff < ia.address + ia.size:
                    k = roff - ia.address
                    for j in range(k, min(k + width, ia.size)):
                        ba[j] = bb[j] = 0
            ok = ba == bb
        equal += ok
        if not ok and first_diff is None:
            first_diff = i
        rows.append((ok, ia, ib))
    bad_targets, unverified = verify_targets(relocs, base_bytes, base_addr, base, relaxed) if relocs else ([], 0)
    return {"obj_insns": len(a), "base_insns": len(b), "equal": equal,
            "score": (equal / n) if n else 1.0, "first_diff": first_diff, "rows": rows,
            "obj_size": len(obj_bytes), "base_size": len(base_bytes),
            "bad_targets": bad_targets, "unverified_relocs": unverified,
            "targets_ok": not bad_targets}


def fmt(ins, side_addr=None) -> str:
    if ins is None:
        return "-"
    return f"{ins.address:06x}  {ins.bytes.hex():<22} {ins.mnemonic} {ins.op_str}".rstrip()


def print_diff(name: str, r: dict) -> None:
    fd = r["first_diff"]
    for t in r.get("bad_targets", []):
        print(f"{name}: WRONG TARGET {t}")
    if fd is None:
        extra = f", {r['unverified_relocs']} relocation(s) unverified" if r.get("unverified_relocs") else ""
        print(f"{name}: {'equal' if r.get('targets_ok', True) else 'equal bytes, wrong targets'} "
              f"({r['equal']} instructions, {r['obj_size']} bytes{extra})")
        return
    print(f"{name}: {r['equal']}/{max(r['obj_insns'], r['base_insns'])} instructions equal "
          f"(score {r['score']:.4f}); object {r['obj_size']} bytes, base {r['base_size']} bytes; "
          f"first difference at instruction {fd}")
    lo, hi = max(0, fd - 5), min(len(r["rows"]), fd + 6)
    print(f"  {'':2} {'object (compiled)':<48} | base")
    for i in range(lo, hi):
        ok, ia, ib = r["rows"][i]
        mark = "  " if ok else ">>"
        print(f"  {mark} {fmt(ia):<48} | {fmt(ib)}")


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    g = ap.add_mutually_exclusive_group(required=True)
    g.add_argument("--tu", help="source file, compiled with tools/compile_cpp.sh")
    g.add_argument("--obj", help="an object already built")
    ap.add_argument("--func", action="append", default=[],
                    help="function row name in config/functions.<slug>.txt (repeatable)")
    ap.add_argument("--symbol", action="append", default=[],
                    help="the object's symbol for the corresponding --func, when it differs")
    ap.add_argument("--all", action="store_true",
                    help="every object function whose symbol names a functions row")
    ap.add_argument("--diff", action="store_true")
    ap.add_argument("--json", action="store_true")
    a = ap.parse_args(argv)
    ver = detect_version(REPO_ROOT)
    funcs = load_functions(ver)
    base = BaseElf(REPO_ROOT, ver)
    data, phdrs = base.data, base.phdrs
    obj = compile_tu(a.tu, ver) if a.tu else Path(a.obj)
    objfuncs = object_functions(obj)

    pairs: list[tuple[str, str]] = []
    if a.all:
        pairs = [(s, s) for s in objfuncs if s in funcs]
    for i, fn in enumerate(a.func):
        pairs.append((fn, a.symbol[i] if i < len(a.symbol) else fn))
    if not pairs:
        print("match_check: nothing to check (--func or --all)", file=sys.stderr)
        return 2

    worst = 1.0
    for fn, sym in pairs:
        if fn not in funcs:
            print(f"match_check: {fn} is not in config/functions.{ver}.txt", file=sys.stderr)
            return 2
        sym = resolve_symbol(objfuncs, fn, sym) or sym
        if sym not in objfuncs:
            print(f"match_check: symbol {sym} not defined in {obj} "
                  f"(have: {', '.join(sorted(objfuncs)[:8])}{'...' if len(objfuncs) > 8 else ''})",
                  file=sys.stderr)
            return 2
        addr, size = funcs[fn]
        off = vaddr_to_off(phdrs, addr)
        base_bytes = data[off:off + size]
        ob, rl = objfuncs[sym]
        r = compare(ob, rl, base_bytes, addr, base)
        worst = min(worst, r["score"] if r["targets_ok"] else 0.0)
        if a.json:
            print(json.dumps({"func": fn, "symbol": sym, "addr": addr, "size": size,
                              "score": r["score"], "equal": r["equal"],
                              "obj_insns": r["obj_insns"], "base_insns": r["base_insns"],
                              "obj_size": r["obj_size"], "base_size": r["base_size"],
                              "targets_ok": r["targets_ok"], "bad_targets": r["bad_targets"],
                              "unverified_relocs": r["unverified_relocs"]}))
        elif a.diff or r["first_diff"] is not None or not r["targets_ok"]:
            print_diff(fn if fn == sym else f"{fn} ({sym})", r)
        else:
            print(f"{fn}: equal")
    return 0 if worst == 1.0 else 1


if __name__ == "__main__":
    sys.exit(main())
