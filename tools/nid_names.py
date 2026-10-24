#!/usr/bin/env python3
"""
nid_names.py: name the executable's imports by recomputing their NIDs.

A PS4 import symbol is `<nid>#<lib>#<module>`, where the NID is the first
eight bytes of SHA-1(name + a fixed 16-byte suffix), little-endian, base64
with `+-` as the extra characters, padding dropped (the scheme the PS3 and
Vita used before it; public since the first PS4 homebrew). A NID is a hash of
a name, so a candidate name is verified, not looked up: the tool hashes every
name in the candidate lists and keeps those whose NID the executable imports.

    nid_names.py                 write config/imports.<slug>.txt and print a summary
    nid_names.py --name <sym>    print the NID of one name
    nid_names.py --check <file>  print which names of <file> (one per line) hit

Candidate names come from config/nid_candidates.txt (tracked: standard C and
C++ library names and the Sony API names used in this tree, one per line) and
from tools/ext/nid_candidates.txt (untracked: any further list, for example
names collected from public SDK documentation). Only names that hit are
written; a name is a fact about the API, and the lists are never copied in.
"""
from __future__ import annotations

import argparse
import base64
import hashlib
import struct
import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(Path(__file__).resolve().parent))
from tlg_version import baseelf_path, config_path, detect_version  # noqa: E402
from survey_elf import (DT_SCE_STRTAB, DT_SCE_SYMENT, DT_SCE_SYMTAB, DT_SCE_SYMTABSZ,  # noqa: E402
                        PT_DYNAMIC, PT_SCE_DYNLIBDATA, read_phdrs)

SUFFIX = bytes.fromhex("518D64A635DED8C1E6B039B1C3E55230")


def nid(name: str) -> str:
    d = hashlib.sha1(name.encode() + SUFFIX).digest()
    v = struct.unpack("<Q", d[:8])[0]
    return base64.b64encode(struct.pack(">Q", v), altchars=b"+-").decode().rstrip("=")


def imports(data: bytes) -> list[tuple[str, str, str, bool]]:
    """[(nid, lib, module, is_func)] for every undefined dynamic symbol."""
    phdrs = read_phdrs(data)
    dyn = next(p for p in phdrs if p["type"] == PT_DYNAMIC)
    dld = next(p for p in phdrs if p["type"] == PT_SCE_DYNLIBDATA)
    tags: dict[int, list[int]] = {}
    o = dyn["offset"]
    while True:
        tag, val = struct.unpack_from("<qQ", data, o)
        o += 16
        if tag == 0:
            break
        tags.setdefault(tag, []).append(val)
    strtab = dld["offset"] + tags[DT_SCE_STRTAB][0]
    symtab = dld["offset"] + tags[DT_SCE_SYMTAB][0]
    ent = tags.get(DT_SCE_SYMENT, [24])[0]
    out = []
    for i in range(tags[DT_SCE_SYMTABSZ][0] // ent):
        st_name, st_info, _o, _sh, st_value, _sz = struct.unpack_from("<IBBHQQ", data, symtab + i * ent)
        if not st_name or st_value:
            continue
        end = data.index(b"\0", strtab + st_name)
        parts = data[strtab + st_name:end].decode().split("#")
        out.append((parts[0], parts[1] if len(parts) > 1 else "", parts[2] if len(parts) > 2 else "",
                    (st_info & 0xF) == 2))
    return out


def candidates() -> list[str]:
    names = []
    for p in (REPO_ROOT / "config" / "nid_candidates.txt",
              REPO_ROOT / "tools" / "ext" / "nid_candidates.txt"):
        if p.exists():
            names += [l.strip() for l in p.read_text().splitlines()
                      if l.strip() and not l.startswith("#")]
    return names


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--name")
    ap.add_argument("--check", type=Path)
    a = ap.parse_args(argv)
    if a.name:
        print(nid(a.name))
        return 0
    ver = detect_version(REPO_ROOT)
    data = baseelf_path(REPO_ROOT, ver).read_bytes()
    imps = imports(data)
    by_nid = {n: (lib, mod, f) for n, lib, mod, f in imps}
    if a.check:
        for name in [l.strip() for l in a.check.read_text().splitlines() if l.strip()]:
            k = nid(name)
            print(f"{'HIT ' if k in by_nid else '    '} {name:40s} {k}")
        return 0
    hits = {}
    for name in candidates():
        k = nid(name)
        if k in by_nid:
            hits[k] = name
    out = config_path(REPO_ROOT, ver, "imports", "txt")
    lines = ["# The executable's imports: `<nid> <library> <module> <kind> <name>`, name",
             "# `?` until a candidate name's NID equals the import's (tools/nid_names.py).",
             "# Addresses are not here: the PLT and GOT slots are matched by relocation."]
    named = 0
    for n, lib, mod, f in sorted(imps, key=lambda t: (t[2], t[1], t[0])):
        name = hits.get(n, "?")
        named += name != "?"
        lines.append(f"{n} {lib} {mod} {'func' if f else 'obj'} {name}")
    out.write_text("\n".join(lines) + "\n")
    print(f"nid_names: {named}/{len(imps)} imports named; wrote {out.relative_to(REPO_ROOT)}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
