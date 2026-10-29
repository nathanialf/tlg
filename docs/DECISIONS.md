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

**Addendum, 2026-10-26 (round 28 harvest).** The trigger fired: 0x12120 is
not a matched function, 0x13d80 matches only without `-fwrapv`, and every
claimed row (989) matches with the flag or without it in both lines, so
`-fwrapv` leaves both lines (D24). `-fno-strict-aliasing` keeps its
evidence (0x79a5d0's reload) and stays.

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

**Addendum, 2026-10-26 (round 29 harvest).** A read-only string the base
holds (a debug message in `.rodata`) is referenced from source as the data
it is, `extern const char D_<hex>[]`, resolved by address like any `D_<hex>`
reference (the compiler's GOT load becomes the base's `lea` under D10). Its
text is never copied into the tree: docs/LEGAL.md's rule on debug strings.
The first use is FUN_0019a490's 631-character message at 0x14cca20.

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

**Addendum, 2026-10-27 (round 31 harvest): `__restrict`.** Round 31's
hknpCircularSurfaceVelocity::calcVelocities (0x15fa60, slot 5) copies a
vector into an output and uses the value again without reloading it after
the store through the output pointer, and GVN merges the two loads only
when the output cannot alias the input: the bytes are correct only under a
no-alias promise, so the developer declared one, `HK_RESTRICT` on both
output parameters (`__restrict`, declared in `src/include/tlg_hk_reflect.h`
under Havok's HK_ prefix; docs/COOKBOOK.md 77). `__restrict` is language,
a promise about the program's pointers, not steering, and passes the
checker, under the test of this decision: it is written where the bytes
prove the promise (a reload omitted across a store through another
pointer) and refused where it only moves bytes around. The cookbook entry
carries the proof for each use.

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

**Addendum, 2026-10-28 (round 44 harvest).** A GOT slot the linker filled
with the address of an object the executable defines is a slot the base
keeps: a RELATIVE relocation among the import slots (eleven in the
base). The code folds such a load into an arithmetic instruction
(`mov esi, 0x1d0; add rsi, [rip+0x16d80d8]` at 0x6fc9c reads the
constant table 0x14b2060 through the slot 0x16d80d8), which no
relaxation to `lea` can express, so the linker left the GOT access.
`BaseElf.got_slots` now names those slots after their target (`D_<hex>`),
and the layout places a GOTPCREL reference to such an object at the
base's slot instead of refusing it. FUN_0006fc70 (hknpShape's slot 28
default, 104 bytes) is the first row placed this way.

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

**Addendum, 2026-10-26 (round 19 harvest).** A row cites its constructor
by address: `ctor FUN_<hex>` is looked up by the address when no row of the
function table carries that name any more, so a derived row survives the
renaming of its constructor's row to the mangled symbol (hkSlot's base
destructor 0x47cb0 is `_ZN6hkSlotD1Ev` in both tables; the derived row still
says `FUN_00047cb0`). Fourth row: hknpSurfaceVelocityModifier (0x16a5600,
constructor FUN_0016d1f0), one of the twenty modifiers of the set
FUN_00048b20 allocates at 0x49d0f and fills from 0x49d8b, all unnamed (no
`hknp*Modifier` string exists in the executable; the only `Modifier` strings
are the game's own). The vtable has the set's thirteen-slot interface; its
slot 2 returns the callback mask 8 and the one callback it implements, slot
7 (0x16d200), averages the manifold's contact positions, asks the object at
+0x30 of each body's material for its linear and angular velocity there
(the reflected class hknpSurfaceVelocity, slot 5) and applies body B's minus
body A's to the contact jacobian (0x348e0). The name is the provider class's
plus `Modifier`, derived; the other nineteen are named the same way when
their one implemented callback is read.

**Addendum, 2026-10-26 (round 23 harvest).** Three rows: `ImageSource`
0x16a6610 (constructor FUN_00188e90; slots 5 and 6 are pure, relocated to
the pure-virtual import; built by hkMemoryMeshTexture's slot 7 at 0xad7f2
in a 0x18-byte object), `FileImageSource` 0x16a3aa0 (constructor, in the
row's sense, the destructor FUN_000ad590 that stores it; the derived
source over a file name, slot 6 loading a "tga" file; stored at 0xad80a
after the base constructor), and `Allocator0000ed40` 0x168da00 (the
thirteen-slot allocator interface, built at 0xbb69 at +0 of the object
FUN_0000bb60 constructs). The first two names follow the object's role
(an image source, a file-backed one) and the third the constructor's
address: a derived name is a placeholder a fact replaces, and
`docs/FINISHING.md` lists address-named classes as debt. The slots and
the relocations were read from the executable by the supervisor
(`tools/layout_link.py` `base_dynamic_relocs`), the constructor stores
from the disassembly.

**Addendum, 2026-10-26 (round 24 harvest).** Six more rows, each slot read
from the base's RELATIVE relocations and each vptr store found by its
address-point `lea` over the whole executable: hkTypeInfoRegistry 0x16a60b0
(the name is the string at 0x14cc1f0 its creator FUN_00184e80 references at
0x184ef0, the singleton record: a fact, not a derived name; stored at
0x17d830, 0x17d85a, 0x184eb2 and 0x17ea81), hkDynamicClassNameRegistry
0x16a61f0 (derived: the base whose thirteen slots hkDefaultClassNameRegistry's
0x16a6170 shares; stored at 0x17ec10, 0x17ec3a, 0x184f72 and 0x17e9db, the
last two overwritten by 0x16a6170 at 0x184f94 and 0x17e9fd), the XML reader's
nodes XmlEndElement 0x16a6a20 and XmlCharacters 0x16a6a60 (derived; stored by
their destructors and by the reader FUN_0019da90 at 0x19e1eb, 0x19e5de,
0x19e08c, 0x19e28b), hknpWorldObject6c0 0x16a4940 (derived; stored only at
0x1585db, built at 0x49a67 for hknpWorld's +0x6c0) and BufferOstream
0x168c3a0 (derived; stored at 0xdba, 0xe4a, 0xeb0, 0xf0f and 0xfc1, the
last two inside FUN_00000ee0, which the round's report did not list).
`tools/vtable_names.py --check`: 13 derived rows, 0 failing.

**Addendum, 2026-10-26 (round 25 harvest).** Two rows: Object00061f00
0x16997f0 (derived; stored only at 0x61f07 by its constructor, which the
game calls at 0xea9d11; slots 0x3b640, 0x4060, 0x270, 0x42d0, 0x69a0,
0x58a0, 0x61f40, 0x3b640, 0x1c1e0, 0x1c1e0) and OffsetOnlyStreamWriter
0x16a6af0 (derived; stored only at 0x19f677 by its constructor, called at
0x19ad01 and 0x19c76d on stack objects; twelve slots, 0x17de10, 0x1ba30,
0x270, 0x42d0, 0x69a0, 0x40b0, 0x19f6a0, 0x270, 0x40b0, 0x19f6d0, 0x34840,
0x1bad0; the round's report stopped at slot 9, and the relocated pointer
after slot 11 points at the string "name", the next object). `--check`: 15
derived rows, 0 failing.

**Addendum, 2026-10-26 (round 26 harvest).** Two rows: hknpSolverFactoryTask
0x16a4080 (derived from the timer string "Solve/SolverFactory" at 0x14c9a92
its slot 6 copies; a class with two vtables, the second for the task
interface at +0x10 with offset-to-top -16 at 0x16a40c8; both address points
formed from the vtable's start, `lea rax, [rip+V]; lea rcx, [rax+0x10]`
and `add rax, 0x58`, at 0x14e4b0, 0x14e4da, 0x14e7b0, 0x14e7da and 0x1515ed,
the last inside FUN_00151250, which builds the object inline at 0x1515a1)
and RefArrays 0x1698f40 (derived; the arrays object at +0x38 of that task;
stored at 0x92287 by its constructor and 0x4804e by its destructor). The
walker of `tools/vtable_names.py` did not follow `lea r2, [r1+imm]`, so
`_verify_derived` could not see the first row's store; it follows it now
(the regeneration under the fixed walker is recorded in docs/NOTES.md).
`--check`: 17 derived rows, 0 failing.

**Addendum, 2026-10-26 (round 27 harvest).** Two rows whose names are facts
though their vtables carry no type info: hkpWrappedConstraintData 0x169cee0
(the hkClass string at 0x14c05e8, loaded at 0x7e3a5 for the record 0x57c4308
whose parent argument is hkpConstraintData's record; thirty slots, 5 and 29
pure; stored at 0x7d55f, 0x7d52e, 0x7d48a, 0x67a9a, 0x3c10a, 0x3c17a,
0x679fa) and hkDummySingleton 0x168d2b0 (the singleton record's string at
0x14b3307, loaded at 0x9c50; six slots; stored only at 0x9c35 inside the
create function FUN_00009c20, which news the object and constructs it
inline). The second form needed the walker to count a store into the
pointer a call returns (`vptr_stores`, the `fresh` walk); `vptr_of`, which
names vtables through finish constructors (D12), keeps `this` alone, so the
regeneration is unchanged by it (recorded in docs/NOTES.md). `--check`: 19
derived rows, 0 failing.

**Addendum, 2026-10-26 (round 28 harvest).** Four rows: hknpPrepareExistingPairsTask
0x16a5c60 and hknpPrepareConstraintsTask 0x16a4640 (derived names after the
timer strings their slot 6 opens, "Collide/Prepare Existing Pairs" at
0x14cb100 and "Constraints/Prepare" at 0x14c9e70; both two-vtable task
classes stored only by their constructors at 0x179847 and 0x154ed7, which
FUN_00150330 calls at 0x150392 and 0x1504d5), hkStaticClassNameRegistry
0x16a63b0 (derived; the static object 0x57c8870 built at 0x17f09e over the
class list 0x16c9060 with version -1 and the name "hk_2014.2.0-r1" at
0x14b3b02; stored only at 0x181827) and hknpVehicleWheelCollide 0x169af50
(the name a fact: the hkClass string at 0x14bdd53 built into the record
0x57c1510 at 0x5b2a1; slots 5 to 10 pure; stored by the inline finish
constructors FUN_00070750 and FUN_00075f60 before their derived vtables).
`--check`: 23 derived rows, 0 failing.

**Addendum, 2026-10-26 (round 29 harvest).** Two rows: hknpCharacterStateInAir
0x1693610 (derived; the game builds the object at 0xea9c91 and registers it
as state 2; stored only at 0x365a7 by its constructor) and FixedSizeAllocator
0x168e5b0 (derived; thirteen slots; stored at 0x14a59 by its destructor and
inline by the constructions in FUN_00001960 and FUN_00001fb0 at 0x19a9 and
0x2192). `--check`: 25 derived rows, 0 failing. Collected, not yet a row:
hkSerializeDeprecated 0x16a6860, whose name is a fact (the singleton
record's string at 0x14cca08, loaded at 0x19a680) and whose only store,
0x19a618 to 0x19a623, is into the static instance 0x57c8a08 inside the
create function 0x19a5f0: a form the walker does not count (neither `this`
nor a returned pointer); nothing claimed needs the row, and the walker
grows that form when one does.

**Addendum, 2026-10-27 (round 30 harvest).** One row: hkObjectCopier 0x16a75d0
(derived; stored only at 0x1a0847 by its constructor, called at 0x19a9dc and
0x19b49e; eight slots). `--check`: 26 derived rows, 0 failing.

**Addendum, 2026-10-27 (round 37 harvest).** A static instance built in
place by its initializer stores the vptr RIP-relative
(`mov [rip+instance], vptr`, the system allocator's at 0x4b3b, hkSerializeDeprecated's
at 0x19a618); `tools/vtable_names.py`'s walker now counts that store as
the initializer's, so `--check` verifies such a row and the generated file
lists the vtable. Rows added: hkArrayStreamWriter 0x16a32f0 (a fact: the
hkClass record 0x57c8750, its string at 0x14c3faf, which slot 3 returns),
hkMallocAllocator 0x168c9f0 (derived from the shape, the static instance
0x57b7b00), hkSerializeDeprecated 0x16a6860 (a fact: the singleton string
at 0x14cca08) and Class16969d0 0x16969d0 (derived; a 0x50-byte
reference-counted object only the game builds, 0xeaa611). Round 38's
harvest renamed that row hknpCharacterContext: its constructor's stores
are the character context's fields in Havok's order (the character type,
the state manager, current and previous state, filterEnable,
maxLinearAcceleration 625, maxLinearSpeed 20, gain 1, the previous surface
velocity, the update count), the name the header already used; and added
hknpWorld 0x1699220 (derived after the home file hknpWorld.cpp at
0x14bda42 and the reflected hknpWorldCinfo and hknpWorldSnapshot; stored
by the constructor FUN_00048b20 at 0x48b51 and the destructor
FUN_0004b040 at 0x4b062).
Round 39's harvest added hkBufferedStreamWriter 0x168d210 (a fact: the
hkClass 0x57b7fe8 its slot 3 returns, the string at 0x14b32c7),
Elements000768c0 0x169b400, Object00006800 0x168caf0 and Object00199ec0
0x16a67e0 (derived, named after their constructor, create function and
initializer; the last a static instance stored RIP-relative at 0x199ed1).
Round 45's harvest corrected round 44's naming of 0x1699510: it is the
kind-1 splitter (FlaggedPoints00060c70, the nearest of up to 16 flagged
points), not the grid, and added DirectoryIterator0001bc80 0x168eb00
(anonymous namespace, the bare-lea form), hkDefaultClassNameRegistry
0x16a6170 (a fact: the singleton string 0x14cc203),
hknpCharacterStateManager 0x1692eb0 (the header's derived name; eleven
state pointers) and Object00070900 0x169b100.
Round 46's harvest renamed Object00070900 hknpAllHitsCollector (a derived
name: the collector is 0x3f0 bytes, not reference-counted, with the hints
int at +8, the early-out vector at +0x10 and an hkInplaceArray of ten
0x60-byte hits at +0x20, hknpAllHitsCollector's shape; the row's first
comment had it reference-counted, which the worker's reading of 0x70900
corrected).
Round 47's harvest added PageAllocator 0x168e8e0 (derived: a page allocator
over hkReferencedObject, constructor 0x195c0, destructor 0x19780, no string),
hkLargeBlockAllocator 0x168e290 (a fact: its slot 19, 0x13060, names it by the
string at 0x14b4257; the class was LargeBlockAllocator, a derived name, and is
renamed with its rows; two bases, the second vtable at +0xc0 inside the one
`_ZTV` object, whose thunk 0x122f0 serves both of the second vtable's
destructor slots and is named the D1's by D15), hkpConstraintMotor 0x169c750
and hkpLimitedForceConstraintMotor 0x169c710 (facts: the strings at 0x14c00ae
and 0x14c1e56 their hkClass builders store; the vtables are stored only by
derived motors' clones, which build the bases in turn, so the citing function
is a clone, 0x7c100).
Round 48's harvest added BufferedStreamReader 0x16a35c0 (derived: a reader
over hkReferencedObject that buffers another stream, the header's name;
stored by its constructor 0x94170, called at 0x1a7f7 with a 0x4000-byte
buffer, and by its destructors 0x94230 and 0x942e0; no string) and the three
router allocators RouterAllocator50 0x168d430, RouterAllocator60 0x168d4b0
and RouterAllocator58 0x168d530 (derived from the router offset each slot 2
loads, 0x50 at 0xac76, 0x60 at 0xae06, 0x58 at 0xaf96; one static instance
each at 0x57b8470, 0x57b8478 and 0x57b8480, built in place by the one
initializer 0xb120, which forms the instance's address in a register
before the store, `lea rsi, [rip+instance]; mov [rsi], vptr`, because the
same register is the exit registration's argument; the verifier's walk
now reads that form as the static store it is, `tools/vtable_names.py`
`_walk`, measured over the whole table: no other row changed). The third
instance is D_57b8480, the containers' allocator, declared an AllocatorBase
in tlg_hk_reflect.h; its type is RouterAllocator58 by the store at 0xb18e,
and the declaration follows when 0xb120 is written (the class is declared
after the header that declares the object).
Round 49's harvest added TreeQuery00127a50 0x16a3df0 (derived; a class of
an anonymous namespace, the address point 0x16a3e00 stored by one bare lea
into a 0x30-byte object on the stack of the compressed mesh shape's slot 29,
0x127a50, and handed to the tree walk 0x104000, which calls its slots 2, 3
and 4 at 0x10454b, 0x10456f and 0x104a3f; slots 0, 1, 2 and 4 are folded
one-line bodies, slot 3 its work 0x127b20). The verifier's walk now takes a
store of an address point into the function's own frame (`mov [rbp-X],
vptr`) as the in-place construction of a local, so a function that builds
such an object is its citing function; over the whole table the rows,
conflicts and derived checks are unchanged (171, 0, 72 and 0 failing) and
the unnamed listing grew from 1,551 to 1,757 entries, the locals' vtables
now attributed to the functions that build them (the listing's header says
"stored by a function" for that reason).
Round 40's harvest renamed Object00006800 hkReferencedObjectLock (the
singleton string at 0x14b2c9c, a fact), added hkOstream 0x168d100 (the
string at 0x14b31e4) and hknpCompoundShape 0x1697900 (slot 3 returns its
hkClass, the string at 0x14bf746), both facts, and the derived rows
Object000ea540 0x16a3cc0, Object000ea380 0x16a3c90 (stored only by their
destructors), BroadPhaseCollideTask 0x16a66f0 (after its slot 3's format
string) and Object00185000 0x16a65d0. Object00199ec0's row is keyed by
`_ZTVN12_GLOBAL__N_114Object00199ec0E`: the base stores its address
point with one direct lea, the fold of a vtable with internal linkage,
so the class is in an anonymous namespace, and `BaseElf._verify_derived`
accepts that mangling of the row's class name; its initializer matches
under the file's own init symbol `_GLOBAL__I_a` (the row's symbol column).

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

**Addendum, 2026-10-26 (round 23 harvest).** 0x8c0a0 is one empty body
that the compiler folded for hkxVertexDescription's finish constructor
and for twelve empty vtable slots of other classes. The row is named
`_ZN20hkxVertexDescriptionC1E24hkFinishLoadedObjectFlag`, the constructor
hkxVertexBuffer's constructor must call on its desc member; a vtable row
that cites the address resolves by address, so the slots keep matching
under the constructor's name. The same rule as for the C1/C2 pair: one
name per address, the name a caller needs by symbol wins, every other
reference resolves by address.

**Addendum, 2026-10-27 (round 31 harvest).** The same rule names a shared
deleting destructor. A class whose destructor is empty and whose storage
is a fixed-size block on the thread's heap gets a deleting destructor of
one shape, `if (this) free(this, size)` through the thread-local memory
router (0xd900 for 8-byte classes, 0x13e50 for 16, 0x6c810 for 32), and
the executable holds one body per size: 16 vtables with six different
slot-0 destructors cite 0xd900 at slot 1, 11 cite 0x13e50, two cite
0x6c810, 0xcf880 and 0x10b050 (the data region scanned for every pointer
to each body). Identical bodies of different classes are one address only
through the linker's folding, so the body is one function and gets one
name: the class whose other members sit beside it (0xd900 between
StackTracer's constructor 0xd8f0 and destructor 0xd940, 0x13e50 in the
runner's file), `_ZN11StackTracerD0Ev`, `_ZN14Runner00016350D0Ev`; every
other vtable's slot 1 resolves by address.

**Addendum, 2026-10-27 (round 35 harvest).** When no citing class has
other members beside the body, the body is named after the citing vtable
of lowest address. Measured over the shared deleting destructors named
so far (the supervisor entry after Round 35 in docs/NOTES.md): in every
case where a class sits beside the body and the lowest-address citing
vtable is a named one, the two rules agree (StackTracer, hkUuidObject,
hknpCharacterRigidBodyCinfo, hknpGroupCollisionFilter,
hkpVehicleFrictionDescription, hkpCogWheelConstraintData,
hkpVelocityConstraintMotor, hkpBallAndSocketConstraintData,
hkpRagdollLimitsData, hkxCamera, hknpCharacterStateInAir: 11 of 11), as
the linker keeps the first copy of a folded body in link order and lays
the vtables out in the same order. Round 35 named 0x1ba80 and 0x383f0 by
a rule of the worker's (the first citing class the headers already size);
their lowest-address citers are hknpRefMassDistribution (0x169a820) and
hknpShapeMassProperties (0x1693ef0), and round 36 renames them.
The fallback is a fallback: round 36's thunk 0x48890, shared by three
task classes one function builds (0x48b20, one translation unit), sits
beside hknpPreSolveTask's slots and is named for it, while its
lowest-address citer is hknpPostSolveTask's vtable; inside one
translation unit the vtables' order says nothing about which copy the
linker kept, so the class beside the body governs whenever there is one.

**Addendum, 2026-10-29 (round 49 harvest).** A code reference to a folded
destructor resolves through the class's vtable. The static initializer
0xb120 builds the three router allocators in place and registers each
class's complete destructor with `__cxa_atexit`; the base registers 0x4ac0
for all three, the one empty body the linker kept, whose row is
`_ZN17hkMallocAllocatorD1Ev`. The compile names `_ZN17RouterAllocator50D1Ev`
and the other two, which no row can name (one name per address). Each
class's vtable, a ruled row (D14), holds that body in its slot 0: the
executable's own statement that the class's complete destructor is 0x4ac0.
`tools/base_elf.py` `folded_destructor` therefore resolves a destructor
symbol no row names by its class's primary vtable: slot 0 for D1 and D2,
slot 1 for D0, when the vtable is one the executable names or a ruled
derived row and the body in the slot already carries a class's name. A
slot pointing at a FUN_ row is refused, so a body is named when it is
claimed and never through a fold. The resolver runs after the row names
and D15's alias, so no existing row's resolution changes; the gate held
on every row (the commit's hook). 0xb120 is claimed over it.

## D16. A statement the bytes prove but do not spell: the release-null assert (2026-10-26)

**Decision.** Where the base keeps a destructor's vptr store and emits
nothing else, the source body holds one statement that compiles to nothing,
written as the library's own release assert: `HK_ASSERT(0, <condition>)`
with the macro defined in our headers as Havok's release expansion, a null
statement (`((void)0)`), the id 0 because the original id is not in the
executable, and the condition an invariant the recovered data model
supports, named in a comment and marked `/* derived assert */`. It is
permitted only where the bytes demand a non-empty body; nowhere else, and
never to move code.

**Why.** LLVM 3.3 skips a destructor's vptr store only when the
destructor's body is trivial and every field's destructor body is trivial
(`CGClass.cpp:1224` `CanSkipVTablePointerInitialization`,
`HasTrivialDestructorBody`); the worker confirmed on 2026-10-26 that a
field whose destructor is `{}` still skips, and that any statement, even
`;`, keeps the store. So where the base stores the vptr and returns, the
original destructor (or a member's) contained a statement that emitted no
code. Measured over the library region: of 81 fifteen-byte functions that
only store a vptr and return, 79 are finish constructors (a constructor
always stores) and 2 are base destructors in slot 0 of the vtable they
store (0x47cb0 hkSlot, 0x90450 the command writer whose member at +0x10 is
a block-stream writer). The statement is unrecoverable; Havok's destructors
assert their invariants with `HK_ASSERT`, whose release form is a null
statement, so an assert is the developer-native representative and is
written as derived. A null statement `;` or an invented empty call would
be a crutch: it exists only to steer. The assert states something the
model says is true at destruction (the writer was finalized, the slot was
unsubscribed), which is what the developer asserted.

**Trigger to revisit.** An executable string or a public Havok header of
the same version that spells the statement (then it is a fact and replaces
the derived assert), or a third destructor of this shape whose model yields
no invariant to assert.

## D17. A file-local object is resolved through the object's own symbol table (2026-10-26)

**Decision.** A relocation in a compiled object against a section symbol
(`.rodata + offset`, `.bss + offset`, `.text + offset`) is attributed to the
named local symbol of that section whose extent holds the target offset,
and is then a relocation against that symbol with the addend reduced by the
symbol's value: `tools/match_check.py` (`named_locals`, `reloc_symbol`) does
this when it reads an object, for the functions' relocations and, through
`tools/layout_link.py`, for the data objects'. The target offset of a
PC-relative field is its addend plus the distance from the field to the end
of its instruction, which `field_tails` reads from one disassembly of the
function (a `lea` has 4, a `cmp dword [rip+x], imm32` has 8); an absolute
field or a data slot adds nothing. A relocation no named local covers (a
string literal in `.rodata.str1.1`, a constant-pool entry) keeps its
section's name and is placed by its bytes as before. The object is spelled
as the developer spelled it, with internal linkage (`static`, an anonymous
namespace, or a namespace-scope `const`), and named `D_<hex>` until a fact
names it; the mangled form `_ZL<n>D_<hex>` is the same identifier to
`BaseElf.base_identifier`, so the address comes from the name as for any
`D_<hex>`. A `.bss` object needs no claim for its references to resolve; an
initialised one is claimed in `config/data.base.txt` so its bytes are
checked (D8), with its content under D18.

**Why.** Which linkage a data reference has is in the bytes. Under PIC with
default visibility (the region has GOT loads for its own defined symbols,
D10), the compiler reaches an external object through the GOT and only an
object local to the translation unit by a direct RIP-relative operand: the
linker's relaxation (D10) turns the 8B `mov` form of a GOT load into `lea`
and nothing else, so a `lea` whose extern compile gives a folded GOT load
(`add rcx, [rip+D@GOTPCREL]` for the member type table at 0x16dc150, read by
0x7d40), a store (`movaps [rip+D], xmm0` to the tolerance at 0x57c8990 by
the initializer 0x188540) or any other direct memory operand on a data
address is a reference the compiler emitted for an internal-linkage object.
Before this ruling the resolver searched the base for the object's bytes
(zeros, or unrelocated pointers), which cannot place it. 888 library
functions hold a direct RIP-relative data operand that is not a `lea` and
not the relaxable `mov` (constant pools and file-local objects alike; 883
unclaimed), and 1,205 more a `lea` to data. The scratch claim of 0x7d40 with
the table defined `static` in its TU (a zero table of the record's size
for the test; the real one has 36 rows of 24 bytes, 864 bytes) compared equal with its relocation verified and laid out
every segment identical to the base.

**Trigger to revisit.** A named local whose extent does not hold the field's
target (an attribution the gate then fails as a wrong address), or a
compiler whose section relocations carry a different addend convention.

## D18. A table's content is generated at build time from the user's executable (2026-10-26)

**Decision.** A data object whose bytes carry content from the package, a
table of records or of pointers, or any object holding a string pointer, is
committed as its type, its count and its name only. Its row of
`config/data.base.txt` (`D_<hex> <tu> [<symbol>]`, D8) is joined by a row of
`config/data_schema.base.txt` (`D_<hex> <record type> <count> <header>`),
the record type a struct in `src/include/` whose fields are typed from the
bytes; `tools/gen_data_inc.py` writes the initializer at build time from the
user's own `baserom/base/eboot.elf` into `build/base/gen/D_<hex>.inc`, and
the owning translation unit includes that file between the braces of the
definition (the object stays in the TU that reads it, D17). A pointer slot
is written as what the base's RELATIVE relocation resolves to: a string
literal when the target is a NUL-terminated string, the name of a function
of the table, a `D_<hex>`, a vtable's address point; an integer or a float
by its field's type, decimal, floats as the shortest text that reads back to
the same bits. Nothing generated is committed (`build/` is ignored, and
`tools/check_no_rom.sh` keeps it so); the gate's data-claim path (D8) checks
the compiled object's bytes and every pointer slot against the base. A
scalar or a vector of a few literal constants the function itself uses (an
epsilon, a mask) is written by hand as the literal it is. The tool is
modelled on the sibling project's `tools/gen_data_c.py` and
`config/data_schema.*.txt`, which write every data-only member of that
executable this way.

**Why.** `docs/LEGAL.md` forbids a string or identifier table copied into
the repository in whole or in bulk and promises that data ranges are
generated at build time from the user's executable, with only types, counts
and names committed. The first case is the member type table at 0x16dc150:
36 rows of 24 bytes (`u8 type; const char *name; s16 size; s16 align`,
the last row TYPE_MAX), their 36 pointers relocated into the type-name pool
from 0x14b2fa6
("void", "hkBool", "hkChar", ...), read by 0x7d40, which cannot be claimed
until the table is defined in its TU. The executable has 29,118 RELATIVE
slots, 4,761 of them pointing at printable NUL-terminated strings and 21,367
at functions, so string and function tables are the shape most of the data
segments' content takes. Writing the 35 names by hand would be a table
copied verbatim; generating them keeps the repository's contribution to the
developer's type and count, which is what it knows.

**Trigger to revisit.** A table whose record type the generator cannot
express (bit-fields, unions, a pointer into the middle of an object), which
is a schema extension, not a hand-written table.

**Addendum, 2026-10-26 (round 20).** Landed as `tools/gen_data_inc.py`,
`config/data_schema.base.txt`, a `gen_data` ninja edge per schema row and
`-I build/base` for the compile (match_check regenerates a TU's tables
before compiling it outside ninja). The first claim is D_16dc150 with
FUN_00007d40 (36 rows: the bytes hold a TYPE_MAX row this ruling's first
text did not count). A slot holding a vtable's address point stops the
generator rather than being spelled: such an object is an instance of a
class with a constructor, written as that object in C++, not a table row.

## D19. Havok's kept check stops on `HK_BREAKPOINT`, spelled as the debug trap (2026-10-26)

**Decision.** A check the release library keeps, which traps and goes on,
is spelled `HK_BREAKPOINT(id)`, defined once in `src/include/tlg_hk_reflect.h`
as `__builtin_debugtrap()`, which LLVM 3.3 lowers to `int3`
(`tools/cc/src/llvm-3.3.src/lib/Target/X86/X86InstrSystem.td:37`). It is a
different thing from the release-null `HK_ASSERT` (D16): that one compiles to
nothing and stands only where a body must be non-empty; this one is the
bytes. Inline `asm("int3")` would emit the same byte but spells a builtin
as assembly, and `__builtin_trap()` emits `ud2`, not the bytes.

**Why.** The library region holds 214 `int3` instructions in 137 functions:
92 reached through a conditional branch (the kept checks: a range check on
an enum index in hknpModifierManager's table setters 0x66770 and 0x66790,
matched with this spelling, cookbook 29), 122 after a call, jump or return
and never reached (fill inside an unwind range), none in the game region. A
spelling that varied per function would be a per-function choice of the
same mechanism; the macro names the mechanism once.

**Trigger to revisit.** A conditional `int3` whose surrounding code the
builtin's lowering cannot produce (the builtin is a scheduling barrier only
as far as `ISD::DEBUGTRAP` is), which would be a classified note first.

## D20. Both regions were built with the strong stack protector (2026-10-26)

**Decision.** The stack protector level of both regions is strong:
`-fstack-protector-strong`, the Orbis driver default Sony's 2013 toolchain
talk lists (docs/TARGETS.md). The game prefix passes it now (4.0.0 has the
flag; the gate does not move: the twelve game rows have no address-taken
local). The library prefix cannot yet: the prebuilt 3.3 frontend knows
`-fstack-protector` (ssp) and `-fstack-protector-all` (sspreq) and nothing
between, while its backend already implements `sspstrong`
(`tools/cc/src/llvm-3.3.src/lib/CodeGen/StackProtector.cpp:193`). Under D2's
rule for compiler changes, the library compiler becomes a from-source 3.3
build (`tools/build_llvm.sh 3.3`, verified byte-identical to the prebuilt on
the probe and on `src/libs/`) carrying one backport patch, the
`-fstack-protector-strong` frontend support that reached upstream in clang
3.5 (the code as it stands in `tools/cc/src/llvm-3.6.2.src/tools/clang`:
`Options.td` `fstack_protector_strong`, `Driver/Tools.cpp`,
`Frontend/CompilerInvocation.cpp` level 2, `Basic/LangOptions`,
`CodeGen/CodeGenModule.cpp` `StackProtectStrong`,
`Frontend/InitPreprocessor.cpp` `__SSP_STRONG__`), and the library prefix
then passes `-fstack-protector-strong` under `cxx=3.3-src`. Until that build
verifies, the library prefix keeps `-fstack-protector`, and a
canary-bearing library function is not claimable.

**Why.** The old count (394 library and 80 game functions loading the
canary, `config/flags.base.txt`, docs/TARGETS.md) came from an instruction
shape in `tools/fingerprint.py` (guard load, deref, store to `[rbp-N]`,
adjacent) that the scheduler and the frame layout break; counting the
symbols instead (a load of `__stack_chk_guard`'s GOT slot 0x16d80c0 or a
call of `__stack_chk_fail`'s stub 0x14b1dc8, both give the same functions)
finds 745 of 3,391 library functions and 5,980 of 16,344 game functions.
The level follows from which functions those are. Under ssp LLVM 3.3
protects only a function holding a char array of 8 bytes or more
(`StackProtector.cpp` `ContainsProtectableArray`); under strong, any array
and any local whose address is taken. In the library region 724 functions
take a local's address (`lea r, [rsp+n]` or `[rbp-n]`) and call something;
722 of those carry the canary, 2 do not (0x18c90, 0x8f330), and 29 carry it
without such a `lea` (arrays indexed without one). The game region: 5,688
address-taking functions, 51 without the canary. That is the strong
heuristic's footprint, not ssp's; a game region built with the protector
off would show none. FUN_00187750 (0xdec bytes, round 20) is the first
canary-bearing library function worked: round 20's model of its source has
it taking the address of a Vec4 array and two matrices, locals strong
protects and ssp does not (a reading of the function, not a measurement);
its frame, measured, is 0x1c8 against the 0x198 our compile makes.

**Trigger to revisit.** The from-source 3.3 build failing to verify
byte-identical to the prebuilt, or the patched build regressing the gate on
a claimed library function, either of which reopens the level or the
backport.

**Addendum (2026-10-26, round 21): the build verified and the prefix
switched.** `tools/build_llvm.sh 3.3` fetches llvm-3.3.src.tar.gz (SHA-256
68766b1e70d05a25e2f502e997a3cb3937187a3296595cf6e0977d5cd6727578) and
cfe-3.3.src.tar.gz
(b1b55de4ab3a57d3e0331a83e0284610191c77d924e3446498d9113d08dfb996), both
release signatures good (Bill Wendling, key C135 49BB 82A1 7681 BF71 43C2
B446 8DF4 E95C 63DC, checked again by the supervisor), builds them with GCC
14 under `-std=gnu++98 -fno-lifetime-dse -fno-delete-null-pointer-checks`
(the last keeps the `this == 0` tests of `Value::print` and `Type::print`,
`lib/IR/AsmWriter.cpp:2182` and `:2198`, which `-print-after-all` relies on)
and one host patch (`utils/llvm-build` to Python 3), and installs the driver
as a file, as the release does. `--verify` compiles every probe TU and every
`src/libs/` TU with the prebuilt 3.3 and the built one under the library
flags and finds every object identical in disassembly, relocations and
bytes: 735 TUs on 2026-10-26, run by the worker three times (pristine, with
the backport, after the third host flag) and once more by the supervisor
(`tools/build_llvm.sh 3.3 --verify`, exit 0). The backport
(`tools/patches/llvm-3.3-sspstrong-01-fstack-protector-strong.patch`)
touches six clang files (`Options.td`, `LangOptions.h`, `Driver/Tools.cpp`,
`CompilerInvocation.cpp`, `CodeGenModule.cpp`, `InitPreprocessor.cpp`),
numbers the levels as clang 3.5 does (1 ssp, 2 strong, 3 all) and changes no
object without the flag (the same verification, run with the patch applied
and `-fstack-protector` in place of the strong flag). The library prefix
reads `cxx=3.3-src ... -fstack-protector-strong`; the gate did not move (706
rows at the switch, 745 at the end of the round). Of the 720 library objects
then built, one references `__stack_chk_guard` and `__stack_chk_fail`
(`func_00188540.cpp.o`, FUN_00187750), and its canary sequence equals the
base's: on the claimed set the strong level puts a canary exactly where the
base has one. `tools/fingerprint.py --obj` counted that object's canary as 0
until the supervisor's fix (it compared a relocation's offset, the field at
+3, with instruction addresses); it reports 1 now. `tools/setup.sh` builds
the from-source 3.3 after fetching the prebuilt, and `build.sh` requires it.

**Addendum, 2026-10-27 (round 32 harvest).** The from-source build now
carries a second backport, D26's nop after the stack check's failure
call; `tools/build_llvm.sh 3.3` applies both and its stamp records the
set. Round 33's harvest added the third, D27's single store merge per
visit; round 34's the fourth, D28's jump tables inside the function;
round 42's the fifth, D29's BEXTR combine.

## D21. The library region stays at -O2; FUN_00187750's loop unswitch is an open level question (2026-10-26)

**Question.** FUN_00187750 (0xdec bytes, `src/libs/unknown/func_00188540.cpp`)
holds two copies of its main loop, at 0x187aa9 with the inner block search
and at 0x18806e without it: the shape of LLVM's non-trivial loop unswitch on
the search's guard, which is defined before the loop. LLVM 3.3 builds the
pass with OptimizeForSize below -O3
(`lib/Transforms/IPO/PassManagerBuilder.cpp:189`,
`createLoopUnswitchPass(SizeLevel || OptLevel < 3)`), and
`UnswitchIfProfitable` (`lib/Transforms/Scalar/LoopUnswitch.cpp:651`) then
refuses every non-trivial condition. So the base's shape is -O3's, the
developer's own two loops, or a compiler that unswitches at -O2.

**Measurements (2026-10-26, supervisor).**

- The claimed set does not tell the levels apart. With the library line at
  -O3 (3.3-src, nothing else changed) every one of the 745 claimed rows still
  matches and the gate passes; the three probe TUs compile to byte-identical
  objects at -O2 and -O3. FUN_00187750 at -O3 is 3,535 bytes against the
  base's 3,564 (2,311 at -O2) with 27 of 714 instructions aligned (46 at
  -O2): the duplication is reproduced, the function is not.
- -O3 in 3.3 also adds ArgumentPromotion (`PassManagerBuilder.cpp:167`), the
  loop vectorizer (`:195`; clang 3.3's driver passes `-vectorize-loops` by
  default, `lib/Driver/Tools.cpp:3314`) and the inliner threshold 275 in
  place of 225 (`clang/lib/CodeGen/BackendUtil.cpp:281`). The vectorizer
  leaves a fingerprint the region lacks: under `-march=btver2` it works in
  256-bit ymm registers, and the library region's 1,068 ymm instructions are
  all moves and zeroing (vmovaps 604, vxorps 334, vinsertf128 69, vmovapd
  37, vxorpd 24: memcpy and memset lowering and aggregate copies), not one
  ymm arithmetic instruction in 3,391 functions. The game region, whose
  4.0.0 runs the vectorizer at -O2, holds 1,471 `vmulps ymm` and 388
  `vaddps ymm`.
- The inliner threshold and ArgumentPromotion leave nothing measurable in
  the claimed functions (too small to cross either).

**Ruling.** The library line stays `-O2`. A plain -O3 would have to find
no vectorizable loop in 3,391 Havok functions, which the census argues
against; `-O3 -fno-vectorize` is not excluded by anything measured, and one
function's shape does not change a region's flags (D2, D6). FUN_00187750 is
not claimable and is not worked by a round's worker until the question is
settled; the supervisor runs every level experiment. What settles it:
(a) a second library function whose base shape -O2 cannot produce and -O3
(with or without `-fno-vectorize`) does, with the whole gate and both
functions matching at that level, which switches the line and records the
fingerprint here; or (b) a source for FUN_00187750 that matches at -O2 (the
two loops as the developer wrote them), which closes the question in
-O2's favour.

**Trigger to revisit.** (a) or (b) above, or a vectorized loop found in the
library region (ymm arithmetic, or the vectorizer's runtime checks), which
would reopen the vectorizer half of the census.

**Addendum, 2026-10-28 (round 41 harvest).** The pre-RA scheduler is
3.3's own: the ILP list scheduler, which the x86-64 target selects
(`lib/Target/X86/X86ISelLowering.cpp:201-202`, `Sched::ILP` for 64-bit;
`SelectionDAGISel.cpp:241`, createDefaultScheduler). Round
41 left FUN_00184e20 (the AABB's conversion to sortable integers) equal
except for the order of its last instructions, and measured that the
source-order scheduler (`-pre-RA-sched=source`) gives the base's 18
instructions exactly; the supervisor ran the library line with
`-mllvm -pre-RA-sched=source` between rounds (flags backed up and
restored, `schedexp.log`): the function matches, and `gate-all` fails on
253 of the 1,452 rows (1,199 equal, five of them also with a different
size). The ILP scheduler stays; 0x184e20 is classified (a single witness
against 1,199) and leaves the queues until a source whose DAG the ILP
scheduler orders as the base does is derived.

**Addendum, 2026-10-28 (round 46 harvest).** A witness for the level
question, collected and not ruled on: 0x33990,
hknpCompoundShapeInternalsKeyMask's deleting destructor (254 bytes), has
the 187-byte destructor body (0x338d0, matched as the class's D1 in round
46) inlined and tests the object for null before freeing 0x30 bytes. The
fixed line calls the body and frees through hknpShapeKeyMask's untested
delete, as the compressed mesh mask's matched 0x34a00 does. The inliner's
threshold is 225 at -O2 and 275 at -O3 (3.3's
`tools/clang/lib/CodeGen/BackendUtil.cpp:276-283`), raised to 325 for a
callee with the inline hint (`lib/Transforms/IPO/Inliner.cpp:50,252-255`);
no level was compiled. Two readings stay open: the level (to be measured
over the region as the source scheduler was above, never per function) and
the source (a class-specific operator delete of the compound mask's own
that tests its argument, which changes the deleting destructor's shape and
the inline cost both). Classified with 0x187750 and 0x184e20 until a second
witness or a source reading.

**Addendum, 2026-10-29 (round 49 harvest).** The second witness arrived
(0x41650, hknpCompoundShape's destructor: the free-list array's destructor
and hkArray::clearAndDeallocate are inlined in the base, and the worker's
scratch diagnostic inlines them only from a threshold of 275), so the level
was measured over the region as the ruling requires: the library line with
-O3 in place of -O2, flags backed up and restored, every claimed row
(`o3exp_O3.log`). Seven of 1,762 rows differ at -O3 (0x14640, 0x27240,
0x2b670, 0x310f0, 0x904f0, 0x17a360, 0x18e380, three of them with no
instruction in common with the base), and 0x33990 does not match at -O3
either. -O3 is refuted; the level is -O2. The witnesses' mechanism is the
other threshold: 3.3 raises the inliner's threshold from 225 to 325 for a
callee carrying the inline hint (`lib/Transforms/IPO/Inliner.cpp:249-255`),
and clang 3.3 gives the hint only when the `inline` keyword appears
explicitly on some declaration of the function
(`tools/clang/lib/CodeGen/CodeGenFunction.cpp:497-504`,
`isInlineSpecified`): a function defined in its class body gets none. The
witnesses are therefore a source question in the method's own terms: the
callee the base inlines was declared `inline` in the original source, and
the tree writes the keyword where the bytes prove the hint (0x33990's
class destructor, defined in the deleting destructor's own translation
unit; 0x41650's free-list destructor), never a flag. Both leave the
classified set and return to the queue with that lead; 0x187750 stays
parked (its shape is the unswitch, not the inliner).

## D22. The library region holds a second compiler generation in two stretches; its functions are not claimable under the 3.3 prefix (2026-10-26)

**Finding.** Two instruction-selection habits separate LLVM 3.3 from 3.4 and
later, measured on `tools/probe/batch*.cpp` under every prebuilt release
(3.3: `movsxd rax, eax` 6, `cdqe` 0, 8-bit zeros as `xor r8, r8`; 3.4,
3.5.2, 3.6.2, 3.7.1, 3.8.1, 3.9.1, 4.0.0: `cdqe` 6, `movsxd rax, eax` 0, no
8-bit zero idiom: `lib/Target/X86/X86InstrCompiler.td` selects `MOV8r0` for
an 8-bit zero in 3.3 and `(EXTRACT_SUBREG (MOV32r0), sub_8bit)` from 3.4).
`tools/generation_census.py` gives every library function a vote by those
marks (421 old, 20 new, 2,950 with no mark) and finds the votes in
stretches: old from 0x1770, new from 0xafaa0 to 0xc68d0 (73 functions,
every voter new), old to 0x18adc0, new for FUN_0018adc0 (0x11bc bytes,
two `cdqe`), old from 0x18ce30 to the region's end. No function votes both
ways. `tools/fingerprint.py --range 0xafaa0:0xc68d0` agrees: 77 `cdqe`, no
`movsxd rax, eax`, against 1 and 46 in the 0x90000 to 0xb0000 stretch
before it. The first stretch is Havok's geometry processing: its functions
cite `hkgpConvexHull::buildIndices` and
`Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHullInternals.h`
from FUN_000af620 on (the two unvoted functions 0xaeb20 and 0xaed70 before
it cite neither), and one cites a header under
`C:\Work\P4\depot\Release\2014_2\2014_2_0_Release\Source\`, where the
old stretches cite `Y:\NightlyJobs\20141121-01\Source\` (Havok's nightly of
2014-11-21) and relative paths. Two Havok builds, two compilers. The new
stretch also shows the strong protector (41 of 73 functions load the
canary) and none of the 3.7 and later marks the game region has (no merged
constant stores, no `ud2` after a noreturn call, no `int 0x41`), so its
compiler is of the 3.4 to 3.6 generation; which release is a probe question
(D2's method, a batch written from the stretch under every prebuilt
release with the library flags), not settled here.

**Why it matters.** FUN_000bc7d0 (0xbc7d0, in the stretch) zeroes a bool
with `xor eax, eax` after two EFLAGS readers, which 3.3 never does and 3.4
does (the prebuilt 3.4 compiles the same source to that shape); round 22
read it as a second instance of a 3.3 residual. Six matched rows lie in the
stretch (FUN_000b6bf0, FUN_000b6d00, FUN_000b6d10, FUN_000b6d20,
FUN_000b8a80, FUN_000c0af0, 4 to 11 bytes each): bodies every release
compiles alike, so the gate holds, but they sit under the wrong compiler.

**Ruling.** The stretches [0xaf620, 0xc68d0) and [0x18adc0, 0x18bf80)
(the second's end is open to 0x18ce10: FUN_0018bf80 and FUN_0018c930 carry
no mark) are the library region's second generation. A function in them is
not claimable under `src/libs/` and is left out of the queue until a
ruling names the stretch's compiler and prefix (a third flags line,
`cxx=<release>`, over a directory of its own); the six matched rows then
move to that prefix and must still match. The boundary functions without a
mark (0xaeb20, 0xaed70, 0x18bf80, 0x18c930) are decided when first
matched: whichever prefix compiles them to the base's bytes, recorded here.
D6's two-region statement is read with this exception.

**Trigger to revisit.** The probe naming the stretch's release (then this
entry records it and the prefix), a function in a stretch matching under the
other generation's compiler, or a new mark that splits the votes.


**Addendum, 2026-10-26 (round 25 harvest): a third stretch, [0x1a3a70,
0x1a3e00).** FUN_001a3a80 (29 bytes, the texture container's
size-and-alignment helper the game's loader calls at 0xbd9689 and 0xbda877)
compiles to the same nine instructions under every release, in the base's
order only under a compiler with the btver2 machine model and the default
pre-RA scheduler: measured by the supervisor over the releases on disk,
under the library line, 3.3 (prebuilt and from source), 3.4, 3.4.2 and
3.5.2 differ (4/9 and 3/9 instructions in place), 3.6.2, 3.7.1, 3.8.1,
3.9.1 and 4.0.0 are byte-equal; 3.6.2 with `-march=btver1`, `x86-64`,
`bdver1` or `core2` differs; 4.0.0 is byte-equal with the PS4 target and
differs the moment the game line's `-mllvm -pre-RA-sched=list-ilp` is
added, under either target. The census has no mark in [0x1a3510+0xae,
0x1a3e00); the functions from 0x1a3ac0 to 0x1a3c50 carry Sony's GNM error
code 0x80d30000 (at 0x1a3ac0, 0x1a3b60, 0x1a3bb0, 0x1a3c00, 0x1a3c71,
0x1a3cc6, 0x1a3d9d) and 0x1a3c50 calls 0x1a6f10 to 0x1a7120 in the game
region. Reading: Sony's texture-container helpers, built by a 3.6-or-later
compiler with its default scheduler (neither the library line nor the game
line). The stretch joins the two above: not claimable under `src/libs/`,
left out of the queue until a ruling names its compiler and prefix.
FUN_001a3a70 (11 bytes, matched, alike under every release) stays as the
six tiny rows do. FUN_001a3a80 keeps its NONMATCHING note.

## D23. The linker's TLS relaxation (general dynamic to initial exec) is reproduced in the gate (2026-10-26)

**Decision.** The 16-byte general-dynamic sequence both compilers emit for a
thread-local under `-fPIC` (`data16 lea rdi, [rip+x@tlsgd]; data16 data16
rex.W call __tls_get_addr`, relocations R_X86_64_TLSGD and R_X86_64_PLT32)
is compared and laid out as the initial-exec form the linker made of it in
the same 16 bytes: `mov rax, fs:[0]; add rax, [rip+x@gottpoff]`, the GD to
IE code transition of the x86-64 psABI (the "Thread-Local Storage" chapter,
"GD to IE"; lld's `X86_64::relaxTlsGdToIe` in lld/ELF/Arch/X86_64.cpp
writes these bytes).
`tools/match_check.py` `relax_tls_gd` rewrites the bytes before
disassembling and replaces the two relocations by one GOTTPOFF relocation
on the add's displacement; `verify_targets` and `tools/layout_link.py`
resolve it to the base's GOT slot that holds the variable's thread-pointer
offset (`BaseElf.tls_got_slot`: the variable's offset in the PT_TLS
template minus the template's aligned size, found by value among the
unrelocated slots of the GOT, exactly one slot or an error). A wrong
variable fails the target check (tested: D_16dc068 against the base's
0xbb40 reports the slot mismatch). A TLSGD relocation on any other
instruction form is left as it is and does not match.

**Why.** There is no source form that makes the compiler emit the
initial-exec access short of `-ftls-model=initial-exec` or a per-variable
`tls_model` attribute, and the attribute is a crutch; the flag is not in
the region's line and would be a guess at a build setting the relaxation
makes invisible. The executable, measured whole on 2026-10-26 over the
disassembly of every loaded segment: no `__tls_get_addr` import, PLT stub
or call; no `data16 lea` left anywhere; 21,974 `mov rax, fs:[0]; add rax,
[rip+X]` pairs (984 below 0x1a3e00, 20,990 above, all through `rax`, the
register the transition fixes), every one of whose targets is one of the 15
GOT slots without a dynamic relocation that hold a small negative value
(0x16d80b8 to 0x16d8170); PT_TLS is 0x70 bytes at 0x16dc060 (4 initialised),
align 8, so those values are the thread-pointer offsets of 15 thread-locals
(-0x70 to -8; the slot for 0x16dc070 holds -0x60, as the first claim
needs). The linker therefore relaxed every general-dynamic access, which
GNU ld and lld do for an executable (the variable's offset is known at link
time). The first function to need it: FUN_0000bb40, the memory system's
"this thread's router" store (`D_16dc070 = router;`, 25 bytes, everything
outside the 16 bytes already equal).

**Trigger to revisit.** A TLS access in the base in another form (a
local-exec `mov rax, fs:[0]; lea rax, [rax-N]`, or an access through a
register other than `rax`), which none of the 21,974 is; or a GOT slot
value shared by two thread-locals, which `tls_got_slot` reports as an
error rather than guessing.

## D24. The library line honours no NaNs and no longer wraps signed overflow (2026-10-26)

**Decision.** `src/libs/` compiles with `-fno-honor-nans` and without
`-fwrapv`; `src/game/` loses `-fwrapv` too. Both lines keep every other
flag. `-fno-honor-nans` is the narrowest flag that explains the evidence;
`-ffinite-math-only` and `-ffast-math` are not ruled out by the gate and
wait for a function that needs what they add (infinities folded,
reassociation, reciprocals).

**Why.** Two residuals of round 28 are flag shapes, and each was measured
over the whole executable and through the whole gate before the line
changed.

*NaNs.* 0x7c350 (hkpBallAndSocketConstraintData's runtime info, 42 bytes)
tests `breachImpulse != HK_REAL_MAX` with one `je` after `vucomiss`, the
lowering of an ordered compare; `!=` compiles to the unordered one, `jne;
jnp`. The disassembly of the library region's 3.3 part holds 121 float
equality tests (`ucomiss`/`comiss` followed by `je`, `jne`, `sete`, `setne`,
`cmove` or `cmovne`) and not one parity branch (`jp`, `jnp`, `setp`, `setnp`:
19 hits, every one inside data, none in a function); the D22 stretches 14
and 0; the game region 3,047 and 91. Under the standard lowering every
float equality carries a parity branch, so the library region was built
with NaN semantics off. Compiled with my own run under the library line
plus `-fno-honor-nans`, `-ffinite-math-only` or `-ffast-math`, 0x7c350 is
byte-equal; without, 1 of 11 instructions in place. The gate with each of
the three added: 989 rows, every one equal, every segment identical.

*Signed overflow.* 0x13d80 (a word map's clear, 43 bytes) guards its loop
on the mask's sign (`test; js`), the fold of `hashMod + 1 > 0` into
`hashMod >= 0` that needs the add's `nsw` (InstCombineCompares.cpp:1318 in
3.3); `-fwrapv` strips it and the guard stays `inc; test; jle`. Compiled
without `-fwrapv`: byte-equal. The gate without the flag in the library
line, in the game line, and without it beside `-fno-honor-nans`: 989 rows,
every one equal. D3 took the flag from 0x12120's subtract-then-extend, an
unmatched function whose shape the fingerprint shows is common either way
(74 `sub eax; movsxd rax, eax` and 1,255 `movsxd reg, [mem]` in the library
region). A flag no row needs and one row refuses has no evidence; D3's own
trigger.

*The game region.* Its line changes only by losing `-fwrapv` (12 rows,
indifferent). Its 3,047 equality tests without a parity branch against 91
with one say its NaN setting is not uniform or not the default either; that
is the game region's question, to be ruled when a game function needs it.

**Trigger to revisit.** A claimed row that stops matching under the new
line (none did: the gate ran before and after); a library function that
needs infinities folded or reassociation (then `-ffinite-math-only` or
`-ffast-math`, measured the same way); a function that needs `-fwrapv`
back, which would split the region by flags as D22 splits it by compiler.

**Addendum, 2026-10-28 (round 46 harvest).** The vehicle's speeds 0x165890
and 0x165910 (hknpVehicleInstance's kilometres and miles an hour) multiply
the chassis speed once by 0x40666667 (0x14ca400) and 0x400f2af7 (0x14ca404).
Round 46 read the pair as Havok's divide-then-multiply folded under
reciprocal math and reassociation, which would be this trigger. Measured in
float: 0x40666667 is f(0.001f * 3600.0f), also f((1.0f / 1000.0f) *
3600.0f), where f(3600.0f / 1000.0f) and 3.6f are 0x40666666; 0x400f2af7 is
f(3600.0f / 1609.3f), also f(3.6f * f(1000.0f / 1609.3f)), where the
reciprocal reading f(f(1.0f / 1609.3f) * 3600.0f) is 0x400f2af8, not the
base's. Both constants are exact folds of a constant expression whose
constants the source groups (a named conversion factor or a parenthesised
product), which the fixed line folds with no flag; the reciprocal reading
does not give the miles constant at all. No flag. The two functions return
to the queue with the grouped form as the lead. The trigger stands.

## D25. The CRT's `__dso_handle` resolves from the base's own exit registrations (2026-10-27)

**Decision.** A reference to `__dso_handle` (the hidden object the C++
runtime's `crtbegin` defines, which every `__cxa_atexit` registration of a
static object's destructor passes as its third argument) resolves to the
address the base itself passes: `BaseElf.dso_handle` reads the `lea rdx,
[rip+X]` before each call or tail jump to `__cxa_atexit`'s PLT stub and
takes the one value they agree on; two values would be an error, not a
guess. The compiler's GOT load of the symbol becomes the base's `lea`
under D10 as for any symbol the executable defines.

**Why.** The symbol is not in the base's dynamic symbol table (hidden
visibility), so neither the import tables nor the function table name it,
and there is no source form for a static object with a destructor that
avoids it. Measured 2026-10-27 over the whole text: 13,043 call or jump
sites of `__cxa_atexit`, 10,632 with the `lea` in reach, all naming
0x16dc0d8, no other value. The first function to need it: FUN_00006bf0, the
static initializer that builds the stack tracer and registers its
destructor (49 bytes, equal once the symbol resolves).

**Trigger to revisit.** A second value among the registrations (none), or
a base whose registrations pass the handle only through another register
(then the finder follows the move).

## D26. The PS4 compiler follows the stack check's failure call with one nop (2026-10-27)

**Decision.** The library prefix's compiler (`cxx=3.3-src`) carries a
second backport patch, `tools/patches/llvm-3.3-sspnop-01-stack-chk-fail-nop.patch`:
after the X86 printer emits a `call __stack_chk_fail`, it emits one
`nop` (0x90). Nothing else changes. The game prefix (the prebuilt 4.0.0)
is not patched yet; the game region shows the same byte and will take
the same patch on a from-source 4.0.0 once that build is verified
byte-identical to the prebuilt (D20's procedure), a separate decision.

**Why.** Round 32's worker left FUN_000029b0 equal except for its last
byte: the base's function ends `call 0x14b1dc8; nop` and the compiler
ends it at the call. 0x14b1dc8 is the import stub of `__stack_chk_fail`
(`config/imports.base.txt`, NID Ou3iL1abvng). The whole executable was
measured (the supervisor entry after Round 32 in docs/NOTES.md holds the
script's output):

- Every call to the stub is followed by `nop`: 751 of 751 in the library
  region (below 0x1a3e00), 5,981 of 5,981 in the game region. 711 of the
  library's and 5,899 of the game's end their function with it; the
  others sit mid-function, the nop before the next block's code.
- The nop is inside the function: `config/functions.base.txt` takes its
  sizes from the `.eh_frame` FDE ranges (`tools/survey_elf.py`), and the
  range covers the byte (FUN_000029b0 is 0x3a bytes, its call ends at
  0x39). It is therefore the compiler's, not the linker's alignment.
- No other callee gets one. Of the four other `call; nop` pairs in the
  executable (0xf6dc9, 0x8b77aa, 0x94f1f9, 0x94f409) each nop pads the
  next instruction to a 16-byte boundary: loop alignment.
- The game region's other `noreturn` callees are followed by `ud2`
  (328 after the stub at 0x14b0378, 139 after 0x14b04e8): that is
  `TrapUnreachable`, which upstream LLVM 4.0 turns on for PS4 so that "the
  return address of a noreturn call must still be within the calling
  function" (`lib/Target/X86/X86TargetMachine.cpp:168-175`). The failure
  block is the one place where the executable has a nop instead, in
  both compiler generations; the library region has one `ud2` in all and
  no trap after any call. The upstream stack protector builds the block
  as `call @__stack_chk_fail; unreachable` (`lib/CodeGen/StackProtector.cpp`,
  `CreateFailBB`, 3.3 and 4.0.0 alike), which gives nothing (3.3) or
  `ud2` (4.0.0 on PS4) after the call, never a nop.
- No matched function carries a canary that ends on its failure call:
  the shape was unclaimable, and it blocks 711 library functions.

The patch reproduces the observed rule at the one place that cannot
change any other byte, instruction emission: the nop is added after the
call's MCInst, so register allocation, scheduling, block placement and
the function's own size (the end label moves past the nop, as the FDE
shows) are untouched. The PS4 compiler's own form of the rule is not
known; its effect is measured exactly. A source-level spelling (a nop
asm after the call) would be a crutch and would not survive the
protector's own block anyway.

**Trigger to revisit.** A call to `__stack_chk_fail` in the base with no
nop after it, or a canary function that matches under the patch only by
an unrelated change; either reopens the mechanism.

## D27. The library compiler merges one run of consecutive stores per visit (2026-10-27)

**Decision.** The library prefix's compiler (`cxx=3.3-src`) carries a
third backport patch,
`tools/patches/llvm-3.3-storemerge-01-single-merge-per-visit.patch`:
`DAGCombiner::visitSTORE` calls `MergeConsecutiveStores` once per visit
of a store, as the 3.2 release does
(`if (!LegalTypes && MergeConsecutiveStores(ST))`), instead of the 3.3
release's loop that repeats the merge until the visited store is itself
merged. Nothing else changes. The game prefix is not concerned: the game
region merges every pair (3,065 merged constant stores, `config/flags.base.txt`;
28 merged trailing pairs against 1 unmerged in D26's census), as 4.0.0 does.

**Why.** Rounds 29 to 33 left FUN_0007a020 and FUN_0017afe0 equal except
for one pair of constant stores: the base merges the lowest pair of each
function's run into one 8-byte store and keeps the next pair apart, the
compiler merged both. Round 32 ruled it source structure after a census
(46 library functions end on a merged pair, 9 on an unmerged one) and
sent a structural lead; round 33's worker derived the lead and showed it
does not give the bytes, then found the probe that separates the two
readings: FUN_00082430, hkpPositionConstraintMotor's constructor, stores
seven constants in one block with no control flow, and the base keeps
only its lowest pair (the forces at +0x10) merged; tau, damping and the
two recovery velocities at +0x18, +0x1c, +0x24 and +0x20 stay four
4-byte stores in source order. The supervisor measured it:

- The 3.3 release's `visitSTORE` repeats `MergeConsecutiveStores(ST)` in
  a do-while until the store is deleted
  (`lib/CodeGen/SelectionDAG/DAGCombiner.cpp:8526-8541`). Each call
  merges the lowest run of the walk (two i32 stores into an i64, the
  largest legal integer type), so the loop merges every pair. The 3.2
  release calls it once (`DAGCombiner.cpp:8119` of llvmorg-3.2.0). The
  loop is upstream commit 1157e1410c83 of 2012-12-02 (Nadav Rotem,
  "Allow merging multiple store sequences on the same chain"); the
  `sspstrong` attribute the region uses (D20) is 2013-01-23
  (d154e283f285), so the PS4 compiler's generation is not simply older
  than the loop; it behaves as if the loop were absent. Its own form of
  the rule is not known; its effect is measured exactly.
- A scratch constructor of 0x82430's layout, compiled under the library
  line: the unpatched build emits three `movabs` pairs (+0x10, +0x18,
  +0x20); the patched build emits the base's instructions exactly (12
  instructions, 68 bytes, the probe's own vtable the one unverified
  relocation). FUN_0007a020 (43 bytes) and FUN_0017afe0 (54 bytes) are
  equal under the patch as written, with no change to their source, and
  are claimed.
- `tools/build.sh gate-all` holds on every row under the patch: the
  twelve matched functions that end on a merged pair (one run each) and
  every matched constructor are unchanged, since a single run merges in
  one call.
- The remaining unmerged tails of D26's census (0x7b400, 0x7c710,
  0x7d660, 0x82510, 0x83060) are hkpConstraintData slot-6
  implementations and constructors of the same shape; they come up in
  the queues under the patch.

**Trigger to revisit.** A library function whose base merges two runs
on one chain (two 8-byte constant stores built from four 4-byte
constants in one block), or a matched row that fails under the patch;
either reopens the mechanism.

## D28. The library compiler prints a function's jump tables inside the function (2026-10-27)

**Decision.** The library prefix's compiler (`cxx=3.3-src`) carries a
fourth backport patch,
`tools/patches/llvm-3.3-jumptable-01-table-before-function-end.patch`:
`AsmPrinter::EmitFunctionBody` prints the function's jump tables after the
body and before the function's end label, so that the symbol's size and
the unwind range (the `.eh_frame` FDE, the source of
`config/functions.base.txt`'s sizes) cover a table printed into the
function's own section. A table printed into another section leaves the
current section as it was. Nothing else changes. The game prefix is not
concerned: 4.0.0 prints the tables into `.rodata`, as the game region
shows.

**Why.** Round 34's worker left FUN_000aa570 with an object whose `.text`
is the base's 64 bytes exactly (the code, one alignment nop, the
four-entry table) and a symbol and FDE that end at the last `ret`
(0x2f); the base's row is 0x40 and covers the table, so the function was
unclaimable, and so was every function with a switch table. The
supervisor measured the executable (`jtcensus.py` in the session's
scratchpad: an indirect `jmpq *%r` reached through a `movslq (%r,%r,4)`
and a `leaq` of the table; the table's address against the row of the
jump):

- The library region below the D22 stretches: 54 tables in 44 functions,
  every one inside its function's row. The D22 third stretch
  [0x1a3a70, 0x1a3e00) holds 3 tables, all in `.rodata` (0x14d2b40 on),
  as its later generation prints them.
- The game region: 497 tables in 354 functions, none in `.text`.
- The 3.3 release prints the tables after `.size` and after the
  exception handler's end (`.cfi_endproc`):
  `lib/CodeGen/AsmPrinter/AsmPrinter.cpp:758-788`. 3.6.2 (`:865-891`)
  and 4.0.0 (`:982-1015`) print them after the end label too; the
  worker measured the FDE end at 0x2f under 3.3 to 3.7.1 and at 0x2d
  under 3.8.1 to 4.0.0 for the same object. Under `-fPIC` on x86-64 the
  table's entries are 32-bit label differences, which 3.3 prints into
  the function's section (`EmitJumpTableInfo`, `EK_LabelDifference32`),
  and the alignment before the table is code alignment, a nop, as the
  base's byte at 0xaa59f is.
- Under the patch FUN_000aa570 is equal with every target verified, and
  `tools/build.sh gate-all` holds on every row: no matched function holds
  a table, so the change touches no claimed byte, and the symbol sizes of
  the others are unchanged.

The PS4 compiler's own form of the rule is not known (an end label after
the tables, or an FDE that spans the section's data); its effect on the
symbol and the unwind range is measured exactly, and the patch reproduces
it at the one place that cannot change any other byte of the function.

**Trigger to revisit.** A library function whose base holds a table
outside its FDE range, or a matched row that fails under the patch;
either reopens the mechanism.

## D29. The library compiler forms BEXTR from a shifted, masked value (2026-10-28)

**Decision.** The library prefix's compiler (`cxx=3.3-src`) carries a
fifth backport patch,
`tools/patches/llvm-3.3-bextr-01-and-shift-mask-combine.patch`: the X86
DAG combiner forms `X86ISD::BEXTR` from `(and (srl|sra x, imm), mask)`
when the mask is contiguous and the field fits the type, selected as
`bextr` on a BMI target. It is upstream commit b25f0f5538fb of
2013-09-02 ("Create BEXTR instructions for (and ((sra or srl) x, imm),
(2**size - 1)). Fixes PR17028."), with the node's type fixed as in
3bf0317fec6a of 2013-10-01, both after the 3.3 branch and before 3.4;
the 3.3 release forms BEXTR only from the `__builtin_ia32_bextr`
intrinsics. The game prefix (4.0.0) has the combine upstream.

**Why.** Round 42's worker left FUN_0003a290 (hknpGroupCollisionFilter's
slot 7) equal except for two `bextr` (controls 0x505 and 0x50a) where
the compile has `shr; and`, and counted the shape over the region: 135
`bextr` in 47 library functions (one in a D22 stretch), none claimed,
and no source form produces one under the release 3.3 without the
intrinsic, which is no developer's spelling of a field extract. The
patch ports the upstream combine unchanged; under it FUN_0003a290 is
equal and `gate-all` holds on every row (the harvest commit of round
42: no matched function held a shifted, masked field the combine
converts, which the census of claimed rows under the release build had
already shown).

**Trigger to revisit.** A library function whose base keeps `shr; and`
on a contiguous mask the combine would have converted, or a matched row
that fails under the patch; either reopens the mechanism.

## D30. The library region was built with debug information (2026-10-28)

**Decision.** The library prefix's flags carry `-g`. Nothing else
changes: the gate compares the loaded segments, which debug information
does not touch, and every row holds under it.

**Why.** Round 31 measured the executable for loads the compiler refused
to fold into their one user (`cmpfold.py`): the library region has 6
such 32-bit sites against 742 folded, the game region 1 against 33,185;
round 43 added the 64-bit census, 2 refused (0x15f6 in FUN_000015c0,
0x13c4d in FUN_00013c10) against 356 folded. Round 31 also found that
FUN_0017a290 matches only under `-g` and only with the loaded value in a
named local, and that `gate-all` holds under `-g` on every row, but left
the mechanism open. Round 43's worker found it:
`lib/CodeGen/PeepholeOptimizer.cpp:431` in 3.3 folds a load into its
user when the register `hasOneUse`, a count that includes the
`DBG_VALUE` a named local's debug information adds, so under `-g` a
load held in a named local keeps its own instruction; 3.6.2 counts
`hasOneNonDBGUse` (`:325`, `:1006`). The refused folds are therefore the
mark of debug information in the 3.3 generation, and the game's single
site is noise under a compiler that no longer counts them. Under `-g`
FUN_000015c0 (93 bytes) and FUN_0017bb80 (94 bytes) match as written
with their values in named locals (`mid`, `compiled`), and the gate
holds on every row (the harvest commit of round 43). A named local is
the developer's form, not a crutch: it is what the debug information
describes.

**Trigger to revisit.** A library function whose base folds a load that
a named local must hold, or a matched row that fails under `-g`; either
reopens the mechanism.
