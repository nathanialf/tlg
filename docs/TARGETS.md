# Targets

One target so far. Each target has its own `config/*.<slug>.*`,
`baserom/<slug>/`, `build/<slug>/` and `docs/<slug>/`; `VERSION=<slug>`
picks it (`tools/tlg_version.py`). A second target (the v1.03 patch, another
region) would join by adding a `PKGS` row there, a `config/sha256sums.<slug>.txt`
from its own extraction, and its slug to `.github/scripts/build_pages_site.sh`
and the dashboard's picker.

## EU retail base game 1.00 (`base`)

| | |
| --- | --- |
| package | `EP9000-CUSA03745_00-LASTGUARDIANEU00`, title id `CUSA03745`, `CATEGORY=gd`, `APP_VER=01.00`, `VERSION=01.00` |
| firmware | `SYSTEM_VER=0x03700000` (3.70) |
| publishing tools (param.sfo `PUBTOOLINFO`) | `sdk_ver=03508000`, `c_date=20180603`, `st_type=digital50` |
| executable | `eboot.bin`, 92,854,265 bytes as shipped (fake-signed SELF, program type `PT_FAKE`); 92,706,009 bytes as a plain ELF |
| ELF | `ET_SCE_DYNEXEC` (0xFE10), x86-64, OS/ABI FreeBSD, entry 0xA0, 11 program headers, no section headers, no symbol table but the dynamic one |
| SDK the executable was linked against (`PT_SCE_PROCPARAM`) | 03.508.031 |
| original output path (`PT_SCE_COMMENT`) | `D:/trico/engine/anzu/bin/ps4/launch_tricom.elf` |
| code | one executable `PT_LOAD` of 23,635,436 bytes at vaddr 0; 19,733 functions by unwind table, 21,488,900 bytes |
| data | `PT_SCE_RELRO` 0x4D148 bytes at 0x168C000; a read-write `PT_LOAD` of 0x40D3288 file bytes (0x4406D10 in memory) at 0x16DC000; TLS 4 bytes (0x70 in memory) |
| dynamic | 510 symbols, 508 imports (503 functions), no exports; 29,413 RELA + 503 JMPREL relocations; 23 needed modules, 24 import libraries |
| modules shipped beside it | `sce_module/libc.prx`, `sce_module/libSceFios2.prx` (Sony's; extracted and hashed, not rebuilt) |

The full survey, program header by program header and library by library, is
[`SURVEY.md`](SURVEY.md) (`tools/survey_elf.py --md`).

### What the executable says about its build

- **Compiler.** Sony's Orbis clang from SDK 3.508 (the SDK version is in the
  process parameters; `PUBTOOLINFO` agrees). The ELF has no `.comment`
  section and no `clang version` string, so the upstream LLVM release the
  Orbis compiler was based on cannot be read off the binary. The code uses
  AVX (`vmovaps`, `vdpps`) and the AMD Jaguar scheduling clang's
  `x86_64-scei-ps4` target selects (`-march=btver2`), position-independent
  addressing, and unwind tables for every function.
- **Two compiler generations.** `tools/fingerprint.py --range` over the
  whole executable splits `.text` at 0x1a3e00:

  | | below 0x1a3e00 (3,389 functions) | from 0x1a3e00 (16,344 functions) |
  | --- | ---: | ---: |
  | `movsxd rax, eax` (never shrunk) / `cdqe` | 679 / 79 | 0 / 1,027 |
  | adjacent constant 8-byte stores left unmerged / merged into one vector store | 258 / 2 | 15 / 3,229 |
  | `ud2` after a call (trap after noreturn) | 1 | 512 |
  | `int 0x41` (PS4 debug trap) | 0 | 492 |
  | functions loading a stack canary (`__stack_chk_guard` or `__stack_chk_fail` referenced; D20) | 745 | 5,980 |
  | leaves keeping a frame pointer | 0 of 1,326 | 104 of 3,978 |

  The lower region is library code linked first and built years earlier
  (the Havok 2014.2 nightly of 2014-11-21 and others; it has sub-runs of
  both kinds at 0xafaa0 to 0xc68d0 and 0x18adc0 to 0x18cf50). The
  `movsxd`-to-`cdqe` shrink is unconditional in upstream since LLVM 3.4
  (`X86MCInstLower.cpp`, commit 068a2253e925), so that region's compiler is
  of the 3.3 generation; the upper region, the game and its engine, is of the
  3.7-or-later generation (constant-store merging) with the PS4 behaviours
  upstream gained in 3.7 (`int 0x41`), 3.9 (`ud2` after noreturn calls) and
  4.0 (no `vzeroupper` for the Jaguar). What looked like two Sony-only
  code-generation traits in the first probe (the register order of 0x7180,
  the unshrunk `movsxd`) were LLVM 3.3 behaviours: every probe function of
  the lower region matches under upstream 3.3.

- **Which public clang.** Two, one per region, both prebuilt upstream
  releases (`tools/fetch_llvm.sh`), selected per source prefix in
  `config/flags.base.txt` (`cxx=`):

  | region | prefix | compiler | tuning | probe |
  | --- | --- | --- | --- | --- |
  | libraries, below 0x1a3e00 | `src/libs/` | LLVM 3.3 (`-target x86_64-pc-freebsd9`; 3.3 knows no PS4 triple) | `-march=btver2`, default schedulers | batch 1 and 2: 10 of 10 with the right source forms |
  | game, from 0x1a3e00 | `src/game/` | LLVM 4.0.0 (`--target=x86_64-scei-ps4`) | `-march=btver2 -mllvm -pre-RA-sched=list-ilp` | batch 3: 12 of 12 |

  The probe table that led here (`tools/compiler_probe.sh`, every prebuilt
  release 3.3 to 9.0 and clang 19):

  | LLVM | batch 1+2, library region (14 fns) | batch 3, game region (12 fns) |
  | --- | ---: | ---: |
  | 3.3 | 14 | 8 |
  | 3.4, 3.4.2, 3.5.2 | 9 | 4 to 8 |
  | 3.6.2 to 5.0.2 | 8 | 12 (with list-ilp; 7 with the default scheduler) |
  | 6.0.1 to 8.0.0 | 4 to 6 | 8 |
  | 9.0.0, clang 19 | 2 to 4 | 4 to 8 |

  On the game region 3.6.2 through 5.0.2 tie; 4.0.0 is chosen because it is
  the only one of them that also shows all three PS4 behaviours the region
  has (no `vzeroupper`, `ud2` after noreturn, `int 0x41`) without a patch,
  and because its generic behaviour (store merging, scheduling) matches where
  3.6.2's does not. The pre-RA scheduler differs from upstream's x86 default
  (source order): `list-ilp`, `list-burr` and `list-hybrid` all reproduce the
  probe; `list-ilp` is used until a function tells them apart. Nothing in
  the executable so far needs a change to the compiler itself; the
  from-source build (`tools/build_llvm.sh`) stays as the instrument for the
  day one does.
- **What Sony's driver did by default.** Sony's 2013 LLVM developer meeting
  talk on the PS4 toolchain (Paul Robinson, "PS4 Toolchain", slide 23,
  https://llvm.org/devmtg/2013-11/slides/Robinson-PS4Toolchain.pdf) lists
  the defaults their clang driver changed: `-target` and `-mcpu` (a
  cross-compiler), `-std=gnu++11`, `-fno-exceptions -fno-rtti`, `-fPIC
  -fstack-protector-strong`, `-fno-omit-frame-pointer
  -momit-leaf-frame-pointer`; slide 19 says their developers build at `-O2`
  minimum, often as unity builds, "LTO might replace this"; slide 28 that
  formal releases were still based on upstream releases while they moved
  toward living on trunk. The upstream PS4 driver that landed in 3.8 (clang
  `PS4CPU.cpp`) adds `-fno-math-errno`, PIC by default, stack protector
  level strong, `-fno-use-init-array`, and the SCE debugger tuning
  (https://reviews.llvm.org/D13482). Upstream 3.6.2 predates that driver, so
  `config/flags.base.txt` passes those defaults explicitly; this executable
  confirms two of them itself: it imports `__stack_chk_fail` and
  `__stack_chk_guard` (stack protector) and is a position-independent
  `ET_SCE_DYNEXEC`. Sony kept one frozen clang ABI (version 6, "the PS4
  platform ABI follows Clang 3.2 in places", https://reviews.llvm.org/D46767)
  across SDKs, so ABI behaviour does not date the compiler.
- **What public research did not find.** No posted `orbis-clang --version`
  string for any SDK, no SDK-to-LLVM mapping, no Sony statement of release
  cadence, no Sony X86 backend patches explaining the two differences above.
  The linked Sony static libraries carry `_lto` variants (`libSceGnm_lto` in
  `PT_SCE_LIBVERSION`), so Sony's own libraries were built with LTO; nothing
  says the game was.
- **Fingerprints in the whole executable** (`llvm-objdump -d` over `.text`):
  32,321 `ymm` uses and no `vzeroupper` at all. Upstream omits `vzeroupper`
  for btver2 only from 4.0 (`fast-partial-ymm-write`) and never under generic
  tuning, while 3.6.2 always emits it, so Sony's 3.5-era compiler carried a
  Jaguar tuning upstream did not yet have; functions that touch `ymm`
  registers will not match under 3.6.2 until that is reproduced. `cdqe`
  appears 1,106 times and `movsxd rax, eax` 679 times, and the two never mix
  within a region: the `movsxd` form is the lower region's older compiler
  (above). The same split explains the constant-store merging.
- **Source layout.** The assert and `__FILE__` strings name 119 source files
  under four roots (`SURVEY.md`, "Source roots"): `D:/trico/engine/anzu/`
  (the engine, "anzu"; the output path above is under it),
  `C:/sound/sndx/trico/` (the sound engine, "sndx"),
  `Y:/NightlyJobs/20141121-01/Source/` (a middleware built on 2014-11-21)
  and `C:/Work/P4/depot/`. `src/<dir>/` follows those roots: `anzu/` (the
  engine and game, with HavokScript 2013.3 under its `external/havok/`),
  `havok/` (the 2014.2 physics nightly and the P4 geometry-processing file,
  one tree), `sndx/`. `tools/source_homes.py` maps each path string to the
  functions that load it and writes `config/homes.base.txt`: 519 functions
  name a path, 360 of them one source file (291 under `anzu/`, 48 under
  `havok/`, 21 under `sndx/`), 22 several (a unity build or an inlined
  function of another file), 130 only headers. `tools/vtable_names.py`
  reads the Havok type-info registrations (type name, scoped name, finish,
  cleanup, vtable address point, size) and writes `config/vtables.base.txt`:
  170 classes whose vtable the executable names, which the gate resolves
  `_ZTV<class>` relocations against (`DECISIONS.md` D12); vtables named by
  ruling from the constructor that stores them are in
  `config/vtables.derived.base.txt` (D14). `tools/text_residue.py` classes
  the text between the table's functions: 171,532 bytes of padding, two
  static initializers without unwind entries (now rows), and 29,162 bytes of
  linker residue no source produces (D13).
- **Libraries.** The needed modules and import libraries are Sony's system
  libraries (`libSceGnmDriver`, `libSceNgs2`, `libSceFios2`, `libScePad`,
  `libkernel`, `libc`, and the rest in `SURVEY.md`); the `PT_SCE_LIBVERSION`
  segment lists the static libraries linked (`libSceGnf`, `libSceGpuAddress`,
  `libSceShaderBinary`, the stub libraries, crt). Imports are known by NID;
  a name is attached by hashing a candidate from public documentation
  (`docs/LEGAL.md`).

### What is not read from the package

The build reads `eboot.bin` (to convert, hash and compare against) and
`sce_sys/param.sfo` (to check the target); it copies `sce_module/*.prx` and
hashes them. The `trico_*.psarc` archives (the game's assets, 24 GB) are
extracted with the rest of the filesystem and never read, and nothing from
them is committed.
