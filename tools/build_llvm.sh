#!/usr/bin/env bash
# tools/build_llvm.sh [--verify] [--force]: build upstream LLVM 3.6.2 + clang
# 3.6.2 from the release sources on this host, into tools/cc/llvm-3.6.2-src/.
# This is the pristine baseline on which Sony-behaviour backports are applied
# one at a time later (docs/TARGETS.md); it must compile every probe TU and
# every file under src/ to the same code as the prebuilt release under
# tools/cc/llvm-3.6.2/ (tools/fetch_llvm.sh), which --verify checks.
#
#   1. Fetch llvm-3.6.2.src.tar.xz and cfe-3.6.2.src.tar.xz from
#      releases.llvm.org, pinned by SHA-256 (both also carry Tom Stellard's
#      release signature, key 11E5 21D6 4698 2372 EB57 7A1F 8F08 71F2 0211
#      9294, checked when this pin was taken), unpack them into
#      tools/cc/src/llvm-3.6.2.src/ with clang at tools/clang.
#   2. Apply tools/patches/llvm-3.6.2-host-*.patch in order (-p1 from the
#      llvm source root). These only make the 2015 sources build with a
#      current host toolchain; none changes code generation.
#   3. Configure (CMake + ninja, Release, X86 only, no assertions), build the
#      `clang` target and install it with its resource headers
#      (lib/clang/3.6.2/include, which -nostdlibinc relies on for xmmintrin.h).
#
# Skipped when the install exists and is newer than every patch and this
# script; --force rebuilds. --verify (alone, or after a build) compiles
# tools/probe/batch*.cpp and src/**/*.cpp with the prebuilt and the built
# clang under the src/ flags of config/flags.<slug>.txt and requires
# `llvm-objdump-19 -d` of every object to be identical.
#
# Host: gcc/g++ (14 tested), cmake >= 3.5, ninja (.venv/bin/ninja or PATH).
# JOBS sets the parallelism (default 3). Everything here is upstream LLVM
# (Apache-2.0 with LLVM exception for later releases; 3.6.2 is under the
# University of Illinois/NCSA licence); nothing comes from a Sony SDK.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
cd "$ROOT"

VER=3.6.2
LLVM_URL=https://releases.llvm.org/$VER/llvm-$VER.src.tar.xz
LLVM_SHA=f60dc158bfda6822de167e87275848969f0558b3134892ff54fced87e4667b94
CFE_URL=https://releases.llvm.org/$VER/cfe-$VER.src.tar.xz
CFE_SHA=ae9180466a23acb426d12444d866b266ff2289b266064d362462e44f8d4699f3

SRCROOT="$ROOT/tools/cc/src"
SRC="$SRCROOT/llvm-$VER.src"
BLD="$SRCROOT/build-$VER"
PREFIX="$ROOT/tools/cc/llvm-$VER-src"
PREBUILT="$ROOT/tools/cc/llvm-$VER"
JOBS="${JOBS:-3}"
NINJA="$ROOT/.venv/bin/ninja"
[[ -x "$NINJA" ]] || NINJA="$(command -v ninja || true)"

do_build=1 do_verify=0 force=0
for a in "$@"; do
    case "$a" in
        --verify) do_verify=1 ;;
        --force) force=1 ;;
        -h|--help) sed -n '2,32p' "$0"; exit 0 ;;
        *) echo "usage: $0 [--verify] [--force]" >&2; exit 2 ;;
    esac
done
# `--verify` alone verifies an existing install without rebuilding it.
[[ $do_verify == 1 && $force == 0 && -x "$PREFIX/bin/clang" ]] && do_build=0

fetch_pinned() {  # <label> <url> <sha256> <dest>
    local label="$1" url="$2" sha="$3" dest="$4"
    if [[ -f "$dest" ]] && echo "$sha  $dest" | sha256sum -c --status; then return 0; fi
    echo "==> fetching $label"
    mkdir -p "$(dirname "$dest")"
    curl -fsSL -o "$dest.part" "$url"
    echo "$sha  $dest.part" | sha256sum -c --status || { echo "==> $label: SHA-256 mismatch" >&2; rm -f "$dest.part"; return 1; }
    mv "$dest.part" "$dest"
}

shopt -s nullglob
PATCHES=("$ROOT"/tools/patches/llvm-$VER-host-*.patch)
shopt -u nullglob

up_to_date() {  # the install exists and is newer than every input
    local stamp="$PREFIX/.build-stamp" p
    [[ -x "$PREFIX/bin/clang" && -f "$stamp" ]] || return 1
    for p in "${PATCHES[@]}" "$0"; do [[ "$p" -nt "$stamp" ]] && return 1; done
    # the patch set must be the same list as last time (a removed patch too)
    [[ "$(cat "$stamp")" == "$(patch_list)" ]]
}
patch_list() { local p; for p in "${PATCHES[@]}"; do sha256sum "$p" | sed "s|$ROOT/||"; done; }

build() {
    [[ -n "$NINJA" ]] || { echo "build_llvm: ninja not found (.venv/bin/ninja or PATH)" >&2; exit 1; }
    fetch_pinned "llvm-$VER.src" "$LLVM_URL" "$LLVM_SHA" "$SRCROOT/llvm-$VER.src.tar.xz"
    fetch_pinned "cfe-$VER.src" "$CFE_URL" "$CFE_SHA" "$SRCROOT/cfe-$VER.src.tar.xz"
    # Always start from fresh sources, so the tree is exactly tarball + patches.
    echo "==> unpacking into $SRC"
    rm -rf "$SRC" "$SRC.tmp"
    mkdir -p "$SRC.tmp"
    tar -xJf "$SRCROOT/llvm-$VER.src.tar.xz" -C "$SRC.tmp" --strip-components=1
    mkdir -p "$SRC.tmp/tools/clang"
    tar -xJf "$SRCROOT/cfe-$VER.src.tar.xz" -C "$SRC.tmp/tools/clang" --strip-components=1
    local p
    for p in "${PATCHES[@]}"; do
        echo "==> applying $(basename "$p")"
        patch -d "$SRC.tmp" -p1 --forward --batch --silent < "$p"
    done
    mv "$SRC.tmp" "$SRC"
    echo "==> configuring in $BLD"
    rm -rf "$BLD"
    mkdir -p "$BLD"
    CC="${CC:-gcc}" CXX="${CXX:-g++}" cmake -S "$SRC" -B "$BLD" -G Ninja \
        -DCMAKE_MAKE_PROGRAM="$NINJA" \
        -DCMAKE_POLICY_VERSION_MINIMUM=3.5 \
        -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_INSTALL_PREFIX="$PREFIX" \
        -DLLVM_TARGETS_TO_BUILD=X86 \
        -DLLVM_ENABLE_ASSERTIONS=OFF \
        -DLLVM_INCLUDE_TESTS=OFF \
        -DLLVM_INCLUDE_EXAMPLES=OFF \
        -DLLVM_INCLUDE_DOCS=OFF \
        -DLLVM_ENABLE_TERMINFO=OFF \
        -DLLVM_ENABLE_ZLIB=OFF \
        -Wno-dev > "$BLD/cmake.log" 2>&1 || { tail -n 30 "$BLD/cmake.log" >&2; exit 1; }
    echo "==> building clang (-j$JOBS; about an hour on 3 cores)"
    local t0=$SECONDS
    "$NINJA" -C "$BLD" -j"$JOBS" clang
    echo "==> installing into $PREFIX"
    rm -rf "$PREFIX"
    # The clang component installs bin/clang (+ the clang++ link); the
    # clang-headers component installs lib/clang/$VER/include.
    cmake -DCOMPONENT=clang -P "$BLD/cmake_install.cmake" >/dev/null
    cmake -DCOMPONENT=clang-headers -P "$BLD/cmake_install.cmake" >/dev/null
    [[ -x "$PREFIX/bin/clang" && -f "$PREFIX/lib/clang/$VER/include/xmmintrin.h" ]] ||
        { echo "build_llvm: install incomplete under $PREFIX" >&2; exit 1; }
    patch_list > "$PREFIX/.build-stamp"
    echo "==> LLVM $VER (from source) at $PREFIX in $(( (SECONDS - t0) / 60 )) min ($("$PREFIX/bin/clang" --version | head -n1))"
}

verify() {
    # shellcheck source=tools/tlg_version.sh
    . tools/tlg_version.sh
    tlg_version_init "$ROOT"
    local flags out f name rc=0 n=0
    flags="$(grep -m1 '^src/ ' "config/flags.${TLG_VERSION}.txt" | cut -d' ' -f2-)"
    [[ -n "$flags" ]] || { echo "build_llvm: no src/ line in config/flags.${TLG_VERSION}.txt" >&2; exit 1; }
    [[ -x "$PREBUILT/bin/clang" ]] || { echo "build_llvm: no prebuilt at $PREBUILT (tools/fetch_llvm.sh $VER)" >&2; exit 1; }
    out="$TLG_BUILD_DIR/scratch/llvm_verify"
    rm -rf "$out"; mkdir -p "$out/prebuilt" "$out/source"
    echo "==> verifying $PREFIX against $PREBUILT"
    while IFS= read -r f; do
        name="$(echo "${f%.cpp}" | tr / _)"
        # shellcheck disable=SC2086
        LD_LIBRARY_PATH="$ROOT/tools/cc/shim" "$PREBUILT/bin/clang" $flags -c "$f" -o "$out/prebuilt/$name.o"
        # shellcheck disable=SC2086
        "$PREFIX/bin/clang" $flags -c "$f" -o "$out/source/$name.o"
        local which
        for which in prebuilt source; do
            llvm-objdump-19 -d "$out/$which/$name.o" | tail -n +3 > "$out/$which/$name.dis"
            llvm-objdump-19 -dr "$out/$which/$name.o" | tail -n +3 > "$out/$which/$name.disr"
        done
        n=$((n + 1))
        if ! cmp -s "$out/prebuilt/$name.dis" "$out/source/$name.dis"; then
            echo "DIFF  $f (disassembly)"; diff "$out/prebuilt/$name.dis" "$out/source/$name.dis" | head -n 20; rc=1
        elif ! cmp -s "$out/prebuilt/$name.disr" "$out/source/$name.disr"; then
            echo "DIFF  $f (relocations)"; diff "$out/prebuilt/$name.disr" "$out/source/$name.disr" | head -n 20; rc=1
        else
            echo "same  $f"
        fi
    done < <(ls tools/probe/batch*.cpp; find src -name '*.cpp' | sort)
    if [[ $rc == 0 ]]; then echo "==> $n TUs: disassembly and relocations identical"; else echo "==> divergence (objects in $out)" >&2; fi
    return $rc
}

if [[ $do_build == 1 ]]; then
    if [[ $force == 0 ]] && up_to_date; then
        echo "==> LLVM $VER (from source) already at $PREFIX, newer than the patches"
    else
        build
    fi
fi
if [[ $do_verify == 1 ]]; then verify; fi
exit 0
