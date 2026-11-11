#!/usr/bin/env bash
# tools/compile_cpp.sh <source> <object>: compile one C/C++ source with the
# flags config/flags.<slug>.txt gives its prefix (longest match wins), into
# <object>. The compiler is the prefix line's cxx=<version>, else $TLG_CXX, else
# tools/cc/llvm-4.0.0/bin/clang. Run from the repo root
# (gen_ninja.py's commands are); paths are repo-relative.
#
# The game region is built as one module (tools/game_module.py, D50), in two
# steps that use the same flags line:
#   compile_cpp.sh --ir <source> <out.bc>   the unit's unoptimised bitcode:
#       the front end at the line's -O2 with the pipeline off
#       (`-Xclang -disable-llvm-optzns`; bitcode keeps the in-memory use-list
#       order), and beside it <out>.ll, the same module as text
#       (llvm-link -S), which tools/game_module.py reads for what the unit
#       defines and declares. Text is not linked: its use-list directives on
#       a constant count the constant's uses in every module of the context,
#       so the second file that orders `i32 1` fails to parse
#   compile_cpp.sh --codegen <prefix> <module.bc> <object>   the line's -O2
#       pipeline and code generation over a linked module; the driver's
#       front-end flags (-I, -std) have nothing to act on in an IR input and
#       -Qunused-arguments keeps it from saying so
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
# The project default is the prebuilt LLVM 4.0.0 under tools/cc/ (tools/setup.sh,
# docs/TARGETS.md); a prefix's cxx=<version> or TLG_CXX overrides it.
DEFAULT_CXX="$ROOT/tools/cc/llvm-4.0.0/bin/clang"
[[ -x "$DEFAULT_CXX" ]] || DEFAULT_CXX=clang-19
CXX="${TLG_CXX:-$DEFAULT_CXX}"
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
    if [[ -x "$ROOT/tools/cc/llvm-$sel/bin/clang" ]]; then CXX="$ROOT/tools/cc/llvm-$sel/bin/clang"
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
    ir) "$CXX" $best -I"$TLG_BUILD_DIR" -MD -MF "$obj.d" -emit-llvm -Xclang -disable-llvm-optzns \
            -c "$src" -o "$obj"
        exec "$ROOT/tools/cc/llvm-4.0.0-src-tools/bin/llvm-link" -S -o "${obj%.bc}.ll" "$obj" ;;
    codegen) exec "$CXX" $best -Qunused-arguments -c "$src" -o "$obj" ;;
    *) exec "$CXX" $best -I"$TLG_BUILD_DIR" -MD -MF "$obj.d" -c "$src" -o "$obj" ;;
esac
