# Matching a function

The unit of work is one function of the base executable
(`config/functions.base.txt`: address, size, name). The claim is a row in
`config/matched.base.txt`; the proof is `tools/check_elf.py --gate`.

## The loop

1. **Pick a function.** `config/functions.base.txt` lists every one;
   `docs/base/progress.json` (and the dashboard) show which are unclaimed.
   Start with leaves: small functions with no calls. Disassemble it:

   ```sh
   llvm-objdump-19 -d --x86-asm-syntax=intel --start-address=0x104b0 --stop-address=0x104c0 baserom/base/eboot.elf
   ```

2. **Find or make its translation unit.** If an assert string, a vtable or a
   caller places the function in a source file the executable names
   (`docs/SURVEY.md`), it goes in `src/<root>/<path>.cpp` at that path. If
   not, it goes in `src/unknown/<name>.cpp`, one function per file, until a
   home is found. Shared types go in `src/include/`.

3. **Write the C++** as the developer would have. Types and fields from how
   the code uses them; names from facts in the binary (a string, an export)
   or derived and marked `/* derived name */`. No construct that exists only
   to steer the compiler (`CLAUDE.md`, "Rules").

4. **Diff until equal.**

   ```sh
   tools/quick_diff.sh src/unknown/leaf_000104b0.cpp FUN_000104b0 _Z12FUN_000104b0P10PairRecord
   ```

   compiles the TU with the target's flags (`config/flags.base.txt`,
   `tools/compile_cpp.sh`) and prints the first differing instruction with
   five of context on each side. A relocated field (a RIP-relative
   displacement, a call target, a GOT or PLT slot) is masked on both sides,
   so a `call` to a function not yet named compares by its encoding, not
   its target. The third argument is the object's symbol when it differs from
   the row's name (a mangled C++ name behind a `FUN_` row).

5. **Claim it.** Add `<function> <tu> [<symbol>]` to
   `config/matched.base.txt`. `tools/build.sh regen` if the TU is new, then
   `./build.sh`: ninja compiles the tree and the gate compares every claimed
   function. Commit; the pre-commit hook runs the gate and refreshes the
   progress files.

6. **Rename when known.** When a function's real name is found, rename its
   row in `config/functions.base.txt` to the mangled symbol, drop the third
   column of its `matched` row, and move the file out of `src/unknown/`.

## Data

A global the code references is named `D_<hex>` (its address in the base)
until its real name is known, and that name alone lets the layout resolve
the reference. To rebuild the object itself, define it as typed C++ in a TU
under that name (a struct, an array of records, a string: never a byte
array, which `tools/check_no_rom.sh` refuses) and add
`D_<hex> <tu> [<symbol>]` to `config/data.base.txt`. The gate lays the
object's bytes at the address, resolves its pointer fields (each must sit on
a slot the base relocates), and requires the segment byte-identical. An
object in `.bss` has no bytes and counts as owned. Game content (tables,
strings, assets) is never committed in any form (`docs/LEGAL.md`).

## When it will not match

- **A flag, not the code.** If a whole family of functions differs the same
  way (a different `-O` level's scheduling, frame pointers, a vectorizer
  decision), the compiler or its flags are wrong for that prefix, not the
  C++. Change `config/flags.base.txt` for the prefix, never for the file, and
  re-run the gate: every function already matched under the old flags must
  still match, or the change is wrong.
- **The compiler itself.** Orbis clang 3.508 is not a public release
  (`docs/TARGETS.md`). A difference that no source change and no flag removes
  is recorded in `docs/NOTES.md` (local) with the function, and the function
  is parked: its row stays out of `matched`, its C++ stays in the tree with a
  `// NONMATCHING: <why>` comment on the definition. The gate ignores
  unclaimed functions; the dashboard counts them as unmatched.
- **Inlined callees.** The original's inlining decisions were the Orbis
  compiler's. A callee that appears inlined in the base must be written so
  the public clang inlines it too (`inline` in a header, or the same TU), not
  pasted in by hand.

## What the tools compare

`tools/match_check.py` disassembles the compiled function (from the object's
symbol, with its `.rela.text` entries) and the base's bytes at the function's
address (capstone, x86-64), walks the two instruction streams in step, and for
each instruction that carries a relocation in the object zeroes the field the
linker would fill on both sides. Instructions equal after that masking count;
the score is their share over the longer stream, and 1.0 is a match. Sizes
differing is a difference. Nothing else is masked: an immediate, a stack
offset or a register choice that differs is a real difference.

The masked fields are then checked for real where the base can place the
symbol (`tools/base_elf.py`): a call to `FUN_x` must encode `FUN_x`'s
address in the base, a reference to `D_<hex>` that address, a call to an
import its PLT stub, a GOT load its slot. A wrong target fails the function
whatever the score, so a callee or a data label is never a guess that
happens to encode the same way.

The gate goes one step further (`tools/layout_link.py`, `docs/DECISIONS.md`
D7): it rebuilds the whole text segment, every claimed function at its
address with its relocations resolved, everything else from the base, and
requires the image byte-identical to the base. A string literal the TU
defines resolves to the one place the base holds those bytes; a data
reference needs a `D_<hex>` name (its address in the base); a relocation the
resolver cannot place fails the function with a message. An `objdiff` view of
a TU against a carved target object is possible (`tools/ext/objdiff/`) and
not part of the gate.
