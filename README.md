# tlg

A source tree for the PlayStation 4 game **The Last Guardian** (Sony
Interactive Entertainment / genDESIGN / Japan Studio, 2016) that rebuilds the
executable of the EU retail base game 1.00, CUSA03745
(`EP9000-CUSA03745_00-LASTGUARDIANEU00`, `eboot.bin`), function by function.
`VERSION=base` picks the target (the only one, and the default).

The original was built with Sony's Orbis clang (SDK 03.508) and linked by its
linker against the SDK, neither of which is public. This tree is compiled with
a public clang, so the unit of proof is the function, not the file: a
function counts as matched when its compiled instructions equal the base
executable's at its address, with only the fields the linker fills masked
(`tools/match_check.py`). [`docs/MATCH.md`](docs/MATCH.md) describes the
workflow and [`docs/TARGETS.md`](docs/TARGETS.md) the target and what the
executable says about its own build.

<!-- progress:begin -->
| Target | Matched |
| --- | --- |
| [EU retail base game 1.00 (CUSA03745)](https://nathanialf.github.io/tlg/#base) | ![functions progress](https://img.shields.io/badge/functions-9.29%20%25-orange.svg) ![text progress](https://img.shields.io/badge/text-0.40%20%25-orange.svg) ![relro progress](https://img.shields.io/badge/relro-0.00%20%25-red.svg) ![data progress](https://img.shields.io/badge/data-0.00%20%25-orange.svg) ![bss progress](https://img.shields.io/badge/bss-0.00%20%25-red.svg) |
<!-- progress:end -->

**[Progress dashboard](https://nathanialf.github.io/tlg/)**: every function
of the executable, grouped by the source directory that claims it, compared
with the base.

> [!IMPORTANT]
> This project is not affiliated with Sony Interactive Entertainment,
> genDESIGN or Japan Studio. *The Last Guardian* is a trademark of its owners.
> No game data is in this repository; you supply your own copy. Read
> [`docs/LEGAL.md`](docs/LEGAL.md).

## Quickstart

```sh
git clone https://github.com/nathanialf/tlg.git
cd tlg
mkdir -p baserom
ln -s "/path/to/your/CUSA03745 base game.pkg" baserom/TLG_BASE.pkg
./build.sh
```

`./build.sh` runs `tools/setup.sh` when the Python environment or the tools
under `tools/ext/` are missing, extracts the executable from the package when
`baserom/base/eboot.elf` is missing (`tools/extract_pkg.sh`: the package's
filesystem to `baserom/base/app/`, the executable and modules converted from
fake-signed SELF to plain ELF by `tools/unfself.py`, their SHA-256s recorded),
verifies the recorded hashes, then runs `tools/build.sh setup` (or `verify`),
`ninja` and the gate, `tools/check_elf.py --gate`, and exits non-zero if any
step fails. The host needs a 64-bit Linux, LLVM 19 (`clang-19`,
`llvm-objdump-19`), a JDK 25 for Ghidra, and network access for the first run;
[`docs/BUILDING.md`](docs/BUILDING.md) lists the packages and describes each
step. Extracting the 12.9 GB package writes about 25 GB under `baserom/`.

The package must be one whose executable is fake-signed (unencrypted), the
form a homebrew-packaged dump takes. A retail-signed package is refused: no
key material is in this project.

The build checks the SHA-256s from `config/sha256sums.base.txt`, recorded the
first time the package is extracted and never edited:

| file | SHA-256 |
| --- | --- |
| `baserom/TLG_BASE.pkg` (the base game package) | `a0023b6d84a01959c0f8992a081961ea8e498fc177a13c7fe26b0996e3a90e54` |
| `baserom/base/eboot.bin` (the executable as shipped, a fake-signed SELF) | `a25497ce99c4884dac673872a727330097b97487943affb70d4b1b432969f473` |
| `baserom/base/eboot.elf` (converted to a plain ELF) | `f457d7b0fe0c99d2391cac5d63d030b50bd4d4feab9659ece9f11f5604c5d89f` |

## Progress badges

`tools/check_elf.py --progress` (`tools/build.sh progress`) rewrites the
badges above, [`docs/base/PROGRESS.md`](docs/base/PROGRESS.md) and the
dashboard's `docs/base/progress.json`. The `text` badge is the share of the
executable segment's bytes inside matched functions; the `functions` badge
is the count. The function list comes from the executable's own unwind
tables (`tools/survey_elf.py`, `config/functions.base.txt`): 19,733
functions covering 21.5 MB of the 23.6 MB segment.

## Layout

```
src/libs/                   the library region of the executable (below
                            0x1a3e00; LLVM 3.3): one directory per library
                            once known, src/libs/unknown/ before that
src/game/                   the game and engine (from 0x1a3e00; LLVM 4.0.0):
                            one directory per original source root as the
                            executable names them (docs/SURVEY.md),
                            src/game/unknown/ before that; one function per
                            file while its home is unknown
src/include/                shared headers
config/                     per target <slug>: sha256sums (the base files),
                            functions (every function: address, size, name),
                            matched (the functions claimed as matched, with
                            their TU), flags (compiler flags per source prefix),
                            homes (functions whose source file the executable
                            names, tools/source_homes.py), vtables (the classes
                            whose vtable the executable names,
                            tools/vtable_names.py), vtables.derived (vtables
                            named by ruling, D14), residue (the text between
                            functions, tools/text_residue.py, D13), data (the
                            data objects claimed from source, D8),
                            data_schema (a claimed table's record type and
                            count, its rows generated at build time by
                            tools/gen_data_inc.py, D18)
tools/                      setup, extraction, survey, build, match and gate
                            scripts, listed in tools/README.md
docs/                       documentation, indexed by docs/README.md;
                            docs/base/ holds the target's progress files
baserom/  build/            local only and gitignored: the user's package and
                            extracted files, and the build output
```

## Toolchain

`tools/setup.sh` fetches every tool into `tools/ext/` and `tools/ghidra/`,
pinned by SHA-256; nothing comes from a Sony SDK.

| tool | role | source | licence |
| --- | --- | --- | --- |
| LLVM 3.3, prebuilt | the release the library compiler is verified against (`tools/build_llvm.sh 3.3 --verify`) | releases.llvm.org `clang+llvm-3.3-amd64-Ubuntu-12.04.2.tar.gz`, sha256 pinned in `tools/fetch_llvm.sh`; Debian bookworm's `libtinfo5` beside it | Apache-2.0 with LLVM exception |
| LLVM 3.3, built from source | compiles `src/libs/` (the library region, built years earlier): the release sources plus six backports: clang 3.5's `-fstack-protector-strong` frontend (`docs/DECISIONS.md` D20), one nop after the stack check's failure call (D26), one store merge per visit (D27), a function's jump tables inside its size and unwind range (D28), the BEXTR combine of upstream 2013-09-02 (D29) and the lane-0 scalar selection of upstream 2013-12-10 (D31) | releases.llvm.org `llvm-3.3.src.tar.gz` and `cfe-3.3.src.tar.gz`, sha256 pinned and signatures checked in `tools/build_llvm.sh`; patches under `tools/patches/` | University of Illinois/NCSA |
| LLVM 4.0.0, prebuilt | compiles `src/game/` (the game and engine), `--target=x86_64-scei-ps4` | releases.llvm.org `clang+llvm-4.0.0-x86_64-linux-gnu-ubuntu-16.04.tar.xz`, pinned likewise | Apache-2.0 with LLVM exception |
| clang 19 (host package) | `llvm-objdump`, `llvm-readelf`, `llvm-nm`; the fallback compiler | Debian `clang-19`, `llvm-19`, `lld-19` | Apache-2.0 with LLVM exception |
| LibOrbisPkg PkgTool.Core 0.2.231 | extracts the user's package | github.com/maxton/LibOrbisPkg release v0.2, on a user-local .NET 8 runtime (`dotnet-install.sh`) | MIT |
| `tools/unfself.py` | converts the fake-signed SELFs to ELF | this repository | MIT |
| objdiff-cli 3.8.3 | an interactive diff viewer for objects, optional | github.com/encounter/objdiff release v3.8.3 | MIT / Apache-2.0 |
| Ghidra 12.2 | analysis, optional (needs a JDK 25) | github.com/NationalSecurityAgency/ghidra release | Apache-2.0 |

The executable holds two compiler generations, the libraries linked first
and the game after them, and each gets the upstream release that reproduces
its region's functions byte for byte (`tools/compiler_probe.sh`,
`tools/fingerprint.py`, [`docs/TARGETS.md`](docs/TARGETS.md),
[`docs/DECISIONS.md`](docs/DECISIONS.md)). The flags and the compiler are per
source prefix in `config/flags.base.txt`, never per function.

## Legal and licence

The code in this repository is MIT licensed ([`LICENSE`](LICENSE)). The
licence covers the code written for this project and grants no rights in the
game, its data or anything else owned by Sony Interactive Entertainment,
genDESIGN or Japan Studio. [`docs/LEGAL.md`](docs/LEGAL.md) says what may and
may not be in the repository and which references were used.
