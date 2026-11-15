#!/usr/bin/env bash
# tools/compile_cpp.sh <source> <object>: compile one C/C++ source with the
# flags config/flags.<slug>.txt gives its prefix (longest match wins), into
# <object>. The compiler is the prefix line's cxx=<version> (every line of
# config/flags.base.txt names one), else $TLG_CXX, else the host's clang-19.
# Run from the repo root (gen_ninja.py's commands are); paths are
# repo-relative.
#
# The game region is built as one module in two stages (tools/game_module.py),
# in steps that use the same flags line:
#   compile_cpp.sh --ir <source> <out.bc>   the unit's unoptimised bitcode:
#       the front end at the line's -O2 with the pipeline off
#       (`-Xclang -disable-llvm-optzns`; bitcode keeps the in-memory use-list
#       order), and beside it <out>.ll, the same module as text
#       (llvm-link -S), which tools/game_module.py reads for what the unit
#       defines and declares. Text is not linked: its use-list directives on
#       a constant count the constant's uses in every module of the context,
#       so the second file that orders `i32 1` fails to parse. Then stage 1:
#       the line's -O2 pipeline over that bitcode, to the same path with
#       /game/unit/ for /game/ir/ (the unit as its own compile optimises
#       it, before code generation)
#   compile_cpp.sh --codegen <prefix> <module.bc> <object>   code generation
#       alone over the linked module the link stage optimised (the IR
#       pipeline off); the driver's front-end flags (-I, -std) have nothing
#       to act on in an IR input and -Qunused-arguments keeps it from saying
#       so
set -euo pipefail
mode=obj
case "${1:-}" in
    --ir) mode=ir; shift ;;
    --codegen) mode=codegen; shift; prefix_of="$1"; shift ;;
esac
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
cd "$ROOT"
# shellcheck source=tools/tlg_version.sh
. tools/tlg_version.sh
tlg_version_init "$ROOT"
src="$1"; obj="$2"
match="${prefix_of:-$src}"
# A prefix's cxx=<version> names its compiler (tools/setup.sh,
# docs/TARGETS.md); a line without one compiles with TLG_CXX, else with the
# host's clang-19.
# llvm-link of the compiler's own release (bitcode is read only by its own
# release's tools): tools/cc/llvm-<version>-src-tools/bin, beside the
# compiler the line names
LLVM_LINK=""
CXX="${TLG_CXX:-clang-19}"
# A prebuilt LLVM release under tools/cc/ links against libtinfo.so.5, which
# tools/cc/shim/ provides (tools/setup.sh); put it on the library path.
case "$CXX" in */tools/cc/*|tools/cc/*) export LD_LIBRARY_PATH="$ROOT/tools/cc/shim${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}" ;; esac
flags_file="config/flags.${TLG_VERSION}.txt"
best=""; bestlen=-1
while IFS= read -r line; do
    [[ -z "$line" || "$line" == \#* ]] && continue
    prefix="${line%% *}"; rest="${line#* }"
    if [[ "$match" == "$prefix"* && ${#prefix} -gt $bestlen ]]; then best="$rest"; bestlen=${#prefix}; fi
done < "$flags_file"
if [[ $bestlen -lt 0 ]]; then
    echo "compile_cpp: no flags prefix in $flags_file matches $src" >&2; exit 1
fi
# `cxx=<path>` or `cxx=<version>` as the first flag selects another compiler for
# this prefix (a tools/cc/llvm-<version>/bin/clang, or any path).
if [[ "$best" == cxx=* ]]; then
    sel="${best%% *}"; sel="${sel#cxx=}"; best="${best#* }"
    if [[ -x "$ROOT/tools/cc/llvm-$sel/bin/clang" ]]; then
        CXX="$ROOT/tools/cc/llvm-$sel/bin/clang"
        [[ -x "$ROOT/tools/cc/llvm-$sel-tools/bin/llvm-link" ]] && LLVM_LINK="$ROOT/tools/cc/llvm-$sel-tools/bin/llvm-link"
    else CXX="$sel"; fi
    case "$CXX" in */tools/cc/*|tools/cc/*) export LD_LIBRARY_PATH="$ROOT/tools/cc/shim${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}" ;; esac
fi
mkdir -p "$(dirname "$obj")"
# -MD -MF: the headers the TU includes, for ninja's depfile, so an edited
# header rebuilds every object that includes it (a stale object once passed
# the gate on a header change that had broken four rows).
# -I build/<slug>: a table's rows generated from the user's executable
# (tools/gen_data_inc.py, docs/DECISIONS.md D18), included by the TU that
# defines the table as "gen/D_<hex>.inc". It emits nothing of its own.
# shellcheck disable=SC2086
case "$mode" in
    ir) [[ -n "$LLVM_LINK" ]] || { echo "compile_cpp: no llvm-link beside the compiler of $match's line (tools/build_llvm.sh <version>)" >&2; exit 1; }
        "$CXX" $best -I"$TLG_BUILD_DIR" -MD -MF "$obj.d" -emit-llvm -Xclang -disable-llvm-optzns \
            -c "$src" -o "$obj"
        "$LLVM_LINK" -S -o "${obj%.bc}.ll" "$obj"
        unit="${obj/\/game\/ir\///game/unit/}"
        [[ "$unit" != "$obj" ]] || { echo "compile_cpp: --ir output $obj is not under game/ir/" >&2; exit 1; }
        mkdir -p "$(dirname "$unit")"
        exec "$CXX" $best -Qunused-arguments -emit-llvm -c "$obj" -o "$unit" ;;
    codegen) exec "$CXX" $best -Qunused-arguments -Xclang -disable-llvm-optzns -c "$src" -o "$obj" ;;
    *) exec "$CXX" $best -I"$TLG_BUILD_DIR" -MD -MF "$obj.d" -c "$src" -o "$obj" ;;
esac
