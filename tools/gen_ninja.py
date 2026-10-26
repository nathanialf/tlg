#!/usr/bin/env python3
"""
gen_ninja.py: write build.ninja for the current target.

One compile rule (tools/compile_cpp.sh, flags from config/flags.<slug>.txt)
per source under src/ (*.cpp, *.cc, *.c), each to build/<slug>/obj/<path>.o,
and the `gate` target, tools/check_elf.py --gate over every object: each
function config/matched.<slug>.txt claims must compare equal to the base.
Every row of config/data_schema.<slug>.txt gets a `gen_data` edge
(tools/gen_data_inc.py) writing build/<slug>/gen/D_<hex>.inc from the user's
executable, an implicit input of the compile of the TU config/data.<slug>.txt
names for it (docs/DECISIONS.md D18).
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
from tlg_version import baseelf_path, build_dir, config_path, detect_version  # noqa: E402
from gen_data_inc import schema_rows  # noqa: E402

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
    schema = schema_rows(ver)
    gen_of: dict[str, list[str]] = {}
    for ident, row in sorted(schema.items()):
        gen_of.setdefault(row["tu"], []).append(f"{bd}/gen/{ident}.inc")
    elf = baseelf_path(REPO_ROOT, ver).relative_to(REPO_ROOT)
    schema_cfg = config_path(REPO_ROOT, ver, "data_schema", "txt").relative_to(REPO_ROOT)
    data_cfg = config_path(REPO_ROOT, ver, "data", "txt").relative_to(REPO_ROOT)
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
             "rule gen_data",
             f"  command = VERSION={ver} .venv/bin/python -I tools/gen_data_inc.py $ident --out $out --depfile $out.d",
             "  description = GEN $out",
             "  depfile = $out.d",
             "  deps = gcc",
             "  restat = 1",
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
    for ident, row in sorted(schema.items()):
        lines.append(f"build {esc(f'{bd}/gen/{ident}.inc')}: gen_data | tools/gen_data_inc.py tools/base_elf.py "
                     f"tools/layout_link.py {esc(str(schema_cfg))} {esc(str(data_cfg))} {esc(row['header'])} "
                     f"{esc(str(elf))}")
        lines.append(f"  ident = {ident}")
    objs = []
    for s in srcs:
        o = f"{bd}/obj/{s}.o"
        objs.append(o)
        gen = "".join(f" {esc(g)}" for g in gen_of.pop(s, []))
        lines.append(f"build {esc(o)}: cxx {esc(s)} | tools/compile_cpp.sh {esc(str(flags))}{gen}")
    for tu in gen_of:
        print(f"gen_ninja: {tu} (config/data.{ver}.txt) is not a source under src/", file=sys.stderr)
        return 1
    lines.append("")
    deps = " ".join(esc(o) for o in objs)
    lines.append(f"build gate: gate | {deps} tools/check_elf.py tools/match_check.py "
                 f"{esc(str(matched))} {esc(str(funcs))}".rstrip())
    lines.append(f"build build.ninja: regen | tools/gen_ninja.py tools/tlg_version.py tools/gen_data_inc.py "
                 f"{esc(str(schema_cfg))} {esc(str(data_cfg))}")
    lines.append("default gate")
    (REPO_ROOT / "build.ninja").write_text("\n".join(lines) + "\n")
    print(f"gen_ninja: {len(srcs)} source(s), VERSION={ver}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
