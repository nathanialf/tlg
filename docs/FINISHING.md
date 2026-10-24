# Finishing

What happens when every function of a region, then of the executable, is
rebuilt from source: the pass that turns a matched tree into the
developer's tree, and the release that follows. Carried over from the ICO
project's finishing rules and its Phase 2 tickets, adapted to this target,
and written down before the first region is complete so the end state is
the standard from the start (`docs/DECISIONS.md`).

## Phase 1 ends when

`config/matched.base.txt` claims every row of `config/functions.base.txt`
and `config/data.base.txt` every data object of the segments, the layout
gate reports every segment from source with nothing from the base but what
the linker made (PLT, GOT, dynamic tables), and the dashboard reads 100 %.
Until then the finishing tickets below run per region as it completes
(libraries first, since the game depends on their types), never on a held
function: a region held at its last unmatched rows gets no finishing pass;
it gets the rows matched.

## Standing rules for a finishing worker

Read before the ticket. One worker, one ticket, its own worktree; the
supervisor harvests, gates and commits.

1. The gate is the truth. Nothing lands that moves a byte unless the ticket
   says re-match and the worker re-matches it. Gate output is reported
   verbatim.
2. Developer-native only (`CLAUDE.md`, `docs/MATCH.md` "Crutches",
   `tools/check_dev_native.py`). The test: would the engine's developer have
   written this line to express what the code does?
3. Names are the executable's: a string, an export, a vtable, an import's
   verified NID, a class name in a type-info string. A name derived from
   context carries `/* derived name */` on its definition line; a record
   whose fields are named from their use carries one `/* field names
   derived */` on its opening line. Sony's public API types keep their public
   names.
4. Field names. A field named after its offset (`unknown0x68`, `word830`)
   is a placeholder of the same class as `D_<hex>` and ends the pass renamed
   from what it is: its writers and readers, the strings and callers around
   it, the unit it carries. Pads are `pad<N>`. No new offset-named field from
   the finishing pass on; a field whose meaning the accessors do not fix is
   named by type and role as a last resort and listed in the report.
5. Decimal where the developer typed decimal; masks and hardware values stay
   hex.
6. Headers for shared declarations, no stray `extern` in a `.cpp`, no
   include-only `.inl` that the executable does not attest, no `.h` that
   exists to make a match compile. Declaration, definition and every caller
   agree on the signature; every parameter is used or the signature is
   wrong.
7. Getters are checked for a return value against the bytes: does the
   function write `rax`/`xmm0` at every return and does a caller read it?
   Where yes, it gets the type and the callers read it; where no, it stays
   `void` or returns through its out-parameter.
8. Sony's API is called by its public names through headers of our own
   (`src/include/sce/...`), never Sony's headers. Hardware and system
   constants are named once in our headers and used by name.
9. `tools/format.sh` before the gate; the gate after it.
10. Warnings are corrected, not counted. A clean build's clang warnings are
    each fixed at the source the way the developer would have written it (a
    prototype with the types its definition and callers use, the header
    included before the use, the cast the code already spells elsewhere). A
    fix lands only if every object it touches is byte-identical (the layout
    gate says so); a warning no byte-neutral faithful fix removes stays, with
    its reason in the report. Never `-w`, pragmas, flags or a cast that makes
    code the developer evidently did not write look intended.
11. Replicate the developer's source and build. A file split, a file name,
    a directory, a record, a build invocation is what this developer wrote
    and how it was compiled: the source roots the executable names
    (`docs/SURVEY.md`), the engine's naming in its strings, the compiler and
    flags of the region. A measurable constraint (a byte, a hash, an
    address) selects among candidates that fit the convention; it never
    generates a candidate on its own.
12. Compiling is never wasted; guessing is. Write the expected change before
    each compile.
13. Never write into `tools/` or `config/` unless the ticket names the file;
    scratch goes to the scratchpad under the ticket's name. No sub-workers.
14. Land often: a batch is reported at about forty changed files or two
    hours, whichever comes first.
15. Report: what landed, the gate output, what did not land and its exact
    state, the files touched; under four hundred words; nothing unmeasured.

## The tickets

In this order, per region then for the whole:

- **F1 Idle lists.** `config/matched.base.txt` and `config/data.base.txt`
  carry every row; nothing is read from the base at build time but the
  linker's own output. Any `// NONMATCHING` marker is gone.
- **F2 to F5 Review sweeps**, one ticket per source root (`src/libs/<lib>`,
  `src/game/anzu/...`, `src/game/sndx`, ...): stale prototypes, carve-time
  and matching-era comments, derived-name marks checked against the
  executable's strings, placeholders renamed (rule 4), hex to decimal (rule
  5); every byte unchanged.
- **F6 Stale declarations.** Declarations nothing in the link defines or
  names are removed; headers that held only them go.
- **F7 File conventions.** Encodings, line endings and the include order the
  developer's tree shows; `.clang-format` applied everywhere.
- **F8 Docs for the finished build.** README, BUILDING, LEGAL, TARGETS,
  MATCH, DECISIONS and the docs index describe a tree built wholly from
  source; what stays unverified is stated (an ordering the bytes cannot fix,
  a name the strings do not attest). Plain, short, accurate.
- **F9 Warnings** (rule 10), with the byte-neutral check per fix.
- **F10 Fresh-clone build.** A clone with nothing but the package symlink
  runs `./build.sh` to a green gate, on a machine that has never built the
  tree.
- **F11 Release.** Tag `base-v1.0.0` on `main`, a GitHub release that names
  the base files' SHA-256s and the compilers, the dashboard at 100 %.
- **F12 Join.** With one target there is nothing to join. A second target
  (the 1.03 patch, another region) joins as ICO's did: its differences
  inline in the shared files as `VERSION_<SLUG>` blocks, never a per-target
  copy; its progress on the dashboard read from its own frozen branch.
- **F13 Names.** The last pass over every `FUN_`, `D_` and derived name:
  each either attested, or derived and marked, with the evidence in the
  report.
- **F14 Retire the matching scaffolding**, as ICO's commit 695c86a8f did:
  the compiler probe, the other LLVM releases, the probe batches, the
  fingerprint tool, the match-era notes, leaving the build as the tracked
  flags, the two compilers, the layout and the gate. `docs/DECISIONS.md`
  and the probe tables in `docs/TARGETS.md` stay as the record.
- **F15 Review.** A code review of `src/` on the newest opus-tier model at
  high effort, fixes applied under the gate, once, after every other ticket.

## What a hold looks like

A region that stops short (one function the compiler cannot reproduce,
classified under `docs/DECISIONS.md` and left unclaimed) is documented as
such in F8's terms and released as `base-v1.0.0-rc` at most. It is not
finished; the dashboard says so; ICO's rule for its held branches was no
F1, no F11, no F12 until the last row matched, and it holds here.
