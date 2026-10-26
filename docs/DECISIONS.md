# Decisions

The record of every decision that shapes what "matched" means in this tree,
and the standard each one had to meet. A decision here is not revisited by
taste; it is revisited when its stated trigger fires, with the same evidence
standard it was made under. New decisions are appended, never edited in
place; a superseded entry gets a "Superseded by" line.

## The standard

1. **Evidence from the executable first.** A claim about the original
   compiler, its flags or its libraries is backed by a measurement over the
   whole executable (`tools/fingerprint.py`: every function, not the few we
   have written) or by a primary source (Sony's own talks and patches,
   upstream LLVM source at a named tag), cited in `docs/TARGETS.md`. One
   function's diff is a hint, never a justification.
2. **Measured, not argued.** A change to the compiler or to a flag is made
   only with the probe (`tools/compiler_probe.sh`) and the gate run before
   and after. It must not lower the score of any function already matched,
   and it must raise the whole-executable agreement it was made for.
3. **Per prefix, never per function.** Flags and the compiler attach to a
   source prefix in `config/flags.base.txt`, with the evidence written beside
   them. No file-level or function-level steering, no pragmas, no attributes
   that exist to change codegen (`CLAUDE.md`, "Rules").
4. **No unexplained residue.** A function that will not match is not
   claimed and is not forgotten: its diff is classified (source form, flag,
   compiler behaviour, Sony-only) in `docs/NOTES.md` and feeds the next
   decision. "Unmatchable" is a classification that must name the compiler
   mechanism (file, pass, commit), not a shrug.
5. **Reproduce, do not approximate, when the mechanism is known.** When an
   observed behaviour is traced to a specific upstream change (a Sony
   commit, a backend feature), the project reproduces it in a from-source
   compiler build with a documented backport patch, rather than living with
   the mismatch or picking a release that happens to have it alongside
   behaviours the executable does not show.
6. **Nothing lands red.** The pre-commit gate compiles and compares every
   claimed function; the hashes of the base files are never edited; a
   claimed function is never un-claimed to pass.

## D1. The unit of proof is the function (2026-10-24)

**Decision.** A function is matched when its compiled instructions equal the
base executable's at its address, with only the fields the linker fills
masked (`tools/match_check.py`). There is no link step and no whole-ELF hash
gate.

**Why.** The original was linked by Sony's linker against Sony's libraries
(`PT_SCE_LIBVERSION`: `libSceGnm_lto`, `libSceGpuAddress`, crt), none of
which are public or reproducible; a whole-file comparison would measure the
linker, not the source. Per-function equality is the strongest claim the
available inputs support, and it is total: every instruction, every
immediate, every register.

**Trigger to revisit.** A public, reproducible way to lay out the executable
(an open linker with Sony's section and PLT conventions) would allow a
section-level gate; the function gate would remain underneath it.

## D2. The compiler (2026-10-24; superseded by D6)

**Criteria, in order.** (a) Reproduce every whole-executable fingerprint the
base shows; (b) maximise probe matches; (c) minimise downstream patches, and
each patch must be a backport of an identified upstream commit or an
identified Sony behaviour, never a tuning invented to fit.

**Evidence** (`docs/TARGETS.md`, "What the executable says about its
build"): SDK 03.508 (2016); PS4 defaults from Sony's 2013 talk; store merging
of adjacent constant 8-byte stores in 13 of 272 cases (an upstream 3.7+
behaviour mostly absent); no post-RA reordering of register copies (the
upstream btver2 model's post-RA scheduler, present from 3.7); `int 0x41`
debug traps (upstream 3.7), `ud2` after noreturn calls (upstream 3.9) and no
`vzeroupper` around 32,321 `ymm` uses (upstream 4.0), all three Sony's own
PS4 changes that reached upstream after 3.6; `movsxd rax, eax` beside `cdqe`
(no upstream release since 3.4 can emit the former; the shrink is
unconditional in `X86MCInstLower.cpp`).

**Reading.** A fork of roughly the 3.6 generation carrying Sony's PS4
patches ahead of upstream. 3.6.2 matches the generic behaviours (store
merging, scheduling) and lacks the PS4 ones; 4.0.0 has the PS4 ones and
diverges on the generic ones. Neither prebuilt release satisfies criterion
(a).

**Decision.** The project compiler is upstream LLVM 3.6.2 **built from
source** (`tools/build_llvm.sh`), first verified byte-identical to the
prebuilt release on the probe, then extended by backport patches under
`tools/patches/`, one behaviour per patch, each named for the upstream
commit it backports and each accepted only when the probe and the gate do
not regress and `tools/fingerprint.py` moves toward the executable on the
fingerprint it targets:

1. no `vzeroupper` for the Jaguar (upstream `FastPartialYMMWrite`, 4.0);
2. `ud2` after a noreturn call (upstream `TrapUnreachable` for PS4, 3.9);
3. `int 0x41` for `__builtin_debugtrap` (upstream PS4 change, 3.7);
4. the `movsxd`/`cdqe` condition, once the condition is understood from the
   1,785 sites in the executable (open; `docs/NOTES.md`).

Until the from-source build exists, the prebuilt 3.6.2 with
`-march=btver2 -mllvm -disable-post-ra` is used, and a function that depends
on 1-3 is left unclaimed rather than claimed under 4.0.0.

**Trigger to revisit.** A primary source naming the SDK 3.5 compiler's
upstream base; or the matched corpus (50+ functions) disagreeing with the
3.6 generation on a generic behaviour.

## D3. Flags (2026-10-24)

**Decision.** `config/flags.base.txt`, one line for `src/`, every flag with
its evidence beside it. The Orbis driver defaults are passed explicitly
because 3.6.2 does not know the PS4 triple. `-fwrapv` and
`-fno-strict-aliasing` are the two flags not in Sony's published defaults;
they rest on 0x12120's subtract-then-extend and reload-after-store and must
be re-confirmed by `tools/fingerprint.py` once it measures them across the
executable (open).

**Trigger to revisit.** Any matched function that a flag's removal would
still match, or that its presence breaks.

## D4. Names (2026-10-24)

**Decision.** A name is a fact or it is marked. Facts: an export, an assert or
log string, a vtable's RTTI, an import whose NID a candidate name hashes to
(`tools/nid_names.py`). Everything else is `FUN_<addr>` or carries
`/* derived name */`. Third-party notes (tlg_pc's `analysis/`) are pointers
to facts to re-verify in our own executable, never a source to copy.

## D5. Publishing (2026-10-24)

**Decision.** The repository is published to `github.com/nathanialf/tlg`
only on the maintainer's explicit word; approval of a plan is not that word.

## D6. Two compilers, one per region (2026-10-24, supersedes D2)

**Evidence.** `tools/fingerprint.py --range` shows two populations in
`.text` with a boundary at 0x1a3e00 (`docs/TARGETS.md`, "Two compiler
generations"): below it, library code of the LLVM 3.3 generation (the
`movsxd rax, eax` form upstream has shrunk to `cdqe` unconditionally since
3.4; constant stores unmerged; stack protector on); above it, the game, of
the 3.7-or-later generation (merged constant stores, `ud2` after noreturn
calls, `int 0x41`, no `vzeroupper`; stack protector off). The two traits D2
called "Sony's own" were LLVM 3.3 behaviours: the first probe batch was
drawn entirely from the lower region.

**Decision.** `src/libs/` compiles with prebuilt upstream LLVM 3.3
(`-target x86_64-pc-freebsd9`, `-march=btver2`, `-fstack-protector`) and
`src/game/` with prebuilt upstream LLVM 4.0.0 (`--target=x86_64-scei-ps4`,
`-march=btver2 -mllvm -pre-RA-sched=list-ilp`, `-fno-stack-protector`),
selected per prefix in `config/flags.base.txt`. Both reproduce their probe
batches 100% with no compiler patch. The from-source build
(`tools/build_llvm.sh`, 4.0.0) is kept as the instrument for reproducing a
behaviour that a later function shows and no release has; none is known
today.

**What the standard caught.** Criterion 1 (whole-executable evidence) is
what exposed the two regions; a probe of ten functions had pointed at a
single wrong compiler and at two "unmatchable" traits. A probe batch is now
drawn from every region, and a claim of "Sony-only" needs the fingerprint
to show the trait across the region, not a function.

**Open.** The boundary's sub-runs (0xafaa0 to 0xc68d0, 0x18adc0 to 0x18cf50
are newer-compiler code inside the library region): each library's exact
extent and compiler, to be settled as functions are attributed. Which stack
protector level the libraries used (3.3 has only `-fstack-protector`). Which
of `list-ilp`, `list-burr`, `list-hybrid` the game used. The 80
canary-loading functions in the game region.

**Trigger to revisit.** A function in either region that its compiler
cannot reproduce after source-form and flag review, classified in
`docs/NOTES.md`.

## D7. The gate is the whole text segment (2026-10-24)

**Problem.** D1's per-function comparison masks the fields the linker fills.
A call to the wrong function with the same encoding, or a reference to the
wrong data, passed. ico never had that hole: its gate links every object at
the original addresses with the unwritten functions stubbed from the user's
ELF and compares the whole file.

**Decision.** The same gate, without Sony's linker: `tools/layout_link.py`
starts from the base text segment, lays every claimed function's compiled
bytes at its address with its relocations resolved the way the original link
did (a function of the table to its address, `D_<hex>` to that address, an
import to its PLT stub, a GOT load to its slot, a literal the object defines
to the one place the base holds those bytes), and compares the image with
the base byte for byte. `tools/check_elf.py --gate` requires the image
identical, and `tools/match_check.py` checks every maskable field it can
place, so the inner loop reports a wrong target too. A relocation the
resolver cannot place fails the function with a message; nothing is guessed.

**Evidence.** A deliberate wrong callee (`FUN_00470da1` for
`FUN_00470da0`) compiles to the same bytes and now fails both the quick diff
and the gate. All 20 claimed functions resolve and the rebuilt text segment
(23,635,436 bytes) is identical to the base.

**Not rebuilt.** The PLT, the GOT, the dynamic tables and the data segments
are Sony's linker's output and are read from the base; a data function will
reference them by address. Data-only ranges stay a later decision (ico
generates them from the user's ELF at build time; the same is planned).

**Trigger to revisit.** A public linker that reproduces Sony's section
layout, which would let the image be a real link.

## D8. Every loaded segment is in the gate; data comes from source by claim (2026-10-24)

**Decision.** `tools/layout_link.py` rebuilds all three loaded segments
(`.text`: code, read-only data, PLT, unwind tables; `.relro`: vtables and the
GOT; `.data`, with its NOBITS tail `.bss`) and the gate requires each equal
to the base. A data object is claimed in `config/data.base.txt`
(`D_<hex> <tu> [<symbol>]`): the TU defines it as typed C++ under its
`D_<hex>` name, the layout takes its bytes from the object, resolves its
pointer fields the way the file holds them (a RELATIVE slot carries the
target address; an import's address slot carries 0) and requires that the
base has the matching dynamic relocation at every pointer slot. A `.bss`
object has no bytes to compare and counts as owned. The progress JSON
reports every segment as ico's schema does: the share from source, and the
share taken from the user's own executable at build time.

**Why.** ico's gate compares every allocated section; a text-only gate
would let data drift unmeasured and would give a data-referencing function
nothing to resolve against. Measuring the share "from the base" keeps the
honest number visible: today it is everything but 582 bytes.

**Not reproduced.** The PLT, the GOT and the dynamic tables are the
linker's output; they are compared but come from the base. The data-only
ranges of the game (tables, strings) are content and are never committed;
when they are needed they will be generated from the user's executable at
build time from a committed schema, as ico does (a later decision).

**Trigger to revisit.** The first data object claimed from source (to
exercise the pointer-slot rule on real data); a public linker.

## D9. Developer-native code is enforced mechanically (2026-10-24)

**Decision.** `tools/check_dev_native.py` runs in the pre-commit hook on every
staged source under `src/` and refuses: inline assembly in any spelling;
`register` and register pins; attributes, pragmas and builtins that steer
code generation (`noinline`, `always_inline`, `flatten`, `optnone`,
`optimize`, `hot`, `cold`, `section`, `alias`, `__forceinline`, `#pragma
clang optimize`, `#pragma unroll`, `__builtin_expect`, and the rest listed
in the tool); an empty `do { } while (0)`; a symbol-name alias; and
`volatile` without a comment on its line or the line above giving the data
model reason. A ruled exception goes in `tools/dev_native_allow.txt` with
its reason and is reported as allowed on every run, never silent.
Alignment (`alignas`, `aligned`), `inline`, `const`, `#pragma once` and
`#pragma pack` are layout and language, not steering, and pass.

**Why.** ICO's rulings record that the same rule, written as prose in its
CLAUDE.md and briefs, did not hold: register pins, empty asm barriers,
`do { } while (0)` wrappers and dead stores entered as ordinary-looking C
under narrower readings of "crutch", every audit missed some, and retiring
them later cost more than matching without them. The user's instruction for
this project: "we want to make sure we dont do the crutches the same. we
want dev native code." A gate the hook runs is the only form of the rule
that has held.

**What the checker cannot see.** A dead store after the last read, an
orphan carrier local, a block scope that exists to move a live range, a
`volatile` with a plausible comment on a value the program does not treat
as volatile. Those remain the reviewer's and the harvest audit's job: the
test is whether the engine's developer would have written the line to
express what the function does. The checker's list grows when a landing or
an audit shows a new spelling; the test does not change.

**Trigger to revisit.** A construct the executable proves the developer used
that the checker refuses (an alignment or packing attribute, a real
`volatile`); it is allowed by evidence in `tools/dev_native_allow.txt`, or
the rule is loosened for that construct with its evidence recorded here.

## D10. The linker's GOT-load relaxation is reproduced in the gate (2026-10-25)

**Decision.** A `mov r64, [rip+sym@GOTPCREL]` in a compiled object whose
symbol is not an import (the base has no GOT slot for it) is compared and
laid out as the `lea r64, [rip+sym]` the linker made of it:
`tools/match_check.py` rewrites the opcode (8B to 8D) before disassembling
and verifies the field as PC32 (S + A - P); `tools/layout_link.py` writes
the same bytes into the rebuilt segment. A GOT load of an import keeps its
slot as before; a GOTPCREL relocation on any other instruction form is an
error, not relaxed.

**Why.** Both compilers emit a GOT-relative load for every default-visibility
global that is not local to the TU (LLVM 3.3 `X86Subtarget.cpp:85`,
`ClassifyGlobalReference`, under `-fPIC`); there is no source form that
makes the compiler emit `lea` for an object another TU defines short of a
visibility attribute, which is a crutch. The executable, measured whole on
2026-10-25: 12,871 RIP-relative 64-bit loads land in the GOT range, reading 7
distinct slots, all imports' (the stack guard accounts for most); the GOT's
named slots are the 507 imports; 188,454 RIP-relative `lea` reach every
other global; no symbol the executable defines has a GOT slot. The linker
therefore relaxed every such load, the mov-to-lea relaxation GNU ld (2.26+)
and lld perform. The first function to need it: `FUN_00008a20`, hkOstream's
reflected-class getter (`lea rax, [rip+0x57b7e18]; ret`), one of 18 of its
shape in round 8's queue.

**Trigger to revisit.** A load through a GOT slot of a symbol the executable
defines anywhere in the base (none found), or a relaxed form other than
mov-to-lea (a `call *[rip+slot]` to `addr32 call`) that a function needs.

## D11. The build is hosted: `-ffreestanding` dropped from both prefixes (2026-10-25)

**Decision.** `config/flags.base.txt` no longer passes `-ffreestanding` for
`src/libs/` or `src/game/`. `-nostdlibinc -nostdinc++` still hide the host's
C and C++ headers; `src/include/stdlib.h` and `tlg_libc.h` declare, as our
own headers, the C library functions the executable imports (FINISHING
rule 8), which also satisfies the compiler's `xmmintrin.h` when it includes
`mm_malloc.h` in a hosted build.

**Why.** `-ffreestanding` turns the compiler's builtins off (clang
`CompilerInvocation.cpp:1244`, `NoBuiltin = ... || Freestanding`), so
`memcpy` was an ordinary call and, in tail position, a tail call (`mov edx,
edx; jmp memcpy`). The base's wrapper at 0x17e70 is `push rbp; mov rbp, rsp;
mov edx, edx; call memcpy; pop rbp; ret`: the lowering of the `llvm.memcpy`
intrinsic, which LLVM 3.3 emits with `isTailCall = false`
(`SelectionDAG.cpp:3929`; memmove :3985, memset :4049). Measured over the
executable on 2026-10-25 against the imports' PLT stubs: in the library
region memcpy, memmove and memset are called 10, 2 and 52 times and never
tail-jumped, while memcmp and strlen, which have no intrinsic, are
tail-jumped; in the game region they are called 478, 369 and 570 times with
11, 0 and 7 tail jumps, the form LLVM 4.0 gives the intrinsic in tail
position. Both regions therefore compiled with builtins on, that is, hosted.
The flag had been chosen for header reasons only (no host libc headers), not
from code-generation evidence. With it dropped every one of the 499 matched
rows still compares equal and every segment is identical; the memcpy wrapper
matches as plain `memcpy(dst, src, n)`.

**Trigger to revisit.** A matched function that needs a builtin off (a
`memcpy` the base calls where the builtin would inline or lower it
otherwise), or a hosted-only behaviour the base contradicts.


## D12. Vtables are named by the executable's type-info registrations (2026-10-26)

**Decision.** A relocation against a vtable symbol (`_ZTV<class>`, what the
compiler emits for every constructor's or finish constructor's vptr store)
resolves in the gate to the address `config/vtables.base.txt` gives that
symbol, and the base's operand must agree, exactly as a `D_<hex>` label
(`tools/base_elf.py` `address_of`; `tools/match_check.py` verifies the
target, `tools/layout_link.py` relocates to it). The file is written by
`tools/vtable_names.py` and never edited: each row is a class whose
reflection initializer stored, into the +0x20 slot of its `hkTypeInfo`
record beside the type name at +0, either a `lea` of the vtable's address
point or the vptr of a temporary it built through the class's out-of-line
finish constructor (the tool follows the constructor to the last vtable it
stores in its object, the derived class's after its bases', and an inlined
derived constructor's store over the base call's into the same stack
slot). Every address point is checked to sit 16 bytes after two zero
quadwords (offset-to-top and the absent RTTI pointer). 170 classes on
2026-10-26; no name registers two vtables and no two classes one.

**Why.** The executable is stripped and has no RTTI, so a vtable carries no
name; but a Havok type info does (`Common/Base/Reflection/hkTypeInfo.h`:
type name, scoped name, finish, cleanup, vtable, size), and the base stores
the vtable there by address. The source cannot name a vtable `D_<hex>`: the
vptr store is the compiler's, from the class the developer wrote, and
writing it by hand would be a crutch. Without the table every constructor
and finish callback of a polymorphic class was unclaimable
(`FUN_000002c0` was the first, docs/NOTES.md round 15). The gate bites: the
address shifted by 8 fails `FUN_000002c0` with "base refers to 0x168c1b0,
source to 0x168c1b8".

**Scope.** Classes without a type-info registration (the engine's, the
sound library's, Havok classes registered with a null vtable, the two
constraint data classes of NOTES round 15) stay unnamed; a vtable
established by other evidence (a constructor's store beside a name string,
a registry entry) needs its own ruling here before it is written, and would
go in a second, evidenced file, not the generated one.

**Addendum (2026-10-26, parents).** A class with no type info of its own
(an abstract base such as hkpConstraintData, whose initializer at 0x7f444
builds only its hkClass) is named through its children: a derived class's
inlined finish constructor calls the base's out-of-line finish constructor
F on the temporary and then stores its own vptr over the slot (0x7cf9c
calls 0x82850, 0x7cfb3 stores hkpPrismaticConstraintData's vtable); F
stores a vtable V that is not the derived class's; V belongs to an
ancestor on the derived class's hkClass parent chain (the hkClass
constructor's third argument, recorded per class). When every derived
class that calls F agrees on exactly one ancestor whose vtable is still
unknown, V is that ancestor's vtable; the row carries `parent <derived
classes> ctor F`. The tool writes these rows with the others.

**Trigger to revisit.** A registration the walk misreads (the tool aborts
on an address point that is not a vtable's and lists the untraced ones),
or a class whose constructor the gate needs and the type infos do not name.

## D13. The text between the functions: linker residue, padding, and two functions without unwind entries (2026-10-26)

**Decision.** `config/functions.base.txt` gains the functions the unwind
tables omit when a live reference reaches them, and everything else between
the table's functions is the linker's: padding, or residue that no source
produces and no claim may cover. `tools/text_residue.py` writes the
classification to `config/residue.base.txt` (`<lo> <hi> <class> <note>`)
and `tools/survey_elf.py` adds its `function` rows to the table with a
comment naming the reference. Measured on 2026-10-26 over the code span of
the text segment:

| class | pieces | bytes |
|---|---|---|
| padding (nop, int3) | 21,173 | 171,532 |
| function (no unwind entry, reached) | 2 | 3,019 |
| residue | 2,612 | 29,162 |

**What a reference is.** A direct call or jump (rel8 or rel32, conditional
too) or a RIP-relative operand from inside a function of the table, or a
pointer slot the loader relocates (`R_X86_64_RELATIVE` with the target in
its addend). A text address sitting in a data slot with no relocation is
stale: the loader never fixes it, so it points at nothing at run time. The
writable segments hold 621 such slots; six of them point at one-byte `ret`s
and three at zeroed `lea rax, [rip+0]; ret` stubs, none of which is a
function. A call from residue to residue (a zeroed `call +0`) is not a
reference either.

**The two functions.** 0xe270 (116 bytes) and 0x19f710 (2,903 bytes) are
static initializers: each is the target of a relocated pointer in the
initializer table that runs from 0x57ad000 to 0x57af268 (873 relocated text
pointers, every other one a function of the table), and 0xe270 constructs an
hkClass through 0x41a0. They have no FDE; nothing else distinguishes them.
Both are now rows (`FUN_0000e270 0x74`, `FUN_0019f710 0xb57`, the size from
the decoded body to its `ret`) and are matched like any other.

**The residue.** Three shapes, all with the same signature: code the linker
discarded whose bytes were left in the image. (1) Whole small bodies with
their relocations resolved to zero: `lea rax, [rip+0]; ret` (0x1060, 0x280),
`jmp +0` (0x290), `add rdi, -8; jmp +0` (0x2210, a this-adjusting thunk);
751 pieces carry a zeroed PC-relative field. (2) Tails cut mid-instruction
where a live function was laid over the head: 0x1240 begins `c4 08`, the
last two bytes of `add rsp, 8`, then the six pops and `jmp rax` of an
epilogue; 112 pieces begin undecodably. (3) Unreferenced fragments no live
function contains in full (`leave; mov eax, ecx; ret` at 0x2410; 1,739
unreferenced pieces, 188 of them byte-identical, zeros masked, to a whole
function of the table such as the empty destructor 0x2d0). No function of
the table reaches any residue byte by call, jump or RIP-relative operand,
and no relocated pointer targets one. The layout gate therefore keeps the
base's bytes there, as it does for padding, and the progress figures count
them as linker-made, not as unmatched code.

**Why not a row per fragment.** A fragment has no entry, no unwind entry
and no reference; writing source for it would be writing bytes, which is
the one thing the method forbids. The mechanism that left them (an
identical-code fold or a section discard whose bytes were not scrubbed)
belongs to Sony's linker and cannot be reproduced from source.

**Trigger to revisit.** A residue piece that a matched function's source
would need to reference, or a reference from a newly matched function into
residue (the tool reports both as a class change on the next run).

## D14. A vtable the executable does not name may be named by ruling, from the constructor that stores it (2026-10-26)

**Decision.** `config/vtables.derived.base.txt` holds rows
`<vtable symbol> <vtable address> <class name> derived ctor <function>
[evidence]`, written by the supervisor one ruling at a time, never by a
worker and never regenerated. The address is a fact: the named constructor
(or base destructor, which stores the vptr the same way) stores the
vtable's address point (address + 0x10) into its object, and
`tools/base_elf.py` verifies that by walking the constructor the first time
the gate resolves the symbol (`tools/vtable_names.py --check` verifies every
row), refusing a row whose symbol is not the mangling of its class name,
whose constructor is not in the table, or whose constructor stores another
vtable. The class name is derived: the executable has no string for it, the
definition carries `/* derived name */`, and a later fact (a type info, an
assert string, a registry entry) renames the class in every file. A vtable
the generated file names (D12) must not appear here; the loader refuses the
duplicate.

**Why.** The gate needs the vtable's address, not the truth of its name:
the compiler emits `_ZTV<class>` for whatever the class is called, and the
base's operand must agree. D4 already lets a derived name stand where it is
marked; a vtable is the same case. Without this, every constructor of a
class outside Havok's reflection (the engine's, the sound library's, Havok's
own unreflected classes: 80 such vtables in the library region and 1,263 in
the game region on 2026-10-26, against 170 the type infos name) stays
unclaimable. `tools/vtable_names.py` lists every unnamed vtable with the
evidence at hand (the storing functions, the hkClass its slot 3 returns when
that getter is this vtable's alone, the storing functions' home files) so a
ruling starts from the executable's facts. The first row is StackTracer
(0x168d840, constructor FUN_0000d8f0): a static instance at 0x57b7b80 built
at 0x6bf0 and registered with `__cxa_atexit`, the error report that builds
one on its stack at 0xb752, and the message "No stack trace available"
printed by 0xd890; no string names the class, so the name is the worker's
and marked.

**Trigger to revisit.** A fact that names a derived class differently
(rename, do not add), or a generated row appearing for a vtable a derived
row holds (delete the derived row).

## D15. One name per address: a constructor row answers for both of its spellings (2026-10-26)

**Decision.** `config/functions.base.txt` holds one name per address. A
constructor or destructor row named with one of the two spellings the
compiler emits at the same address (C1, the complete-object constructor,
and C2, the base-object constructor; D1 and D2 likewise) resolves a
reference to the other: `tools/base_elf.py` `ctor_alias`. D0, the deleting
destructor, is a separate function and has no alias.

**Why.** Without virtual bases the Itanium ABI makes C1 and C2 the same
code, and LLVM 3.3 emits C1 as an alias of C2 (`CodeGenModule.cpp`,
`EmitCXXConstructor`, `TryEmitDefinitionAsAlias`), so the executable has
one address for both. Source written natively references both: a caller
constructs the complete object (C1), a derived class's constructor calls
its base's C2. Round 17 named the rows C1 (what every matched caller used)
and the derived shapes' finish constructors, which call hknpShape's C2 at
the same address, would not have resolved.

**Trigger to revisit.** A class with a virtual base (C1 and C2 differ in
code and address), which none of the matched classes has.
