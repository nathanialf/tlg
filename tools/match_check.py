#!/usr/bin/env python3
"""
match_check.py: how far a compiled function is from the base executable's.

The compiled object (a TU built by tools/compile_cpp.sh) holds the function
as a symbol with its .text bytes and relocations. The base executable holds
the linked bytes at the function's address (config/functions.<slug>.txt).
Both are disassembled (capstone) and compared instruction by instruction;
where the object's instruction carries a relocation, the field the linker
fills (a RIP-relative displacement, a call target, a GOT or PLT slot) is
masked on both sides, and nothing else is; a GOT load of a symbol the
executable defines is first relaxed to the `lea` the linker made of it
(docs/DECISIONS.md D10). The score is the share of
instructions equal after masking, over the longer of the two streams: 1.0 is
a match. The masked fields are then checked for real where the base can
place the symbol: a call to FUN_x must encode, in the base, the address of
FUN_x; a reference to D_<hex> that address; a call to an import its PLT
stub. A wrong target fails the function whatever the score (tools/base_elf.py).

    match_check.py --tu src/x/y.cpp --func <name> [--symbol <mangled>] [--diff]
    match_check.py --tu src/x/y.cpp --all          every function the TU defines
                                                  that config/functions lists
    match_check.py --obj build/base/obj/x/y.o ...  an object already built

A game unit (src/game/) is compiled as the gate compiles it, one module
(tools/game_module.py, D50): by default the module of that one file and its
stand-ins (fast, the inner loop); --module the whole game module, the
gate's object; --both each, saying whether the function's bytes differ
between them (a difference is a cross-file effect, real information).

<name> is the function's row in config/functions.<slug>.txt (FUN_<addr>, or
its real name); --symbol is the object's symbol when it differs (a mangled
C++ name behind a FUN_ row). With --diff the first difference is printed
with five instructions of context on each side.

Exit 0 when every checked function scores 1.0, 1 otherwise, 2 on a usage
error. --json prints the results as one JSON object per line.
"""
from __future__ import annotations

import argparse
import json
import re
import os
import subprocess
import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(Path(__file__).resolve().parent))
from tlg_version import baseelf_path, build_dir, config_path, detect_version  # noqa: E402
from survey_elf import read_phdrs, vaddr_to_off  # noqa: E402
from base_elf import BaseElf  # noqa: E402

# R_X86_64_* relocation types -> field width in bytes.
RELOC_WIDTH = {1: 8, 2: 4, 3: 4, 4: 4, 5: 8, 6: 8, 7: 8, 8: 8, 9: 4, 10: 4, 11: 4,
               12: 2, 13: 2, 14: 1, 15: 1, 16: 8, 17: 8, 18: 8, 19: 4, 20: 4, 21: 4,
               22: 4, 23: 4, 24: 8, 25: 8, 26: 4, 27: 4, 28: 8, 29: 4, 30: 4, 31: 4,
               32: 8, 33: 4, 34: 4, 35: 4, 36: 4, 41: 4, 42: 4}


def load_functions(ver: str) -> dict[str, tuple[int, int]]:
    out = {}
    p = config_path(REPO_ROOT, ver, "functions", "txt")
    for line in p.read_text().splitlines():
        s = line.split("#", 1)[0].split()
        if len(s) >= 3:
            out[s[2]] = (int(s[0], 16), int(s[1], 16))
    return out


def generate_tables_of(tu: str, ver: str) -> None:
    """Write build/<slug>/gen/D_<hex>.inc for every table the TU claims
    (config/data_schema.<slug>.txt, tools/gen_data_inc.py, D18), so a compile
    outside ninja sees the current rows."""
    try:
        from gen_data_inc import schema_rows
        rows = schema_rows(ver)
    except Exception:  # noqa: BLE001  (no schema file, or an error ninja will report)
        return
    for ident, row in rows.items():
        if row.get("tu") == tu:
            subprocess.run([sys.executable, "-I", str(REPO_ROOT / "tools" / "gen_data_inc.py"), ident],
                           cwd=REPO_ROOT, check=True, env={**os.environ, "VERSION": ver})


def _compilers_newest(link: bool = False) -> float:
    """The newest installed compiler built from source (tools/build_llvm.sh
    replaces tools/cc/llvm-*-src): a reinstalled one makes every older object
    stale, whichever line built it (round 116A). With `link`, llvm-link beside
    the game's too (tools/cc/llvm-*-src-tools), which the game's bitcode and
    module pass through."""
    cc = REPO_ROOT / "tools" / "cc"
    paths = list(cc.glob("llvm-*-src/bin/clang")) + (list(cc.glob("llvm-*-src-tools/bin/llvm-link")) if link else [])
    return max([p.stat().st_mtime for p in paths if p.exists()] + [0.0])


def _fresh(out: Path, src: Path, link: bool = False) -> bool:
    """Whether `out` is newer than `src`, the compilers and every header its
    depfile (<out>.d, written by tools/compile_cpp.sh) lists."""
    if not out.exists() or out.stat().st_mtime < max(src.stat().st_mtime, _compilers_newest(link)):
        return False
    dep = out.with_name(out.name + ".d")
    # ninja (deps = gcc) consumes the depfile it was given, so an object
    # ninja built has no .d beside it and its headers cannot be checked:
    # it is recompiled (round 31's note: a header change was not seen).
    if not dep.exists():
        return False
    text = dep.read_text().replace("\\\n", " ")
    deps = [Path(d) for d in text.split(":", 1)[1].split()] if ":" in text else []
    mt = out.stat().st_mtime
    return not any(not (d if d.is_absolute() else REPO_ROOT / d).exists()
                   or (d if d.is_absolute() else REPO_ROOT / d).stat().st_mtime > mt for d in deps)


def is_module_tu(tu: str) -> bool:
    """A unit of the game module (tools/game_module.py, D50)."""
    from game_module import MODULE_PREFIX
    return tu.startswith(MODULE_PREFIX)


def object_path(tu: str, ver: str) -> Path:
    """Where the unit's code is compiled to: its own object, or for a game
    unit the one module object."""
    if is_module_tu(tu):
        import game_module as gm
        return gm.module_object(ver)
    return build_dir(REPO_ROOT, ver) / "obj" / (tu + ".o")


def compile_tu(tu: str, ver: str) -> Path:
    """The TU's object, recompiled when the TU or any header its depfile
    lists (tools/compile_cpp.sh writes <obj>.d) is newer than it. A game
    unit's object is the game module's (module_object)."""
    if is_module_tu(tu):
        return module_object(tu, ver)
    obj = object_path(tu, ver)
    src = REPO_ROOT / tu
    generate_tables_of(tu, ver)
    if _fresh(obj, src):
        return obj
    subprocess.run([str(REPO_ROOT / "tools" / "compile_cpp.sh"), tu, str(obj.relative_to(REPO_ROOT))],
                   cwd=REPO_ROOT, check=True)
    return obj


_MODULE_CHECKED: dict[str, bool] = {}     # version -> whether the module built


def module_stale(ver: str) -> str | None:
    """Why build/<slug>/game/module.o is stale, or None: it must be newer than
    the compilers, the tools and configuration its edge names, and every game
    unit's bitcode, each newer than its source and headers, and it must have
    been linked from exactly today's game sources."""
    import game_module as gm
    obj = gm.module_object(ver)
    if not obj.exists():
        return "not built"
    mt = obj.stat().st_mtime
    inputs = obj.with_name(obj.name[:-2] + ".inputs")
    have = inputs.read_text().split()[:-1] if inputs.exists() else []
    from gen_ninja import sources
    want = [str(gm.ir_path(s, ver)) for s in sources() if s.startswith(gm.MODULE_PREFIX)]
    if [str(Path(h).resolve()) for h in have] != [str(Path(w).resolve()) for w in want]:
        return "the game sources changed"
    for p in ([REPO_ROOT / "tools" / n for n in ("game_module.py", "module_boundary.py", "base_elf.py", "compile_cpp.sh")]
              + [config_path(REPO_ROOT, ver, st, "txt") for st in ("flags", "modules", "functions", "vtables",
                                                                 "vtables.derived", "imports", "local_data")]):
        if p.exists() and p.stat().st_mtime > mt:
            return f"{p.relative_to(REPO_ROOT)} is newer"
    if _compilers_newest(link=True) > mt:
        return "a compiler is newer"
    for s in sources():
        if s.startswith(gm.MODULE_PREFIX):
            bc = gm.ir_path(s, ver)
            if not _fresh(bc, REPO_ROOT / s, link=True) or bc.stat().st_mtime > mt:
                return f"{s} changed"
    return None


def module_object(tu: str, ver: str) -> Path:
    """The game module's object, rebuilt by ninja when stale (checked once per
    process: a gate run under ninja finds it built)."""
    import game_module as gm
    obj = gm.module_object(ver)
    if ver not in _MODULE_CHECKED:
        why = module_stale(ver)
        ok = True
        if why:
            print(f"match_check: the game module is stale ({why}): ninja {obj.relative_to(REPO_ROOT)}",
                  file=sys.stderr)
            env = {**os.environ, "VERSION": ver}
            if "local_data" in why:
                # the row file is not yet an input of ninja's module edge (tools/gen_ninja.py):
                # without the object ninja builds it again
                obj.unlink()
            if why == "the game sources changed":
                subprocess.run([sys.executable, "-I", str(REPO_ROOT / "tools" / "gen_ninja.py")],
                               cwd=REPO_ROOT, check=True, env=env)
            ninja = REPO_ROOT / ".venv" / "bin" / "ninja"
            ok = subprocess.run([str(ninja) if ninja.exists() else "ninja", str(obj.relative_to(REPO_ROOT))],
                                cwd=REPO_ROOT, env=env).returncode == 0
        _MODULE_CHECKED[ver] = ok
    if not _MODULE_CHECKED[ver]:
        # one failed build answers for every game unit of this run
        raise subprocess.CalledProcessError(1, ["game_module", tu])
    return obj


def single_module(tu: str, ver: str, base=None) -> Path:
    """The inner loop's object for a game unit: the same pipeline over a
    module of that one file and its stand-ins (tools/game_module.py --single):
    the unit's bitcode, recompiled when stale, its stand-ins, the -O2 pipeline
    and code generation."""
    import game_module as gm
    bc = gm.ir_path(tu, ver)
    generate_tables_of(tu, ver)
    if not _fresh(bc, REPO_ROOT / tu, link=True):
        bc.parent.mkdir(parents=True, exist_ok=True)
        subprocess.run([str(REPO_ROOT / "tools" / "compile_cpp.sh"), "--ir", tu, str(bc.relative_to(REPO_ROOT))],
                       cwd=REPO_ROOT, check=True)
    out = gm.single_object(tu, ver)
    try:
        gm.build([bc], out, ver, single=True, base=base)
    except gm.Refusal as e:
        print(f"match_check: {e}", file=sys.stderr)
        raise subprocess.CalledProcessError(1, ["game_module", tu])
    return out


def tu_functions(tu: str, obj: Path, ver: str) -> dict[str, tuple[bytes, list]]:
    """object_functions(obj), narrowed for the game module to the functions
    the unit itself defines (build/<slug>/game/symbols.txt), so a row is
    checked against its own unit; an internal name two game files define is
    left out (the link renamed the second), and renamed_note says why. A
    name the compiler gives (game_module.COMPILER_LOCAL) is never taken by
    its spelling in the module: it is keyed by the unit's own name and maps to
    the module's symbol compiler_local_aliases proves."""
    funcs = object_functions(obj)
    if not is_module_tu(tu):
        return funcs
    funcs = with_header_statics(tu, obj, ver, funcs)
    if obj != object_path(tu, ver):
        return funcs
    import game_module as gm
    by_tu, renamed = gm.load_symbols(ver)
    mine = {s for s in by_tu.get(tu, set()) - renamed if not gm.compiler_local(s)}
    out = {k: v for k, v in funcs.items() if k in mine}
    aliases, _why = compiler_local_aliases(tu, obj, ver)
    for unit_name, module_name in aliases.items():
        out[unit_name] = funcs[module_name]
    return out


_ALIASES: dict[tuple, tuple[dict[str, str], dict[str, str]]] = {}


def compiler_local_aliases(tu: str, obj: Path, ver: str) -> tuple[dict[str, str], dict[str, str]]:
    """({unit's name: module object's symbol}, {unit's name: why none}) for
    the functions of a game unit whose names the compiler gave
    (game_module.COMPILER_LOCAL: `__cxx_global_array_dtor`, `.1`, ...;
    `__cxx_global_var_init`, `.1`, ...; `_GLOBAL__sub_I_<file>`).

    The link renames such a function when an earlier unit holds its name, by
    one counter over the whole link, so the module's spelling says nothing
    about whose it is. The row names it as the unit does (its IR and its
    single-file object), which depends on that unit alone, and the module
    symbol is proven by two facts the unit's IR and the module object both
    state:

      1. what it reaches: the unit's own uniquely named internal objects and
         functions its IR body references, directly or through the
         compiler-named functions it calls (an array-destroy helper reaches
         its array, `_ZZ<owner>E9D_<hex>` or `_ZL9D_<hex>`; a file's
         `_GLOBAL__sub_I_` reaches every object its `__cxx_global_var_init`s
         initialise), against the same names among the candidate's
         relocations (D17 attributes a section-relative field to the named
         local it lands in); the sets must be equal and not empty;
      2. who reaches it: every function of the unit with a stable name whose
         IR body references it (the owner's `__cxa_atexit` registration), and
         every compiler-named one already proven (by its module symbol),
         must reference the candidate in the module object; a compiler-named
         referrer the module does not keep (a `__cxx_global_var_init` the
         pipeline inlined into its `_GLOBAL__sub_I_`) is passed through to
         its own referrers; a `_GLOBAL__sub_I_` is reached from
         `@llvm.global_ctors`, and the candidate must be a target of the
         module object's constructor table (`.ctors` on this target).

    A candidate is a local function of the module of the same compiler name
    with any `.N` suffixes. Exactly one candidate must satisfy both, and no
    other compiler-named function of the unit of the same kind may reach the
    same set, or there is no alias and `why` says which fact failed. A wrong
    alias would still fail later: the row's bytes and relocation targets are
    compared with the base's at its address, and the layout resolves the
    owner's reference to the module symbol through the row
    (tools/layout_link.py)."""
    import game_module as gm
    st = obj.stat()
    key = (tu, str(obj), st.st_mtime_ns, st.st_size)
    if key in _ALIASES:
        return _ALIASES[key]
    by_tu, renamed = gm.load_symbols(ver)
    # the file's initializer first, then the objects' initializers, then the
    # helpers they register: each is anchored by the one before it
    order = {"_GLOBAL__sub_I_": 0, "__cxx_global_var_init": 1}
    names = sorted((s for s in by_tu.get(tu, set()) if gm.compiler_local(s)),
                   key=lambda s: (order.get(s[:15], order.get(gm.compiler_kind(s), 2)), s))
    aliases: dict[str, str] = {}
    why: dict[str, str] = {}
    if names:
        ll = gm.ir_path(tu, ver).with_suffix(".ll")
        unit = gm.Unit(ll, tu)
        refs = gm.function_refs(ll)
        # names that are the unit's alone and that no link renames: internal,
        # defined by no other game file, not compiler-given, no `.N` of the
        # link's form
        own = {n for n, (lk, _tls) in unit.defs.items()
               if lk in gm.LOCAL and n not in renamed and not gm.compiler_local(n) and "." not in n}
        stable = {n for n in refs if not gm.compiler_local(n) and n not in renamed and "." not in n}
        funcs = object_functions(obj)
        cands = {c: {r.symbol for r in rl} for c, (_b, rl) in funcs.items() if gm.compiler_local(c)}
        ctors = init_array_targets(obj)

        def closure(n: str, seen: frozenset = frozenset()) -> set[str]:
            out = set(refs.get(n, set()))
            for g in refs.get(n, set()):
                if gm.compiler_local(g) and g in refs and g not in seen and g != n:
                    out |= closure(g, seen | {n})
            return out

        reach = {n: closure(n) & own for n in names}
        inlined: set[str] = set()

        def anchors_of(n: str, seen: frozenset = frozenset()) -> tuple[list[str], str]:
            out: list[str] = []
            for f in sorted(f for f in refs if n in refs[f] and f != n):
                if f in stable:
                    if f in funcs:
                        out.append(f)
                elif f in aliases:
                    out.append(aliases[f])
                elif f in inlined and f not in seen:
                    sub, bad = anchors_of(f, seen | {n})
                    if bad:
                        return [], bad
                    out += sub
                elif gm.compiler_local(f):
                    return [], f"its referrer {f} is not proven ({why.get(f, 'not examined')})"
            return out, ""

        for n in names:
            kind = gm.compiler_kind(n)
            if not reach[n]:
                if (n.startswith("_GLOBAL__sub_I_") and n not in renamed and n in funcs and n in ctors
                        and sum(1 for t in by_tu.values() if n in t) == 1):
                    # a file's initializer whose objects are all the unit's
                    # own but none uniquely named (header statics, renamed by
                    # the link; external objects): its name, from the file's
                    # name, is defined by this unit alone, so the link keeps it,
                    # and the constructor table points at it
                    aliases[n] = n
                    continue
                why[n] = "its IR body reaches none of the unit's own named objects"
                continue
            twins = [m for m in names if m != n and gm.compiler_kind(m) == kind and reach[m] == reach[n]]
            if twins:
                why[n] = f"{twins[0]} reaches the same objects ({', '.join(sorted(reach[n]))})"
                continue
            mine = {c: rs for c, rs in cands.items() if gm.compiler_kind(c) == kind and rs & own == reach[n]}
            if n.startswith("_GLOBAL__sub_I_"):
                hits = [c for c in mine if c in ctors]
                anchors = [".ctors"]
            else:
                anchors, bad = anchors_of(n)
                if bad:
                    why[n] = bad
                    continue
                if not anchors:
                    if not mine and kind == "__cxx_global_var_init":
                        inlined.add(n)
                        why[n] = "the module keeps no function of it (inlined into its referrer)"
                        continue
                    why[n] = "no function of the unit that references it in its IR is in the module object"
                    continue
                hits = [c for c, rs in mine.items() if all(c in {r.symbol for r in funcs[f][1]} for f in anchors)]
                if not hits and not mine and kind == "__cxx_global_var_init":
                    inlined.add(n)
                    why[n] = "the module keeps no function of it (inlined into its referrer)"
                    continue
            if len(hits) == 1:
                aliases[n] = hits[0]
            else:
                why[n] = (f"{len(hits)} module functions reach {', '.join(sorted(reach[n]))} and are "
                          f"referenced by {', '.join(anchors)}" + (f" ({', '.join(sorted(hits))})" if hits else ""))
    _ALIASES[key] = (aliases, why)
    return aliases, why


# --- header statics: one name in a header, one copy and one address per unit --
#
# A namespace-scope `static` (or `const`) object a header defines is an
# internal object of every unit that includes it: each unit has its own copy,
# at its own address, under the one name the header gives it (the game's
# vector constants, tlg_game_vector.h: 325 copies of the same nineteen
# objects, each unit's in its own .bss). The address is a fact about the unit,
# so it is data: config/header_statics.<slug>.txt, `<tu> <symbol> 0x<addr>`
# (the symbol as the unit spells it, `_ZL11VECTOR_ZERO`). A function's
# reference to the unit's copy is resolved to the row's address under the name
# `D_<hex>` (tu_functions), and is then checked like any D_<hex>: the field
# must encode that address in the base, in match_check and in the layout, so a
# wrong row fails the first claimed function that touches the object (the
# file's initializer stores every one). A reference to a header static of a
# unit with no row fails, naming the row it needs.
#
# In the whole module the link renames all copies but the first (`.N`), so
# which module symbol is the unit's copy is proven, never read from the
# numbering (as D56 does for compiler-named functions): the functions of the
# unit whose IR references the object (directly or through the compiler-named
# functions they call), each by its module symbol (a stable name, or the
# alias compiler_local_aliases proves), must all reference one and the same
# candidate (a local object of the module whose name is the unit's with any
# `.N`), and no other unit's proof may give that candidate.

HEADER_STATIC_SUFFIX = re.compile(r"(?:\.\d+)+$")


def load_header_statics(ver: str) -> dict[str, dict[str, int]]:
    """{tu: {symbol: address}} from config/header_statics.<slug>.txt."""
    key = ver
    if key not in _HEADER_ROWS:
        p = config_path(REPO_ROOT, ver, "header_statics", "txt")
        out: dict[str, dict[str, int]] = {}
        if p.exists():
            for n, line in enumerate(p.read_text().splitlines(), 1):
                s = line.split("#", 1)[0].split()
                if not s:
                    continue
                if len(s) != 3 or not s[2].startswith("0x"):
                    raise SystemExit(f"{p.relative_to(REPO_ROOT)}:{n}: a row is `<tu> <symbol> 0x<addr>`")
                if s[1] in out.get(s[0], {}):
                    raise SystemExit(f"{p.relative_to(REPO_ROOT)}:{n}: {s[0]} {s[1]} has two rows")
                out.setdefault(s[0], {})[s[1]] = int(s[2], 16)
        _HEADER_ROWS[key] = out
    return _HEADER_ROWS[key]


_HEADER_ROWS: dict[str, dict[str, dict[str, int]]] = {}


def header_static_names(ver: str, obj: Path | None = None) -> set[str]:
    """Every symbol a row of config/header_statics.<slug>.txt names, and, given
    the object, every internal data object of it that two or more game files
    define under one name (the link renamed all but one: a header static
    whether or not a row names it yet; a name of the D_<hex> or FUN_<hex> form
    is a file's own and is left out)."""
    names = {s for rows in load_header_statics(ver).values() for s in rows}
    if obj is not None:
        import game_module as gm
        _by_tu, renamed = gm.load_symbols(ver)
        objs = {HEADER_STATIC_SUFFIX.sub("", c) for c in local_objects(obj)}
        names |= {n for n in renamed if n in objs and not gm.compiler_local(n)
                  and not BaseElf.base_identifier(n).startswith(("D_", "FUN_"))}
    return names


def local_objects(obj: Path) -> set[str]:
    """The names of the local data objects (STB_LOCAL STT_OBJECT) an object
    defines."""
    st = obj.stat()
    key = (str(obj), st.st_mtime_ns, st.st_size)
    if key not in _LOCAL_OBJECTS:
        from elftools.elf.elffile import ELFFile
        with obj.open("rb") as f:
            elf = ELFFile(f)
            _LOCAL_OBJECTS[key] = {
                s.name for s in elf.get_section_by_name(".symtab").iter_symbols()
                if s["st_info"]["bind"] == "STB_LOCAL" and s["st_info"]["type"] == "STT_OBJECT" and s.name}
    return _LOCAL_OBJECTS[key]


_LOCAL_OBJECTS: dict[tuple, set[str]] = {}


def header_static_aliases(tu: str, obj: Path, ver: str) -> tuple[dict[str, str], dict[str, str]]:
    """({object symbol: unit symbol}, {unit symbol: why none}) for the header
    statics (the symbols config/header_statics names) the game unit `tu`
    defines, in `obj`: the unit's single-file module, where the unit's names
    are its own, or the whole module, where each is proven as the comment
    above says and no other unit with rows is given the same candidate."""
    st = obj.stat()
    key = (tu, str(obj), st.st_mtime_ns, st.st_size)
    if key in _HEADER_ALIASES:
        return _HEADER_ALIASES[key]
    aliases, why = _header_static_proofs(tu, obj, ver)
    aliases, why = dict(aliases), dict(why)
    if aliases and obj == object_path(tu, ver):
        for other in sorted(load_header_statics(ver)):
            if other == tu or not (REPO_ROOT / other).exists():
                continue
            theirs = _header_static_proofs(other, obj, ver)[0]
            for c in [c for c in aliases if c in theirs]:
                why[aliases.pop(c)] = f"{c} is proven for {other} too"
    _HEADER_ALIASES[key] = (aliases, why)
    return aliases, why


def _header_static_proofs(tu: str, obj: Path, ver: str) -> tuple[dict[str, str], dict[str, str]]:
    import game_module as gm
    st = obj.stat()
    key = ("proof", tu, str(obj), st.st_mtime_ns, st.st_size)
    if key in _HEADER_ALIASES:
        return _HEADER_ALIASES[key]
    names = header_static_names(ver, obj)
    aliases: dict[str, str] = {}
    why: dict[str, str] = {}
    ll = gm.ir_path(tu, ver).with_suffix(".ll")
    if names and ll.exists():
        unit = gm.Unit(ll, tu)
        mine = sorted(n for n, (lk, _tls) in unit.defs.items() if lk in gm.LOCAL and n in names)
        have = local_objects(obj)
        if obj != object_path(tu, ver):
            for n in mine:
                if n in have:
                    aliases[n] = n
                else:
                    why[n] = "the unit's object keeps no copy of it"
        elif mine:
            refs = gm.function_refs(ll)
            by_tu, renamed = gm.load_symbols(ver)
            funcs = object_functions(obj)
            cl_aliases = compiler_local_aliases(tu, obj, ver)[0]

            def closure(n: str, seen: frozenset = frozenset()) -> set[str]:
                out = set(refs.get(n, set()))
                for g in refs.get(n, set()):
                    if gm.compiler_local(g) and g in refs and g not in seen and g != n:
                        out |= closure(g, seen | {n})
                return out

            # the unit's functions by their module symbols: a name the unit
            # alone defines and the link keeps (not shared, not renamed, not
            # compiler-given), or a compiler-given one's proven alias
            anchors_of: dict[str, str] = {}
            for f in refs:
                lk = unit.defs.get(f, ("", False))[0]
                if gm.compiler_local(f):
                    if f in cl_aliases:
                        anchors_of[f] = cl_aliases[f]
                elif lk and lk not in gm.SHARED and f not in renamed and f in funcs:
                    anchors_of[f] = f
            reach = {f: closure(f) for f in anchors_of}
            for n in mine:
                cands = {c for c in have if HEADER_STATIC_SUFFIX.sub("", c) == n}
                anchors = sorted(anchors_of[f] for f in anchors_of if n in reach[f])
                if not anchors:
                    why[n] = ("no function of the unit that references it has a module symbol the gate can "
                              "prove (a stable name, or a proven compiler-given alias)")
                    continue
                common = set(cands)
                for a in anchors:
                    common &= {r.symbol for r in funcs[a][1]}
                if len(common) == 1:
                    aliases[common.pop()] = n
                else:
                    why[n] = (f"{len(common)} module objects named {n}[.N] are referenced by all of "
                              f"{', '.join(anchors)}" + (f" ({', '.join(sorted(common))})" if common else ""))
    _HEADER_ALIASES[key] = (aliases, why)
    return aliases, why


_HEADER_ALIASES: dict[tuple, tuple[dict[str, str], dict[str, str]]] = {}


def with_header_statics(tu: str, obj: Path, ver: str, funcs: dict) -> dict:
    """`funcs` with every reference to a header static resolved: to `D_<hex>`,
    the address config/header_statics gives the copy's unit, when the copy is
    proven (header_static_aliases); else to a name BaseElf.address_of refuses
    with the reason (`!<why>`), so match_check and the layout fail the
    function and say which row it needs. A reference to anything else is
    untouched, so no row of a unit without header statics changes."""
    names = header_static_names(ver, obj)
    if not names:
        return funcs
    rows = load_header_statics(ver)
    # every unit's proven copies in this object (a function may reach another
    # unit's copy through a body the module shares), then this unit's
    resolved: dict[str, int | str] = {}
    module = obj == object_path(tu, ver)
    units = sorted(set(rows) | {tu}) if module else [tu]
    for u in units:
        if not (REPO_ROOT / u).exists():
            continue
        al, why = header_static_aliases(u, obj, ver)
        for c, n in al.items():
            if n in rows.get(u, {}):
                resolved[c] = rows[u][n]
            else:
                resolved[c] = (f"!{n}: a header static of {u} with no row: add `{u} {n} 0x<addr>` to "
                               f"config/header_statics.{ver}.txt, the address of the unit's copy")
        if u == tu:
            for n, w in why.items():
                resolved.setdefault(n, f"!{n}: a header static of {u} whose copy is not proven: {w}")
    hit = False
    out = {}
    for k, (code, relocs) in funcs.items():
        if not any(HEADER_STATIC_SUFFIX.sub("", r.symbol) in names for r in relocs):
            out[k] = (code, relocs)
            continue
        new = []
        for r in relocs:
            if HEADER_STATIC_SUFFIX.sub("", r.symbol) in names:
                hit = True
                t = resolved.get(r.symbol, f"!{r.symbol}: a header static no unit's proof places")
                sym = f"D_{t:x}" if isinstance(t, int) else t
                r = Reloc(r.offset, r.width, r.type, sym, r.addend, r.sym_section, r.sym_value, r.sym_size)
            new.append(r)
        out[k] = (code, new)
    return out if hit else funcs


def init_array_targets(obj: Path) -> set[str]:
    """The functions the object's constructor table points at (a file's
    `_GLOBAL__sub_I_`, from `@llvm.global_ctors`): `.ctors` for the game's
    target (x86_64-scei-ps4, whose clang does not use `.init_array`),
    `.init_array` otherwise; each attributed to its named symbol as a
    function's relocation is (D17)."""
    st = obj.stat()
    key = (str(obj), st.st_mtime_ns, st.st_size)
    if key not in _INIT_ARRAY:
        from elftools.elf.elffile import ELFFile
        from elftools.elf.relocation import RelocationSection
        out: set[str] = set()
        with obj.open("rb") as f:
            elf = ELFFile(f)
            syms = list(elf.get_section_by_name(".symtab").iter_symbols())
            locs = named_locals(syms)
            for sec in elf.iter_sections():
                if not isinstance(sec, RelocationSection):
                    continue
                if not elf.get_section(sec["sh_info"]).name.startswith((".init_array", ".ctors")):
                    continue
                for r in sec.iter_relocations():
                    rsym = syms[r["r_info_sym"]]
                    name = reloc_symbol(elf, locs, rsym, r["r_addend"] if "r_addend" in r.entry else 0, 0)[0]
                    out.add(name)
        _INIT_ARRAY[key] = out
    return _INIT_ARRAY[key]


_INIT_ARRAY: dict[tuple, set[str]] = {}


def is_compiler_local(name: str) -> bool:
    """A function name the compiler gives (game_module.COMPILER_LOCAL)."""
    from game_module import compiler_local
    return compiler_local(name)


def module_symbol(tu: str, sym: str, obj: Path, ver: str) -> str:
    """The module object's symbol for a row's `sym`: the proven alias of a
    compiler-given name, else `sym` itself."""
    if is_module_tu(tu) and obj == object_path(tu, ver):
        import game_module as gm
        if gm.compiler_local(sym):
            return compiler_local_aliases(tu, obj, ver)[0].get(sym, sym)
    return sym


def renamed_note(tu: str, sym: str, ver: str) -> str:
    """A refusal's reason when `sym` is an internal name more than one game
    file defines, or a compiler-given name with no proven module symbol,
    else ""."""
    if not is_module_tu(tu):
        return ""
    import game_module as gm
    by_tu, renamed = gm.load_symbols(ver)
    if gm.compiler_local(sym):
        obj = object_path(tu, ver)
        if not obj.exists() or sym not in by_tu.get(tu, set()):
            return f" ({sym}: the unit does not define this compiler-given name)"
        why = compiler_local_aliases(tu, obj, ver)[1].get(sym)
        return f" ({sym} is a compiler-given name with no proven module symbol: {why})" if why else ""
    if sym in renamed:
        tus = sorted(t for t, ss in by_tu.items() if sym in ss)
        return (f" ({sym} is an internal name {len(tus)} game files define ({', '.join(tus[:4])}); "
                "the module's link renamed all but one: give it a name of its own)")
    return ""


class Reloc:
    """One relocation inside a function of a compiled object."""
    __slots__ = ("offset", "width", "type", "symbol", "addend", "sym_section", "sym_value", "sym_size")

    def __init__(self, offset, width, type_, symbol, addend, sym_section, sym_value, sym_size):
        self.offset, self.width, self.type = offset, width, type_
        self.symbol, self.addend = symbol, addend
        self.sym_section, self.sym_value, self.sym_size = sym_section, sym_value, sym_size

    def __iter__(self):  # (offset, width, type), the shape compare() masks with
        yield self.offset
        yield self.width
        yield self.type


def named_locals(syms) -> dict[int, list[tuple[int, int, str]]]:
    """The object's named local data and function symbols by section index:
    a `static` object or function, or a namespace-scope const, which the
    assembler references as its section plus an offset (docs/DECISIONS.md
    D17). Assembler temporaries (`.L...`) are not in the symbol table."""
    out: dict[int, list[tuple[int, int, str]]] = {}
    for s in syms:
        info = s["st_info"]
        if info["bind"] != "STB_LOCAL" or info["type"] not in ("STT_OBJECT", "STT_FUNC") or not s.name:
            continue
        out.setdefault(s["st_shndx"], []).append((s["st_value"], s["st_size"], s.name))
    return out


def reloc_symbol(elf, locals_by_sec, sym, addend, tail=0) -> tuple[str, int, int, int]:
    """(name, addend, value, size) for a relocation's symbol. A section symbol
    is attributed to the named local whose extent holds the target offset,
    the reference the assembler rewrote as section + offset; a string literal
    or a constant-pool entry keeps the section's name, and the resolver finds
    its bytes in the base. `tail` is the distance from the field to the end
    of its instruction, which a PC-relative addend subtracts (an absolute
    field or a data slot has none)."""
    if sym["st_info"]["type"] != "STT_SECTION":
        return sym.name, addend, sym["st_value"], sym["st_size"]
    shndx = sym["st_shndx"]
    target = addend + tail
    for value, size, name in locals_by_sec.get(shndx, []):
        if value <= target < value + max(size, 1):
            return name, addend - value, value, size
    return elf.get_section(shndx).name, addend, sym["st_value"], sym["st_size"]


PCREL_TYPES = (2, 4, 9, 41, 42)      # PC32, PLT32, GOTPCREL, GOTPCRELX, REX_GOTPCRELX


def field_tails(code: bytes, offsets: list[int]) -> dict[int, int]:
    """offset of a relocated field -> bytes from the field to the end of its
    instruction, by disassembling the function once (4 where the decoder
    stops short)."""
    import capstone
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    want = sorted(offsets)
    out = {o: 4 for o in want}
    i = 0
    for ins in md.disasm(code, 0):
        end = ins.address + ins.size
        while i < len(want) and want[i] < end:
            if want[i] >= ins.address:
                out[want[i]] = end - want[i]
            i += 1
        if i >= len(want):
            break
    return out


_OBJECT_FUNCTIONS: dict[tuple[str, int, int], dict] = {}


def object_functions(obj: Path) -> dict[str, tuple[bytes, list[Reloc]]]:
    """symbol -> (bytes, [Reloc]) for every STT_FUNC the object defines;
    read once per object state (the game module's object serves every game
    unit)."""
    st = obj.stat()
    key = (str(obj), st.st_mtime_ns, st.st_size)
    if key not in _OBJECT_FUNCTIONS:
        _OBJECT_FUNCTIONS[key] = _object_functions(obj)
    return _OBJECT_FUNCTIONS[key]


def _object_functions(obj: Path) -> dict[str, tuple[bytes, list[Reloc]]]:
    from elftools.elf.elffile import ELFFile
    from elftools.elf.relocation import RelocationSection
    out = {}
    with obj.open("rb") as f:
        elf = ELFFile(f)
        symtab = elf.get_section_by_name(".symtab")
        syms = list(symtab.iter_symbols())
        locs = named_locals(syms)
        raw_by_sec: dict[int, list] = {}
        for sec in elf.iter_sections():
            if isinstance(sec, RelocationSection):
                for r in sec.iter_relocations():
                    raw_by_sec.setdefault(sec["sh_info"], []).append(
                        (r["r_offset"], r["r_info_type"], syms[r["r_info_sym"]],
                         r["r_addend"] if "r_addend" in r.entry else 0))
        for sym in syms:
            if sym["st_info"]["type"] != "STT_FUNC" or sym["st_shndx"] in ("SHN_UNDEF", "SHN_ABS"):
                continue
            shndx = sym["st_shndx"]
            sec = elf.get_section(shndx)
            lo, size = sym["st_value"], sym["st_size"]
            data = sec.data()[lo:lo + size]
            raw = [x for x in raw_by_sec.get(shndx, []) if lo <= x[0] < lo + size]
            tails = field_tails(data, [off - lo for off, ty, _s, _a in raw if ty in PCREL_TYPES])
            rl = []
            for off, ty, rsym, addend in raw:
                name, addend, value, ssize = reloc_symbol(elf, locs, rsym, addend, tails.get(off - lo, 0))
                rl.append(Reloc(off - lo, RELOC_WIDTH.get(ty, 4), ty, name, addend, rsym["st_shndx"], value, ssize))
            out[sym.name] = (data, sorted(rl, key=lambda r: r.offset))
    return out


def object_symbol(obj: Path, name: str) -> tuple[int, int, int] | None:
    """(section index, value, size) of a symbol the object defines, or None."""
    for s in object_view(obj).syms:
        if s.name == name and s["st_shndx"] not in ("SHN_UNDEF", "SHN_ABS"):
            return s["st_shndx"], s["st_value"], s["st_size"]
    return None


class _ObjectView:
    """One object file read once: its symbols, its named locals, every
    section's bytes, flags and size, and its relocations by the section they
    apply to. The game module's object serves thousands of lookups a gate."""

    def __init__(self, obj: Path):
        from elftools.elf.elffile import ELFFile
        from elftools.elf.relocation import RelocationSection
        with obj.open("rb") as f:
            elf = ELFFile(f)
            self.syms = list(elf.get_section_by_name(".symtab").iter_symbols())
            self.locs = named_locals(self.syms)
            self.sections = {}
            self.relocs: dict[int, list] = {}
            self.names: dict[int, str] = {}
            self.entsizes: dict[int, int] = {}
            for i, sec in enumerate(elf.iter_sections()):
                self.names[i] = sec.name
                self.entsizes[i] = sec["sh_entsize"]
                if isinstance(sec, RelocationSection):
                    self.relocs.setdefault(sec["sh_info"], []).extend(
                        (r["r_offset"], r["r_info_type"], r["r_info_sym"],
                         r["r_addend"] if "r_addend" in r.entry else 0) for r in sec.iter_relocations())
                else:
                    self.sections[i] = (sec.data(), sec["sh_flags"], sec["sh_size"])

    def get_section(self, i: int):
        """What reloc_symbol needs of a section: its name."""
        class _S:
            name = self.names[i]
        return _S()


_OBJECT_VIEWS: dict[tuple[str, int, int], _ObjectView] = {}


def object_view(obj: Path) -> _ObjectView:
    st = obj.stat()
    key = (str(obj), st.st_mtime_ns, st.st_size)
    if key not in _OBJECT_VIEWS:
        _OBJECT_VIEWS[key] = _ObjectView(obj)
    return _OBJECT_VIEWS[key]


def object_bytes_of(obj: Path, section_index: int, value: int, size: int) -> bytes:
    """The bytes a local data symbol (a string literal) covers in the object."""
    d = object_view(obj).sections[section_index][0]
    if size == 0:  # a section symbol: the literal runs to the next NUL
        end = d.find(b"\0", value)
        size = (end + 1 if end >= 0 else len(d)) - value
    return d[value:value + size]


def object_data_relocs(obj: Path, section_index: int, value: int, size: int) -> tuple[list, int, bool]:
    """The relocations inside a data object of the object file (a lookup table
    of pointers), as object_functions lists a function's: ([Reloc] with offsets
    from `value`, the size read (to the section's end when `size` is 0), whether
    the section is a merged-strings section)."""
    v = object_view(obj)
    _data, flags, sh_size = v.sections[section_index]
    strings = bool(flags & 0x30 == 0x30)   # SHF_MERGE | SHF_STRINGS
    if size == 0:
        size = sh_size - value
    out = []
    for off, ty, si, addend in v.relocs.get(section_index, []):
        if not (value <= off < value + size):
            continue
        rsym = v.syms[si]
        name, addend, sv, ssize = reloc_symbol(v, v.locs, rsym, addend, 0)
        out.append(Reloc(off - value, RELOC_WIDTH.get(ty, 4), ty, name, addend, rsym["st_shndx"], sv, ssize))
    return sorted(out, key=lambda r: r.offset), size, strings


def resolve_symbol(objfuncs: dict, fn: str, sym: str) -> str | None:
    """The object's symbol for a row: `sym` itself, or, failing that, the one
    Itanium-mangled symbol whose base identifier is `fn` (a free function or
    a member whose last component is the FUN_ placeholder), so a FUN_<addr>
    row needs no symbol column while its signature is a guess."""
    if sym in objfuncs:
        return sym
    from base_elf import BaseElf
    hits = [s for s in objfuncs if BaseElf.base_identifier(s) == fn]
    return hits[0] if len(hits) == 1 else None


GOTPCREL_TYPES = (9, 41, 42)        # R_X86_64_GOTPCREL, GOTPCRELX, REX_GOTPCRELX


def relaxable_got_load(code: bytes, r) -> bool:
    """True when `r` is a GOTPCREL relocation on `mov r64, [rip+disp32]`
    (REX.W 8B /r with mod=00 rm=101), the form the linker relaxed to
    `lea r64, [rip+disp32]` for every symbol defined in the executable
    (docs/DECISIONS.md D10)."""
    k = r.offset
    return (r.type in GOTPCREL_TYPES and k >= 3 and code[k - 2] == 0x8B
            and (code[k - 1] & 0xC7) == 0x05 and (code[k - 3] & 0xF8) == 0x48)


def relax_got_loads(code: bytes, relocs, base) -> tuple[bytes, set]:
    """The linker's mov-to-lea relaxation applied to the object: a GOT load of
    a symbol that is not an import (the base has GOT slots for imports only)
    becomes the lea the base holds. Returns the relaxed bytes and the offsets
    of the relocations that now verify as PC32."""
    out = bytearray(code)
    relaxed = set()
    if base is None:
        return code, relaxed
    slots = base.got_slots()
    for r in relocs:
        if relaxable_got_load(code, r) and r.symbol not in slots:
            out[r.offset - 2] = 0x8D
            relaxed.add(r.offset)
    return bytes(out), relaxed


R_X86_64_TLSGD, R_X86_64_GOTTPOFF = 19, 22
TLS_GD_LEA = bytes.fromhex("66488d3d")                     # data16 lea rdi, [rip+x@tlsgd]
TLS_GD_CALL = bytes.fromhex("666648e8")                    # data16 data16 rex.W call __tls_get_addr
TLS_IE_FORM = bytes.fromhex("64488b042500000000480305")    # mov rax, fs:[0]; add rax, [rip+x@gottpoff]


def relax_tls_gd(code: bytes, relocs: list) -> tuple[bytes, list]:
    """The linker's GD-to-IE relaxation applied to the object (docs/DECISIONS.md
    D23): the 16-byte general-dynamic sequence the compiler emits for a
    thread-local (`data16 lea rdi, [rip+x@tlsgd]; data16 data16 rex.W call
    __tls_get_addr`) becomes the initial-exec form the base holds in the same
    16 bytes (`mov rax, fs:[0]; add rax, [rip+x@gottpoff]`), the x86-64 psABI's
    GD to IE code transition. The TLSGD and PLT32 relocations are replaced by
    one GOTTPOFF relocation on the add's displacement, against the variable;
    verify_targets and layout_link resolve it to the base's GOT slot holding
    the thread-pointer offset. A TLSGD relocation on another form is left
    alone (it will not match the base, which holds no such form)."""
    by_off = {r.offset: r for r in relocs}
    out = bytearray(code)
    drop, added = set(), []
    for r in relocs:
        k = r.offset
        c = by_off.get(k + 8)
        if (r.type == R_X86_64_TLSGD and k >= 4 and code[k - 4:k] == TLS_GD_LEA
                and code[k + 4:k + 8] == TLS_GD_CALL and c is not None and c.type == 4
                and c.symbol == "__tls_get_addr"):
            out[k - 4:k + 12] = TLS_IE_FORM + b"\0\0\0\0"
            drop.update((k, k + 8))
            added.append(Reloc(k + 8, 4, R_X86_64_GOTTPOFF, r.symbol, -4, r.sym_section, r.sym_value, r.sym_size))
    if not drop:
        return code, relocs
    return bytes(out), sorted([r for r in relocs if r.offset not in drop] + added, key=lambda r: r.offset)


def disasm(code: bytes, base: int):
    from capstone import Cs, CS_ARCH_X86, CS_MODE_64
    md = Cs(CS_ARCH_X86, CS_MODE_64)
    return list(md.disasm(code, base))


def verify_targets(relocs, base_bytes: bytes, base_addr: int, base,
                   relaxed: set | None = None) -> tuple[list[str], int]:
    """For every relocation whose symbol the base can place (a function of the
    table, a D_<hex> label, an import's PLT stub), compute the target the
    base's own displacement encodes and compare. Returns (mismatches,
    unverified count). PC-relative: S + A - P = disp, so S = disp + P - A."""
    import struct as _st
    bad, unverified = [], 0
    for r in relocs:
        if r.width != 4 or r.offset + 4 > len(base_bytes):
            unverified += 1
            continue
        try:
            expected = base.address_of(r.symbol) if base is not None else None
        except ValueError as e:   # a vtable whose evidence fails (a D14 row, an instantiation's slot-0 row)
            where = ""
            if r.symbol.startswith("!") and r.type in (2, 4):   # a refused header static: where the base points
                where = f"; the base's field points at 0x{_st.unpack_from('<i', base_bytes, r.offset)[0] + base_addr + r.offset - r.addend:x}"
            bad.append(f"{e} (reloc at +0x{r.offset:x}{where})")
            continue
        if expected is None:
            unverified += 1
            continue
        P = base_addr + r.offset
        disp = _st.unpack_from("<i", base_bytes, r.offset)[0]
        if r.type in (2, 4) or (relaxed and r.offset in relaxed):   # PC32, PLT32, relaxed GOT load
            actual = disp + P - r.addend
        elif r.type in GOTPCREL_TYPES:  # GOTPCREL*: the GOT slot, not the symbol
            slot = base.got_slots().get(r.symbol)
            if slot is None:
                unverified += 1
                continue
            expected, actual = slot, disp + P - r.addend
        elif r.type in (10, 11):        # 32, 32S: absolute
            actual = disp - r.addend
        elif r.type == R_X86_64_GOTTPOFF:   # the relaxed TLS access: the GOT slot holding the offset (D23)
            slot = base.tls_got_slot(r.symbol)
            if slot is None:
                bad.append(f"{r.symbol}: no single GOT slot of the base holds its thread-pointer offset "
                           f"(reloc at +0x{r.offset:x})")
                continue
            expected, actual = slot, disp + P - r.addend
        else:
            unverified += 1
            continue
        if actual != expected:
            bad.append(f"{r.symbol}: base refers to 0x{actual:x}, source to 0x{expected:x} "
                       f"(reloc at +0x{r.offset:x})")
    return bad, unverified


def compare(obj_bytes: bytes, relocs, base_bytes: bytes, base_addr: int, base=None) -> dict:
    obj_bytes, relocs = relax_tls_gd(obj_bytes, relocs)
    obj_bytes, relaxed = relax_got_loads(obj_bytes, relocs, base)
    a = disasm(obj_bytes, 0)
    b = disasm(base_bytes, base_addr)
    n = max(len(a), len(b))
    equal = 0
    first_diff = None
    rows = []
    for i in range(n):
        ia = a[i] if i < len(a) else None
        ib = b[i] if i < len(b) else None
        ok = False
        if ia is not None and ib is not None and ia.size == ib.size:
            ba, bb = bytearray(ia.bytes), bytearray(ib.bytes)
            for roff, width, _ in relocs:
                if ia.address <= roff < ia.address + ia.size:
                    k = roff - ia.address
                    for j in range(k, min(k + width, ia.size)):
                        ba[j] = bb[j] = 0
            ok = ba == bb
        equal += ok
        if not ok and first_diff is None:
            first_diff = i
        rows.append((ok, ia, ib))
    bad_targets, unverified = verify_targets(relocs, base_bytes, base_addr, base, relaxed) if relocs else ([], 0)
    return {"obj_insns": len(a), "base_insns": len(b), "equal": equal,
            "score": (equal / n) if n else 1.0, "first_diff": first_diff, "rows": rows,
            "obj_size": len(obj_bytes), "base_size": len(base_bytes),
            "bad_targets": bad_targets, "unverified_relocs": unverified,
            "targets_ok": not bad_targets}


def fmt(ins, side_addr=None) -> str:
    if ins is None:
        return "-"
    return f"{ins.address:06x}  {ins.bytes.hex():<22} {ins.mnemonic} {ins.op_str}".rstrip()


def print_diff(name: str, r: dict) -> None:
    fd = r["first_diff"]
    for t in r.get("bad_targets", []):
        print(f"{name}: WRONG TARGET {t}")
    if fd is None:
        extra = f", {r['unverified_relocs']} relocation(s) unverified" if r.get("unverified_relocs") else ""
        print(f"{name}: {'equal' if r.get('targets_ok', True) else 'equal bytes, wrong targets'} "
              f"({r['equal']} instructions, {r['obj_size']} bytes{extra})")
        return
    print(f"{name}: {r['equal']}/{max(r['obj_insns'], r['base_insns'])} instructions equal "
          f"(score {r['score']:.4f}); object {r['obj_size']} bytes, base {r['base_size']} bytes; "
          f"first difference at instruction {fd}")
    lo, hi = max(0, fd - 5), min(len(r["rows"]), fd + 6)
    print(f"  {'':2} {'object (compiled)':<48} | base")
    for i in range(lo, hi):
        ok, ia, ib = r["rows"][i]
        mark = "  " if ok else ">>"
        print(f"  {mark} {fmt(ia):<48} | {fmt(ib)}")


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    g = ap.add_mutually_exclusive_group(required=True)
    g.add_argument("--tu", help="source file, compiled with tools/compile_cpp.sh")
    g.add_argument("--obj", help="an object already built")
    ap.add_argument("--func", action="append", default=[],
                    help="function row name in config/functions.<slug>.txt (repeatable)")
    ap.add_argument("--symbol", action="append", default=[],
                    help="the object's symbol for the corresponding --func, when it differs")
    ap.add_argument("--all", action="store_true",
                    help="every object function whose symbol names a functions row")
    ap.add_argument("--diff", action="store_true")
    ap.add_argument("--json", action="store_true")
    m = ap.add_mutually_exclusive_group()
    m.add_argument("--module", action="store_true",
                   help="a game unit: compare in the whole game module, as the gate does")
    m.add_argument("--both", action="store_true",
                   help="a game unit: the single-file module and the whole module, and whether they differ")
    a = ap.parse_args(argv)
    ver = detect_version(REPO_ROOT)
    funcs = load_functions(ver)
    base = BaseElf(REPO_ROOT, ver)
    data, phdrs = base.data, base.phdrs
    variants: list[tuple[str, Path]] = []
    if a.tu and is_module_tu(a.tu):
        if not a.module:
            variants.append(("single-file module", single_module(a.tu, ver, base)))
        if a.module or a.both:
            variants.append(("whole game module", compile_tu(a.tu, ver)))
        if not a.json:
            print(f"({a.tu}: " + " and ".join(f"{lab}" for lab, _ in variants)
                  + (": the unit and its stand-ins alone; --module for the gate's whole module)"
                     if not (a.module or a.both) else ")"))
    else:
        variants.append(("", compile_tu(a.tu, ver) if a.tu else Path(a.obj)))
    worst = 1.0
    seen: dict[str, list] = {}
    for label, obj in variants:
        objfuncs = tu_functions(a.tu, obj, ver) if a.tu else object_functions(obj)
        pairs: list[tuple[str, str]] = []
        if a.all:
            pairs = [(s, s) for s in objfuncs if s in funcs]
        for i, fn in enumerate(a.func):
            pairs.append((fn, a.symbol[i] if i < len(a.symbol) else fn))
        if not pairs:
            print("match_check: nothing to check (--func or --all)", file=sys.stderr)
            return 2
        if len(variants) > 1:
            print(f"== {label}")
        for fn, sym in pairs:
            if fn not in funcs:
                print(f"match_check: {fn} is not in config/functions.{ver}.txt", file=sys.stderr)
                return 2
            sym = resolve_symbol(objfuncs, fn, sym) or sym
            if sym not in objfuncs:
                print(f"match_check: symbol {sym} not defined in {obj}"
                      f"{renamed_note(a.tu, sym, ver) if a.tu else ''} "
                      f"(have: {', '.join(sorted(objfuncs)[:8])}{'...' if len(objfuncs) > 8 else ''})",
                      file=sys.stderr)
                return 2
            addr, size = funcs[fn]
            off = vaddr_to_off(phdrs, addr)
            base_bytes = data[off:off + size]
            ob, rl = objfuncs[sym]
            r = compare(ob, rl, base_bytes, addr, base)
            seen.setdefault(fn, []).append((label, ob, r["score"] if r["targets_ok"] else 0.0))
            worst = min(worst, r["score"] if r["targets_ok"] else 0.0)
            if a.json:
                print(json.dumps({"func": fn, "symbol": sym, "addr": addr, "size": size,
                                  "score": r["score"], "equal": r["equal"],
                                  "obj_insns": r["obj_insns"], "base_insns": r["base_insns"],
                                  "obj_size": r["obj_size"], "base_size": r["base_size"],
                                  "targets_ok": r["targets_ok"], "bad_targets": r["bad_targets"],
                                  "unverified_relocs": r["unverified_relocs"]}
                                 | ({"build": label} if label else {})))
            elif a.diff or r["first_diff"] is not None or not r["targets_ok"]:
                print_diff(fn if fn == sym else f"{fn} ({sym})", r)
            else:
                print(f"{fn}: equal")
    if len(variants) > 1 and not a.json:
        for fn, vs in seen.items():
            (l1, b1, s1), (l2, b2, s2) = vs[0], vs[-1]
            if b1 != b2 or s1 != s2:
                print(f"{fn}: the single-file module and the whole module DIFFER ({s1:.4f} and {s2:.4f}): "
                      "the module shows the unit something another file defines (cross-file inlining or "
                      "propagation); the gate's answer is the whole module's")
            else:
                print(f"{fn}: the single-file module and the whole module give the same bytes")
    return 0 if worst == 1.0 else 1


if __name__ == "__main__":
    sys.exit(main())
