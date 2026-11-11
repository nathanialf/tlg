#!/usr/bin/env python3
"""
game_module.py: build the game region as one module (docs/DECISIONS.md D50).

The game and engine (src/game/, 0x1a3e00 up) were compiled as one module:
a function's code shows what other game files define (an empty member
destructor in another file inlined, a callee that returns 1 in another file
propagated) and reaches the game's own objects PC-relative while the
libraries' stay behind the GOT. The gate builds it the same way:

    1. Every game translation unit to unoptimised bitcode by the front end
       at -O2 (tools/compile_cpp.sh --ir: `-Xclang -disable-llvm-optzns`),
       under the game line of config/flags.<slug>.txt
       (`-fvisibility=protected -ffunction-sections` among its flags), with
       the same module as text beside it, which this tool reads for what each
       unit defines and declares and for the declared types.
    2. The stand-ins: an object some file declares and no file defines gets a
       generated definition when config/modules.<slug>.txt
       (tools/module_boundary.py) puts its base address in the game's part of
       the data: protected, writable, zero-initialised, of the declared type
       and alignment, in a module of its own (build/<slug>/game/standins.ll)
       linked in last. A thread-local stand-in has default visibility: under
       protected visibility the 4.0.0 compiler accesses it local-dynamic,
       which the base's code is not (D23). A library object, an import, a
       library vtable and a name without a base address stay declarations
       (the GOT and PLT forms). An opaque class (a declaration whose type no
       file completes) is completed as one byte.
    3. llvm-link (built from the game compiler's own source, tools/cc/
       llvm-4.0.0-src-tools/bin) links every file and the stand-ins into one
       module, in the sources' order.
    4. One -O2 pipeline and code generation over the module, to one object
       (tools/compile_cpp.sh --codegen), build/<slug>/game/module.o.

It refuses, naming the files: a name two files define with external
linkage (llvm-link would say only the name), and a thread-local a game file
defines (it would be accessed local-dynamic). It writes
build/<slug>/game/symbols.txt, `<tu> <symbol> <linkage>` for every
definition of every file, which the gate reads to check a row's unit
defines its symbol (tools/match_check.py tu_functions), and the list of
internal names two files define (`renamed`): the link gives the second a
`.N` suffix, so a row or data claim naming one is refused.

    game_module.py --out build/base/game/module.o <a.bc>... | @<list>   the module (ninja's edge)
    game_module.py --out <obj> --single <a.bc>                 a module of one file and its stand-ins
                                                               (the inner loop, tools/quick_diff.sh)

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
LLVM_LINK = "tools/cc/llvm-4.0.0-src-tools/bin/llvm-link"
LINKAGES = {"private", "internal", "available_externally", "linkonce", "weak", "common", "appending",
            "extern_weak", "linkonce_odr", "weak_odr", "external"}
LOCAL = {"private", "internal"}
SHARED = {"linkonce", "weak", "common", "linkonce_odr", "weak_odr", "appending"}
NAME = r'(?:"(?:[^"\\]|\\.)*"|[-a-zA-Z$._0-9]+)'
TYPE_LINE = re.compile(r'^(%' + NAME + r') = type (.*)$')
GLOBAL_LINE = re.compile(r'^@(' + NAME + r') = (.*)$')
DEFINE_LINE = re.compile(r'^define ([^@]*)@(' + NAME + r')\(')
TYPE_REF = re.compile(r'%' + NAME)
DECL = re.compile(r'^external ((?:hidden |protected |default )?)((?:dllimport )?)((?:thread_local(?:\([a-z]+\))? )?)'
                  r'((?:local_unnamed_addr |unnamed_addr )?)((?:addrspace\(\d+\) )?)((?:externally_initialized )?)'
                  r'(global|constant) (.*?)(, align \d+)?$')


def module_dir(ver: str) -> Path:
    return build_dir(REPO_ROOT, ver) / "game"


def ir_path(tu: str, ver: str) -> Path:
    """The unoptimised bitcode of a game unit (tools/compile_cpp.sh --ir);
    the same module as text is beside it, with .ll for .bc."""
    return module_dir(ver) / "ir" / (tu + ".bc")


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
            if tls:
                errors.append(f"{u.tu} defines the thread-local {name}: the module would access it local-dynamic "
                              "(protected visibility), which no access in the base is; a game thread-local waits "
                              "for the supervisor's ruling on the TLS model (round 133A)")
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


def standins(units: list[Unit], ver: str, base=None, table=None) -> tuple[str, list[str]]:
    """(the stand-in module's text, a log line per declaration considered)."""
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
        addr = base.address_of(name)
        owner = owner_of(table, addr)
        where = f"0x{addr:x}" if addr is not None else "-"
        if owner != "game":
            log.append(f"KEEP {name} {where} {owner or 'no-address'}")
            continue
        u, d = decls[name][0]
        tls = d.group(3)
        unnamed = "unnamed_addr "     # llvm-link keeps the weakest of every declaration's
        vis = "" if tls else "protected "
        ty = types.subst(u, d.group(8))
        q = name if re.fullmatch(r"[-a-zA-Z$._][-a-zA-Z$._0-9]*", name) else '"' + name + '"'
        out.append(f"@{q} = {vis}{tls}{unnamed}{d.group(5)}global {ty} zeroinitializer{d.group(9) or ''}")
        log.append(f"DEF {name} {where}" + (" thread_local default visibility" if tls else ""))
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


def build(bcs: list[Path], out: Path, ver: str, single: bool = False, base=None) -> list[str]:
    """Link the files and their stand-ins and compile the module to `out`.
    Returns the stand-in log."""
    units = [Unit(p.with_suffix(".ll"), tu_of(p, ver)) for p in bcs]
    lines, renamed = check_units(units)
    text, log = standins(units, ver, base)
    work = out.parent / (out.name[:-2] if out.name.endswith(".o") else out.name)
    out.parent.mkdir(parents=True, exist_ok=True)
    sl = Path(str(work) + ".standins.ll")
    sl.write_text(text)
    bc = Path(str(work) + ".bc")
    rsp = Path(str(work) + ".inputs")
    rsp.write_text("".join(f"{p}\n" for p in bcs) + f"{sl}\n")
    run([str(REPO_ROOT / LLVM_LINK), "-o", str(bc), f"@{rsp}"], "llvm-link")
    run([str(REPO_ROOT / "tools" / "compile_cpp.sh"), "--codegen", MODULE_PREFIX, str(bc), str(out)],
        "code generation")
    Path(str(work) + ".standins.log").write_text("\n".join(log) + "\n")
    if not single:
        (out.parent / "symbols.txt").write_text(
            "# <tu> <symbol> <linkage>: every definition of every game file (tools/game_module.py)\n"
            + "".join(f"{x}\n" for x in lines)
            + "".join(f"renamed {n}\n" for n in renamed))
    return log


def load_symbols(ver: str) -> tuple[dict[str, set[str]], set[str]]:
    """({tu: {symbol}}, {renamed internal name}) from build/<slug>/game/symbols.txt."""
    by_tu: dict[str, set[str]] = {}
    renamed: set[str] = set()
    p = module_dir(ver) / "symbols.txt"
    if p.exists():
        for line in p.read_text().splitlines():
            if line.startswith("#"):
                continue
            s = line.split()
            if len(s) == 2 and s[0] == "renamed":
                renamed.add(s[1])
            elif len(s) >= 2:
                by_tu.setdefault(s[0], set()).add(s[1])
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
