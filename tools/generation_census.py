"""Compiler-generation census of a text range of the base, per function.

Two instruction-selection habits separate LLVM 3.3 from 3.4 and later on
x86-64 (measured on tools/probe/batch*.cpp under every prebuilt release,
docs/DECISIONS.md D22): 3.3 sign-extends eax with `movsxd rax, eax` and
zeroes an 8-bit value with `xor r8, r8` (MOV8r0); 3.4 onward emit `cdqe`
and zero through the 32-bit register. Each function votes `old` or `new` by
the marks it contains; most functions contain none and inherit the stretch
around them. The script prints the stretches of agreeing votes and the
boundary functions, which docs/DECISIONS.md D22 records.

    .venv/bin/python -I tools/generation_census.py [--range lo:hi] [--votes]
"""
import argparse
import bisect
import re
import subprocess
import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(Path(__file__).resolve().parent))
from tlg_version import baseelf_path, config_path, detect_version  # noqa: E402

INS_RE = re.compile(r"^\s*([0-9a-f]+):\s+(\w+)\s*(.*)$")
R8 = {"al", "bl", "cl", "dl", "sil", "dil", "r8b", "r9b", "r10b", "r11b", "r12b", "r13b", "r14b", "r15b"}


def functions(ver: str, lo: int, hi: int) -> list[list]:
    out = []
    for line in config_path(REPO_ROOT, ver, "functions", "txt").read_text().splitlines():
        if not line.strip() or line.startswith("#"):
            continue
        a, s, name = line.split()[:3]
        a, s = int(a, 16), int(s, 16)
        if lo <= a < hi:
            out.append([a, s, name, 0, 0])  # old votes, new votes
    out.sort()
    return out


def vote(ver: str, funcs: list[list], lo: int, hi: int) -> None:
    elf = baseelf_path(REPO_ROOT, ver)
    dis = subprocess.run(["llvm-objdump-19", "-d", "--no-show-raw-insn", "--x86-asm-syntax=intel",
                          f"--start-address={lo:#x}", f"--stop-address={hi:#x}", str(elf)],
                         capture_output=True, text=True, check=True).stdout
    starts = [f[0] for f in funcs]
    for line in dis.split("\n"):
        m = INS_RE.match(line)
        if not m:
            continue
        a, mn, ops = int(m.group(1), 16), m.group(2), m.group(3)
        i = bisect.bisect_right(starts, a) - 1
        if i < 0 or a >= funcs[i][0] + funcs[i][1]:
            continue
        if mn == "cdqe":
            funcs[i][4] += 1
        elif mn == "movsxd" and ops == "rax, eax":
            funcs[i][3] += 1
        elif mn == "xor":
            p = [x.strip() for x in ops.split(",")]
            if len(p) == 2 and p[0] == p[1] and p[0] in R8:
                funcs[i][3] += 1


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--range", default="0:0x1a3e00", help="lo:hi addresses (hex); default the library region")
    ap.add_argument("--votes", action="store_true", help="print every voting function")
    a = ap.parse_args(argv)
    lo, _, hi = a.range.partition(":")
    lo, hi = int(lo, 16), int(hi, 16)
    ver = detect_version(REPO_ROOT)
    funcs = functions(ver, lo, hi)
    vote(ver, funcs, lo, hi)
    label = start = None
    count = 0
    stretches = []
    for addr, size, name, old, new in funcs:
        v = "old" if old and not new else "new" if new and not old else "mixed" if old and new else None
        if a.votes and v:
            print(f"  {name} {addr:#x} {size:#x} old={old} new={new}")
        if v == "mixed":
            print(f"  mixed votes: {name} {addr:#x} old={old} new={new}")
        if v in ("old", "new") and v != label:
            if label:
                stretches.append((label, start, addr, count))
            label, start, count = v, addr, 0
        count += 1
    if funcs:
        stretches.append((label, start, funcs[-1][0] + funcs[-1][1], count))
    print("stretch  first voter  next voter  functions")
    for lab, s, e, n in stretches:
        print(f"{lab:5s}  {s:#011x}  {e:#010x}  {n:5d}")
    old = sum(1 for f in funcs if f[3] and not f[4])
    new = sum(1 for f in funcs if f[4] and not f[3])
    print(f"functions {len(funcs)}: old votes {old}, new votes {new}, no mark {len(funcs) - old - new}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
