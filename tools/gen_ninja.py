#!/usr/bin/env python3
"""
gen_ninja.py: write build.ninja for the current target.

One compile rule (tools/compile_cpp.sh, flags from config/flags.<slug>.txt)
per source under src/ (*.cpp, *.cc, *.c), each to build/<slug>/obj/<path>.o,
and the `gate` target, tools/check_elf.py --gate over every object: each
function config/matched.<slug>.txt claims must compare equal to the base.
`gate` is the default target. There is no link step: the original was linked
by Sony's linker against its SDK, and the match is per function.

build.ninja's first line names the slug it was written for; it rewrites
itself when this script, the flags or the sources list change.
"""
from __future__ import annotations

import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(Path(__file__).resolve().parent))
from tlg_version import build_dir, config_path, detect_version  # noqa: E402

SRC_EXTS = (".cpp", ".cc", ".c")


def sources() -> list[str]:
    src = REPO_ROOT / "src"
    if not src.is_dir():
        return []
    return sorted(str(p.relative_to(REPO_ROOT)) for p in src.rglob("*")
                  if p.is_file() and p.suffix in SRC_EXTS)


def esc(s: str) -> str:
    return s.replace("$", "$$").replace(" ", "$ ").replace(":", "$:")


def main() -> int:
    ver = detect_version(REPO_ROOT)
    bd = build_dir(REPO_ROOT, ver).relative_to(REPO_ROOT)
    flags = config_path(REPO_ROOT, ver, "flags", "txt").relative_to(REPO_ROOT)
    matched = config_path(REPO_ROOT, ver, "matched", "txt").relative_to(REPO_ROOT)
    funcs = config_path(REPO_ROOT, ver, "functions", "txt").relative_to(REPO_ROOT)
    srcs = sources()
    lines = [f"# tlg build.ninja for VERSION={ver}: written by tools/gen_ninja.py; do not edit.",
             "ninja_required_version = 1.5",
             f"builddir = {bd}",
             "",
             "rule cxx",
             f"  command = VERSION={ver} tools/compile_cpp.sh $in $out",
             "  description = CXX $in",
             "  depfile = $out.d",
             "  deps = gcc",
             "",
             "rule gate",
             f"  command = VERSION={ver} .venv/bin/python -I tools/check_elf.py --gate",
             "  description = GATE (tools/check_elf.py --gate)",
             "  pool = console",
             "",
             "rule regen",
             f"  command = VERSION={ver} .venv/bin/python -I tools/gen_ninja.py",
             "  description = REGEN build.ninja",
             "  generator = 1",
             ""]
    objs = []
    for s in srcs:
        o = f"{bd}/obj/{s}.o"
        objs.append(o)
        lines.append(f"build {esc(o)}: cxx {esc(s)} | tools/compile_cpp.sh {esc(str(flags))}")
    lines.append("")
    deps = " ".join(esc(o) for o in objs)
    lines.append(f"build gate: gate | {deps} tools/check_elf.py tools/match_check.py "
                 f"{esc(str(matched))} {esc(str(funcs))}".rstrip())
    lines.append("build build.ninja: regen | tools/gen_ninja.py tools/tlg_version.py")
    lines.append("default gate")
    (REPO_ROOT / "build.ninja").write_text("\n".join(lines) + "\n")
    print(f"gen_ninja: {len(srcs)} source(s), VERSION={ver}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
