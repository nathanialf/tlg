#!/usr/bin/env bash
# build.sh: from a clean clone to the gate in one command.
#
# The target is the one tools/tlg_version.sh detects: VERSION=<slug>, or the
# first configured one (a config/sha256sums.<slug>.txt exists; base on main).
#
#   1. tools/setup.sh, when the venv or the tools under tools/ext/ are missing.
#   2. tools/extract_pkg.sh, when baserom/<slug>/eboot.elf or the recorded
#      hashes (config/sha256sums.<slug>.txt) are missing. It
#      reads the user's own package, baserom/TLG_BASE.pkg (a symlink is fine),
#      extracts it, converts the executable to a plain ELF and records (or
#      verifies) the SHA-256s.
#   3. tools/build.sh verify: the recorded SHA-256s of the base files.
#   4. tools/build.sh setup + ninja, once tools/gen_ninja.py exists (the
#      compile and match stage; not yet, during the survey stage).
#   5. tools/check_elf.py --gate, when it exists.
#
# Exits non-zero when any step fails.
set -euo pipefail

ROOT="$(cd "$(dirname "$0")" && pwd)"
cd "$ROOT"

# shellcheck source=tools/tlg_version.sh
. tools/tlg_version.sh
tlg_version_init "$ROOT"

toolchain_ok() {
    [[ -x .venv/bin/python && -x .venv/bin/ninja ]] &&
    [[ -f tools/ext/pkgtool/PkgTool.Core.dll && -x tools/ext/dotnet/dotnet ]] &&
    [[ -x tools/ext/objdiff/objdiff-cli ]]
}

if ! toolchain_ok; then
    echo "==> build.sh: toolchain incomplete, running tools/setup.sh"
    TLG_FROM_BUILD_SH=1 tools/setup.sh
    if ! toolchain_ok; then
        echo "build.sh: tools/setup.sh finished but the toolchain is still incomplete;" >&2
        echo "  see its output above (network access, host packages)." >&2
        exit 1
    fi
fi

if [[ ! -f "$TLG_BASEELF" || ! -f "$TLG_SHA256SUMS" ]]; then
    if [[ ! -e "$TLG_PKG" ]]; then
        cat >&2 <<EOM
build.sh: $TLG_BASEELF is missing and there is no package to extract it from.
  Point $TLG_PKG at your own copy of the $TLG_PKG_NAME package:
    mkdir -p baserom
    ln -s "/path/to/your/${TLG_CONTENT_ID}.pkg" $TLG_PKG
  then run ./build.sh again. Nothing under baserom/ is ever committed.
EOM
        exit 1
    fi
    echo "==> build.sh: extracting the executable from $TLG_PKG"
    tools/extract_pkg.sh
fi

tools/build.sh verify

if [[ -f tools/gen_ninja.py ]]; then
    if [[ -f build.ninja ]]; then :; else tools/build.sh setup; fi
    .venv/bin/ninja
    if [[ -f tools/check_elf.py ]]; then
        echo
        echo "==> build.sh: gate"
        VERSION="$TLG_VERSION" .venv/bin/python tools/check_elf.py --gate
    fi
else
    echo "==> build.sh: survey stage (no tools/gen_ninja.py yet); base files verified."
    echo "    Next: tools/survey_elf.sh"
fi
