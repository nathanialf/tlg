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

**Addendum, 2026-11-09 (after D45).** Two shapes of the game region are what a pre-3.9 clang
emits and upstream 4.0.0 does not: the weak-linkage structor emitted as its own function (D45,
clang 3.3's rule) and the masked load of a bool global shrunk to i1 (`mov al, [rip]; and al, 1`,
0xb108d0 and eight more sites; 3.7.1 and 3.8.1 emit the mask, 3.9.1 and later do not). Measured
over the whole gate with the prebuilt 3.8.1 on the game line (scratchpad d6/gate_381.log): 1,300
of the 1,301 game rows compile equal, the one failure 0xdebd80's `ud2; ud2` after __builtin_trap,
which is one of this entry's 4.0.0 fingerprints. The matched rows, small leaves, do not separate
the generations; the fingerprints of this entry (the trap pairs, the merged constant stores, the
missing vzeroupper) still do. The reading stands: the game compiler is a 4.0.0-generation code
generator carrying older frontend and lowering rules, each reproduced as a backport patch on the
4.0.0 source build when a region-wide census shows the base never deviates from it (D45; the i1
mask is the next candidate, round 114A's investigation).

**Addendum, 2026-11-10 (round 129A, after D48).** Every matched game row (2,932 in 2,637 files)
and every unmatched draft, compiled under each prebuilt release with the game line's flags
(scratchpad a129/sweep_table.txt, sw/res_<release>.tsv, rule_table.txt): 3.6.2 holds 2,909 rows,
3.7.1 2,922, 3.8.1 2,918, 3.9.1 2,877, unpatched 4.0.0 2,879, the 4.0.0 source build with its
eight backports all 2,932. Three corrections to this entry's fingerprints, each dated from the
upstream history: the trap pair is the PS4 TrapUnreachable setting (r264224, 2016-03-24, first in
3.9; the base has 342 `ud2; ud2` pairs), the missing vzeroupper is the btver2 change (r260764,
2016-02-12, first in 3.9; the base has no vzeroupper against 31,253 ymm operands), both Sony's own
patches sent upstream, so they do not date the base; the merged constant stores are 3.8's and
later (0xacd590; r248169 of 2015-09-21 is the candidate, not confirmed by backing it out). The
4.0.0 fingerprints the rows do show are two: the X86 representative register class of float
values (r282836, 2016-09-30: list-ilp's register-pressure order in 0x228960, 0x228a60, 0x4b7be0,
0x6e1d60, 0x82fbe0; `-disable-sched-reg-pressure` on the source build gives 3.9.1's bytes) and
SimplifyCFG's sinking of common loads (r279460, 2016-08-22: 0x1393600's cmovge;
`-simplifycfg-sink-common=false` gives 3.9.1's). Against them stand the rules the base lacks
(D46 to D48 and a ninth candidate, CodeGenPrepare's load-based select-to-branch heuristic, removed
by r261809 on 2016-02-25, which three drafts need), dated from 2015-07-17 to 2016-10-20. No single
upstream date separates the rules the base has from those it lacks: they overlap by about
fourteen months, so the base's compiler is a fork with its own selection of changes, and neither
"4.0.0 with backports" (nine with the candidate) nor "3.7.1 with forward ports" (five, one of
them a rewritten SimplifyCFG function, and D45's backport) is the original; both are
reproductions. The line stays the 4.0.0 source build: it holds every row today, each of its
patches is one rule with a census, and a move to 3.7.1 would have to carry a pass rewrite and
re-prove every decision on rows that are still small leaves. Trigger to revisit: a class of
functions (not leaves) that the 4.0.0 line cannot hold and 3.7.1 does, measured by the same sweep.

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

**Addendum, 2026-11-08 (round 80A's harvest).** A member written twice in a
constructor passes the test when the bytes prove the second write.
hkpPrismaticConstraintData's constructor 0x7e3d0 and
hkpLinearClearanceConstraintData's 0x836d0 write the motor atom's isEnabled
false before and again after its target position and motor pointer. The
base clears isEnabled and motorAxis with one memset, and MemCpyOpt forms a
memset from adjacent byte stores only from three of them
(`lib/Transforms/Scalar/MemCpyOptimizer.cpp:149-172`,
`isProfitableToUseMemset`: two stores are left to the code generator, three
byte stores over two bytes exceed the pointer-and-byte store count); the two
bytes hold no third member, and a single write compiles to 47 of 53
instructions (round 80A's control). The second write is the developer's
statement recovered from the optimizer's rule, not a steer, and the same
pair in both constraint datas (Havok's constructors copy each other) is its
second witness. A duplicate store is refused where no such rule needs it.

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
Round 50's harvest added hkDebugDisplay 0x16a64f0 and hkProcessFactory
0x16a6530 (facts: the singleton strings at 0x14cbaa4 and 0x14cbab3 their
registrations 0x183cd0 and 0x183f90 store into the records 0x57c88c8 and
0x57c88f0 beside the create functions 0x183c40 and 0x183f00, which allocate
the 0x28-byte objects and store the vtables), hkPackfileWriter 0x16a6960
and hkBinaryPackfileWriter 0x16a6470 (derived: the base's constructor
0x19be50 belongs to the file whose path string at 0x14cce52,
hkPackfileWriter.cpp, its functions load at 0x19cb3f and 0x19d01e; the
derived class is built on the stack of hkSerializeUtil's savePackfile,
0x17da40, a fact from its warning string at 0x14cb438, whose calls to slot
6, the contents, and slot 9, the save, are the two calls the public API
makes over hkBinaryPackfileWriter; the base's slot 9 is pure, a dynamic
relocation) and LoadedImage 0x16a7580 (derived, the header's class, stored
by its constructor 0x1a04d0 and its destructors 0x1a0310 and 0x1a03a0).
The functions 0x183c40, 0x183f00, 0x181b10 and 0x1a0310 were blocked on
these rows.
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

Round 51's harvest added Crc32StreamWriter 0x168c980 (derived: no type
info and no string names it; hkClass's signature function 0x45c0 builds it
on its stack at 0x45ec, the only store site, seeds the CRC with all ones
and returns its complement, and slot 6 0x40c0 folds each byte in with the
reflected polynomial 0xedb88320; the tree had already named its deleting
destructor's row 0x4060 and declared the class), so 0x45c0 is claimable
as written.

Round 52 added no vtable. hknpVehicleSuspension's row (0x16a4000) names its
storing function by that function's current row, `_ZN21hknpVehicleSuspensionD1Ev`
(0x14deb0, the destructor the round claimed from func_0014dd30.cpp); the
column is the function that stores the vtable, a constructor or, as here, a
destructor.

Round 53's harvest added two rows. ConstraintData169ffe0 0x169ffd0 (a
derived name already carried by the claimed slot 20 row 0x832b0; no type
info and no string names it): stored only by its constructor 0x831a0, which
sets a local-transforms atom and an angular friction atom (type 17), slot 5
0x83330 returns 26, slot 7 is 0x832d0 and slot 20 0x832b0; the constructor,
equal in quick_diff but for this relocation, is claimed with the row.
hkPlatformObjectWriter 0x16a6910 (a derived name already carried by the
claimed slot 6 row 0x19ae90, after the public Havok SDK class whose two
virtuals, the object write and the raw write, sit in slots 5 and 6; no
string names it): stored by its constructor 0x19a950 and both destructors
0x19ab10 (slot 1) and 0x19abf0 (slot 0); the constructor keeps a 32-byte
object taken through the memory router at +0x10, which the destructors
release, and copies the host layout rules (the bytes 08 01 01 01 at
0x14cb8f6) to its stack; seven slots, 2 to 4 the common 0x270, 0x42d0,
0x69a0, 5 0x19aca0, 6 0x19ae90.

Round 54's harvest added two rows. RefArrays0005a230 0x169ab10 (the base
of RefArrays0005a340, whose row names it; no type info and no string names
it): stored by its constructor 0x6bc50 (already the row
`_ZN17RefArrays0005a230C1EP9hknpWorld`) and by its base destructor 0x5a230,
which the round renamed `_ZN17RefArrays0005a230D2Ev`; the matched slot 0
0x6b7c0 is a jump to it and the matched slot 1 0x6b7d0 calls it, the D1
calling its own D2 of cookbook 9; eight slots, 5 to 7 0x6b820, 0x6c110,
0x3b640. Object0019a7c0 0x16a68d0 (named by the tree after its destructor;
no string names it): the 64-byte cache hkPlatformObjectWriter's constructor
0x19a950 builds in place at 0x19aa7b when no cache is handed in and the
layouts differ, two pointer maps at +0x10 and +0x20 and an array at +0x30,
the public Havok SDK's hkPlatformObjectWriter::Cache by layout, stored also
by its destructor 0x19a7c0 (slot 0; slot 1 0x19a770 is claimed); five
slots, nothing beyond hkReferencedObject's. The round's third request,
0x169b190 (the manifold event modifier whose slots 2 and 3, 0x71520 and
0x715d0, the round matched), needs no row: nothing claimed stores it.

Round 55's harvest added XmlStartElement 0x16a69e0 (the parser's
start-element node, named beside the tree's XmlEndElement and
XmlCharacters; a derived name, no string names it): stored by its
destructor 0x19d450 (slot 0) and deleting destructor 0x19d500 (slot 1) and
built in place by the parser's reader at 0x19e52b; five slots, nothing
beyond hkReferencedObject's. Object0019a7c0's row now cites its destructor
0x19a7c0: the verifier wants the cited function to store the address point
into its own object, and the constructor that builds the cache does so into
a new one; the destructor 0x19a7c0 is claimed with the correction.

**Addendum, 2026-10-30 (round 63B).** A derived row may cite a constructor that builds the
class's object in place as a member of its own: hkLargeBlockAllocator's constructor 0x12160
stores SingleBlockAllocator's address point at `this+0x138` (0x12194). The checker's
`vptr_stores` now counts a store at any offset of `this` (`members=True`); `vptr_of`, which
names a finish constructor's own vtable by its last store, keeps offset 0, so a member built
after the own store cannot be mistaken for it. 90 derived rows, 0 failing.

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

**Addendum, 2026-10-29 (round 50 harvest).** A translation unit's own
callback the linker folded is spelled under the folded body's name.
hkBaseObject's type-info registration (0x6a60) passes a finish and a
cleanup callback, both the empty body 0x6660 in the base (the body its
vtable's slots 0 and 1 cite too, FUN_00006660). The TU defines them as two
overloads of FUN_00006660 with external linkage: a `static` callback is
reached by an assembler-resolved displacement to the TU's own copy, which
the gate cannot place (D17 attributes data, not a folded function), while
the external name carries a relocation that resolves to the body the
linker kept. The spelling emits the base's bytes and steers nothing; the
two overloads are one name per address applied to a body with two
signatures. The type-info size the registration stores is written as the
literal 16 the bytes hold (hkBaseObject is 8 bytes; what the registration
measured is not yet known).

**Addendum, 2026-10-30 (round 57 harvest).** When the folded body's row
carries a constructor's or a destructor's name, no overload of that name
can take the callback's signature. The callback is then spelled under the
address's own name, `FUN_<addr>(void *)`, with external linkage: hkColor,
hkTraceStreamTitle and hkFourTransposedPointsf (0xa1d0, 0x9470, 0xc1b0)
pass their cleanup as `FUN_00008d60`, the empty body whose row is
AllocatorBase's base destructor; hkPackfileHeader and
hkPackfileSectionHeader (0x8e380, 0x8e460) pass `FUN_0008c0a0`, the
empty body whose row is hkxVertexDescription's finish constructor. The
gate places the symbol as it placed 0x6a60's: the object's own bytes of
the function sit at the base's field, so the reference resolves there and
nowhere else. `FUN_<addr>` is the address's name in
`config/functions.base.txt`, the name every callee carries until its own
is known, so no second name is given to the address; the row of the body
keeps its destructor's or constructor's symbol.

**Addendum, 2026-10-31 (round 68A).** When one translation unit registers
two classes whose callbacks the linker folded onto one body, the source
held two functions, one per class as the reflection files register them,
and the base forms the folded address before each hkClass call. One
shared external callback keeps its GOT load in a register across the call
(the load is CSEd), so the bytes differ. The second callback is spelled
under the address's own name with the registered class appended,
`FUN_<addr>_<class>(void *)`, external linkage, and the layout places it
as it places the first (its own bytes at the base's field, the resolver of
6b9c2f9). The suffix names no address: the folded function's own address
never existed in the executable, and the body's row keeps its name. 0x8af0
(hkCustomAttributes::Attribute and hkCustomAttributes, both cleanups the
empty body 0x6c80) is claimed so, equal at every instruction with the two
names where one name left the load in r14 (measured 2026-10-31 through
tools/quick_diff.sh); 0x155a0, 0x1c5d0, 0x3c920 and 0x12a0 hold the same
shape (bodies 0xe5c0, 0x1c1e0, 0x3b640, 0x270).

**Addendum, 2026-10-30 (rounds 62A and 64B).** The gate placed a folded callback by finding its
raw bytes in the base, which fails when the callback's code holds a relocation field (a vtable's
GOT load in hkxBlobMeshShape's and hkxTextureFile's finish callbacks, 0x85d40 and 0x878f0:
"bytes occur 0 times"). tools/layout_link.py now places such a function where the base's own
field at the referencing site points, when the function's code compares equal there instruction
by instruction with its relocations masked and their targets verified (match_check.compare, the
gate's own comparison); the raw search stays for literals. The spelling rule is unchanged:
`FUN_<addr>(...)` with external linkage, the body byte-equal to the folded one.

**Round 70A addendum (D39).** The external spellings above stay valid where claimed; a new
registration writes its callbacks as the registering file's own static functions (D39), and the
files carrying the external form are rewritten to it as they are revisited.

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

**Addendum, 2026-10-29 (round 50 harvest).** A function-local static is
a file-local object with a longer name. hkSerializeDeprecated's create
function (0x19a5f0) builds its instance as a static of the function,
guarded (`__cxa_guard_acquire` at 0x19a5fe; the object at 0x57c8a08, the
guard byte at 0x57c8a18). The mangled object
`_ZZ12FUN_0019a5f0vE9D_57c8a08` is the identifier D_57c8a08 to
`BaseElf.base_identifier` (the last component after the function's
encoding, with any discriminator); the guard `_ZGVZ...` is not the
object: `tools/layout_link.py` places it at the object's address plus the
two symbols' distance in the object file's section (the compiler lays the
guard out beside the object in the unit's `.bss`, 0x10 after the 16-byte
object here, and the linker keeps the unit's layout), and the gate checks
every reference against the base's field as for any symbol. 0x19a5f0's
twelve relocations resolve to the base's targets (three to the guard, six
to the object, the two guard imports and the vtable row of D14); the row
is claimed in this harvest.

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

**Addendum, 2026-10-30 (round 58 harvest).** The second witness of the
unswitch shape arrived (0x13e090, the layer tree update: two copies of the
leaf gather loop with the `split` test after the loop's guard, NOTES Round
58), and both flag readings were measured over the region with an
experiment build of the live 3.3 source (two hidden options, the live
install untouched; scratchpad exp33/, every claimed library TU compiled
under each and its `.text` compared with the live object's; the baseline
run under no option finds every one of the 1,829 TUs identical). Non-trivial
unswitching at -O2 (`createLoopUnswitchPass(SizeLevel)` in place of
`SizeLevel || OptLevel < 3`) changes one claimed function, 0x1806b0
(hkMemoryResourceContainer, 60 instructions from 52, no longer equal), and
matches neither witness (0x187750 at 0.23, 0x13e090 at 0.03): refuted. -O3
measured again over the 2,076 rows changes fourteen TUs with sixteen
claimed functions, among them hknp's own (0x2b670, 0x310f0, 0x18e380,
0x142a40's three siblings) and hkBase's (0x14640, 0x904f0, 0x1806b0), so a
level raised for one library is refuted with the plain level. The shape has
no flag in the region; it is a source question, (b) of the ruling: the two
loops as the developer wrote them, or a structure that duplicates the loop
(a template or an inline helper instantiated on the guard). Both functions
stay parked with that lead until a source reading arrives; neither is a
round's queue item.

**Addendum, 2026-10-30 (round 62B's question).** Round 62B found that code-generating a TU from
its own serialized bitcode (`clang -emit-llvm` at the library line, then `clang -Xclang
-disable-llvm-optzns` on the .bc) makes 0x174f30 equal, where the one-step compile differs in
the registers of a clear loop's two induction variables, and asked whether the base's code
generator ran on deserialized IR (use-list order is what the round trip changes). Measured over
every claimed library TU at 560c963 (1,937 TUs, scratchpad rtexp/run.sh in a snapshot
worktree): 17 TUs change their text and 18 claimed functions among them stop matching (0x17f60,
0x27a40, 0x310f0, 0x68440, 0x68500, 0x69150, 0x76910, 0x7fea0, 0x92e70, 0xae780, 0x142a40,
0x142af0, 0x142bb0, 0x158a40, 0x16ae20, 0x185460, 0x1854b0, 0x18e380), while 0x174f30 alone
becomes equal. REFUTED: the base's generator ran on the optimizer's in-memory module, as the
one-step compile does. 0x174f30's residual is a use-list-order question of its source (which
value is defined or used first), never a pipeline or a flag.

**Addendum, 2026-10-30 (round 64A).** A third witness of the unswitch shape: 0x605b0,
hknpSpaceSplitter's constructor, whose base holds two copies of an inner loop that -O3's
non-trivial unswitch reproduces (and -O3 is refuted over the region, the round 58 addendum). It
joins 0x13e090 and 0x187750 under (b): a source question, parked, never a flag; a fourth witness
is reported, not worked. Two further details of 0x605b0 (a 64-bit `a - 1`, a u16 mask emitted as
`shl 16; add 0x10000; shr 16`, the mask shape also at 0x18e820) are source questions of their
own and go with it.

**Addendum, 2026-10-31 (round 67A).** A fourth witness of the unswitch shape: 0x72c10,
hkAlgorithm::quickSortRecursive over Keyed00072c10, whose base holds two copies of the j scan
split on the invariant `str == null`. In 3.3 the test reaches LoopUnswitch inside the header's
`or i1` (SimplifyCFG's FoldBranchToCommonDest); FindLIVLoopCondition takes the invariant out of
the `or` (LoopUnswitch.cpp:373), the condition is not a trivial unswitch, and UnswitchIfProfitable
refuses the non-trivial one in a pass built for size (LoopUnswitch.cpp:651;
PassManagerBuilder.cpp:189 builds it so below -O3). Unlike 0x605b0, -O3 does not reproduce the
base either: the fixed line and -O3 both first diverge at 0x72c32 (the draft compiled through
tools/compile_cpp.sh with -O3 appended, 2026-10-31). The shape is a source question in every
case. Parked under (b) with 0x13e090, 0x187750 and 0x605b0; a fifth witness is reported, not
worked.

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

**Addendum (round 55).** The region holds two spellings of the reference
release: 437 sites fold the count's test into the compare and swap loop
(`removeReference` in the tree) and 27 read the word once into a value
the test keeps as its own instruction under `-g`, the named value of this
decision (the platform object writer's release of its copier at 0x19ac0c,
hknpTyremarksInfo's destructor at 0x68db8, the parsed node's at 0x19a570).
The tree spells the second `releaseReference` (a derived name) on
hkReferencedObject, and a release site is written in the spelling its
bytes hold; neither is a crutch, both are the program's reads.

## D31. The library compiler folds a lane-0 scalar operation into its insert (2026-10-29)

**Decision.** The library prefix compiles with a sixth backport patch,
`tools/patches/llvm-3.3-scalarfp-01-lane0-op-insert.patch`: the pattern
block of upstream r196925 (2013-12-10, Andrea Di Biagio, "Ensure that the
backend no longer emits unnecessary vector insert instructions immediately
after SSE scalar fp instructions like addss or mulss"), which selects
ADDSS, SUBSS, MULSS and DIVSS, their SD forms and their VEX forms from a
scalar operation on lane 0 followed by X86Movss or, under SSE4.1 and AVX,
X86insrtps, placed in `lib/Target/X86/X86InstrSSE.td` before `/// Unop
Arithmetic` as upstream placed it. r197145 (the packed operation followed
by an insert) is not taken: no library function has shown that shape.

**Evidence.** Round 50's worker left 0xbd30 (hkMatrix3 from a quaternion)
NONMATCHING on one shape: the base holds a bare `vaddss` whose upper
lanes come from its first operand and feed the vector operations after it
(`c = _mm_add_ss(b, one)`, then `_mm_sub_ps(c, a)`), where the 3.3 compile
adds and then inserts (`vaddss; vinsertps`), which reorders what follows.
Measured with a two-line probe under the library flags: LLVM 3.3 (the
release and the from-source build) and 3.4.2 emit `vaddss; vinsertps`;
3.5.2 emits the bare `vaddss`. The 3.3 source has no such pattern and
lowers a lane-0 float insert to INSERTPS whenever SSE4.1 is on
(`X86ISelLowering.cpp`, `LowerINSERT_VECTOR_ELT_SSE4`), so no spelling of
the intrinsic produces the base's bytes without the pattern. The patch was
built as an experimental compiler in the supervisor's scratch space first
(the procedure of D21's -O3 measurement): under it the probe folds to the
bare `vaddss`, and `gate-all` in a scratch worktree holds on every one of
the 1,793 functions then claimed (`gate: OK`, 2,714 relocations resolved);
0xbd30 drops from a reordered function to 3 divergent instructions (a
`vpshufd` register pair at 0x63 and 0x68, and `vmovss xmm0, xmm3, xmm0`
where the base has `vinsertps xmm0, xmm3, xmm0, 0` at 0xbda9), a source
shape for the worker. The live compiler was rebuilt with the patch
(`tools/build_llvm.sh 3.3`) after round 51's harvest, and the hook's gate
on the adopting commit holds on every claimed function (1,834) under it. 0xbd30 and the
four functions the worker counted with the shape (0xbf40, 0x30ca0, 0x311f0
and 0xcd910) return to the queue.

**Trigger to revisit.** A library function whose base keeps `vinsertps`
after a lane-0 scalar operation on a vector; or a packed operation
followed by an insert (r197145's shape), which would be a seventh patch
measured the same way.

## D32. The library compiler keeps a constant-count vector shift intrinsic as a call (2026-10-29)

**Decision.** The library compiler keeps a constant-count packed shift
intrinsic (`_mm_srli_epi32` and its family) as the intrinsic call, as LLVM
3.3 does; the upstream fold of such a call into an IR shift is refuted for
the region and is not backported. A function whose magnitude (cookbook 70:
`vpaddd x, x; vpsrld 1`) feeds a commutative floating-point operation with
its operands in the other order is a source-shape question for the worker
(the ranks Reassociate sorts by), not a compiler question.

**Evidence.** Round 51's worker left 0x19ff0 (the quaternion from an axis
and an angle) NONMATCHING on one shape: the base multiplies a value by its
magnitude value first (`vmulps xmm1, xmm0, xmm1`), the 3.3 compile
magnitude first. 3.3's Reassociate commutes a vector FMul or FAdd by rank
(`lib/Transforms/Scalar/Reassociate.cpp:1837-1852`, the lower rank first;
a load or a call other than a debug intrinsic is unmovable and ranked by
its position in the block, `:253-289`), and the magnitude's `psrld` is the
`@llvm.x86.sse2.psrli.d` call, so its rank is its position where the
value's is its expression depth over its loads' positions. The worker's
scratch compile with the shift as an IR `lshr` compiled equal, and 3.5.2
and 3.6.2 fold a constant-count `psrli` into `lshr`, which made the fold a
backport candidate (upstream r207058 of 2014-04-24, Michael J. Spencer,
"[InstCombine][x86] Constant fold psll intrinsics", review D3359, and
r207299 of 2014-04-26, Andrea Di Biagio, "[InstCombine][X86] Teach how to
fold calls to SSE2/AVX2 packed logical shift right intrinsics"). The
refutation is the base's own bytes: under those releases the folded pair
`lshr (shl x, 1), 1` is folded further into `and x, 0x7fffffff` by the
vector form of InstCombine's shift-by-constant folds (upstream r206045,
relanded as r206214 on 2014-04-14, Matt Arsenault, "Fix shift by constants
for vector"), which precedes r207058 and r207299 in trunk, so any upstream
compiler that folds the intrinsic also folds the pair: the worker's
five-line probe compiles under 3.5.2 and 3.6.2 to one `vandps` with a
sign-mask constant, under 3.3 to `vpaddd; vpsrld`. The library region
holds 196 `vpaddd x, x, y; vpsrld 1` magnitudes in 84 functions and not one
`vandps`, `vandpd` or `vpand` with a 0x7fffffff splat (census of the
disassembly below 0x1a3e00 against the base's constants), so the base's
compiler did not fold the intrinsic. The library compiler is therefore a
generation after r196925 (2013-12-10, D31's selection, present) and before
r206214 (2014-04-14, absent), read as a trunk snapshot (Sony's own changes,
D27's single store merge among them, sit outside that model). 0x19ff0
returns to the queue with its residual reclassified: the base's value-first
order says the magnitude's rank is at least the value's, so the source
places more unmovable instructions (loads) between the value's last load
and the magnitude's call, or builds the value in fewer layers; the worker
derives the ranks from the IR and writes the shape the program has.

**Trigger to revisit.** A library function whose base holds a sign-mask
`and` where the source's magnitude is the add-and-shift idiom; or a
magnitude the base computes as an IR shift would (a `vpslld 1` where the
idiom's add should be).

**Addendum (round 53).** The bracket refutes a second hypothesis the same
way. Round 53's worker, on the quaternion from an axis and an angle
(0x19ff0, 26 of 28 on one product's operand order), found that LLVM 4.0's
`BuildRankMap` ranks only the instructions `mayBeMemoryDependent` admits
(`Reassociate.cpp:166`), which would place the base's order, where 3.3 ranks
the fixed list of `isUnmovableInstruction` (a phi, landing pad, alloca,
load, invoke, non-debug call, division or remainder). That change is
upstream r244244 of 2015-08-06 (review D11577, "Reassociate: Implement
isUnmovableInstruction() without a hardcoded list", Matthias Braun,
committed by Quentin Colombet), sixteen months after r206214; the 3.6.2
release still carries 3.3's list. The library compiler ranks by 3.3's list,
and the function's order is found among the instructions that list ranks
(the SSE intrinsics 3.3 still lowers through calls, a division, a load),
not by a later rule.

**Addendum, 2026-10-30 (D36).** D36 restores, for one condition of
LoopRotate, the state before r181230 (2013-05-06), which 3.3 carries and
the bracket's lower bound r196925 (2013-12-10) postdates by seven months.
The bracket is read as a trunk snapshot; a snapshot after r196925 holds
r181230, so the base's rotation is either a vendor change on top of the
snapshot or a branch whose point predates May 2013 with r196925's selection
cherry-picked. Both readings keep every measurement above; neither is
established. The bracket stays as the bound on upstream changes considered
for a backport; D36 is a reversion inside it, taken on the region's
measurement alone.

**Addendum, 2026-11-07 (round 75B): the magnitude's spelling.** D32 fixes
the compiler and leaves the magnitude's source a question; two witnesses
answer it. 0x19ff0 (the quaternion from an axis and an angle, 26 of 28 with
the intrinsic) and 0x2a5c0 (the mass properties under a scale, 107 of 108:
the uniform branch's `x * x * f` needs the square's rank at most the
magnitude's, where the `psrli` call is the entry's second unmovable and the
square comes from the scale read again after the centre's store, the
seventh) each order a product the way Reassociate orders it when the shift
is an IR `lshr`, and no order of their statements reaches the base with the
call. Written with the GCC vector extension's shift on unsigned lanes,
`(bits + bits) >> one`, the shift is an `lshr <4 x i32>` that 3.3's
InstCombine leaves as it is (no sign-mask `and`, as the base), selected as
`vpaddd; vpsrld $1`, and ranked from its operands; both functions compile
equal. The spelling is one helper, `hkMath::quadFabs` in
`src/include/tlg_hk_reflect.h`, with `hkMath::fabs` over it, and the
measurement is every claimed user: the commit that claims 0x2a5c0 and
0x19ff0 (fdf25e3) passed the gate over 2,703 rows with hkMath::fabs
respelled (its four claimed users, 0x396b0, 0x3bf20, 0x151e10, 0x16a4b0,
still equal), and the next (b841053) moved the 22 files whose own helper
or inline pair spelled the intrinsic (24 claimed functions) onto the one
helper, every row still equal. No claimed function needs the call's rank,
so the developer's magnitude is the lshr form. Trigger to revisit: a
library function whose base order needs the magnitude ranked at the call's
position.

## D33. The library compiler counts no debug intrinsic in the inline cost's vector bonus nor in the memory dependence scan limit (2026-10-29)

**Decision.** The library prefix compiles with a seventh and an eighth
backport patch: `tools/patches/llvm-3.3-memdepdbg-01-dbg-before-scan-limit.patch`
(upstream r194646 of 2013-11-13, Yunzhong Gao, "Fixing a heisenbug where the
memory dependence analysis behaves differently with and without -g": in
`getPointerDependencyFrom` a debug intrinsic is skipped before the block
scan limit is decremented, as the 3.4 release has it) and
`tools/patches/llvm-3.3-inlinedbg-01-dbg-not-counted-in-vector-bonus.patch`
(upstream r200609 of 2014-02-01, Chandler Carruth from a patch by Dario
Domizioli, "[inliner] Skip debug intrinsics even earlier in computing the
inline cost so that they don't impact the vector bonus": `analyzeBlock`
skips a debug intrinsic before counting it, as the 3.5 release has it). A
debug intrinsic is then neither an instruction of the inline cost's vector
bonus nor a step of the memory dependence scan, and the library line's `-g`
(D30) changes neither decision.

**Evidence.** Round 52's worker left three functions NONMATCHING on `-g`
alone: 0xbf40 and 0x1a1c0 compile equal at `-g0` and differ at `-g` because
3.3's inline cost counts the callee's `llvm.dbg.value` calls among its
instructions before the vector bonus is decided
(`lib/Analysis/IPA/InlineCost.cpp:809-811`; the callee's cost 330 against the
threshold 325, the bonus withheld), and 0x30ca0 (189 of 197 at `-g0`)
because 3.3's memory dependence scan decrements its block scan limit before
it skips a debug intrinsic (`lib/Analysis/MemoryDependenceAnalysis.cpp:376-384`),
so a block with many `dbg.value`s runs out of budget and a load's dependence
is unknown. Both upstream fixes sit inside the library compiler's generation
(after r196925 of 2013-12-10 for the second, before r206214 of 2014-04-14
for both, D32's bracket) and both were filed by engineers of the PS4
toolchain team, so the model predicts the base's compiler carries them.
Measured as D31 was: an experimental 3.3 built in the supervisor's scratch
space from the live source with both patches; under it 0xbf40 and 0x1a1c0
compile equal and 0x30ca0 reaches its `-g0` figure (189 of 197, its
remainder another shape), and `gate-all` in a snapshot of the tree holds on
every one of the 1,872 claimed functions (every library object rebuilt under
the swapped compiler, 3,104 relocations resolved, every segment identical).
The live compiler was rebuilt with both patches after round 53's harvest,
and the hook's gate on the adopting commit holds under it. 0xbf40, 0x1a1c0
and 0x30ca0 return to the queue.

**Trigger to revisit.** A library function whose base shows the 3.3 count
(an inline refused, or a dependence lost, by debug intrinsics alone); or a
third place where 3.3's `-g` output differs from its `-g0` output by a
count of debug intrinsics, which would be measured the same way.

## D34. The library's timers read the time-stamp counter through inline assembly (2026-10-30)

**Decision.** The monitor stream's timer commands (the records the tree's
`timerBegin`, `timerEnd`, `timerBeginList` and `timerEndList` write) read
the counter with `__asm__ __volatile__("rdtsc" : "=a"(low), "=d"(high))`
in one helper of the stream class, as the rdtscp read of 0x184cf0 already
does under D9's allow list. The asm emits the instruction itself and is
the program's read, not a device that steers codegen, so the crutch test
passes; the helper is ruled in `tools/dev_native_allow.txt`.

**Evidence.** The broad phase's layer updates (0x142bb0, round 55) end a
timer on two paths. The base keeps each path's `rdtsc` (0x142cfd, which
jumps past the other's, and 0x142d9e) and merges only the three stores
after it into one tail at 0x142da0. LLVM 3.3's tail merge stops a common
tail at an inline asm (`lib/CodeGen/BranchFolding.cpp:340-346`,
`I1->isInlineAsm()` with its own comment that people expect asm to keep
its place), where the RDTSC machine instruction `__builtin_readcyclecounter`
lowers to is identical on both paths and merges with the stores, which is
what the tree's compile of the function gave (one tail holding the read).
The region holds 391 `rdtsc` sites below 0x1a3e00; ten lie in matched
functions, all through the stream's helpers, and the gate on the adopting
commit holds on them under the asm spelling.

**Trigger to revisit.** A library function whose base merges two counter
reads into one tail; or a site where the asm's ordering moves a read the
base schedules otherwise.

## D35. The stack protector's frame layout: arrays nearest the guard, then address-taken objects (2026-10-30)

**Decision.** The library region's protected frames are laid out as
upstream r197653 (2013-12-19) and r200601 (2014-02-01) lay them out: the
`StackProtector` pass classifies each alloca (a large array, a small array,
an address-taken object under the strong rules, or none) and the prolog
and epilog inserter assigns the classified objects after the guard in that
order, each set in frame-index order, then the rest in index order. LLVM
3.3 places after the guard only an array allocation or a `char` array of
8 bytes or more (`FunctionLoweringInfo.cpp:90-99`,
`PrologEpilogInserter.cpp:583-629`), everything else in index order. The
3.3 line adopts the layout as a backport (the ninth patch) once it holds on
every row; until then the three functions below stay unclaimed.

**Evidence.** The base's layer tree update (0x13e090, 0x29cf bytes) has
21 frame objects. Its 3.3 -O2 IR laid out by the 3.5.2 back end
(`tools/cc/llvm-3.5.2/bin/llc -print-after=prologepilog`, the same codegen
flags) puts every one at the base's displacement: the guard at -0x30, the
sort's entry tail -0x40, the walk -0x6e8, the leaves' arrays -0x1130, the
buffers -0x1150, the jobs -0x1760, the dropped nodes -0x1870, the children's
boxes -0x1890, the extent -0x189c, the entry -0x18b0, the box -0x18c0, the
centres -0x18d0, the keys' byte count -0x18d4, the ages -0x18f8, the leaf
jobs -0x1908, the four node lists -0x1928 to -0x1988 and the keys -0x1998
(every displacement the base's instructions use). The 3.3 back end on the
same IR puts the byte count at -0x44, the ages at -0x1150 and the walk at
-0x6f0: the byte count's alloca is the inlined TempArray constructor's,
spliced to the front of the entry block (`InlineFunction.cpp:628-667`) and
so the lowest index, yet the base places it after the boxes and before the
ages, where the address-taken group begins. No source order under 3.3
gives that. Both upstream revisions sit inside the compiler bracket of D32
(after r196925 of 2013-12-10, before r206214 of 2014-04-14; r200601 is of
the day D33's r200609 is of), so the rule is of the base's generation, not
a later one. Measured over the region (the supervisor's run, round 57's
harvest: every library object that loads the guard, 56 objects, 84
functions, each function's IR through both back ends and the allocas'
order by offset compared): the 3.5 rule reorders the allocas of exactly
three functions, 0x13e090, 0x19da90 (the XML reader) and 0x30ca0, none
claimed; every claimed function's order is the same under both.

**Adopted, 2026-10-30.** The live 3.3 prefix carries the ninth and tenth
backports, `llvm-3.3-ssplayout-01-protector-layout-analysis` (upstream
r191570 of 2013-09-27, r193653 of 2013-10-29 and r197653 of 2013-12-19:
the stack protector pass as an analysis that classifies its allocas, read
by the prolog and epilog inserter and the local stack slot pass in place of
MachineFrameInfo's MayNeedSP flag) and
`llvm-3.3-ssplayout-02-sspstrong-layout-rules` (r200601 of 2014-02-01, the
three groups after the guard, and r199684 of 2014-01-20, the
classification carried when stack coloring merges slots). r199658 (the IR
rewrite stack coloring's merge does for alias analysis) and r206486 of
2014-04-17 (the ssp-buffer-size attribute, after the bracket) are not
ported; the class in the new StackProtector.h is 3.3's own, still
inserting the guard as 3.3 does. The patches' headers hold every
adaptation. Under the rebuilt compiler every one of 0x13e090's frame
objects sits at the base's displacement (the function's remaining
differences are source), the PS4 stream writer's opener 0x91d50 compiles
equal and is claimed, and the gate holds on every claimed function (2,007
on the backport's own run, then this commit's hook). 0x19da90 and 0x30ca0
return to the queue.

**Trigger to revisit.** A claimed function whose frame the backport moves;
or a protected function the base lays out in index order where the rule
would group an array or an address-taken object.

## D36. A loop whose latch LoopRotate has just folded is not rotated (2026-10-30)

**Decision.** The library compiler carries an eleventh backport,
`tools/patches/llvm-3.3-looprotate-01-no-rotation-after-latch-fold.patch`:
in `LoopRotate::rotateLoop` the exiting-latch test no longer consults
`SimplifiedLatch`, so a loop whose latch `simplifyLoopLatch` has just
folded into the final exiting block (a scan `while (i < n && buf[i] != c)
i++;`, the increment folded into the test's block) is left as it is, the
header test first and the increment in the body. That is the state of the
condition before upstream r181230 (9c72b071fe4e, 2013-05-06, Andrew Trick,
"Rotate multi-exit loops even if the latch was simplified.", PR10293),
which 3.3 (branched 2013-05-07) carries. Nothing else of r181230 is
reverted: the latch fold, `runOnLoop`'s repeat and the fold's return value
stay as 3.3 has them. The flags line is unchanged.

**Evidence.** Round 58 (NOTES "Round 58") classified two functions whose
scans the base leaves unrotated after the fold: 0x19da90 (the XML reader:
five scans at 0x19db90, 0x19dbf0, 0x19ddd0, 0x19df20, 0x19e2e8 and the
attribute parse's pointer walks from 0x19e3b8) and 0x1a0780 (the image's
part check at 0x1a07c0), each with the header's `cmp i, n; jge` first and
`lea rax, [rsi+1]` in the body, which 3.3 rotates; the reader's comment
loop, whose latch has two predecessors and is not folded, is rotated in the
base as 3.3 rotates it, the converse the patch keeps. The region was
measured with an experiment build of the live source (a hidden option
`-rotate-simplified-latch=false` reproducing the condition's pre-state, the
live install untouched; scratchpad exp33/): every claimed library TU
(1,829) compiled under the option and its `.text` compared with the live
object's; the baseline run under no option finds all 1,829 identical; under
the option exactly one TU differs, `func_0019da90.cpp`, and only in its
unclaimed function. No claimed function changes. Under it 0x1a0780 compiles
equal to the base (0.29 before, the first difference at instruction 4) and
0x19da90 goes from 0.06 to 0.53 with its first difference moved from
instruction 26 to 139 (its loops take the base's shape; the rest is its own
residual). The claimed set is silent on the condition (none of the 2,076
functions holds a folded-latch scan), so the ruling rests on the two
witnesses and the absence of a counter-witness; D32's addendum records what
the reversion says about the bracket.

**Adopted, 2026-10-30.** The live compiler rebuilt with the eleven patches
(`tools/build_llvm.sh 3.3`, the previous install backed up); the gate holds
on every claimed row under it; 0x1a0780 is claimed under it (its row added
in the adopting commit) and 0x19da90 returns to the queue with its residual
from instruction 139.

**Trigger to revisit.** A claimed function whose folded-latch scan the base
holds rotated (the condition's post-state), or a base loop the patch now
leaves unrotated where the base rotates it; either reopens the condition
and the reading of the bracket.

## D37. A vtable another translation unit defines is not emitted available_externally (2026-10-30)

**Decision.** The library compiler carries upstream r189852 (clang ee6aa0c62e8b, 2013-09-03,
Rafael Espindola, "Don't emit an available_externally vtable pointing to linkonce_odr funcs.",
PR13124) as its twelfth backport, tools/patches/llvm-3.3-vtable-01-no-available-externally.patch:
at -O2, a referenced vtable whose key function another translation unit defines is no longer
emitted available_externally, so the optimizer cannot read its slots and a call through it
stays a call through the vtable. A vtable is still emitted, and a call through it still folds,
in the translation unit that defines the class's key function; a function whose bytes hold such
a fold therefore lives in that file, as the executable's own files did.

**Evidence.** Round 64B's 0xc360 (hkFreeListMemorySystem's destructor) equals the base but for
one call, ThreadMemory's slot 13, which the live 3.3 folds to a direct call; the base keeps
`call [rax+0x68]`. 3.3's CGVTables.cpp emits every referenced vtable available_externally when
optimizing (getVTableLinkage, shouldEmitVTableAtEndOfTranslationUnit); r189852 removed that,
inside the compiler's bracket (D32: after r196925 of 2013-12-10, before r206214). Second witness
0x158bf0 at 0x158c45. Measured with an experiment clang (the live source plus the commit's
change to CGVTables.cpp) over every claimed library TU at 2bf6508: 2,022 of 2,024 TUs
unchanged; 0xc360's TU changes and 0xc360 becomes equal; 0x181b10's TU changes and
hkBinaryPackfileWriter's constructor loses the fold of its slot 10 call, because its file in
this tree did not define the class's key function (the destructor 0x181bf0, `jmp 0x19c150`):
with that destructor defined in the same file, as hkBinaryPackfileWriter.cpp defined it, the
constructor is equal again under the patch and the destructor matches too. A compile-time
fold that depends on the vtable's presence is a fact about the file, not the flag.

**Adopted.** A first adoption commit was refused by the gate: three files held inline destructors
(hknpCompositeShape's, hkpLinearParametricCurve's, hkpWrappedConstraintData's) that 3.3's
available_externally emission alone had put there; round 64A moved them to their key functions'
files, defined hkBinaryPackfileWriter's destructor beside its constructor and hkPackfileWriter's
0x19c150 under its D1 row, all equal under the eleven patch compiler. The live 3.3 then rebuilt
with the twelve patches (tools/build_llvm.sh 3.3), 0xc360 claimed, the gate holding on every row.

**Trigger.** A claimed function that loses a direct call to a virtual slot under a later
compiler, or a draft whose only residual is a direct call where the base holds a call through
the vtable, is this decision: the key function's file, never a flag.

## D38. No vzeroupper: the X86 pass that inserts it is skipped on the library line (2026-10-30)

**Decision.** The library line carries `-mllvm -x86-use-vzeroupper=false`: 3.3's X86 pass that
inserts `vzeroupper` before calls and returns in a function that touched a ymm register
(X86VZeroUpper.cpp, added by X86TargetMachine::addPreEmitPass when the subtarget has AVX and
the option holds) is skipped, so no vzeroupper is ever emitted, as the executable holds none.
The game line needs nothing: 4.0.0 already skips the pass for btver2 by its own feature.

**Evidence.** The executable holds 0 vzeroupper against 1,068 ymm uses in the library region and
31,248 in the game region (a census of the whole text). LLVM 3.3 inserts one in every function that uses a
ymm register and calls or returns (X86TargetMachine.cpp:208, `if (getX86Subtarget().hasAVX()
&& UseVZeroUpper)`, the option `x86-use-vzeroupper` defaulting to true); round 65A's 0xd0950 is
the first library function in work to reach a ymm use, and 3.3 inserts a vzeroupper the base
does not have. The target is Jaguar (btver2), which has no AVX-to-SSE transition penalty, so the
insertion is useless there, and upstream knows it by 4.0.0: its X86.td gives btver2
FeatureFastPartialYMMWrite and X86VZeroUpper.cpp:260 returns early on it (`if (!ST.hasAVX() ||
ST.hasAVX512() || ST.hasFastPartialYMMWrite())`; LLVM 7.0.0 spells the feature
FastPartialYMMorZMMWrite), which is why the game region's 31,248 ymm uses already compile
without one (a 64-byte copy followed by a call: 4.0.0 emits four ymm moves and no vzeroupper for
either triple). The library compiler's own mechanism is not visible (3.3 has no such feature);
the option reproduces its effect exactly: the pass does not run. Measured over every claimed TU of both regions at b663afc (2,076 TUs, each
compiled by its own line with the option, scratchpad d38/run.sh; a first run had not passed the
option at all and was discarded): no claimed function changes (none held a vzeroupper, or it would not have matched), and the one function
that had reached a ymm use, 0xd0950, loses its vzeroupper (its other residuals stay its own).

**Adopted.** config/flags.base.txt, the library line (04adafa put it on both; the game line's
copy, a no-op by 4.0.0's feature, was dropped again); the gate holds on every row.

**Trigger.** A vzeroupper in a compile is this decision; a function whose only residual is a
vzeroupper the base lacks needs nothing else.

## D39. The library objects keep one section per function; a file's reflection callbacks are its own static functions (2026-10-31)

**Question.** Round 69A's 0x6c470 (hknpExternMeshShape's static initializer) is 3 of 67 with its
two type-info callbacks spelled as D15 ruled, external functions: under -fPIC their addresses are
GOT loads, which greedy keeps in callee-saved registers across the hkClass calls (a third push, the
guard's address in r15), where the base forms each address with a `lea` right before its use. With
the callbacks `static` in the file the function is 63 of 65 and the two left are the displacements
to the file's own copies, which the assembler resolves inside one `.text` and the gate cannot place:
the base's finish callback is kept at 0x6c440, directly before the initializer, and its cleanup is
the folded body 0x2d0 (`mov rax, [rdi]; jmp [rax]`, the virtual destructor called through the
vtable), which many files share.

**Evidence.** The executable folds single functions across translation units (D15's folded
destructors and callbacks; 0x2d0, 0x6c80, 0xe5c0, 0x270 each stand for bodies of many files). A
linker folds sections, so each folded function was its own section in its object: the library
objects were compiled with one section per function (`-ffunction-sections`). With that flag a
reference to the file's own static function is a relocation against the function's section
(`R_X86_64_PC32 .text.<function> - 4`), which the gate can place.

**Measurement (2026-10-31, scratchpad expwt at c6bfe8d, 2,528 rows).** With
`-ffunction-sections` added to the library line: every row equal and every loaded segment equal to
the base (tools/build.sh gate-all, 06:26:53 to 06:28:38); no claimed function changed a byte (the
flag changes sections and relocations, never instructions). With the layout resolving a
`.text.<function>` section symbol to that function (its claimed row's address, else the base's own
field when the function's code sits there, instruction by instruction with its relocations checked,
the resolver of 6b9c2f9) and 0x6c470 written with its two static callbacks: 0x6c470 equal (65
instructions) and 0x6c440 equal as the local symbol `_ZL37finishLoadedObjecthknpExternMeshShapePvi`
of the initializer's file, the folded cleanup placed at 0x2d0 by its bytes, every other row equal
(06:31:12 to 06:31:44).

**Ruling.** The library line carries `-ffunction-sections`. A type info's finish and cleanup
callbacks are the registering file's own `static` functions, named after hkTypeInfo's typedefs
(`finishLoadedObject<Class>`, `cleanupLoadedObject<Class>`, derived names: no string spells them);
a callback the linker kept (0x6c440) is claimed from the registering file under its local symbol, a
callback the linker folded is placed where the base's field points. The external spellings of D15's
round 50, 57 and 68A addenda stay valid for the rows that carry them (the bytes are equal through
the linker's relaxation of the GOT load) and are rewritten to the static form as their files are
revisited; a new registration uses the static form. The game line is unchanged: the same linker
folded the game region's bodies too, but no game witness has been measured yet (a game initializer
whose callback's register allocation differs is the test).

**Adopted (2026-10-31).** config/flags.base.txt, the library line; tools/layout_link.py resolves a
`.text.<function>` section symbol to the function (its claimed row, else the base's field when the
function's code sits there); src/libs/unknown/func_0006c470.cpp carries the two static callbacks and
the rows FUN_0006c440 (the local symbol) and FUN_0006c470 (the initializer); the gate holds on every
row. Round 70A's rows (2,547) were gated under the flag at adoption.

**Trigger.** A static initializer whose only residual is the callbacks' addresses held in
callee-saved registers (GOT loads where the base has `lea`) is this decision: write the callbacks
static in the registering file. A folded callback that the gate cannot place at the base's field
(its bytes differ from the body the base's field names) is a question for the supervisor, not a
reason to spell the callback external.


## D40. The library line allows unsafe floating-point algebra (2026-11-07)

**Question.** Round 76A's 0x158e20 (hknpVehicleRayCastWheelCollide's wheel output from its hit,
482 bytes) is equal through its clipping test and then negates the reciprocal's factor as the base
does not under the line: the base holds `vsubps (d*r) - [2.0]; vmulps r; vxorps zero; vaddps zero +
x` where the line keeps `2 - d*r` and `vsubps zero - x` (85 of 113 instructions). The shape is
DAGCombiner's: visitFSUB's `(fsub A, (fneg B)) -> (fadd A, B)` negates the factor through
isNegatibleForFree, whose ISD::FSUB case returns 0 unless the target options allow unsafe
floating-point math (tools/cc/src/llvm-3.3.src/lib/CodeGen/SelectionDAG/DAGCombiner.cpp:432-434,
"We can't turn -(A-B) into B-A when we honor signed zeros"). No source form gives the shape: a
double negation written on the factor yields the subtraction and InstCombine then drops the zero
add (round 76A, NOTES "Round 76A").

**Evidence.** D24 adopted `-fno-honor-nans` as the narrowest flag for its witnesses and left
`-ffinite-math-only` and `-ffast-math` waiting "for a function that needs what they add
(infinities folded, reassociation, reciprocals)". 0x158e20 is the first function that needs the
unsafe-algebra part and nothing else. The driver flag `-funsafe-math-optimizations` maps, in
clang 3.3, to the single cc1 option `-menable-unsafe-fp-math` (the `-###` line of the library
flags with it; no `-fno-signed-zeros`, `-freciprocal-math` or `-ffast-math` is passed), the
option the worker's diagnostic used. A census of the executable (scratchpad all.dis against the
base's constants): the library region holds 130 divisions (`vdivss`, `vdivsd`, `vdivps`, `vdivpd`)
and none by a RIP-relative constant, the game region 4,013 and 30 by a constant; 3.3's
DAGCombiner folds `fdiv X, C` into `fmul X, 1/C` only under UnsafeFPMath (visitFDIV), so a
library division by a constant would have been a witness against the flag, and there is none
(the count is small, so this is consistent, not decisive; the game region, LLVM 4.0.0, keeps its
constant divisions and stays as it is).

**Measurement (2026-11-07, main tree at 01fcfea, 2,711 rows).** With
`-funsafe-math-optimizations` added to the library line after `-fno-honor-nans` and every object
rebuilt under it (tools/build.sh gate-all, 02:57:29 to 03:02:40): every row equal and every loaded
segment identical to the base; no claimed function changed a byte. 0x158e20's draft compiled
under the flag through the line's own script is equal at every instruction (and equal again
with `-Xclang -menable-unsafe-fp-math`, with `-ffast-math` and at -O3); compiled under the line
without the flag it is 85 of 113, the first difference at instruction 58.

**Ruling.** The library line carries `-funsafe-math-optimizations`, the narrowest driver flag that
yields the cc1 option the shape needs. `-ffast-math` and `-ffinite-math-only` remain unadopted:
nothing has needed infinities folded, and the game line keeps honouring everything. The game line
is unchanged (30 divisions by a constant stand in its region).

**Adopted (2026-11-07).** config/flags.base.txt, the library line; 0x158e20 claimed from
src/libs/unknown/func_00158e20.cpp (its NONMATCHING note removed); the gate holds on every row.

**Trigger.** A library function equal but for a negation moved across a subtraction, a
reassociated constant, or a division by a constant compiled as a multiplication is this decision's
flag at work, not a source question; a GAME function showing one of those shapes is a new
question for the game line (measure, never assume). A library function whose residual needs
`-ffinite-math-only` (an infinity test folded) or a reciprocal estimate is the next decision, with
the same whole-gate measurement.

## D41. A member order is read from the functions that store the members (2026-11-08)

**Question.** LocalArray (src/include/tlg_lib_unknown.h, the shape of Havok's hkLocalArray: an
hkArray with the local block's pointer and the initial capacity after it) stores its constructor's
members in the tree's order data, local copy, capacity. That order was chosen for 0x1707d0 (the
distinct vertex ids of a convex shape), whose setSize folds its reserve only when the capacity's
load follows the capacity's store with no other store between: InstCombine forwards a stored
value to a load through FindAvailableLoadedValue without alias analysis, and that walk stops at a
store to another field of the same alloca (tools/cc/src/llvm-3.3.src/lib/Analysis/Loads.cpp:176-201;
InstCombineLoadStoreAlloca.cpp:367). Round 79A ruled for the SDK's order, round 80A measured
0x1707d0 under it (7 of 137 with setSize, 31 of 96 with setSizeUnchecked), round 81A measured the
other users.

**Evidence.** The base stores the members in the SDK's order wherever it stores them at all:
0x13b940 (the broad phase tree's rebuild) stores the data pointer at 0x13baa7 (-0x50), the capacity
at 0x13bab1 (-0x44) and the local copy at 0x13bab4 (-0x40); 0x1430b0 (the layers' rebuild) the
same at 0x143180, 0x14318a, 0x14318d. Five functions compile equal under either order (0x1412e0,
0x142a40, 0x142af0 and 0x142bb0, matched rows under the tree's order and measured equal under the
SDK's by round 81A; 0x13b940 needs the SDK's). 0x1707d0 keeps the array out of memory from its
first instruction to its last (0x1707d0 to 0x17091e store no member): it witnesses no order, only
that the compiler could fold the reserve, which the tree's source does under one order and not
the other. The destructor adds a second fact from 0x1430b0's loop (0x143300 to 0x14334d): the local
block is freed first (the stack allocator's inlined fast path, then 0xf460), the size is cleared
(0x14332a), the owned storage is freed through the container allocator (0x14334d), and nothing is
stored after it; the tree's LocalArray clears the size conditionally before its free, and its
hkArray base's destructor (clearAndDeallocate) stores the data pointer and the capacity after. The
32-byte object gets no lifetime markers (clang 3.3 CGDecl.cpp:792-805, shouldUseLifetimeMarkers
marks only objects over 32 bytes), so dead store elimination keeps those stores inside a loop and
removes them at a function's end: every witness that destroys the array once is blind to the
difference, and only 0x1430b0 sees it.

**Ruling.** The order of a constructor's member stores is read from the functions whose bytes
store the members. A function in which the object is promoted to registers is no witness for an
order; a header written to make one such function fold is the optimizer's order, not the
developer's, and is corrected when a storing witness appears. LocalArray's constructor therefore
follows the SDK's order (data, capacity, local copy) and its destruction the sequence 0x1430b0
shows (the local block freed, the size cleared, the owned storage freed, no reset after). Rows are
never removed, so the header changes in the commit that compiles 0x1707d0 equal under the new
order, together with 0x13b940 and 0x1430b0; until then the tree's order holds the gate. 0x1707d0's
question is its source: which statement lets its reserve fold under the SDK's order (the capacity
read before the local copy is stored, or a size call that does not read the capacity), with the
second `n != 0` test before the memset and the free's mask 0x3fffff80 as the controls (round 80A's
measurement, NOTES "Round 80A").

**Trigger.** A header whose member order was chosen for a function that keeps the object in
registers; a destructor whose stores are seen only in a loop.

**Addendum, 2026-11-09 (round 105A).** The switch landed (commit f5f8797): LocalArray stores in
the SDK's order and 0x13b940, 0x140ff0, 0x1a1e80, 0x72100 and 0x72740 are claimed under it, every
earlier LocalArray row equal, 0x1707d0 equal as an hkLocalBitField (cookbook 981). The destructor
sequence this entry read from 0x1430b0 is not a header fact: hkArray's destructor does reset the
data and the capacity (235 rows fail with the reset removed), and what removes the reset in
0x1430b0's loop is the inliner. The per-layer body is a static helper of the file; InlineFunction
puts lifetime markers around the helper's arrays and DSE drops the reset before the end marker
(DeadStoreElimination.cpp:221), which an inline member of the class, not inlined there, does not
get (cookbook 980). 0x1430b0 stands at 187 of 189 at the base's size, the last difference a null
phi constant's place before the leaves' initial-capacity store (list-ilp order).

## D42. The library compiler unswitches loops at -O2, under LoopUnswitch's compile-wide budget (2026-11-09)

**Question.** D21 left open whether the two copies of a loop that FUN_00187750 holds are the
developer's loops or a compiler that unswitches at -O2: upstream 3.3 creates LoopUnswitch with
OptimizeForSize set at every level below -O3 (lib/Transforms/IPO/PassManagerBuilder.cpp:189), and
UnswitchIfProfitable then refuses every non-trivial unswitch (LoopUnswitch.cpp:651). Rounds 84A to
89A brought seven more functions with the shape: 0x5c120 (matched by writing the two loops, cookbook
773), 0xab150 and 0xab4f0 (the vertex buffer utility's element conversions, where only the first
cases of a switch carry the copy), 0x1698f0, 0x776a0, 0x1806b0's neighbours. D21 asked the
supervisor to run every level experiment.

**Evidence (2026-11-09, supervisor; flags and compiler restored after each run, objects rebuilt
from an empty cache).**

- `-O3 -fno-vectorize` over the whole gate: 2,862 of 2,868 rows equal. Six fail: 0x4470, 0xac810,
  0x1412e0, 0x1806b0 and 0x1985d0 grow (214 to 315, 488 to 648, 541 to 581, 142 to 174, 597 to 889
  bytes), 0x936a0 differs by two bytes at the same size. The five growing rows compile equal again
  at `-O3 -fno-vectorize -mllvm -loop-unswitch-threshold=0`: their growth is non-trivial unswitching
  of a loop-invariant test the base left inside the loop (0x1806b0's `childName == 0` in its search
  loop). Holding the inliner at -O2's 225 (`-mllvm -inline-threshold=225`) changes none of the six.
  0x936a0's two bytes are the operands of one vmulps swapped, the promoted-argument form of its
  static reciprocal helper: -O3's ArgumentPromotion (PassManagerBuilder.cpp, OptLevel > 2), which the
  base lacks.
- At the same level the unswitch witnesses move to the base's size and near equality: 0xab150 16
  to 240 of 243, 0x1698f0 38 to 221 of 223 (810 to 925 bytes), 0x776a0 65 to 151 of 247 (604 to 924
  bytes), 0xab4f0 22 to 74 of 249. The inline-cost margin witnesses (0x175160, 0x581c0) do not move.
- No per-function threshold separates the two sets. A sweep of `-loop-unswitch-threshold` from 10 to
  90 at that level gives 0xab4f0 its best (244 of 247) at 30 to 50 and 0xab150 its best (240 of 243)
  from 60 up, while 0x1806b0 holds only below 20 and 0xac810 only below 40.
- The budget is not per loop. LUAnalysisCache::MaxSize starts at the threshold (100) once, when the
  pass is constructed, is debited by every loop the pass unswitches (LoopUnswitch.cpp:250-252) and
  refunded only when a loop is forgotten (:284): one budget for every function of a compile, spent
  in function order. Compiled as one TU in the base's address order (0xaaaf0, 0xaab10, 0xaacb0,
  0xaae70, 0xaafd0, 0xab150, 0xab4f0, 0xac810) at `-O3 -fno-vectorize -mllvm -inline-threshold=225`,
  the five matched rows stay equal, 0xab150 is 240 of 243, 0xab4f0 244 of 247 (its best from the
  sweep, now at the default threshold) and 0xac810 is equal: the budget is spent before it, as the
  base shows. That is the pattern the whole region shows, unswitched loops in some functions and
  the same shapes left alone in others of the same library, with no per-function rule.
- One line of 3.3 reproduces all of it at the line's own flags: PassManagerBuilder.cpp:189 with
  `createLoopUnswitchPass(SizeLevel)` in place of `createLoopUnswitchPass(SizeLevel || OptLevel <
  3)`, built into tools/cc/src/build-3.3 and run over the whole gate with config/flags.base.txt
  unchanged: 2,863 of 2,868 rows equal, the five growing rows the only failures, 0x936a0 equal,
  0xab150 240 of 243, 0x1698f0 221 of 223 at 925 bytes.

**Ruling.** The library region's compiler ran LoopUnswitch's non-trivial unswitching at -O2 with
3.3's compile-wide budget. The reproduction is a backport patch to the 3.3 source
(tools/patches/llvm-3.3-unswitch-01-nontrivial-at-O2.patch, the one line above), not a level or a
flag: -O3's other two differences are excluded (ArgumentPromotion by 0x936a0) or unsupported (the
inliner's 275 by nothing). The line keeps `-O2`. The patch lands in one commit with the five rows
compiling equal under it, since the gate never drops a row: 0x4470, 0xac810, 0x1412e0, 0x1806b0 and
0x1985d0 were not unswitched in the base, so either an earlier function of their source file spent
the budget (0xac810's case, shown above; the TU is assembled in the base's order, which
docs/FINISHING.md asks for anyway) or the base's source holds no loop-invariant test inside the
loop (a different form of the loop; a check for the worker). Until that commit, a loop copied under
an invariant test is a D42 residual and is not worked at the current compiler; cookbook 773's form
(two loops written in source) is not used for a new function, and 0x5c120 is rechecked under the
patch with one loop. A matched function whose source holds two copies of a loop that the patched
compiler would produce from one is rewritten with one when the patch lands, since the one is the
developer's.

**Trigger to revisit.** A function the patched compiler unswitches where the base does not, with
its whole source file assembled in the base's order and no earlier unswitch to spend the budget;
or a budget that the TU order cannot account for (a refund the base shows, LoopUnswitch.cpp:284).

**Addendum, 2026-11-09 (rounds 90A and 91A).** Three of the five rows were explained by an
earlier unswitch in their source file and fixed by assembling the file in the base's order
(hkResourceHandle.cpp: 0x17ff90's search loop unswitched twice, then 0x1806b0's "cost too high";
the broad phase unit: 0x13e090's gather before 0x1412e0; the vertex buffer utility's file). The
pass's own trace (a debug build of the same patched source, `-debug-only=loop-unswitch`) shows each.
0x4470's spender was outside the function table: three hkClass enum functions the linker discarded,
whose last lines survive as residue at 0x4300, 0x4310 and 0x4320 (D43); written into the file
before 0x4350, their first loop takes the budget and 0x4470's reads "cost too high" as the base
has it. One row remains, 0x1985d0: no residue from 0x19443b to 0x1997b0, no copied loop in the
callees the pass meets first, and the file's thirteen earlier functions (0x194990 to 0x1981e0,
15 KB) have no source yet; the spender is sought as they are written. A fourth way to spend the
budget is read from the source and not yet observed: when LoopUnswitch deletes the loop it works
on, RemoveLoopFromHierarchy clears currentLoop (LoopUnswitch.cpp:1011-1014) and releaseMemory
refunds nothing, so that loop's whole reservation is lost for the rest of the compile. Also under
the patch: 0x5c120's and 0x45c0's two loop paths come from one loop each (cookbook 773's form is
the compiler's), to be rewritten in the switch commit with 0x17ff90, 0xab150 and 0xab4f0 claimed.

## D43. A function the linker discarded is written when the residue shows it (2026-11-09)

**Question.** D13 classes the text between the unwind tables' functions as padding or linker
residue, "never source, never claimed". Round 91A found that the three residue fragments at
0x4300 (13 bytes), 0x4310 (5) and 0x4320 (11) are the last 16-byte lines of three hkClass enum
functions written in the file's own idiom (the enums counted through the parents, an indexed
lookup, a lookup by name): compiled from source, each function's last line equals its fragment
byte for byte (supervisor's check, 2026-11-09, from the object of func_00004350.cpp). The linker
dropped the functions as unreferenced and left those lines. The functions matter: the pass ran on
them before 0x4470 and the first of their loops spent LoopUnswitch's budget (D42).

**Ruling.** A function that the base's text does not keep may be written into its file, with no
row, when a residue fragment equals the compiled function's bytes at the fragment's offset within
its last line and the function's place in the file follows from its address (the fragment's). The
definition carries a comment naming the fragment ("discarded by the linker; residue 0x4300 to
0x430d"). The residue rows stay what D13 says: never claimed; the fragment is evidence, not a
target. A function with no such fragment is not written on the strength of the budget alone: that
would be a steer. Names follow the usual rule (SDK method names unmarked where the class is known,
derived names marked).

**Trigger to revisit.** A residue fragment that two different functions' last lines both equal;
or a written function whose fragment match depends on a form the file's other functions contradict.

**Addendum, 2026-11-09 (rounds 96A and 99A).** The broad phase tree's object is 0x195ee0 to
0x198a70 (D44), not 0x194990 onward: 0x194990 belongs to the convex-convex detector's object with
0x18f430, so it is not the spender. The spender of 0x1985d0's budget is therefore inside the
tree's own object: the base forms of the drafts still open there (0x196720, 0x196190, 0x198030,
0x197610), the destructor 0x195ff0 (its body equal, its emission not yet understood), or a
linkonce function the base's compile emitted and the linker then dropped for another object's
copy, which the trace of our file cannot show when our header's form differs. "Cost too high: N"
in the trace names a loop of N blocks whose quota is zero; from 21 blocks up that is the loop's
own size, not the budget left. The dedicated rounds stop here; the file's drafts return to the
parked rotation, each visit rerunning the trace, and the patch lands when 0x1985d0 reads "cost
too high" under it.

## D44. An object's functions share one CIE in .eh_frame (2026-11-09)

**Question.** Assembling a source file in the base's order (D42, docs/FINISHING.md) needs the
file's boundaries, which rounds 90A to 92A inferred from class names and neighbours, and round 99A
found wrong for the broad phase tree (0x194990 was taken for its first function).

**Evidence.** Every FDE names its CIE by a relative offset; the linker kept each object's CIE
rather than merging the byte-identical copies, so the executable holds 637 distinct CIEs and the
functions whose FDEs share one came from one object. Checked against three files whose bounds
were known from their functions: hkClass.cpp is one CIE from 0x4060 to 0x4a40 (25 functions, the
hkUuid initializer 0x3ed0 before it in another), the vertex buffer utility is exactly 0xaaaf0 to
0xac810 (9), the broad phase tree exactly 0x195ee0 to 0x198a70 (16, so 0x198830, 0x198a20 and
0x198a70 belong to it after 0x1985d0). `tools/eh_objects.py` lists the objects (639 address runs
of the 637 CIEs: two objects' runs are interrupted once by another's) and, with a range, the
object a function belongs to.

**Ruling.** A file assembled in the base's order takes its members from the object the tool
names, every function of the object in address order, and nothing from outside it; a matched
function moved into its object's file keeps its row (retargeted). An object whose functions carry
no file string is named by its class as before, with the derived marker.

**Trigger to revisit.** A function whose FDE's CIE differs from its neighbours' while a file
string or a class ties it to them; or one of the two interrupted runs turning out to be two files.

## D45. The game compiler emits a weak-linkage structor as its own function (2026-11-09)

**Question.** Rounds 103A to 108A matched 248 complete destructors of the game region that are a
five-byte jump to the class's base-object destructor, and five constructors of the same shape,
as free-function stand-ins: upstream 4.0.0 under the game line never emits them (an inline or
instantiated destructor's D1 is replaced by its D2, an explicit instantiation's D1 and D2 share a
D5 COMDAT body, a strong one is an alias). Which rule the base's compiler followed bears on D6.

**Evidence (round 109A's census and tests, the supervisor's patch and gate, 2026-11-09).**

- Every game vtable with functions in slots 0 and 1 (1,868): 507 whose D0 calls the slot-0 body
  (the alias relation; 476 with D0 the next function), 248 whose slot 0 is `jmp X` with D0 calling
  X (X 147 to 2,925 bytes, median 550; 123 store the vtable itself, 125 a base's), 905 whose slot 0
  is a body D0 does not call, 208 a bare ret. No virtual-base shape. The thunks sit in the
  linker's linkonce stretch from 0x1340000 (122 of the 123 own thunks), the aliases below it (497
  of 507). The library region, 3.3's: 29, 14, 95, 87.
- Nine structor cases (strong, inline, explicit instantiation, derived inline, virtual base; a
  small and a big body) compiled under the game flags with 3.3, 3.4.2, 3.5.2, 3.6.2, 3.7.1, 3.8.1,
  3.9.1 and 4.0.0, and 4.0.0's cc1 without -mconstructor-aliases (a109/t/). Strong: every compiler
  aliases D1 to D2. Inline: 3.3 emits D1 as its own function (`jmp D2` when big) with D0 calling
  D2; 3.4.2 and later replace D1 by D2. Explicit instantiation: 3.3 to 3.5.2 the thunk, 3.6.2 and
  later the D5 group. Aliases off: no alias at all, D1 and D2 twin bodies for a strong class, which
  the 507 exclude. Only 3.3's rule gives all three of the base's relations in the base's places.
- One rule in 4.0.0's ItaniumCXXABI.cpp getCodegenToUse (weak-for-linker linkage returns Emit
  before the RAUW and COMDAT cases) reproduces 3.3's shape in all nine cases (a109/t/4p_*) and
  leaves the other cases as 4.0.0 has them; the whole gate, every row of both regions, passes
  under it from an empty object cache (scratchpad d45/gate_structor.log, 5 minutes).

**Ruling.** The game line's compiler is 4.0.0 built from source with the backport
`tools/patches/llvm-4.0.0-structor-01-weak-structor-emitted.patch` (cxx=4.0.0-src in
config/flags.base.txt), D6's generation and flags unchanged. A destructor or constructor the base
holds as a thunk is written as the class's own inline (or instantiated) structor, not as a free
function; the stand-ins of rounds 103A to 108A are rewritten as classes where the class is known,
and the "derived from" comments corrected where the target is the same class's D2. The bytes of
D2 and D0 do not move; only the D1 and C1 rows gain their class symbols.

**Trigger to revisit.** A weak-linkage structor the base holds as one body where the patched
compiler emits two (a RAUW shape in the base); or an alias the base shows for a definition the
patched compiler emits separately.

## D46. The game compiler's X86 backend keeps three pre-3.9 rules (2026-11-09)

**Question.** After D45, three shapes of the game region remained that upstream 4.0.0 never emits:
a bool global shrunk to i1 is loaded with a mask (`mov al, [rip + x]; and al, 1`; `movzx eax, byte
ptr [rip + x]; and eax, 1; cmp eax, 1`), a compare of a byte or a word is done at i32, and a zero-
extended setcc is `sete al; movzx eax, al` where 4.0.0 clears the register first (lib/Target/X86/
X86FixupSetCC.cpp, new in 3.9). Round 113A's five `return field == k` functions and round 112A's
0xb108d0 failed on them.

**Evidence (round 114A, scratchpad a114/; the supervisor's whole gate, d46/).**

- The i1 mask is codegen, not IR: every release from 3.6.2 to 5.0.2 produces the same `load i1`
  of the shrunk static; 3.7.1 and 3.8.1 select the mask (X86InstrCompiler.td, "zextload bool ->
  zextload byte"), 3.6.2 and 3.9.1 onward do not. The base's 32-bit masks are the imm32 forms
  (`25 01 00 00 00`, `81 e2 01 00 00 00`): 3.7.1's patterns, not 3.8.1's imm8 ones. Census: the
  game region's 20 byte globals stored only with constants 0 and 1 and never address-taken are
  loaded at 45 sites, all masked, none bare; the 11,994 `mov al; test al, al` loads are all
  address-taken guards. The i32 compare (X86ISelLowering.cpp EmitCmp, 3.5.2 to 3.8.1; 4.0.0 keeps
  it only for i16 against an immediate): the game region has 15 byte or word compares against a
  nonzero value, all `cmp x, 1` feeding sbb or adc or a misdecode; the library region, whose 3.3
  predates the rule, has 900. FixupSetCC: 1,548 `setcc; movzx` pairs in 775 game functions and no
  xor-before-setcc form but 76 ordinary zeroed registers; the library 234 pairs, none of the form.
- Source forms excluded by bytes: a bitfield (read-modify-write stores where the base stores a
  plain byte), a written `& 1` (selects `83 e0 01`, never the base's imm32), a flag (none restores
  either pattern).
- Three one-rule backports (X86InstrCompiler.td with 3.7.1's patterns; EmitCmp with 3.8.1's
  condition; createX86FixupSetCC left out of the pipeline), applied together: 0xb108d0 and the five
  setcc functions compile equal; the two bool-reading drafts move their first difference past the
  flag test; every one of the 1,471 matched game rows is equal per function (a114/sw/), and the
  whole gate passes from an empty object cache (d46/gate_three.log, 6m52s).

**Ruling.** The three patches join the structor backport in the 4.0.0 source build of the game
line (tools/patches/llvm-4.0.0-i1load-01, -cmp-01, -setcc-01). Each is one instruction form or
one pass, narrower than any source form, with the source alternatives excluded above: a compiler
change may never stand in for a source shape (the ICO lesson, 2026-11-09).

**Trigger to revisit.** A shrunk bool the base loads bare; a byte compare against a nonzero value
the base does at 8 bits outside the sbb/adc forms; a `xor; cmp; setcc` the base emits where a
register was not otherwise zeroed; or 0x5a8dbb4 (masked, yet stored by setne) and the 15 `cmp
byte, 0` globals, left as a probe: whether those are struct members or wider-stored neighbours.

## D47. Two more pre-3.8 rules of the game compiler's X86 backend: no shrink-wrapping, an `or` is an address only with a constant (2026-11-10)

**Question.** After D46, round 125A met two shapes upstream 4.0.0 never emits. Five small
functions (0xd8ff10, 0xd8ff30, 0x582360, 0x582380, 0xc871e0) set up their frame at entry where
4.0.0 moves `push rbp; mov rbp, rsp` below an early test (lib/CodeGen/ShrinkWrap.cpp, enabled for
X86 by X86FrameLowering::enableShrinkWrapping). 0x12fd220 keeps two `or` instructions of operands
with no common bits where 4.0.0 selects one `lea` (X86ISelDAGToDAG.cpp, the `or` case of the
address matcher).

**Evidence (round 126A, scratchpad a126/; the supervisor's whole gate).**

- Shrink-wrapping. Census: of the game region's 16,341 functions 12,521 push rbp, every one as its
  first instruction; 12,563 push a callee-saved register, none after a branch or an exit; the 78
  functions whose early exit needs no frame (a test before any stack use, branching to `pop rbp;
  ret`: the shape 4.0.0 shrink-wraps) all keep the frame at entry. The library region (3.3):
  2,101 and 15, likewise. History: ShrinkWrap.cpp exists in 3.7.1 but is off (lib/CodeGen/
  Passes.cpp:220, `EnableShrinkWrap(false)`); upstream r255175 (5d2f7cfd44db, 2015-12-09, "[X86]
  Enable shrink-wrapping by default") turned it on, first released in 3.8.0. 0xd8ff10's source
  compiled with each release: 3.6.2 and 3.7.1 set the frame up at entry, 3.8.1 to 5.0.2 below the
  test.
- The `or`. Census: the game region has 44 `or r, r` of bit-disjoint operands beside an `or $C` on
  the same register (25 functions) and 21 with an operand shifted by 1 to 3, and no `lea` with a
  displacement over two bit-disjoint registers; the 68 two-register `lea`s of disjoint operands
  without a displacement are the `or_is_add` pattern every release has (3.3's
  X86InstrCompiler.td:1189). History: 3.7.1 matches only "X | C" as "X + C" (X86ISelDAGToDAG.cpp:
  1268-1280); upstream r252515 (32538d681177, 2015-11-09, "[x86] try harder to match bitwise 'or'
  into an LEA", D13956) added the haveNoCommonBitsSet test, first released in 3.8.0. 0xbc4a68's
  expression compiles to the base's `lea (r,r); and; and; shl; or; or $0x406` under 3.7.1 and
  under the backport, to one `lea` under 4.0.0.
- Source forms excluded by bytes. Shrink-wrapping: a local read before the test, an explicit early
  return and a result variable are each still shrink-wrapped by 4.0.0; a form that needs the frame
  on the early path adds bytes the base does not have. The `or`: written as `+`, `^` or `|=` the
  expression still gives 4.0.0's `lea`; the masks and shifts are in the base's bytes, so any source
  for those sites has operands the compiler proves disjoint. The hidden option
  `-enable-shrink-wrap=false` gives the same objects as the first backport; the backport was taken
  because it touches X86 alone and leaves the game line's flags as they are.
- Two one-rule backports (enableShrinkWrapping returns false; the `or` case restored to 3.7.1's
  text), each alone over the 2,909 matched game rows in 2,615 files: no row changes (a126/sw/).
  The five functions compile equal under the first; 0x12fd220 keeps its two `or`s under the second
  and still differs in the order of an and/shl pair (list-ilp), so it is not claimed.

**Ruling.** Both patches join the game line's 4.0.0 source build (tools/patches/
llvm-4.0.0-shrinkwrap-01-no-x86-shrink-wrap.patch, llvm-4.0.0-orlea-01-or-constant-only.patch):
six backports with D45's and D46's. Each is one pass or one matcher case, narrower than any
source form, with the source alternatives excluded above. With D46's three, five X86 rules of the
game compiler now read as 3.7's (the imm32 mask patterns, no FixupSetCC, no shrink-wrapping, the
constant-only `or`; the i32 compare is 3.5's to 3.8's).

**Trigger to revisit.** A game function whose frame setup follows a conditional branch; a `lea`
with a displacement over two bit-disjoint registers in the game region; or a matched row that
needs either 3.8 behaviour.

## D48. The game compiler's MachineSink is 3.9's: no edge split by branch probability, no sinking of subreg_to_reg (2026-11-10)

**Question.** Rounds 123A and 127A met functions whose base keeps a return constant in the entry
block before the test, on one shared `ret` (`mov eax, 1; je ret` in 0xc11e40; `xor eax, eax; test;
je` in 0x13c8870), where the game line moves the constant onto a block of its own behind the
branch. Round 123A filed it as a missing source form.

**Evidence (round 128A, scratchpad a128/; the supervisor's whole gate).**

- Two rules of lib/CodeGen/MachineSink, both first released in 4.0.0, make the split. Upstream
  r284757 (f03f51555a63, 2016-10-20, "Using branch probability to guide critical edge splitting",
  D24818) breaks a critical edge for a cheap instruction when the edge's probability is at or
  under 40% (MachineSink.cpp:400-402; a null or `== 0` test gives 37.5%). Upstream r278466
  (7e103d92cc2b, 2016-08-12, D23210) made TargetInstrInfo::shouldSink return true, where up to
  3.9.1 it refused insert_subreg, subreg_to_reg and reg_sequence; a 64-bit zero is a
  subreg_to_reg, not as cheap as a move, so once it may be sunk its edge is broken at any
  probability. 3.9.1's MachineSink.cpp differs from 4.0.0's by the probability test and edits
  without effect (a128/hist/ms_391_400.diff).
- The releases: 0x13c8870's and 0xc11e40's sources compile to the base's bytes under the prebuilt
  3.6.2, 3.7.1, 3.8.1 and 3.9.1 and split under 4.0.0 and 5.0.2 (a128/hist/rel/summary.txt).
- Census over the game region, straight-line liveness from both successors: 15,871 sites keep a
  cheap definition before a branch although it is live on one critical successor only and 4.0.0's
  rules would split the edge (467 in the library, the 3.3 control); at a shared `ret`, 34 sites in
  28 functions. 4.0.0's form at a return (one eax constant and `ret` on a single conditional
  edge): 11 sites in 9 functions, each read: tail calls on the other path, bool returns (an 8-bit
  copy, which the earlier releases split too), switch defaults and even compares; five of them are
  matched rows and stay equal under both backports. The script's wider count of split-looking
  blocks (751) is register copies at joins of several predecessors; twenty read, none the shape.
  No counterexample found.
- Source forms excluded by bytes: a result local, a ternary and the arms swapped, on both
  functions, six compiles: all still split under the unpatched line.
- Two one-rule backports (the probability test removed; shouldSink restored to 3.9.1's text). Over
  the 2,929 matched game rows in 2,634 files no object changes under the first or under both.
  0xc11e40 and 0x7790c0 compile equal under the first alone, 0x13c8870 needs both. The hidden
  option `-machine-sink-split-probability-threshold=0` gives the first backport's objects; no
  option gives the second, so both are patches (D47's reasons).

**Ruling.** Both patches join the game line's 4.0.0 source build (tools/patches/
llvm-4.0.0-msinksplit-01-no-probability-split.patch, llvm-4.0.0-msinksubreg-01-subreg-not-sunk.
patch): eight backports with D45's, D46's and D47's. One decision, two patches, because they are
two upstream commits and one function needs both. Round 123A's "shared return" class is closed as
this rule, not a source form. These two are target-independent code generation of late 2016,
where D46's and D47's are X86 rules of 3.7 and 3.8; D6's fingerprints (the trap pair, the merged
constant stores) remain 4.0.0's. Whether a single upstream state holds the whole region is D6's
open question and the next investigation's (every matched row and draft under each prebuilt
release, failures classified).

**Trigger to revisit.** A game function with a cheap constant alone on a block reached by one
conditional edge where neither a tail call, an 8-bit copy nor a switch explains it; or a matched
row that needs either 4.0.0 rule.
