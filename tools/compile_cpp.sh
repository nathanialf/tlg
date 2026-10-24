#!/usr/bin/env bash
# tools/compile_cpp.sh <source> <object>: compile one C/C++ source with the
# flags config/flags.<slug>.txt gives its prefix (longest match wins), into
# <object>. The compiler is $TLG_CXX, default clang-19. Run from the repo root
# (gen_ninja.py's commands are); paths are repo-relative.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
cd "$ROOT"
# shellcheck source=tools/tlg_version.sh
. tools/tlg_version.sh
tlg_version_init "$ROOT"
src="$1"; obj="$2"
CXX="${TLG_CXX:-clang-19}"
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
mkdir -p "$(dirname "$obj")"
# shellcheck disable=SC2086
exec "$CXX" $best -c "$src" -o "$obj"
