# Building

How the tree goes from a clean clone to the gate, step by step, and what each
tool needs. The one-command form is `./build.sh`; this document is what it
does.

## Host

A 64-bit Linux. Tested on Debian 13 (trixie), x86-64, 4 cores, 12 GB RAM.
Disk: the package is 12.9 GB and its extracted filesystem about 25 GB, both
under `baserom/`.

Host packages (Debian names; `tools/setup.sh` checks for them and prints this
line when one is missing):

```sh
sudo apt-get install -y clang-19 lld-19 llvm-19 openjdk-25-jdk-headless python3-venv unzip curl git
```

- `clang-19`, `llvm-19`, `lld-19`: `llvm-objdump-19`, `llvm-readelf-19`,
  `llvm-nm-19`, and the fallback compiler. The compilers are the prebuilt
  LLVM 4.0.0 `setup.sh` fetches and LLVM 3.3 built from source with its
  backports (`tools/build_llvm.sh 3.3`, below). Upstream LLVM knows the
  PS4 triple from 3.7; no SDK is involved.
- `openjdk-25-jdk-headless`: for Ghidra 12.2 (optional; the survey does not
  need it).

Everything else is fetched by `tools/setup.sh` into `tools/ext/` and
`tools/ghidra/` (gitignored), pinned by SHA-256:

| tool | where | why |
| --- | --- | --- |
| Python venv (`tools/requirements.txt`: pyelftools, capstone, ninja, clang-format) | `.venv/` | every Python tool; ninja; the formatter |
| .NET 8 runtime (`dotnet-install.sh`, user-local) | `tools/ext/dotnet/` | runs PkgTool.Core |
| LibOrbisPkg PkgTool.Core 0.2.231, framework-dependent build | `tools/ext/pkgtool/` | extracts the package (the self-contained Linux build bundles a 2020 .NET Core 3 that needs libssl 1.x and ICU, neither on a current host) |
| LLVM 3.3 and 4.0.0 prebuilt + Debian's `libtinfo5` (`tools/fetch_llvm.sh`) | `tools/cc/llvm-3.3/`, `tools/cc/llvm-4.0.0/`, `tools/cc/shim/` | the game region's compiler, and the 3.3 release the library region's from-source build is verified against (`docs/TARGETS.md`); other releases for `tools/compiler_probe.sh` on demand |
| LLVM 3.3, 3.6.2 and 4.0.0 built from source (`tools/build_llvm.sh <version>`; 3.3 is required, about 15 minutes on 3 cores; 3.6.2 and 4.0.0 optional, about 20 and 40) | `tools/cc/llvm-<version>-src/` | verified byte-identical to the prebuilt releases (`--verify`); 3.3 then carries the eight backports the library prefix compiles with (`cxx=3.3-src`, D20, D26, D27, D28, D29, D31, D33). Pins: llvm-3.3.src.tar.gz `68766b1e70d05a25e2f502e997a3cb3937187a3296595cf6e0977d5cd6727578`, cfe-3.3.src.tar.gz `b1b55de4ab3a57d3e0331a83e0284610191c77d924e3446498d9113d08dfb996` (signed by Bill Wendling, key C135 49BB 82A1 7681 BF71 43C2 B446 8DF4 E95C 63DC); host build `-std=gnu++98 -fno-lifetime-dse -fno-delete-null-pointer-checks` with GCC 14 (the last keeps the `this == 0` tests of `Value::print` and `Type::print`, which `-print-after-all` relies on); host patch `llvm-3.3-host-01-llvm-build-python3` (the configure-time tool to Python 3); backports `llvm-3.3-sspstrong-01-fstack-protector-strong` (clang 3.5's `-fstack-protector-strong` frontend, changes code only under that flag) and `llvm-3.3-sspnop-01-stack-chk-fail-nop` (one nop after every call to `__stack_chk_fail`, as the PS4 compiler emits it, D26; changes code only where a canary is emitted) and `llvm-3.3-storemerge-01-single-merge-per-visit` (one store merge per visit of a store, the 3.2 release's `visitSTORE`, D27; changes code only where one chain holds more than one mergeable run) and `llvm-3.3-jumptable-01-table-before-function-end` (a function's jump tables printed before its end label, so its size and unwind range cover them, D28; changes only functions with a switch table) and `llvm-3.3-bextr-01-and-shift-mask-combine` (upstream b25f0f5538fb of 2013-09-02: `bextr` from a shifted value masked with a contiguous mask, D29; changes only such extracts on a BMI target) and `llvm-3.3-scalarfp-01-lane0-op-insert` (upstream r196925 of 2013-12-10: a scalar add, sub, mul or div on lane 0 followed by its insert selects the SSE scalar instruction, D31; changes only such lane-0 operations) and `llvm-3.3-memdepdbg-01-dbg-before-scan-limit` (upstream r194646 of 2013-11-13: a debug intrinsic is skipped before the memory dependence scan's block limit is spent, D33; changes only `-g` compiles whose scan meets debug intrinsics) and `llvm-3.3-inlinedbg-01-dbg-not-counted-in-vector-bonus` (upstream r200609 of 2014-02-01: a debug intrinsic is not counted among the instructions the inline cost's vector bonus is decided on, D33; changes only `-g` compiles where that count decides an inline) |
| objdiff-cli 3.8.3 | `tools/ext/objdiff/` | optional interactive object diff viewer |
| Ghidra 12.2 | `tools/ghidra/ghidra_12.2_PUBLIC/` | optional analysis (`SKIP_GHIDRA=1` skips the 570 MB download) |

## One command

```sh
mkdir -p baserom
ln -s "/path/to/your/CUSA03745 base game.pkg" baserom/TLG_BASE.pkg
./build.sh
```

`build.sh`:

1. runs `tools/setup.sh` when `.venv/`, PkgTool or objdiff are missing;
2. runs `tools/extract_pkg.sh` when `baserom/base/eboot.elf` or
   `config/sha256sums.base.txt` is missing;
3. runs `tools/build.sh verify` (the recorded SHA-256s of `eboot.bin` and
   `eboot.elf`);
4. runs `tools/build.sh setup` when there is no `build.ninja`, then `ninja`,
   whose default target compiles every source under `src/` and ends with the
   gate, `tools/check_elf.py --gate`.

It exits non-zero when any step fails.

## 1. Host setup: `tools/setup.sh`

Idempotent. Creates the venv and installs `tools/requirements.txt`; fetches
the pinned tools above (a download whose SHA-256 does not match is refused);
checks the host packages; installs the git hooks (`tools/install_hooks.sh`).
`SKIP_TOOLCHAIN=1` skips the downloads, `SKIP_GHIDRA=1` only Ghidra.

## 2. The executable: `tools/extract_pkg.sh`

`tools/extract_pkg.py`, in the venv:

1. `PkgTool.Core pkg_extract baserom/TLG_BASE.pkg baserom/base/app` (about
   seven minutes; skipped when `baserom/base/app/uroot/eboot.bin` exists). The
   package's PFS filesystem lands under `app/uroot/`: `eboot.bin`,
   `sce_module/`, `sce_sys/`, `sce_discmap.plt` and the `trico_*.psarc`
   archives, which nothing reads.
2. `baserom/base/eboot.bin`: the executable as shipped, a fake-signed SELF
   (magic `4F 15 3D 1D`, program type `PT_FAKE`). `tools/unfself.py` unwraps
   the container into `baserom/base/eboot.elf`: the ELF header and program
   headers verbatim, each segment at its `p_offset`. It decrypts nothing: an
   entry with the Encrypted or Compressed bit set (a retail SELF) stops the
   build with a message. Its output is byte-identical to the reference
   `ps4_unfself` tool's for this executable and both modules.
3. `baserom/base/param.sfo`: PKG entry 11 (`pkg_extractentry`), decoded to
   `param.sfo.txt` (`tools/sfo.py`). The content id and `APP_VER` must be the
   target's (`tools/tlg_version.py`, `PKGS`), or the run stops.
4. `baserom/base/modules/`: `sce_module/*.prx`, each also converted to `.elf`.
5. `config/sha256sums.base.txt`: the SHA-256 of the package, `eboot.bin`,
   `eboot.elf`, `param.sfo` and each module, recorded on the first run and
   verified on every later one. **Never edit the hashes.** A mismatch is a
   different package or a changed tool, and either is a finding.
   `--no-pkg-hash` skips hashing the package itself.

## 3. `tools/build.sh setup`

Deletes `build/base/`, verifies the hashes, writes `build.ninja`
(`tools/gen_ninja.py`): one `cxx` edge per source under `src/`
(`tools/compile_cpp.sh`, flags from `config/flags.base.txt` by longest
matching prefix) to `build/base/obj/<path>.o`, and the `gate` target.
`tools/build.sh regen` rewrites it after adding a source; `verify` checks the
hashes alone; `clean` and `distclean` remove the build output.

The gate (`gate-all`, what the hooks run) does not start from `setup`: its
`prepare` step verifies the hashes and rewrites `build.ninja`, and ninja
rebuilds what changed from its dependency log (every header a TU includes is
in the object's depfile; each object names its compiler binary as an implicit
input, so a rebuilt compiler rebuilds every object). `TLG_CLEAN=1
tools/build.sh gate-all` deletes `build/base/` first, the from-scratch form.
The gate writes `build/base/gate.pickle` (its per-function results and the
laid-out image, keyed by the configuration rows and the claimed objects'
sizes and mtimes); `progress-all` reuses it when the key still matches
instead of laying the image out a second time.

A claimed table whose bytes carry the package's content (records, string
pointers) is committed as its type, count and name only (`docs/DECISIONS.md`
D18): its row of `config/data.base.txt` names the TU that defines it, and its
row of `config/data_schema.base.txt` (`D_<hex> <record type> <count>
<header>`) the record struct in `src/include/`. For each schema row
`build.ninja` has a `gen_data` edge, `tools/gen_data_inc.py`, which reads the
rows from the user's own `baserom/base/eboot.elf` and writes
`build/base/gen/D_<hex>.inc` (rewritten only when its text changes); that file
is an implicit input of the TU's compile, which includes it between the
braces of the definition as `"gen/D_<hex>.inc"` (`tools/compile_cpp.sh` puts
`build/base/` on the include path). Nothing under `build/` is committed.

## 4. `ninja` and the gate

`ninja` compiles every object, then runs `tools/check_elf.py --gate`: for
every row of `config/matched.base.txt` (`<function> <tu> [<symbol>]`), the
function's bytes in the TU's object are compared with the base executable's
at the function's address (`config/functions.base.txt`), instruction by
instruction, with only the linker-filled fields masked
(`tools/match_check.py`; `docs/MATCH.md` explains the masking and the target
check). Then `tools/layout_link.py` rebuilds the text segment, every claimed
function at its address with its relocations resolved and the rest from the
base, and the image must equal the base byte for byte
(`build/base/text.bin`, `build/base/layout.json`). Every row must score 1.0
with correct targets; a row naming an unknown function, a missing symbol, a
TU that does not compile, or a relocation the resolver cannot place fails
too. There is no real link: the original's linker and SDK libraries are
Sony's, so the layout is done by the tool and the PLT, GOT and data are read
from the base.

The inner loop is `tools/quick_diff.sh <tu> <function> [<symbol>]`.

## The survey: `tools/survey_elf.py`

Writes `config/functions.base.txt` (every function's address, size and name,
from the executable's unwind tables) and `build/base/survey.json`; `--md`
prints `docs/SURVEY.md`. It reads the program headers, `.eh_frame_hdr` and
`.eh_frame`, the SCE dynamic tags (string and symbol tables inside
`PT_SCE_DYNLIBDATA`), `PT_SCE_PROCPARAM`, `PT_SCE_COMMENT`,
`PT_SCE_LIBVERSION`, and the source paths in the executable's strings.
Re-run it only when the tooling changes; the function list is the base of
every claim.

## Progress and the dashboard

`tools/build.sh progress` (`tools/check_elf.py --progress`) runs the same
comparison and rewrites `docs/base/progress.json` (the dashboard's data,
schema 2), the table in `docs/base/PROGRESS.md` and the badge row between
the `<!-- progress:begin -->` / `<!-- progress:end -->` markers in
`README.md`. The dashboard, `docs/index.html`, reads `base/progress.json`;
preview it locally with `python3 -m http.server -d docs` and open
`http://localhost:8000/`. `.github/workflows/pages.yml` publishes
`docs/index.html`, `docs/base/progress.json` and `docs/base/PROGRESS.md` to
GitHub Pages on a push to `main` that changes one of them
(`.github/scripts/build_pages_site.sh` assembles `_site/`).

## Hooks

`tools/install_hooks.sh` (run by `setup.sh`) writes two hooks:

- **pre-commit**: `tools/check_no_rom.sh` (the IP scan of the staged files),
  `tools/check_dev_native.py` (no crutches in the staged sources),
  `tools/format.sh --check` on staged sources, and when a staged path is under
  `src/`, `config/` or `tools/`: `tools/build.sh gate-all`, then
  `tools/build.sh progress-all`, whose refreshed files are staged into the
  commit.
- **pre-push**: `gate-all` on the tip of each pushed ref, in a temporary
  worktree, unless the tip's tree is one the pre-commit hook (or an earlier
  push) already gated: the hooks record each gated tree's hash in
  `.git/gated-trees`, and the gate is a function of the tree alone, so a
  commit pushed as it was gated is not gated twice. A commit made with
  `--no-verify` records nothing and is gated at push.

`git commit --no-verify` bypasses the first and `git push --no-verify` the
second; use either only for a commit that cannot touch the build.

## Formatting

`tools/format.sh` runs clang-format with the tracked `.clang-format` over the
sources under `src/` (`--check` for the hook). Whitespace only.
