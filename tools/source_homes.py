#!/usr/bin/env python3
"""tools/source_homes.py [--md] [--no-write]: which source file each function
came from, where the executable says so.

The compiler baked the developers' own source paths into the executable as
assert and log strings (`__FILE__`; docs/SURVEY.md "Source files"). A function
that loads such a string (a RIP-relative `lea` into it) contains code from that
file. When every source path a function loads is the same `.cpp`/`.c`, that
file is the function's home translation unit and the row goes to
config/homes.<slug>.txt as

    <function> <path under src/> <original path>

with the original root mapped to a directory of ours (ROOTS below) under the
region prefix the address selects (docs/TARGETS.md "Two compiler
generations"). A function whose strings name several source files (a unity
build, or an inlined function of another file's) or only headers is listed in
the comment block at the top, not assigned: it has evidence, not a home.
Sony's SDK headers (`C:/Program Files (x86)/SCE/...`) are not homes of ours.

The rows are facts about the base and are regenerated, never edited;
tools/check_elf.py does not read them. A matching worker reads the row before
choosing a directory (docs/MATCH.md "Where a function lives").
"""
from __future__ import annotations

import argparse
import bisect
import posixpath
import re
import struct
import sys
from collections import defaultdict
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO_ROOT / "tools"))
from base_elf import BaseElf  # noqa: E402
from tlg_version import config_path  # noqa: E402

# The compiler split (docs/DECISIONS.md D6).
GAME_START = 0x1A3E00

# Original root -> our directory. Order matters: the first match wins.
ROOTS = [
    ("D:/trico/engine/anzu/", "anzu/"),
    ("Y:/NightlyJobs/20141121-01/Source/", "havok/"),
    ("C:/Work/P4/depot/Release/2014_2/2014_2_0_Release/Source/", "havok/"),
    ("C:/sound/sndx/trico/", "sndx/"),
]
SOURCE_EXTS = (".cpp", ".cc", ".cxx", ".c")
SRC_RE = re.compile(rb"[A-Za-z]:[\\/][\x20-\x7e]{3,200}?\.(?:cpp|cc|cxx|c|h|hpp|inl)(?=\x00)")
# lea r64, [rip+disp32]: REX.W(/R) 8D, modrm mod=00 rm=101
LEA_RIP_RE = re.compile(rb"[\x48\x4c]\x8d[\x05\x0d\x15\x1d\x25\x2d\x35\x3d]")


def our_path(orig: str) -> str | None:
    for root, ours in ROOTS:
        if orig.startswith(root):
            return ours + posixpath.normpath(orig[len(root):])
    return None


def collect(elf: BaseElf):
    """-> {function name: {original path}} for every function that loads a
    source-path string, and the sorted path strings by address."""
    strings: dict[int, str] = {}
    for m in SRC_RE.finditer(elf.data):
        seg = next((p for p in elf.loaded_segments()
                    if p["offset"] <= m.start() < p["offset"] + p["filesz"]), None)
        if seg is not None:
            strings[seg["vaddr"] + (m.start() - seg["offset"])] = m.group(0).decode().replace("\\", "/")
    funcs = sorted(elf.functions)
    starts = [f[0] for f in funcs]
    text = elf.text_bytes()
    text_va = elf.text["vaddr"]
    refs: dict[str, set[str]] = defaultdict(set)
    for m in LEA_RIP_RE.finditer(text):
        p = m.end()
        disp, = struct.unpack_from("<i", text, p)
        target = text_va + p + 4 + disp
        s = strings.get(target)
        if s is None:
            continue
        i = bisect.bisect_right(starts, text_va + m.start()) - 1
        if i >= 0 and funcs[i][0] <= text_va + m.start() < funcs[i][0] + funcs[i][1]:
            refs[funcs[i][2]].add(s)
    return refs, strings


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--md", action="store_true", help="print a Markdown summary")
    ap.add_argument("--no-write", action="store_true", help="do not write config/homes.<slug>.txt")
    a = ap.parse_args(argv)
    elf = BaseElf(REPO_ROOT)
    refs, strings = collect(elf)
    addr = {n: ad for ad, _, n in elf.functions}

    homes: list[tuple[str, str, str]] = []
    several: list[tuple[str, list[str]]] = []
    headers_only: list[tuple[str, list[str]]] = []
    sdk_only = 0
    for fn, paths in sorted(refs.items(), key=lambda kv: addr[kv[0]]):
        ours = {p: our_path(p) for p in paths}
        if all(v is None for v in ours.values()):
            sdk_only += 1
            continue
        sources = sorted({v for p, v in ours.items() if v and v.lower().endswith(SOURCE_EXTS)})
        if len(sources) == 1:
            orig = next(p for p, v in ours.items() if v == sources[0])
            region = "game/" if addr[fn] >= GAME_START else "libs/"
            homes.append((fn, region + sources[0], orig))
        elif len(sources) > 1:
            several.append((fn, sources))
        else:
            headers_only.append((fn, sorted(v for v in ours.values() if v)))

    out = config_path(REPO_ROOT, elf.version, "homes", "txt")
    lines = [
        "# Functions whose home source file the executable names: `<function> <path under src/>",
        "# <original path>`. Written by tools/source_homes.py from the source-path strings",
        "# each function loads (its docstring has the rule); regenerate, never edit.",
        f"# {len(homes)} functions with one source file; {len(several)} load several source files",
        f"# (not assigned, listed below); {len(headers_only)} load only headers; {sdk_only} load",
        "# only Sony SDK headers.",
        "#",
        "# Several source files (a unity build or an inlined function of another file):",
    ]
    lines += [f"#   {fn} {' '.join(s)}" for fn, s in several]
    lines += ["#", "# Headers only (the function has inline code from the header, home unknown):"]
    lines += [f"#   {fn} {' '.join(h)}" for fn, h in headers_only]
    lines += [f"{fn} {ours} {orig}" for fn, ours, orig in homes]
    if not a.no_write:
        out.write_text("\n".join(lines) + "\n")
    if a.md:
        by_dir = defaultdict(int)
        for _, ours, _ in homes:
            by_dir["/".join(ours.split("/")[:2])] += 1
        print(f"| functions naming a source path | {len(refs)} |")
        print(f"| with one home source file | {len(homes)} |")
        print(f"| several source files (unity or inlined) | {len(several)} |")
        print(f"| headers only | {len(headers_only)} |")
        print("\n| directory | functions |\n|---|---|")
        for d, n in sorted(by_dir.items(), key=lambda kv: -kv[1]):
            print(f"| `src/{d}/` | {n} |")
        print(f"\n{len(strings)} source-path strings in the executable.")
    else:
        print(f"source_homes: {len(homes)} homes, {len(several)} several, "
              f"{len(headers_only)} headers only -> {out.relative_to(REPO_ROOT)}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
