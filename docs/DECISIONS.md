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

D1 to D44 are in `docs/DECISIONS-D1-D44.md`, unchanged; this file continues from D45.

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

## D49. The game compiler's CodeGenPrepare keeps the load test: a select on a compare of a single-use load is a branch (2026-11-10)

**Question.** Three drafts (0x5894e0, 0x92ce60, 0x139eae0) differ from the base in one shape: the
base branches over one `mov` where the game line selects a `cmov`, and each compare has a memory
operand. Round 129A found that the prebuilt 3.6.2, 3.7.1 and 3.8.1 compile all three to the
base's bytes and 3.9.1 and later do not. They had been filed under FoldTwoEntryPHINode and round
123A's comparison class.

**Evidence (rounds 129A, 130A, 131A; scratch a129/, a130/, a131/ under
.claude/handoff/scratch-archive/; the supervisor's whole gate).**

- The rule: isFormingBranchFromSelectProfitable (lib/CodeGen/CodeGenPrepare.cpp) turned a select
  into a branch when its compare has one use and an operand that is a load with one use, "to
  avoid stalls on a load from memory". Upstream r261809 (161dc1c60532, 2016-02-25,
  "[CodeGenPrepare] Remove load-based heuristic", D16836) removed that test and nothing else;
  3.8.1's function text equals the text of r261809's parent (a130/hist/), and 3.3 has the same
  test (lib/Transforms/Scalar/CodeGenPrepare.cpp:1805). First release without it: 3.9.0.
- Census over the game region (a130/cen4/): a compare with a folded memory operand feeding one
  select is a jump over one `mov` at 302 sites and a single `cmov` at 18; a masked memory test
  (an `and` of the load, not a LoadInst operand) is 0 branches against 45 `cmov`s; register
  compares are 1,583 against 9,637. Twenty of the 302 read. The 18: 14 select chains, a reused
  compare, a sext, a combined condition, each a form the test itself leaves a select (the
  reconstructions give the same under 3.8.1 and under the backport), and 0x131f599.
- 0x131f599, the candidate counterexample, sits in FUN_0131f450 beside a heuristic branch. Round
  131A wrote the function (CreateRasterizerState of JsRasterizerState.cpp by its assert strings;
  a131/s5.cpp): under the backport the site compiles to the base's `cmp dword ptr [rax + 0x30],
  2; cmove` and the bool site at +0x50 to the base's branch; under the installed line both are
  `cmov`. In the IR at CodeGenPrepare the site's compare has two uses (two identical selects made
  by the last SimplifyCFG's store speculation, one for the store and one for the value read
  again), so the test does not fire; the bool's has one. The source form is a constructor that
  initialises the register and a creator that sets it through the member (a131, probe_one.ll and
  probe_two.ll). The rule holds there as upstream had it. The function as a whole is not matched
  (five residuals away from the site, linkage among them).
- Source forms excluded by bytes: a result variable, the ternary and the arms swapped on each of
  the three drafts, nine compiles: all `cmov` under the installed line. A choice between `if` and
  `?:` cannot produce a split that follows the operand's kind (load 302 to 18, masked load 0 to
  45).
- One hunk restores the test in 4.0.0's function. Over the 2,932 matched game rows no object
  changes; the three drafts compile equal; no hidden option gives the same objects.

**Ruling.** The patch joins the game line's 4.0.0 source build (tools/patches/
llvm-4.0.0-cgpload-01-load-compare-select-to-branch.patch): nine backports. FoldTwoEntryPHINode
(0x5894e0) and the 1/-1 comparison class are closed as this rule where the compare reads memory.

**Trigger to revisit.** A game site where a compare with one use and a single-use load operand
feeds a `cmov`; or FUN_0131f450 matched whole with a source that contradicts the reading above.

## D50. The game region is one module; the libraries are the other (2026-11-11)

**Question.** The game region reaches its own data with direct operands and stores its own
vptrs with the +0x10 folded into the `lea`, where a translation unit compiled alone under the
game line reaches an object another file defines through the GOT (D10's relaxed `lea` and a
load). By round 132B about 800 small functions waited on it: direct reads of shared objects,
folded vptr stores, and the deleting destructors emitted with them.

**Evidence (rounds 124A, 133A, 134A; scratch a124/, a133/, a134/ under
.claude/handoff/scratch-archive/; the gate).**

- The base, by census of every RIP-relative operand by the region of its instruction
  (tools/module_boundary.py, 440,278 operands): the game reaches 53,033 of its data addresses
  only directly and 4,295 of its vptr stores are folded; it reaches the libraries' objects only
  through the GOT forms (24 `lea` sites, 3 library vtables as `lea; add 0x10`) and never
  directly; all 21,974 thread-local accesses are general-dynamic relaxed by the linker (D23),
  none local-dynamic, local-exec or compiled initial-exec; the game region is one CIE run in
  .eh_frame (0x1afa60 to 0x14a8fa0), where the libraries have 637.
- No flag makes a declaration local: an extern object is a GOT load under -fPIC, -fPIE,
  hidden and protected visibility alike (clang gives a declaration no visibility unless it is
  explicit, CodeGenModule.cpp:1039-1041). A definition is local under protected visibility
  (4.0.0 TargetMachine.cpp:137). PIE is excluded by the thread-locals (a definition goes
  local-exec), hidden by the three library vtables and the thread-local model.
- Round 133A built the game's sources as one module in scratch, four ways. The form taken:
  every file to unoptimised bitcode by the front end at -O2, one link, a generated definition
  for every game-side object the sources declare and no file defines yet, one -O2 pipeline and
  code generation. All 2,935 matched game rows equal; the nine linkage witnesses, written as
  plain externs, equal; a library object, a library thread-local, a library vtable and the
  imports keep their GOT and PLT forms. A second optimisation run over per-file optimised
  bitcode loses 8 rows (GlobalOpt deletes stores the unwritten part of the module reads) and
  was dropped. The per-file variant with stand-ins holds the same rows and witnesses but cannot
  give two shapes the base has, which need another file's body: a destructor that keeps only
  its vptr store because a member's empty destructor in another file was inlined (0xcef1f0's
  shape), and a thunk whose callee always returns 1 (`call F; mov eax, 1`, IPSCCP over an exact
  definition, 0x1374750's shape).
- The user, 2026-11-10: the game as one module is accepted, the libraries being the other
  module; a source statement that emits nothing is wrong.

**Ruling.** The gate builds src/game/ as one module (tools/game_module.py, tools/gen_ninja.py,
tools/compile_cpp.sh): each unit to bitcode with `-Xclang -disable-llvm-optzns`; llvm-link
(built from the game compiler's own source, installed beside it in
tools/cc/llvm-4.0.0-src-tools/ by tools/build_llvm.sh); stand-in definitions generated into the
build directory, protected, writable, zero-initialised, with the declared type and alignment,
for the objects config/modules.base.txt gives the game; one -O2 and code generation to
build/base/game/module.o. The game line gains `-fvisibility=protected -ffunction-sections`
(the second so that a call between two functions of the one object keeps its relocation for
the gate). config/modules.base.txt is written by tools/module_boundary.py from the base and
checked by `--check`: one cut per data area, with the exceptions carved out (the CRT's objects,
0x16c82b0 and 0x16c9060, the libraries' three thread-locals, and every object the game reaches
through a RELATIVE GOT slot, 0x14b2060 among them). Nothing is added to a source file. A name
two game files define, and a thread-local a game file defines, are refused by the build.
tools/quick_diff.sh compiles a module of the one file and its stand-ins by default and the
whole module with `--module`; a difference between the two for a function is cross-file
optimisation and is reported with `--both`. D17 stands for an object one file owns. First rows
under it: 0x1373a50, 0xb10d80, 0x13320a0, 0xe030d0, 0x37aa70.

**What it is not.** The stand-ins are the gate's, like the bytes it takes from the base for
unwritten functions (D7): they hold no content, and an optimisation that needs an object's
content (a const table folded) is not reproduced until that object is claimed (D8, D18). The
module is incomplete: a file-local object is judged on the functions written so far, as before.
A thread-local stand-in is emitted at default visibility because 4.0.0 gives a protected
thread-local definition the local-dynamic model where the base has general-dynamic
(TargetMachine.cpp:172; 3.6.2's rule at TargetMachine.cpp:107-117 keeps general-dynamic): the
one-rule backport is open, to be ruled with its census before any game file defines one.

**Trigger to revisit.** A game access to a library object in direct form, or to a game object
through the GOT, that the boundary gets wrong; a matched row whose bytes differ between the
single-file module and the whole module for a reason other than another file's body; a link of
the module that merges two different bodies under one name.

**Addendum, 2026-11-11 (round 156C).** The module is not internalised: it is one module whose
functions have external linkage unless the source says `static`. Evidence over the region
(scratch c156/): 86 directly-called functions whose address is never taken keep a value in rax
that no caller reads, and 6 one in xmm0 (six read by hand: a `mov eax, 1` or `mov al, 1` before
the epilogue, callers that overwrite rax); a function with local linkage would have lost that
return (SCCP.cpp:1676-1680, DeadArgumentElimination.cpp:501 of the compiler's source). The 12
game thread-locals are general-dynamic at all 20,990 game sites and the executable exports
nothing that would have kept them external. An internal rewrite of the gate's module, tried in
scratch, deletes 1,551 matched functions whose callers are unwritten and changes 128. What had
looked like a mark of internalisation is not one: an unused argument is dropped at the call
sites of ANY function whose exact definition the module holds (DeadArgumentElimination.cpp:
242-278), so FUN_00c831d0's first argument is unset at 378 of its 380 call sites once its body
is written. A dropped return value does need local linkage: the nine accessors FUN_00a64740 to
FUN_00a65bd0 are `static` in the source, and a file of src/game/ may hold a static with its
callers from far-apart addresses (the game is one object in the base; a file boundary there is
the tree's own).

## D51. Four more rules of the game compiler: protected thread-locals stay general-dynamic, the scheduler's operand order, the switch condition's width, ReassociateOps' operand order (2026-11-11)

**Question.** D50 left a thread-local stand-in at default visibility because 4.0.0 gives a
protected thread-local definition the local-dynamic model. Rounds 132B and 135B met drafts that
compile to the base's bytes under the prebuilt 3.8.1 and not under 3.9.1 or later.

**Evidence (rounds 138B, 141B, 145B; scratch b138/, b141/, b145/ under
.claude/handoff/scratch-archive/; each patch built alone on the nine-backport source, then
together; the supervisor's whole gate).**

- Thread-locals. Upstream r273921 (8121becac311, 2016-06-27, "Teach shouldAssumeDSOLocal about
  tls"), first in 3.9.0, made getTLSModel treat any non-default visibility as local. The base has
  general-dynamic at all 21,974 thread-local sites and local-dynamic at none (D23, round 124A). A
  protected `__thread` definition is TLSGD under 3.8.1 and under the patch, TLSLD under 3.9.1 and
  the unpatched line. With the patch and protected thread-local stand-ins FUN_00d6a930 is equal
  and every game row holds.
- The scheduling graph. Upstream r269076 (a356bb7fa46d, 2016-05-10), first in 3.9.0, makes
  ScheduleDAGInstrs::buildSchedGraph visit an instruction's defs before its uses; 3.8 took the
  operands in list order, which gives the post-RA list scheduler other dependence edges. The rule
  has no byte form to count; the sweep stands for the census: no matched row changes, and
  0xbe5650, 0x13c8720 and (in the whole module) 0xd41700 compile equal. Post-RA scheduling itself
  runs in the base: turning it off breaks 225 matched rows.
- The switch condition. Upstream r274233 (7c6eab577743, 2016-06-30, D12965), first in 3.9.0, lets
  InstCombine narrow a switch condition to any width; 3.8 narrowed only to a width at least the
  largest legal integer. Census: jump tables indexed by a zero-extended byte less a nonzero
  lowest case are 2 at i32 (0xed8bf8, 0x1304664), a form the unpatched line cannot emit, and 5 in
  i8, each the form an if chain on a char gives under 3.8.1 too. No matched row changes. No draft
  becomes equal by this patch alone (0x12fd360 also needs the layout rule below).
- ReassociateOps. Upstream r262148 (982224cfb8de, 2016-02-27), first in 3.9.0, builds
  (op y, (op x, c1)) as (op (op y, x), c1) where 3.8 built (op (op x, y), c1). Census: the
  member-function pointer's vtable slot is addressed with the pointer's offset as base and the
  vtable as index at 49 sites of the game region and in the other order at none. No matched row
  changes; 0xd332b0 compiles equal.
- Together: all 3,437 matched game rows equal in the module and per file; six functions of the
  module change, all drafts.
- Source forms: none of the four has one (a TLS model, a scheduling order, an integer width
  chosen by the optimizer, an operand order inside the DAG combiner are not spelled in C++); for
  the switch, four spellings were compiled and none gives the base's width.

**Ruling.** Four patches join the game line's 4.0.0 source build (tools/patches/
llvm-4.0.0-tlsprot-01, -schedops-01, -switchwidth-01, -reassoc-01): thirteen backports. The
game module's thread-local stand-ins become protected like every other and a game file may
define a thread-local (tools/game_module.py; D50's exception is closed).

**Held, not adopted.** (1) r277187's forward check in MachineBlockPlacement (mbpprob-01): it makes
0x12fd360 equal together with the switch patch and changes no matched row, but it has one
witness, no byte form to census, and six other layout drafts (0x13985e0, 0x13999c0, 0x139a080,
0x845560, 0x1395c30, 0x1395e40) are unchanged by it: it waits for a second witness. (2) No tail
duplication in MachineBlockPlacement (r283934): 0xebbb70 says the base lacks it, 25 guard-and-
latch pairs look like its copies, and 10 pairs of 3 to 5 common instructions, which it cannot
copy and tail merging should merge, stay unmerged by a mechanism not found: conflicting
evidence, held. (3) The min/max canonicalization (r287585): it breaks a matched row and its
witness stays unequal for two more reasons.

**Trigger to revisit.** A game thread-local access in the local-dynamic form; a matched row
that needs 3.9's scheduling order, switch width or operand order; the member-pointer address
with the vtable as base.

## D52. std::function and its lambdas are written as the developer wrote them; an instantiation's vtable is inferred from its claimed slots (2026-11-11)

**Question.** About 500 small functions of the game region are the virtual slots of the standard
library's function implementation objects, one eight-slot vtable per lambda held in a
`std::function`; 11 large functions create them. Rounds 135B to 146C wrote the slots as free
functions on hand-declared classes with one derived vtable row each (D14): 340 rows that way.
That is not the source: the developer wrote a lambda where a `std::function` was wanted, and the
library's header did the rest.

**Evidence (rounds 147A, 148A; scratch a147/, a148/ under .claude/handoff/scratch-archive/).**

- The executable imports `_ZSt19_Xbad_function_callv` (the throw of an empty function object),
  `_ZSt14_Xlength_errorPKc` and `_ZSt11_Xbad_allocv`, each name verified by its NID: the game uses
  the SDK library's `std::function`.
- The data model, from the bytes: 65 implementation vtables, every one of 8 slots and no other
  count: copy, move, call (arguments by reference), target type (returns 0: no type info),
  destroy and free, the complete and deleting destructors, the callable's address. A function
  object is 0x20 bytes of space and the implementation pointer at +0x20, null when empty; the
  implementation is built in the space up to 0x20 bytes and on the heap above; the destructor is
  `if (impl) impl->slot4(impl != &space)`, the call tests the pointer and calls
  `_Xbad_function_call`.
- A header written from those bytes (src/include/functional, with src/include/utility and
  src/include/new; nothing read or copied from any vendor's library) and three lambdas written
  in their creating functions compile slots 2 to 7 of their vtables to the base's bytes (147A);
  13 vtables are migrated in the tree with every re-pointed row equal in the gate (148A). Slots 0
  and 1 differ in one thing, the null test after operator new (a compiler rule under
  investigation, round 149B's opnew-01), and are not claimed until it is ruled.
- Three facts of the source the bytes force: the callable sits in a holder of its own (an empty
  lambda's copy is one byte); the implementation holds an allocator with a user-provided copy
  constructor and destructor; the implementation is copied by its implicit copy constructor.
- Folding: 4 of the 65 vtables have slots the linker folded with other functions; the other 61
  keep byte-identical slots apart. D15's one name per address covers the folded ones.

**Ruling.** (1) src/include/functional is the tree's `<functional>`: `std::function`,
`std::allocator` and the `_X` helpers are facts (the imports); every internal name is ours and
carries the derived-name marker. (2) A lambda is written as a lambda in the function that
creates it; that function may stand in the tree as an unclaimed draft with a NONMATCHING note
while the lambda's functions are claimed, each proven on its own bytes. (3) A row for an
instantiation is `FUN_<addr> <unit> <the compiler's mangled symbol>`. (4) An instantiation's
vtable takes no hand-made row: tools/base_elf.py resolves it as the one base vtable that holds
every claimed row of the instantiation in its slot, once slot 0's row is claimed and that
function stores the vtable's address point; until then nothing may reference the vtable, and
`tools/vtable_names.py --check` lists it as pending and fails on any disagreement of slots.
(5) tools/rename_rows.py rewrites the symbol column when an enclosing function is renamed or a
unit's lambdas are renumbered, accepting only the one assignment under which every row compares
equal. (6) A slot is claimed only after `tools/quick_diff.sh --both`: the whole module is the
measure (two single-file results in round 148A were wrong against it). (7) The 340 rows of the
earlier form and their D14 rows are migrated vtable by vtable as each creating function's file
is written; none is added in the old form.

**Trigger to revisit.** An implementation vtable with a slot count other than eight; a function
object whose layout contradicts the header; a vtable two instantiations both claim.

## D53. Four more rules of the game compiler: operator new's result, a new-expression's alignment, DSE's trim, X86FixupBWInsts (2026-11-11)

**Question.** The copy and move slots of the std::function implementation objects (D52) keep a
null test after operator new that the game line deletes; rounds 146C and 147A met it
independently, and round 146C met two more shapes: an unaligned zeroing store right after
operator new where the line stores aligned, and a byte load in a loop kept as `mov al` where
the line widens it.

**Evidence (rounds 147A, 149B, 151B; scratch a147/, b149/, b151/ under
.claude/handoff/scratch-archive/; each patch built alone, then together; the supervisor's
whole gate).**

- Operator new. Upstream r256787 (2016-01-04, first in 3.8) replaced isKnownNonNull's test for
  an operator new call that may be the builtin (a new-expression) with a nonnull attribute on
  the declaration, so every call loses its null test. Measured on a probe: 3.7.1 keeps the test
  after a direct call and folds it after a new-expression; 3.8.1 and 4.0.0 fold both; the patch
  gives 3.7.1's result. Census: `test rax, rax` follows 156 calls of `_Znwm` in the game region,
  every one branching to `_Xbad_alloc` (130 of them std::function's copy and move slots), a form
  the unpatched line cannot emit; 2,110 calls are untested. The nothrow forms are not imported.
  No matched row changes; the three examples' slots 0 and 1 compile equal.
- A new-expression's alignment. Upstream r283789 (2016-10-10, first in clang 4.0) takes the
  storage of a global operator new as aligned to min(16, the type's size). Census: 142 call
  sites store a zeroed vector register at offset 0 of the result, all unaligned, none aligned;
  every one of the 34 zeroed aligned stores after a call lands in an object whose size is a
  multiple of 16 (vector members, aligned by their type).
- DeadStoreElimination. Upstream r267197 (2016-04-22, first in 3.9) shortens a memset at its
  start; 3.8 at its end only. Census: 32 zeroing 16-byte stores are rewritten in their first 8
  bytes at once, which the trim would have cut; the search for a zeroing run the base does
  shorten at its start found 47 candidates, each explained by a constructor storing fields one
  by one. Its limit, stated: where a memset covers exactly the fields the two give the same
  bytes, so the search can only fail to find a counterexample. Alone the patch changes no
  function of the module; with the alignment patch 0x137c3e0 compiles equal (it needs both).
- X86FixupBWInsts. The pass was added off in r260572 and turned on in r265830 (2016-04-08), both
  first in 3.9. Census by the pass's own conditions (control flow, natural loops and forward
  liveness rebuilt from the bytes): 802 `mov r8, m8` lie in an innermost loop with the 32-bit
  register dead after the load, and 1,004 `mov r16, r16` have a dead upper half: sites the pass
  rewrites. A sample of 40 byte loads read: 35 provably meet the conditions, 4 undecided (an
  argument register reaching a call), 1 in an outer loop (the pass skips it), none live. The
  hidden option gives the same module as the patch. No matched row changes; 0x47de10 compiles
  equal.
- Together with every earlier backport: all 3,523 matched game rows equal.
- Source forms: none of the four has one (a null test the source writes is kept or deleted by
  the optimizer; an alignment the front end assumes; a store the optimizer trims; a move the
  back end widens).

**Ruling.** Four patches join the game line's 4.0.0 source build (tools/patches/
llvm-4.0.0-opnew-01, -newalign-01, -dsebegin-01, -fixupbw-01): seventeen backports.

**Held, not adopted.** SimplifyCFG's sinking through an end block with a conditional arc
(r280364, 2016-09-01, first in 4.0; sinkcond-01): it makes 0xf170d0 equal with every row equal
and keeps r279460's sinking that the matched 0x1393600 needs, but its byte census is not done.
**Not a compiler rule.** The order of a switch's compares follows the order of the arms in the
source (the fall-through rearrangement after the probability sort, SelectionDAGBuilder.cpp:8970;
every release from 3.6.2 to 9.0.0 agrees): 0x92ce20 is equal with `default:` written first.

**Trigger to revisit.** A game call of operator new whose null test the source must have and
the base lacks; an aligned zeroing store at offset 0 of a new's result in an object not a
multiple of 16; a zeroing run the base shortens at its start that field stores do not explain;
a `movzx r32, m8` in an innermost loop that only the pass makes.

## D54. SimplifyCFG sinks through two unconditional arcs only; D26's nop on the game line (2026-11-11)

**Question.** Two things. (1) Drafts of rounds 143B, 144A and 157A keep, in the base, a store at
the end of each of two arms (`mov [x], 1` and `mov [x], 2`) where the game line stores once in a
block of its own, the immediate chosen by a phi. (2) D26 (2026-10-27) ruled that the PS4 compiler
follows every call to `__stack_chk_fail` with one `nop` and patched the library line; the game
line was left for the day it was a source build (D45) and was never patched: a game function with
a stack canary ended one byte short of the base.

**Evidence (rounds 151B, 154B, 159C; scratch b151/, b154/, sspnop/ under
.claude/handoff/scratch-archive/; the supervisor's whole gate).**

- Sinking. Upstream r279460 (2016-08-22) rewrote SimplifyCFG's SinkThenElseCodeToEnd to sink when
  the instructions differ in an operand, through a phi; the base has it (D6's addendum: the
  matched 0x1393600). Upstream r280364 (88cad7e5cf, 2016-09-01, "Handle tail-sinking of more than
  2 incoming branches", first in 4.0) lifted its restriction to an end block with exactly two
  unconditional predecessors, splitting the unconditional arcs into a `.sink.split` block when a
  conditional arc also enters. Census, control flow rebuilt from the bytes: 104 joins of the game
  region entered by a conditional arc keep two stores of different immediates at the arm ends,
  which r280364 would sink; 107 more with three or more such arms and no conditional arc, its
  other half, also unsunk. The split form with an immediate in every arm occurs once (0x69600a in
  FUN_00691910: two stores merged into one 64-bit immediate), where `x = c ? A : B;` then a store
  gives it with no sinking; the other 176 split-looking sites store a loaded or computed value,
  which a ternary or a shared tail gives. With the patch 0xf170d0 and the call slots 0x8b0700,
  0x8b0eb0 and 0x8afc90 compile equal and no matched row changes.
- The nop. D26's census stands: 5,981 of 5,981 calls of the stub in the game region are followed
  by 0x90, 5,899 game functions end with it. A probe under the unpatched game line ends at the
  call. In 4.0 the failure call is a libcall of the stack protector's lowering (an external
  symbol), where 3.3 called the declared function: the first port of the library's hunk tested a
  global only and emitted nothing (found by the probe on the installed compiler before anything
  was committed); the patch tests both. With it the probe ends `call; nop` and 0x1354ee0 compiles
  equal. No matched game row carried a canary, so none changes.
- Source forms: for the sinking, the arms' operand order was corrected first (`yes == selected`,
  as the compare's operands show) and the two stores remained sunk under the unpatched line in
  every arm order; the nop has none.

**Ruling.** Two patches join the game line's 4.0.0 source build (tools/patches/
llvm-4.0.0-sinkcond-01-two-unconditional-arcs.patch, llvm-4.0.0-sspnop-01-stack-chk-fail-nop.
patch): nineteen backports. The second executes D26 for the game line.

**Trigger to revisit.** A game join entered by a conditional arc where two arms' stores of
different immediates are sunk into a block of their own and no ternary explains it; a call of
`__stack_chk_fail` not followed by the nop.

## D55. The game line stores stack arguments into a reserved call frame: X86CallFrameOptimization off (2026-11-11)

**Question.** Round 173C's draft 0x98eb90 passes three arguments on the stack. The base reserves
the frame (`sub rsp, 0x20`) and stores to `[rsp]`; the installed game compiler pushes them
(`X86CallFrameOptimization`, lib/Target/X86/X86CallFrameOptimization.cpp of 4.0.0). No source
form chooses between a push and a store of an outgoing argument.

**Evidence, over the region.** (1) The base: inside the 19,735 functions of
`config/functions.base.txt`, the game region holds no push of an immediate and no push of a
memory operand (the library region holds 18; every other such push in the disassembly, 6,754,
lies outside any function, in data). (2) The build: the gate's game module compiled by the
installed compiler holds 8 such pushes. (3) With `-mllvm -no-x86-call-frame-opt` (the pass's own
upstream option, line 42 of that file) the module sweep is identical row for row and draft for
draft to the sweep without it (3,822 rows and 178 drafts of round 176B's lists), so no matched
row depends on the pass; 0x98eb90's frame becomes the base's. (4) The prebuilt 3.8.1 release
stores, 3.9.1 and 4.0.0 push (round 173C's probe): the base agrees with the older behaviour, as
in D47, D48 and D54.

**Decision.** `-mllvm -no-x86-call-frame-opt` on the `src/game/` line of
`config/flags.base.txt`. A per-prefix flag, not a patch: the option is upstream's and turns off
exactly the pass in question. The library line (3.3) has no such pass for x86-64 and is not
changed.

**Not shown.** Pushes of a register as an outgoing argument were not counted separately from
prologue pushes. The upstream revision that enabled the pass for x86-64 between 3.8.1 and 3.9.1
was not identified.

**Trigger to revisit.** A game function of the base that pushes an outgoing argument.

## D56. A compiler-named internal function is claimed under its unit's own spelling (2026-11-11)

**Question.** The gate builds the game as one module (D50). Ten units define
`__cxx_global_array_dtor`, the name clang gives an array's destroy helper
(lib/CodeGen/CGDeclCXX.cpp, generateDestroyHelper, of 4.0.0); the link renames all but one by a
counter over the whole link (`.38` to `.46` for the leaf units' helpers in the module object),
and `tools/match_check.py` refused a row on such a name. The source cannot rename it.

**Decision.** A row for a compiler-given internal function (`game_module.COMPILER_LOCAL`) names
it as its unit does: the symbol in the unit's own IR and single-file object, which depends on
that unit alone (clang numbers `.N` inside the unit). The gate maps it to the module's symbol by
two facts the unit's IR and the module object both state
(`match_check.compiler_local_aliases`): what it reaches (the unit's own uniquely named internal
objects, a non-empty set equal on both sides) and who reaches it (every stably named function
of the unit that references it references the candidate). Exactly one candidate must satisfy
both and no other compiler-named function of the unit may reach the same set; otherwise the row
is refused with the fact that failed. `tools/layout_link.py` places the row under the proven
symbol and resolves the owner's reference through it.

**Evidence.** Round 177A: every one of the 23 helpers claimed has one proven candidate; with two
aliases swapped a helper compares 16 of 16 bytes equal but its target fails (the base refers to
0x581ea90, the source to 0x581eaa0) and the owner's reference resolves to the wrong row; the
gate's row count was 6,698 before and after the tool change; a developer-named colliding static
(`_ZL11_mm_set1_psf`) is still refused.

**Excluded.** A module suffix written by hand in the row (it changes when a unit is added);
renaming internal names in the bitcode before the link (rewriting the compiler's output); the
order of the owner's references alone (order is not a proof); the same path for developer-named
statics (D50's addendum: the source can name them).

**Extension (round 181A).** `COMPILER_LOCAL` also covers `__cxx_global_var_init[.N]` and
`_GLOBAL__sub_I_<file>`. What a function reaches is followed through the compiler-named
functions it calls; an initializer the pipeline inlined is passed through to its referrer; twins
are compared within one kind of name; a `_GLOBAL__sub_I_` is proven by being a target of the
module's constructor table (`.ctors` on x86_64-scei-ps4). Within one unit `.N` comes from one
counter shared by initializers and helpers, so a row takes its `.N` from the unit's symbols,
never by counting. First rows: the 25 helpers of twenty static-initializer files
(FUN_00685a40's file and nineteen others); the fault test (two helper aliases swapped: 100 of
100 bytes equal, target wrong, base 0x5829730 against 0x58296a0) was rerun for the new names.

**Trigger to revisit.** A compiler-named function that reaches no uniquely named object of its
unit, or two that reach the same set.

## D57. A header's namespace-scope static: one name in the header, one checked address per unit (2026-11-11)

**Question.** 325 of the game's 332 per-file static initializers begin with the same nineteen
16-byte stores: a math header's `static const` vector constants, constructed into each file's
own copies. The tree names a file-local object by its address (D17); a header static has one
name and a different address in every unit, in 123 different .bss orders.

**Decision.** The object is written once in the header under its derived name
(`src/include/tlg_game_vector.h`: class Vector4, nineteen objects in the base's order). Its
per-unit address is data: `config/header_statics.base.txt`, `<tu> <symbol> 0x<addr>`, one row
per unit and object. `tools/match_check.py` resolves a function's reference to the unit's copy
to `D_<row address>`, then checked like any `D_<hex>`. In the whole module the copy is proven,
not read from the link's `.N`: every function of the unit that references it references one and
the same candidate, and no other unit's proof gives that candidate. A unit with no row, or an
unproven copy, fails the function with the row it needs and where the base's field points.
`tools/layout_link.py` checks every row (the unit proves the copy, the address lies in .bss, no
two rows share one). A file's `_GLOBAL__sub_I_` whose IR reaches no uniquely named object is its
own alias when no other unit defines the name and `.ctors` points at it (D56).

**Evidence.** Round 189A: twelve units, 228 rows, every block store's target verified in both
builds; with two rows swapped, two wrong targets (the base's 0x58b65f0 against 0x58b6600 and
the reverse); with a row dropped, the refusal names the row and the base's field; the gate's
count 6,849 before and after the tool change.

**Excluded.** A `D_<hex>` per unit through the preprocessor (the header would carry each unit's
facts); one `extern` shared object (the base has 325 copies, each stored by its own unit); a
block base address with a fixed layout (123 orders); the nineteen definitions copied into every
file; renaming internal names before the link (D56's exclusion); the link's `.N`.

**Trigger to revisit.** A copy read only through a function the module shares between units,
which no function of the reading unit can prove.

## D58. LoopStrengthReduce counts an immediate once per run of equal offsets: r278927's cost not taken (2026-11-11)

**Question.** 53 array-destroy loops of the game (ten or more names) exit on the add's flags
with a -4 displacement (`add rbx, -4; jne`); the installed compiler compares (`cmp rbx, -4`)
from a zero-displacement base.

**Evidence.** Round 185A: nine source forms of the element's destructor all give the compare;
the prebuilt 3.9.1 gives the base's form, 4.0.0 and 5.0.2 do not. Round 186B: the deciding
change is r278927 (llvm-project 7a79422536d8, 2016-08-17, first release 4.0), which removed
`LSRUse::Offsets`, so `Cost::RateFormula` adds an immediate's cost once per fixup instead of
once per run of equal offsets. Taken back in the cost alone: the module sweep is equal row for
row and draft for draft to the installed compiler's (3,923 of 3,973 resolvable rows in both),
and 12 of the 53 loops compile to the base's bytes where none did; the supervisor's own sweep
of the two patches of D58 and D59 together gave the same (s190: `cmp $-4` loops 12 before, 0
after).

**Decision.** `tools/patches/llvm-4.0.0-lsroffsets-01-immediate-once-per-offset-run.patch`.
The rest of r278927 stays. The patch reproduces the Offsets list's rule over the fixups in
their order; 3.9 also appended to that list when uses were merged, a path not reproduced.

**Not explained.** The base unrolls a list of nine names and loops at ten; every release from
3.8.1 to 4.0.0 unrolls ten and eleven as well (loop cost 15; the base's boundary needs 17 or
18, or a limit in (119, 132]). Open; 37 of the 53 loops also wait on lists not yet written.

**Trigger to revisit.** A game loop whose exit is the compare form where the offsets of its
address uses are equal.

## D59. MOVD and MOVQ between general and vector registers carry no execution domain: r288902 not taken (2026-11-11)

**Question.** Every block initializer of D57 builds its lane mask with `mov eax, -1; vmovd
xmm2, eax; vmovaps [mask], xmm2`; the installed compiler stores with `vmovdqa`. No source form
changes the domain of the store.

**Evidence.** In the game region a `vmovd` of a general register into a vector register is
followed directly by a `vmovaps` store 376 times and by a `vmovdqa` store once (the
supervisor's count over the disassembly; round 189A's count by next use: 456, 42 `vmovups`, 1).
r288902 (llvm-project 8893bd95f015, 2016-12-07, first release 4.0) put six groups of
X86InstrSSE.td in SSEPackedInt; the prebuilt 3.6.2 to 3.9.1 give `vmovaps`, 4.0.0 and 5.0.2
`vmovdqa`. With that file's part of the commit taken back the module sweep is equal row for
row and draft for draft to the installed compiler's, and the twelve initializers in the tree
store with `vmovaps` (12 `vmovdqa` stores before, 0 after).

**Decision.** `tools/patches/llvm-4.0.0-movddomain-01-movd-movq-default-domain.patch`: the
commit's X86InstrSSE.td hunks reversed exactly. Twenty-one backports with D58's.

**Trigger to revisit.** A game `vmovdqa` or `vpxor`-family instruction that only the integer
domain of a preceding movd or movq explains.

## D60. A conditional branch's uses give no edge to the scheduling region's exit: r286544 not taken (2026-11-11)

**Question.** 0x83fef0 stores a value and then tests it (`mov [rbx+0x554], eax; test eax, eax;
jne`); the installed compiler lifts the test above the store. No source form reaches it: the
machine code is the same in 3.9.1 and 4.0.0 until the post-RA list scheduler.

**Evidence.** Round 192B: every game draft compiled alone under the prebuilt 3.8.1 and 3.9.1;
0x83fef0 and 0x1496a80 are equal under both and first differ from 4.0.0 at that scheduler. The
change is r286544 (llvm-project 325cd2c98ab6, 2016-11-11, first release 4.0): the branch's
uses get an edge to ExitSU and macro fusion walks ExitSU's predecessors and zeroes the fused
edge's latency. Both code hunks taken back: every matched row's line identical to the installed
compiler's (3,965 of 4,010 resolvable rows in both), and 0x83fef0, 0x1380640, 0x1380850,
0x1496a80 equal; the supervisor's own build of the unconditional form and sweep gave the same
(s194).

**Decision.** `tools/patches/llvm-4.0.0-condjumpdeps-01-no-exit-edge-for-branch-uses.patch`.
The commit's signature changes stay.

**Trigger to revisit.** A game block where the flag setter is lifted above an independent
store or load before its conditional branch.

## D61. Block placement duplicates no tail: `-tail-dup-placement=false` (2026-11-11)

**Question.** D51 held r283934 (tail duplication during MachineBlockPlacement, first release
4.0) on conflicting evidence: 0xebbb70 said the base lacks it, 25 guard-and-latch pairs of the
base looked like its copies.

**Evidence.** Round 192B: with the pass's own option off every matched row's line is identical
and four drafts become equal (0x4a2c80, 0x8455a0, 0xebbb70, 0xecc810). Round 194B: none of the
25 pairs, and none of the 10 longer unmerged pairs D51 names, lies in a matched row or a draft;
the two drafts that show the base's merged tests need the option off; placement duplication
copies at most two instructions (MachineBlockPlacement.cpp:139-144 of 4.0.0), so it cannot
have made the 10 longer pairs: whatever keeps those unmerged would keep the 25 unmerged too.

**Decision.** `-mllvm -tail-dup-placement=false` on the `src/game/` line of
`config/flags.base.txt`: the pass's upstream option, a per-prefix flag as in D55.

**Not explained.** The 35 pairs the branch folder's tail merging would merge and the base
keeps apart; no function holding one is written yet.

**Trigger to revisit.** A game function, written whole, whose base bytes hold a two-instruction
tail copied into predecessors that only placement duplication produces.

## D62. The anti-dependency breaker skips a def of a kept register: r270935 not taken (2026-11-11)

**Question.** 0xdb00e0 and 0xdafdc0 load the script's pc into r8d and edi; the installed
compiler uses esi. Their notes blamed the allocator; round 194B showed the allocation is the
same and the register is renamed after it, by the post-RA scheduler's critical
anti-dependency breaker.

**Evidence.** Equal under the prebuilt 3.8.1 only. r270935 (llvm-project 05aeeb5cf19e,
2016-05-26, first release 3.9) made ScanInstruction process a def of a register in KeepRegs
instead of skipping it. With that hunk reversed exactly (round 196B): no matched row's line
changes, both functions equal the base, and they are the only two of the module's 4,679
functions that change. `-break-anti-dependencies=none` and `=all` leave both unequal.

**Decision.** `tools/patches/llvm-4.0.0-antidepkeep-01-kept-register-def-skipped.patch`.
Twenty-three backports with D60's. This is the first rule where the base agrees with 3.8 and
not 3.9; D6's addendum (the base is a fork, not a release) stands.

**Held beside it (round 196B), one partial witness each:** clang r282453 (an array
subscript's index emitted before its base: 0xc19ab0, 1 of 23 to 5 of 24, one function of 4,680
changed), r276008 (`returned` inferred on an argument: 0xeeac70, 0 of 32 to 17 of 22, one
function changed), and a condition with no upstream state (D49's load test not applied to a
floating-point select: 0x1395c30 and 0x1395e40 equal, no row changed). Each waits for a second
witness.

**Trigger to revisit.** A post-RA rename in a game function that only r270935's bookkeeping
gives.

## D63. A multi-bit mask compared with itself stays `and; cmp`: r268858 not taken (2026-11-12)

**Question.** 0x968760 tests `(x & 3) == 3` with `and; cmp`; the installed compiler emits
`andn` and tests the result against zero. No source form selects between the two.

**Evidence.** Round 202B's census of the game region: `and C; cmp C` with a multi-bit constant
at 245 sites (32 in the library); of the 98 `andn`, 96 produce a value and the two that feed a
branch (0x1301214, 0x130147c) have a variable mask: no `andn` compare with a constant mask
exists. 0x968760 is equal under the prebuilt 3.8.1 and uses `andn` under 3.9.1 and 4.0.0. The
change is r268858 (llvm-project c2751e7050b2, 2016-05-07, first release 3.9), the and-not
branch of simplifySetCCWithAnd. Taken back: no matched row's line changes and one function of
the module's 4,955 changes, the witness (2 of 37 to 33 of 35; what remains is a spill placed
before a copy, another rule).

**Decision.** `tools/patches/llvm-4.0.0-andncmp-01-no-and-not-compare.patch`. Twenty-four
backports. With D62 this is the second rule where the base agrees with 3.8 against 3.9.

**Held beside it (round 202B).** The loop-preheader protection of CodeGenPrepare
(d3fb38cae522, first release 3.9; its own option `-disable-preheader-prot`): 0xdd2290 is equal
without it and 0x4f46c0 fits, but 0xdacb80 shows a kept preheader holding a copy, and the base
has both forms (1,872 loops with the zero after the guard, 387 above it): held until 3.8's
rule is shown to predict both.

**Trigger to revisit.** A game `andn` whose result is only compared with zero and whose mask is
a constant.

## D64. GVN's scalar PRE reports only its last instruction's change: r253518 not taken (2026-11-12)

**Question.** 0x307330 and 0x402110 keep `add rax, 0x40` before a store; the installed compiler
folds the constant into the store's address.

**Evidence.** Round 208B's table of 253 drafts compiled alone: both are equal under the
prebuilt 3.7.1 only. The first pass that differs is GVN; r253518 (llvm-project adb4057a153a,
2015-11-18, first release 3.8) changed performPRE's `Changed = performScalarPRE(...)` to
`Changed |=`, so a further round runs when an earlier instruction of a block was changed. With
the assignment restored: no matched row's line changes, both functions equal the base, and
they are the only two of the module's 4,998 functions that change (the worker's sweep and the
supervisor's own with the unconditional form: s210). The rule changes how often an IR pass
repeats, so it has no instruction form to census.

**Decision.** `tools/patches/llvm-4.0.0-gvnpre-01-pre-last-change-only.patch`.

**Trigger to revisit.** A game function whose bytes need GVN's further PRE round.

## D65. The rewritten loop exit test truncates the induction variable: r278421 not taken (2026-11-12)

**Question.** 0xd49e00's loop compares its counter at 32 bits (`cmp r8d, ecx`); the installed
compiler compares at 64 (`cmp r8, rcx`). The test is one IndVarSimplify writes (linear
function test replacement), not the source's.

**Evidence.** Equal under the prebuilt 3.7.1 and 3.8.1. r278421 (llvm-project dbcfea98115b,
2016-08-11, first release 4.0) extends the trip count when that is provably equivalent;
earlier releases always truncated the induction variable. Taken back: no matched row's line
changes, 0xd49e00 and 0x470400 equal the base, six functions of the module change (both
sweeps as in D64). Census by a crude form (a 64-bit increment followed by a compare of the
same variable): 1,607 at 32 bits against 828 at 64 in the game region; a 64-bit count is also
legitimate, so the census does not decide alone.

**Decision.** `tools/patches/llvm-4.0.0-lftrwidth-01-exit-test-truncates-iv.patch`.
Twenty-six backports with D64's.

**Held beside them (round 208B).** The switch-weight series r246104, r246129, r246522 (first
release 3.8: the jump table's range check weighted 20 to 80 instead of evenly): three drafts
equal, twelve functions changed, no row changed, but the tested hunk approximates 3.7's weight
of the default edge: held until the three commits are reversed exactly. r249378
(TwoAddressInstructionPass) is refuted by the matched row 0xbe5650. r259673's chain edge from
a non-aliasing store to an unknown load (0x968760's remaining difference): census 5 against 3:
held.

**Note on D58 (round 201A).** D58's trigger fired once (a name-pair list's destructor exiting
on the add's flags in the build where the base compares) and was resolved by a source form:
the count and the entries held in one member instead of two gave the same optimised IR up to
use-list order, and LoopStrengthReduce's choice follows use-list order. No compiler change.

**Trigger to revisit.** A game loop whose rewritten exit test compares at the induction
variable's width where the count is narrower.

## D6, third addendum. The line re-measured over the whole module: it stays; the base is a 3.7-era code generator with a few later changes (2026-11-12)

**Measurement (round 212B).** The whole game module built as the gate builds it by each
prebuilt release (3,691 units, none rejected; the gate's stand-ins unchanged), every matched
row and draft compared. Rows equal of 4,135: the installed line (4.0.0 with twenty-six
backports) 4,087; 3.7.1 3,888 as built and 4,023 once the PS4 settings it lacks are counted in
(the trap after a noreturn call 95 rows, D26's nop 22, no vzeroupper 10, both 8); 3.8.1 3,853
and 3,890; 3.9.1 3,702; the prebuilt 4.0.0 3,699. Drafts equal of 257: installed 5, 3.7.1 20,
3.8.1 9, 3.9.1 4, 4.0.0 2. No row is equal under a release and not under the installed line.
After the PS4 settings 3.7.1 still lacks eight behaviours the base has (58 rows): list-ilp's
register-pressure order r282836 (4.0; 20 rows), the array-destroy helper's function attributes
(clang 3.8; 24), SimplifyCFG's sinking r279460 (4.0; 3), an aligned vector move (3.8; 5),
constant store merging (3.8; 3), r249378 (3.8; one row), two singles. Every backport's witness
is equal under the release the backport restores.

**Decision.** The line stays LLVM 4.0.0 with backports: it holds 64 more rows than 3.7.1 with
every PS4 setting ported, and a 3.7.1 line would need forward ports of two 4.0 passes. But the
base's compiler is, by every count, a 3.7-era code generator with a small number of later
changes, so the method is fixed accordingly: a draft that is equal in the prebuilt 3.7.1's
module and not under the installed line names an upstream change between 3.7 and 4.0 to take
back, found in the public history, reversed exactly, swept over the module (no row changed),
and adopted on an equal witness. D66 to D70 are the first decisions made on that footing.

## D66. A jump table's range check takes BranchProbabilityInfo's weights: r246104 and r246522 not taken there (2026-11-12)

**Evidence.** 0x13985e0, 0x13999c0, 0x139a080 are equal under 3.7.1 only. 3.7 adds the range
check's two edges with no weight, so they take BranchProbabilityInfo's; the 2015 series (first
release 3.8) weights the table by its cases and shares the default's weight out. The exact
reversal for the range check alone (round 210B, built and swept in its unconditional form): no
matched row's line changes, the three functions equal the base and are the only three that
change. Census of which side falls through: the base 315 table against 111 default; the
module 4 and 0 before, 1 and 3 after.

**Decision.** `tools/patches/llvm-4.0.0-switchjt-01-range-check-bpi-weights.patch`. The
series' other parts stay: the unhandled-sum change reproduces 3.7.1's counts on four drafts
without making one equal (held); the bit-test and pivot parts change nothing in the module.

## D67. A sign-extended add is not widened at instruction selection: r250560 not taken (2026-11-12)

**Evidence.** The base keeps `inc eax; cdqe` at 108 sites of the game region (one-sided
census). 0xb34440 and 0xb34470 are equal in the 3.7.1 module and first lost in 3.8.1's, with
the same IR in both; r250560 (bbd524496ccf, 2015-10-16, first release 3.8) promotes
sext(add nsw) in X86's DAG combine. Taken back: no row's line changes, both equal, four
functions change.

**Decision.** `tools/patches/llvm-4.0.0-sextadd-01-no-sext-add-promotion.patch`.

## D68. BasicAA's all-positive-offsets rule is absent, as in 3.7: r246502 not taken (2026-11-12)

**Evidence.** 0x13883d0 reloads a count after a store to entries[count]; equal in the 3.7.1
module, first lost in 3.8.1's at the first InstCombine. The rule was in 3.6 (r221876),
reverted for 3.7 (r245394) and reapplied for 3.8 (r246502, 5989bc6f4161, 2015-08-31). Its use
in aliasGEP taken back: no row's line changes; the witness equals the base and is the only
function that changes. One witness: adopted on D6's third addendum (the base agrees with 3.7
where 3.7 and 3.8 differ and no row says otherwise).

**Decision.** `tools/patches/llvm-4.0.0-baapos-01-no-allpositive-noalias.patch`.

## D69. No chain edge from a spill-slot store to an unknown load: r259673's edge not taken (2026-11-12)

**Evidence.** 0x968760's last difference after D63 is a spill placed before an independent
copy by the post-RA scheduler; equal in the 3.7.1 and 3.8.1 modules. r259673 (ac29f01788e3,
2016-02-03, first release 3.9) rewrote ScheduleDAGInstrs' memory dependencies; the narrow
rule taken back is the chain edge from a store to a non-aliasing stack slot to a later load of
unknown memory. With it: no row's line changes, 0x968760 and 0xedede0 equal, six functions
change, none away from the base. The census of the exact shape is two-sided (five copy-first,
three spill-first), and none of the three spill-first sites is in a function the tree holds.

**Decision.** `tools/patches/llvm-4.0.0-sdichain-01-no-spill-store-chain-edge.patch`.

**Trigger to revisit.** One of the three spill-first sites (0x4c0fa0 among them) written whole
and unequal only in that order.

## D70. Block placement keeps 3.9's forward check: r277187 not taken (2026-11-12)

**Evidence.** D51 held this (mbpprob-01) for a second witness. 0x12fd360 is equal in the 3.7.1
module; with 3.9's three lines restored in hasBetterLayoutPredecessor no row's line changes,
0x12fd360 equals the base and two functions change. D51's other layout drafts are explained
elsewhere (three by D66) or are equal under no release, so the second witness is the
whole-module measurement of D6's third addendum, not another function.

**Decision.** `tools/patches/llvm-4.0.0-mbpfwd-01-forward-check-as-3.9.patch`. Thirty-one
backports with D66 to D69's.

**Held beside these (round 214B).** r271602 (InstSimplify after the late LICM, first release
3.9): 0x1af9d0 equal, but 0xdacb80 moves away (16 to 4 of 78). r243831 with r288365 (a
zero-masking `and` kept instead of a blend): no draft becomes equal. The loop-preheader
protection: two drafts toward, 0xdacb80 away. r282836 taken back is REFUTED (18 rows): the
base has it, so 0xbb4af0 stays a draft.

## D71. After a commute the two-address pass tests the operand tied before it: r249378 not taken (2026-11-12)

**Question.** 0xcef1b0 and 0x1393620 have a `lea` where the installed compiler keeps an `add`;
the matched row 0xbe5650 has two `add`s that r249378's absence would turn into `lea`s, so
round 208B refuted the reversal.

**Evidence.** Round 216B: for both shapes the first pass that differs between the prebuilt
3.7.1 and 3.8.1 is the two-address pass and nothing before it; r249378 (2c4068f40966,
2015-10-06, first release 3.8) re-samples the tied operand after a commute; 3.7 tests the
operand tied before it and converts the commuted `add` to a `lea`. 3.7.1 gets 0xbe5650 wrong
as the tree wrote it (a byte pointer plus an offset) and right when the block's relative
offsets are read as such data is read: each offset added to the block's address as an integer,
offset first: that form is equal under 3.7.1, 3.8.1 and the installed line with and without
the reversal. So the row's old text matched only through a 3.8 behaviour the base lacks.

**Decision.** `tools/patches/llvm-4.0.0-twoaddr-01-no-resample-after-commute.patch`, and
`src/game/unknown/leaf_00be5650.cpp` rewritten in the same commit (a row's text changed, the
row kept). Thirty-two backports. 0xcef1b0 and 0x1393620 become equal; fifteen functions of the
module change; no other row changes.

**Held beside it (rounds 216B, 218B).** The loop-preheader option and r271602: 0xdacb80's two
preheader blocks in the base are the installed line's, block for block. r259736 taken back:
the base has it. A sinking rule in which an operand already sunk still counts as a PHI (no
upstream state): it gives 0xdacb80's three address blocks and loses its preheader copy. D49's
load test not applied to an FP select with a +0.0 arm (no upstream state; the census of the
base is undecided for that arm; "not for an FP select" and "not when both arms are constants"
are both refuted).

**Trigger to revisit.** A game `add` of a commuted two-address instruction that only the
re-sampled operand keeps from becoming a `lea`.

## D72. A jump table needs 40% density: `-jump-table-density=40` (2026-11-12)

**Question.** 0x12fd240 switches over 13 cases in a range of 52; the installed compiler makes
one 52-entry table (25% dense); the base makes a table for the dense part only (8 of 20
values) and compares for the rest.

**Evidence.** The base's 468 jump tables by density (cases over entries, the most common
target taken as the default: an approximate count, round 219C's census repeated by the
supervisor): 7 below 40%, 24 from 40 to 50%, 40 from 50 to 60%, 293 full: a floor at 40%,
where LLVM 4.0.0's default minimum is 10% (`jump-table-density`, SelectionDAGBuilder.cpp:93;
its own value for functions optimised for size is 40) and 3.6.2's lowering requires 40%. With
the option at 40 the module sweep is identical row for row and draft for draft to the
installed line's (s223: 4,219 of 4,268 resolvable rows in both).

**Decision.** `-mllvm -jump-table-density=40` on the `src/game/` line of
`config/flags.base.txt`: the upstream option, a per-prefix flag as in D55 and D61.

**Not shown.** The seven tables under 40% by the approximate count were not read one by one
(a default target that is also a case's target is miscounted as the default).

**Trigger to revisit.** A game jump table, in a function written whole, whose density is below
40% by its source's cases.

## D73. A claimed function's jump table is derived from its row and proven entry by entry (2026-11-12)

**Question.** The game line lowers a switch to a table of 32-bit entries in .rodata, each the
target block's address minus the table's. The layout step refused any unit holding such a
table ("a layout extension"), so no game function with a jump table could be claimed; the
region has 468 tables in 344 functions.

**Decision (round 219C, `jump_table` in `tools/layout_link.py`).** The table has no config
row: it is derived from the function's row on every run. Its address is where the base's own
`lea` points and must lie in the game's read-only data (`config/modules.base.txt`); the
object's table must be exactly its entries, each a PC-relative relocation to a block of that
function; every entry must equal the base's word at that entry or the row fails naming the
entry; the table's bytes are then laid at its address so the segment comparison covers them;
a table that overlaps another claimed object fails its row. Any other data object holding a
relocation that is not a pointer keeps the old refusal.

**Evidence.** The gate's count 7,150 before and after the tool change; with one entry of
0x13985e0's table moved by five bytes in a scratch copy of the object the row fails: "entry 1
(+0x4) targets +0x35 (0x1398615), the base's entry targets 0x1398610"; five functions claimed
through it (0x13985e0, 0x13999c0, 0x139a080, 0xdd1d60, 0x331950).

**Excluded.** A config row typed by hand per table; skipping the table; trusting the object's
entries without the base's bytes.

## D74. The game's bool variables that were local to the optimiser: rows of local data, proven from the base (2026-11-13)

**Question.** Every bool global of the game that GlobalOpt could shrink to one bit is read as a
masked single bit (19 of 19 ordinary globals; the four thread-local bools at 9,382 sites): the
form TryToShrinkGlobalToBoolean gives, and it runs only on a variable with local linkage. Yet
the two thread-local flags D_16dc088 and D_16dc098 have one address each and are read in 2,482
and 542 functions across the whole region with no accessor function between (the smallest
readers hold the read inline), the game was many translation units (332 static initializers),
and functions were not internalised (D50: 89 of 92 kept unused returns are never address-taken).
About 2,800 functions and 511 destructor pairs read the flags.

**The maintainer's ruling (2026-11-12).** "we can internalize variables if they are appropriate
and make sense dev native".

**Decision (round 228C).** The source keeps the developer's form: an ordinary variable
declared in a header and defined once (`extern __thread bool`). That the base's build treated
it as local is the gate's knowledge, as checked data: a row `<symbol>` in
`config/local_data.base.txt` makes `tools/game_module.py` give that variable internal linkage
in the linked module before the pipeline (the prebuilt `opt -internalize` with every other
definition preserved; refused unless the symbol table changes by exactly the rows). A row is
proven from the base before it is used (`tools/module_boundary.py --local`): every read takes
one bit or is a saved copy put back, every store is 0, 1 or that copy; a variable any read of
which compares the whole byte is refused. A stand-in for a row's variable carries one writer
so the shrink's condition holds; it goes when a file defines the variable. Of the 19 shrunk
ordinary bools, 17 are reached from one unit or two adjacent ones and are plain file statics
needing nothing; rows exist for the two flags.

**Evidence.** The proof's counts: D_16dc088 8,224 sites, 8,204 masked, seven saved copies put
back, stores of 1 ten and of 0 three; D_16dc098 1,158 sites, 1,144 masked. The gate's count
7,458 before and after the tool. The fault test: D_58b6008 marked local is refused ("4 read(s)
compare the whole byte ... first 0xb91249"), as are a pointer and the flag at tp -71. With D75
the three destructor pairs 0x138e5f0, 0x13ed250, 0x1482fd0 equal the base.

**Not shown.** No public mechanism internalises variables and not functions; the twelve
shrink-eligible bools the base did not shrink are all bytes inside larger objects, and their
IR form was not compiled. The proof reads 25 instructions of text order after an access, not
control flow.

**Excluded.** A `static` in a header (one copy per unit; each flag has one address); an
accessor function (none exists in the base); internalising the whole module (D50); a
source attribute.

## D75. A thread-local with local linkage stays general-dynamic (2026-11-13)

**Question.** With D74 a flag is local, and the installed compiler then accesses it through
the local-dynamic model; all 21,974 thread-local accesses of the base are general-dynamic
(D23). `-ftls-model=global-dynamic` does not help: a selected model can only strengthen the
computed one (TargetMachine.cpp:190-193 of 4.0.0).

**Decision.** `tools/patches/llvm-4.0.0-tlsprot-02-local-tls-general-dynamic.patch`: in the
position-independent branch of TargetMachine::getTLSModel only a hidden symbol is
local-dynamic. Thirty-three backports. This rule has NO UPSTREAM STATE (every release from
3.8.0 to 12.0.0 gives local-dynamic here): it is adopted on the executable's own evidence: no
local-dynamic access anywhere, beside thread-locals that were local when optimised.

**Evidence.** Round 228C, the rule as a hidden option: option off, the module object is
identical; option on, the module's local-dynamic relocations go from 10 to 0 and of 4,589 rows
swept only the six destructor functions change, to equal.

**Trigger to revisit.** A local-dynamic access (`__tls_get_addr` with a module-base
relocation and `@dtpoff` offsets) anywhere in the base.

## D76. No wrap flags inferred on (A + C) from A's range: r251048 not taken (2026-11-13)

**Question.** 0x583980, 0x583d80, 0x58b7c0 and 0xc060d0 are equal to the base in the prebuilt
3.7.1's whole-module build and not under the installed line: loop strength reduction works on
a 32-bit induction variable where the base has the 64-bit recurrence.

**Evidence.** Round 233B: a reduced function whose `opt -analyze -iv-users` folds zext(i) to
an i64 add recurrence under 3.7.1 and not under 3.8.1, 3.9.1 or 4.0.0. r251048 (8f27415c05,
2015-10-22, "[SCEV] Mark AddExprs as nsw or nuw if legal", first release 3.8) makes
StrengthenNoWrapFlags ask for A's signed and unsigned range when (A + C) is built; read from
the sources, that query computes the backedge-taken count before the extension is requested
and the unfolded extension stays in the unique table. The unconditional reversal built and
swept alone by the round: 0 matched rows change, 4 of 6,123 functions change, all four equal.
The supervisor repeated the build and sweep with D77 and D78 together: 0 rows change, 7 drafts
become equal, 19 functions change (13 toward, 5 level, 1 away), test tree restored by sha256.

**Decision.** `tools/patches/llvm-4.0.0-scevaddflags-01-no-add-const-nowrap.patch`.

**Excluded.** A source form: the four functions' loops are plain indexed loops; no spelling of
the index reached the 64-bit recurrence under the installed line (the drafts stood at 5/29 and
10/62).

**Trigger to revisit.** A game loop whose bytes need a no-wrap flag only A's range can prove.

## D77. A switch's range compare carries the sum of the clusters still to test: r246129 and r246522's share not taken (2026-11-13)

**Question.** Held since round 210B for want of an equal witness: under D66 the false edge of
a case cluster's compare still carried 3.8's sum (the unhandled clusters plus the default's
share, the cluster subtracted before its compare).

**Evidence.** Round 233B: 0x1af030 and 0x1af3c0 are equal in the prebuilt 3.7.1's module and
22 of 59 under the installed line. 3.7's rule (the sum without the default's share, a cluster
leaving it where its compare is emitted, an empty sum left to BranchProbabilityInfo; r246129,
08cb4fc688a9, 2015-08-27, and r246522, 511298b91951, 2015-09-01, both first release 3.8)
built and swept alone on top of D66: 0 rows change; 13 functions change: both witnesses equal,
7 toward (0x12fd240 13 to 49 of 58, 0x13d2490 18 to 41 of 52, 0x13cc210 15 to 24 of 33,
0xb5bc40 1 to 7 of 12), 5 level, 1 away (the draft 0xef65f0, 4 to 2 of 18).

**Decision.** `tools/patches/llvm-4.0.0-switchunh-01-unhandled-sum-as-3.7.patch`.

**Stands against it.** 0xef65f0 (a draft at 4 of 18, not a row). 0x82ee90 is a counter-witness
to the exactness of D66's form, not to this rule: it is equal only with D66 off, which loses
five rows; what remains there is block placement under D66's probabilities for a table whose
gap entry is the default.

**Trigger to revisit.** 0xef65f0 or 0x82ee90 worked to a first difference that names this rule.

## D78. An array subscript's index is emitted before its base: clang r282453 not taken (2026-11-13)

**Question.** Held since round 196B on one witness: clang 4.0.0 emits a subscript's index
after its base (C++17's order); the base's bytes show the index first.

**Evidence.** Round 233B's second witness: 0x13ace60 is equal in the prebuilt 3.7.1's module
and 27 of 63 under the installed line; with the base's field address emitted after the index,
SimplifyCFG hoists the address GVN's scalar PRE left in a split edge and the edge block
disappears. clang r282453 (9e67b9922bb1, 2016-09-26, first release 4.0.0). The unconditional
reversal (round 196B's form) built alone, the module rebuilt from all 4,219 units by that
front end (0 rejected) and swept: 0 rows change; 2 functions change: 0x13ace60 equal,
0xc19ab0 1 of 23 to 5 of 24.

**Decision.** `tools/patches/llvm-4.0.0-subscript-01-index-before-base.patch`. Thirty-six
backports with D76 and D77.

**Held beside them (round 233B).** Load widening: r281074 (22ce5eb05159, 2016-09-09, first
release 4.0.0) taken back makes 0x20d3d0, 0xb46580 and 0xb746b0 equal and changes 110 rows;
with 3.7's field alignment in the front end (part of clang r246985) it changes 5 rows, all
Float4A `vmovaps`; with Float4A holding a vector, 1 row. The base has 5,964 widened sites
(an 8-byte load then `shr 32`) in 871 functions and the module 0, so widening is region-wide
in the base; the candidate waits on Float4A's source form. The deleting destructors 0xeaaf10,
0xeab310, 0xeb1840: the machine scheduler's order on one input differs from 3.7.1; commit not
traced.

**Trigger to revisit.** A game subscript whose bytes need the base emitted first.

### D78 addendum: WITHDRAWN (2026-11-14)

The audit the maintainer ordered ("validate there is no C++ source that can reach the
matches") found an ordinary source form that reaches D78's witness without the rule. Round
240D, repeated by the supervisor: 0x13ace60 with the block array read through an accessor
member (`Block013ace60 &at(int index) { return blocks[index]; }`) is equal (63 instructions,
204 bytes) under the compiler built without subscript-01 and under the installed one alike;
D78's other mover, 0xc19ab0, reaches the same 5 of 24 without the rule through an accessor;
0x58da20 reaches its bytes without the rule through a local for the offset. The leave-one-out
sweep (round 241B) shows no matched row lost without the patch. An accessor is what a
developer writes; the rule is not needed, so it is not kept: `leaf_013ace60.cpp` takes the
accessor form in this commit, and `tools/patches/llvm-4.0.0-subscript-01-index-before-base.patch`
is removed at the next compiler install (the audit holds the build tree until then; the row is
equal under both compilers meanwhile). Thirty-five backports after that install.

D76 and D77 under the same test (round 240D, six developer forms per witness beside the
tree's, compiled without the rule; `scratch d240/forms/README.txt`): none equal. D76's
nearest is a 64-bit index (19 of 27), excluded by bytes (the base compares 32 bits). D77's
nearest is the cases written in descending order (37 of 58). D77 gained three witnesses whose
rows need it: 0xef65f0 (2 of 18 without it; its earlier "away" was the draft's own case
order), 0x13cc210 and 0xb5bc40.

Rule from here on: a compiler rule is installed only after the developer forms tried on its
witnesses under the compiler without it are recorded in its decision.

### D6 fourth addendum: the scheduler flag removed from the game line (2026-11-14)

Question. Is list-ilp the base's DAG scheduler in the game region, or a stand-in for the order of reads in the source?
Evidence. The flag was chosen on two probe rows (0x639e60, 0x779070). Round 241B and round 244B measured the whole gate
module without it: of 5047 game rows 22 were lost; 21 are equal in ordinary C++ once the reads are written in the base's
order (forms per row in round 244B's entry: the header's pushNumber/pushBoolean inline for 0x1b0880, 0xa5edb0, 0x468e60;
the int read before the top for 0x1b1790, 0x1b2700; a clock_t local for 0xde6990; a local for the target pointer for
0x639e60, 0x778dc0; inline setters for 0x779070, 0x7793f0; the argument or key read into a local first for 0x69d360,
0xd41700, 0xd49e00, 0x13580d0, 0x1499360; no block local for 0xdafb70; the operands or compares in the base's order for
0x12fd1f0, 0x135e2b0, 0x135e310, 0x135e3a0; 0x3e3e00 a pair of floats copied by value, round 249B). 316 drafts are equal
without it (221 static initializers, 3 deleting destructors, 92 functions), none is lost. The last row, 0x75f2c0, kept
the base's instructions with another register assignment: the base needs the leave code laid out before the search
loop's body (round 246B's IR probe); no public release from 3.7.1 to 9.0.0 does that for a loop left by break (round
249B's oracle), and the row is equal when the reader count is held by a scope object in the init of a for statement
that runs once, whose destructor clang lays out before the statement's body.
Decision. The flag is removed from the src/game/ line; the scheduler is upstream's default.
Trigger to revisit. A second function whose base order no source order gives without the flag; or a ruling that the
one-pass for scope of 0x75f2c0 is not a developer's form (then 0x75f2c0 is the only row that speaks for the flag, and
the nine unclaimed loops of its shape in census.tsv are the place to test the scope form again).

**Is the one-pass for scope a developer's form?** (the maintainer's test: "would a dev have
written it?"). Round 252B, independent of 0x75f2c0: 155 game functions take this reader lock
in 265 scopes. Three of them (0x45b950, 0x45bad0, 0x45f4e0: a return from inside a loop inside
the scope) keep clang's cleanup destination index in a register (`mov ebx, 2` before the loop,
`mov ebx, 1` on the return path, one leave, `cmp ebx, 2`): the for-scope form produces exactly
those constants and the single leave; plain enter and leave statements produce none, and a
block-scoped object produces none. So the base's own bytes show the for-statement scope with
this lock. The idiom is not universal: 0x45bc50, 0x46bf30 and 0xb91cc0 drop the lock by hand
on two paths (two leaves, no index). No case was found where the plain form is equal and the
scope form is not. The four claimed users are equal with one shared class and macro.

### The audit of the compiler rules (2026-11-14): outcome and the forms recorded

The maintainer ordered every compiler rule of the game line audited: "validate there's no c++
source that can reach the matches"; the deciding test: "would a dev have written it?".
Method: one compiler per rule with that rule alone reversed (36, kept in scratch
`b241/loo/`), the module swept (rows lost without the rule: `b241/dependents.tsv`), then
developer forms compiled without the rule on its dependent rows (rounds 240D, 241B, 245D,
247C; per rule `forms/<rule>/README.txt` under scratch d240, b241, d245, c247), and two-rule
leave-outs for the switch pair (round 248D).

- **Removed.** D78 (subscript-01): an accessor member reaches its witness. The scheduler flag
  `-pre-RA-sched=list-ilp` (above): every row that needed it is written without it.
- **Stands, forms that reach rows without the rule rejected as not a developer's:** newalign-01
  (D53: `new (operator new(sizeof(T))) T()`, a class operator new that clears, a constructor
  that memsets a polymorphic object: at 142 of 142 zeroed new-sites a developer writes
  `new T()`); sextadd-01 (D67: an unsigned return against the data model, whose word holds the
  sentinels 0xffffffff and 0xfffffffd; an unsigned constant nothing evidences); mbpfwd-01 and
  cgpload-01 (`__builtin_expect`); tlsprot-01 (`visibility("default")`); dsebegin-01 (a vector
  store over the vtable pointer; an inline SSE clear the census of 2,266 new-sites speaks
  against).
- **Stands, no form found** (about six per row, every dependent row where five or fewer, else
  sampled by shape): andncmp-01, orlea-01, baapos-01, twoaddr-01, sdichain-01, lftrwidth-01,
  movddomain-01, reassoc-01, switchwidth-01, gvnpre-01, antidepkeep-01, fixupbw-01,
  schedops-01, sinkcond-01, mbpfwd-01, `-tail-dup-placement=false`, lsroffsets-01,
  msinksplit-01, setcc-01, shrinkwrap-01, opnew-01, condjumpdeps-01, sspnop-01,
  msinksubreg-01, i1load-01, cmp-01, tlsprot-02, D76 (scevaddflags-01), D77 (switchunh-01).
  Limits: the heavily depended rules were sampled, most runs were a unit alone, and the 186
  thread-flag readers got no forms of their own under i1load-01 and cmp-01.
- **Stands on drafts or a pair:** switchjt-01 (D66: no row needs it alone; with D77 it is the
  coherent 3.7 pair; draft 0x12fd240 needs both; 0x82ee90, equal only with both out, is the
  open counter-witness); `-no-x86-call-frame-opt` (D55) and `-jump-table-density=40` (D72:
  rows 0x1af030, 0x1af3c0 since round 240D).
- **Open:** structor-01 (D45): its six lost rows are lost by symbol name only; its real
  witnesses (own-vtable `jmp D2` thunks) are free-function stand-ins: one is to be written as
  a class so the rule rests on a row, or the rule goes.

Rule from here on: a compiler rule is installed only with the developer forms tried without
it recorded in its decision.

### D78 second addendum: REINSTATED (2026-11-14)

The withdrawal was the supervisor's error. Its evidence was one function (0x13ace60) that an
accessor reaches without the rule and a sweep of the rows of that day. The install without
`subscript-01` was then gated on main at 3456964b: 18 matched rows are not equal without the
rule (scratch `b249/rows_need_subscript_scores.txt`: 0x7af2c0, 0x968550, 0x9685a0, 0x9685f0,
0x968820, 0xa18a70, 0xdd1dc0, 0xdd1e40, 0xdd24b0, 0xdde5a0, 0xde2e60, 0xde3000, 0xeb2930,
0xedffb0, 0x1367690, 0x139ecf0, 0x13af260, 0x13d02a0), all claimed since, most with the
scheduler flag's removal. Their sources are the plainest C++ there is: `self->unknown50[i]`,
`_Getptolower()[static_cast<u8>(c)]`, `&array->unknown0[i]`, `self->unknown20[i].unknown6`.
The maintainer's test ("would a dev have written it?") decides it the other way round from
how the withdrawal read it: a developer writes the direct subscript, in eighteen functions and
more to come; an accessor in every one of them would be the contrivance. And the reversed
commit (clang r282453, 2016-09-26, C++17's evaluation order) cannot be in the base's 3.7-era
compiler, the same ground on which newalign-01 stands. With the rule installed no matched
row asks for the base before the index.

So: `tools/patches/llvm-4.0.0-subscript-01-index-before-base.patch` stays; thirty-six
backports. 0x13ace60 and 0xc8b0d0 keep their accessor and local forms (equal with and without
the rule). The audit's lesson is recorded with its limit: one function reached by another
form does not unseat a rule; the question is what the developer wrote at ALL its sites.

## D79. The game is built with -ffast-math; the sndx sound runtime is not (2026-11-14)


Evidence (round 262A, scratch a262/: census.py, c_marks.txt, c_totals.txt, q1.py, q5.py, strings_wide.txt, fnflags.txt):
- Strict-math marks in the base. Game region: 25,734 scalar float compares, 94 followed by a parity test; 4,041
  divisions, 29 by a RIP constant (48000.0 seven times, 1000.0 seven, 2*pi eight, 21.0 three, 100.0 two, 360.0, ln 10);
  one `x + 0.0` kept (0xee92d0). Every one of them lies in 31 functions from 0xec18b0 to 0xf0fe30 (the last ends at
  0xf15220). Round 260A's thirtieth division (0x13a674b) divides by a variable in .bss, not a constant.
  Outside those bounds: 0 parity tests, 0 constant divisions, and 229 multiplies by a reciprocal of an integer with a
  prime factor other than 2 and 5 (1/30 52, 1/3 31, 1/360 12, 1/15 12, 1/1080 10, 1/1920 8, 1/255 8) in 136 functions;
  ten read by hand (0xba4950, 0x128e88a, 0x113228a, 0xffa518, 0x106119b, 0xd2bde6, 0xe99f35, 0x142d968, 0xd2a09f,
  0x1429e09): an int converted and scaled by 1/30, 1/6, 1/360; a colour byte by 1/255; `(x + c) * (1/17)`. Each is
  what `x / 30.0f` becomes under reciprocal math; a typed `x * (1.0f / 30.0f)` gives the same bytes, so the mark is
  the absence of any division beside them, not each site.
  Inside the bounds the same census finds 25 such multiplies (0xed3a00's factorial series, 1/32767) beside the 29
  divisions: there a reciprocal is what the source typed.
  Library region (below 0x1a3e00): 1,216 compares, 128 divisions, 0 parity, 0 constant divisions, 7 reciprocals (D24, D40).
- Identity. The code inside the bounds refers to the strings of Sony's "sndx" runtime: its API names (sceSndx...), its
  messages, and assert file names `C:\sound\sndx\trico\runtime\source\sndx\sndx_buss_fx.c` (0xec1210),
  `sndx_player_sequence.c` (0xee05e0), `sndx_audioout_orbis.c` (0xf0e8b0), and after the bounds
  `sndxs_file\sndxs_file_instance.c` (0xf199a3), `sndxs_file_request.c` (0xf1a2a3). A C library. By its strings it runs
  from about 0xebfcc0 to 0xf1a2e0, wider than the marks; below 0xec1170 it is interleaved with the game's sound manager
  (0xeb3c90 to 0xebefd0: vtables, the thread flag, 0xdeadc0de) whose functions carry sndx API strings (API bodies
  inlined into their one caller), and an island of C++ (std::function slots, 0xf0e070 to 0xf0e5a0) sits inside it.
  Both fit a link-time module in which each function keeps its unit's float semantics.
- Oracle (round 260A, a260/c2_oracle.txt, c2_fmf.txt): 0xf51a20, 0x762bd0, 0x7790f0, 0x108d770, 0x109ddf0 equal with
  -ffast-math under 3.7.1, 3.9.1 and the installed compiler; -funsafe-math-optimizations, -fassociative-math
  -fno-signed-zeros -fno-trapping-math, -fno-signed-zeros, -ffinite-math-only, -freciprocal-math change nothing.
- Forms without the flag (round 260A, a260/forms/c2/README.txt): six on 0x108d770, none; six on 0xf51a20, one equal
  (the second component read first to steer the ranks): not a developer's, and fourteen copies.

Change: `-ffast-math` on the `src/game/` line; `src/game/sndx/` the same line without it, holding the units whose
functions lie in 0xec18b0 to 0xf15220 (24 claimed units, 26 rows, 3 drafts, moved by `git mv`, rows re-pointed). No
tool changed: compile_cpp.sh takes the longest prefix for a unit's front end, the module's code generation runs under
the `src/game/` line, and every function carries its unit's "unsafe-fp-math", "no-nans-fp-math", "no-infs-fp-math",
"no-signed-zeros-fp-math" attributes and its instructions' fast flags (TargetMachine::resetTargetOptions,
lib/Target/TargetMachine.cpp:69 to 81).

Gate: first build with the flag: 8,296 rows equal, 6 not (0x4ada80, 0xfb5c50, 0xfb5cf0, 0xfb5d90, 0x1246fd0,
0x1328ed0); 0xeddfe0 and 0xedede0, lost in round 260A's whole-module measurement, are equal in the sndx prefix as they
stood. The six rewritten (below): gate: OK (a262/gate2.log). Six drafts equal as they stood and claimed.

Forms under the flag, for the maintainer's test at all sites:
- 0x4ada80: `if (to < from) return 1.0f - FUN_004ada80(value, to, from);` first, then the step. (`from > to` and
  `from <= to` give `vucomiss xmm3, xmm2`; the base compares to against from.) One site.
- 0xfb5c50 and its three copies: `if (D_14db590 > input->records[0].value && D_14db590 > input->records[1].value)
  return 0;`. Without NaNs the compare keeps the source's operand order (X86 TranslateX86CC swaps only the ordered
  less-than forms), and the base holds the threshold in the register and folds each value from memory: the threshold
  is the left operand in the source. `value < threshold` gives 163 bytes against 159. Four sites, one shape. A ruling
  is asked: the constant-first compare is a house style or it is not; no other claimed row shows it either way (no
  other row of the 8,302 changed under the flag).
- 0x1328ed0: `scale->unknown28[i] * in[i] * 2.0 - 1.0` (the scale read first; the value-first product gives
  `in * (scale + scale)`). Four lines, one shape.

Against: (1) a typed reciprocal is indistinguishable from a division at any one site; the case rests on none of
the region's other 4,012 divisions being by a constant, and on the five reassociated sums. (2) The sndx bounds are
the marks' bounds, not the library's: units of the library outside them that hold float code would need the prefix
too; none is claimed today. (3) 0xde6c40 moves from 11/55 to 9/54 and 0x778080 from 7/77 to 9/63 under the flag
(drafts). (4) The library region's line keeps -fno-honor-nans -funsafe-math-optimizations (D24, D40): whether it is
-ffast-math too is not measured here.

**Supervisor's ruling on the forms (the maintainer's test: what the developers made).** The
four copies of 0xfb5c50 compare the constant first (`D_14db590 > records[0].value`): a
threshold test written threshold-first is ordinary. Against: two drafts move away under the
flag (0xde6c40, 0x778080), and the prefix covers the marks' bounds, not the library's full
string range: a float-bearing sndx unit outside 0xec18b0 to 0xf15220 joins the prefix when it
is written.

## D79 (proposed number). CodeGenPrepare's loop-preheader protection is not in the base: `-mllvm -disable-preheader-prot` on the game line (2026-11-14)

**Question.** Held beside D63 since round 202B: LLVM r265397 (d3fb38cae522, 2016-04-05, first release 3.9.0;
lib/CodeGen/CodeGenPrepare.cpp:471 to 474, the first test of isMergingEmptyBlockProfitable; its option
`-disable-preheader-prot` at :121) keeps an empty loop preheader from being merged into the branch that
enters it. Does the base's code generator have it?

**Evidence.**
- Census of the constant (round 260A, a260/census_dead_*.txt): `mov reg, 0xdeadc0de` BEFORE the thread flag's
  test (`mov; movzx; and; cmp; jne`): base 1,292 sites in 474 functions; the module with the protection 0;
  the module with the option 8 (d263/census_dead_module_after.txt), in the functions claimed by this round.
- Census of a counter's zero (d263/loopcensus.py, loopcensus_base.txt, loopcensus_module_before.txt,
  loopcensus_module_after.txt): a guarded counted loop with `xor r, r` ABOVE the guard's compare (the zero in
  the guard's block: only possible when the preheader is merged): base 78 sites (76 in unclaimed functions),
  module with the protection 0 of 39, module with the option 2 (0xdd2290, 0x13936a0). The other form (the zero
  behind the guard's branch) is 1,064 in the base, 39 in the module before and 43 after: the option's
  compiler makes both forms, the protected one makes only the second.
- Whole tree (round 263D, branch r263d): the flag added to the src/game/ line, everything rebuilt, the gate
  run: `gate: OK`, 8,314 claimed functions before and with the flag, no row differs. 13 of 5,919 module
  functions change (d263/fnchg.txt, the same 13 as a260/php/fnchg.txt).
- Rows: six drafts equal as they stood (0x804c70, 0x373200, 0x4f46c0, 0xdd2290, 0x967d40, 0x13936a0); six
  functions written new under the flag, equal on their first compile (0x13ceda0, 0x1352a50, 0x13aca00,
  0x135fae0, 0x231020, 0x1347ab0), five of them among the smallest ten of the 474.
- The commit cannot be in a 3.7-era compiler (first release 3.9.0); D6's third addendum.

**Forms excluded (the audit's rule).** Round 260A, whole module, without the option
(a260/forms/README_c3_c4_module.txt): the tree's form and six more on 0x804c70, the tree's and three more
on 0x373200: none moves the constant above the flag's test. By construction: the constant is no value of
the source; MachineLICM hoists it to the loop's preheader, and only the block the preheader is can change.
THE TEST at all sites: the sources are a `for` over an array and a release of a counted reference
(`self->item(i)->unknown80.clear()`, `entries.removeAll()`, `table->clear()`): what a developer writes, at
474 functions.

**Decision.** `-mllvm -disable-preheader-prot` on the src/game/ line of config/flags.base.txt (commit
2f670b26 on r263d). An upstream option of the installed compiler, no patch, per prefix.

**What stands against.**
- 0xdacb80 (17 of 80 with the option, 16 without): the base has `test ecx, ecx; je; mov esi, ecx` before its
  first page walk (the count's copy behind the guard) and the option gives `mov esi, ecx; test; je`. The
  function is not reproduced under any configuration (its address shape, the unsunk returns of
  instruction(): rounds 216B, 218B), so the block is read from a function whose IR is not the base's.
- 0xabbfd0 (2 of 64) and the four copies of 0xf501a0 (2 of 29) change and stay far (the IndVarSimplify
  class); nothing to read from them.

**Trigger to revisit.** A game loop whose base bytes show an EMPTY preheader kept apart from its guard (a
block holding only a phi's copy or a hoisted constant, behind the guard's branch, in a function otherwise
equal); or 0xdacb80 equal but for that block.

The option is on both game prefixes (src/game/ and src/game/sndx/): Sony's sound runtime was
built by the same SDK-era compiler, which predates the 3.9 behaviour; its 26 rows are equal
with and without it.
