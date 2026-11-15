#!/usr/bin/env python3
"""
ir_layout.py: where an element of an LLVM IR type lies, under the game
target's data layout (x86_64-scei-ps4: e-m:e-i64:64-f80:128-n8:16:32:64-S128).

    offset_of(type text, [index, ...], named types) -> byte offset

Used by tools/match_check.py for the pieces of a file static the link stage
split (GlobalOpt's SRA names piece i of an array or struct `<name>.<i>`, and
splits a piece again): the piece `<name>.7.0.0` of `[8 x %struct.E]` is
element 7's first field's first field, and lies where that element lies in
the whole object. Only the types a game static is made of are known
(integers, float, double, pointers, arrays, structs, packed structs,
vectors of those); anything else raises LayoutError.
"""
from __future__ import annotations

import re


class LayoutError(Exception):
    pass


_INT = re.compile(r"^i(\d+)$")
_ARRAY = re.compile(r"^\[(\d+) x (.*)\]$", re.S)
_VECTOR = re.compile(r"^<(\d+) x (.*)>$", re.S)


def _split(body: str) -> list[str]:
    """The top-level comma-separated members of a struct body."""
    out, depth, cur = [], 0, ""
    for ch in body:
        if ch in "[{<(":
            depth += 1
        elif ch in "]}>)":
            depth -= 1
        if ch == "," and depth == 0:
            out.append(cur.strip())
            cur = ""
        else:
            cur += ch
    if cur.strip():
        out.append(cur.strip())
    return out


def _up(n: int, a: int) -> int:
    return (n + a - 1) // a * a


def _members(t: str, types: dict[str, str]) -> tuple[list[str], bool] | None:
    """(member types, packed) when `t` is a struct, else None."""
    t = t.strip()
    seen = set()
    while t.startswith("%") and not t.endswith("*"):
        if t in seen or t not in types or types[t] == "opaque":
            raise LayoutError(f"type {t} has no body")
        seen.add(t)
        t = types[t].strip()
    if t.startswith("<{") and t.endswith("}>"):
        return _split(t[2:-2]), True
    if t.startswith("{") and t.endswith("}"):
        return _split(t[1:-1]), False
    return None


def size_align(t: str, types: dict[str, str]) -> tuple[int, int]:
    """(allocation size, ABI alignment) of the IR type `t` in bytes."""
    t = t.strip()
    if t.endswith("*"):
        return 8, 8
    m = _INT.match(t)
    if m:
        size = (int(m.group(1)) + 7) // 8
        align = 1
        while align < size and align < 8:
            align *= 2
        return _up(size, align), align
    if t == "float":
        return 4, 4
    if t == "double":
        return 8, 8
    m = _ARRAY.match(t)
    if m:
        s, a = size_align(m.group(2), types)
        return int(m.group(1)) * s, a
    mem = _members(t, types)
    if mem is not None:
        members, packed = mem
        off, align = 0, 1
        for x in members:
            s, a = size_align(x, types)
            if not packed:
                off = _up(off, a)
                align = max(align, a)
            off += s
        return _up(off, align), align
    m = _VECTOR.match(t)
    if m:
        s, _a = size_align(m.group(2), types)
        size = int(m.group(1)) * s
        align = 1
        while align < size:
            align *= 2
        return _up(size, align), align
    raise LayoutError(f"type {t} is not one the layout knows")


def offset_of(t: str, path: list[int], types: dict[str, str]) -> int:
    """The byte offset of the element `path` names inside an object of the
    IR type `t` (each index an array element or a struct member)."""
    off = 0
    for i in path:
        t = t.strip()
        m = _ARRAY.match(t)
        if m:
            if i >= int(m.group(1)):
                raise LayoutError(f"index {i} is outside {t}")
            t = m.group(2)
            off += i * size_align(t, types)[0]
            continue
        mem = _members(t, types)
        if mem is None:
            raise LayoutError(f"{t} has no element {i}")
        members, packed = mem
        if i >= len(members):
            raise LayoutError(f"index {i} is outside {t}")
        o = 0
        for k, x in enumerate(members):
            s, a = size_align(x, types)
            if not packed:
                o = _up(o, a)
            if k == i:
                break
            o += s
        off += o
        t = members[i]
    return off
