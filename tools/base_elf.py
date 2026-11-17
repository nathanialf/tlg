"""
base_elf.py: the facts of the target's base executable that the match tools
share: its text segment, its function table, and the addresses the linker
gave every import (PLT stub and GOT slot) and every GOT-resident global.

Everything here is read from the user's own baserom/<slug>/eboot.elf at run
time; nothing is stored in the repository but names and addresses that the
tools derive again on every run.
"""
from __future__ import annotations

import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from tlg_version import baseelf_path, config_path, detect_version  # noqa: E402
from survey_elf import (DT_SCE_JMPREL, DT_SCE_PLTRELSZ, DT_SCE_RELA, DT_SCE_RELASZ,  # noqa: E402
                        DT_SCE_STRTAB, DT_SCE_SYMENT, DT_SCE_SYMTAB, DT_SCE_SYMTABSZ,
                        PT_DYNAMIC, PT_LOAD, PT_SCE_DYNLIBDATA, read_phdrs, vaddr_to_off)

R_X86_64_64, R_X86_64_PC32, R_X86_64_PLT32, R_X86_64_GLOB_DAT, R_X86_64_JUMP_SLOT = 1, 2, 4, 6, 7
R_X86_64_RELATIVE, R_X86_64_GOTPCREL, R_X86_64_32, R_X86_64_32S = 8, 9, 10, 11
R_X86_64_GOTPCRELX, R_X86_64_REX_GOTPCRELX = 41, 42
R_X86_64_TLSGD, R_X86_64_GOTTPOFF = 19, 22
PT_TLS = 7


# {(base file, function address): the vtable address points the function
# stores (tools/vtable_names.py Walker.vptr_stores)}, for _verify_derived
_VPTR_STORES: dict[tuple[str, int], frozenset[int]] = {}

# {(base file, object, its mtime and size, row): "" or the refusal}, for _prove_merge
_MERGE_PROOFS: dict[tuple, object] = {}   # merge refusals and source vtable slots, by object state


# --- the gate's cache ----------------------------------------------------------
#
# tools/check_elf.py --gate (and --progress) turn it on, under
# build/<slug>/gate-cache/; `--full` and every other tool leave it off. It holds
# the answers of computations that are pure functions of what their key hashes,
# and nothing else: every key is the SHA-256 of the tools' digest (every file
# under tools/ but the fetched compilers and tools, the Python version and the
# versions of capstone and pyelftools), the kind of answer, and the inputs
# themselves (file contents, never a path's size or time). A key is the repr
# of a tuple of plain values (str, int, bytes, None, tuples), which is one
# text per value, so two different inputs never share a key. The cache is advisory: deleting it changes nothing
# but time. Entries no run used are dropped when the gate writes it back.

import hashlib  # noqa: E402
import os  # noqa: E402
import pickle  # noqa: E402

_GC: dict = {"dir": None, "tables": {}, "used": {}, "dirty": set(), "files_used": {},
             "hits": {}, "misses": {}}
# kinds whose answers are large (an object file's every function): one file each
_GC_FILE_KINDS = ("objfuncs", "objdata", "objview")


def gate_cache_enable(path: Path | None) -> None:
    """Turn the cache on under `path` (None: off)."""
    _GC.update({"dir": path, "tables": {}, "used": {}, "dirty": set(), "files_used": {},
                "hits": {}, "misses": {}})


def gate_cache_on() -> bool:
    return _GC["dir"] is not None


_TOOLS_DIGEST: list[str] = []


def tools_digest() -> str:
    """SHA-256 over every file under tools/ (path and bytes; not the
    compilers under tools/cc, the fetched tools/ext and tools/ghidra, or
    __pycache__), the Python version and the capstone and pyelftools
    versions: a change to any tool invalidates every entry."""
    if not _TOOLS_DIGEST:
        import capstone
        import elftools
        root = Path(__file__).resolve().parent
        h = hashlib.sha256()
        h.update(f"{sys.version}\0capstone {capstone.__version__}\0pyelftools {elftools.__version__}\0".encode())
        for d, dirs, files in os.walk(root):
            rel = Path(d).relative_to(root)
            dirs[:] = sorted(x for x in dirs if not (rel == Path(".") and x in ("cc", "ext", "ghidra"))
                             and x != "__pycache__")
            for f in sorted(files):
                p = Path(d) / f
                h.update(f"{(rel / f).as_posix()}\0{p.stat().st_size}\0".encode())
                h.update(p.read_bytes())
        _TOOLS_DIGEST.append(h.hexdigest())
    return _TOOLS_DIGEST[0]


def content_digest(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


_FILE_DIGESTS: dict[tuple, str] = {}


def file_digest(path: Path) -> str:
    """SHA-256 of the file's bytes ("" when it does not exist); read once per
    process and file state."""
    try:
        st = path.stat()
    except FileNotFoundError:
        return ""
    k = (str(path), st.st_mtime_ns, st.st_size, st.st_ino)
    if k not in _FILE_DIGESTS:
        _FILE_DIGESTS[k] = content_digest(path.read_bytes())
    return _FILE_DIGESTS[k]


def gate_cache_key(kind: str, payload) -> str:
    """The key of an answer: the SHA-256 of the repr of (the tools' digest,
    the kind, the inputs), the inputs plain values (str, int, bytes, None and
    tuples of them), whose repr is one text per value and differs between
    any two values."""
    return hashlib.sha256(repr((tools_digest(), kind, payload)).encode()).hexdigest()


_MISS = object()


def _gc_table(kind: str) -> dict:
    t = _GC["tables"].get(kind)
    if t is None:
        t = {}
        try:
            with open(_GC["dir"] / f"{kind}.pickle", "rb") as f:
                t = pickle.load(f)
            if not isinstance(t, dict):
                t = {}
        except Exception:  # noqa: BLE001  (missing or unreadable: an empty table)
            t = {}
        _GC["tables"][kind] = t
        _GC["used"][kind] = {}
    return t


def gate_cache_get(kind: str, key: str):
    """The answer stored under `key`, or base_elf._MISS."""
    if _GC["dir"] is None:
        return _MISS
    if kind in _GC_FILE_KINDS:
        p = _GC["dir"] / kind / f"{key}.pickle"
        try:
            with open(p, "rb") as f:
                v = pickle.load(f)
        except Exception:  # noqa: BLE001
            _GC["misses"][kind] = _GC["misses"].get(kind, 0) + 1
            return _MISS
        _GC["files_used"].setdefault(kind, set()).add(p.name)
        _GC["hits"][kind] = _GC["hits"].get(kind, 0) + 1
        return v
    t = _gc_table(kind)
    if key in t:
        _GC["used"][kind][key] = t[key]
        _GC["hits"][kind] = _GC["hits"].get(kind, 0) + 1
        return t[key]
    _GC["misses"][kind] = _GC["misses"].get(kind, 0) + 1
    return _MISS


def _atomic_write(p: Path, blob: bytes) -> None:
    p.parent.mkdir(parents=True, exist_ok=True)
    tmp = p.with_name(f".{p.name}.{os.getpid()}.tmp")
    tmp.write_bytes(blob)
    os.replace(tmp, p)


def gate_cache_put(kind: str, key: str, value) -> None:
    if _GC["dir"] is None:
        return
    if kind in _GC_FILE_KINDS:
        p = _GC["dir"] / kind / f"{key}.pickle"
        try:
            _atomic_write(p, pickle.dumps(value, protocol=4))
            _GC["files_used"].setdefault(kind, set()).add(p.name)
        except OSError:
            pass
        return
    _gc_table(kind)
    _GC["used"][kind][key] = value
    _GC["dirty"].add(kind)


def gate_cache_flush(prune: bool) -> str:
    """Write the tables back. With `prune` (a whole gate ran), keep only the
    entries this run used, and remove the per-object files it did not use.
    Returns one summary line."""
    if _GC["dir"] is None:
        return "gate cache: off"
    for kind, used in _GC["used"].items():
        if kind in _GC["dirty"] or (prune and len(used) != len(_GC["tables"].get(kind, {}))):
            keep = used if prune else {**_GC["tables"].get(kind, {}), **used}
            try:
                _atomic_write(_GC["dir"] / f"{kind}.pickle", pickle.dumps(keep, protocol=4))
            except OSError:
                pass
    if prune:
        for kind in _GC_FILE_KINDS:
            d = _GC["dir"] / kind
            if d.is_dir():
                keep = _GC["files_used"].get(kind, set())
                for p in d.iterdir():
                    if p.name not in keep:
                        try:
                            p.unlink()
                        except OSError:
                            pass
    kinds = sorted(set(_GC["hits"]) | set(_GC["misses"]))
    return "gate cache: " + (", ".join(f"{k} {_GC['hits'].get(k, 0)} reused / {_GC['misses'].get(k, 0)} computed"
                                       for k in kinds) or "empty")


def base_digest(base: "BaseElf") -> str:
    """SHA-256 of the base executable's bytes as this BaseElf read them."""
    if getattr(base, "_digest", None) is None:
        base._digest = content_digest(base.data)
    return base._digest


class BaseElf:
    def __init__(self, repo_root: Path, version: str | None = None):
        self.root = repo_root
        self.version = version or detect_version(repo_root)
        self.path = baseelf_path(repo_root, self.version)
        self.data = self.path.read_bytes()
        self.phdrs = read_phdrs(self.data)
        self.text = next(p for p in self.phdrs if p["type"] == PT_LOAD and p["flags"] & 1)
        self.functions: list[tuple[int, int, str]] = []
        self.func_by_name: dict[str, tuple[int, int]] = {}
        for line in config_path(repo_root, self.version, "functions", "txt").read_text().splitlines():
            s = line.split("#", 1)[0].split()
            if len(s) >= 3:
                a, sz, n = int(s[0], 16), int(s[1], 16), s[2]
                self.functions.append((a, sz, n))
                self.func_by_name[n] = (a, sz)
        # vtables the executable names (config/vtables.<slug>.txt, generated,
        # D12) and vtables named by ruling (config/vtables.derived.<slug>.txt,
        # D14): symbol -> address of the _ZTV object. A derived row is
        # verified against the constructor it cites the first time the gate
        # resolves it (`_verify_derived`).
        #
        # One class per address, with one exception: a derived row may carry
        # `merges <symbol>` after its constructor, naming the row that already
        # holds its address (a generated row, or a derived row without
        # `merges`). Two classes whose vtables are identical constants of
        # local linkage are one object after the link stage (ConstantMerge in
        # 3.7.1's populateLTOPassManager, lib/Transforms/IPO/ConstantMerge.cpp:
        # the duplicate's uses are given the canonical global and the duplicate
        # is erased), so the base holds one vtable for both and the module
        # references whichever survived. The second class's row resolves only
        # when that is proven every time it is asked (`_prove_merge`): the
        # module defines one object for the two symbols, and that object's
        # words equal the base's vtable word for word.
        self.vtables: dict[str, int] = {}
        self._derived: dict[str, tuple[int, str, str]] = {}
        self._merged: dict[str, str] = {}       # a second class's row -> the row holding its address
        self._proving: set[str] = set()         # rows whose merge is being proven (no destructor folds through them)
        self.merge_object: Path | None = None   # the object a merge is proven in (None: the game module's)
        p = config_path(repo_root, self.version, "vtables", "txt")
        if p.exists():
            for line in p.read_text().splitlines():
                s = line.split("#", 1)[0].split()
                if len(s) >= 2 and s[0].startswith("_ZTV"):
                    self.vtables[s[0]] = int(s[1], 16)
        self._dyn = None
        self._plt = None
        self._got = None
        self._relative_got = None
        self._tls_got = None
        self._dso = None
        self._fold_starts = None
        self._import_names = None
        p = config_path(repo_root, self.version, "vtables.derived", "txt")
        if p.exists():
            self._load_derived(p, p.read_text().splitlines())

    def _load_derived(self, p: Path, lines: list[str]) -> None:
        """The rows of config/vtables.derived.<slug>.txt (`lines` of the file
        `p`), with the one-class-per-address rule and its `merges` exception
        (above). Raises ValueError naming the row and the address's holder."""
        holder = {a: sym for sym, a in self.vtables.items()}
        holder.update({a: sym for sym, (a, _c, _f) in self._derived.items() if sym not in self._merged})
        rows = []
        for line in lines:
            s = line.split("#", 1)[0].split()
            if len(s) >= 6 and s[0].startswith("_ZTV") and s[3] == "derived" and s[4] == "ctor":
                merges = None
                if len(s) > 6:
                    if s[6] != "merges" or len(s) != 8:
                        raise ValueError(f"{p.name}: {s[0]}: after the constructor only `merges <vtable symbol>`")
                    merges = s[7]
                if s[0] in self.vtables or s[0] in self._derived:
                    raise ValueError(f"{p.name}: {s[0]} is named twice")
                self._derived[s[0]] = (int(s[1], 16), s[2], s[5])
                rows.append((s[0], int(s[1], 16), merges))
        for sym, a, merges in rows:              # the holders first: rows without `merges`
            if merges is None:
                if a in holder:
                    raise ValueError(f"{p.name}: {sym} 0x{a:x}: the address is {holder[a]}'s; a second class at one "
                                     f"vtable address needs `merges {holder[a]}` and its proof")
                holder[a] = sym
        for sym, a, merges in rows:
            if merges is not None:
                if holder.get(a) != merges:
                    raise ValueError(f"{p.name}: {sym} merges {merges}, which is not the row holding 0x{a:x} "
                                     f"({holder.get(a, 'no row holds it')})")
                self._merged[sym] = merges

    # --- bytes -------------------------------------------------------------
    PT_SCE_RELRO = 0x61000010

    def loaded_segments(self) -> list[dict]:
        """The file-backed segments the loader maps: the PT_LOADs and the
        PT_SCE_RELRO (which is not a PT_LOAD but is mapped like one)."""
        return [p for p in self.phdrs if p["type"] in (PT_LOAD, self.PT_SCE_RELRO)]

    def segment_of(self, va: int) -> dict | None:
        for p in self.loaded_segments():
            if p["vaddr"] <= va < p["vaddr"] + p["memsz"]:
                return p
        return None

    def off(self, va: int) -> int | None:
        p = self.segment_of(va)
        if p is None or va >= p["vaddr"] + p["filesz"]:
            return None
        return p["offset"] + (va - p["vaddr"])

    def read(self, va: int, size: int) -> bytes:
        o = self.off(va)
        if o is None:
            raise ValueError(f"0x{va:x} is not in a loaded segment")
        return self.data[o:o + size]

    def text_bytes(self) -> bytes:
        return self.data[self.text["offset"]:self.text["offset"] + self.text["filesz"]]

    # --- the dynamic tables --------------------------------------------------
    def _dynamic(self):
        if self._dyn is not None:
            return self._dyn
        dyn = next(p for p in self.phdrs if p["type"] == PT_DYNAMIC)
        dld = next(p for p in self.phdrs if p["type"] == PT_SCE_DYNLIBDATA)
        tags: dict[int, list[int]] = {}
        o = dyn["offset"]
        while True:
            t, v = struct.unpack_from("<qQ", self.data, o)
            o += 16
            if t == 0:
                break
            tags.setdefault(t, []).append(v)
        base = dld["offset"]
        strtab = base + tags[DT_SCE_STRTAB][0]
        symtab = base + tags[DT_SCE_SYMTAB][0]
        ent = tags.get(DT_SCE_SYMENT, [24])[0]
        syms = []
        for i in range(tags[DT_SCE_SYMTABSZ][0] // ent):
            st_name, st_info, _o, _sh, st_value, st_size = struct.unpack_from("<IBBHQQ", self.data, symtab + i * ent)
            name = ""
            if st_name:
                end = self.data.index(b"\0", strtab + st_name)
                name = self.data[strtab + st_name:end].decode()
            syms.append((name, st_value, st_size, st_info))
        rels = []
        for tag, sztag in ((DT_SCE_JMPREL, DT_SCE_PLTRELSZ), (DT_SCE_RELA, DT_SCE_RELASZ)):
            if tag in tags:
                off = base + tags[tag][0]
                for i in range(tags[sztag][0] // 24):
                    r_off, r_info, r_add = struct.unpack_from("<QQq", self.data, off + i * 24)
                    rels.append((r_off, r_info & 0xFFFFFFFF, r_info >> 32, r_add))
        self._dyn = (syms, rels)
        return self._dyn

    def import_names(self) -> dict[str, str]:
        """nid -> name, from config/imports.<slug>.txt (tools/nid_names.py)."""
        if self._import_names is None:
            self._import_names = {}
            p = config_path(self.root, self.version, "imports", "txt")
            if p.exists():
                for line in p.read_text().splitlines():
                    s = line.split("#", 1)[0].split()
                    if len(s) >= 5 and s[4] != "?":
                        self._import_names[s[0]] = s[4]
        return self._import_names

    def _import_slots(self, types) -> dict[int, str]:
        """GOT slot address -> symbol name (import name when known, else
        nid#lib#mod) for the dynamic relocations of the given types."""
        syms, rels = self._dynamic()
        names = self.import_names()
        out = {}
        for r_off, r_type, r_sym, _a in rels:
            if r_type in types and r_sym < len(syms):
                full = syms[r_sym][0]
                out[r_off] = names.get(full.split("#")[0], full)
        return out

    def got_slots(self) -> dict[str, int]:
        """symbol name -> the GOT slot a data reference to the import reads
        (`mov r64, [rip+sym@GOTPCREL]`): its GLOB_DAT slot, or its JUMP_SLOT
        when it has no GLOB_DAT. An import called through the PLT and also
        taken by address has both; the two must not overwrite each other
        (memcpy lost its PLT stub that way)."""
        if self._got is None:
            self._got = {}
            for slot, name in self._import_slots((R_X86_64_JUMP_SLOT,)).items():
                self._got[name] = slot
            for slot, name in self._import_slots((R_X86_64_GLOB_DAT,)).items():
                self._got[name] = slot
        return self._got

    def relative_got_slots(self) -> dict[str, int]:
        """`D_<hex>` -> the GOT slot the linker filled with that address: a
        RELATIVE relocation among the import slots, the slot of a GOT load
        of an object the executable defines that the linker could not relax
        to `lea` because the code folds it into an add (`mov esi, 0x1d0;
        add rsi, [rip+slot]` at 0x6fc9c reads the constant table 0x14b2060
        through 0x16d80d8; eleven such slots). A relaxable load of the same
        object is still relaxed (docs/DECISIONS.md D10)."""
        if self._relative_got is None:
            self._relative_got = {}
            imports = self.got_slots().values()
            if imports:
                lo, hi = min(imports) - 0x100, max(imports) + 0x100
                for r_off, r_type, _s, r_add in self._dynamic()[1]:
                    if r_type == R_X86_64_RELATIVE and lo <= r_off <= hi:
                        self._relative_got.setdefault(f"D_{r_add:x}", r_off)
        return self._relative_got

    def tls_got_slot(self, name: str) -> int | None:
        """The GOT slot holding the thread-pointer offset of the thread-local
        `name` (a `D_<hex>` label inside PT_TLS): the field the linker's
        GD-to-IE relaxation reads (docs/DECISIONS.md D23). The slot has no
        dynamic relocation; it holds the variable's offset in the TLS
        template minus the template's aligned size (x86-64 TLS variant II,
        the block sits below the thread pointer). Found by its value among
        the unrelocated slots of the GOT; None when no slot or more than one
        holds the value."""
        va = self.address_of(name)
        tls = next((p for p in self.phdrs if p["type"] == PT_TLS), None)
        if va is None or tls is None or not (tls["vaddr"] <= va < tls["vaddr"] + tls["memsz"]):
            return None
        align = tls["align"] or 1
        tpoff = (va - tls["vaddr"]) - ((tls["memsz"] + align - 1) // align * align)
        if self._tls_got is None:
            imports = self.got_slots().values()
            lo, hi = min(imports) - 0x100, max(imports)
            relocated = {r_off for r_off, _t, _s, _a in self._dynamic()[1]}
            found: dict[int, list[int]] = {}
            for slot in range(lo, hi + 8, 8):
                if slot in relocated or self.off(slot) is None:
                    continue
                v = struct.unpack("<q", self.read(slot, 8))[0]
                if -0x10000 < v < 0:
                    found.setdefault(v, []).append(slot)
            self._tls_got = found
        slots = self._tls_got.get(tpoff, [])
        return slots[0] if len(slots) == 1 else None

    def plt_stubs(self) -> dict[str, int]:
        """symbol name -> address of its PLT stub (`jmp qword ptr [rip+slot]`)
        in the text segment, found by scanning for the stub form against the
        JUMP_SLOT relocations."""
        if self._plt is None:
            slot_to_name = self._import_slots((R_X86_64_JUMP_SLOT,))
            self._plt = {}
            t = self.text_bytes()
            base_va = self.text["vaddr"]
            i = 0
            while True:
                i = t.find(b"\xff\x25", i)
                if i < 0:
                    break
                disp = struct.unpack_from("<i", t, i + 2)[0]
                target = base_va + i + 6 + disp
                if target in slot_to_name:
                    self._plt[slot_to_name[target]] = base_va + i
                i += 1
        return self._plt

    # --- symbol resolution ----------------------------------------------------
    @staticmethod
    def base_identifier(sym: str) -> str:
        """The row identifier inside an Itanium-mangled name: a free function
        (`_Z12FUN_00470da0P11Owner46b3f0i` -> `FUN_00470da0`) or a member
        whose last component is a FUN_ or D_ placeholder
        (`_ZNK19hkMemoryMeshTexture12FUN_000ad770Ev` -> `FUN_000ad770`); other
        names unchanged."""
        import re
        m = re.match(r"^_ZL?(\d+)", sym)   # _ZL: internal linkage (a `static` or namespace-scope const)
        if m:
            n = int(m.group(1))
            start = m.end()
            return sym[start:start + n]
        # a function-local static, `_ZZ<function>E<len><name>[_<n>]`: the
        # object is named D_<hex> like a file-local one (docs/DECISIONS.md
        # D17); its guard `_ZGVZ...` is not the object and is placed by
        # tools/layout_link.py beside it
        if sym.startswith("_ZZ"):
            m = re.search(r"E(\d+)(D_[0-9a-fA-F]+)(?:_\d+)?$", sym)
            if m and len(m.group(2)) == int(m.group(1)):
                return m.group(2)
        m = re.match(r"^_ZN[KVr]*", sym)
        if m:
            pos, last = m.end(), None
            while True:
                m2 = re.match(r"\d+", sym[pos:])
                if not m2:
                    break
                n = int(m2.group())
                start = pos + m2.end()
                last = sym[start:start + n]
                pos = start + n
            if last and (last.startswith("FUN_") or last.startswith("D_")):
                return last
        return sym

    @staticmethod
    def ctor_alias(sym: str) -> str | None:
        """The other spelling of a constructor or destructor the compiler
        emits at the same address: without virtual bases the complete object
        constructor C1 is an alias of the base object constructor C2, and D1
        of D2 (Itanium ABI 5.1.4.3; LLVM 3.3 `CodeGenModule::EmitCXXConstructor`
        emits C1 as an alias). The table holds one name per address, so a
        row named C1 answers for C2 and the reverse. D0 (deleting) is a
        separate function and has no alias."""
        import re
        m = re.search(r"(C|D)([12])(E|I)", sym)
        if not m or not sym.startswith("_ZN"):
            return None
        other = "2" if m.group(2) == "1" else "1"
        return sym[:m.start(2)] + other + sym[m.end(2):]

    def folded_destructor(self, sym: str, hint: int | None = None) -> int | None:
        """A destructor symbol no row names, resolved by its class's vtable
        (D15): the linker folded the identical destructor bodies of
        different classes into one function, which carries one name, and
        every other class's vtable still points at that body; or the
        destructor is not claimed yet and its row is still FUN_<addr>.
        The vtable is one the executable names or a ruled derived row.

        Slot 0 of the class's primary vtable is its complete destructor
        (D1, and D2 with it), slot 1 its deleting destructor (D0), when the
        slot holds the first address of a row of the function table,
        whatever the row's name: the callee of a claimed function need not
        be claimed for the call to be proven, as a call to FUN_<addr> is
        proven by FUN_<addr>'s row alone (D82).

        A class whose destructor is not its first virtual (round 373E: the
        fade rigs, findElement and slot1 before it) resolves by its
        destructor PAIR wherever it lies, given `hint`, the address the
        base's own instruction at the reference encodes
        (`destructor_pair`): the D1/D0 pair is adjacent in every Itanium
        vtable, so slot k is the complete destructor and k + 1 the deleting
        one exactly when the base's function at k + 1 calls the one at k
        (or the body k's five-byte jump enters: the game compiler's D1 of an
        inline destructor is `jmp D2`, D45). A D1 or D2 reference resolves to
        the hint when the hint is slot k's entry or that jump's target; a D0
        reference when the hint is slot k + 1's entry; and the vtable the
        object compared emits for the class (the game module's, or
        match_check's single-file module), when it emits one, must hold the
        class's D1 (or D2) and D0 at the same slots k and k + 1
        (source_destructor_slot): a source declaring the destructor at
        another slot is refused. No such pair, or a hint that is not its
        entry, gives slot 0's (or 1's) address as before, which the
        reference's field then refuses. The address is
        what the base says, read every run; the row gets the destructor's
        name when the destructor itself is claimed (D15), not here."""
        import re
        m = re.fullmatch(r"_ZN(.+)D([012])Ev", sym)
        if not m:
            return None
        enc, kind = m.group(1), m.group(2)
        slot = 1 if kind == "0" else 0
        for vt in ("_ZTV" + enc, "_ZTVN" + enc + "E"):
            if vt in self._proving:     # the vtable is what is being proven: its slot proves nothing
                continue
            addr = self.vtables.get(vt)
            if addr is None and vt in self._derived:
                try:
                    addr = self._verify_derived(vt)
                except ValueError:
                    addr = None
            if addr is None:
                continue
            try:
                target = int.from_bytes(self.read(addr + 0x10 + 8 * slot, 8), "little")
            except Exception:
                return None
            if self._fold_starts is None:
                self._fold_starts = {a: n for n, (a, _s) in self.func_by_name.items()}
            if hint is not None and hint != target:
                pair = self.destructor_pair(addr, hint, kind)
                if pair is not None and self.source_destructor_slot(vt, enc, pair) == pair:
                    return hint
            if target in self._fold_starts:
                return target
        return None

    def _jump_target(self, fn: int) -> int | None:
        """The target of the five-byte `jmp rel32` that is the whole body of
        the function-table row starting at `fn` (D45's complete destructor
        of an inline destructor, a jump to the base-object one), or None."""
        row = self._fold_starts.get(fn)
        if row is None:
            return None
        size = self.func_by_name[row][1]
        code = self.read(fn, min(size, 5))
        if len(code) < 5 or code[0] != 0xE9 or (size > 5 and any(self.read(fn + 5, size - 5).strip(b"\x90\xcc"))):
            return None
        return fn + 5 + int.from_bytes(code[1:5], "little", signed=True)

    def _calls(self, fn: int) -> set[int]:
        """Every target of a direct `call rel32` (or tail `jmp rel32`) in the
        function-table row starting at `fn`, by disassembly of the base."""
        from capstone import Cs, CS_ARCH_X86, CS_MODE_64
        row = self._fold_starts.get(fn)
        if row is None:
            return set()
        size = self.func_by_name[row][1]
        out = set()
        for ins in Cs(CS_ARCH_X86, CS_MODE_64).disasm(self.read(fn, size), fn):
            if ins.bytes[0] in (0xE8, 0xE9) and ins.size == 5:
                out.add(ins.address + 5 + int.from_bytes(ins.bytes[1:5], "little", signed=True))
        return out

    def source_vtable_slots(self, vt: str) -> tuple | None:
        """The slots of the vtable `vt` as the object compared defines it
        (merge_object, else the game module's): each slot's relocation
        symbol, or None for a slot without one; None when the object does not
        emit `vt` (undefined, or the module's zero stand-in for a vtable whose
        key function is not in the tree). Read once per object state."""
        import match_check as mc
        obj = self._merge_object()
        if not obj.exists():
            return None
        st = obj.stat()
        key = ("slots", str(obj), st.st_mtime_ns, st.st_size, vt)
        if key not in _MERGE_PROOFS:
            v = mc.object_view(obj)
            d = next(((s["st_shndx"], s["st_value"], s["st_size"]) for s in v.syms if s.name == vt
                      and s["st_shndx"] not in ("SHN_UNDEF", "SHN_ABS", "SHN_COMMON")), None)
            relocs = mc.object_data_relocs(obj, *d)[0] if d is not None and d[2] >= 0x10 and not d[2] % 8 else []
            # no relocation: not the class's vtable but the module's stand-in
            # for one the source does not emit (its key function is not in the
            # tree; game_module.standins), zero bytes in .bss
            at = {r.offset: r.symbol for r in relocs if r.width == 8 and r.addend == 0}
            _MERGE_PROOFS[key] = tuple(at.get(o) for o in range(0x10, d[2], 8)) if relocs else None
        return _MERGE_PROOFS[key]

    def source_destructor_slot(self, vt: str, enc: str, base_slot: int) -> int | None:
        """The slot k at which the source's vtable `vt` (source_vtable_slots)
        holds the class's complete destructor (D1, or D2 where the link
        stage folded them) followed at k + 1 by its deleting destructor (D0),
        or None when no slot, or more than one, holds the pair. A destructor
        resolved by its vtable pair (folded_destructor) must sit at the same
        slot in the source as in the base when the source emits the vtable:
        a source declaring the destructor elsewhere is refused. When the
        source does not emit it (its key function is not in the tree) the
        source has no slot to compare and `base_slot`, the base's proven
        pair, is the answer: the reference is proven by the base's pair and
        its own field, as a slot-0 destructor is (D82)."""
        slots = self.source_vtable_slots(vt)
        if slots is None:
            return base_slot
        found = [k for k in range(len(slots) - 1)
                 if slots[k] in ("_ZN" + enc + "D1Ev", "_ZN" + enc + "D2Ev")
                 and slots[k + 1] == "_ZN" + enc + "D0Ev"]
        return found[0] if len(found) == 1 else None

    def destructor_pair(self, vtable: int, hint: int, kind: str) -> int | None:
        """The slot k of the class's destructor pair in the base vtable whose
        address point is `vtable`, proven for a reference of `kind` ("0",
        "1" or "2": D0, D1, D2) whose base field encodes `hint`, or None.
        Proven: slots k and k + 1 each hold the first address of a row of
        the function table; the function at k + 1 (the deleting destructor)
        calls the function at k or the body that one's five-byte jump enters
        (the complete destructor, D45's census: 507 deleting destructors call
        slot 0's body, 248 slot 0's jump target); and the hint is slot
        k + 1's entry for a D0, slot k's entry or its jump target for a D1 or
        D2. Exactly one k may be proven; two refuse."""
        found = []
        k = 0
        while True:
            try:
                d1 = int.from_bytes(self.read(vtable + 0x10 + 8 * k, 8), "little")
                d0 = int.from_bytes(self.read(vtable + 0x10 + 8 * (k + 1), 8), "little")
            except Exception:
                break
            if d1 not in self._fold_starts:
                break                   # the end of the vtable's functions
            if d0 in self._fold_starts:
                body = self._jump_target(d1)
                calls = self._calls(d0)
                if d1 in calls or (body is not None and body in calls):
                    ok = (hint == d0) if kind == "0" else (hint == d1 or (body is not None and hint == body))
                    if ok:
                        found.append(k)
            k += 1
        return found[0] if len(found) == 1 else None

    def address_of(self, name: str, hint: int | None = None) -> int | None:
        """Where the base put `name`: a function of the table (by its mangled
        name or its bare identifier), a `D_<hex>` data label, a vtable the
        executable names (config/vtables.<slug>.txt, tools/vtable_names.py),
        or an import (its PLT stub). A name beginning `!` is a reference the
        gate has already refused (tools/match_check.py with_header_statics: a
        header static whose unit has no row or whose copy is not proven); it
        raises ValueError with the reason. `hint`, where the caller has it,
        is the address the base's own field at the reference encodes; only a
        destructor resolved by its class's vtable pair reads it
        (folded_destructor), and the field is checked against the answer
        all the same."""
        if name.startswith("!"):
            raise ValueError(name[1:])
        if name in self.func_by_name:
            return self.func_by_name[name][0]
        alias = self.ctor_alias(name)
        if alias in self.func_by_name:
            return self.func_by_name[alias][0]
        folded = self.folded_destructor(name, hint)
        if folded is not None:
            return folded
        if name.startswith("_ZTV"):
            if name in self.vtables:
                return self.vtables[name]
            if name in self._derived:
                return self._verify_derived(name)
            if self.instantiation_template(name) is not None:
                return self.instantiation_vtable(name)
            return None
        ident = self.base_identifier(name)
        if ident in self.func_by_name:
            return self.func_by_name[ident][0]
        name = ident
        if name.startswith("D_"):
            try:
                return int(name[2:], 16)
            except ValueError:
                return None
        if name == "__dso_handle":
            return self.dso_handle()
        return self.plt_stubs().get(name)

    def dso_handle(self) -> int | None:
        """The address of `__dso_handle`, the CRT's hidden object every
        `__cxa_atexit` registration passes as its third argument (a static
        object's destructor registered by its constructor). Read from the
        base itself: the `lea rdx, [rip+X]` within 24 bytes before each
        call or tail jump to `__cxa_atexit`'s PLT stub; the one value they
        all agree on (10,632 of 13,043 sites name it directly on 2026-10-27,
        the rest pass it through another register; no second value)."""
        if self._dso is not None:
            return self._dso or None
        plt = self.plt_stubs().get("__cxa_atexit")
        text = self.text_bytes()
        text_va = self.text["vaddr"]
        found: dict[int, int] = {}
        if plt is not None:
            for op in (0xE8, 0xE9):                      # call rel32, jmp rel32
                i = text.find(bytes([op]))
                while i != -1:
                    va = text_va + i
                    if va + 5 <= text_va + len(text) and \
                            va + 5 + struct.unpack_from("<i", text, i + 1)[0] == plt:
                        lo = max(0, i - 24)
                        j = text.rfind(b"\x48\x8d\x15", lo, i)   # lea rdx, [rip+rel32]
                        if j != -1 and j + 7 <= i:
                            tgt = text_va + j + 7 + struct.unpack_from("<i", text, j + 3)[0]
                            found[tgt] = found.get(tgt, 0) + 1
                    i = text.find(bytes([op]), i + 1)
        self._dso = max(found, key=found.get) if len(found) == 1 else 0
        return self._dso or None

    def vptr_stores(self, fn: int) -> frozenset[int]:
        """tools/vtable_names.py Walker.vptr_stores(fn): a function of the
        base's bytes and of the function's address and size in the table
        alone. The gate asks it of two BaseElf objects (check_elf.check_all's
        and layout_link.build_image's): answered once per process, and kept in
        the gate's cache under the base's digest, the address and the size."""
        key = (str(self.path), fn)
        stored = _VPTR_STORES.get(key)
        if stored is not None:
            return stored
        ck = None
        if gate_cache_on():
            sizes = getattr(self, "_size_at", None)
            if sizes is None:
                sizes = self._size_at = {a: sz for a, sz, _n in self.functions}
            ck = gate_cache_key("vptr", (base_digest(self), fn, sizes.get(fn)))
            v = gate_cache_get("vptr", ck)
            if v is not _MISS:
                stored = v
        if stored is None:
            from vtable_names import Walker
            stored = frozenset(Walker(self).vptr_stores(fn))
            if ck is not None:
                gate_cache_put("vptr", ck, stored)
        _VPTR_STORES[key] = stored
        return stored

    def _verify_derived(self, sym: str) -> int:
        """A derived vtable row holds when its symbol is the mangling of its
        class name and the constructor it cites stores the vtable's address
        point into its object (tools/vtable_names.py, D14). The class may be
        an instantiation of a class template of the tree, written as C++
        (`Task0052c710<TargetA0052c710>`, tools/vtable_names.py
        mangle_instantiation): its symbol is the mangling of that name, the
        compiler's own reference to the instantiation's vtable, and it is
        proven by the constructor's store as every other row is."""
        addr, cls, ctor = self._derived[sym]
        from vtable_names import mangle_vtable
        expected = mangle_vtable(cls, templates=True)
        if expected is None:
            raise ValueError(f"vtables.derived: {sym}: the class name {cls} cannot be mangled")
        # a class of an anonymous namespace: its vtable is the file's own
        # (the base stores the address point with one direct lea)
        anonymous = "_ZTVN12_GLOBAL__N_1" + expected[len("_ZTV"):] + "E"
        if sym not in (expected, anonymous):
            raise ValueError(f"vtables.derived: {sym} is not the vtable symbol of {cls}")
        if ctor in self.func_by_name:
            fn = self.func_by_name[ctor][0]
        else:   # a row cites the constructor by address (FUN_<hex>) and survives its row's renaming
            try:
                fn = int(ctor[4:], 16) if ctor.startswith("FUN_") else None
            except ValueError:
                fn = None
            if fn is None or fn not in {a for a, _s in self.func_by_name.values()}:
                raise ValueError(f"vtables.derived: {sym}: {ctor} is not a function of the table")
        stored = self.vptr_stores(fn)
        if addr + 0x10 not in stored:
            raise ValueError(f"vtables.derived: {sym}: {ctor} stores "
                             f"{', '.join(hex(v) for v in sorted(stored)) or 'no vtable'}, not 0x{addr + 0x10:x}")
        if sym in self._merged:     # proven in the object every time it is asked, never kept in self.vtables
            self._prove_merge(sym)
            return addr
        self.vtables[sym] = addr
        return addr

    def merged_row_address(self, sym: str) -> int | None:
        """The address a `merges` row names, unproven: the game module's
        stand-ins are decided by it before the module exists
        (tools/game_module.py); every reference is proven (_prove_merge)."""
        return self._derived[sym][0] if sym in self._merged else None

    def _merge_object(self) -> Path:
        if self.merge_object is not None:
            return Path(self.merge_object)
        from game_module import module_object
        return module_object(self.version)

    def _prove_merge(self, sym: str) -> None:
        """A second class's row at an address another row holds (`merges`):
        it holds when the object the module was compiled to (merge_object,
        else the game module's) defines ONE object for the two vtable
        symbols, and that object, word for word, is the base's vtable at the
        address: the offset to top and the type info as bytes, each slot as
        the address its relocation resolves to (address_of; a destructor of
        the row's own class is not folded through the vtable being proven).
        Two objects are refused with the first word in which they differ; a
        word that differs from the base's is refused with the word named.
        Raises ValueError with the reason; answered once per object state."""
        obj = self._merge_object()
        first = self._merged[sym]
        if not obj.exists():
            raise ValueError(f"vtables.derived: {sym} merges {first}: no object to prove it in ({obj} is not built)")
        st = obj.stat()
        key = (str(self.path), str(obj), st.st_mtime_ns, st.st_size, sym)
        if key not in _MERGE_PROOFS:
            _MERGE_PROOFS[key] = self._merge_refusal(sym, first, obj)
        if _MERGE_PROOFS[key]:
            raise ValueError(_MERGE_PROOFS[key])

    def _merge_refusal(self, sym: str, first: str, obj: Path) -> str:
        """_prove_merge's answer: "" when the merge holds, else the reason."""
        import match_check as mc
        addr = self._derived[sym][0]
        head = f"vtables.derived: {sym} merges {first} at 0x{addr:x}"
        v = mc.object_view(obj)

        def where(name):
            for s in v.syms:
                if s.name == name and s["st_shndx"] not in ("SHN_UNDEF", "SHN_ABS", "SHN_COMMON"):
                    return s["st_shndx"], s["st_value"], s["st_size"]
            return None

        def words(d):
            shndx, value, size = d
            if size % 8:
                return None, f"its size {size} is not a whole number of slots"
            data = v.sections[shndx][0][value:value + size].ljust(size, b"\0")
            relocs, _n, _s = mc.object_data_relocs(obj, shndx, value, size)
            at = {}
            for r in relocs:
                if r.offset % 8 or r.width != 8:
                    return None, f"a relocation of {r.width} bytes at +0x{r.offset:x} is not a slot"
                at[r.offset] = (r.symbol, r.addend)
            return [at.get(o, (None, int.from_bytes(data[o:o + 8], "little"))) for o in range(0, size, 8)], ""

        def label(i):
            return {0: "the offset to top", 1: "the type info"}.get(i, f"slot {i - 2}")

        def show(w):
            if w is None:
                return "nothing"
            if w[0] is None:
                return f"0x{w[1]:x}"
            return w[0] + (f"{w[1]:+#x}" if w[1] else "")

        mine, held = where(sym), where(first)
        if mine is None and held is None:
            return f"{head}: {obj.name} defines neither: no merged constant to prove"
        if mine is not None and held is not None and mine != held:
            a, why = words(held)
            b, why2 = words(mine)
            if a is None or b is None:
                return f"{head}: they are two objects in {obj.name}, not one: {why or why2}"
            for i in range(max(len(a), len(b))):
                x = a[i] if i < len(a) else None
                y = b[i] if i < len(b) else None
                if x != y:
                    return (f"{head}: they are two objects in {obj.name}, not one merged constant: {label(i)} "
                            f"differs ({first} holds {show(x)}, {sym} holds {show(y)})")
            return (f"{head}: they are two objects in {obj.name} with the same words, not one merged constant "
                    f"(the link merges only constants of local linkage)")
        name = sym if mine is not None else first
        ws, why = words(mine if mine is not None else held)
        if ws is None:
            return f"{head}: the module's {name}: {why}"
        self._proving.add(sym)
        try:
            for i, w in enumerate(ws):
                want = int.from_bytes(self.read(addr + 8 * i, 8), "little")
                if w[0] is None:
                    got = w[1]
                else:
                    try:
                        s = self.address_of(w[0])
                    except ValueError as e:
                        return f"{head}: {label(i)} of the module's {name} holds {show(w)}: {e}"
                    if s is None:
                        return (f"{head}: {label(i)} of the module's {name} holds {show(w)}, "
                                "which the base does not place")
                    got = s + w[1]
                if got != want:
                    return (f"{head}: {label(i)} of the module's {name} holds {show(w)} (0x{got:x}); "
                            f"the base's vtable holds 0x{want:x} there")
        finally:
            self._proving.discard(sym)
        return ""

    # --- vtables of library instantiations (round 148A) ----------------------
    # A class template of our own library headers whose instantiations the
    # compiler emits with their vtables: the mangled template prefix and the
    # slot of each virtual member, by its mangled name (src/include/functional:
    # std::function's implementation, one instantiation per callable type,
    # internal to its unit when the callable is a lambda of an ordinary
    # function). Such a vtable has no hand-made row (D14): it is the base
    # vtable that holds the claimed rows of the instantiation in their slots,
    # and its slot-0 row must be claimed and store that vtable's address point.
    INSTANTIATION_SLOTS = {
        "St14_Function_implI": {"_Copy": 0, "_Move": 1, "_Call": 2, "_Target_type": 3, "_Delete_this": 4,
                                "D1": 5, "D2": 5, "D0": 6, "_Get": 7},
    }

    @classmethod
    def instantiation_template(cls, vtable: str) -> str | None:
        """The template prefix of INSTANTIATION_SLOTS a `_ZTV` symbol
        instantiates, or None."""
        enc = vtable[len("_ZTV"):] if vtable.startswith("_ZTV") else ""
        return next((t for t in cls.INSTANTIATION_SLOTS if enc.startswith(t)), None)

    @staticmethod
    def mangled_close(s: str, i: int, depth: int = 1) -> int | None:
        """The index just past the `E` that closes `depth` open levels of an
        Itanium mangled name read from `s[i]` (the end of a template argument
        list or a local name `Z<encoding>E`), or None when it does not close.
        Counts the productions that open a level ending in `E` (template
        arguments, a local name, a pack, a function type, a nested name, an
        expression, a closure type), skipping what may hold an `E` or digits
        of its own (a source name, a substitution or template parameter, an
        array bound, a literal)."""
        try:
            while depth:
                c = s[i]
                if c.isdigit():                        # <length><identifier>
                    j = i
                    while s[j].isdigit():
                        j += 1
                    i = j + int(s[i:j])
                    continue
                if c in "ST":                          # S<seq>_, T<seq>_, or St, Sa...
                    j = i + 1
                    while s[j].isdigit() or s[j].isupper():
                        j += 1
                    if s[j] == "_":
                        i = j + 1
                    else:
                        i += 2 if c == "S" else 1
                    continue
                if c == "A":                           # A<bound>_
                    i = s.index("_", i) + 1
                    continue
                if c == "L":                           # L<type><value>E or L_Z<encoding>E
                    if s.startswith("_Z", i + 1):
                        depth += 1
                        i += 3
                    else:
                        i = s.index("E", i) + 1
                    continue
                if c == "U" and s[i + 1] == "l":    # a closure type: Ul<parameters>E[<n>]_
                    depth += 1
                    i += 2
                    continue
                if c in "IZJFNX":
                    depth += 1
                elif c == "E":
                    depth -= 1
                i += 1
        except (IndexError, ValueError):
            return None
        return i if i <= len(s) else None

    @classmethod
    def instantiation_member(cls, sym: str) -> tuple[str, int] | None:
        """(`_ZTV` symbol, slot) of a member symbol of an instantiation of
        INSTANTIATION_SLOTS: `_ZN[K]<class><member>E<params>`, the class
        encoding the same string the vtable symbol carries after `_ZTV`."""
        import re
        m = re.match(r"^_ZNK?", sym)
        if not m:
            return None
        rest = sym[m.end():]
        tmpl = next((t for t in cls.INSTANTIATION_SLOTS if rest.startswith(t)), None)
        if tmpl is None:
            return None
        i = cls.mangled_close(rest, len(tmpl))
        if i is None:
            return None
        enc, member = rest[:i], rest[i:]
        m2 = re.match(r"^(\d+)", member)
        name = member[m2.end():m2.end() + int(m2.group(1))] if m2 else member[:2]
        slot = cls.INSTANTIATION_SLOTS[tmpl].get(name)
        return None if slot is None else ("_ZTV" + enc, slot)

    def _matched_symbols(self) -> dict[str, int]:
        """symbol -> address of every row of config/matched.<slug>.txt."""
        if getattr(self, "_matched", None) is None:
            self._matched = {}
            p = config_path(self.root, self.version, "matched", "txt")
            if p.exists():
                for line in p.read_text().splitlines():
                    s = line.split("#", 1)[0].split()
                    if len(s) >= 2 and s[0] in self.func_by_name:
                        self._matched[s[2] if len(s) > 2 else s[0]] = self.func_by_name[s[0]][0]
        return self._matched

    def instantiation_rows(self) -> dict[str, dict[int, tuple[str, int]]]:
        """`_ZTV` symbol -> {slot: (row symbol, address)} over the claimed rows."""
        out: dict[str, dict[int, tuple[str, int]]] = {}
        for sym, addr in self._matched_symbols().items():
            m = self.instantiation_member(sym)
            if m is not None:
                out.setdefault(m[0], {})[m[1]] = (sym, addr)
        return out

    def _slot_index(self) -> dict[int, list[int]]:
        """text address -> every 8-aligned read-only-data address holding it."""
        if getattr(self, "_slots", None) is None:
            self._slots = {}
            relro = next(p for p in self.loaded_segments() if p["type"] == self.PT_SCE_RELRO)
            seg = self.data[relro["offset"]:relro["offset"] + relro["filesz"]]
            lo, hi = self.text["vaddr"], self.text["vaddr"] + self.text["memsz"]
            for i, (v,) in enumerate(struct.iter_unpack("<Q", seg[:len(seg) // 8 * 8])):
                if lo <= v < hi:
                    self._slots.setdefault(v, []).append(relro["vaddr"] + 8 * i)
        return self._slots

    def instantiation_vtable(self, sym: str, require_slot0: bool = True) -> int:
        """The base vtable of an instantiation's `_ZTV` symbol: the one vtable
        whose slots hold every claimed row of the instantiation at its slot,
        with slot 0's row claimed and storing the vtable's address point
        (tools/vtable_names.py --check runs this over every instantiation).
        Raises ValueError saying which condition fails. `require_slot0`
        false: the slots' agreement alone (tools/vtable_names.py --check of
        an instantiation whose slot 0 is not claimed yet)."""
        rows = self.instantiation_rows().get(sym, {})
        if not rows:
            raise ValueError(f"{sym}: an instantiation's vtable, and no claimed row is a member of it")
        index = self._slot_index()
        cands = None
        for slot, (rsym, addr) in sorted(rows.items()):
            here = {p - 0x10 - 8 * slot for p in index.get(addr, [])}
            here = {x for x in here if self.read(x, 0x10) == bytes(0x10)}
            cands = here if cands is None else cands & here
        if not cands:
            raise ValueError(f"{sym}: no base vtable holds its claimed rows in their slots ("
                             + ", ".join(f"slot {k} 0x{a:x}" for k, (_s, a) in sorted(rows.items())) + ")")
        if len(cands) > 1:
            raise ValueError(f"{sym}: {len(cands)} base vtables hold its claimed rows in their slots ("
                             + ", ".join(hex(x) for x in sorted(cands)) + "); slot 0's row decides")
        addr = cands.pop()
        if 0 not in rows and not require_slot0:
            return addr
        if 0 not in rows:
            raise ValueError(f"{sym}: the vtable at 0x{addr:x} holds its claimed rows, but its slot-0 row "
                             "is not claimed (slot 0 stores the vtable and is its evidence)")
        stored = self.vptr_stores(rows[0][1])
        if addr + 0x10 not in stored:
            raise ValueError(f"{sym}: its slot-0 row {rows[0][0]} stores "
                             f"{', '.join(hex(v) for v in sorted(stored)) or 'no vtable'}, not 0x{addr + 0x10:x}")
        self.vtables[sym] = addr
        return addr

    def find_bytes(self, blob: bytes) -> list[int]:
        """Every address at which `blob` occurs in a loaded segment (for a
        string literal or a constant the object defines locally)."""
        hits = []
        for p in self.loaded_segments():
            seg = self.data[p["offset"]:p["offset"] + p["filesz"]]
            i = seg.find(blob)
            while i >= 0:
                hits.append(p["vaddr"] + i)
                i = seg.find(blob, i + 1)
        return hits
