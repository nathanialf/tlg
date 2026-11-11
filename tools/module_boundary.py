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
    a = ap.parse_args(argv)
    ver = detect_version(REPO_ROOT)
    base = BaseElf(REPO_ROOT, ver)
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
