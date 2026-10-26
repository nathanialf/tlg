#!/usr/bin/env bash
# tools/build_llvm.sh [<version>] [--verify] [--force]: build upstream LLVM +
# clang <version> (default 4.0.0; 3.3 and 3.6.2 also known) from the release
# sources on this host, into tools/cc/llvm-<version>-src/. Built with the host
# patches alone it is the pristine baseline, and it must compile every probe
# TU and every file under src/ to the same code as the prebuilt release under
# tools/cc/llvm-<version>/ (tools/fetch_llvm.sh), which --verify checks.
# Backport patches (below) are applied on top of that baseline.
#
#   1. Fetch llvm-<version>.src.tar.{xz,gz} and cfe-<version>.src.tar.{xz,gz}
#      from releases.llvm.org, pinned by SHA-256 (the release signatures were
#      checked when the pins were taken: 3.3 by Bill Wendling, key C135 49BB
#      82A1 7681 BF71 43C2 B446 8DF4 E95C 63DC; 3.6.2 by Tom Stellard, key
#      11E5 21D6 4698 2372 EB57 7A1F 8F08 71F2 0211 9294; 4.0.0 by Hans
#      Wennborg, key B6C8 F982 82B9 44E3 B0D5 C253 0FC3 042E 345A D05D),
#      unpack them into tools/cc/src/llvm-<version>.src/ with clang at
#      tools/clang. The tree is always unpacked fresh from the pinned tarballs.
#   2. Apply tools/patches/llvm-<version>-host-*.patch in order (-p1 from the
#      llvm source root). These only make the old sources build with a
#      current host toolchain; none changes code generation.
#   3. Apply the backport patches, tools/patches/llvm-<version>-<what>-*.patch
#      for every other <what> (3.3: sspstrong, the clang 3.5
#      -fstack-protector-strong frontend, docs/DECISIONS.md D20). These DO
#      change code generation, but only under the flag they add: --verify
#      without that flag must still find every object identical.
#   4. Configure (CMake + ninja, Release, X86 only, no assertions), build the
#      `clang` target and install it with its resource headers
#      (lib/clang/<version>/include, which -nostdlibinc relies on for xmmintrin.h).
#
# Skipped when the install exists, is newer than every patch and was built
# from the same patch set (hashes in <prefix>/.build-stamp, each line marked
# host or backport); --force rebuilds. --verify (alone, or after a build)
# compiles tools/probe/batch*.cpp and src/**/*.cpp with the prebuilt and the
# built clang under every flag line of config/flags.<slug>.txt (prefix and
# cxx= dropped; VERIFY_SUBST rewrites a flag the version spells otherwise:
# for 4.0.0 `-mllvm -pre-RA-sched=list-ilp` replaces any `-mllvm
# -disable-post-ra`; for 3.3 `-fstack-protector` replaces
# `-fstack-protector-strong`, which the prebuilt does not know) and requires
# `llvm-objdump-19 -d` (and -dr) of every object to be identical. VERBOSE=1
# lists each identical object too.
#
# Host: gcc/g++ (14 tested), cmake >= 3.5, ninja (.venv/bin/ninja or PATH).
# JOBS sets the parallelism (default 3). Everything here is upstream LLVM
# (3.3, 3.6.2 and 4.0.0 are under the University of Illinois/NCSA licence);
# nothing comes from a Sony SDK.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
cd "$ROOT"

declare -A LLVM_SHA CFE_SHA EXT HOST_CXXFLAGS VERIFY_SUBST
LLVM_SHA[3.3]=68766b1e70d05a25e2f502e997a3cb3937187a3296595cf6e0977d5cd6727578
CFE_SHA[3.3]=b1b55de4ab3a57d3e0331a83e0284610191c77d924e3446498d9113d08dfb996
EXT[3.3]=tar.gz
LLVM_SHA[3.6.2]=f60dc158bfda6822de167e87275848969f0558b3134892ff54fced87e4667b94
CFE_SHA[3.6.2]=ae9180466a23acb426d12444d866b266ff2289b266064d362462e44f8d4699f3
LLVM_SHA[4.0.0]=8d10511df96e73b8ff9e7abbfb4d4d432edbdbe965f1f4f07afaf370b8a533be
CFE_SHA[4.0.0]=cea5f88ebddb30e296ca89130c83b9d46c2d833685e2912303c828054c4dc98a
# The host C++ dialect and options an old tree needs (its CMake sets none):
# 3.3 is C++98 code (GCC 14 defaults to gnu++17); GCC 6 and later remove
# stores before a placement new that LLVM before 3.9 relies on
# (-fno-lifetime-dse, which upstream's own CMake adds from 3.9 on).
HOST_CXXFLAGS[3.3]='-std=gnu++98 -fno-lifetime-dse'
# --verify: "<from>|<to>" applied to every flags line for this version
VERIFY_SUBST[4.0.0]='-mllvm -disable-post-ra|-mllvm -pre-RA-sched=list-ilp'
VERIFY_SUBST[3.3]='-fstack-protector-strong|-fstack-protector'

VER=4.0.0
if [[ $# -gt 0 && "$1" != -* ]]; then VER="$1"; shift; fi
[[ -n "${LLVM_SHA[$VER]:-}" ]] || { echo "build_llvm: unknown version $VER (known: ${!LLVM_SHA[*]})" >&2; exit 2; }
X="${EXT[$VER]:-tar.xz}"
LLVM_URL=https://releases.llvm.org/$VER/llvm-$VER.src.$X
CFE_URL=https://releases.llvm.org/$VER/cfe-$VER.src.$X
case "$X" in tar.xz) TARZ=-J ;; tar.gz) TARZ=-z ;; *) echo "build_llvm: unknown archive type $X" >&2; exit 2 ;; esac

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
        -h|--help) sed -n '2,46p' "$0"; exit 0 ;;
        *) echo "usage: $0 [<version>] [--verify] [--force]" >&2; exit 2 ;;
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
HOST_PATCHES=("$ROOT"/tools/patches/llvm-$VER-host-*.patch)
BACKPORT_PATCHES=()
for p in "$ROOT"/tools/patches/llvm-$VER-*.patch; do
    [[ "$p" == */llvm-$VER-host-*.patch ]] || BACKPORT_PATCHES+=("$p")
done
shopt -u nullglob
PATCHES=("${HOST_PATCHES[@]}" "${BACKPORT_PATCHES[@]}")

up_to_date() {  # the install exists and is newer than every input
    local stamp="$PREFIX/.build-stamp" p
    [[ -x "$PREFIX/bin/clang" && -f "$stamp" ]] || return 1
    for p in "${PATCHES[@]}"; do [[ "$p" -nt "$stamp" ]] && return 1; done
    # the patch set must be the same list as last time (a removed patch too)
    [[ "$(cat "$stamp")" == "$(patch_list)" ]]
}
patch_list() {
    local p
    for p in "${HOST_PATCHES[@]}"; do echo "host     $(sha256sum "$p" | sed "s|$ROOT/||")"; done
    for p in "${BACKPORT_PATCHES[@]}"; do echo "backport $(sha256sum "$p" | sed "s|$ROOT/||")"; done
    echo "cxxflags ${HOST_CXXFLAGS[$VER]:-}"
}

build() {
    [[ -n "$NINJA" ]] || { echo "build_llvm: ninja not found (.venv/bin/ninja or PATH)" >&2; exit 1; }
    fetch_pinned "llvm-$VER.src" "$LLVM_URL" "${LLVM_SHA[$VER]}" "$SRCROOT/llvm-$VER.src.$X"
    fetch_pinned "cfe-$VER.src" "$CFE_URL" "${CFE_SHA[$VER]}" "$SRCROOT/cfe-$VER.src.$X"
    # Always start from fresh sources, so the tree is exactly tarball + patches.
    echo "==> unpacking into $SRC"
    rm -rf "$SRC" "$SRC.tmp"
    mkdir -p "$SRC.tmp"
    tar -x "$TARZ" -f "$SRCROOT/llvm-$VER.src.$X" -C "$SRC.tmp" --strip-components=1
    mkdir -p "$SRC.tmp/tools/clang"
    tar -x "$TARZ" -f "$SRCROOT/cfe-$VER.src.$X" -C "$SRC.tmp/tools/clang" --strip-components=1
    local p
    for p in "${HOST_PATCHES[@]}"; do
        echo "==> applying host patch $(basename "$p")"
        patch -d "$SRC.tmp" -p1 --forward --batch --silent < "$p"
    done
    for p in "${BACKPORT_PATCHES[@]}"; do
        echo "==> applying backport patch $(basename "$p")"
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
        -DCMAKE_CXX_FLAGS="${HOST_CXXFLAGS[$VER]:-}" \
        -DLLVM_TARGETS_TO_BUILD=X86 \
        -DLLVM_ENABLE_ASSERTIONS=OFF \
        -DLLVM_INCLUDE_TESTS=OFF \
        -DLLVM_INCLUDE_EXAMPLES=OFF \
        -DLLVM_INCLUDE_DOCS=OFF \
        -DLLVM_ENABLE_TERMINFO=OFF \
        -DLLVM_ENABLE_ZLIB=OFF \
        -Wno-dev > "$BLD/cmake.log" 2>&1 || { tail -n 30 "$BLD/cmake.log" >&2; exit 1; }
    echo "==> building clang (-j$JOBS; 30-60 min on 3 cores)"
    local t0=$SECONDS
    # The 2015-2017 sources trip many GCC 14 warnings; keep them in a log.
    "$NINJA" -C "$BLD" -j"$JOBS" clang > "$BLD/ninja.log" 2>&1 ||
        { grep -E '^FAILED|error:' "$BLD/ninja.log" | head -n 40 >&2; echo "build_llvm: build failed, log $BLD/ninja.log" >&2; exit 1; }
    echo "==> installing into $PREFIX"
    rm -rf "$PREFIX"
    # The clang component installs bin/clang (+ the clang++ link); the
    # clang-headers component installs lib/clang/$VER/include.
    cmake -DCOMPONENT=clang -P "$BLD/cmake_install.cmake" >/dev/null
    cmake -DCOMPONENT=clang-headers -P "$BLD/cmake_install.cmake" >/dev/null
    # 3.6.2's CMake has no install components (the calls above install
    # nothing); copy the driver and the resource headers the clang target
    # staged in the build tree instead.
    if [[ ! -x "$PREFIX/bin/clang" ]]; then
        mkdir -p "$PREFIX/bin" "$PREFIX/lib/clang/$VER"
        cp -a "$BLD"/bin/clang "$BLD"/bin/clang++ "$BLD"/bin/clang-[0-9]* "$PREFIX/bin/"
        cp -a "$BLD/lib/clang/$VER/include" "$PREFIX/lib/clang/$VER/"
    fi
    # The driver names itself by the file it was run as in its diagnostics,
    # which --verify compares: where the prebuilt release's bin/clang is the
    # binary itself (3.3), make ours the binary too, not a link to clang-<v>.
    if [[ -L "$PREFIX/bin/clang" && -f "$PREBUILT/bin/clang" && ! -L "$PREBUILT/bin/clang" ]]; then
        local real
        real="$(readlink -f "$PREFIX/bin/clang")"
        rm "$PREFIX/bin/clang"
        cp "$real" "$PREFIX/bin/clang"
    fi
    [[ -x "$PREFIX/bin/clang" && -f "$PREFIX/lib/clang/$VER/include/xmmintrin.h" ]] ||
        { echo "build_llvm: install incomplete under $PREFIX" >&2; exit 1; }
    patch_list > "$PREFIX/.build-stamp"
    echo "==> LLVM $VER (from source) at $PREFIX in $(( (SECONDS - t0) / 60 )) min ($("$PREFIX/bin/clang" --version | head -n1))"
}

verify() {
    # shellcheck source=tools/tlg_version.sh
    . tools/tlg_version.sh
    tlg_version_init "$ROOT"
    [[ -x "$PREBUILT/bin/clang" ]] || { echo "build_llvm: no prebuilt at $PREBUILT (tools/fetch_llvm.sh $VER)" >&2; exit 1; }
    # Flag sets: every prefix line of config/flags.<slug>.txt, prefix and any
    # cxx= token removed (so each TU is compiled under every configured flag
    # set, not only its own prefix's: more codegen paths compared). A line
    # still carrying -mllvm -disable-post-ra gets VERIFY_SUBST for versions
    # that use another scheduler flag.
    local -a sets=()
    local line rest
    while IFS= read -r line; do
        [[ -z "$line" || "$line" == \#* ]] && continue
        rest="${line#* }"
        [[ "$rest" == cxx=* ]] && rest="${rest#* }"
        if [[ -n "${VERIFY_SUBST[$VER]:-}" ]]; then
            local from="${VERIFY_SUBST[$VER]%%|*}" to="${VERIFY_SUBST[$VER]#*|}"
            rest="${rest/"$from"/"$to"}"
        fi
        sets+=("$rest")
    done < "config/flags.${TLG_VERSION}.txt"
    [[ ${#sets[@]} -gt 0 ]] || { echo "build_llvm: no flag lines in config/flags.${TLG_VERSION}.txt" >&2; exit 1; }
    local out="$TLG_BUILD_DIR/scratch/llvm_verify-$VER"
    rm -rf "$out"; mkdir -p "$out"
    echo "==> verifying $PREFIX against $PREBUILT"
    local -a tus
    mapfile -t tus < <(ls tools/probe/batch*.cpp; find src -name '*.cpp' | sort)
    local rc=0 n=0 same=0 raw=0 bothfail=0 i f name w o
    for i in "${!sets[@]}"; do
        echo "==> flag set $i: ${sets[$i]}"
        mkdir -p "$out/$i/prebuilt" "$out/$i/source"
        for f in "${tus[@]}"; do
            name="$(echo "${f%.cpp}" | tr / _)"
            n=$((n + 1))
            local okp=1 oks=1
            # shellcheck disable=SC2086
            LD_LIBRARY_PATH="$ROOT/tools/cc/shim" "$PREBUILT/bin/clang" ${sets[$i]} -I"$TLG_BUILD_DIR" -c "$f" \
                -o "$out/$i/prebuilt/$name.o" 2>"$out/$i/prebuilt/$name.err" || okp=0
            # shellcheck disable=SC2086
            "$PREFIX/bin/clang" ${sets[$i]} -I"$TLG_BUILD_DIR" -c "$f" -o "$out/$i/source/$name.o" \
                2>"$out/$i/source/$name.err" || oks=0
            if [[ $okp == 0 && $oks == 0 ]]; then
                if cmp -s "$out/$i/prebuilt/$name.err" "$out/$i/source/$name.err"; then
                    echo "both-fail  [$i] $f (same diagnostics)"; bothfail=$((bothfail + 1)); continue
                fi
                echo "DIFF  [$i] $f (both fail, different diagnostics)"; rc=1; continue
            elif [[ $okp != "$oks" ]]; then
                echo "DIFF  [$i] $f (compiles with only one of them)"; rc=1; continue
            fi
            for w in prebuilt source; do
                o="$out/$i/$w/$name"
                llvm-objdump-19 -d "$o.o" | tail -n +3 > "$o.dis"
                llvm-objdump-19 -dr "$o.o" | tail -n +3 > "$o.disr"
            done
            o="$out/$i"
            if ! cmp -s "$o/prebuilt/$name.dis" "$o/source/$name.dis"; then
                echo "DIFF  [$i] $f (disassembly)"; diff "$o/prebuilt/$name.dis" "$o/source/$name.dis" | head -n 20; rc=1
            elif ! cmp -s "$o/prebuilt/$name.disr" "$o/source/$name.disr"; then
                echo "DIFF  [$i] $f (relocations)"; diff "$o/prebuilt/$name.disr" "$o/source/$name.disr" | head -n 20; rc=1
            else
                same=$((same + 1)); [[ -n "${VERBOSE:-}" ]] && echo "same  [$i] $f"
                cmp -s "$o/prebuilt/$name.o" "$o/source/$name.o" && raw=$((raw + 1))
            fi
        done
    done
    echo "==> $n compiles (${#tus[@]} TUs x ${#sets[@]} flag sets): $same identical (disassembly and relocations; $raw of them byte-identical .o files), $bothfail fail identically under both"
    if [[ $rc != 0 ]]; then echo "==> divergence (objects in $out)" >&2; fi
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
