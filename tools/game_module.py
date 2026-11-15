#!/usr/bin/env python3
"""
game_module.py: build the game region as one module, in two stages
(docs/DECISIONS.md D50, whose one pipeline D83 supersedes).

The game and engine (src/game/, 0x1a3e00 up) were compiled unit by unit and
then optimised together at the link: a function's code shows what other game
files define (an empty member destructor in another file inlined, a callee
that returns 1 in another file propagated) and reaches the game's own
objects PC-relative while the libraries' stay behind the GOT; and it shows
what each unit's own optimiser had already decided before the link saw the
rest (a deleting destructor that calls a complete destructor the one
pipeline would inline, an inline member's unused argument dropped). The gate
builds it the same way:

    1. Every game translation unit to unoptimised bitcode by the front end
       at -O2 (tools/compile_cpp.sh --ir: `-Xclang -disable-llvm-optzns`),
       under the unit's line of config/flags.<slug>.txt
       (`-fvisibility=protected -ffunction-sections` among its flags), with
       the same module as text beside it, which this tool reads for what each
       unit defines and declares and for the declared types; and STAGE 1,
       the unit's own -O2 pipeline over that bitcode by the same compiler
       and flags line, to build/<slug>/game/unit/<path>.bc (the same edge
       and script): what a compile of the unit alone gives before code
       generation.
    2. The stand-ins: an object some file declares and no file defines gets a
       generated definition when config/modules.<slug>.txt
       (tools/module_boundary.py) puts its base address in the game's part of
       the data: protected, writable, zero-initialised, of the declared type
       and alignment, in a module of its own (build/<slug>/game/standins.ll)
       linked in last. A thread-local stand-in is protected like the rest:
       the game compiler keeps a protected thread-local general-dynamic, as
       the base's code is (D23, D51). A library object, an import, a
       library vtable and a name without a base address stay declarations
       (the GOT and PLT forms). An opaque class (a declaration whose type no
       file completes) is completed as one byte.
    3. llvm-link (built from the game compiler's own source, tools/cc/
       llvm-<version>-src-tools/bin) links every unit's stage 1 bitcode and
       the stand-ins into one module, in the sources' order.
    3a. What the link made local, in one step (`opt -internalize` with
       every other definition of the module on its preserved list; the
       list is the module's own symbol table, and the table is read again
       afterwards: exactly these names went local):
       - The local data (config/local_data.<slug>.txt, D74): a variable of a
         row was local to the optimiser when the base was built (its reads
         take one bit: GlobalOpt's shrink, which needs local linkage),
         though every file declares it. Each row the module defines is
         proven from the base's code (tools/module_boundary.py local_proof;
         a row that fails is a refusal, with what the base shows). While
         the variable's definition is a stand-in, the stand-in carries one
         writer, `__standin_writer_<symbol>`, storing 1: the base's code
         stores 1 somewhere (the proof says so), the files written so far
         may not, and a local variable nothing sets is folded to its initial
         value. The writer is the gate's, like the stand-in, and goes when a
         file defines the variable.
       - The used inline definitions: a linkonce_odr or weak_odr definition
         (an inline function, a template's instantiation, a class's inline
         vtable) that another definition of the module names. Once every
         unit is linked nothing outside the module can name one, and the
         base shows them local (a container's clear(unsigned) with its
         argument folded in, an inline destructor dropped after its last
         call was inlined). One that nothing in the module names stays as it
         is: the module is unfinished, and a claimed function whose callers
         are not written yet would be deleted. A function the source
         defines with external linkage is never made local (D50's addendum:
         the base keeps returns no caller reads).
    4. STAGE 2, the link's pipeline over the module: `opt -std-link-opts
       -vectorize-loops -vectorize-slp` (PassManagerBuilder::
       populateLTOPassManager at its stock thresholds, with the two
       vectorisers on as libLTO's LTOCodeGenerator::optimize sets them)
       by the opt built from the game compiler's own patched source
       (tools/build_llvm.sh, beside llvm-link; TLG_OPT names another copy).
    5. Code generation alone over the result, to one object
       (tools/compile_cpp.sh --codegen: the IR pipeline off),
       build/<slug>/game/module.o.

It refuses, naming the files: a name two files define with external
linkage (llvm-link would say only the name), and a thread-local a game file
defines (it would be accessed local-dynamic). It writes
build/<slug>/game/symbols.txt, `<tu> <symbol> <linkage>` for every
definition of every file, which the gate reads to check a row's unit
defines its symbol (tools/match_check.py tu_functions), and the list of
internal names two files define (`renamed`): the link gives the second a
`.N` suffix, so a row or data claim naming one is refused.

A name the compiler gives (COMPILER_LOCAL: clang's array-destroy helper
`__cxx_global_array_dtor`, `.1`, `.2` in the unit's own order) is the
exception: no source can rename it, and ten units define one. Its row names
the unit's own symbol (what the unit's IR and its single-file object call
it, which depends on that unit alone), and the gate finds the module's
symbol for it by proof, never by the link's numbering:
tools/match_check.py compiler_local_aliases, from the unit's IR
(function_refs) and the module object's relocations.

    game_module.py --out build/base/game/module.o <a.bc>... | @<list>   the module (ninja's edge)
    game_module.py --out <obj> --single <a.bc>                 a module of one file and its stand-ins,
                                                               through both stages (the inner loop's
                                                               pre-screen, tools/quick_diff.sh: it shows
                                                               the unit nothing another file defines)

The stand-ins, the linked module and the object are build products, never
committed.
"""
from __future__ import annotations

import argparse
import os
import re
import subprocess
import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(Path(__file__).resolve().parent))
from tlg_version import build_dir, detect_version  # noqa: E402

MODULE_PREFIX = "src/game/"



def _line_version() -> str:
    """The LLVM release of the game line's compiler: the `cxx=<version>-src`
    of the src/game/ line of config/flags.<slug>.txt (3.7.1, the game line's
    release since D81, when it names none). Bitcode is read only by its own release's tools."""
    flags = REPO_ROOT / "config" / f"flags.{detect_version(REPO_ROOT)}.txt"
    for line in flags.read_text().splitlines():
        parts = line.split()
        if len(parts) >= 2 and parts[0] == MODULE_PREFIX and parts[1].startswith("cxx="):
            return parts[1][len("cxx="):].removesuffix("-src")
    return "3.7.1"


# llvm-link and opt built from the line's own patched source
# (tools/build_llvm.sh), so the link stage's passes are the compiler's own;
# llvm-nm of the same release as fetched (tools/fetch_llvm.sh)
LLVM_LINK = f"tools/cc/llvm-{_line_version()}-src-tools/bin/llvm-link"
LLVM_OPT = f"tools/cc/llvm-{_line_version()}-src-tools/bin/opt"
LLVM_NM = f"tools/cc/llvm-{_line_version()}/bin/llvm-nm"
STANDIN_WRITER = "__standin_writer_"
LINKAGES = {"private", "internal", "available_externally", "linkonce", "weak", "common", "appending",
            "extern_weak", "linkonce_odr", "weak_odr", "external"}
LOCAL = {"private", "internal"}
ODR = {"linkonce_odr", "weak_odr"}
SHARED = {"linkonce", "weak", "common", "linkonce_odr", "weak_odr", "appending"}
NAME = r'(?:"(?:[^"\\]|\\.)*"|[-a-zA-Z$._0-9]+)'
TYPE_LINE = re.compile(r'^(%' + NAME + r') = type (.*)$')
GLOBAL_LINE = re.compile(r'^@(' + NAME + r') = (.*)$')
DEFINE_LINE = re.compile(r'^define ([^@]*)@(' + NAME + r')\(')
TYPE_REF = re.compile(r'%' + NAME)
DECL = re.compile(r'^external ((?:hidden |protected |default )?)((?:dllimport )?)((?:thread_local(?:\([a-z]+\))? )?)'
                  r'((?:local_unnamed_addr |unnamed_addr )?)((?:addrspace\(\d+\) )?)((?:externally_initialized )?)'
                  r'(global|constant) (.*?)(, align \d+)?$')


# The internal function names the compiler gives, not the developer: clang
# 3.7.1's destroy helper of a static array of a class with a destructor
# (CGDeclCXX.cpp:595, generateDestroyHelper), which the unit's module numbers
# `.1`, `.2` on a second and third (ValueSymbolTable::reinsertValue), and
# which llvm-link renames again, by one counter over the whole link, when an
# earlier unit holds the name; and the static initializer of a namespace-scope
# object, `__cxx_global_var_init` (`.1`, ... in the unit's order,
# CGDeclCXX.cpp EmitCXXGlobalVarDeclInitFunc), which the unit's
# `_GLOBAL__sub_I_<file>` calls (EmitCXXGlobalInitFunc, the name from the main
# file's name) and which the -O2 pipeline inlines there. The unit's `.N`
# comes from one counter over its names, so a file's initializers and helpers
# interleave (`__cxx_global_var_init`, `__cxx_global_array_dtor`,
# `__cxx_global_var_init.1`, `__cxx_global_array_dtor.2`). A developer's static
# is not one of these: a collision of one is refused as before
# (docs/DECISIONS.md D50, D56).
COMPILER_LOCAL = re.compile(r"^(?:(?:__cxx_global_array_dtor|__cxx_global_var_init)(?:\.\d+)*|_GLOBAL__sub_I_.+)$")
COMPILER_BASE = re.compile(r"(?:\.\d+)+$")
REF = re.compile(r"@(" + NAME + r")")
ALIAS = re.compile(r"^(?:[a-z_]+(?:\([a-z0-9]+\))? )*alias ")


def compiler_local(name: str) -> bool:
    return bool(COMPILER_LOCAL.match(name))


def compiler_kind(name: str) -> str:
    """A compiler-given name without the `.N` the unit or the link added:
    two names of one kind are the same function of different units, or of
    one unit in its order."""
    return COMPILER_BASE.sub("", name)


def function_refs(path: Path) -> dict[str, set[str]]:
    """function name -> every global its body in the IR text `path`
    references by name (the `define` line to the closing brace)."""
    out: dict[str, set[str]] = {}
    cur: set[str] | None = None
    for line in path.read_text().splitlines():
        if cur is None:
            if line.startswith("define "):
                m = DEFINE_LINE.match(line)
                if m:
                    cur = out.setdefault(unquote(m.group(2)), set())
                    body = line[m.end():]
                    cur.update(unquote(x) for x in REF.findall(body))
                    if body.rstrip().endswith("}"):
                        cur = None
        elif line.startswith("}"):
            cur = None
        else:
            cur.update(unquote(x) for x in REF.findall(line))
    return out


def module_dir(ver: str) -> Path:
    return build_dir(REPO_ROOT, ver) / "game"


def ir_path(tu: str, ver: str) -> Path:
    """The unoptimised bitcode of a game unit (tools/compile_cpp.sh --ir);
    the same module as text is beside it, with .ll for .bc."""
    return module_dir(ver) / "ir" / (tu + ".bc")


def unit_path(tu: str, ver: str) -> Path:
    """Stage 1 of a game unit: its bitcode after its own -O2 pipeline
    (tools/compile_cpp.sh --ir writes it with the unoptimised one)."""
    return module_dir(ver) / "unit" / (tu + ".bc")


def module_object(ver: str) -> Path:
    return module_dir(ver) / "module.o"


def single_object(tu: str, ver: str) -> Path:
    return module_dir(ver) / "single" / (tu + ".o")


def unquote(name: str) -> str:
    if name.startswith('"'):
        return re.sub(r"\\([0-9A-Fa-f]{2})", lambda m: chr(int(m.group(1), 16)), name[1:-1])
    return name


class Unit:
    """What one file's IR defines and declares, and its named types."""

    def __init__(self, path: Path, tu: str):
        self.path, self.tu = path, tu
        self.types: dict[str, str] = {}          # %name -> body text
        self.defs: dict[str, tuple[str, bool]] = {}   # name -> (linkage, thread_local)
        self.decls: dict[str, re.Match] = {}     # name -> DECL match
        self.avail: set[str] = set()             # available_externally globals
        for line in path.read_text().splitlines():
            if line.startswith("%"):
                m = TYPE_LINE.match(line)
                if m:
                    self.types[m.group(1)] = m.group(2)
            elif line.startswith("@"):
                m = GLOBAL_LINE.match(line)
                if not m:
                    continue
                name, rest = unquote(m.group(1)), m.group(2)
                d = DECL.match(rest)
                if d:
                    self.decls[name] = d
                    continue
                first = rest.split(" ", 1)[0]
                linkage = first if first in LINKAGES else "external"
                if linkage == "available_externally":
                    self.avail.add(name)
                    continue
                words = re.match(r"^((?:[a-z_]+(?:\([a-z0-9]+\))? )*)(?:global|constant|alias|ifunc) ", rest)
                self.defs[name] = (linkage, bool(words and "thread_local" in words.group(1)))
            elif line.startswith("define "):
                m = DEFINE_LINE.match(line)
                if m:
                    words = m.group(1).split()
                    linkage = words[0] if words and words[0] in LINKAGES else "external"
                    if linkage != "available_externally":
                        self.defs[unquote(m.group(2))] = (linkage, False)


def tu_of(path: Path, ver: str) -> str:
    rel = path.resolve().relative_to((module_dir(ver) / "ir").resolve())
    return str(rel)[:-len(".bc")]


class Refusal(Exception):
    pass


def check_units(units: list[Unit]) -> tuple[list[str], list[str]]:
    """(symbols.txt lines, renamed internal names); raises Refusal on a name
    two files define with external linkage or a thread-local definition."""
    strong: dict[str, str] = {}
    local: dict[str, list[str]] = {}
    lines, errors = [], []
    for u in units:
        for name, (linkage, tls) in sorted(u.defs.items()):
            lines.append(f"{u.tu} {name} {linkage}")
            if linkage in LOCAL:
                if linkage == "internal":
                    local.setdefault(name, []).append(u.tu)
            elif linkage not in SHARED:
                if name in strong:
                    errors.append(f"{name} is defined by both {strong[name]} and {u.tu}")
                else:
                    strong[name] = u.tu
    if errors:
        raise Refusal("\n".join(errors))
    renamed = sorted(n for n, tus in local.items() if len(tus) > 1 or n in strong)
    return lines, renamed


class TypeTable:
    """The named types of the stand-in module: every type a stand-in needs,
    copied from the file that declares it under a name of its own
    (`%"s<k>.<name>"`), so two files' different bodies for one name never
    meet; llvm-link maps each to the declaration's type by structure."""

    def __init__(self, units: list[Unit]):
        self.units = units
        self.index = {id(u): k for k, u in enumerate(units)}
        self.memo: dict[tuple[int, str], str] = {}
        self.lines: list[str] = []
        self.opaque: list[str] = []

    def body_unit(self, u: Unit, t: str) -> Unit | None:
        if t in u.types and u.types[t] != "opaque":
            return u
        return next((o for o in self.units if o.types.get(t, "opaque") != "opaque"), None)

    def name(self, u: Unit, t: str) -> str:
        src = self.body_unit(u, t) or u
        key = (self.index[id(src)], t)
        if key in self.memo:
            return self.memo[key]
        bare = t[1:].strip('"')
        new = f'%"s{key[0]}.{bare}"'
        self.memo[key] = new
        body = src.types.get(t)
        if body is None or body == "opaque":
            self.opaque.append(f"{bare} ({u.tu})")
            body = "{ i8 }"
        self.lines.append(f"{new} = type {self.subst(src, body)}")
        return new

    def subst(self, u: Unit, text: str) -> str:
        return TYPE_REF.sub(lambda m: self.name(u, m.group(0)), text)


def standins(units: list[Unit], ver: str, base=None, table=None, local=()) -> tuple[str, list[str]]:
    """(the stand-in module's text, a log line per declaration considered).
    `local`: the rows of config/local_data.<slug>.txt; a stand-in for one
    carries its writer."""
    from base_elf import BaseElf
    from module_boundary import load, owner_of
    base = base or BaseElf(REPO_ROOT, ver)
    table = table or load(ver)
    defined = set()
    for u in units:
        defined |= set(u.defs)
    decls: dict[str, list[tuple[Unit, re.Match]]] = {}
    for u in units:
        for name, d in u.decls.items():
            if name not in defined:
                decls.setdefault(name, []).append((u, d))
    types = TypeTable(units)
    out, log = [], []
    for name in sorted(decls):
        addr = base.merged_row_address(name)
        if addr is None:
            addr = base.address_of(name)
        owner = owner_of(table, addr)
        where = f"0x{addr:x}" if addr is not None else "-"
        if owner != "game":
            log.append(f"KEEP {name} {where} {owner or 'no-address'}")
            continue
        u, d = decls[name][0]
        tls = d.group(3)
        unnamed = "unnamed_addr "     # llvm-link keeps the weakest of every declaration's
        vis = "protected "
        ty = types.subst(u, d.group(8))
        q = name if re.fullmatch(r"[-a-zA-Z$._][-a-zA-Z$._0-9]*", name) else '"' + name + '"'
        out.append(f"@{q} = {vis}{tls}{unnamed}{d.group(5)}global {ty} zeroinitializer{d.group(9) or ''}")
        log.append(f"DEF {name} {where}" + (" thread_local" if tls else ""))
        if name in local:
            if ty != "i8":
                raise Refusal(f"local data row {name}: declared as {ty}, not a bool")
            out.append(f"define protected void @{STANDIN_WRITER}{name}() {{\n  store i8 1, i8* @{q}, align 1\n"
                       f"  ret void\n}}")
            log.append(f"WRITER {name}")
    for name in sorted({n for u in units for n in u.avail} - defined):
        log.append(f"AVAILABLE_EXTERNALLY {name} (kept: no file defines it)")
    for o in types.opaque:
        log.append(f"OPAQUE {o} completed as {{ i8 }}")
    head = [f"; the stand-in definitions of the game module: written by tools/game_module.py; do not edit",
            'target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"',
            'target triple = "x86_64-scei-ps4"', ""]
    return "\n".join(head + types.lines + [""] + out) + "\n", log


def run(cmd: list[str], what: str) -> None:
    r = subprocess.run(cmd, cwd=REPO_ROOT, capture_output=True, text=True)
    if r.returncode != 0:
        sys.stderr.write(r.stderr)
        raise Refusal(f"{what} failed ({' '.join(cmd[:2])} ...)")


def opt_path() -> Path:
    """The opt of the game line: built from the compiler's own patched
    source beside llvm-link; TLG_OPT names another copy of it (a build
    tree's own, before an install)."""
    p = os.environ.get("TLG_OPT")
    return Path(p) if p else REPO_ROOT / LLVM_OPT


def used_odr(bc: Path) -> list[str]:
    """The linkonce_odr and weak_odr definitions of the linked module `bc`
    that another definition's body or initialiser names (step 3a). An alias
    of a definition does not use it."""
    ll = Path(str(bc) + ".ll")
    run([str(REPO_ROOT / LLVM_LINK), "-S", "-o", str(ll), str(bc)], "llvm-link -S")
    odr: set[str] = set()
    used: set[str] = set()
    cur = None
    with open(ll, errors="replace") as f:
        for line in f:
            if line.startswith("define "):
                m = DEFINE_LINE.match(line)
                if not m:
                    continue
                cur = unquote(m.group(2))
                words = m.group(1).split()
                if words and words[0] in ODR:
                    odr.add(cur)
                used.update(x for x in map(unquote, REF.findall(line[m.end():])) if x != cur)
            elif line.startswith("@"):
                m = GLOBAL_LINE.match(line)
                if not m:
                    continue
                name, rest = unquote(m.group(1)), m.group(2)
                if rest.split(" ", 1)[0] in ODR:
                    odr.add(name)
                # an alias is another name of its definition, not a user of it
                if not ALIAS.match(rest):
                    used.update(x for x in map(unquote, REF.findall(rest)) if x != name)
            elif line.startswith("}"):
                cur = None
            elif cur is not None and "@" in line:
                used.update(x for x in map(unquote, REF.findall(line)) if x != cur)
    ll.unlink()
    return sorted(odr & used)


def externals(bc: Path) -> set[str]:
    """The names a bitcode module defines with non-local linkage."""
    env = {**os.environ, "LD_LIBRARY_PATH": str(REPO_ROOT / "tools" / "cc" / "shim")}
    r = subprocess.run([str(REPO_ROOT / LLVM_NM), "--defined-only", str(bc)], cwd=REPO_ROOT, capture_output=True,
                       text=True, env=env)
    if r.returncode != 0:
        sys.stderr.write(r.stderr)
        raise Refusal("llvm-nm failed on the linked module")
    names = set()
    for line in r.stdout.splitlines():
        s = line.split()
        if len(s) >= 2 and s[-2].isupper():
            names.add(s[-1])
    return names


def make_local(bc: Path, names: list[str]) -> None:
    """Give `names` internal linkage in the linked module `bc`, in place,
    and nothing else: every other non-local definition is on the preserved
    list, and the symbol table before and after must differ by `names`
    alone."""
    before = externals(bc)
    missing = [n for n in names if n not in before]
    if missing:
        raise Refusal(f"local data: the linked module does not define {' '.join(missing[:8])} with external linkage")
    api = Path(str(bc) + ".preserved")
    api.write_text("".join(f"{n}\n" for n in sorted(before - set(names))))
    tmp = Path(str(bc) + ".local")
    env = {**os.environ, "LD_LIBRARY_PATH": str(REPO_ROOT / "tools" / "cc" / "shim")}
    r = subprocess.run([str(opt_path()), "-internalize", f"-internalize-public-api-file={api}",
                        "-preserve-bc-uselistorder", "-o", str(tmp), str(bc)], cwd=REPO_ROOT, capture_output=True,
                       text=True, env=env)
    if r.returncode != 0:
        sys.stderr.write(r.stderr)
        raise Refusal("opt -internalize failed on the linked module")
    after = externals(tmp)
    if before - after != set(names) or after - before:
        raise Refusal("the internalising step did not change exactly the names asked: "
                      + " ".join(sorted((before - after) ^ set(names) | (after - before))[:8]))
    tmp.replace(bc)


def build(bcs: list[Path], out: Path, ver: str, single: bool = False, base=None) -> list[str]:
    """Link the files and their stand-ins and compile the module to `out`.
    Returns the stand-in log."""
    units = [Unit(p.with_suffix(".ll"), tu_of(p, ver)) for p in bcs]
    lines, renamed = check_units(units)
    from base_elf import BaseElf
    from module_boundary import local_proof, local_rows
    base = base or BaseElf(REPO_ROOT, ver)
    rows = local_rows(ver)
    named = {n for u in units for n in list(u.defs) + list(u.decls)}
    local = [n for n in rows if n in named]
    if local:
        proofs, errors = local_proof(base, local)
        if errors:
            raise Refusal("\n".join(errors))
    text, log = standins(units, ver, base, local=set(local))
    work = out.parent / (out.name[:-2] if out.name.endswith(".o") else out.name)
    out.parent.mkdir(parents=True, exist_ok=True)
    sl = Path(str(work) + ".standins.ll")
    sl.write_text(text)
    bc = Path(str(work) + ".bc")
    rsp = Path(str(work) + ".inputs")
    if not opt_path().exists():
        raise Refusal(f"no opt at {opt_path()}: tools/build_llvm.sh {_line_version()} builds it beside llvm-link "
                      "(TLG_OPT names another copy)")
    stage1 = [unit_path(u.tu, ver) for u in units]
    for p, s1 in zip(bcs, stage1):
        if not s1.exists() or s1.stat().st_mtime < p.stat().st_mtime:
            raise Refusal(f"{s1.relative_to(REPO_ROOT)} (stage 1) is missing or older than the unit's bitcode: "
                          "tools/compile_cpp.sh --ir writes both")
    rsp.write_text("".join(f"{p}\n" for p in bcs) + f"{sl}\n")
    s1rsp = Path(str(work) + ".units")
    s1rsp.write_text("".join(f"{p}\n" for p in stage1) + f"{sl}\n")
    run([str(REPO_ROOT / LLVM_LINK), "-o", str(bc), f"@{s1rsp}"], "llvm-link")
    defined = {n for u in units for n, (linkage, _t) in u.defs.items() if linkage not in LOCAL}
    defined |= {x.split()[1] for x in log if x.startswith("DEF ")}
    local = [n for n in local if n in defined]
    odr = used_odr(bc)
    if local or odr:
        make_local(bc, local + odr)
        log += [f"LOCAL {proofs[n]}" for n in local]
        Path(str(work) + ".odr").write_text("".join(f"{n}\n" for n in odr))
    lto = Path(str(work) + ".lto.bc")
    env = {**os.environ, "LD_LIBRARY_PATH": str(REPO_ROOT / "tools" / "cc" / "shim")}
    # the two vectorisers on, as the link's own driver sets them (libLTO,
    # LTOCodeGenerator::optimize: PMB.LoopVectorize and PMB.SLPVectorize);
    # opt's -std-link-opts leaves them at their options' defaults, off
    r = subprocess.run([str(opt_path()), "-std-link-opts", "-vectorize-loops", "-vectorize-slp",
                        "-preserve-bc-uselistorder", "-o", str(lto), str(bc)],
                       cwd=REPO_ROOT, capture_output=True, text=True, env=env)
    if r.returncode != 0:
        sys.stderr.write(r.stderr)
        raise Refusal("opt -std-link-opts failed on the linked module")
    run([str(REPO_ROOT / "tools" / "compile_cpp.sh"), "--codegen", MODULE_PREFIX, str(lto), str(out)],
        "code generation")
    Path(str(work) + ".standins.log").write_text("\n".join(log) + "\n")
    if not single:
        (out.parent / "symbols.txt").write_text(
            "# <tu> <symbol> <linkage>: every definition of every game file (tools/game_module.py)\n"
            + "".join(f"{x}\n" for x in lines)
            + "".join(f"renamed {n}\n" for n in renamed))
    return log


_SYMBOLS: dict[tuple, tuple[dict[str, set[str]], set[str]]] = {}


def load_symbols(ver: str) -> tuple[dict[str, set[str]], set[str]]:
    """({tu: {symbol}}, {renamed internal name}) from build/<slug>/game/symbols.txt.
    The gate asks once per unit, so the parse is kept for the file as it
    stands (path, mtime, size); callers read the result and never change it."""
    p = module_dir(ver) / "symbols.txt"
    st = p.stat() if p.exists() else None
    key = (str(p), st.st_mtime_ns if st else None, st.st_size if st else None)
    if key in _SYMBOLS:
        return _SYMBOLS[key]
    by_tu: dict[str, set[str]] = {}
    renamed: set[str] = set()
    if st:
        for line in p.read_text().splitlines():
            if line.startswith("#"):
                continue
            s = line.split()
            if len(s) == 2 and s[0] == "renamed":
                renamed.add(s[1])
            elif len(s) >= 2:
                by_tu.setdefault(s[0], set()).add(s[1])
    _SYMBOLS.clear()
    _SYMBOLS[key] = (by_tu, renamed)
    return by_tu, renamed


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--out", required=True)
    ap.add_argument("--single", action="store_true", help="a module of one file (no symbols.txt)")
    ap.add_argument("inputs", nargs="+", help="the units' bitcode files, or @<list>")
    a = ap.parse_args(argv)
    ver = os.environ.get("VERSION") or detect_version(REPO_ROOT)
    lls: list[Path] = []
    for i in a.inputs:
        if i.startswith("@"):
            lls += [Path(x) for x in Path(i[1:]).read_text().split()]
        else:
            lls.append(Path(i))
    lls = [p if p.is_absolute() else REPO_ROOT / p for p in lls]
    try:
        log = build(lls, REPO_ROOT / a.out, ver, single=a.single)
    except Refusal as e:
        print(f"game_module: {e}", file=sys.stderr)
        return 1
    n = sum(1 for x in log if x.startswith("DEF "))
    print(f"game_module: {len(lls)} unit(s), {n} stand-in(s) -> {a.out}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
