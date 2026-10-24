#!/usr/bin/env bash
# tools/quick_diff.sh <TU> <func> [<symbol>]: compile the TU and show how far
# <func> (a row of config/functions.<slug>.txt) is from the base, with the
# first difference in context. The inner loop of matching a function.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
cd "$ROOT"
[[ $# -ge 2 ]] || { echo "usage: $0 <TU> <func> [<symbol>]" >&2; exit 2; }
args=(--tu "$1" --func "$2" --diff)
[[ $# -ge 3 ]] && args+=(--symbol "$3")
exec .venv/bin/python -I tools/match_check.py "${args[@]}"
