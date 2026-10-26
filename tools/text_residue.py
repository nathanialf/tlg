#!/usr/bin/env python3
"""tools/text_residue.py [--md] [--no-write] [--out <file>]: what the text
segment holds between the functions the unwind tables name.

config/functions.<slug>.txt comes from .eh_frame: one row per FDE (19,733).
The code span of the text segment also holds bytes no FDE covers. This tool
decodes every such gap and splits it at reference targets (the targets of
direct `call`/`jmp` rel32 in the text and of 8-byte pointers in the
writable and RELRO segments) and at padding runs, then classes each piece:

  padding   only nop and int3 instructions (alignment fill)
  plt       an import's PLT stub (tools/base_elf.py plt_stubs)
  function  starts at a reference target, has no zeroed PC-relative field,
            and decodes to a terminator (ret, jmp, ud2, hlt): a function the
            compiler emitted without an unwind entry (0xe270, a static
            initializer: push rbp ... call 0x41a0 ... ret, reached through a
            relocated pointer). A reference is a direct call or jump from a
            function of the table, or a pointer slot the loader relocates
            (R_X86_64_RELATIVE); a text address sitting in data with no
            relocation is stale and references nothing.
  residue   anything else: bytes the linker left behind from code it
            discarded, with their relocations resolved to zero (`lea rax,
            [rip+0]; ret`, `jmp +0`, `add rdi, -8; jmp +0`), fragments cut
            mid-instruction where a live function was laid over the head
            (0x1240: `c4 08`, the tail of `add rsp, 8`, then the pops and
            `jmp rax` of an epilogue), and unreferenced tails no live
            function contains in full (`leave; mov eax, ecx; ret`); not
            produced by any source, never reached from a function of the
            table (a reference from residue to residue is not a reference)

The rows go to config/residue.<slug>.txt as `<lo> <hi> <class> <note>`; the
`function` rows are the evidence for tools/survey_elf.py to add the function
to config/functions.<slug>.txt (docs/DECISIONS.md D13). Regenerate, never
edit.
"""
from __future__ import annotations

import argparse
import bisect
import re
import struct
import sys
from collections import Counter
from pathlib import Path

from capstone import CS_ARCH_X86, CS_MODE_64, Cs
from capstone.x86 import X86_OP_IMM, X86_OP_MEM, X86_REG_RIP

REPO_ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO_ROOT / "tools"))
from base_elf import BaseElf  # noqa: E402
from tlg_version import config_path  # noqa: E402

PAD = ("nop", "int3")
TERM = ("ret", "jmp", "ud2", "hlt")


def references(elf: BaseElf) -> tuple[Counter, Counter, dict]:
    """Targets of direct calls and jumps (rel8 and rel32, conditional too)
    and of RIP-relative operands from inside the functions of the table ->
    count; 8-byte pointers into
    the text the loader relocates -> count; and the source
    of one reference to each target, for the note. A reference from code
    outside the table (residue calling residue) is not a reference."""
    md = Cs(CS_ARCH_X86, CS_MODE_64)
    md.detail = True
    tv, tend = elf.text["vaddr"], elf.text["vaddr"] + elf.text["filesz"]
    calls: Counter = Counter()
    src: dict[int, str] = {}
    for a, sz, _n in elf.functions:
        for ins in md.disasm(elf.read(a, sz), a):
            ops = ins.operands
            if ins.mnemonic == "call" or ins.mnemonic.startswith("j"):
                if ops and ops[0].type == X86_OP_IMM:
                    t = ops[0].imm
                    if tv <= t < tend and not a <= t < a + sz:
                        calls[t] += 1
                        src.setdefault(t, f"{ins.mnemonic} at 0x{ins.address:x}")
            for op in ops:
                # a RIP-relative operand: the address of a function taken, or
                # data the compiler put in the text
                if op.type == X86_OP_MEM and op.mem.base == X86_REG_RIP:
                    t = ins.address + ins.size + op.mem.disp
                    if tv <= t < tend and not a <= t < a + sz:
                        calls[t] += 1
                        src.setdefault(t, f"{ins.mnemonic} at 0x{ins.address:x}")
    ptrs: Counter = Counter()
    syms, rels = elf._dynamic()
    for r_off, r_type, r_sym, r_add in rels:
        # a pointer the loader fills: RELATIVE (the target in the addend). A
        # slot holding a text address with no relocation is stale data the
        # loader never fixes, not a reference (621 such slots in the
        # writable segments; the six one-byte `ret`s they point to are not
        # functions).
        if r_type == 8 and tv < r_add < tend:
            ptrs[r_add] += 1
            src.setdefault(r_add, f"relocated pointer at 0x{r_off:x}")
    return calls, ptrs, src


def zeroed(ins) -> bool:
    """A PC-relative field the linker resolved to zero: `call/jmp +0` or a
    RIP-relative operand with displacement 0."""
    if ins.mnemonic in ("call", "jmp") and ins.size >= 5 and ins.operands \
            and ins.operands[0].type == X86_OP_IMM and ins.operands[0].imm == ins.address + ins.size:
        return True
    return any(op.type == X86_OP_MEM and op.mem.base == X86_REG_RIP and op.mem.disp == 0 for op in ins.operands)


def classify(elf: BaseElf):
    md = Cs(CS_ARCH_X86, CS_MODE_64)
    md.detail = True
    calls, ptrs, src = references(elf)
    plt = set(elf.plt_stubs().values())
    funcs = sorted(elf.functions)
    tv = elf.text["vaddr"]
    rows = []
    end = tv
    for a, sz, _n in funcs:
        if a > end:
            rows += classify_gap(elf, md, end, a, calls, ptrs, src, plt)
        end = max(end, a + sz)
    return rows


def classify_gap(elf, md, lo, hi, calls, ptrs, src, plt):
    ins = list(md.disasm(elf.read(lo, hi - lo), lo))
    if not ins:
        return [(lo, hi, "residue", "starts mid-instruction" if lo else "ELF header")]
    decoded = ins[-1].address + ins[-1].size
    # split points: reference targets, PLT stubs, and the ends of padding runs
    cuts = {i.address for i in ins if calls[i.address] or ptrs[i.address] or i.address in plt}
    prev_pad = None
    for i in ins:
        is_pad = i.mnemonic in PAD
        if prev_pad is not None and prev_pad != is_pad:
            cuts.add(i.address)
        prev_pad = is_pad
    pieces, cur = [], []
    for i in ins:
        if i.address in cuts and cur:
            pieces.append(cur)
            cur = []
        cur.append(i)
    if cur:
        pieces.append(cur)
    out = []
    for p in pieces:
        plo, phi = p[0].address, p[-1].address + p[-1].size
        if all(i.mnemonic in PAD for i in p):
            out.append((plo, phi, "padding", ""))
        elif plo in plt:
            out.append((plo, phi, "plt", ""))
        else:
            ref = []
            if calls[plo]:
                ref.append(f"reached {calls[plo]}x ({src[plo]})")
            if ptrs[plo]:
                ref.append(f"pointed to {ptrs[plo]}x ({src[plo]})")
            z = [i for i in p if zeroed(i)]
            if ref and not z and p[-1].mnemonic in TERM:
                out.append((plo, phi, "function", ", ".join(ref)))
            else:
                why = []
                if z:
                    why.append(f"zeroed field at 0x{z[0].address:x}")
                if not ref:
                    why.append("unreferenced")
                elif not z:
                    why.append("referenced but no terminator")
                out.append((plo, phi, "residue", "; ".join(why) + (f" ({', '.join(ref)})" if ref and z else "")))
    if decoded < hi:
        out.append((decoded, hi, "residue", "starts mid-instruction"))
    return out


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--md", action="store_true")
    ap.add_argument("--no-write", action="store_true")
    ap.add_argument("--out", type=Path, help="write here instead of config/residue.<slug>.txt")
    a = ap.parse_args(argv)
    elf = BaseElf(REPO_ROOT)
    rows = classify(elf)
    by = Counter()
    nbytes = Counter()
    for lo, hi, cls, _ in rows:
        by[cls] += 1
        nbytes[cls] += hi - lo
    out = a.out or config_path(REPO_ROOT, elf.version, "residue", "txt")
    lines = [
        "# The text segment between the functions the unwind tables name: `<lo> <hi> <class>",
        "# <note>`. Written by tools/text_residue.py (its docstring has the classes and the",
        "# rule); regenerate, never edit. `function` rows are code with no unwind entry that a",
        "# live reference reaches; tools/survey_elf.py adds them to the function table",
        "# (docs/DECISIONS.md D13). `residue` is the linker's: never source, never claimed.",
        "# " + "; ".join(f"{cls}: {by[cls]} pieces, {nbytes[cls]:,} bytes" for cls in ("padding", "plt", "function", "residue")),
    ]
    lines += [f"0x{lo:08x} 0x{hi:08x} {cls} {note}".rstrip() for lo, hi, cls, note in rows if cls != "padding"]
    if not a.no_write:
        out.write_text("\n".join(lines) + "\n")
    if a.md:
        print("| class | pieces | bytes |\n|---|---|---|")
        for cls in ("padding", "plt", "function", "residue"):
            print(f"| {cls} | {by[cls]:,} | {nbytes[cls]:,} |")
    else:
        print("text_residue: " + lines[5][2:] + f" -> {out}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
