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
- **Which public clang.** Upstream LLVM 3.6.2, provisionally, tuned as the
  Jaguar without the post-RA scheduler. The probe (`tools/compiler_probe.sh`
  over `tools/probe/batch1.cpp` and `batch2.cpp`, ten small functions written
  from their disassembly) scored every prebuilt release from 3.5 to 9.0 and
  the host's clang 19 under the same flags:

  | LLVM | functions equal (of 10) | what breaks |
  | --- | ---: | --- |
  | 3.5.2, 3.6.2 | 7 | 0x7180, 0x12120 (below); 0xdf30 only as a struct copy |
  | 3.7.1 to 4.0.0 | 6 | also merge the two scalar stores of 0x104b0 into one vector store |
  | 5.0.2 | 5 | hoists the loads of 0x137c0 |
  | 6.0.1 | 4 | also reorders 0x14af0 |
  | 7.0.1 to 9.0.0 | 2 | also 0xbc30 and 0x17a60 |
  | clang 19 | 4 | 0xbc30, 0x17a60, 0x137c0 differ in register choice or order |

  Reading upstream's source settles what the triple does per release
  (`clang/lib/Driver`, `lib/Target/X86`; the agent report's citations are in
  `docs/NOTES.md`): **3.6.2 does not know the PS4 triple at all** (the `ps4`
  OS parses from 3.7), so it compiles `x86_64-scei-ps4` as generic x86-64 ELF
  with the SandyBridge scheduling model and every Orbis default has to be
  passed by hand. From 3.7 the triple selects `btver2`, whose scheduling
  model (`BtVer2Model`, in LLVM since 2014-09, so 3.6.2 has it when asked
  for) sets `PostRAScheduler = 1`: the post-RA list scheduler is what swaps
  the register copies of 0xbc30 and reorders 0x137c0 against the base, and
  `-mllvm -disable-post-ra` with `-march=btver2` scores the same as generic
  tuning while keeping the Jaguar instruction set the executable uses (410
  `movbe`, 207 `andn`, 69 `lzcnt`). No upstream release has any other
  PS4-specific hook in the X86 backend: no scheduler, register allocator,
  isel or vector-width change.

  Three behaviours the executable shows that upstream added for PS4 only
  LATER than 3.6, so Sony's SDK 3.5 compiler carried them ahead of upstream:
  492 `int 0x41` debug traps (upstream 3.7), 874 `ud2`, 508 of them directly
  after a `call`, the trap after a noreturn call (upstream 3.9), and 32,321
  `ymm` uses with no `vzeroupper` anywhere (upstream 4.0, the
  `fast-partial-ymm-write` feature of btver2; 3.6.2 always emits it). 4.0.0
  with the same flags reproduces all three and seven of the eight claimed
  functions; it loses 0x104b0 to store merging, which the executable shows
  rarely (13 of 272 adjacent 8-byte immediate store pairs are merged). A
  function that uses `ymm` registers or ends in a trap is therefore tried
  under 4.0.0 (`TLG_CXX=tools/cc/llvm-4.0.0/bin/clang`, or a `cxx=4.0.0`
  prefix in `config/flags.base.txt`), and the compiler question stays open
  until the matched set is large enough to decide it. The components were in
  any case built in different years: the Havok 2014.2 nightly on 2014-11-21,
  the sound engine on 2016-09-30 (its build string), the game with SDK 3.5.

  Two differences no upstream release can reproduce, so they are Sony's own
  changes to the compiler: the register assignment of 0x7180 (the base moves
  `this` out of `rdi` first and loads the callee object straight into `rdi`;
  upstream keeps `this` in `rdi` and copies at the end), and `movsxd rax,
  eax` for a 32-to-64 sign extension (679 times, against 1,106 `cdqe`).
  Upstream shrinks that `movsxd` to `cdqe` unconditionally at MC lowering
  (`SimplifyMOVSX`, `X86MCInstLower.cpp`, since 3.4; `X86::optimizeMOVSX`
  today), with no option or feature to stop it, so Sony's fork changed or
  conditioned that step. A function whose only difference is one of these is
  recorded in `docs/NOTES.md` and left unclaimed.
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
  appears 1,106 times and `movsxd rax, eax` 679 times, so the sign-extension
  choice is situational, not a blanket change. Of 272 pairs of adjacent
  8-byte immediate stores, 13 show the 3.7+ vector-store merge signature, so
  the compiler did little or no such merging.
- **Source layout.** The assert and `__FILE__` strings name 119 source files
  under four roots (`SURVEY.md`, "Source roots"): `D:/trico/engine/anzu/`
  (the engine, "anzu"; the output path above is under it),
  `C:/sound/sndx/trico/` (the sound engine, "sndx"),
  `Y:/NightlyJobs/20141121-01/Source/` (a middleware built on 2014-11-21)
  and `C:/Work/P4/depot/`. `src/<dir>/` follows those roots.
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
