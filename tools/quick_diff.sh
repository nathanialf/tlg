#!/usr/bin/env bash
# tools/quick_diff.sh <TU> <func> [<symbol>] [--module | --both]: compile the TU
# and show how far <func> (a row of config/functions.<slug>.txt) is from the
# base, with the first difference in context. The inner loop of matching a
# function.
#
# A game unit (src/game/) is built as the gate builds the game, as a module
# in two stages (tools/game_module.py): by default a module of that one file
# and its stand-ins, the same flags, the unit's -O2, the link stage and code
# generation (about a second): a pre-screen, since the link stage sees
# nothing another file defines; --module compiles it in the whole game
# module, the gate's object (ninja rebuilds what changed), where a row is
# claimed; --both shows each and says whether the
# function differs between them, which is a cross-file effect (another file's
# definition inlined or propagated) and real information. A function whose
# name the compiler gave (`__cxx_global_array_dtor.2`) is named as the unit
# names it, in both builds (match_check.py compiler_local_aliases).
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
cd "$ROOT"
pos=(); extra=()
for a in "$@"; do
    case "$a" in
        --module|--both) extra+=("$a") ;;
        *) pos+=("$a") ;;
    esac
done
[[ ${#pos[@]} -ge 2 ]] || { echo "usage: $0 <TU> <func> [<symbol>] [--module | --both]" >&2; exit 2; }
args=(--tu "${pos[0]}" --func "${pos[1]}" --diff)
[[ ${#pos[@]} -ge 3 ]] && args+=(--symbol "${pos[2]}")
exec .venv/bin/python -I tools/match_check.py "${args[@]}" "${extra[@]}"
