#!/usr/bin/env bash
# tools/compile_cpp.sh <source> <object>: compile one C/C++ source with the
# flags config/flags.<slug>.txt gives its prefix (longest match wins), into
# <object>. The compiler is the prefix line's cxx=<version>, else $TLG_CXX, else
# tools/cc/llvm-4.0.0/bin/clang. Run from the repo root
# (gen_ninja.py's commands are); paths are repo-relative.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
cd "$ROOT"
# shellcheck source=tools/tlg_version.sh
. tools/tlg_version.sh
tlg_version_init "$ROOT"
src="$1"; obj="$2"
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
    if [[ "$src" == "$prefix"* && ${#prefix} -gt $bestlen ]]; then best="$rest"; bestlen=${#prefix}; fi
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
# shellcheck disable=SC2086
exec "$CXX" $best -c "$src" -o "$obj"
