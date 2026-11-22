#!/usr/bin/env python3
"""
module_boundary.py: where the library's data ends and the game's begins.

The game region (src/game/, 0x1a3e00 up) is built as one module
(tools/game_module.py): every game translation unit linked into one module
before the -O2 pipeline and code generation. An object a game source
declares and no game file defines yet gets a generated stand-in definition
(protected, zero-initialised, writable) when the base puts it in the GAME's
part of the data, so the code reaches it PC-relative as the base does; a
library object stays a declaration, which the code reaches through the GOT
as the base does. This tool writes that partition, config/modules.<slug>.txt,
from the base:

    1. The census: every RIP-relative operand of the code, by the region of
       the instruction (`lib` below 0x1a3e00, `game` from it, both inside a
       function of config/functions.<slug>.txt; `crt` for code no function
       of the table holds: the start and end code the linker adds, D13) and
       the target address. GOT slots are left out (a GOT load names a slot,
       not an object), and so is any target outside the loaded segments.
    2. Per data area (the read-only data after the PLT, the RELRO, the
       initialised data, the NOBITS tail), the cut: the place between two
       consecutive referenced targets that leaves the fewest targets on the
       wrong side (a target with a game site and none from the library below
       it, a target with no game site above it). Below the cut is the
       library's (`lib`), above it the game's (`game`). The linker laid the
       library's input sections out before the game's, so the cut is clean
       but for a few objects.
    3. The exceptions above the cut: a target no game instruction references
       is carved out from the previous referenced target (exclusive) to it
       (inclusive), so the object holding it, a vtable referenced at its
       address point included, is not the game's: `lib` when library code
       references it, `crt` when only the CRT does.
    4. The read-only data is the game's whole, cut or not: it interleaves
       (the header counts the runs), and an object of it a game source
       declares is a constant the game reaches PC-relative.
    5. An object the code reaches through a GOT slot (the slot's RELATIVE
       target: the base's 0x14b2060 is one, loaded by game code at
       0xea34f9) is a declaration whoever loads it: carved out as `lib`
       from its address to the next referenced target.
    6. The thread-locals (PT_TLS, interleaved): a variable is the library's
       when a library instruction accesses it, else the game's; an access is
       the linker-relaxed `mov rax, fs:[0]; add rax, [rip+slot]` (D23), the
       slot holding the variable's thread-pointer offset.
    7. The GOT, the PT_SCE_PROCPARAM block and the PLT are neither.

Each line is `<lo> <hi> <owner> <area> [note]`, half-open, sorted, covering
the data areas; tools/game_module.py reads it (`owner_of`). The file is a
fact about the base: regenerated, never edited.

    module_boundary.py            write config/modules.<slug>.txt
    module_boundary.py --check    regenerate in memory, exit 1 if the file differs

Local data (config/local_data.<slug>.txt, one `<symbol>` per row, written by
hand with the variable): a game variable that was local to the optimiser when
the base was built, though the source declares it for every file. GlobalOpt
turns a variable into a one-bit value only when it has local linkage and every
store is the initial value, one other constant, or a value loaded from the
variable itself (lib/Transforms/IPO/GlobalOpt.cpp of 3.7.1: ProcessGlobal
returns before ProcessInternalGlobal unless hasLocalLinkage; the shrink is
TryToShrinkGlobalToBoolean), and the base's code shows which variables it
did that to: a one-bit load is masked (`movzx; and 1`, `mov; xor 1; test 1`,
`test byte, 1`), where a bool that kept its byte is compared whole
(`cmp byte, 0`). tools/game_module.py gives a row's variable internal linkage
in the linked module before the pipeline; a row is never trusted:
`local_proof` reads every access of the variable in the game's code and
refuses the row unless

    - no access compares the byte whole, takes another width, or does
      anything but load or store the byte;
    - at least one load is masked; a loaded byte's first use within WINDOW
      instructions is the mask, or the byte is kept (stored or copied, read
      later: not judged), never a test of the whole byte; a register is
      stored at most as often as a byte is kept or a masked copy is put back
      (the saved copy: GlobalOpt accepts a store of 0, of the one other
      constant, or of a value loaded from the variable itself, GlobalStatus's
      analyzeGlobal and TryToShrinkGlobalToBoolean of LLVM 3.7.1; the shrink
      turns the loaded copy into a load of the bit, so the copy is either the
      byte kept whole or `mov r, byte; and r, 1` with `mov byte, r` after it
      into the same operand, the register and the address untouched between:
      a "copy", _put_back);
    - every store of a constant stores 0 or 1, and 1 is stored somewhere (a
      variable never set would have been folded to its initial value).

A thread-local's accesses are found from its `add rax, [rip+slot]` sites
(item 6), following the address register and its 64-bit copies for WINDOW
instructions along every path from the site: a direct jump is followed to
its target and a conditional one on both sides, to a `ret`, an indirect jump
or the function's end; an ordinary variable's are the RIP-relative operands
that name it. A loaded byte's first use is read the same way, on every path:
whole on any path refuses the row, another use on any path is a kept byte.
What this can still miss, and so cannot refuse: an access more than WINDOW
instructions from its site; one through an address kept in memory (spilled,
or stored in an object) or passed to a callee, or in a register a call
preserves only by the callee's own saving; one behind an indirect jump (a
jump table); an address formed any other way than the site's two
instructions; a loaded byte copied to another register or to memory before
it is tested (a kept byte, not judged). It does not invent an access: a
register is read as the address only on a path where it still holds it. A
function that does not decode whole from its first byte is read in text
order from the site, as before.

Once-stored pointers (a row `<symbol> once <function> <unit>` of the same
file): a game pointer variable that was local to the optimiser and stored
once with a constant. GlobalOpt, for a variable with local linkage
(ProcessGlobal, lib/Transforms/IPO/GlobalOpt.cpp:1706 of 3.7.1) that
GlobalStatus finds "stored once" (lib/Transforms/Utils/GlobalStatus.cpp:
78-123: every store is of the initial value, of a value loaded from the
variable, or of one other value; a store OF its address, a call taking it,
or any other user that is not a load, store, cast, GEP, select, PHI or
compare is a refusal, :79-81, :153-158), with a null initial value and a
constant stored (ProcessInternalGlobal's StoredOnce branch, :1807-1835;
OptimizeOnceStoredGlobal, :1555-1588), rewrites every use of a loaded value
that would trap if it were null to the constant
(OptimizeAwayTrappingUsesOfLoads, :738-800, and
OptimizeAwayTrappingUsesOfValue, :677-736): a call through the loaded
pointer becomes a direct call to the stored function (which the inliner may
then inline), a load or store through it a direct access; a compare with
null is not rewritten (OptimizeAwayTrappingUsesOfValue has no case for it),
so every null test stays. `once_proof` reads every
access of the variable's eight bytes in the WHOLE executable's code (the
library's, the game's and the CRT's RIP-relative operands, item 1) and every
dynamic relocation whose addend falls in them, and refuses the row unless
the base shows:

    - exactly one store, a whole-width `mov qword [var], reg` whose register
      was last written, in text order before it and with no call, jump or
      `ret` between, by `lea reg, [rip+X]` (the stored value is the
      constant X, not null), inside the row's <function>;
    - every other access a whole-width load whose value is only compared
      with null: `cmp qword [var], 0`, or `mov reg, qword [var]` whose first
      use on every path within WINDOW instructions is `test reg, reg` or
      `cmp reg, 0`;
    - at least one such load (a variable never loaded is deleted, not
      rewritten);
    - no load called through (`call qword [var]`, or the loaded register
      called): the form of a variable the optimiser did not see as stored
      once with local linkage, since it would have made the call direct;
      no load used any other way (passed, stored, dereferenced: a use the
      rewrite would or would not touch, which this proof does not judge);
      no `lea` of it, no access of another width or at another offset, no
      relocation naming it (the address taken).

tools/game_module.py gives a proven row's variable internal linkage in the
linked module, as for a one-bit row, and refuses the module unless exactly
one store to the variable is in its units' unoptimised IR, in <unit>, of a
constant (`@...`): the store the compiler sees is the module's own, in the
unit of the base's one store; no writer is generated for it. What this can
still miss, and so cannot refuse: an access through an address formed any
other way than a RIP-relative operand or a relocation (none is known: the
code is position-independent); a stored register written by an instruction
the backward reading does not see (it reads the text, not the paths: a
register set on another path into a join is read as the nearer writer); a
use of the loaded value beyond WINDOW instructions, behind an indirect jump,
or after it was copied to another register or to memory (read as `used`,
which refuses: it does not accept what it cannot see); that the source
called through the pointer at all (the null test alone is what a source that
never calls it gives too: the direct call or inlined body after the test is
the module's to reproduce, measured by the rows, not by this proof); a
second store a unit not yet written will add (the base has one, so the
written source can have only that one).

    module_boundary.py --local    prove every row of config/local_data.<slug>.txt, exit 1 on a refusal
    module_boundary.py --self-test   the once-stored proof on the base's rows and on refused shapes
"""
from __future__ import annotations

import argparse
import bisect
import re
import struct
import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(Path(__file__).resolve().parent))
from base_elf import PT_TLS, BaseElf  # noqa: E402
from survey_elf import PT_LOAD  # noqa: E402
from tlg_version import config_path, detect_version  # noqa: E402

GAME_START = 0x1a3e00          # docs/DECISIONS.md D6: the game region's first address
PT_SCE_RELRO, PT_SCE_PROCPARAM = 0x61000010, 0x61000001
RIP = re.compile(r"\[rip ([+-]) 0x([0-9a-f]+)\]")
TLS_ADD = re.compile(r"^rax, qword ptr \[rip ([+-]) 0x([0-9a-f]+)\]$")
REG64 = ["rax", "rbx", "rcx", "rdx", "rsi", "rdi", "rbp", "rsp"] + [f"r{i}" for i in range(8, 16)]


def census(base: BaseElf) -> tuple[list[tuple[int, int, str]], dict]:
    """[(site, target, region)] for every RIP-relative operand, and the code
    span's facts (PLT range)."""
    from capstone import CS_ARCH_X86, CS_MODE_64, Cs
    md = Cs(CS_ARCH_X86, CS_MODE_64)
    plt = base.plt_stubs()
    plt_lo, plt_hi = min(plt.values()), max(plt.values()) + 16
    text = base.text
    tdata = base.data[text["offset"]:text["offset"] + text["filesz"]]
    spans = []   # (lo, hi, region): the table's functions, and the gaps between them below the PLT
    pos = 0
    for a, s, _n in sorted(base.functions):
        if a >= plt_lo:
            break
        if a > pos:
            spans.append((pos, a, "crt"))
        spans.append((a, a + s, "lib" if a < GAME_START else "game"))
        pos = max(pos, a + s)
    if pos < plt_lo:
        spans.append((pos, plt_lo, "crt"))
    refs = []
    tls_adds = []   # (site, slot, region) of `add rax, [rip+slot]` after `mov rax, fs:[0]`
    for lo, hi, region in spans:
        off = lo
        prev_fs = False
        while off < hi:
            end = off
            for addr, size, mn, ops in md.disasm_lite(tdata[off - text["vaddr"]:hi - text["vaddr"]], off):
                end = addr + size
                m = RIP.search(ops)
                if m:
                    disp = int(m.group(2), 16) * (1 if m.group(1) == "+" else -1)
                    refs.append((addr, end + disp, region))
                    if prev_fs and mn == "add" and TLS_ADD.match(ops):
                        tls_adds.append((addr, end + disp, region))
                prev_fs = mn == "mov" and ops == "rax, qword ptr fs:[0]"
            # the decoder stops at a byte it cannot decode (residue in a gap): step over it
            off = end + 1 if end < hi else end
    return refs, {"plt": (plt_lo, plt_hi), "tls_adds": tls_adds}


WINDOW = 25
_LEGACY = {"ax": "rax", "bx": "rbx", "cx": "rcx", "dx": "rdx", "si": "rsi", "di": "rdi", "bp": "rbp", "sp": "rsp"}
FAMILY: dict[str, str] = {}
for _w, _q in _LEGACY.items():
    for _n in (_q, "e" + _w, _w, _w + "l" if _w in ("si", "di", "bp", "sp") else _w[0] + "l"):
        FAMILY[_n] = _q
    if _w in ("ax", "bx", "cx", "dx"):
        FAMILY[_w[0] + "h"] = _q
for _i in range(8, 16):
    for _sfx in ("", "d", "w", "b"):
        FAMILY[f"r{_i}{_sfx}"] = f"r{_i}"
CALL_CLOBBERED = {"rax", "rcx", "rdx", "rsi", "rdi", "r8", "r9", "r10", "r11"}
MEM = re.compile(r"^(?:(byte|word|dword|qword|xmmword|ymmword|tbyte) ptr )?(?:[a-z]s:)?\[(.*)\]$")
NO_DEST = ("cmp", "test", "push", "call", "jmp", "ret", "nop", "bt", "ucomis", "comis", "vucomis", "vcomis")
LOCAL_KINDS = ("masked", "copy", "kept", "plain", "store0", "store1", "store_reg", "other")
CALLEE_SAVED = {"rbx", "rbp", "r12", "r13", "r14", "r15"}


def _successors(insns, index, k) -> list[int]:
    """The instructions that can run after instruction k inside its function:
    the next one in text order and a direct jump's target (an indirect jump,
    a jump out of the function and a `ret` have none)."""
    _addr, _size, mn, ops = insns[k]
    if mn == "ret":
        return []
    nxt = [k + 1] if k + 1 < len(insns) else []
    if not mn.startswith("j"):
        return nxt
    t = index.get(int(ops, 16)) if re.fullmatch(r"0x[0-9a-f]+", ops) else None
    target = [t] if t is not None else []
    return target if mn == "jmp" else nxt + target


def _walk(insns, index, i, limit):
    """Instruction numbers after i, each once, to `limit` instructions along a
    path. With `index` (address -> number over the whole function) the paths
    follow direct jumps and both sides of a conditional one; without it the
    order is the text's. The caller sends False to end the path it is on."""
    if index is None:
        for k in range(i + 1, min(i + 1 + limit, len(insns))):
            if (yield k) is False:
                return
        return
    seen = {i}
    todo = [(k, 1) for k in reversed(_successors(insns, index, i))]
    while todo:
        k, depth = todo.pop()
        if k in seen or depth > limit:
            continue
        seen.add(k)
        if (yield k) is False:
            continue
        todo.extend((n, depth + 1) for n in reversed(_successors(insns, index, k)))


def _put_back(insns, index, j, fam, operand) -> str | None:
    """Whether the bit masked at instruction j (`and <fam>, 1`) is stored back
    into the variable it was loaded from: the text of the first
    `mov byte ptr [<operand>], <fam's byte>` on a path from j, or None. This is
    the shrunk form of a saved copy put back (GlobalOpt's
    TryToShrinkGlobalToBoolean: a store of a loaded copy of the variable
    becomes a store of the i1 loaded, whose byte the code generator masks). A
    path ends where the copy or a register of the variable's address is
    written or read by anything else, at a `ret`, and at a call unless the
    copy and the address are in registers a call preserves."""
    addr_regs = {FAMILY[x] for x in re.findall(r"[a-z][a-z0-9]+", operand) if x in FAMILY}
    walk = _walk(insns, index, j, WINDOW)
    k = next(walk, None)
    while k is not None:
        a2, _s2, mn2, ops2 = insns[k]
        p2 = ops2.split(", ") if ops2 else []
        go = True
        if mn2 == "ret":
            go = False
        elif mn2 == "call":
            go = fam in CALLEE_SAVED and addr_regs <= CALLEE_SAVED
        elif mn2 != "nop":
            m = MEM.match(p2[0]) if p2 else None
            if (mn2 == "mov" and len(p2) == 2 and m and m.group(1) == "byte" and m.group(2) == operand
                    and FAMILY.get(p2[1]) == fam):
                return f"0x{a2:x}: {mn2} {ops2}"
            if any(FAMILY.get(x) == fam for x in re.findall(r"[a-z][a-z0-9]+", ops2)):
                go = False
            elif p2 and FAMILY.get(p2[0]) in addr_regs and not mn2.startswith(NO_DEST):
                go = False
        try:
            k = walk.send(go)
        except StopIteration:
            k = None
    return None


def _classify(insns, i, is_var, index=None) -> tuple[str, str] | None:
    """What instruction i does to the variable: (kind, text) or None when it
    does not touch it. `is_var(operand)` says whether a memory operand is the
    variable itself; `index` as _walk takes it."""
    addr, size, mn, ops = insns[i]
    parts = ops.split(", ") if ops else []
    hit = [k for k, o in enumerate(parts) if MEM.match(o) and is_var(o, addr + size)]
    if not hit or mn == "nop":
        return None
    text = f"0x{addr:x}: {mn} {ops}"
    k = hit[0]
    width = MEM.match(parts[k]).group(1)
    if width != "byte" or len(parts) != 2:
        return "other", text
    other = parts[1 - k]
    if k == 0:
        if mn == "mov":
            if other in ("0", "1"):
                return "store" + other, text
            return ("store_reg" if other in FAMILY else "other"), text
        if mn == "cmp" and other == "0":
            return "plain", text
        if mn == "test" and other == "1":
            return "masked", text
        return "other", text
    if mn not in ("mov", "movzx") or other not in FAMILY:
        return "other", text
    # a load: the first later use of the loaded register on each path says whether one bit
    # of it is read: whole on any path is a refusal, another use on any path a kept byte
    fam = FAMILY[other]
    masked = kept = False
    copies = []
    walk = _walk(insns, index, i, WINDOW)
    j = next(walk, None)
    while j is not None:
        a2, _s2, mn2, ops2 = insns[j]
        go = True
        if mn2 == "nop" or not any(FAMILY.get(x) == fam for x in re.findall(r"[a-z][a-z0-9]+", ops2)):
            go = mn2 not in ("call", "ret")
        else:
            p2 = ops2.split(", ") if ops2 else []
            go = False
            if len(p2) == 2 and FAMILY.get(p2[0]) == fam and p2[1] == "1" and mn2 in ("and", "xor", "test"):
                masked = True
                if mn2 == "and":    # the masked bit may be the saved copy, put back later
                    back = _put_back(insns, index, j, fam, MEM.match(parts[k]).group(2))
                    if back:
                        copies.append(back)
            elif len(p2) == 2 and FAMILY.get(p2[0]) == fam and ((mn2 == "test" and FAMILY.get(p2[1]) == fam)
                                                                 or (mn2 == "cmp" and p2[1] == "0")):
                return "plain", text + f" ; 0x{a2:x}: {mn2} {ops2}"
            else:
                kept = True
        try:
            j = walk.send(go)
        except StopIteration:
            j = None
    if masked and not kept and copies:
        return "copy", text + " ; " + copies[0]
    return ("masked" if masked and not kept else "kept"), text


def local_census(base: BaseElf, variables: dict[str, int]) -> dict[str, dict]:
    """{symbol: {kind: [text]} and "sites"} for each variable (symbol ->
    address in the base): every access the game's code makes."""
    from capstone import CS_ARCH_X86, CS_MODE_64, Cs
    md = Cs(CS_ARCH_X86, CS_MODE_64)
    text = base.text
    lo_text = text["vaddr"]
    tdata = base.data[text["offset"]:text["offset"] + text["filesz"]]
    tls = next(p for p in base.phdrs if p["type"] == PT_TLS)
    tls_lo, tls_hi = tls["vaddr"], tls["vaddr"] + tls["memsz"]
    align = tls["align"] or 1
    tls_size = (tls["memsz"] + align - 1) // align * align
    funcs = sorted((a, a + s) for a, s, _n in base.functions if a >= GAME_START)
    starts = [f[0] for f in funcs]
    out = {n: {**{k: [] for k in LOCAL_KINDS}, "sites": 0} for n in variables}
    tls_vars = {n: a for n, a in variables.items() if tls_lo <= a < tls_hi}
    plain_vars = {n: a for n, a in variables.items() if n not in tls_vars}
    if tls_vars:
        want = {a - tls_lo - tls_size: n for n, a in tls_vars.items()}     # thread-pointer offset -> symbol
        head = bytes.fromhex("64488b042500000000480305")                   # mov rax, fs:[0]; add rax, [rip+d32]
        whole: dict[int, tuple[list, dict[int, int]]] = {}                 # function -> its instructions, by address
        counted: dict[str, set[int]] = {n: set() for n in tls_vars}        # an access is counted once
        pos = tdata.find(head, GAME_START - lo_text)
        while pos >= 0:
            end = lo_text + pos + len(head) + 4
            slot = end + struct.unpack("<i", tdata[pos + len(head):pos + len(head) + 4])[0]
            i = bisect.bisect_right(starts, end) - 1
            name = None
            if i >= 0 and end < funcs[i][1] and text["vaddr"] + text["filesz"] <= slot:
                try:
                    name = want.get(struct.unpack("<q", base.read(slot, 8))[0])
                except Exception:
                    name = None
            if name:
                rec = out[name]
                rec["sites"] += 1
                lo, hi = funcs[i]
                if lo not in whole:
                    fi = list(md.disasm_lite(tdata[lo - lo_text:hi - lo_text], lo))
                    whole[lo] = (fi, {ins[0]: k for k, ins in enumerate(fi)})
                insns, index = whole[lo]
                if end in index and insns[-1][0] + insns[-1][1] == hi:
                    first = index[end]
                else:                                                       # not decoded whole: the text's order
                    insns, index, first = [], None, 0
                    for ins in md.disasm_lite(tdata[end - lo_text:hi - lo_text], end):
                        insns.append(ins)
                        if len(insns) >= 2 * WINDOW or ins[2] == "ret":
                            break
                # the address register and its 64-bit copies, along every path from the site
                todo = [(first, 0, frozenset({"rax"}))]
                seen: set[int] = set()
                while todo:
                    j, depth, track = todo.pop()
                    if j in seen or depth >= WINDOW or j >= len(insns) or not track:
                        continue
                    seen.add(j)
                    addr, size, mn, ops = insns[j]
                    parts = ops.split(", ") if ops else []

                    def is_var(o, _next, track=track):
                        return MEM.match(o).group(2) in track

                    c = _classify(insns, j, is_var, index)
                    if c is None and mn != "nop":
                        for o in parts:
                            m = MEM.match(o)
                            if m and any(FAMILY.get(x) in track for x in re.findall(r"[a-z][a-z0-9]+", m.group(2))):
                                c = ("other", f"0x{addr:x}: {mn} {ops}")
                    if c and addr not in counted[name]:
                        counted[name].add(addr)
                        rec[c[0]].append(c[1])
                    if mn == "call":
                        track = track - CALL_CLOBBERED
                    elif mn == "mov" and len(parts) == 2 and parts[0] in REG64 and parts[1] in track:
                        track = track | {parts[0]}
                    elif parts and parts[0] in FAMILY and not mn.startswith(NO_DEST):
                        track = track - {FAMILY[parts[0]]}
                    if index is None:
                        if mn != "ret":
                            todo.append((j + 1, depth + 1, track))
                    else:
                        todo.extend((n, depth + 1, track) for n in reversed(_successors(insns, index, j)))
            pos = tdata.find(head, pos + 1)
    if plain_vars:
        by_addr = {a: n for n, a in plain_vars.items()}
        for lo, hi in funcs:
            insns = list(md.disasm_lite(tdata[lo - lo_text:hi - lo_text], lo))
            index = ({ins[0]: k for k, ins in enumerate(insns)}
                     if insns and insns[-1][0] + insns[-1][1] == hi else None)
            for j, (addr, size, mn, ops) in enumerate(insns):
                m = RIP.search(ops)
                if not m:
                    continue
                target = addr + size + int(m.group(2), 16) * (1 if m.group(1) == "+" else -1)
                name = by_addr.get(target)
                if name is None:
                    continue
                out[name]["sites"] += 1

                def is_var(o, nxt, target=target):
                    r = RIP.search(o)
                    return bool(r) and nxt + int(r.group(2), 16) * (1 if r.group(1) == "+" else -1) == target

                c = _classify(insns, j, is_var, index) or ("other", f"0x{addr:x}: {mn} {ops}")
                out[name][c[0]].append(c[1])
    return out


def local_rows(ver: str) -> list[str]:
    """The symbols of config/local_data.<slug>.txt."""
    p = config_path(REPO_ROOT, ver, "local_data", "txt")
    if not p.exists():
        return []
    return [l.split()[0] for l in p.read_text().splitlines()
            if l.strip() and not l.startswith("#") and len(l.split()) == 1]


def once_rows(ver: str) -> dict[str, tuple[str, str]]:
    """The once-stored rows of config/local_data.<slug>.txt: {symbol: (the
    storing function, its unit)}. A row of another shape is a refusal."""
    p = config_path(REPO_ROOT, ver, "local_data", "txt")
    out = {}
    if not p.exists():
        return out
    for l in p.read_text().splitlines():
        s = l.split()
        if not s or l.startswith("#") or len(s) == 1:
            continue
        if len(s) != 4 or s[1] != "once":
            raise ValueError(f"{p.name}: `{l}` is neither `<symbol>` nor `<symbol> once <function> <unit>`")
        out[s[0]] = (s[2], s[3])
    return out


def local_proof(base: BaseElf, names: list[str]) -> tuple[dict[str, str], list[str]]:
    """({symbol: the proof's one line}, [refusal]) for the rows `names`."""
    variables, errors = {}, []
    for n in names:
        a = base.address_of(n) if re.fullmatch(r"D_[0-9a-f]+", n) else None
        if a is None:
            errors.append(f"local data row {n}: not a D_<hex> data label of the base")
        else:
            variables[n] = a
    proofs = {}
    for n, rec in local_census(base, variables).items():
        c = {k: len(rec[k]) for k in LOCAL_KINDS}
        line = (f"{n} sites={rec['sites']} " + " ".join(f"{k}={c[k]}" for k in LOCAL_KINDS))
        why = []
        if c["plain"]:
            why.append(f"{c['plain']} read(s) compare the whole byte, the form of a variable that kept its byte "
                       f"(first {rec['plain'][0]})")
        if c["other"]:
            why.append(f"{c['other']} access(es) are not a byte load or store (first {rec['other'][0]})")
        if not c["masked"] and not c["copy"]:
            why.append("no read takes one bit of the byte")
        if c["store_reg"] > c["kept"] + c["copy"]:
            why.append(f"{c['store_reg']} register store(s) against {c['kept']} kept load(s) and {c['copy']} masked "
                       f"cop(ies) put back: a register stored must be a copy of the variable put back "
                       f"(first {rec['store_reg'][0]})")
        if not c["store1"]:
            why.append("no store of 1: a variable never set is folded to its initial value, not shrunk")
        if why:
            errors.append(f"local data row {n} is refused, the base's code does not show a variable local to the "
                          f"optimiser: " + "; ".join(why) + f" [{line}]")
        else:
            proofs[n] = line
    return proofs, errors


ONCE_KINDS = ("null_test", "store_const", "store_other", "called", "used", "address", "other")


def _rip_target(addr: int, size: int, operand: str) -> int | None:
    r = RIP.search(operand)
    return addr + size + int(r.group(2), 16) * (1 if r.group(1) == "+" else -1) if r else None


def _once_access(insns, index, i, var: int) -> tuple[str, str] | None:
    """What instruction i does to the pointer variable at `var` (eight bytes):
    (kind of ONCE_KINDS, text), or None when no operand names those bytes.
    `index` as _walk takes it."""
    addr, size, mn, ops = insns[i]
    parts = ops.split(", ") if ops else []
    hit = [(k, _rip_target(addr, size, o)) for k, o in enumerate(parts) if RIP.search(o)]
    hit = [(k, t) for k, t in hit if t is not None and var - 7 <= t < var + 8]
    if not hit:
        return None
    k, t = hit[0]
    text = f"0x{addr:x}: {mn} {ops}"
    if mn == "lea":
        return "address", text
    m = MEM.match(parts[k])
    if t != var or not m or m.group(1) != "qword":
        return "other", text + " (another width or offset)"
    if mn == "call" and len(parts) == 1:
        return "called", text
    if len(parts) != 2:
        return "other", text
    other = parts[1 - k]
    if k == 0:
        if mn == "cmp" and other == "0":
            return "null_test", text
        if mn != "mov":
            return "other", text
        if other not in FAMILY or not other.startswith("r"):
            return "store_other", text
        for j in range(i - 1, max(-1, i - 1 - WINDOW), -1):     # the stored register's writer, in text order
            a2, s2, mn2, ops2 = insns[j]
            p2 = ops2.split(", ") if ops2 else []
            if mn2 in ("call", "ret") or mn2.startswith("j"):
                break
            if p2 and FAMILY.get(p2[0]) == FAMILY[other] and not mn2.startswith(NO_DEST):
                v = _rip_target(a2, s2, p2[1]) if mn2 == "lea" and len(p2) == 2 and p2[0] == other else None
                if v:
                    return "store_const", text + f" ; 0x{a2:x}: {mn2} {ops2} (0x{v:x})"
                break
        return "store_other", text
    if mn != "mov" or other not in REG64:
        return "other", text
    # a load: its first use on each path must be a compare with null
    uses = set()
    walk = _walk(insns, index, i, WINDOW)
    j = next(walk, None)
    while j is not None:
        _a2, _s2, mn2, ops2 = insns[j]
        go = True
        if mn2 == "nop" or not any(FAMILY.get(x) == other for x in re.findall(r"[a-z][a-z0-9]+", ops2)):
            go = mn2 not in ("call", "ret")
            if not go and mn2 == "call" and other not in CALLEE_SAVED:
                uses.add("used")        # the register is lost to the call: not seen, not accepted
        else:
            go = False
            p2 = ops2.split(", ") if ops2 else []
            if len(p2) == 2 and p2[0] == other and ((mn2 == "test" and p2[1] == other)
                                                   or (mn2 == "cmp" and p2[1] == "0")):
                uses.add("null_test")
            elif mn2 == "call" and ops2 == other:
                uses.add("called")
            else:
                uses.add("used")
        try:
            j = walk.send(go)
        except StopIteration:
            j = None
    if "called" in uses:
        return "called", text
    if uses == {"null_test"}:
        return "null_test", text
    return "used", text + (" (no use seen)" if not uses else "")


def once_census(base: BaseElf, variables: dict[str, int], refs=None) -> dict[str, dict]:
    """{symbol: {kind: [text]}, "sites", "relocations", "stores_in"} for each
    pointer variable (symbol -> address in the base): every access of its
    eight bytes the code of the whole executable makes (census's operands:
    library, game and CRT), every dynamic relocation whose addend names them,
    and the function holding each store."""
    from capstone import CS_ARCH_X86, CS_MODE_64, Cs
    md = Cs(CS_ARCH_X86, CS_MODE_64)
    if refs is None:
        refs, _facts = census(base)
    text = base.text
    lo_text = text["vaddr"]
    tdata = base.data[text["offset"]:text["offset"] + text["filesz"]]
    funcs = sorted((a, a + s, n) for a, s, n in base.functions)
    starts = [f[0] for f in funcs]
    by_byte = {a + d: n for n, a in variables.items() for d in range(8)}
    out = {n: {**{k: [] for k in ONCE_KINDS}, "sites": 0, "relocations": [], "stores_in": []} for n in variables}
    decoded: dict[int, tuple] = {}
    for site, t, _region in refs:
        names = {by_byte[b] for b in range(t, t + 8) if b in by_byte}
        for name in names:
            var = variables[name]
            rec = out[name]
            rec["sites"] += 1
            i = bisect.bisect_right(starts, site) - 1
            if i < 0 or site >= funcs[i][1]:     # CRT code: read alone
                insns = list(md.disasm_lite(tdata[site - lo_text:site - lo_text + 16], site))[:1]
                index, k, fname = None, 0, "crt"
            else:
                lo, hi, fname = funcs[i]
                if lo not in decoded:
                    fi = list(md.disasm_lite(tdata[lo - lo_text:hi - lo_text], lo))
                    decoded[lo] = (fi, {x[0]: n for n, x in enumerate(fi)})
                insns, index = decoded[lo]
                k = index.get(site)
                if not (insns and insns[-1][0] + insns[-1][1] == hi):
                    index = None
                if k is None:
                    rec["other"].append(f"0x{site:x}: not on an instruction boundary of {fname}")
                    continue
            c = _once_access(insns, index, k, var) or ("other", f"0x{site:x}: not read as an operand")
            rec[c[0]].append(c[1])
            if c[0].startswith("store"):
                rec["stores_in"].append(fname)
    for r_off, _ty, _sym, add in base._dynamic()[1]:
        if add in by_byte:
            out[by_byte[add]]["relocations"].append(f"0x{r_off:x}")
    return out


def _once_reasons(rec: dict, fn: str) -> list[str]:
    """Why the census `rec` of a variable (once_census's record) does not
    show a pointer stored once, in `fn`, with a constant and local to the
    optimiser: [] when it does."""
    c = {k: len(rec[k]) for k in ONCE_KINDS}
    stores = rec["store_const"] + rec["store_other"]
    why = []
    if len(stores) != 1:
        why.append(f"{len(stores)} stores, not one" + (f" (first {stores[0]}, second {stores[1]})"
                                                      if len(stores) > 1 else ""))
    elif not rec["store_const"]:
        why.append(f"the one store is not of a constant address ({stores[0]})")
    elif rec["stores_in"][0] != fn:
        why.append(f"the one store is in {rec['stores_in'][0]}, not the row's {fn}")
    if c["called"]:
        why.append(f"{c['called']} load(s) called through, the form of a variable not stored once with local "
                   f"linkage, whose call would be direct (first {rec['called'][0]})")
    if c["used"]:
        why.append(f"{c['used']} load(s) used otherwise than compared with null (first {rec['used'][0]})")
    if c["address"]:
        why.append(f"its address is taken (first {rec['address'][0]})")
    if c["other"]:
        why.append(f"{c['other']} access(es) are not a whole-width load or store (first {rec['other'][0]})")
    if rec["relocations"]:
        why.append(f"a relocation names it (its address in data: {', '.join(rec['relocations'][:4])})")
    if not c["null_test"] + c["called"] + c["used"]:
        why.append("no load: a variable never loaded is deleted, not rewritten")
    return why


def once_proof(base: BaseElf, rows: dict[str, tuple[str, str]], refs=None) -> tuple[dict[str, str], list[str]]:
    """({symbol: the proof's one line}, [refusal]) for the once-stored rows
    {symbol: (function, unit)} (the module docstring's conditions)."""
    variables, errors = {}, []
    tls = next(p for p in base.phdrs if p["type"] == PT_TLS)
    for n in rows:
        a = base.address_of(n) if re.fullmatch(r"D_[0-9a-f]+", n) else None
        if a is None:
            errors.append(f"local data row {n}: not a D_<hex> data label of the base")
        elif tls["vaddr"] <= a < tls["vaddr"] + tls["memsz"]:
            errors.append(f"local data row {n}: a thread-local; the once-stored proof reads ordinary variables")
        else:
            variables[n] = a
    proofs = {}
    for n, rec in once_census(base, variables, refs).items():
        fn = rows[n][0]
        c = {k: len(rec[k]) for k in ONCE_KINDS}
        stores = rec["store_const"] + rec["store_other"]
        line = (f"{n} once {fn} sites={rec['sites']} " + " ".join(f"{k}={c[k]}" for k in ONCE_KINDS)
                + f" relocations={len(rec['relocations'])}"
                + (f" store {rec['store_const'][0]}" if len(stores) == 1 and rec["store_const"] else ""))
        why = _once_reasons(rec, fn)
        if why:
            errors.append(f"local data row {n} is refused, the base's code does not show a pointer stored once and "
                          f"local to the optimiser: " + "; ".join(why) + f" [{line}]")
        else:
            proofs[n] = line
    return proofs, errors


def self_test() -> int:
    """The once-stored proof: the base's two variables accepted, a variable
    called through refused (the base's 0x57ad998), and made-up functions for
    the shapes the base may not hold: two stores, the address taken, a read
    at another width, a value stored that is not a constant, a load passed
    on. Each refusal must name its reason."""
    ver = detect_version(REPO_ROOT)
    base = BaseElf(REPO_ROOT, ver)
    refs, _facts = census(base)
    ok = True

    def expect(rows, want):
        nonlocal ok
        proofs, errors = once_proof(base, rows, refs)
        for n in rows:
            e = next((x for x in errors if x.startswith(f"local data row {n} ")), None)
            if want[n] is None and e:
                print(f"self-test: {n} wrongly refused: {e}")
                ok = False
            elif want[n] is not None and (not e or want[n] not in e):
                print(f"self-test: {n} not refused for `{want[n]}`: {e or proofs.get(n)}")
                ok = False
            else:
                print(f"self-test: {n}: " + (f"accepted: {proofs[n]}" if want[n] is None else f"refused: {e}"))

    expect({"D_5ace510": ("FUN_00b8a480", "-"), "D_593a588": ("FUN_001bd010", "-"),
            "D_57ad998": ("FUN_00eb45d0", "-")},
           {"D_5ace510": None, "D_593a588": None, "D_57ad998": "called through"})
    expect({"D_5ace510": ("FUN_00b8a440", "-")}, {"D_5ace510": "not the row's FUN_00b8a440"})

    # made-up code over a variable at 0x40000000: each function's instructions
    # as the decoder gives them, the RIP displacement written to reach it
    var = 0x40000000

    def fn(*lines):
        insns, a = [], 0x100000
        for mn, ops in lines:
            size = 7
            if "{v" in ops:
                off = int(re.search(r"\{v([+-]\d+)?\}", ops).group(1) or 0)
                d = var + off - (a + size)
                ops = re.sub(r"\{v([+-]\d+)?\}", f"rip + 0x{d:x}", ops)
            elif "{c}" in ops:
                ops = ops.replace("{c}", "rip + 0x1000")
            insns.append((a, size, mn, ops))
            a += size
        return insns

    store = [("lea", "rax, [{c}]"), ("mov", "qword ptr [{v}], rax")]
    load_test = [("mov", "rax, qword ptr [{v}]"), ("test", "rax, rax"), ("ret", "")]
    shapes = {
        "accepted": (store + [("cmp", "qword ptr [{v}], 0"), ("ret", "")], None),
        "two stores": (store + store + load_test, "2 stores, not one"),
        "address taken": (store + [("lea", "rdi, [{v}]"), ("ret", "")] + load_test, "its address is taken"),
        "another width": (store + [("mov", "eax, dword ptr [{v}]"), ("ret", "")] + load_test,
                          "not a whole-width load or store"),
        "another offset": (store + [("mov", "rax, qword ptr [{v+4}]"), ("ret", "")] + load_test,
                           "not a whole-width load or store"),
        "value stored": ([("mov", "rax, qword ptr [rdi]"), ("mov", "qword ptr [{v}], rax")] + load_test,
                         "not of a constant address"),
        "loaded and called": (store + [("mov", "rax, qword ptr [{v}]"), ("call", "rax"), ("ret", "")],
                              "called through"),
        "loaded and passed": (store + [("mov", "rdi, qword ptr [{v}]"), ("mov", "rsi, rdi"), ("ret", "")],
                              "used otherwise than compared with null"),
        "never loaded": (store + [("ret", "")], "no load"),
    }
    for what, (lines, want) in shapes.items():
        insns = fn(*lines)
        index = {x[0]: k for k, x in enumerate(insns)}
        rec = {**{k: [] for k in ONCE_KINDS}, "relocations": [], "stores_in": []}
        for k in range(len(insns)):
            c = _once_access(insns, index, k, var)
            if c:
                rec[c[0]].append(c[1])
                if c[0].startswith("store"):
                    rec["stores_in"].append("FUN_made_up")
        got = _once_reasons(rec, "FUN_made_up")
        if (want is None) != (not got) or (want is not None and not any(want in g for g in got)):
            print(f"self-test: made-up `{what}`: want {want or 'accepted'}, got {got or 'accepted'}")
            ok = False
        else:
            print(f"self-test: made-up `{what}`: " + ("accepted" if not got else f"refused: {'; '.join(got)}"))
    print("module_boundary: self-test", "OK" if ok else "FAILED")
    return 0 if ok else 1


def hx(v: int) -> str:
    return f"0x{v:x}"


def build(base: BaseElf) -> list[str]:
    refs, facts = census(base)
    plt_lo, plt_hi = facts["plt"]
    got = sorted(set(base.got_slots().values()) | set(base.relative_got_slots().values()))
    tls = next(p for p in base.phdrs if p["type"] == PT_TLS)
    tls_lo, tls_hi = tls["vaddr"], tls["vaddr"] + tls["memsz"]
    align = tls["align"] or 1
    tls_size = (tls["memsz"] + align - 1) // align * align
    # the TLS slots: unrelocated GOT slots holding a small negative value (D23)
    tls_slot_var = {}
    for site, slot, region in facts["tls_adds"]:
        if slot not in tls_slot_var:
            v = struct.unpack("<q", base.read(slot, 8))[0]
            tls_slot_var[slot] = tls_lo + tls_size + v
    got_lo = min(got + list(tls_slot_var))
    got_hi = max(got + list(tls_slot_var)) + 8
    relro = next(p for p in base.phdrs if p["type"] == PT_SCE_RELRO)
    data = next(p for p in base.phdrs if p["type"] == PT_LOAD and p["flags"] == 6)
    proc = next(p for p in base.phdrs if p["type"] == PT_SCE_PROCPARAM)
    text = base.text
    areas = [("rodata", plt_hi, text["vaddr"] + text["filesz"]),
             ("relro", relro["vaddr"], relro["vaddr"] + relro["memsz"]),
             ("data", data["vaddr"], data["vaddr"] + data["filesz"]),
             ("bss", data["vaddr"] + data["filesz"], data["vaddr"] + data["memsz"])]
    by_target: dict[int, set[str]] = {}
    first_site: dict[tuple[int, str], int] = {}
    for site, t, region in refs:
        if got_lo <= t < got_hi or tls_lo <= t < tls_hi:
            continue
        if not any(lo <= t < hi for _a, lo, hi in areas):
            continue
        by_target.setdefault(t, set()).add(region)
        first_site.setdefault((t, region), site)
    rows: list[tuple[int, int, str, str, str]] = []
    head: list[str] = []
    for area, lo, hi in areas:
        ts = sorted(t for t in by_target if lo <= t < hi)
        own = [by_target[t] for t in ts]
        game_only = sum(1 for o in own if "game" in o and "lib" not in o)
        no_game = sum(1 for o in own if "game" not in o)
        both = sum(1 for o in own if "game" in o and "lib" in o)
        head.append(f"#   {area:<6} {hx(lo)}..{hx(hi)}: {len(ts)} targets, {game_only} game-only, "
                    f"{no_game} with no game site, {both} both")
        if area == "rodata":
            runs = 1 + sum(1 for a, b in zip(own, own[1:]) if ("game" in a) != ("game" in b))
            rows.append((lo, hi, "game", area, f"interleaved ({runs} runs of game and non-game targets)"))
            continue
        # the cut: index k, below = ts[:k]; minimise wrong-side targets
        below_bad = [0]
        for o in own:
            below_bad.append(below_bad[-1] + (1 if ("game" in o and "lib" not in o) else 0))
        above_bad = [0] * (len(own) + 1)
        for i in range(len(own) - 1, -1, -1):
            above_bad[i] = above_bad[i + 1] + (1 if "game" not in own[i] else 0)
        k = min(range(len(own) + 1), key=lambda i: (below_bad[i] + above_bad[i], i))
        cut = ts[k - 1] + 1 if k > 0 else lo
        head.append(f"#          cut after {hx(ts[k - 1]) if k else 'nothing'}: {below_bad[k]} game-only "
                    f"target(s) below it stay the library's, {above_bad[k]} above it are carved out")
        segs = [(lo, cut, "lib", "")]
        pos = cut
        for i in range(k, len(ts)):
            if "game" in own[i]:
                continue
            start = ts[i - 1] + 1 if i > 0 else lo
            start = max(start, cut)
            owner = "lib" if "lib" in own[i] else "crt"
            site = first_site[(ts[i], owner)]
            nsites = sum(1 for s, t, r in refs if t == ts[i])
            if start > pos:
                segs.append((pos, start, "game", ""))
            segs.append((start, ts[i] + 1, owner,
                         f"{hx(ts[i])} referenced only by {'library' if owner == 'lib' else 'CRT'} code "
                         f"({nsites} site(s), first {hx(site)})"))
            pos = ts[i] + 1
        segs.append((pos, hi, "game", ""))
        for s_lo, s_hi, owner, note in segs:
            if s_lo < s_hi:
                rows.append((s_lo, s_hi, owner, area, note))
    # carve out the GOT, the TLS template and the PROCPARAM block
    tls_vars = sorted(set(tls_slot_var.values()))
    tls_owner = {}
    for site, slot, region in facts["tls_adds"]:
        tls_owner.setdefault(tls_slot_var[slot], set()).add(region)
    # an object the code reaches through a GOT slot (the slot's RELATIVE
    # target) is a declaration for whoever loads it, from its address to the
    # next referenced target
    rel = {r_off: add for r_off, ty, _s, add in base._dynamic()[1] if ty == 8 and got_lo <= r_off < got_hi}
    loads: dict[int, set[str]] = {}
    for site, t, region in refs:
        if t in rel:
            loads.setdefault(rel[t], set()).add(region)
    alltargets = sorted(by_target)
    got_carve = []
    for tg in sorted(loads):
        area = next((a for a, lo, hi in areas if lo <= tg < hi), None)
        if area is None:
            continue
        hi = next(hi for a, lo, hi in areas if a == area)
        j = bisect.bisect_right(alltargets, tg)
        end = min(alltargets[j], hi) if j < len(alltargets) else hi
        slots = sorted(sl for sl, t in rel.items() if t == tg)
        got_carve.append((tg, end, "lib", area, f"{hx(tg)} reached through the GOT slot "
                          f"{', '.join(hx(x) for x in slots)} by {'+'.join(sorted(loads[tg]))} code"))
    head.append(f"#   GOT    {len(rel)} slot(s) hold a RELATIVE target; {len(got_carve)} data object(s) reached through them")
    carve = got_carve + [(got_lo, got_hi, "got", "relro", "the GOT"),
             (proc["vaddr"], proc["vaddr"] + proc["memsz"], "crt", "data", "PT_SCE_PROCPARAM")]
    if tls_vars and tls_vars[0] > tls_lo:
        carve.append((tls_lo, tls_vars[0], "game", "tls", "no access"))
    for i, v in enumerate(tls_vars):
        end = tls_vars[i + 1] if i + 1 < len(tls_vars) else tls_hi
        regs = tls_owner.get(v, set())
        owner = "lib" if "lib" in regs else "game"
        carve.append((v, end, owner, "tls", f"tp {v - tls_lo - tls_size}: accessed by {'+'.join(sorted(regs))}"))
    head.append(f"#   tls    {hx(tls_lo)}..{hx(tls_hi)}: {len(tls_vars)} variables accessed, "
                f"{sum(1 for v in tls_vars if 'lib' in tls_owner.get(v, ()))} by the library")
    rows = carve_out(rows, carve)
    # merge neighbours with the same owner, area and no note
    merged: list[list] = []
    for r in rows:
        if merged and merged[-1][1] == r[0] and merged[-1][2:4] == list(r[2:4]) and not merged[-1][4] and not r[4] \
                and r[2] in ("lib", "game"):
            merged[-1][1] = r[1]
        else:
            merged.append(list(r))
    lines = [
        "# The game module's boundary: who owns each address of the executable's data, for the",
        "# stand-in definitions of tools/game_module.py (an object a game source declares and no",
        "# game file defines is defined, protected and zero-initialised, when its address is `game`;",
        "# else it stays a declaration). Written by tools/module_boundary.py from the base (its",
        "# docstring has the method: a census of every RIP-relative operand of the code by the",
        "# region of the instruction, a cut per data area, the exceptions above the cut carved out);",
        "# regenerated, never edited; `tools/module_boundary.py --check` verifies it.",
        f"# census: {len(refs)} RIP-relative operands, GOT {hx(got_lo)}..{hx(got_hi)}, PLT {hx(plt_lo)}..{hx(plt_hi)}",
    ] + head + ["# <lo> <hi> <owner> <area> [note]"]
    for lo, hi, owner, area, note in merged:
        lines.append(f"{hx(lo)} {hx(hi)} {owner} {area}" + (f" {note}" if note else ""))
    return lines


def carve_out(rows, carve):
    """rows with each carve interval replacing what it overlaps."""
    out = []
    for lo, hi, owner, area, note in rows:
        pieces = [(lo, hi)]
        for c_lo, c_hi, *_ in carve:
            nxt = []
            for p_lo, p_hi in pieces:
                if c_hi <= p_lo or c_lo >= p_hi:
                    nxt.append((p_lo, p_hi))
                    continue
                if p_lo < c_lo:
                    nxt.append((p_lo, c_lo))
                if c_hi < p_hi:
                    nxt.append((c_hi, p_hi))
            pieces = nxt
        out += [(p_lo, p_hi, owner, area, note) for p_lo, p_hi in pieces]
    out += [tuple(c) for c in carve]
    return sorted(out)


def load(ver: str) -> tuple[list[int], list[tuple[int, int, str]]]:
    """config/modules.<slug>.txt as (starts, [(lo, hi, owner)]) for owner_of."""
    rows = []
    for line in config_path(REPO_ROOT, ver, "modules", "txt").read_text().splitlines():
        s = line.split("#", 1)[0].split()
        if len(s) >= 3:
            rows.append((int(s[0], 16), int(s[1], 16), s[2]))
    rows.sort()
    return [r[0] for r in rows], rows


def owner_of(table, addr: int | None) -> str | None:
    """The owner (`game`, `lib`, `crt`, `got`) of `addr`, or None outside the table."""
    if addr is None:
        return None
    starts, rows = table
    i = bisect.bisect_right(starts, addr) - 1
    if i >= 0 and rows[i][0] <= addr < rows[i][1]:
        return rows[i][2]
    return None


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--check", action="store_true", help="exit 1 if config/modules.<slug>.txt is not what the base gives")
    ap.add_argument("--local", action="store_true", help="prove the rows of config/local_data.<slug>.txt")
    ap.add_argument("--self-test", action="store_true", help="the once-stored proof on known accepted and refused shapes")
    a = ap.parse_args(argv)
    if a.self_test:
        return self_test()
    ver = detect_version(REPO_ROOT)
    base = BaseElf(REPO_ROOT, ver)
    if a.local:
        proofs, errors = local_proof(base, local_rows(ver))
        once_p, once_e = once_proof(base, once_rows(ver)) if once_rows(ver) else ({}, [])
        proofs.update(once_p)
        errors += once_e
        for line in proofs.values():
            print(f"module_boundary: local {line}")
        for e in errors:
            print(f"module_boundary: {e}", file=sys.stderr)
        return 1 if errors else 0
    text = "\n".join(build(base)) + "\n"
    out = config_path(REPO_ROOT, ver, "modules", "txt")
    if a.check:
        if not out.exists() or out.read_text() != text:
            print(f"module_boundary: {out.relative_to(REPO_ROOT)} differs from the base's census "
                  "(run tools/module_boundary.py)", file=sys.stderr)
            return 1
        print(f"module_boundary: {out.relative_to(REPO_ROOT)} is the base's census")
        return 0
    out.write_text(text)
    print(f"module_boundary: {sum(1 for l in text.splitlines() if not l.startswith('#'))} ranges -> "
          f"{out.relative_to(REPO_ROOT)}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
