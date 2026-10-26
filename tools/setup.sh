#!/usr/bin/env bash
# =============================================================================
# tools/setup.sh
#
# One-shot host setup. Idempotent: running it twice is fine.
#
#   1. Create a Python venv at .venv and install tools/requirements.txt.
#   2. Fetch the pinned external tools into tools/ext/ and tools/ghidra/:
#        LLVM 3.3, 4.0.0 the compilers (tools/fetch_llvm.sh; docs/TARGETS.md),
#                       and LLVM 3.3 built from source for the library
#                       prefix (tools/build_llvm.sh 3.3; docs/DECISIONS.md D20)
#        .NET 8         runtime, user-local via dotnet-install.sh, to run:
#        PkgTool.Core   LibOrbisPkg 0.2.231 (MIT): extracts the user's own
#                       PKG (tools/extract_pkg.py)
#        objdiff-cli    objdiff 3.8.3 (MIT/Apache-2.0): per-function match
#                       scoring (tools/match_check.py)
#        Ghidra         12.2 (Apache-2.0): function boundaries and the survey
#                       (tools/survey_elf.py); needs a JDK 25 on the host
#      and check for the host packages the tools need (LLVM 19, JDK 25),
#      printing the apt command when one is missing.
#   3. Install the git hooks (tools/install_hooks.sh).
#
# This script downloads no game data and no Sony files. Everything pulled is
# open source and pinned by SHA-256.
#
# Skip flags:
#   SKIP_TOOLCHAIN=1   skip step 2
#   SKIP_GHIDRA=1      skip only the 570 MB Ghidra download
# =============================================================================
set -euo pipefail

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
cd "$ROOT"

PYTHON="${PYTHON:-python3}"
VENV="${VENV:-.venv}"

echo "==> tlg setup at $ROOT"

# --- 1. Python venv ----------------------------------------------------------

if [[ ! -d "$VENV" ]]; then
    echo "==> creating venv at $VENV"
    "$PYTHON" -m venv "$VENV"
fi
# shellcheck disable=SC1091
source "$VENV/bin/activate"
python -m pip install --upgrade pip >/dev/null
python -m pip install -q -r tools/requirements.txt

# --- 2. Pinned external tools --------------------------------------------------

# The framework-dependent build (the self-contained linux-x64 one bundles a
# 2020 .NET Core 3 runtime that needs libssl 1.x and ICU, neither on a current
# host). It runs on the .NET 8 runtime installed below, rolled forward.
PKGTOOL_URL="https://github.com/maxton/LibOrbisPkg/releases/download/v0.2/PkgTool.Core-0.2.231.zip"
PKGTOOL_SHA256="4bdb25a32be28f84ac2aa177fe1ae4285669419d5e15c05968b4d8cf43e872b3"
PKGTOOL_DIR="$ROOT/tools/ext/pkgtool"

DOTNET_INSTALL_URL="https://dot.net/v1/dotnet-install.sh"
DOTNET_INSTALL_SHA256="082f7685e156738a1b2e2ed8381a621870d4ce8e8c59278034556f05c186eb2e"
DOTNET_DIR="$ROOT/tools/ext/dotnet"
DOTNET_CHANNEL="8.0"

OBJDIFF_URL="https://github.com/encounter/objdiff/releases/download/v3.8.3/objdiff-cli-linux-x86_64"
OBJDIFF_SHA256="e823ae932a56c68dcd86b68d12f2268c953e0c027402162c8a6dfa6a00d65008"
OBJDIFF_BIN="$ROOT/tools/ext/objdiff/objdiff-cli"

GHIDRA_URL="https://github.com/NationalSecurityAgency/ghidra/releases/download/Ghidra_12.2_build/ghidra_12.2_PUBLIC_20261016.zip"
GHIDRA_SHA256="2c2cd776db3c1f6a097ba418922378ac3649cadd5e844a6f5f088ae628a7be67"
GHIDRA_DIR="$ROOT/tools/ghidra"
GHIDRA_HOME="$GHIDRA_DIR/ghidra_12.2_PUBLIC"

# fetch_pinned <label> <url> <sha256> <dest file>
fetch_pinned() {
    local label="$1" url="$2" sha="$3" dest="$4"
    if [[ -f "$dest" ]] && echo "$sha  $dest" | sha256sum -c --status; then
        echo "==> $label already at $dest"
        return 0
    fi
    echo "==> fetching $label"
    mkdir -p "$(dirname "$dest")"
    curl -fsSL -o "$dest.part" "$url"
    if ! echo "$sha  $dest.part" | sha256sum -c --status; then
        echo "==> $label: SHA-256 mismatch; refusing to install" >&2
        rm -f "$dest.part"
        return 1
    fi
    mv "$dest.part" "$dest"
}

if [[ "${SKIP_TOOLCHAIN:-0}" == "1" ]]; then
    echo "==> SKIP_TOOLCHAIN=1; not fetching tools"
else
    if [[ -x "$DOTNET_DIR/dotnet" ]] && "$DOTNET_DIR/dotnet" --list-runtimes 2>/dev/null | grep -q "Microsoft.NETCore.App $DOTNET_CHANNEL"; then
        echo "==> .NET $DOTNET_CHANNEL runtime already at $DOTNET_DIR"
    elif fetch_pinned "dotnet-install.sh" "$DOTNET_INSTALL_URL" "$DOTNET_INSTALL_SHA256" "$ROOT/tools/ext/dotnet-install.sh"; then
        echo "==> installing the .NET $DOTNET_CHANNEL runtime (user-local, for PkgTool.Core)"
        bash "$ROOT/tools/ext/dotnet-install.sh" --runtime dotnet --channel "$DOTNET_CHANNEL" \
            --install-dir "$DOTNET_DIR" --no-path >/dev/null
    fi
    if fetch_pinned "PkgTool.Core 0.2.231" "$PKGTOOL_URL" "$PKGTOOL_SHA256" "$ROOT/tools/ext/pkgtool.zip"; then
        if [[ ! -f "$PKGTOOL_DIR/PkgTool.Core.dll" ]]; then
            mkdir -p "$PKGTOOL_DIR"
            unzip -q -o "$ROOT/tools/ext/pkgtool.zip" -d "$PKGTOOL_DIR"
        fi
        echo "==> PkgTool.Core at $PKGTOOL_DIR/PkgTool.Core.dll"
    fi
    if fetch_pinned "objdiff-cli 3.8.3" "$OBJDIFF_URL" "$OBJDIFF_SHA256" "$OBJDIFF_BIN"; then
        chmod +x "$OBJDIFF_BIN"
    fi
    if [[ "${SKIP_GHIDRA:-0}" == "1" ]]; then
        echo "==> SKIP_GHIDRA=1; not fetching Ghidra"
    elif [[ -x "$GHIDRA_HOME/support/analyzeHeadless" ]]; then
        echo "==> Ghidra already at $GHIDRA_HOME"
    elif fetch_pinned "Ghidra 12.2" "$GHIDRA_URL" "$GHIDRA_SHA256" "$GHIDRA_DIR/ghidra_12.2_PUBLIC_20261016.zip"; then
        unzip -q -o "$GHIDRA_DIR/ghidra_12.2_PUBLIC_20261016.zip" -d "$GHIDRA_DIR"
        echo "==> Ghidra at $GHIDRA_HOME"
    fi
fi

# --- 2a. The compilers: upstream LLVM 3.3 (library region) and 4.0.0 (game) ---
# The compiler that reproduces the most of the executable's functions in the
# probe (tools/compiler_probe.sh; docs/TARGETS.md). tools/fetch_llvm.sh pins
# the tarball and the libtinfo.so.5 it links against.
if [[ "${SKIP_TOOLCHAIN:-0}" == "1" ]]; then
    echo "==> SKIP_TOOLCHAIN=1; not fetching the project compiler"
else
    bash tools/fetch_llvm.sh 3.3 4.0.0
    # The library prefix compiles with LLVM 3.3 built from source (cxx=3.3-src,
    # docs/DECISIONS.md D20): the release plus the one backport the prefix's
    # flags need, verified against the prebuilt it was just fetched next to.
    # About 15 minutes on 3 cores; skipped when the install is current.
    bash tools/build_llvm.sh 3.3
fi

# --- 2b. Host packages: LLVM 19 (disassembly, the tooling clang) and JDK 25 ---

missing=()
for t in clang-19 llvm-objdump-19 llvm-readelf-19 llvm-nm-19 ld.lld-19; do
    command -v "$t" >/dev/null 2>&1 || missing+=("$t")
done
if (( ${#missing[@]} )); then
    cat >&2 <<EOM

==> LLVM 19 tools missing on PATH: ${missing[*]}
    Debian/Ubuntu:
      sudo apt-get install -y clang-19 lld-19 llvm-19
EOM
else
    echo "==> LLVM 19 on PATH ($(clang-19 --version | head -n1))"
fi
if java -version 2>&1 | grep -qE 'version "(25|2[6-9])'; then
    echo "==> JDK on PATH ($(java -version 2>&1 | head -n1))"
else
    cat >&2 <<EOM

==> Ghidra 12.2 needs a JDK 25 on PATH (java -version shows: $(java -version 2>&1 | head -n1 || echo none))
    Debian/Ubuntu:
      sudo apt-get install -y openjdk-25-jdk-headless
    then: sudo update-alternatives --config java   (or set JAVA_HOME for Ghidra)
EOM
fi

# --- 3. git hooks --------------------------------------------------------------

if [[ -d .git ]]; then
    bash tools/install_hooks.sh
else
    echo "==> not a git repo yet; skipping hook install"
fi

echo
if [[ "${TLG_FROM_BUILD_SH:-0}" == "1" ]]; then
    echo "Setup complete; build.sh continues."
    exit 0
fi
# shellcheck source=tools/tlg_version.sh
. "$(dirname "$0")/tlg_version.sh"
tlg_version_init "$ROOT"
echo "Setup complete. Next steps:"
echo "  1. Point $TLG_PKG at your own copy of the $TLG_PKG_NAME package:"
echo "       mkdir -p baserom && ln -s /path/to/your.pkg $TLG_PKG"
echo "  2. Run './build.sh' (or 'tools/extract_pkg.sh') to extract $TLG_BASEELF"
