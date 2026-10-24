# Legal notes

What this repository may contain, what it must never contain, and which
references its source is written from.

This is a community decompilation project. It is not affiliated with,
endorsed by, or sponsored by Sony Interactive Entertainment Inc., Sony Group,
genDESIGN Inc., Japan Studio, or any of their affiliates. *The Last Guardian*
and *PlayStation 4* are trademarks of their respective owners.

## What is in this repository

- C++ source written for this project, which a public clang compiles into
  functions that match the game's executable.
- Build scripts and tooling written for this project.
- Documentation written for this project.
- Configuration that describes how the user's own package is checked and how
  the rebuilt functions are compared: the SHA-256s of the expected files
  (`config/sha256sums.base.txt`), the list of the executable's functions as
  address, size and name (`config/functions.base.txt`), the functions claimed
  as matched with their translation unit (`config/matched.base.txt`), and the
  compiler flags per source prefix (`config/flags.base.txt`).
- The survey of the executable's structure (`docs/SURVEY.md`): program
  headers, counts, the SDK version, the libraries it links and imports, and
  the paths of the developers' own source files that the executable names.
  Those are facts about the file, in the way a linker map's addresses are.

## What is not in this repository, and must never be added

- The game package (`.pkg`) or any file from it, in whole or in part:
  `eboot.bin`, the modules under `sce_module/`, `param.sfo`, `sce_sys/`, the
  `trico_*.psarc` archives or anything extracted from them.
- The executable in any form, SELF or ELF, or any part of its bytes.
- Audio, images, textures, models, shaders, text or other assets from the
  package.
- The game's data tables (next section).
- Symbol tables, NID tables, strings or other identifier tables, and any
  debug string, asset or code blob, copied verbatim or in bulk out of the
  executable or the package. Using an individual fact (a name, an offset, a
  `__FILE__` path) as a reference is covered under "Identifiers as references"
  below; this item forbids copying a table of them into the repository.
- Any code believed to derive from leaked source, a leaked SDK, or a leaked
  SDK header.

`.gitignore` and `tools/check_no_rom.sh` (run by the pre-commit hook) make it
harder to commit such material by accident. They do not replace care. If you
suspect a file in this repository breaks these rules, open an issue tagged
`legal`.

## Data

The game's content lives in the `trico_*.psarc` archives and in the data
segments of the executable (tables, strings, shader binaries). None of it is
committed in any form, as C++, as assembly or otherwise. The build does not
yet reproduce any data segment; when it does, data-only ranges will be
generated at build time from the user's own executable, as the sibling ICO
project does, with only types, counts and names committed. A count or size
derived from a table is an ordinary fact about it.

## Public reverse-engineering material (allowed as references)

Published reverse-engineering material may be consulted as a reference for
naming and structure: conference talks, blog posts and articles, public
Ghidra projects with clear non-leaked provenance, the public PS4 developer
wiki's descriptions of file formats (SELF, PKG, PFS, the SCE ELF extensions),
and academic papers on x86-64 code generation. Treat them like academic
papers: read, understand, then re-derive from the disassembly. Never paste
their code, comments or symbol names into this repository.

Public source code under an open licence is used the same way. The PS4's
system library APIs are documented publicly by name in the open-source
homebrew toolchains; a name from them may be attached to an import after the
NID computed from that name equals the NID in the executable. That is
verifying a fact, not copying a table.

## Identifiers as references: facts, not expression

Facts observable in a copy you legally own (function and symbol names, struct
field offsets and sizes, array strides, `__FILE__` paths in the executable's
strings, the SDK version in its headers) are not copyrightable expression.
They may inform original code: read, understand, re-derive. Never commit the
source artifact, and never paste a table of identifiers in bulk.

- **Allowed:** reading the legally owned executable, or a public decomp of
  clean provenance, and re-deriving names and shapes into your own code.
- **Forbidden:** committing the package, the executable, asset bytes, or a
  symbol, NID, string or debug table in whole or in bulk; and any use of
  leaked source, leaked SDKs, or leaked prototype or debug builds (below). A
  retail copy you own is never in that category.

## Forbidden inputs

These may never be used as inputs to this project, even indirectly:

- Sony's PlayStation 4 SDK (Orbis SDK), its headers, libraries, compiler or
  documentation, in any version, however obtained. The SDK is licensed to
  registered developers only; this project has no such licence and uses none
  of it. The public clang's `x86_64-scei-ps4` target is upstream LLVM.
- Leaked source code from any party, including any of genDESIGN's, Japan
  Studio's or Team Ico's titles, however obtained.
- Leaked prototype or debug builds of the game.
- Paid asset extractors that bundle game data.

If you have ever read any of the above, say so on your first pull request so
your contributions can be reviewed for provenance.

## The package and the executable (`base`)

The target is the EU retail base game 1.00 (`CUSA03745`). The build reads
the user's own copy of its package: `eboot.bin`, to convert to a plain ELF
(`tools/unfself.py`, which unwraps the fake-signed SELF container; it
decrypts nothing and refuses an encrypted one), to hash and to compare the
rebuilt functions against; `sce_sys/param.sfo`, to check the content id and
version; and `sce_module/*.prx`, which it copies and hashes. The package's
filesystem is extracted by LibOrbisPkg's PkgTool (MIT) because the executable
lives inside its PFS image; the game's archives come out with it and are
never read. `tools/extract_pkg.sh` writes everything under gitignored
`baserom/`.

The executable is stripped: it has no symbol table but the dynamic imports,
which are NIDs. Names in this tree come from facts in the executable (assert
and log strings, class names in RTTI or vtables, exported entry points) or
are derived and marked `/* derived name */`. No address is copied from any
file other than the user's own executable: every address in `config/*.base.*`
was found in it by `tools/survey_elf.py`.

## What you need to build

You must legally own a copy of *The Last Guardian* for the PlayStation 4 and
supply the package yourself. The build checks the executable's SHA-256 before
it proceeds and refuses any other file (`config/sha256sums.base.txt`,
`docs/BUILDING.md`). A SHA-256 is a fingerprint, not a copy of the work; the
package and the executable remain the property of their rightsholders.

This project gives no instructions for obtaining a package, dumping a
console or packaging a dump. The only legitimate source is a personal dump of
a game you own, made in compliance with the law where you live. The build
needs the executable in fake-signed (unencrypted) form, which is how a
personal dump packaged for a homebrew-enabled console ships it; this project
holds no key material and decrypts nothing.

## Why decompilation projects can exist

Projects of this kind have a long history (Super Mario 64, Ocarina of Time,
Majora's Mask, Paper Mario, Sly Cooper, Jak and Daxter, Kingdom Hearts, ICO
and many more). They produce original source code by reverse engineering,
distribute no copyrighted assets, and require users to bring their own copy.
This project follows the same model.

If you represent a rightsholder and have a concern, please open a GitHub
issue.
