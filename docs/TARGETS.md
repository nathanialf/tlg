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
- **Which public clang.** Upstream LLVM 3.6.2, provisionally. The probe
  (`tools/compiler_probe.sh` over `tools/probe/batch1.cpp`, ten small
  functions written from their disassembly) scored every prebuilt release
  from 3.5 to 9.0 and the host's clang 19 under the same flags:

  | LLVM | functions equal (of 10) | what breaks |
  | --- | ---: | --- |
  | 3.5.2, 3.6.2 | 7 | 0x7180, 0x12120 (below); 0xdf30 only as a struct copy |
  | 3.7.1 to 4.0.0 | 6 | also merge the two scalar stores of 0x104b0 into one vector store |
  | 5.0.2 | 5 | hoists the loads of 0x137c0 |
  | 6.0.1 | 4 | also reorders 0x14af0 |
  | 7.0.1 to 9.0.0 | 2 | also 0xbc30 and 0x17a60 |
  | clang 19 | 4 | 0xbc30, 0x17a60, 0x137c0 differ in register choice or order |

  The flags that held across releases are in `config/flags.base.txt`:
  generic x86-64 tuning with the Jaguar's instruction set (under the btver2
  scheduling model the two register copies of 0xbc30 come out swapped),
  `-fwrapv`, `-fno-strict-aliasing`, frame pointers kept in non-leaves.
  3.6.2 is chosen over 3.5.2 as the later of the two equal scorers and the
  closer to SDK 3.5's date; the choice is revisited as the matched set grows
  (`tools/compiler_probe.sh tools/probe/*.cpp` reruns the comparison).

  Two differences no upstream release reproduces, so they are Sony's own
  changes to the compiler: the register assignment of 0x7180 (the base moves
  `this` out of `rdi` first and loads the callee object straight into `rdi`;
  upstream keeps `this` in `rdi` and copies at the end) and `movsxd rax, eax`
  for a 32-to-64 sign extension where every upstream release emits `cdqe`
  (0x12120). A function whose only difference is one of these is recorded as
  such in `docs/NOTES.md` and left unclaimed.
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
