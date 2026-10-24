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
        self._dyn = None
        self._plt = None
        self._got = None
        self._import_names = None

    # --- bytes -------------------------------------------------------------
    def off(self, va: int) -> int | None:
        return vaddr_to_off(self.phdrs, va)

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

    def got_slots(self) -> dict[str, int]:
        """symbol name (import name when known, else nid#lib#mod) -> GOT slot
        address, for every JUMP_SLOT and GLOB_DAT relocation."""
        if self._got is None:
            syms, rels = self._dynamic()
            names = self.import_names()
            self._got = {}
            for r_off, r_type, r_sym, _a in rels:
                if r_type in (R_X86_64_JUMP_SLOT, R_X86_64_GLOB_DAT) and r_sym < len(syms):
                    full = syms[r_sym][0]
                    nid = full.split("#")[0]
                    self._got[names.get(nid, full)] = r_off
        return self._got

    def plt_stubs(self) -> dict[str, int]:
        """symbol name -> address of its PLT stub (`jmp qword ptr [rip+slot]`)
        in the text segment, found by scanning for the stub form."""
        if self._plt is None:
            slot_to_name = {v: k for k, v in self.got_slots().items()}
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
        """The identifier inside an Itanium-mangled free function name
        (`_Z12FUN_00470da0P11Owner46b3f0i` -> `FUN_00470da0`); other names
        unchanged."""
        import re
        m = re.match(r"^_Z(\d+)", sym)
        if m:
            n = int(m.group(1))
            start = m.end()
            return sym[start:start + n]
        return sym

    def address_of(self, name: str) -> int | None:
        """Where the base put `name`: a function of the table (by its mangled
        name or its bare identifier), a `D_<hex>` data label, or an import
        (its PLT stub)."""
        if name in self.func_by_name:
            return self.func_by_name[name][0]
        ident = self.base_identifier(name)
        if ident in self.func_by_name:
            return self.func_by_name[ident][0]
        name = ident
        if name.startswith("D_"):
            try:
                return int(name[2:], 16)
            except ValueError:
                return None
        return self.plt_stubs().get(name)

    def find_bytes(self, blob: bytes) -> list[int]:
        """Every address at which `blob` occurs in a loaded segment (for a
        string literal or a constant the object defines locally)."""
        hits = []
        for p in self.phdrs:
            if p["type"] != PT_LOAD:
                continue
            seg = self.data[p["offset"]:p["offset"] + p["filesz"]]
            i = seg.find(blob)
            while i >= 0:
                hits.append(p["vaddr"] + i)
                i = seg.find(blob, i + 1)
        return hits
