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
