"""tools/eh_objects.py [--md] [<lo> <hi>]: the executable's objects, read from .eh_frame.

Every FDE names its CIE by a relative offset, and the linker kept each object's
CIE rather than merging the byte-identical copies, so the functions whose FDEs
share one CIE came from one object file: a translation unit's boundaries,
which docs/FINISHING.md's assembly of source files in the base's order needs
and which docs/DECISIONS.md D44 rules on. Round 99A's finding, checked by the
supervisor against three files whose bounds were known from their functions
(hkClass.cpp, the vertex buffer utility, the broad phase tree).

Output: one line per object, `<first function> <last function> <count>`, in
address order; with --md a Markdown table. With <lo> <hi>, only the objects
that hold a function in [lo, hi). The readers are tools/survey_elf.py's.
"""
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import survey_elf as s  # noqa: E402

ROOT = Path(__file__).resolve().parents[1]


def objects(data):
    ph = s.read_phdrs(data)
    hdr = next(p for p in ph if p["type"] == s.PT_GNU_EH_FRAME)

    def off_to_va(o):
        return hdr["vaddr"] + (o - hdr["offset"])

    o = hdr["offset"]
    _, e1, e2, te = data[o:o + 4]
    o += 4
    _, o = s.read_encoded(data, o, e1, off_to_va, hdr["vaddr"])
    n, o = s.read_encoded(data, o, e2, off_to_va, hdr["vaddr"])
    rows = []
    for _ in range(n):
        ini, o = s.read_encoded(data, o, te, off_to_va, hdr["vaddr"])
        fde, o = s.read_encoded(data, o, te, off_to_va, hdr["vaddr"])
        fo = s.vaddr_to_off(ph, fde)
        cie_ptr, = struct.unpack_from("<I", data, fo + 4)
        rows.append((ini, fo + 4 - cie_ptr))
    rows.sort()
    out = []
    for ini, cie in rows:
        if out and out[-1][2] == cie:
            out[-1][1] = ini
            out[-1][3] += 1
        else:
            out.append([ini, ini, cie, 1])
    return [(lo, hi, cnt) for lo, hi, _, cnt in out]


def main(argv):
    md = "--md" in argv
    args = [a for a in argv if a != "--md"]
    data = (ROOT / "baserom" / "base" / "eboot.elf").read_bytes()
    objs = objects(data)
    if len(args) == 2:
        lo, hi = int(args[0], 16), int(args[1], 16)
        objs = [o for o in objs if o[1] >= lo and o[0] < hi]
    if md:
        print("| first | last | functions |\n|---|---|---|")
        for lo, hi, cnt in objs:
            print(f"| 0x{lo:x} | 0x{hi:x} | {cnt} |")
    else:
        for lo, hi, cnt in objs:
            print(f"0x{lo:x} 0x{hi:x} {cnt}")
    print(f"# {len(objs)} objects", file=sys.stderr)


if __name__ == "__main__":
    main(sys.argv[1:])
