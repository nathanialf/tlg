#!/usr/bin/env python3
"""
layout_link.py: rebuild the executable's text segment and compare it whole.

The ico project's gate links every object at the original addresses, fills
the functions still unwritten with stubs taken from the user's own ELF, and
compares the result with the base byte for byte. This is that gate for a
target whose linker is not public: instead of a linker, the image is laid
out here.

    1. Start from the base text segment (the user's own eboot.elf): every
       function not yet claimed, the padding between functions, the PLT
       stubs, everything, exactly as shipped.
    2. For every row of config/matched.<slug>.txt, take the function's bytes
       from the compiled object and RESOLVE its relocations the way the
       original link did: a call to FUN_x becomes the displacement to FUN_x's
       address in the table; a reference to D_<hex> to that address; a call
       to an import to its PLT stub; a GOT load to the import's GOT slot; a
       string literal the object defines to the one place the base holds
       those bytes. Write the result at the function's address.
    3. Compare the image with the base text segment, whole. Any differing
       byte names the function it falls in (or the gap, which would mean a
       claimed function overran its size).

A relocation the resolver cannot place (a data symbol without a D_<hex>
name, a literal the base holds in two places) fails the function with a
message, never a guess. Only the text segment is rebuilt: the PLT, GOT,
dynamic tables and data segments are Sony's linker's and are read from the
base as they are.

    layout_link.py              build/<slug>/text.bin and build/<slug>/layout.json;
                                prints the differing functions; exit 1 if any
    layout_link.py --quiet
"""
from __future__ import annotations

import argparse
import json
import struct
import subprocess
import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(Path(__file__).resolve().parent))
from tlg_version import build_dir, config_path, detect_version  # noqa: E402
from base_elf import (BaseElf, R_X86_64_64, R_X86_64_32, R_X86_64_32S, R_X86_64_PC32,  # noqa: E402
                      R_X86_64_PLT32, R_X86_64_GOTPCREL, R_X86_64_GOTPCRELX, R_X86_64_REX_GOTPCRELX)
import match_check as mc  # noqa: E402


def load_matched(ver: str) -> list[tuple[str, str, str]]:
    rows = []
    p = config_path(REPO_ROOT, ver, "matched", "txt")
    if p.exists():
        for line in p.read_text().splitlines():
            s = line.split("#", 1)[0].split()
            if len(s) >= 2:
                rows.append((s[0], s[1], s[2] if len(s) > 2 else s[0]))
    return rows


def resolve_symbol_address(base: BaseElf, obj: Path, r: mc.Reloc) -> tuple[int | None, str]:
    """The address S the base gives the relocation's symbol, or (None, why)."""
    s = base.address_of(r.symbol)
    if s is not None:
        return s, ""
    # a symbol the object itself defines in a data section: a string literal
    # or a local constant; find its bytes in the base
    if isinstance(r.sym_section, int) and r.sym_section > 0:
        try:
            if r.sym_size == 0 and r.addend >= 0 and r.symbol.startswith("."):
                blob = mc.object_bytes_of(obj, r.sym_section, r.sym_value + r.addend, 0)
                hits = base.find_bytes(blob)
                if len(hits) == 1:
                    return hits[0] - r.addend, ""
                return None, (f"literal {blob[:24]!r} of {r.symbol} occurs {len(hits)} times in the base"
                              if hits else f"literal {blob[:24]!r} of {r.symbol} not found in the base")
            blob = mc.object_bytes_of(obj, r.sym_section, r.sym_value, r.sym_size)
            if blob:
                hits = base.find_bytes(blob)
                if len(hits) == 1:
                    return hits[0], ""
                return None, f"bytes of {r.symbol} occur {len(hits)} times in the base"
        except Exception as e:  # noqa: BLE001
            return None, f"{r.symbol}: {e}"
    return None, f"{r.symbol}: no address in the base (name it D_<hex> or FUN_<hex>, or add it to the function table)"


def apply_relocs(base: BaseElf, obj: Path, code: bytes, relocs: list[mc.Reloc], addr: int) -> tuple[bytearray, list[str]]:
    out = bytearray(code)
    errors = []
    for r in relocs:
        P = addr + r.offset
        if r.type in (R_X86_64_GOTPCREL, R_X86_64_GOTPCRELX, R_X86_64_REX_GOTPCRELX):
            slot = base.got_slots().get(BaseElf.base_identifier(r.symbol))
            if slot is None:
                errors.append(f"+0x{r.offset:x} {r.symbol}: no GOT slot in the base")
                continue
            struct.pack_into("<i", out, r.offset, slot + r.addend - P)
            continue
        S, why = resolve_symbol_address(base, obj, r)
        if S is None:
            errors.append(f"+0x{r.offset:x} {why}")
            continue
        try:
            if r.type in (R_X86_64_PC32, R_X86_64_PLT32):
                struct.pack_into("<i", out, r.offset, S + r.addend - P)
            elif r.type == R_X86_64_32S:
                struct.pack_into("<i", out, r.offset, S + r.addend)
            elif r.type == R_X86_64_32:
                struct.pack_into("<I", out, r.offset, (S + r.addend) & 0xFFFFFFFF)
            elif r.type == R_X86_64_64:
                struct.pack_into("<Q", out, r.offset, (S + r.addend) & 0xFFFFFFFFFFFFFFFF)
            else:
                errors.append(f"+0x{r.offset:x} {r.symbol}: relocation type {r.type} not handled")
        except struct.error:
            errors.append(f"+0x{r.offset:x} {r.symbol}: target 0x{S:x} out of range")
    return out, errors


def build_image(ver: str, log=print) -> dict:
    base = BaseElf(REPO_ROOT, ver)
    text_lo = base.text["vaddr"]
    image = bytearray(base.text_bytes())
    original = bytes(image)
    report = {"version": ver, "text_vaddr": text_lo, "text_size": len(image), "functions": {},
              "errors": {}, "differing": []}
    by_tu: dict[str, list[tuple[str, str]]] = {}
    for fn, tu, sym in load_matched(ver):
        by_tu.setdefault(tu, []).append((fn, sym))
    for tu, pairs in sorted(by_tu.items()):
        try:
            obj = mc.compile_tu(tu, ver)
        except subprocess.CalledProcessError:
            for fn, _ in pairs:
                report["errors"][fn] = f"{tu} failed to compile"
            continue
        objfuncs = mc.object_functions(obj)
        for fn, sym in pairs:
            if fn not in base.func_by_name:
                report["errors"][fn] = "not in the function table"
                continue
            sym = mc.resolve_symbol(objfuncs, fn, sym) or sym
            if sym not in objfuncs:
                report["errors"][fn] = f"{tu} does not define {sym}"
                continue
            addr, size = base.func_by_name[fn]
            code, relocs = objfuncs[sym]
            resolved, errs = apply_relocs(base, obj, code, relocs, addr)
            if errs:
                report["errors"][fn] = "; ".join(errs)
            if len(resolved) != size:
                report["errors"][fn] = (report["errors"].get(fn, "") +
                                        f"; size {len(resolved)} differs from the base's {size}").lstrip("; ")
            off = addr - text_lo
            n = min(len(resolved), size)
            image[off:off + n] = resolved[:n]
            report["functions"][fn] = {"tu": tu, "symbol": sym, "addr": addr, "size": size,
                                       "relocs": len(relocs), "resolved": not errs}
    # compare
    starts = [a for a, _, _ in base.functions]
    import bisect
    diffs: dict[str, int] = {}
    gap_bytes = 0
    i = 0
    n = len(image)
    while i < n:
        if image[i] == original[i]:
            i += 1
            continue
        va = text_lo + i
        k = bisect.bisect_right(starts, va) - 1
        if k >= 0 and va < base.functions[k][0] + base.functions[k][1]:
            diffs[base.functions[k][2]] = diffs.get(base.functions[k][2], 0) + 1
        else:
            gap_bytes += 1
        i += 1
    report["differing"] = [{"function": k, "bytes": v} for k, v in sorted(diffs.items())]
    report["gap_bytes_differing"] = gap_bytes
    report["identical"] = not diffs and not gap_bytes and not report["errors"]
    bd = build_dir(REPO_ROOT, ver)
    bd.mkdir(parents=True, exist_ok=True)
    (bd / "text.bin").write_bytes(image)
    (bd / "layout.json").write_text(json.dumps(report, indent=1))
    return report


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--quiet", action="store_true")
    a = ap.parse_args(argv)
    ver = detect_version(REPO_ROOT)
    r = build_image(ver)
    if not a.quiet:
        print(f"layout ({ver}): {len(r['functions'])} function(s) from source, "
              f"{sum(f['relocs'] for f in r['functions'].values())} relocation(s) resolved, "
              f"text segment {r['text_size']:,} bytes")
        for fn, why in sorted(r["errors"].items()):
            print(f"  ERROR {fn}: {why}")
        for d in r["differing"]:
            print(f"  DIFFERS {d['function']}: {d['bytes']} byte(s)")
        if r["gap_bytes_differing"]:
            print(f"  DIFFERS outside functions: {r['gap_bytes_differing']} byte(s)")
        print(f"layout: text segment {'IDENTICAL to the base' if r['identical'] else 'DIFFERS from the base'}")
    return 0 if r["identical"] else 1


if __name__ == "__main__":
    sys.exit(main())
