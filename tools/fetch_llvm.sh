#!/usr/bin/env bash
# tools/fetch_llvm.sh <version>...: fetch a prebuilt upstream LLVM release into
# tools/cc/llvm-<version>/, pinned by SHA-256, plus the libtinfo.so.5 those
# binaries link against (Debian bookworm's libtinfo5, extracted, not
# installed) into tools/cc/shim/. tools/setup.sh calls it for the project
# compiler; tools/compiler_probe.sh scores a batch of functions under every
# release present. Everything here is upstream LLVM (Apache-2.0 with LLVM
# exception); nothing comes from a Sony SDK.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
cd "$ROOT"

declare -A URL SHA
URL[3.3]=https://releases.llvm.org/3.3/clang+llvm-3.3-amd64-Ubuntu-12.04.2.tar.gz
SHA[3.3]=60d8f69f032d62ef61bf527857ebb933741ec3352d4d328c5516aa520662dab7
URL[3.4]=https://releases.llvm.org/3.4/clang+llvm-3.4-x86_64-linux-gnu-ubuntu-13.10.tar.xz
SHA[3.4]=5f1df4c12ccafa5e0938993a29aa66a50707a9c0b31d3bd6dd714d15ad375425
URL[3.4.2]=https://releases.llvm.org/3.4.2/clang+llvm-3.4.2-x86_64-linux-gnu-ubuntu-14.04.xz
SHA[3.4.2]=ef0d8faeb31c731b46ef5859855766ec7eb71f9a32cc6407ac5ddb4ccc35c3dc
URL[3.5.2]=https://releases.llvm.org/3.5.2/clang+llvm-3.5.2-x86_64-linux-gnu-ubuntu-14.04.tar.xz
SHA[3.5.2]=0290692714479c4b169e5f02408fc6d2d76f89e873aa04a795024ccde59ec482
URL[3.6.2]=https://releases.llvm.org/3.6.2/clang+llvm-3.6.2-x86_64-linux-gnu-ubuntu-14.04.tar.xz
SHA[3.6.2]=70ff742456459ecad363462c72cba00aaa5473f699da29a2a6125ee7edfb967a
URL[3.7.1]=https://releases.llvm.org/3.7.1/clang+llvm-3.7.1-x86_64-linux-gnu-ubuntu-14.04.tar.xz
SHA[3.7.1]=99b28a6b48e793705228a390471991386daa33a9717cd9ca007fcdde69608fd9
URL[3.8.1]=https://releases.llvm.org/3.8.1/clang+llvm-3.8.1-x86_64-linux-gnu-ubuntu-16.04.tar.xz
SHA[3.8.1]=fa20346ffd086f376bf7ec4b2122c5e9ada76c727d2a92d58fe1f71093c67c30
URL[3.9.1]=https://releases.llvm.org/3.9.1/clang+llvm-3.9.1-x86_64-linux-gnu-ubuntu-16.04.tar.xz
SHA[3.9.1]=99d1ffd4be8fd3331b4d2478ada7ee6ed352729bfe4a1070450cdb9a3ce8ef9b
URL[4.0.0]=https://releases.llvm.org/4.0.0/clang+llvm-4.0.0-x86_64-linux-gnu-ubuntu-16.04.tar.xz
SHA[4.0.0]=8e920c166b00e7869cea443e305933cc410bd1b982c7c5dc56995b6cffb0586f
URL[5.0.2]=https://releases.llvm.org/5.0.2/clang+llvm-5.0.2-x86_64-linux-gnu-ubuntu-16.04.tar.xz
SHA[5.0.2]=15a97aa654b529793da7d115bcfdd8b93281d94f86ec98f0850aff7cf82cbb3f
URL[6.0.1]=https://releases.llvm.org/6.0.1/clang+llvm-6.0.1-x86_64-linux-gnu-ubuntu-16.04.tar.xz
SHA[6.0.1]=7ea204ecd78c39154d72dfc0d4a79f7cce1b2264da2551bb2eef10e266d54d91
URL[7.0.1]=https://releases.llvm.org/7.0.1/clang+llvm-7.0.1-x86_64-linux-gnu-ubuntu-16.04.tar.xz
SHA[7.0.1]=02ad925add5b2b934d64c3dd5cbd1b2002258059f7d962993ba7f16524c3089c
URL[8.0.0]=https://releases.llvm.org/8.0.0/clang+llvm-8.0.0-x86_64-linux-gnu-ubuntu-16.04.tar.xz
SHA[8.0.0]=87b88d620284d1f0573923e6f7cc89edccf11d19ebaec1cfb83b4f09ac5db09c
URL[9.0.0]=https://releases.llvm.org/9.0.0/clang+llvm-9.0.0-x86_64-linux-gnu-ubuntu-16.04.tar.xz
SHA[9.0.0]=5c1473c2611e1eac4ed1aeea5544eac5e9d266f40c5623bbaeb1c6555815a27d

TINFO_URL=https://deb.debian.org/debian/pool/main/n/ncurses/libtinfo5_6.4-4_amd64.deb
TINFO_SHA=dd347f794e651039e7b4c391f86c674fed7f415b3dca6b0937beb0d470f09c1a

fetch_pinned() {  # <label> <url> <sha256> <dest>
    local label="$1" url="$2" sha="$3" dest="$4"
    if [[ -f "$dest" ]] && echo "$sha  $dest" | sha256sum -c --status; then return 0; fi
    echo "==> fetching $label"
    mkdir -p "$(dirname "$dest")"
    curl -fsSL -o "$dest.part" "$url"
    echo "$sha  $dest.part" | sha256sum -c --status || { echo "==> $label: SHA-256 mismatch" >&2; rm -f "$dest.part"; return 1; }
    mv "$dest.part" "$dest"
}

shim() {
    mkdir -p tools/cc/shim tools/cc/deb
    if [[ ! -e tools/cc/deb/lib/x86_64-linux-gnu/libtinfo.so.5 ]]; then
        fetch_pinned "libtinfo5 (Debian bookworm)" "$TINFO_URL" "$TINFO_SHA" tools/cc/libtinfo5.deb
        dpkg-deb -x tools/cc/libtinfo5.deb tools/cc/deb
    fi
    ln -sfn "$ROOT/tools/cc/deb/lib/x86_64-linux-gnu/libtinfo.so.5" tools/cc/shim/libtinfo.so.5
    local lib
    for lib in libncurses libncursesw libform libpanel; do
        [[ -e "/lib/x86_64-linux-gnu/$lib.so.6" && ! -e "tools/cc/shim/$lib.so.5" ]] &&
            ln -s "/lib/x86_64-linux-gnu/$lib.so.6" "tools/cc/shim/$lib.so.5"
    done
    return 0
}

[[ $# -gt 0 ]] || { echo "usage: $0 <version>...   (known: ${!URL[*]})" >&2; exit 2; }
shim
for v in "$@"; do
    [[ -n "${URL[$v]:-}" ]] || { echo "fetch_llvm: unknown version $v (known: ${!URL[*]})" >&2; exit 2; }
    dir="tools/cc/llvm-$v"
    if [[ -x "$dir/bin/clang" ]]; then echo "==> LLVM $v already at $dir"; continue; fi
    ext=xz; [[ "${URL[$v]}" == *.tar.gz ]] && ext=gz
    fetch_pinned "LLVM $v" "${URL[$v]}" "${SHA[$v]}" "tools/cc/llvm-$v.tar.$ext"
    mkdir -p "$dir"
    if [[ $ext == gz ]]; then tar -xzf "tools/cc/llvm-$v.tar.gz" -C "$dir" --strip-components=1
    else tar -xJf "tools/cc/llvm-$v.tar.xz" -C "$dir" --strip-components=1; fi
    echo "==> LLVM $v at $dir ($(LD_LIBRARY_PATH="$ROOT/tools/cc/shim" "$dir/bin/clang" --version | head -n1))"
done
