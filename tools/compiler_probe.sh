#!/usr/bin/env bash
# tools/compiler_probe.sh [<tu> ...]: compile a TU of candidate functions with
# every clang under tools/cc/llvm-*/bin/ and the host's clang-19, and score
# each function against the base (tools/match_check.py --all). The experiment
# that picks the matching compiler (docs/TARGETS.md): the release whose
# codegen agrees most often across many functions wins, and the flags in
# config/flags.<slug>.txt follow it.
#
# PROBE_FLAGS overrides the compiler flags. Default TU: tools/probe/batch1.cpp. Functions in the TU must be
# named as their rows in config/functions.<slug>.txt (extern "C" keeps the
# symbol equal to the row name). The prebuilt releases link against
# libtinfo.so.5 and libncurses.so.5; a shim directory with symlinks to the
# host's .6 libraries is created under tools/cc/shim/ and put on
# LD_LIBRARY_PATH for them.
set -uo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
cd "$ROOT"
# shellcheck source=tools/tlg_version.sh
. tools/tlg_version.sh
tlg_version_init "$ROOT"
TUS=("$@")
[[ ${#TUS[@]} -gt 0 ]] || TUS=("tools/probe/batch1.cpp")
FLAGS="${PROBE_FLAGS:---target=x86_64-scei-ps4 -O2 -fno-exceptions -fno-rtti -fno-omit-frame-pointer -momit-leaf-frame-pointer -ffreestanding -nostdlibinc -nostdinc++ -std=c++11}"
OUT="build/${TLG_VERSION}/scratch/probe"
mkdir -p "$OUT" tools/cc/shim
for lib in libtinfo libncurses libncursesw libform libpanel; do
    for so in /lib/x86_64-linux-gnu/$lib.so.6 /usr/lib/x86_64-linux-gnu/$lib.so.6; do
        [[ -e "$so" && ! -e "tools/cc/shim/$lib.so.5" ]] && ln -s "$so" "tools/cc/shim/$lib.so.5"
    done
done
export LD_LIBRARY_PATH="$ROOT/tools/cc/shim${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}"
compilers=()
for d in tools/cc/llvm-*/; do [[ -x "$d/bin/clang" ]] && compilers+=("$d/bin/clang"); done
command -v clang-19 >/dev/null && compilers+=("clang-19")
for tu in "${TUS[@]}"; do
    echo "== $tu"
    for cc in "${compilers[@]}"; do
        name="$(basename "$(dirname "$(dirname "$cc")")")"; [[ "$cc" == clang-19 ]] && name=clang-19
        ver="$("$cc" --version 2>/dev/null | head -n1)"
        if [[ -z "$ver" ]]; then printf '%-12s does not run on this host\n' "$name"; continue; fi
        obj="$OUT/$name.o"
        # shellcheck disable=SC2086
        if ! "$cc" $FLAGS -c "$tu" -o "$obj" 2>"$OUT/$name.err"; then
            printf '%-12s compile failed: %s\n' "$name" "$(head -n1 "$OUT/$name.err")"; continue
        fi
        printf '%-12s ' "$name"
        .venv/bin/python -I tools/match_check.py --obj "$obj" --all --json |
            python3 -I tools/probe/summarize.py
    done
done
