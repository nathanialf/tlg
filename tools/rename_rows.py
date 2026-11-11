#!/usr/bin/env python3
"""tools/rename_rows.py <tu> [--rename OLD=NEW ...] [--write]: re-point the
symbol column of a unit's rows of config/matched.<slug>.txt that name
members of a library instantiation for a lambda (std::function's
implementation, tools/base_elf.py INSTANTIATION_SLOTS), after the unit
changed the names the compiler gives them.

Such a symbol carries the lambda's enclosing function and its number:
`_ZNSt14_Function_implIZ<function>E3$_<n>...E5_CallE...`, where `$_<n>`
counts the lambdas of the whole file (a lambda added above renumbers every
later one) and `Ul...E<n>_` those of one scope (a lambda in an inline
function or a class member). Renaming the enclosing function or adding a
lambda leaves rows naming symbols the object no longer defines.

The tool compiles the unit (its single-file module, as the inner loop does),
lists the object's instantiations by (enclosing function, order in it), and
for each enclosing function the rows name (by its new name when --rename
maps it) assigns the rows' instantiations, in their old order, to the
object's instantiations of that function, in order: the one order-keeping
assignment under which every re-pointed row compares equal to the base
(tools/match_check.py compare, its targets checked). No such assignment, or
more than one, is refused with the candidates printed. Rows whose symbol the
object defines are left alone. Without --write it prints the rewrites.
"""
from __future__ import annotations

import argparse
import itertools
import re
import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO_ROOT / "tools"))
import match_check as mc  # noqa: E402
from base_elf import BaseElf  # noqa: E402
from survey_elf import vaddr_to_off  # noqa: E402
from tlg_version import config_path, detect_version  # noqa: E402


def lambda_key(cls_enc: str) -> tuple[str, str, int] | None:
    """(enclosing function encoding, lambda token, order key) of an
    instantiation's class encoding `St14_Function_implIZ<enc>E<token>...E`."""
    tmpl = next((t for t in BaseElf.INSTANTIATION_SLOTS if cls_enc.startswith(t)), None)
    if tmpl is None or not cls_enc.startswith("Z", len(tmpl)):
        return None
    z = len(tmpl) + 1
    end = BaseElf.mangled_close(cls_enc, z)
    if end is None:
        return None
    fn = cls_enc[z:end - 1]
    rest = cls_enc[end:]
    m = re.match(r"^(\d+)\$_(\d+)", rest)           # an ordinary function's lambda: internal, file-wide number
    if m and int(m.group(1)) == len(m.group(2)) + 2:
        return fn, rest[:m.end()], int(m.group(2))
    if rest.startswith("Ul"):                         # a lambda of an inline scope: Ul<params>E[<n>]_
        close = BaseElf.mangled_close(rest, 2)
        if close is None:
            return None
        m = re.match(r"^(\d*)_", rest[close:])
        if m:
            return fn, rest[:close + m.end()], (int(m.group(1)) + 1 if m.group(1) else 0)
    return None


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("tu")
    ap.add_argument("--rename", action="append", default=[], metavar="OLD=NEW",
                    help="the enclosing function's identifier (or mangled encoding) before and after")
    ap.add_argument("--write", action="store_true", help="rewrite config/matched.<slug>.txt")
    a = ap.parse_args(argv)
    ver = detect_version(REPO_ROOT)
    base = BaseElf(REPO_ROOT, ver)
    funcs = mc.load_functions(ver)
    obj = mc.single_module(a.tu, ver, base) if mc.is_module_tu(a.tu) else mc.compile_tu(a.tu, ver)
    objfuncs = mc.object_functions(obj)
    renames = dict(r.split("=", 1) for r in a.rename)

    def enclosing(fn: str) -> str:
        for old, new in renames.items():
            fn = re.sub(rf"(?<![0-9A-Za-z_]){len(old)}{re.escape(old)}", f"{len(new)}{new}", fn)
        return fn

    # the object's instantiations: enclosing function -> [(order, class encoding)]
    have: dict[str, list[tuple[int, str]]] = {}
    for sym in objfuncs:
        m = BaseElf.instantiation_member(sym)
        if m:
            enc = m[0][len("_ZTV"):]
            k = lambda_key(enc)
            if k and (k[2], enc) not in have.get(k[0], []):
                have.setdefault(k[0], []).append((k[2], enc))
    for v in have.values():
        v.sort()
    print(f"rename_rows: {a.tu}: {sum(len(v) for v in have.values())} instantiations")
    for fn, v in sorted(have.items()):
        print(f"  {fn}: " + ", ".join(lambda_key(e)[1] for _o, e in v))

    p = config_path(REPO_ROOT, ver, "matched", "txt")
    lines = p.read_text().splitlines()
    # the unit's stale rows: old class encoding -> [(line index, row, member suffix)]
    stale: dict[str, list[tuple[int, str, str]]] = {}
    for i, line in enumerate(lines):
        s = line.split("#", 1)[0].split()
        if len(s) < 3 or s[1] != a.tu or s[2] in objfuncs:
            continue
        m = BaseElf.instantiation_member(s[2])
        if not m:
            continue
        enc = m[0][len("_ZTV"):]
        prefix = s[2][:s[2].index(enc)]
        stale.setdefault(enc, []).append((i, s[0], prefix, s[2][len(prefix) + len(enc):]))
    if not stale:
        print("rename_rows: no stale instantiation rows")
        return 0
    by_fn: dict[str, list[tuple[int, str]]] = {}
    for enc in stale:
        k = lambda_key(enc)
        if not k:
            print(f"rename_rows: {enc}: not a lambda's instantiation", file=sys.stderr)
            return 1
        by_fn.setdefault(enclosing(k[0]), []).append((k[2], enc))

    def equal(row: str, sym: str) -> bool:
        if sym not in objfuncs or row not in funcs:
            return False
        addr, size = funcs[row]
        off = vaddr_to_off(base.phdrs, addr)
        ob, rl = objfuncs[sym]
        r = mc.compare(ob, rl, base.data[off:off + size], addr, base)
        return r["equal"] and r["targets_ok"]

    edits: dict[int, str] = {}
    for fn, olds in sorted(by_fn.items()):
        olds.sort()
        news = have.get(fn, [])
        good = []
        for pick in itertools.combinations(news, len(olds)):
            trial = {}
            for (_o, old), (_n, new) in zip(olds, pick):
                for i, row, prefix, member in stale[old]:
                    trial[i] = (row, prefix + new + member)
            if all(equal(row, sym) for row, sym in trial.values()):
                good.append(trial)
        if len(good) != 1:
            print(f"rename_rows: {fn}: {len(good)} order-keeping assignments of {len(olds)} stale "
                  f"instantiation(s) to the object's {len(news)} compare equal; refused", file=sys.stderr)
            return 1
        for i, (row, sym) in good[0].items():
            old = lines[i].split()[2]
            print(f"  {row}: {old} -> {sym}")
            edits[i] = lines[i].replace(old, sym, 1)
    if a.write:
        for i, line in edits.items():
            lines[i] = line
        p.write_text("\n".join(lines) + "\n")
        print(f"rename_rows: {len(edits)} rows rewritten in {p.relative_to(REPO_ROOT)}")
    else:
        print(f"rename_rows: {len(edits)} rows would be rewritten (--write)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
