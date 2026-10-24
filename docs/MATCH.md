# Matching a function

The unit of work is one function of the base executable
(`config/functions.base.txt`: address, size, name). The claim is a row in
`config/matched.base.txt`; the proof is `tools/check_elf.py --gate`: the
function's instructions equal to the base with every relocation target
verified, and every loaded segment rebuilt and byte-identical. This document
is the method, carried over from the ICO project's matching campaigns and
adapted to this target. `docs/DECISIONS.md` holds the standard it serves.

## Where a function lives

Check the address first. Below 0x1a3e00 the function is library code of the
LLVM 3.3 generation and goes under `src/libs/`; from 0x1a3e00 it is the game's,
built by the 4.0 generation, and goes under `src/game/`. Each prefix has its
compiler and flags in `config/flags.base.txt` (`docs/TARGETS.md`, "Two
compiler generations"). A function whose home file is not known goes in that
prefix's `unknown/`, one function per file, until a string, a vtable or a
caller places it.

## The loop

1. **Pick a function.** `docs/base/progress.json` and the dashboard show
   what is unclaimed; take the smallest unmatched one in the region being
   worked and stay on it until it matches. Parked functions are in the queue
   like any other, and the lowest ones usually are the parked ones.

2. **Recover the data model and the purpose before the first diff.** Read
   the function's disassembly and its callers and callees. Name what each
   offset means (a pointer at +0x68, a count at +0x70, a 4-float row at
   +0x23a0), find the same offsets in sibling functions, learn the callees'
   real signatures from their bodies, and state in one line what the function
   does. The developer wrote toward that purpose in 2012-2016 C++ with the
   engine's idioms (a math class with its own copy constructor, a device
   abstraction behind a vtable, an arena with a header before each block),
   not toward a diff.

3. **Write the C++ as the developer would have.** Typed members, not offset
   casts; the engine's own types in `src/include/`, grown one verified field
   at a time (offset and width from the load or store that touches it).
   Callees are `FUN_<addr>` until named, data `D_<hex>`: both are facts the
   gate checks. A name taken from a string, an export or a vtable is a fact;
   a name invented from context carries `/* derived name */`.

4. **Diff, then reason.** `tools/quick_diff.sh <tu> <function>` compiles the
   TU with the prefix's compiler and flags and prints the first differing
   instruction with five of context on each side, plus any relocation whose
   target the base contradicts. Work the divergences in the function's own
   order: the first one first, because everything before it is proven
   context, and the second does not exist until the first is resolved. For
   each: state the claim (which compiler decision produced the base's form and
   what source property drives it), name the source for it (the compiler's
   code under `tools/cc/src/llvm-<version>.src/`, its IR or machine dumps on
   your TU, the base's own bytes), then change the one semantic property and
   predict the output before compiling. Compile once. If the prediction was
   wrong, fix the model, not the spelling. More than about six compiles on
   one divergence means spraying; stop and derive.

5. **Claim it.** When `quick_diff` reports equal with every target verified,
   add `<function> <tu> [<symbol>]` to `config/matched.base.txt` (the symbol
   column only when the mangled name's base identifier differs from the
   row), `tools/build.sh regen` if the TU is new, then `./build.sh`. The gate
   is the only truth: `quick_diff` compares an isolated object and can pass a
   function that the layout then refutes (a size shortfall, a relocation the
   base does not carry). Commit; the pre-commit hook runs the gate and
   refreshes the progress files.

6. **Rename when known.** A real name replaces the `FUN_` row in
   `config/functions.base.txt` with the mangled symbol, the `matched` row
   drops its third column, and the file moves out of `unknown/`.

## What counts as a hypothesis

A change the compiler can see: a type (int or struct or union or pointer),
aliasing (which pointers may alias, `const`), liveness (what is live across
which call), factoring (inline helper or out-of-line call, same TU or not),
the algorithm, the control-flow shape, the signature (parameter count and
types, `this` or free function, return by value through a hidden pointer).
Respellings the front end folds to the same IR (`if`/`else` versus a
ternary, `a == 3` versus `3 == a`, a named temporary versus an inline
expression) are one hypothesis in several costumes and are not tried. When
every variant gives the same result, the axis is wrong, not the number of
tries.

Derive before compiling on a large function: from the base's bytes compute
what the compiler must have been given (which values were in registers at
which call, which loads were hoisted, which stores merged), solve backward
to the source conditions on paper, then compile to verify, three compiles a
round at most, each with its prediction written first.

## Structure over count

The score (`match_check.py`'s share of equal instructions) is a byproduct.
What converges is structure: a register-allocation, scheduling or
store-merging class snapping into the base's form, often raising the raw
count while a neighbouring class is disturbed, then collapsing in a group
when the upstream cause lands. Keep an edit that makes a class match or
fixes a whole-function property even when the count rises; keep a
structurally-forward state as the working base even when a lower-count
state exists; never select a branch on count. The size of the function
against the base's is a hard signal: an edit that moves it away is a
regression whatever else improves.

## Crutches

A crutch is anything that emits no bytes of its own and exists to steer the
compiler rather than to express what the code does. The ban is a test, not
a list: register pins, empty or register-only inline assembly, dead stores
after the last read, orphan carrier locals, pragmas or attributes that
change codegen, `volatile` applied to a value the program never treats as
volatile, a declaration trick that changes the calling convention, a block
scope or storage class that exists only to move a live range. Each is
spelled as ordinary C++ and each is the same crutch renamed. A barrier may
be used once as a throwaway diagnostic to prove a body is reachable, then
reproduced in real code before anything is saved. Legitimate: `volatile` on
data the program's own logic treats as volatile (a value another thread or
the hardware writes), with its reason in a comment; a store to a real field;
the engine's own idioms. The question to ask of every line: would the
engine's developer have written this to express what the function does?

## The compiler is fixed inside the loop

Within the matching loop the compiler and the flags of the prefix are fixed
and correct, and a residual is a source shape not yet found. "This LLVM
would never emit that order", "needs a different release", "a flag the
developer used" are not conclusions a function can reach on its own: the
compilers were chosen and the flags set from measurements over the whole
executable (`docs/DECISIONS.md` D6, `tools/fingerprint.py`), and one
function's diff is a hint about that evidence, never a verdict. No flag is
ever tried per file or per function; `config/flags.base.txt` is per prefix
and changes only under the standard in `docs/DECISIONS.md`. When a residual
is believed to be the compiler's, the finding goes to `docs/NOTES.md` as a
classified mechanism (which pass, which input, the base's bytes, what was
compiled) with the function left unclaimed, and the question is decided
across the region with the probe and the fingerprints, not inside the round.
A matched sibling of the same shape under the same flags is the usual proof
that the shape exists.

## Talk to the compiler

The LLVM the prefix compiles with is staged as source under
`tools/cc/src/llvm-<version>.src/` (`tools/build_llvm.sh`), and the
from-source build reproduces the prebuilt byte for byte. Read the pass
first-party when a divergence resists: state the pass's required input as a
predicate over its own variables (what `MachineScheduler` orders by, what
`GreedyRegAlloc` evicts on, when `DAGCombiner` merges two stores, when the
inliner's threshold admits a callee), mark each condition satisfied or not
on the current TU from the dumps, and derive backwards from the unsatisfied
condition to the source construct that establishes it. Dumps: `-S -emit-llvm`
for the IR the back end sees, `-mllvm -print-after-all` for every machine
pass, `-mllvm -print-before=<pass>`, `-Rpass=inline` and
`-Rpass-missed=inline` for inlining decisions, `-fno-discard-value-names`
to keep names in the IR. A decisive fact is usually one line of compiler
source that no amount of inference from the output would have surfaced.

## Evidence discipline

- A claim becomes a fact with independent sources: the compiler's code, a
  dump of your own TU, the base's own bytes. One source is a hypothesis and
  is labelled as one.
- Pre-register the falsifier before adopting a reading; a probe that
  satisfies one instrument and contradicts another is the false positive this
  method keeps catching.
- A corrected premise retracts every conclusion built on it; re-open them
  explicitly and record the re-opening.
- A fitted regularity is one-directional until the converse is tested on a
  case where the left side holds and the right does not.
- Record mechanisms and measurements, never prohibitions. "The hoist happens
  unconditionally under this source, dumps attached" is durable; "therefore
  do not look for a shape that stops it" freezes a solvable class. Say what
  was compiled; a model-derived closure with nothing compiled is labelled so.
- Re-derive any number you rely on this session; an inherited gate that was
  never measured has been wrong before.

## When a round ends without a match

There is no stall gate, no skip and no floor. A function that did not match
in one worker's context is resumed by a fresh one from the saved state: the
TU at its best structure-forward form, a round entry in `docs/NOTES.md`
naming what landed, the exact residual as a map (classes, sizes, the
mechanism measured for each) and the next reasoned lead, never a list of
failed spellings and never an instruction not to try. The function is never
claimed until the gate passes; `src/.../unknown/` keeps the work in progress
with a `// NONMATCHING: <residual>` comment on the definition so the tree
compiles and the dashboard counts it unmatched.

## Codify what is learned

When a landing used a mechanism the local cookbook (`docs/COOKBOOK.md`,
gitignored) does not hold, add one entry: the base's shape, the source form
that produced it, the compiler mechanism with its source location. A
landing that reused known mechanisms needs nothing. A tooling or layout fact
goes to `docs/NOTES.md`. The cookbook is what the next worker greps before
writing C++ for the same shape.
