#!/usr/bin/env python3
"""
gen_data_inc.py: write a table's initializer from the user's executable.

A data object whose bytes carry content from the package (a table of records,
a string pointer) is committed as its type, its count and its name only
(docs/DECISIONS.md D18). Its row of config/data.<slug>.txt
(`D_<hex> <tu> [<symbol>]`, D8) is joined by a row of
config/data_schema.<slug>.txt (`D_<hex> <record type> <count> <header>`), and
this tool writes the rows of its initializer, read from the user's own
baserom/<slug>/eboot.elf, into build/<slug>/gen/D_<hex>.inc. The owning
translation unit defines the object with internal linkage (D17) and includes
the file between the braces:

    static const hkClassMember::TypeProperties D_16dc150[36] = {
    #include "gen/D_16dc150.inc"
    };

tools/compile_cpp.sh puts build/<slug>/ on the include path; build.ninja runs
this tool before the TU compiles (the file is an implicit input of the TU's
compile, and the tool writes a depfile naming the headers it read), and the
file is rewritten only when its text changes. Nothing generated is committed.

The record type is a struct in the header the schema row names (a path under
src/include/, or a header it includes), spelled as the source spells it
(`hkClassMember::TypeProperties` for a struct nested in a class). Its fields
are integers (u8 .. s64 and the C++ integer types), bool, float, double,
enums, pointers (data or function) and arrays of those, laid out by the
x86-64 System V rules. Each value is written by its field's type:

    integer      decimal
    bool         true or false
    float        the shortest text that reads back to the same bits
    enum         the enumerator with that value (Scope::NAME)
    pointer      0 when the slot is 0 and the base relocates nothing there;
                 else the base's RELATIVE relocation at the slot gives the
                 target: a char pointer to a NUL-terminated printable string
                 is that string literal; a function of the table is its name
                 (FUN_<hex>, or the row's mangled name demangled); any other
                 data address is &D_<hex> (D_<hex> for a char pointer). A
                 vtable's address point, an import, or a target the tool cannot
                 name stops the tool with the slot's address: a schema
                 extension or a ruling, never a guess.

Nonzero padding, or a field type the tool cannot read, also stops it.

    gen_data_inc.py D_<hex> [--out F] [--depfile F.d]
    gen_data_inc.py --all            every schema row, to build/<slug>/gen/
"""
from __future__ import annotations

import argparse
import re
import struct
import subprocess
import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(Path(__file__).resolve().parent))
from tlg_version import build_dir, config_path, detect_version  # noqa: E402

INCLUDE_DIR = "src/include"


def fail(msg: str) -> None:
    sys.exit(f"gen_data_inc: {msg}")


# --- the schema ------------------------------------------------------------------

def schema_rows(ver: str) -> dict[str, dict]:
    """D_<hex> -> {type, count, header, tu}: config/data_schema.<slug>.txt joined
    with config/data.<slug>.txt (a schema row without a data row is an error:
    the object must be claimed, so the gate checks the bytes it compiles to)."""
    sp = config_path(REPO_ROOT, ver, "data_schema", "txt")
    dp = config_path(REPO_ROOT, ver, "data", "txt")
    tus = {}
    if dp.exists():
        for line in dp.read_text().splitlines():
            s = line.split("#", 1)[0].split()
            if len(s) >= 2:
                tus[s[0]] = s[1]
    rows = {}
    if not sp.exists():
        return rows
    for n, line in enumerate(sp.read_text().splitlines(), 1):
        s = line.split("#", 1)[0].split()
        if not s:
            continue
        if len(s) != 4 or not re.fullmatch(r"D_[0-9a-f]+", s[0]) or not s[2].isdigit():
            fail(f"{sp.name}:{n}: expected 'D_<hex> <record type> <count> <header>'")
        if s[0] in rows:
            fail(f"{sp.name}:{n}: {s[0]} has a second row")
        if s[0] not in tus:
            fail(f"{sp.name}:{n}: {s[0]} has no row in {dp.name} (the TU that defines it)")
        rows[s[0]] = {"type": s[1], "count": int(s[2]), "header": s[3], "tu": tus[s[0]]}
    return rows


# --- C++ types ---------------------------------------------------------------------

class T:
    """A type: kind is int, bool, float, enum, ptr, fptr, array or record."""

    def __init__(self, kind: str, size: int, align: int, **kw):
        self.kind, self.size, self.align = kind, size, align
        self.__dict__.update(kw)


BUILTINS = {
    "char": (1, True), "signed char": (1, True), "unsigned char": (1, False),
    "short": (2, True), "short int": (2, True), "signed short": (2, True),
    "unsigned short": (2, False), "unsigned short int": (2, False),
    "int": (4, True), "signed int": (4, True), "signed": (4, True),
    "unsigned int": (4, False), "unsigned": (4, False),
    "long": (8, True), "long int": (8, True), "signed long": (8, True),
    "unsigned long": (8, False), "unsigned long int": (8, False),
    "long long": (8, True), "long long int": (8, True),
    "unsigned long long": (8, False), "unsigned long long int": (8, False),
    "wchar_t": (2, False),   # -fshort-wchar (config/flags.<slug>.txt)
}
WORDS = {"unsigned", "signed", "char", "short", "int", "long", "float", "double", "bool", "void", "wchar_t"}
QUALIFIERS = {"const", "volatile", "struct", "class", "union", "enum", "typename"}


def strip_cpp(text: str) -> str:
    text = re.sub(r"/\*.*?\*/", " ", text, flags=re.S)
    text = re.sub(r"//[^\n]*", " ", text)
    out, cont = [], False
    for line in text.splitlines():
        directive = cont or line.lstrip().startswith("#")
        cont = directive and line.rstrip().endswith("\\")
        out.append("" if directive else line)
    return "\n".join(out)


def tokenize(text: str) -> list[str]:
    return re.findall(r"0[xX][0-9a-fA-F]+[uUlL]*|\d+[uUlL]*|[A-Za-z_]\w*|::|\.\.\.|[{}()\[\];,*&:=+\-/<>~]", text)


def int_literal(tok: str) -> int:
    return int(tok.rstrip("uUlL"), 0)


class Scope:
    """A namespace or record of the header, with the records, enums and
    typedefs declared in it."""

    def __init__(self, name: str, parent: "Scope | None", kind: str, body=None, bases=False, path=""):
        self.name, self.parent, self.kind, self.body, self.bases = name, parent, kind, body, bases
        self.path = path
        self.records: dict[str, Scope] = {}
        self.enums: dict[str, T] = {}
        self.typedefs: dict[str, list[str]] = {}

    def qualified(self) -> str:
        parts, s = [], self
        while s is not None and s.name:
            parts.append(s.name)
            s = s.parent
        return "::".join(reversed(parts))


class Headers:
    """The headers a schema row names, read as the compile reads them: the
    named header and the headers it includes from src/include/."""

    def __init__(self):
        self.root = Scope("", None, "namespace")
        self.read: list[str] = []
        self.cache: dict[str, T] = {}

    def load(self, rel: str) -> None:
        if rel in self.read:
            return
        p = REPO_ROOT / rel
        if not p.is_file():
            fail(f"{rel}: no such header")
        self.read.append(rel)
        text = p.read_text(encoding="latin-1")
        for name in re.findall(r'^\s*#\s*include\s*"([^"]+)"', text, re.M):
            for d in (str(Path(rel).parent), INCLUDE_DIR):
                if (REPO_ROOT / d / name).is_file():
                    self.load(str(Path(d) / name))
                    break
        self._scan(tokenize(strip_cpp(text)), rel)

    def _match(self, toks: list[str], i: int, open_: str, close: str) -> int:
        depth = 0
        while i < len(toks):
            if toks[i] == open_:
                depth += 1
            elif toks[i] == close:
                depth -= 1
                if depth == 0:
                    return i
            i += 1
        fail("unbalanced braces")
        return i

    def _scan(self, toks: list[str], path: str) -> None:
        """Every namespace, record, enum and typedef of the token stream,
        attached to the scope that declares it."""

        def walk(i: int, end: int, scope: Scope) -> None:
            stmt_start = i
            while i < end:
                t = toks[i]
                if t == "namespace" and i + 2 < end and toks[i + 2] == "{":
                    close = self._match(toks, i + 2, "{", "}")
                    ns = scope.records.get(toks[i + 1]) or Scope(toks[i + 1], scope, "namespace", path=path)
                    scope.records[toks[i + 1]] = ns
                    walk(i + 3, close, ns)
                    i = stmt_start = close + 1
                    continue
                if t in ("struct", "class", "union") and i + 1 < end and re.fullmatch(r"[A-Za-z_]\w*", toks[i + 1]):
                    j = i + 2
                    bases = False
                    if j < end and toks[j] == ":":
                        bases = True
                        while j < end and toks[j] not in ("{", ";"):
                            j += 1
                    if j < end and toks[j] == "{":
                        close = self._match(toks, j, "{", "}")
                        rec = Scope(toks[i + 1], scope, t, body=(j + 1, close), bases=bases, path=path)
                        scope.records[toks[i + 1]] = rec
                        walk(j + 1, close, rec)
                        i = close + 1
                        continue
                if t == "enum":
                    j = i + 1
                    if j < end and toks[j] in ("class", "struct"):
                        j += 1
                    name = toks[j] if j < end and re.fullmatch(r"[A-Za-z_]\w*", toks[j]) else None
                    if name is not None:
                        j += 1
                    under = None
                    if j < end and toks[j] == ":":
                        k = j + 1
                        while k < end and toks[k] not in ("{", ";"):
                            k += 1
                        under = toks[j + 1:k]
                        j = k
                    if j < end and toks[j] == "{":
                        close = self._match(toks, j, "{", "}")
                        if name is not None:
                            scope.enums[name] = self._enum(toks[j + 1:close], under, scope, name)
                        i = close + 1
                        continue
                if t == "typedef":
                    k = i + 1
                    depth = 0
                    while k < end and not (depth == 0 and toks[k] == ";"):
                        depth += toks[k] in "({[" and 1 or 0
                        depth -= toks[k] in ")}]" and 1 or 0
                        k += 1
                    decl = toks[i + 1:k]
                    if decl and "(" not in decl and "{" not in decl and re.fullmatch(r"[A-Za-z_]\w*", decl[-1]):
                        scope.typedefs[decl[-1]] = decl[:-1]
                    i = stmt_start = k + 1
                    continue
                if t == "{":   # a function body or an initializer
                    i = self._match(toks, i, "{", "}") + 1
                    continue
                i += 1

        walk(0, len(toks), self.root)

    def _enum(self, body: list[str], under, scope: Scope, name: str) -> T:
        items, value = [], 0
        k = 0
        while k < len(body):
            if not re.fullmatch(r"[A-Za-z_]\w*", body[k]):
                k += 1
                continue
            item = body[k]
            k += 1
            if k < len(body) and body[k] == "=":
                e = k + 1
                while e < len(body) and body[e] != ",":
                    e += 1
                expr = body[k + 1:e]
                if len(expr) == 1 and re.fullmatch(r"\d\w*|0[xX]\w+", expr[0]):
                    value = int_literal(expr[0])
                elif len(expr) == 2 and expr[0] == "-" and re.fullmatch(r"\d\w*|0[xX]\w+", expr[1]):
                    value = -int_literal(expr[1])
                else:
                    value = None   # an expression the tool does not evaluate
                k = e
            items.append((item, value))
            value = None if value is None else value + 1
        size, signed = 4, any(v is not None and v < 0 for _, v in items)
        if under:
            u = self.base(under, scope)
            if u.kind != "int":
                fail(f"enum {name}: underlying type {' '.join(under)} is not an integer")
            size, signed = u.size, u.signed
        return T("enum", size, size, signed=signed, items=items, scope=scope, name=name)

    # --- lookup --------------------------------------------------------------------
    def find(self, qname: list[str], scope: Scope):
        """The record, enum or typedef a (possibly qualified) name names, looked
        up from scope outward."""
        s = scope
        while s is not None:
            hit = self._find_in(qname, s)
            if hit is not None:
                return hit
            s = s.parent
        return None

    def _find_in(self, qname: list[str], s: Scope):
        for part in qname[:-1]:
            if part not in s.records:
                return None
            s = s.records[part]
        last = qname[-1]
        if last in s.records:
            return ("record", s.records[last])
        if last in s.enums:
            return ("enum", s.enums[last])
        if last in s.typedefs:
            return ("typedef", (s.typedefs[last], s))
        return None

    def base(self, toks: list[str], scope: Scope) -> T:
        """The type a run of type tokens names (no declarator)."""
        toks = [t for t in toks if t not in QUALIFIERS]
        key = " ".join(toks)
        if key in BUILTINS:
            n, sg = BUILTINS[key]
            return T("int", n, n, signed=sg, name=key)
        if key == "bool":
            return T("bool", 1, 1, name=key)
        if key == "float":
            return T("float", 4, 4, name=key)
        if key == "double":
            return T("float", 8, 8, name=key)
        if key == "void":
            return T("void", 0, 1, name=key)
        if toks and toks[-1] == "*":
            return T("ptr", 8, 8, target=self.base(toks[:-1], scope))
        q = [t for t in toks if t != "::"]
        if not q or "::" in toks and any(t != "::" and not re.fullmatch(r"[A-Za-z_]\w*", t) for t in toks):
            fail(f"cannot read type '{key}'")
        hit = self.find(q, scope)
        if hit is None:
            fail(f"no type '{key}' in {', '.join(self.read)}")
        kind, v = hit
        if kind == "enum":
            return v
        if kind == "typedef":
            return self.base(v[0], v[1])
        return self.record(v)

    def record(self, rec: Scope) -> T:
        q = rec.qualified()
        if q in self.cache:
            return self.cache[q]
        if rec.kind == "namespace":
            fail(f"{q} is a namespace")
        if rec.bases:
            fail(f"{q}: a record with a base class is not read (a schema extension)")
        toks = self.toks_of(rec)
        fields = []
        k = 0
        stmt: list[str] = []
        depth = 0
        while k < len(toks):
            t = toks[k]
            if t == "{" and depth == 0:
                close = self._match(toks, k, "{", "}")
                if "(" in stmt:          # a member function's body
                    stmt = []
                    k = close + 1
                    if k < len(toks) and toks[k] == ";":
                        k += 1
                    continue
                if stmt and stmt[0] in ("struct", "class", "union", "enum"):
                    after = close + 1
                    if after < len(toks) and toks[after] != ";":
                        fail(f"{q}: a field of an unnamed or nested record type is not read (a schema extension)")
                    stmt = []
                    k = after + 1
                    continue
                stmt.append(t)
                k += 1
                continue
            if t in ("(", "["):
                depth += 1
            elif t in (")", "]"):
                depth -= 1
            if t == ":" and depth == 0 and len(stmt) == 1 and stmt[0] in ("public", "private", "protected"):
                stmt = []
                k += 1
                continue
            if t == ";" and depth == 0:
                if stmt:
                    fields.extend(self._field(stmt, rec))
                stmt = []
                k += 1
                continue
            stmt.append(t)
            k += 1
        size, align, laid, is_union = 0, 1, [], rec.kind == "union"
        for name, ty in fields:
            align = max(align, ty.align)
            off = 0 if is_union else -(-size // ty.align) * ty.align
            laid.append((name, ty, off))
            size = max(size, off + ty.size)
        size = -(-size // align) * align
        ty = T("record", size, align, fields=laid, union=is_union, name=q)
        self.cache[q] = ty
        return ty

    def toks_of(self, rec: Scope) -> list[str]:
        text = (REPO_ROOT / rec.path).read_text(encoding="latin-1")
        toks = tokenize(strip_cpp(text))
        lo, hi = rec.body
        return toks[lo:hi]

    def _field(self, stmt: list[str], rec: Scope) -> list[tuple[str, T]]:
        """The data members one member declaration declares ([] for a static,
        a typedef, a using, a friend, a member function)."""
        if stmt[0] in ("static", "typedef", "using", "friend", "template", "enum"):
            return []
        if stmt[0] == "virtual" or "virtual" in stmt:
            fail(f"{rec.qualified()}: a polymorphic record holds a vtable pointer (a schema extension)")
        if "(" in stmt:
            # a function pointer member: <ret> ( * name ) ( params )
            p = stmt.index("(")
            if stmt[p + 1:p + 2] == ["*"] and re.fullmatch(r"[A-Za-z_]\w*", stmt[p + 2]) and stmt[p + 3] == ")":
                return [(stmt[p + 2], T("fptr", 8, 8))]
            return []   # a member function
        if "=" in stmt or ":" in [t for t in stmt if t != "::"]:
            fail(f"{rec.qualified()}: cannot read '{' '.join(stmt)}' (a default or a bit-field)")
        # the base type is what precedes the first declarator's stars and name
        # (the last identifier before its first '[' or ',')
        first = stmt.index(",") if "," in stmt else len(stmt)
        head = stmt[:first]
        stop = head.index("[") if "[" in head else len(head)
        n = max((i for i in range(stop) if re.fullmatch(r"[A-Za-z_]\w*", head[i])
                 and head[i] not in QUALIFIERS), default=-1)
        b = n
        while b > 0 and head[b - 1] in ("*", "const", "volatile"):
            b -= 1
        if b <= 0:
            fail(f"{rec.qualified()}: cannot read '{' '.join(stmt)}'")
        base = self.base(stmt[:b], rec)
        out = []
        decls, cur = [], []
        for t in stmt[b:]:
            if t == ",":
                decls.append(cur)
                cur = []
            else:
                cur.append(t)
        decls.append(cur)
        for d in decls:
            ty = base
            while d and d[0] in ("*", "const", "volatile"):
                if d[0] == "*":
                    ty = T("ptr", 8, 8, target=ty)
                d = d[1:]
            if not d or not re.fullmatch(r"[A-Za-z_]\w*", d[0]):
                fail(f"{rec.qualified()}: cannot read declarator '{' '.join(d)}'")
            name, rest, dims = d[0], d[1:], []
            while rest:
                if rest[0] != "[" or len(rest) < 3 or rest[2] != "]" or not re.fullmatch(r"\d\w*|0[xX]\w+", rest[1]):
                    fail(f"{rec.qualified()}: cannot read declarator '{' '.join(d)}'")
                dims.append(int_literal(rest[1]))
                rest = rest[3:]
            for n in reversed(dims):
                ty = T("array", ty.size * n, ty.align, elem=ty, n=n)
            if ty.kind == "void":
                fail(f"{rec.qualified()}: a void member")
            out.append((name, ty))
        return out

    def record_type(self, name: str) -> T:
        hit = self._find_in([p for p in name.split("::") if p], self.root)
        if hit is None or hit[0] != "record":
            fail(f"no record {name} in {', '.join(self.read)}")
        return self.record(hit[1])


# --- values ------------------------------------------------------------------------

def float_text(bits: bytes, double: bool) -> str | None:
    v = struct.unpack("<d" if double else "<f", bits)[0]
    if v != v or v in (float("inf"), float("-inf")):
        return None
    if double:
        s = repr(v)
    else:
        for d in range(1, 10):
            s = f"{v:.{d}g}"
            if struct.pack("<f", float(s)) == bits:
                break
    if "." not in s and "e" not in s:
        s += ".0"
    return s if double else s + "f"


def int_text(v: int, ty: T) -> str:
    bits = 8 * ty.size
    if ty.signed and v >= 1 << (bits - 1):
        v -= 1 << bits
    if bits == 64:
        if v == -(1 << 63):
            return "(-9223372036854775807L - 1)"
        return f"{v}" if -(1 << 31) <= v < 1 << 31 else (f"{v}L" if ty.signed else f"{v}UL")
    if v == -(1 << 31):
        return "(-2147483647 - 1)"
    if not ty.signed and bits == 32 and v >= 1 << 31:
        return f"{v}u"
    return str(v)


def c_string(bs: bytes) -> str:
    out = []
    for b in bs:
        c = chr(b)
        if c in '"\\':
            out.append("\\" + c)
        elif c == "\n":
            out.append("\\n")
        elif c == "\t":
            out.append("\\t")
        elif c == "\r":
            out.append("\\r")
        else:
            out.append(c)
    return '"' + "".join(out) + '"'


def demangled(sym: str) -> str:
    """A mangled function name as the C++ names it (its qualified name, no
    parameters), for a function of the table the matched rows renamed."""
    if not sym.startswith("_Z"):
        return sym
    r = subprocess.run(["c++filt", "-p", sym], capture_output=True, text=True, check=True)
    return r.stdout.strip()


class Writer:
    def __init__(self, base, dyn: dict, vtable_points: set[int], funcs: dict[int, str], ident: str):
        self.base, self.dyn, self.vtable_points, self.funcs = base, dyn, vtable_points, funcs
        self.ident = ident

    def where(self, va: int, path: str) -> str:
        return f"{self.ident} 0x{va:x} ({path})"

    def string_at(self, va: int) -> bytes | None:
        """The NUL-terminated printable string at va, or None."""
        p = self.base.segment_of(va)
        if p is None or va >= p["vaddr"] + p["filesz"]:
            return None
        o = self.base.off(va)
        end = self.base.data.find(b"\0", o, p["offset"] + p["filesz"])
        if end < 0:
            return None
        s = self.base.data[o:end]
        if all(0x20 <= b < 0x7F or b in (9, 10, 13) for b in s):
            return s
        return None

    def value(self, ty: T, va: int, path: str) -> str:
        if ty.kind == "int":
            return int_text(int.from_bytes(self.base.read(va, ty.size), "little"), ty)
        if ty.kind == "bool":
            b = self.base.read(va, 1)[0]
            if b > 1:
                fail(f"{self.where(va, path)}: bool holds {b}")
            return "true" if b else "false"
        if ty.kind == "float":
            s = float_text(self.base.read(va, ty.size), ty.size == 8)
            if s is None:
                fail(f"{self.where(va, path)}: NaN or infinity in a float field")
            return s
        if ty.kind == "enum":
            v = int.from_bytes(self.base.read(va, ty.size), "little")
            if ty.signed and v >= 1 << (8 * ty.size - 1):
                v -= 1 << (8 * ty.size)
            names = [n for n, x in ty.items if x == v]
            if not names:
                fail(f"{self.where(va, path)}: {v} is no enumerator of {ty.name}")
            q = ty.scope.qualified()
            return f"{q}::{names[0]}" if q else names[0]
        if ty.kind in ("ptr", "fptr"):
            return self.pointer(ty, va, path)
        if ty.kind == "array":
            el = ty.elem
            return "{" + ", ".join(self.value(el, va + i * el.size, f"{path}[{i}]") for i in range(ty.n)) + "}"
        if ty.kind == "record":
            if ty.union:
                fail(f"{self.where(va, path)}: a union is not written (a schema extension)")
            held = bytearray(ty.size)
            parts = []
            for name, f, off in ty.fields:
                held[off:off + f.size] = b"\xff" * f.size
                parts.append(self.value(f, va + off, f"{path}.{name}" if path else name))
            raw = self.base.read(va, ty.size)
            loose = [i for i in range(ty.size) if raw[i] and not held[i]]
            if loose:
                fail(f"{self.where(va + loose[0], path)}: nonzero padding at +0x{loose[0]:x} of {ty.name}")
            return "{" + ", ".join(parts) + "}"
        fail(f"{self.where(va, path)}: cannot write a value of kind {ty.kind}")
        return ""

    def pointer(self, ty: T, va: int, path: str) -> str:
        word = int.from_bytes(self.base.read(va, 8), "little")
        d = self.dyn.get(va)
        if d is None:
            if word == 0:
                return "0"
            fail(f"{self.where(va, path)}: pointer slot holds 0x{word:x} and the base relocates nothing there")
        rtype, sym, target = d
        if rtype != 8:   # R_X86_64_RELATIVE
            fail(f"{self.where(va, path)}: slot relocated against {sym or '?'} (type {rtype}): an import "
                 "is not written (a schema extension)")
        if target in self.vtable_points:
            fail(f"{self.where(va, path)}: points at a vtable's address point 0x{target:x}; how it is "
                 "spelled is a ruling (docs/DECISIONS.md D18)")
        is_char = ty.kind == "ptr" and ty.target.kind == "int" and ty.target.size == 1
        if is_char:
            s = self.string_at(target)
            if s is not None:
                return c_string(s)
        if target in self.funcs:
            return demangled(self.funcs[target])
        if self.base.segment_of(target) is None:
            fail(f"{self.where(va, path)}: target 0x{target:x} is outside the loaded segments")
        return f"D_{target:x}" if is_char else f"&D_{target:x}"


def generate(ident: str, row: dict, ver: str) -> tuple[str, list[str]]:
    """The .inc text for one schema row, and the headers it read."""
    from base_elf import BaseElf
    from layout_link import base_dynamic_relocs
    h = Headers()
    h.load(row["header"])
    ty = h.record_type(row["type"])
    base = BaseElf(REPO_ROOT, ver)
    dyn = base_dynamic_relocs(base)
    points = set()
    for sym, addr in list(base.vtables.items()) + [(s, v[0]) for s, v in base._derived.items()]:
        points.add(addr + 0x10)
    funcs = {a: n for a, _s, n in base.functions}
    w = Writer(base, dyn, points, funcs, ident)
    va0 = int(ident[2:], 16)
    if base.off(va0) is None or base.off(va0 + ty.size * row["count"] - 1) is None:
        fail(f"{ident}: {row['count']} x {ty.size} bytes from 0x{va0:x} are not file-backed bytes of one segment")
    lines = [w.value(ty, va0 + i * ty.size, f"[{i}]") + "," for i in range(row["count"])]
    return "\n".join(lines) + "\n", h.read


def write_if_changed(path: Path, text: str) -> None:
    """Write text unless the file already holds it, so ninja's restat skips
    the compiles that include it."""
    raw = text.encode("latin-1")
    if path.exists() and path.read_bytes() == raw:
        return
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_bytes(raw)


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    g = ap.add_mutually_exclusive_group(required=True)
    g.add_argument("ident", nargs="?", help="the object's D_<hex> name")
    g.add_argument("--all", action="store_true", help="every row of the schema")
    ap.add_argument("--out", type=Path, help="default build/<slug>/gen/D_<hex>.inc")
    ap.add_argument("--depfile", type=Path, help="write the headers read, for ninja")
    a = ap.parse_args(argv)
    ver = detect_version(REPO_ROOT)
    rows = schema_rows(ver)
    gen = build_dir(REPO_ROOT, ver) / "gen"
    idents = sorted(rows) if a.all else [a.ident]
    for ident in idents:
        if ident not in rows:
            fail(f"{ident} has no row in {config_path(REPO_ROOT, ver, 'data_schema', 'txt').name}")
        out = a.out if a.out and not a.all else gen / f"{ident}.inc"
        text, read = generate(ident, rows[ident], ver)
        write_if_changed(out, text)
        if a.depfile and not a.all:
            write_if_changed(a.depfile, f"{out}: " + " ".join(read) + "\n")
    return 0


if __name__ == "__main__":
    sys.exit(main())
