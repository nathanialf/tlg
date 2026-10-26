#!/usr/bin/env python3
"""
fingerprint.py: compiler fingerprints over a whole disassembly.

Counts, over every instruction of the base executable (or of a built object
with --obj), the code-generation choices that tell compiler generations and
settings apart, so a compiler or flag decision rests on the whole program
rather than on the few functions already rewritten (docs/DECISIONS.md,
"The standard"):

    cdqe / movsxd rax,eax     the MC-lowering shrink (upstream: always cdqe)
    vzeroupper / ymm          AVX-256 use and the transition guard
    ud2 after call            TrapUnreachable (upstream PS4: 3.9+)
    int 0x41 / int3           __builtin_debugtrap form (upstream PS4: 3.7+)
    adjacent qword imm stores two 8-byte constant stores to consecutive
                              addresses left unmerged (upstream 3.7+ merges
                              them into one vector store: the vmovq, vpslldq,
                              store signature counted beside it)
    push rbp;mov rbp,rsp      functions keeping a frame pointer, by
                              non-leaf/leaf (leaf = no call in the body)
    stack protector           functions loading the canary
    movbe/andn/lzcnt/popcnt   the Jaguar instruction set in use
    sub eax,..;movsxd/cdqe    32-bit arithmetic then extension (the -fwrapv
                              shape) vs movsxd of both operands then 64-bit
                              arithmetic (the nsw-widened shape)

    fingerprint.py                      the base executable, with functions from
                                        config/functions.<slug>.txt
    fingerprint.py --obj <file.o>       a built object (function bounds from symbols)
    fingerprint.py --range 0x1a3e00:    only functions at or above that address
    fingerprint.py --range :0x1a3e00    only functions below it
    fingerprint.py --json               machine-readable
"""
from __future__ import annotations

import argparse
import json
import re
import subprocess
import sys
from collections import Counter
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(Path(__file__).resolve().parent))
from tlg_version import baseelf_path, build_dir, config_path, detect_version  # noqa: E402

OBJDUMP = "llvm-objdump-19"
INS_RE = re.compile(r"^\s*([0-9a-f]+):\s*(?:(?:[0-9a-f]{2} )+\s*)?\t?([a-z0-9]+)\s*(.*)$")


RELOC_RE = re.compile(r"^\s*([0-9a-f]+):\s+R_X86_64_\w+\s+(\S+)")


def disassemble(path: Path, extra: list[str]) -> list[tuple[int, str, str]]:
    out = subprocess.run([OBJDUMP, "-d", "--no-show-raw-insn", "--x86-asm-syntax=intel", *extra, str(path)],
                         capture_output=True, text=True, check=True).stdout
    ins = []
    for line in out.split("\n"):
        m = INS_RE.match(line)
        if m:
            ins.append((int(m.group(1), 16), m.group(2), m.group(3).strip()))
    return ins


def object_canary_sites(obj: Path) -> set[int]:
    """Addresses of the instructions carrying a relocation against
    __stack_chk_guard or __stack_chk_fail in an object (`objdump -dr` prints
    the relocation under its instruction; the relocation's own offset is the
    field inside the instruction, which `measure` would never see)."""
    out = subprocess.run([OBJDUMP, "-dr", "--no-show-raw-insn", str(obj)], capture_output=True, text=True,
                         check=True).stdout
    sites = set()
    at = None
    for line in out.split("\n"):
        m = RELOC_RE.match(line)
        if m:
            if at is not None and m.group(2).split("-")[0].split("+")[0] in ("__stack_chk_guard", "__stack_chk_fail"):
                sites.add(at)
            continue
        m = INS_RE.match(line)
        if m:
            at = int(m.group(1), 16)
    return sites


def base_canary_sites(ins: list[tuple[int, str, str]], ver: str) -> set[int]:
    """Addresses of the instructions that load __stack_chk_guard (through its
    GOT slot) or call __stack_chk_fail (its PLT stub) in the base. The
    protector's own shape (where the canary is parked, what sits between the
    load and the store) varies with the frame and the scheduler, the symbols
    do not."""
    from base_elf import BaseElf
    base = BaseElf(REPO_ROOT, ver)
    guard = base.got_slots().get("__stack_chk_guard")
    fail = base.plt_stubs().get("__stack_chk_fail")
    sites = set()
    rip = re.compile(r"\[rip ([+-]) 0x([0-9a-f]+)\]")
    for i, (a, mn, ops) in enumerate(ins):
        if mn == "call" and fail is not None and ops == f"0x{fail:x}":
            sites.add(a)
            continue
        m = rip.search(ops)
        if m and guard is not None and i + 1 < len(ins):
            disp = int(m.group(2), 16) * (1 if m.group(1) == "+" else -1)
            if ins[i + 1][0] + disp == guard:
                sites.add(a)
    return sites


def function_bounds(ver: str) -> list[tuple[int, int]]:
    out = []
    for line in config_path(REPO_ROOT, ver, "functions", "txt").read_text().splitlines():
        s = line.split("#", 1)[0].split()
        if len(s) >= 3:
            out.append((int(s[0], 16), int(s[1], 16)))
    return out


def object_bounds(obj: Path) -> list[tuple[int, int]]:
    from elftools.elf.elffile import ELFFile
    out = []
    with obj.open("rb") as f:
        elf = ELFFile(f)
        for sym in elf.get_section_by_name(".symtab").iter_symbols():
            if sym["st_info"]["type"] == "STT_FUNC" and sym["st_size"]:
                sec = elf.get_section(sym["st_shndx"])
                out.append((sec["sh_addr"] + sym["st_value"], sym["st_size"]))
    return out


def measure(ins: list[tuple[int, str, str]], bounds: list[tuple[int, int]],
            canary_sites: set[int] | None = None) -> dict:
    c: Counter = Counter()
    by_addr = {a: i for i, (a, _, _) in enumerate(ins)}
    canary_sites = canary_sites or set()
    for i, (a, mn, ops) in enumerate(ins):
        nxt = ins[i + 1] if i + 1 < len(ins) else None
        prv = ins[i - 1] if i else None
        if mn == "cdqe":
            c["cdqe"] += 1
            if prv and prv[1] in ("sub", "add", "dec", "inc", "imul", "lea") and prv[2].startswith("eax"):
                c["cdqe after 32-bit arith on eax"] += 1
        elif mn == "movsxd" and ops == "rax, eax":
            c["movsxd rax, eax"] += 1
            if prv and prv[1] in ("sub", "add", "dec", "inc", "imul", "lea") and prv[2].startswith("eax"):
                c["movsxd rax,eax after 32-bit arith on eax"] += 1
        elif mn == "movsxd" and re.match(r"r\w+, dword ptr", ops):
            c["movsxd reg, dword ptr [mem]"] += 1
        if mn == "vzeroupper":
            c["vzeroupper"] += 1
        if "ymm" in ops:
            c["ymm operand"] += 1
        if mn == "ud2":
            c["ud2"] += 1
            if prv and prv[1] == "call":
                c["ud2 after call"] += 1
        if mn == "int" and ops == "0x41":
            c["int 0x41"] += 1
        if mn == "int3":
            c["int3"] += 1
        if mn in ("movbe", "andn", "lzcnt", "tzcnt", "popcnt", "blsr", "blsi", "bextr", "sarx", "shlx", "shrx", "rorx"):
            c[f"bmi/abm: {mn}"] += 1
        if mn == "vmovq" and re.match(r"xmm\d+, r", ops) and nxt and nxt[1] == "vpslldq":
            c["vmovq r64 + vpslldq (vector build)"] += 1
            if i + 2 < len(ins) and ins[i + 2][1].startswith("vmov") and "xmmword ptr [" in ins[i + 2][2]:
                c["constant-store merge signature (vmovq,vpslldq,store)"] += 1
        m1 = re.match(r"qword ptr \[(\w+)(?: \+ (0x[0-9a-f]+|\d+))?\], (-?0x[0-9a-f]+|-?\d+)$", ops) if mn == "mov" else None
        if m1 and nxt and nxt[1] == "mov":
            m2 = re.match(r"qword ptr \[(\w+)(?: \+ (0x[0-9a-f]+|\d+))?\], (-?0x[0-9a-f]+|-?\d+)$", nxt[2])
            if m2 and m1.group(1) == m2.group(1):
                o1 = int(m1.group(2) or "0", 0); o2 = int(m2.group(2) or "0", 0)
                if o2 == o1 + 8:
                    c["adjacent qword imm stores (unmerged)"] += 1
    # per-function prologue and protector
    fp_leaf = fp_nonleaf = noleaf_fp = leaf = nonleaf = canary = 0
    for addr, size in bounds:
        i = by_addr.get(addr)
        if i is None:
            continue
        j = i
        has_call = False
        has_canary = False
        while j < len(ins) and ins[j][0] < addr + size:
            if ins[j][1] == "call":
                has_call = True
            # the canary: a reference to __stack_chk_guard or __stack_chk_fail
            # (base_canary_sites, object_canary_sites)
            if ins[j][0] in canary_sites:
                has_canary = True
            j += 1
        has_fp = ins[i][1] == "push" and ins[i][2] == "rbp" and i + 1 < len(ins) and ins[i + 1][1] == "mov" and ins[i + 1][2] == "rbp, rsp"
        if has_call:
            nonleaf += 1
            fp_nonleaf += has_fp
        else:
            leaf += 1
            fp_leaf += has_fp
        canary += has_canary
    c["functions"] = len(bounds)
    c["non-leaf functions"] = nonleaf
    c["non-leaf with frame pointer"] = fp_nonleaf
    c["leaf functions"] = leaf
    c["leaf with frame pointer"] = fp_leaf
    c["functions loading a stack canary"] = canary
    c["instructions"] = len(ins)
    return dict(c)


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--obj", type=Path)
    ap.add_argument("--json", action="store_true")
    ap.add_argument("--range", help="lo:hi addresses (hex), either side optional")
    a = ap.parse_args(argv)
    lo, hi = 0, 1 << 64
    if a.range:
        l, _, h = a.range.partition(":")
        lo = int(l, 16) if l else 0
        hi = int(h, 16) if h else 1 << 64
    ver = detect_version(REPO_ROOT)
    if a.obj:
        ins = disassemble(a.obj, [])
        bounds = object_bounds(a.obj)
        sites = object_canary_sites(a.obj)
        label = str(a.obj)
    else:
        elf = baseelf_path(REPO_ROOT, ver)
        ins = disassemble(elf, [])
        bounds = function_bounds(ver)
        sites = base_canary_sites(ins, ver)
        label = str(elf.relative_to(REPO_ROOT))
    if a.range:
        bounds = [(x, s) for x, s in bounds if lo <= x < hi]
        ins = [t for t in ins if lo <= t[0] < hi]
        label += f" [{a.range}]"
    r = measure(ins, bounds, sites)
    if a.json:
        print(json.dumps({"target": label, **r}, indent=1))
        return 0
    print(f"fingerprint: {label}")
    for k in sorted(r, key=lambda k: (k.startswith(("functions", "non-leaf", "leaf", "instructions")), k)):
        print(f"  {k:<46} {r[k]:>10,}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
