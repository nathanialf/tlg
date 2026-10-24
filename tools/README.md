# tools/

Every file in this directory, with what it does. One tree may carry several
targets (a target is configured when `config/sha256sums.<slug>.txt` exists);
the tools work on the target `tlg_version.py` reports (`VERSION=<slug>`, or
the first configured one, `base`), and the config, base file, build
(`build/<slug>/`) and progress (`docs/<slug>/`) paths follow that slug.
`tools/ext/` and `tools/ghidra/` are fetched by `setup.sh` and not tracked.
`../build.sh` at the repository root runs `setup.sh` and `extract_pkg.sh` when
their output is missing, then `build.sh verify` or `setup` and ninja, whose
last step is the gate.

| tool | what it does |
| --- | --- |
| `setup.sh` | idempotent host setup: the venv from `requirements.txt`; the pinned tools into `tools/ext/` (a user-local .NET 8 runtime and LibOrbisPkg's PkgTool.Core, objdiff-cli) and `tools/ghidra/` (Ghidra 12.2); the compilers, LLVM 3.3 and 4.0.0, via `fetch_llvm.sh`; a check for the host's LLVM 19 and JDK 25; the git hooks |
| `requirements.txt` | the venv's Python packages: pyelftools, capstone, ninja, clang-format |
| `install_hooks.sh` | writes the pre-commit hook (`check_no_rom.sh`, `format.sh --check` on the staged sources, then `build.sh gate-all` and `build.sh progress-all` when a staged path can affect the build) and the pre-push hook (`build.sh gate-all` on the pushed tip) |
| `extract_pkg.sh` / `extract_pkg.py` | extracts the user's package (`baserom/TLG_BASE.pkg`) with PkgTool.Core to `baserom/<slug>/app/`, copies out the executable, `param.sfo` (a PKG entry) and the modules, converts the fake-signed SELFs to ELF (`unfself.py`), checks the content id, and records or verifies the SHA-256s in `config/sha256sums.<slug>.txt` |
| `unfself.py` | fake-signed SELF to plain ELF: the ELF headers verbatim and each segment at its `p_offset`; refuses encrypted or compressed entries. Output byte-identical to the reference `ps4_unfself` for every file of this target |
| `sfo.py` | reads a `param.sfo` and prints its fields |
| `tlg_version.py` / `tlg_version.sh` | the target slug (`VERSION`, or the first configured one) and the configured ones, its base file, build, `config/sha256sums.<slug>.txt` and `docs/<slug>/` paths, and the table of each target's package and how messages name it, for the Python and shell tools |
| `verify_elf.py` | checks a file's SHA-256 against `config/sha256sums.<slug>.txt` |
| `survey_elf.py` | the executable's map: every function's address, size and name from `.eh_frame` into `config/functions.<slug>.txt`; the SCE program headers (SDK version, original output path, linked libraries), the dynamic imports and needed modules, and the source paths in the strings into `build/<slug>/survey.json`; `--md` prints `docs/SURVEY.md` |
| `build.sh` | `setup` (delete `build/<slug>/`, verify the hashes, write `build.ninja`), `verify`, `regen`, `clean`, `distclean`, `progress` (runs `check_elf.py --progress`), `gate-all` (every configured target: base files required, then setup, ninja, gate), `progress-all` |
| `gen_ninja.py` | writes `build.ninja`: a `cxx` edge per source under `src/` (`compile_cpp.sh`) to `build/<slug>/obj/<path>.o`, and the default `gate` target, `check_elf.py --gate` |
| `compile_cpp.sh` | compiles one source with the flags `config/flags.<slug>.txt` gives its longest matching prefix; the compiler is the release the prefix's `cxx=<version>` names (3.3 for `src/libs/`, 4.0.0 for `src/game/`), else `TLG_CXX`, else the prebuilt 4.0.0 |
| `fingerprint.py` | compiler fingerprints over the whole disassembly (cdqe vs movsxd, store merging, vzeroupper, ud2 after call, int 0x41, frame pointers by leaf/non-leaf, stack canaries, the Jaguar instructions), for the base executable (`--range lo:hi` for one region) or a built object; the instrument behind docs/DECISIONS.md |
| `nid_names.py` | names the executable's imports by recomputing NIDs (SHA-1 of the name and the public suffix, base64) for the candidates in `config/nid_candidates.txt` and `tools/ext/nid_candidates.txt`; writes `config/imports.<slug>.txt`; `--name` prints one NID, `--check <file>` tests a list |
| `fetch_llvm.sh` | fetches a prebuilt upstream LLVM release (3.3 to 9.0.0, each pinned by SHA-256) into `tools/cc/llvm-<version>/`, and the `libtinfo.so.5` those binaries need into `tools/cc/shim/` (Debian's libtinfo5 package, extracted); `setup.sh` runs it for 3.3 and 4.0.0 |
| `compiler_probe.sh` | compiles a TU of candidate functions (`tools/probe/batch*.cpp`, functions named as their rows) with every release under `tools/cc/` and the host clang, and scores each function against the base; `PROBE_FLAGS` overrides the flags. The experiment behind the compiler choice (`docs/TARGETS.md`) |
| `probe/` | the probe batches and `summarize.py`, which turns `match_check.py --json` lines into one score line |
| `match_check.py` | one function, or every function of a TU (`--all`), against the base: the compiled function's instructions (from the object's symbol and its relocations) and the base's at the function's address, compared in step with only the relocated fields masked; the score is the share of equal instructions, 1.0 a match; `--diff` prints the first difference in context |
| `quick_diff.sh` | `<tu> <function> [<symbol>]`: compile the TU and show the function's diff; the inner loop |
| `check_elf.py` | `--gate`: every row of `config/matched.<slug>.txt` must score 1.0; `--progress`: `docs/<slug>/progress.json` (schema 2: groups by source directory, `unassigned` in 1 MiB ranges), `docs/<slug>/PROGRESS.md` and README.md's badge row |
| `check_no_rom.sh` | IP guard: refuses packages, executables, modules, `param.sfo` and other package files by extension and name, ELF/SELF/PKG magic, large binaries, raw byte-array initializers in tracked sources, and runs of hex directives |
| `format.sh` | clang-format with the tracked `.clang-format`; `--check` for the pre-commit hook |
