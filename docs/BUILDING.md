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
  LLVM 3.3 and 4.0.0 `setup.sh` fetches (below). Upstream LLVM knows the
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
| LLVM 3.3 and 4.0.0 prebuilt + Debian's `libtinfo5` (`tools/fetch_llvm.sh`) | `tools/cc/llvm-3.3/`, `tools/cc/llvm-4.0.0/`, `tools/cc/shim/` | the compilers of the two regions (`docs/TARGETS.md`); other releases for `tools/compiler_probe.sh` on demand |
| LLVM 3.6.2 / 4.0.0 built from source (`tools/build_llvm.sh`, optional, about 20 and 40 minutes) | `tools/cc/llvm-<version>-src/` | verified byte-identical to the prebuilt releases; the base for any future backport patch |
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

## 4. `ninja` and the gate

`ninja` compiles every object, then runs `tools/check_elf.py --gate`: for
every row of `config/matched.base.txt` (`<function> <tu> [<symbol>]`), the
function's bytes in the TU's object are compared with the base executable's
at the function's address (`config/functions.base.txt`), instruction by
instruction, with only the linker-filled fields masked
(`tools/match_check.py`; `docs/MATCH.md` explains the masking). Every row must
score 1.0; a row naming an unknown function, a missing symbol or a TU that
does not compile fails too. There is no link step: the original's linker and
SDK libraries are Sony's, so the proof is per function.

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
  `tools/format.sh --check` on staged sources, and when a staged path is under
  `src/`, `config/` or `tools/`: `tools/build.sh gate-all`, then
  `tools/build.sh progress-all`, whose refreshed files are staged into the
  commit.
- **pre-push**: `gate-all` on the tip of each pushed ref, in a temporary
  worktree.

`git commit --no-verify` bypasses the first and `git push --no-verify` the
second; use either only for a commit that cannot touch the build.

## Formatting

`tools/format.sh` runs clang-format with the tracked `.clang-format` over the
sources under `src/` (`--check` for the hook). Whitespace only.
