#!/usr/bin/env python3
"""
match_check.py: how far a compiled function is from the base executable's.

The compiled object (a TU built by tools/compile_cpp.sh) holds the function
as a symbol with its .text bytes and relocations. The base executable holds
the linked bytes at the function's address (config/functions.<slug>.txt).
Both are disassembled (capstone) and compared instruction by instruction;
where the object's instruction carries a relocation, the field the linker
fills (a RIP-relative displacement, a call target, a GOT or PLT slot) is
masked on both sides, and nothing else is. The score is the share of
instructions equal after masking, over the longer of the two streams: 1.0 is
a match.

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
import subprocess
import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(Path(__file__).resolve().parent))
from tlg_version import baseelf_path, build_dir, config_path, detect_version  # noqa: E402
from survey_elf import read_phdrs, vaddr_to_off  # noqa: E402

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


def compile_tu(tu: str, ver: str) -> Path:
    obj = build_dir(REPO_ROOT, ver) / "obj" / (tu + ".o")
    src = REPO_ROOT / tu
    if obj.exists() and obj.stat().st_mtime >= src.stat().st_mtime:
        return obj
    subprocess.run([str(REPO_ROOT / "tools" / "compile_cpp.sh"), tu, str(obj.relative_to(REPO_ROOT))],
                   cwd=REPO_ROOT, check=True)
    return obj


def object_functions(obj: Path) -> dict[str, tuple[bytes, list[tuple[int, int, int]]]]:
    """symbol -> (bytes, [(offset_in_func, width, type)]) for every STT_FUNC."""
    from elftools.elf.elffile import ELFFile
    from elftools.elf.relocation import RelocationSection
    out = {}
    with obj.open("rb") as f:
        elf = ELFFile(f)
        symtab = elf.get_section_by_name(".symtab")
        relocs_by_sec: dict[int, list] = {}
        for sec in elf.iter_sections():
            if isinstance(sec, RelocationSection):
                relocs_by_sec.setdefault(sec["sh_info"], []).extend(
                    (r["r_offset"], r["r_info_type"]) for r in sec.iter_relocations())
        for sym in symtab.iter_symbols():
            if sym["st_info"]["type"] != "STT_FUNC" or sym["st_shndx"] in ("SHN_UNDEF", "SHN_ABS"):
                continue
            shndx = sym["st_shndx"]
            sec = elf.get_section(shndx)
            lo, size = sym["st_value"], sym["st_size"]
            data = sec.data()[lo:lo + size]
            rl = [(ro - lo, RELOC_WIDTH.get(rt, 4), rt)
                  for ro, rt in relocs_by_sec.get(shndx, []) if lo <= ro < lo + size]
            out[sym.name] = (data, sorted(rl))
    return out


def disasm(code: bytes, base: int):
    from capstone import Cs, CS_ARCH_X86, CS_MODE_64
    md = Cs(CS_ARCH_X86, CS_MODE_64)
    return list(md.disasm(code, base))


def compare(obj_bytes: bytes, relocs, base_bytes: bytes, base_addr: int) -> dict:
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
    return {"obj_insns": len(a), "base_insns": len(b), "equal": equal,
            "score": (equal / n) if n else 1.0, "first_diff": first_diff, "rows": rows,
            "obj_size": len(obj_bytes), "base_size": len(base_bytes)}


def fmt(ins, side_addr=None) -> str:
    if ins is None:
        return "-"
    return f"{ins.address:06x}  {ins.bytes.hex():<22} {ins.mnemonic} {ins.op_str}".rstrip()


def print_diff(name: str, r: dict) -> None:
    fd = r["first_diff"]
    if fd is None:
        print(f"{name}: equal ({r['equal']} instructions, {r['obj_size']} bytes)")
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
    elf = baseelf_path(REPO_ROOT, ver)
    data = elf.read_bytes()
    phdrs = read_phdrs(data)
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
        if sym not in objfuncs:
            print(f"match_check: symbol {sym} not defined in {obj} "
                  f"(have: {', '.join(sorted(objfuncs)[:8])}{'...' if len(objfuncs) > 8 else ''})",
                  file=sys.stderr)
            return 2
        addr, size = funcs[fn]
        off = vaddr_to_off(phdrs, addr)
        base_bytes = data[off:off + size]
        ob, rl = objfuncs[sym]
        r = compare(ob, rl, base_bytes, addr)
        worst = min(worst, r["score"])
        if a.json:
            print(json.dumps({"func": fn, "symbol": sym, "addr": addr, "size": size,
                              "score": r["score"], "equal": r["equal"],
                              "obj_insns": r["obj_insns"], "base_insns": r["base_insns"],
                              "obj_size": r["obj_size"], "base_size": r["base_size"]}))
        elif a.diff or r["first_diff"] is not None:
            print_diff(fn if fn == sym else f"{fn} ({sym})", r)
        else:
            print(f"{fn}: equal")
    return 0 if worst == 1.0 else 1


if __name__ == "__main__":
    sys.exit(main())
