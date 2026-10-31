#!/usr/bin/env python3
"""
layout_link.py: rebuild the executable's loaded segments and compare them whole.

The ico project's gate links every object at the original addresses, fills
the functions still unwritten with stubs taken from the user's own ELF, and
compares the result with the base byte for byte. This is that gate for a
target whose linker is not public: instead of a linker, the image is laid
out here.

    1. Start from the base's loaded segments (the user's own eboot.elf): the
       text segment (code, read-only data, the PLT, the unwind tables), the
       RELRO (vtables, the GOT) and the data segment, every byte not yet
       claimed exactly as shipped.
    2. For every row of config/matched.<slug>.txt, take the function's bytes
       from the compiled object and RESOLVE its relocations the way the
       original link did: a call to FUN_x becomes the displacement to FUN_x's
       address in the table; a reference to D_<hex> to that address; a call
       to an import to its PLT stub; a GOT load to the import's GOT slot; a
       string literal the object defines to the one place the base holds
       those bytes. Write the result at the function's address.
    2b. For every row of config/data.<slug>.txt (`D_<hex> <tu> [<symbol>]`),
       take the object the TU defines under that name, resolve its pointer
       fields (an R_X86_64_64 to a function or a D_<hex> becomes the address,
       which is what the base's file holds at a slot its loader relocates;
       the base must carry a RELATIVE relocation at that slot) and write it
       at the address. An object in the NOBITS tail of the data segment
       (.bss) has no bytes to compare; it counts as owned.
    3. Compare every segment with the base, whole. Any differing byte names
       the function or data object it falls in (or the gap, which would mean
       a claimed object overran its size).

A relocation the resolver cannot place (a data symbol without a D_<hex>
name, a literal the base holds in two places) fails the function with a
message, never a guess. The PLT, the GOT and the dynamic tables are Sony's
linker's output: they are compared like everything else and come from the
base until a source for them exists.

    layout_link.py              build/<slug>/<segment>.bin and build/<slug>/layout.json;
                                prints the differing functions and objects; exit 1 if any
    layout_link.py --quiet
"""
from __future__ import annotations

import argparse
import json
import struct
import subprocess
import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(Path(__file__).resolve().parent))
from tlg_version import build_dir, config_path, detect_version  # noqa: E402
from base_elf import (BaseElf, R_X86_64_64, R_X86_64_32, R_X86_64_32S, R_X86_64_PC32,  # noqa: E402
                      R_X86_64_PLT32, R_X86_64_GOTPCREL, R_X86_64_GOTPCRELX, R_X86_64_REX_GOTPCRELX)
import match_check as mc  # noqa: E402


def load_matched(ver: str) -> list[tuple[str, str, str]]:
    rows = []
    p = config_path(REPO_ROOT, ver, "matched", "txt")
    if p.exists():
        for line in p.read_text().splitlines():
            s = line.split("#", 1)[0].split()
            if len(s) >= 2:
                rows.append((s[0], s[1], s[2] if len(s) > 2 else s[0]))
    return rows


def load_data_rows(ver: str) -> list[tuple[str, str, str]]:
    rows = []
    p = config_path(REPO_ROOT, ver, "data", "txt")
    if p.exists():
        for line in p.read_text().splitlines():
            s = line.split("#", 1)[0].split()
            if len(s) >= 2:
                rows.append((s[0], s[1], s[2] if len(s) > 2 else s[0]))
    return rows


def object_data_symbols(obj: Path) -> dict[str, tuple[bytes, list[mc.Reloc], bool]]:
    """symbol -> (bytes, [Reloc], is_nobits) for every STT_OBJECT the object
    defines (its initialised bytes from .data/.rodata, or zeros for .bss)."""
    from elftools.elf.elffile import ELFFile
    from elftools.elf.relocation import RelocationSection
    out = {}
    with obj.open("rb") as f:
        elf = ELFFile(f)
        symtab = elf.get_section_by_name(".symtab")
        syms = list(symtab.iter_symbols())
        locs = mc.named_locals(syms)
        relocs_by_sec: dict[int, list] = {}
        for sec in elf.iter_sections():
            if isinstance(sec, RelocationSection):
                for r in sec.iter_relocations():
                    sym = syms[r["r_info_sym"]]
                    name, addend, value, size = mc.reloc_symbol(
                        elf, locs, sym, r["r_addend"] if "r_addend" in r.entry else 0)
                    relocs_by_sec.setdefault(sec["sh_info"], []).append(
                        mc.Reloc(r["r_offset"], mc.RELOC_WIDTH.get(r["r_info_type"], 4), r["r_info_type"],
                                 name, addend, sym["st_shndx"], value, size))
        for sym in syms:
            if sym["st_info"]["type"] != "STT_OBJECT" or sym["st_shndx"] in ("SHN_UNDEF", "SHN_ABS", "SHN_COMMON"):
                continue
            shndx = sym["st_shndx"]
            sec = elf.get_section(shndx)
            lo, size = sym["st_value"], sym["st_size"]
            nobits = sec["sh_type"] == "SHT_NOBITS"
            data = bytes(size) if nobits else sec.data()[lo:lo + size]
            rl = [mc.Reloc(r.offset - lo, r.width, r.type, r.symbol, r.addend, r.sym_section, r.sym_value, r.sym_size)
                  for r in relocs_by_sec.get(shndx, []) if lo <= r.offset < lo + size]
            out[sym.name] = (data, sorted(rl, key=lambda r: r.offset), nobits)
    return out


def bytes_at(base: BaseElf, va: int, blob: bytes) -> bool:
    """Whether `blob` is the base's bytes at `va`, inside one loaded segment
    (what BaseElf.find_bytes would report at that address)."""
    for p in base.loaded_segments():
        if p["vaddr"] <= va and va + len(blob) <= p["vaddr"] + p["filesz"]:
            o = p["offset"] + va - p["vaddr"]
            return base.data[o:o + len(blob)] == blob
    return False


_OBJ_FUNCS: dict[Path, dict] = {}


def _object_functions(obj: Path) -> dict:
    """match_check.object_functions, once per object."""
    if obj not in _OBJ_FUNCS:
        _OBJ_FUNCS[obj] = mc.object_functions(obj)
    return _OBJ_FUNCS[obj]


_ROW_BY_SYMBOL: dict[tuple[Path, str], int] = {}  # (object, symbol) -> a claimed row's address


def _function_at_hint(base: BaseElf, obj: Path, name: str, hint: int) -> bool:
    """Whether the object's function `name` sits at `hint` in the base:
    instruction by instruction with its relocations masked and their targets
    checked, as the gate compares a claimed row (match_check.compare); a raw
    byte search cannot find it when the code holds an unrelocated field (a
    vtable load, 0x87950's and 0x85d80's initializers)."""
    funcs = _object_functions(obj)
    if name not in funcs:
        return False
    code, relocs = funcs[name]
    try:
        base_bytes = base.read(hint, len(code))
    except Exception:  # noqa: BLE001
        return False
    if len(base_bytes) != len(code):
        return False
    res = mc.compare(code, relocs, base_bytes, hint, base)
    return res["obj_insns"] == res["base_insns"] and res["equal"] == res["obj_insns"] and res["targets_ok"]


def resolve_symbol_address(base: BaseElf, obj: Path, r: mc.Reloc,
                           hint: int | None = None) -> tuple[int | None, str]:
    """The address S the base gives the relocation's symbol, or (None, why).
    `hint` is the S the base's own field at this site encodes: a literal or
    constant-pool entry whose bytes occur more than once (a float constant
    such as pi sits in hundreds of pools) is placed where the base points,
    provided the bytes there are the entry's."""
    s = base.address_of(r.symbol)
    if s is not None:
        return s, ""
    # a function in its own section (-ffunction-sections, docs/DECISIONS.md
    # D39): the assembler rewrites a reference to the unit's own local function
    # as its section plus an offset, and the section carries the function's
    # name; the function is where its claimed row puts it, or, unclaimed (a
    # callback the linker folded, D15), where the base's own field points when
    # its code sits there
    if r.symbol.startswith(".text.") and r.sym_size == 0:
        name = r.symbol[len(".text."):]
        s = base.address_of(name)
        if s is None:
            s = _ROW_BY_SYMBOL.get((obj, name))
        if s is not None:
            return s, ""
        if hint is not None and _function_at_hint(base, obj, name, hint):
            return hint, ""
        return None, f"{r.symbol}: the unit's own function {name} is not claimed and its code is not at the base's field"
    if r.symbol.startswith("_ZGVZ"):
        # the guard of a function-local static (docs/DECISIONS.md D17): the
        # compiler lays the guard out beside the object in the unit's .bss and
        # the linker keeps the unit's layout, so the guard sits at the object's
        # address plus their distance in the object file; the gate checks every
        # reference against the base's field as for any symbol
        static = "_ZZ" + r.symbol[len("_ZGVZ"):]
        s = base.address_of(static)
        here = mc.object_symbol(obj, static)
        if s is not None and here is not None and here[0] == r.sym_section:
            return s + (r.sym_value - here[1]), ""
        return None, f"{r.symbol}: the guard of a function-local static the base does not place ({static})"
    # a function the object defines under a name no row carries (a finish or
    # cleanup callback the linker folded onto a constructor's body, whose row
    # names the constructor: docs/DECISIONS.md D15's round 57 addendum): placed
    # where the base's own field points when the function's code sits there,
    # instruction by instruction with its relocations masked and their targets
    # checked, as the gate compares a claimed row (match_check.compare); a raw
    # byte search cannot find it when the code holds an unrelocated field (a
    # vtable load, 0x87950's and 0x85d80's initializers)
    if hint is not None and not r.symbol.startswith(".") and _function_at_hint(base, obj, r.symbol, hint):
        return hint, ""
    # a symbol the object itself defines in a data section: a string literal
    # or a local constant; find its bytes in the base
    if isinstance(r.sym_section, int) and r.sym_section > 0:
        try:
            if r.sym_size == 0 and r.addend >= 0 and r.symbol.startswith("."):
                blob = mc.object_bytes_of(obj, r.sym_section, r.sym_value + r.addend, 0)
                # the base's own field is tried first: when the entry's bytes
                # sit where it points, that is the placement (the scan of every
                # loaded segment below is the same answer and cost the gate
                # minutes per short constant)
                if hint is not None and bytes_at(base, hint + r.addend, blob):
                    return hint, ""
                hits = base.find_bytes(blob)
                if len(hits) == 1:
                    return hits[0] - r.addend, ""
                if len(hits) > 1 and hint is not None and (hint + r.addend) in hits:
                    return hint, ""
                return None, (f"literal {blob[:24]!r} of {r.symbol} occurs {len(hits)} times in the base"
                              if hits else f"literal {blob[:24]!r} of {r.symbol} not found in the base")
            blob = mc.object_bytes_of(obj, r.sym_section, r.sym_value, r.sym_size)
            if blob:
                if hint is not None and bytes_at(base, hint, blob):
                    return hint, ""
                hits = base.find_bytes(blob)
                if len(hits) == 1:
                    return hits[0], ""
                if len(hits) > 1 and hint is not None and hint in hits:
                    return hint, ""
                return None, f"bytes of {r.symbol} occur {len(hits)} times in the base"
        except Exception as e:  # noqa: BLE001
            return None, f"{r.symbol}: {e}"
    if r.symbol.startswith("_ZTV"):
        return None, (f"{r.symbol}: the executable does not name this vtable (config/vtables.<slug>.txt, "
                      "tools/vtable_names.py); a class named from other evidence needs a ruling (docs/DECISIONS.md D12)")
    return None, (f"{r.symbol}: no address in the base (name it D_<hex> or FUN_<hex>, or add it to the function "
                  "table; a file-local object is named D_<hex> too, docs/DECISIONS.md D17)")


def base_dynamic_relocs(base: BaseElf) -> dict[int, tuple[int, str, int]]:
    """slot address -> (type, symbol name, addend) for every dynamic relocation
    of the base (RELATIVE slots hold the target address in the file; a
    R_X86_64_64 against an import holds 0)."""
    syms, rels = base._dynamic()
    return {r_off: (r_type, syms[r_sym][0] if r_sym < len(syms) else "", r_add) for r_off, r_type, r_sym, r_add in rels}


def apply_relocs(base: BaseElf, obj: Path, code: bytes, relocs: list[mc.Reloc], addr: int,
                 in_data: bool = False) -> tuple[bytearray, list[str]]:
    if not in_data:
        # the linker's GD-to-IE relaxation of every thread-local access (D23)
        code, relocs = mc.relax_tls_gd(code, relocs)
    out = bytearray(code)
    errors = []
    dyn = base_dynamic_relocs(base) if in_data else {}
    for r in relocs:
        P = addr + r.offset
        if r.type == mc.R_X86_64_GOTTPOFF:
            slot = base.tls_got_slot(r.symbol)
            if slot is None:
                errors.append(f"+0x{r.offset:x} {r.symbol}: no single GOT slot of the base holds its thread-pointer offset")
                continue
            struct.pack_into("<i", out, r.offset, slot + r.addend - P)
            continue
        if in_data and r.type == R_X86_64_64:
            # a pointer field: the file holds the target address and the loader
            # adds the load base (RELATIVE), or holds 0 for an import's address
            # (R_X86_64_64 against the import); the base must have that
            # relocation at this slot, or the layout is wrong
            d = dyn.get(P)
            if d is None:
                errors.append(f"+0x{r.offset:x} {r.symbol}: pointer slot 0x{P:x} has no dynamic relocation in the base")
                continue
            S, why = resolve_symbol_address(base, obj, r, d[2] - r.addend if d[0] == 8 else None)
            if S is None and d[0] == R_X86_64_64:
                struct.pack_into("<Q", out, r.offset, 0)   # an import's address: filled by the loader
                continue
            if S is None:
                errors.append(f"+0x{r.offset:x} {why}")
                continue
            if d[0] == 8 and d[2] != S + r.addend:  # RELATIVE: addend is the target
                errors.append(f"+0x{r.offset:x} {r.symbol}: base relocates slot 0x{P:x} to 0x{d[2]:x}, source to 0x{S + r.addend:x}")
                continue
            struct.pack_into("<Q", out, r.offset, (S + r.addend) & 0xFFFFFFFFFFFFFFFF)
            continue
        if r.type in (R_X86_64_GOTPCREL, R_X86_64_GOTPCRELX, R_X86_64_REX_GOTPCRELX):
            slot = base.got_slots().get(BaseElf.base_identifier(r.symbol))
            if slot is not None:
                struct.pack_into("<i", out, r.offset, slot + r.addend - P)
                continue
            # The base has GOT slots for imports only: a GOT load of a symbol
            # the executable defines was relaxed by the linker to lea
            # (docs/DECISIONS.md D10), so do the same; a load the code folds
            # into an add cannot be relaxed, and the linker kept its slot (a
            # RELATIVE relocation among the import slots, D10's addendum).
            if not mc.relaxable_got_load(code, r):
                slot = base.relative_got_slots().get(BaseElf.base_identifier(r.symbol))
                if slot is not None:
                    struct.pack_into("<i", out, r.offset, slot + r.addend - P)
                    continue
                errors.append(f"+0x{r.offset:x} {r.symbol}: no GOT slot in the base and not a relaxable load")
                continue
            try:
                hint = struct.unpack("<i", base.read(P, 4))[0] + P - r.addend
            except ValueError:
                hint = None
            S, why = resolve_symbol_address(base, obj, r, hint)
            if S is None:
                errors.append(f"+0x{r.offset:x} {why}")
                continue
            out[r.offset - 2] = 0x8D
            struct.pack_into("<i", out, r.offset, S + r.addend - P)
            continue
        hint = None
        if r.type in (R_X86_64_PC32, R_X86_64_PLT32) and r.offset + 4 <= len(code):
            try:  # where the base's own displacement at this site points
                hint = struct.unpack("<i", base.read(P, 4))[0] + P - r.addend
            except ValueError:
                hint = None
        S, why = resolve_symbol_address(base, obj, r, hint)
        if S is None:
            errors.append(f"+0x{r.offset:x} {why}")
            continue
        try:
            if r.type in (R_X86_64_PC32, R_X86_64_PLT32):
                struct.pack_into("<i", out, r.offset, S + r.addend - P)
            elif r.type == R_X86_64_32S:
                struct.pack_into("<i", out, r.offset, S + r.addend)
            elif r.type == R_X86_64_32:
                struct.pack_into("<I", out, r.offset, (S + r.addend) & 0xFFFFFFFF)
            elif r.type == R_X86_64_64:
                struct.pack_into("<Q", out, r.offset, (S + r.addend) & 0xFFFFFFFFFFFFFFFF)
            else:
                errors.append(f"+0x{r.offset:x} {r.symbol}: relocation type {r.type} not handled")
        except struct.error:
            errors.append(f"+0x{r.offset:x} {r.symbol}: target 0x{S:x} out of range")
    return out, errors


SEGMENT_NAMES = {5: ".text", 4: ".relro", 6: ".data"}   # by p_flags of the loaded segments


def build_image(ver: str, log=print) -> dict:
    base = BaseElf(REPO_ROOT, ver)
    segs = []
    for p in base.loaded_segments():
        name = SEGMENT_NAMES.get(p["flags"], f".seg{p['index']}")
        img = bytearray(base.data[p["offset"]:p["offset"] + p["filesz"]])
        segs.append({"name": name, "vaddr": p["vaddr"], "filesz": p["filesz"], "memsz": p["memsz"],
                     "image": img, "original": bytes(img), "from_source": 0, "owned_nobits": 0,
                     "claims": []})   # (lo, hi, name) of every object laid out

    def seg_for(va: int):
        for sg in segs:
            if sg["vaddr"] <= va < sg["vaddr"] + sg["memsz"]:
                return sg
        return None

    report = {"version": ver, "functions": {}, "data": {}, "errors": {}, "segments": {}}

    # --- functions ------------------------------------------------------------
    by_tu: dict[str, list[tuple[str, str]]] = {}
    for fn, tu, sym in load_matched(ver):
        by_tu.setdefault(tu, []).append((fn, sym))
    objcache: dict[str, Path | None] = {}

    def compiled(tu: str) -> Path | None:
        if tu not in objcache:
            try:
                objcache[tu] = mc.compile_tu(tu, ver)
            except subprocess.CalledProcessError:
                objcache[tu] = None
        return objcache[tu]

    for tu, pairs in sorted(by_tu.items()):
        obj = compiled(tu)
        if obj is None:
            for fn, _ in pairs:
                report["errors"][fn] = f"{tu} failed to compile"
            continue
        objfuncs = mc.object_functions(obj)
        for fn, sym in pairs:
            if fn not in base.func_by_name:
                report["errors"][fn] = "not in the function table"
                continue
            sym = mc.resolve_symbol(objfuncs, fn, sym) or sym
            if sym not in objfuncs:
                report["errors"][fn] = f"{tu} does not define {sym}"
                continue
            addr, size = base.func_by_name[fn]
            _ROW_BY_SYMBOL[(obj, sym)] = addr
            code, relocs = objfuncs[sym]
            resolved, errs = apply_relocs(base, obj, code, relocs, addr)
            if errs:
                report["errors"][fn] = "; ".join(errs)
            if len(resolved) != size:
                report["errors"][fn] = (report["errors"].get(fn, "") +
                                        f"; size {len(resolved)} differs from the base's {size}").lstrip("; ")
            sg = seg_for(addr)
            off = addr - sg["vaddr"]
            n = min(len(resolved), size)
            sg["image"][off:off + n] = resolved[:n]
            sg["from_source"] += n
            sg["claims"].append((addr, addr + size, fn))
            report["functions"][fn] = {"tu": tu, "symbol": sym, "addr": addr, "size": size,
                                       "relocs": len(relocs), "resolved": not errs, "segment": sg["name"]}

    # --- data objects -----------------------------------------------------------
    for dn, tu, sym in load_data_rows(ver):
        try:
            addr = int(dn[2:], 16) if dn.startswith("D_") else None
        except ValueError:
            addr = None
        if addr is None:
            report["errors"][dn] = "a data row is named D_<hex>, its address in the base"
            continue
        obj = compiled(tu)
        if obj is None:
            report["errors"][dn] = f"{tu} failed to compile"
            continue
        objs = object_data_symbols(obj)
        if sym not in objs:
            cands = [k for k in objs if BaseElf.base_identifier(k) == dn]
            if len(cands) == 1:
                sym = cands[0]
        if sym not in objs:
            report["errors"][dn] = f"{tu} does not define {sym}"
            continue
        data, relocs, nobits = objs[sym]
        sg = seg_for(addr)
        if sg is None or addr + len(data) > sg["vaddr"] + sg["memsz"]:
            report["errors"][dn] = f"0x{addr:x}+{len(data)} is not inside one loaded segment"
            continue
        in_file = addr + len(data) <= sg["vaddr"] + sg["filesz"]
        if in_file:
            resolved, errs = apply_relocs(base, obj, data, relocs, addr, in_data=True)
            if errs:
                report["errors"][dn] = "; ".join(errs)
            off = addr - sg["vaddr"]
            sg["image"][off:off + len(resolved)] = resolved
            sg["from_source"] += len(resolved)
        elif addr >= sg["vaddr"] + sg["filesz"]:
            if relocs:
                report["errors"][dn] = "a .bss object cannot carry relocations"
            sg["owned_nobits"] += len(data)
        else:
            report["errors"][dn] = f"0x{addr:x}+{len(data)} straddles the file/NOBITS boundary"
            continue
        sg["claims"].append((addr, addr + len(data), dn))
        report["data"][dn] = {"tu": tu, "symbol": sym, "addr": addr, "size": len(data),
                              "relocs": len(relocs), "nobits": not in_file, "segment": sg["name"]}

    # --- compare ------------------------------------------------------------------
    import bisect
    fstarts = [a for a, _, _ in base.functions]
    identical = not report["errors"]
    bd = build_dir(REPO_ROOT, ver)
    bd.mkdir(parents=True, exist_ok=True)
    for sg in segs:
        img, orig = sg["image"], sg["original"]
        diffs: dict[str, int] = {}
        gap = 0
        claims = sorted(sg["claims"])
        cstarts = [c[0] for c in claims]
        i = 0
        while i < len(img):
            if img[i] == orig[i]:
                i += 1
                continue
            va = sg["vaddr"] + i
            k = bisect.bisect_right(cstarts, va) - 1
            if k >= 0 and va < claims[k][1]:
                diffs[claims[k][2]] = diffs.get(claims[k][2], 0) + 1
            else:
                k = bisect.bisect_right(fstarts, va) - 1
                if k >= 0 and va < base.functions[k][0] + base.functions[k][1]:
                    diffs[base.functions[k][2]] = diffs.get(base.functions[k][2], 0) + 1
                else:
                    gap += 1
            i += 1
        if diffs or gap:
            identical = False
        (bd / f"{sg['name'].lstrip('.')}.bin").write_bytes(img)
        report["segments"][sg["name"]] = {
            "vaddr": sg["vaddr"], "filesz": sg["filesz"], "memsz": sg["memsz"],
            "from_source": sg["from_source"], "from_base": sg["filesz"] - sg["from_source"],
            "nobits": sg["memsz"] - sg["filesz"], "owned_nobits": sg["owned_nobits"],
            "differing": [{"name": k, "bytes": v} for k, v in sorted(diffs.items())],
            "gap_bytes_differing": gap, "identical": not diffs and not gap}
    report["identical"] = identical
    # compatibility fields for the text segment
    t = report["segments"].get(".text", {})
    report["text_vaddr"] = t.get("vaddr", 0)
    report["text_size"] = t.get("filesz", 0)
    report["differing"] = t.get("differing", [])
    report["gap_bytes_differing"] = t.get("gap_bytes_differing", 0)
    (bd / "layout.json").write_text(json.dumps(report, indent=1))
    return report


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--quiet", action="store_true")
    a = ap.parse_args(argv)
    ver = detect_version(REPO_ROOT)
    r = build_image(ver)
    if not a.quiet:
        print(f"layout ({ver}): {len(r['functions'])} function(s) and {len(r['data'])} data object(s) from source, "
              f"{sum(f['relocs'] for f in list(r['functions'].values()) + list(r['data'].values()))} relocation(s) resolved")
        for fn, why in sorted(r["errors"].items()):
            print(f"  ERROR {fn}: {why}")
        for name, sg in r["segments"].items():
            for d in sg["differing"]:
                print(f"  DIFFERS {name} {d['name']}: {d['bytes']} byte(s)")
            if sg["gap_bytes_differing"]:
                print(f"  DIFFERS {name} outside claimed objects: {sg['gap_bytes_differing']} byte(s)")
            print(f"  {name:<7} {sg['filesz']:>12,} bytes: {sg['from_source']:,} from source, "
                  f"{sg['from_base']:,} from the base"
                  + (f", NOBITS {sg['nobits']:,} ({sg['owned_nobits']:,} owned)" if sg['nobits'] else "")
                  + f": {'identical' if sg['identical'] else 'DIFFERS'}")
        print(f"layout: {'every segment IDENTICAL to the base' if r['identical'] else 'DIFFERS from the base'}")
    return 0 if r["identical"] else 1


if __name__ == "__main__":
    sys.exit(main())
