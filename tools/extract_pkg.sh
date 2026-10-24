#!/usr/bin/env bash
# =============================================================================
# tools/extract_pkg.sh
#
# Extracts the target's executable, modules and param.sfo from the user's own
# PKG (baserom/TLG_BASE.pkg, a file or a symlink to the user's copy) into
# baserom/<slug>/, converts the fake-signed SELFs to plain ELFs
# (tools/unfself.py) and records the SHA-256s to config/sha256sums.<slug>.txt
# (creating the entries on first run, verifying against them after). The
# target is VERSION, or the first configured one (tools/tlg_version.py).
#
# Wrapper that delegates to tools/extract_pkg.py.
#
# Reads no copyrighted material into the repository: everything but the
# hashes lands under baserom/, which is gitignored.
# =============================================================================
set -euo pipefail

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
cd "$ROOT"

VENV_PY="$ROOT/.venv/bin/python"
if [[ ! -x "$VENV_PY" ]]; then
    echo "extract_pkg: $VENV_PY not found: run tools/setup.sh first" >&2
    exit 1
fi

exec "$VENV_PY" -I "$ROOT/tools/extract_pkg.py" "$@"
