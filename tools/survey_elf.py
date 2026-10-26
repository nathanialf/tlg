#!/usr/bin/env python3
"""
survey_elf.py: the first map of the target's executable, from the ELF alone.

Writes:
    config/functions.<slug>.txt   one row per function: `0x<addr> 0x<size> <name>`,
                                  the boundaries from the compiler's own unwind
                                  tables (.eh_frame, located by PT_GNU_EH_FRAME);
                                  names are FUN_<addr> until a real one is known
    build/<slug>/survey.json      everything below as data, for other tools
    stdout                        the survey summary (--md writes it as Markdown)

What it reads, and from where:
  * Program headers: the loaded ranges, the SCE segments (PT_SCE_PROCPARAM holds
    the SDK version the executable was linked against; PT_SCE_COMMENT the
    original output path; PT_SCE_LIBVERSION the libraries linked).
  * .eh_frame_hdr / .eh_frame: every FDE's pc_begin and pc_range. Each is one
    function the compiler emitted unwind info for (clang does by default on
    x86-64).
  * PT_DYNAMIC + PT_SCE_DYNLIBDATA: the SCE dynamic tags locate the string and
    symbol tables inside the dynlib data; imports and exports are listed by
    NID (symbol names are `<nid>#<lib>#<module>`); the needed modules and
    import libraries are named.
  * Printable strings: source paths the compiler baked in (asserts, __FILE__),
    grouped by root, as hints to the original tree layout.

Nothing it writes carries bytes of the executable: addresses, sizes, counts,
library names and the paths of the developers' own source files only.

    survey_elf.py [--md] [--no-write]
"""
from __future__ import annotations

import argparse
import json
import re
import struct
import sys
from collections import Counter, defaultdict
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(Path(__file__).resolve().parent))
from tlg_version import baseelf_path, build_dir, config_path, detect_version  # noqa: E402

PT_LOAD, PT_DYNAMIC, PT_TLS = 1, 2, 7
PT_GNU_EH_FRAME = 0x6474E550
PT_SCE_RELA, PT_SCE_DYNLIBDATA, PT_SCE_PROCPARAM = 0x60000000, 0x61000000, 0x61000001
PT_SCE_RELRO, PT_SCE_COMMENT, PT_SCE_LIBVERSION = 0x61000010, 0x6FFFFF00, 0x6FFFFF01
PT_NAMES = {PT_LOAD: "PT_LOAD", PT_DYNAMIC: "PT_DYNAMIC", 3: "PT_INTERP", PT_TLS: "PT_TLS",
            PT_GNU_EH_FRAME: "PT_GNU_EH_FRAME", PT_SCE_RELA: "PT_SCE_RELA",
            PT_SCE_DYNLIBDATA: "PT_SCE_DYNLIBDATA", PT_SCE_PROCPARAM: "PT_SCE_PROCPARAM",
            PT_SCE_RELRO: "PT_SCE_RELRO", PT_SCE_COMMENT: "PT_SCE_COMMENT",
            PT_SCE_LIBVERSION: "PT_SCE_LIBVERSION"}

# SCE dynamic tags (values are offsets into PT_SCE_DYNLIBDATA, or sizes).
DT_SCE_FINGERPRINT = 0x61000007
DT_SCE_ORIGINAL_FILENAME = 0x61000009
DT_SCE_MODULE_INFO = 0x6100000D
DT_SCE_NEEDED_MODULE = 0x6100000F
DT_SCE_MODULE_ATTR = 0x61000011
DT_SCE_EXPORT_LIB = 0x61000013
DT_SCE_IMPORT_LIB = 0x61000015
DT_SCE_HASH = 0x61000025
DT_SCE_PLTGOT = 0x61000027
DT_SCE_JMPREL = 0x61000029
DT_SCE_PLTREL = 0x6100002B
DT_SCE_PLTRELSZ = 0x6100002D
DT_SCE_RELA = 0x6100002F
DT_SCE_RELASZ = 0x61000031
DT_SCE_RELAENT = 0x61000033
DT_SCE_STRTAB = 0x61000035
DT_SCE_STRSZ = 0x61000037
DT_SCE_SYMTAB = 0x61000039
DT_SCE_SYMENT = 0x6100003B
DT_SCE_HASHSZ = 0x6100003D
DT_SCE_SYMTABSZ = 0x6100003F
DT_SCE_EXPORT_LIB_ATTR = 0x61000047
DT_SCE_IMPORT_LIB_ATTR = 0x61000049


def read_phdrs(data: bytes):
    e_phoff, = struct.unpack_from("<Q", data, 0x20)
    e_phentsize, e_phnum = struct.unpack_from("<HH", data, 0x36)
    out = []
    for i in range(e_phnum):
        p_type, p_flags, p_offset, p_vaddr, p_paddr, p_filesz, p_memsz, p_align = \
            struct.unpack_from("<2I6Q", data, e_phoff + i * e_phentsize)
        out.append(dict(index=i, type=p_type, name=PT_NAMES.get(p_type, hex(p_type)),
                        flags=p_flags, offset=p_offset, vaddr=p_vaddr, filesz=p_filesz,
                        memsz=p_memsz, align=p_align))
    return out


def vaddr_to_off(phdrs, va: int) -> int | None:
    for p in phdrs:
        if p["type"] == PT_LOAD and p["vaddr"] <= va < p["vaddr"] + p["filesz"]:
            return p["offset"] + (va - p["vaddr"])
    return None


# --- DWARF pointer encodings (the subset .eh_frame uses) ----------------------

def read_uleb(data, off):
    v = s = 0
    while True:
        b = data[off]; off += 1
        v |= (b & 0x7F) << s; s += 7
        if not b & 0x80:
            return v, off


def read_sleb(data, off):
    v = s = 0
    while True:
        b = data[off]; off += 1
        v |= (b & 0x7F) << s; s += 7
        if not b & 0x80:
            if b & 0x40:
                v -= 1 << s
            return v, off


def read_encoded(data, off, enc, pc_va_of_off, datarel_base=0):
    """Read a DW_EH_PE-encoded pointer at file offset `off`; return (value, off)."""
    if enc == 0xFF:  # omit
        return None, off
    fmt = enc & 0x0F
    app = enc & 0x70
    base_off = off
    if fmt == 0x00:
        v, = struct.unpack_from("<Q", data, off); off += 8
    elif fmt == 0x01:
        v, off = read_uleb(data, off)
    elif fmt == 0x02:
        v, = struct.unpack_from("<H", data, off); off += 2
    elif fmt == 0x03:
        v, = struct.unpack_from("<I", data, off); off += 4
    elif fmt == 0x04:
        v, = struct.unpack_from("<Q", data, off); off += 8
    elif fmt == 0x09:
        v, off = read_sleb(data, off)
    elif fmt == 0x0A:
        v, = struct.unpack_from("<h", data, off); off += 2
    elif fmt == 0x0B:
        v, = struct.unpack_from("<i", data, off); off += 4
    elif fmt == 0x0C:
        v, = struct.unpack_from("<q", data, off); off += 8
    else:
        raise ValueError(f"unsupported pointer encoding 0x{enc:X}")
    if app == 0x10:   # pcrel
        v += pc_va_of_off(base_off)
    elif app == 0x30:  # datarel
        v += datarel_base
    elif app != 0x00:
        raise ValueError(f"unsupported pointer application 0x{enc:X}")
    return v, off


def parse_eh_frame(data: bytes, phdrs) -> list[tuple[int, int]]:
    """Every FDE's (pc_begin, pc_range), via .eh_frame_hdr's table."""
    hdr = next((p for p in phdrs if p["type"] == PT_GNU_EH_FRAME), None)
    if hdr is None:
        return []
    off_to_va = lambda o: hdr["vaddr"] + (o - hdr["offset"])  # noqa: E731
    o = hdr["offset"]
    version, eh_frame_ptr_enc, fde_count_enc, table_enc = data[o:o + 4]
    o += 4
    eh_frame_va, o = read_encoded(data, o, eh_frame_ptr_enc, off_to_va, hdr["vaddr"])
    fde_count, o = read_encoded(data, o, fde_count_enc, off_to_va, hdr["vaddr"])
    fdes = []
    for _ in range(fde_count):
        _initial, o = read_encoded(data, o, table_enc, off_to_va, hdr["vaddr"])
        fde_va, o = read_encoded(data, o, table_enc, off_to_va, hdr["vaddr"])
        fdes.append(fde_va)

    cie_cache: dict[int, int] = {}

    def cie_fde_encoding(cie_off: int) -> int:
        if cie_off in cie_cache:
            return cie_cache[cie_off]
        length, = struct.unpack_from("<I", data, cie_off)
        p = cie_off + 8  # length + CIE id (0)
        ver = data[p]; p += 1
        aug_end = data.index(b"\0", p)
        aug = data[p:aug_end].decode("ascii"); p = aug_end + 1
        if ver >= 4:
            p += 2  # address_size, segment_size
        _, p = read_uleb(data, p)        # code alignment
        _, p = read_sleb(data, p)        # data alignment
        if ver == 1:
            p += 1                        # return address register
        else:
            _, p = read_uleb(data, p)
        enc = 0x00
        if aug.startswith("z"):
            _, p = read_uleb(data, p)    # augmentation length
            for ch in aug[1:]:
                if ch == "R":
                    enc = data[p]; p += 1
                elif ch == "P":
                    penc = data[p]; p += 1
                    _, p = read_encoded(data, p, penc, off_to_va)
                elif ch == "L":
                    p += 1
                elif ch == "S" or ch == "B":
                    pass
        cie_cache[cie_off] = enc
        return enc

    out = []
    for fde_va in fdes:
        fo = vaddr_to_off(phdrs, fde_va)
        length, = struct.unpack_from("<I", data, fo)
        cie_ptr, = struct.unpack_from("<I", data, fo + 4)
        cie_off = fo + 4 - cie_ptr
        enc = cie_fde_encoding(cie_off)
        p = fo + 8
        pc_begin, p = read_encoded(data, p, enc, lambda o2: fde_va + (o2 - fo))
        pc_range, p = read_encoded(data, p, enc & 0x0F, lambda o2: 0)
        out.append((pc_begin, pc_range))
    out.sort()
    return out


# --- SCE dynamic data -----------------------------------------------------------

def parse_dynamic(data: bytes, phdrs) -> dict:
    dyn = next((p for p in phdrs if p["type"] == PT_DYNAMIC), None)
    dld = next((p for p in phdrs if p["type"] == PT_SCE_DYNLIBDATA), None)
    if dyn is None or dld is None:
        return {}
    tags: dict[int, list[int]] = defaultdict(list)
    o = dyn["offset"]
    while o < dyn["offset"] + dyn["filesz"]:
        tag, val = struct.unpack_from("<qQ", data, o); o += 16
        if tag == 0:
            break
        tags[tag].append(val)
    base = dld["offset"]
    strtab = base + tags[DT_SCE_STRTAB][0] if DT_SCE_STRTAB in tags else None
    strsz = tags[DT_SCE_STRSZ][0] if DT_SCE_STRSZ in tags else 0

    def cstr(off: int) -> str:
        if strtab is None:
            return ""
        end = data.index(b"\0", strtab + off)
        return data[strtab + off:end].decode("utf-8", "replace")

    info = {"needed_modules": [], "import_libs": [], "export_libs": [], "module_info": "",
            "original_filename": "", "imports": 0, "exports": 0, "import_funcs": 0,
            "export_funcs": 0, "symbols": 0, "rela_count": 0, "jmprel_count": 0,
            "exported_symbols": []}
    for v in tags.get(DT_SCE_NEEDED_MODULE, []):
        info["needed_modules"].append(cstr(v & 0xFFFFFFFF))
    for v in tags.get(DT_SCE_IMPORT_LIB, []):
        info["import_libs"].append(cstr(v & 0xFFFFFFFF))
    for v in tags.get(DT_SCE_EXPORT_LIB, []):
        info["export_libs"].append(cstr(v & 0xFFFFFFFF))
    if DT_SCE_MODULE_INFO in tags:
        info["module_info"] = cstr(tags[DT_SCE_MODULE_INFO][0] & 0xFFFFFFFF)
    if DT_SCE_ORIGINAL_FILENAME in tags:
        info["original_filename"] = cstr(tags[DT_SCE_ORIGINAL_FILENAME][0] & 0xFFFFFFFF)
    if DT_SCE_RELASZ in tags and DT_SCE_RELAENT in tags:
        info["rela_count"] = tags[DT_SCE_RELASZ][0] // tags[DT_SCE_RELAENT][0]
    if DT_SCE_PLTRELSZ in tags:
        info["jmprel_count"] = tags[DT_SCE_PLTRELSZ][0] // 24
    if DT_SCE_SYMTAB in tags and DT_SCE_SYMTABSZ in tags:
        symtab = base + tags[DT_SCE_SYMTAB][0]
        ent = tags[DT_SCE_SYMENT][0] if DT_SCE_SYMENT in tags else 24
        n = tags[DT_SCE_SYMTABSZ][0] // ent
        info["symbols"] = n
        for i in range(n):
            st_name, st_info, st_other, st_shndx, st_value, st_size = \
                struct.unpack_from("<IBBHQQ", data, symtab + i * ent)
            if st_name == 0:
                continue
            is_func = (st_info & 0xF) == 2
            if st_value == 0:
                info["imports"] += 1
                info["import_funcs"] += is_func
            else:
                info["exports"] += 1
                info["export_funcs"] += is_func
                info["exported_symbols"].append(
                    {"name": cstr(st_name), "addr": st_value, "size": st_size, "func": is_func})
    return info


def parse_procparam(data: bytes, phdrs) -> dict:
    pp = next((p for p in phdrs if p["type"] == PT_SCE_PROCPARAM), None)
    if pp is None:
        return {}
    # u32 size, u32 pad, "ORBI", u32 entry count, u32 SDK version (0x03508031
    # reads as 03.508.031), then the pointers.
    size, _pad, magic, entry_count, sdk_version = struct.unpack_from("<II4sII", data, pp["offset"])
    return {"magic": magic.decode("ascii", "replace"), "sdk_version": sdk_version,
            "sdk_version_str": f"{sdk_version >> 24:02X}.{(sdk_version >> 12) & 0xFFF:03X}.{sdk_version & 0xFFF:03X}"}


def parse_comment(data: bytes, phdrs) -> str:
    c = next((p for p in phdrs if p["type"] == PT_SCE_COMMENT), None)
    if c is None:
        return ""
    blob = data[c["offset"]:c["offset"] + c["filesz"]]
    # "PATH" <u32 size> <u32 ?> <string>
    if blob[:4] == b"PATH":
        return blob[12:].split(b"\0", 1)[0].decode("utf-8", "replace")
    return blob.split(b"\0", 1)[0].decode("utf-8", "replace")


def parse_libversion(data: bytes, phdrs) -> list[str]:
    lv = next((p for p in phdrs if p["type"] == PT_SCE_LIBVERSION), None)
    if lv is None:
        return []
    blob = data[lv["offset"]:lv["offset"] + lv["filesz"]]
    # entries: u8 length, then "<name>:" followed by 4 version bytes
    out, o = [], 0
    while o < len(blob):
        ln = blob[o]; o += 1
        if ln == 0 or o + ln > len(blob):
            break
        ent = blob[o:o + ln]; o += ln
        name, _, ver = ent.partition(b":")
        out.append(f"{name.decode('ascii', 'replace')} {ver[:4].hex() if ver else ''}".strip())
    return out


SRC_RE = re.compile(rb"[A-Za-z]:[\\/][\x20-\x7e]{3,200}?\.(?:cpp|cc|cxx|c|h|hpp|inl)(?=\x00)")


def source_paths(data: bytes) -> dict[str, list[str]]:
    paths = sorted({m.group(0).decode("ascii") for m in SRC_RE.finditer(data)})
    by_root: dict[str, list[str]] = defaultdict(list)
    for p in paths:
        parts = re.split(r"[\\/]", p)
        by_root["/".join(parts[:3])].append(p.replace("\\", "/"))
    return dict(by_root)


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--md", action="store_true", help="print the summary as Markdown")
    ap.add_argument("--no-write", action="store_true", help="print only")
    a = ap.parse_args(argv)
    ver = detect_version(REPO_ROOT)
    elf = baseelf_path(REPO_ROOT, ver)
    if not elf.exists():
        print(f"survey_elf: {elf.relative_to(REPO_ROOT)} missing; run ./build.sh", file=sys.stderr)
        return 1
    data = elf.read_bytes()
    phdrs = read_phdrs(data)
    e_type, = struct.unpack_from("<H", data, 0x10)
    e_entry, = struct.unpack_from("<Q", data, 0x18)
    fdes = parse_eh_frame(data, phdrs)
    dyn = parse_dynamic(data, phdrs)
    pp = parse_procparam(data, phdrs)
    comment = parse_comment(data, phdrs)
    libver = parse_libversion(data, phdrs)
    srcs = source_paths(data)

    text = next(p for p in phdrs if p["type"] == PT_LOAD and p["flags"] & 1)
    func_bytes = sum(sz for _, sz in fdes)
    # gaps between consecutive FDEs inside the text segment (padding, or code
    # with no unwind info)
    gap_bytes = 0
    for (a0, s0), (a1, _) in zip(fdes, fdes[1:]):
        if a1 > a0 + s0:
            gap_bytes += a1 - (a0 + s0)
    sizes = [sz for _, sz in fdes]
    exports = dyn.get("exported_symbols", [])
    export_by_addr = {e["addr"]: e["name"] for e in exports if e["func"]}

    summary = {
        "version": ver, "elf": str(elf.relative_to(REPO_ROOT)), "size": len(data),
        "e_type": e_type, "e_entry": e_entry, "phdrs": phdrs,
        "procparam": pp, "comment_path": comment, "libversion": libver,
        "text": {"vaddr": text["vaddr"], "filesz": text["filesz"]},
        "functions": {"count": len(fdes), "bytes": func_bytes, "gap_bytes": gap_bytes,
                      "min": min(sizes) if sizes else 0, "max": max(sizes) if sizes else 0,
                      "median": sorted(sizes)[len(sizes) // 2] if sizes else 0},
        "dynamic": {k: v for k, v in dyn.items() if k != "exported_symbols"},
        "exports": exports,
        "source_roots": {k: len(v) for k, v in srcs.items()},
        "source_files": srcs,
    }

    if not a.no_write:
        funcs_path = config_path(REPO_ROOT, ver, "functions", "txt")
        funcs_path.parent.mkdir(parents=True, exist_ok=True)
        # Names already given to rows (docs/MATCH.md step 6 renames a FUN_ row
        # to its mangled symbol once the name is a fact) are kept: a rewrite
        # that dropped them would break every matched row that cites them.
        known: dict[int, str] = {}
        if funcs_path.exists():
            for line in funcs_path.read_text().splitlines():
                s = line.split("#", 1)[0].split()
                if len(s) >= 3 and not s[2].startswith("FUN_"):
                    known[int(s[0], 16)] = s[2]
        with funcs_path.open("w") as f:
            f.write("# One row per function of the target executable: address, size, name.\n"
                    "# Boundaries from the compiler's unwind tables (.eh_frame), plus the\n"
                    "# functions without one that a live reference reaches (commented rows,\n"
                    "# config/residue.<slug>.txt, docs/DECISIONS.md D13), written by\n"
                    "# tools/survey_elf.py, which keeps a row's name once it is no longer\n"
                    "# FUN_<addr>. A name is a fact of the executable (an exported symbol, a\n"
                    "# reflection or type-info string with the role the vtable or the ABI\n"
                    "# fixes); anything inferred stays FUN_<addr> with a derived name in the\n"
                    "# source (docs/MATCH.md).\n")
            # functions with no unwind entry that a live reference reaches
            # (tools/text_residue.py, docs/DECISIONS.md D13): rows with a
            # comment naming the reference
            extra: dict[int, tuple[int, str]] = {}
            residue_path = config_path(REPO_ROOT, ver, "residue", "txt")
            if residue_path.exists():
                for line in residue_path.read_text().splitlines():
                    s = line.split()
                    if len(s) >= 3 and s[2] == "function":
                        extra[int(s[0], 16)] = (int(s[1], 16) - int(s[0], 16), " ".join(s[3:]))
            rows = [(addr, sz, "") for addr, sz in fdes] + \
                   [(addr, sz, f"  # no unwind entry; {note}") for addr, (sz, note) in extra.items()]
            for addr, sz, note in sorted(rows):
                name = known.get(addr) or export_by_addr.get(addr, f"FUN_{addr:08x}")
                f.write(f"0x{addr:08x} 0x{sz:x} {name}{note}\n")
        bd = build_dir(REPO_ROOT, ver)
        bd.mkdir(parents=True, exist_ok=True)
        (bd / "survey.json").write_text(json.dumps(summary, indent=1))

    fn = summary["functions"]
    if a.md:
        print(f"# Survey of `{summary['elf']}`\n")
        print(f"| | |\n|---|---|")
        print(f"| file size | {len(data):,} bytes |")
        print(f"| ELF type | 0x{e_type:X} ({'ET_SCE_DYNEXEC' if e_type == 0xFE10 else '?'}) |")
        print(f"| entry | 0x{e_entry:X} |")
        print(f"| SDK (PT_SCE_PROCPARAM) | {pp.get('sdk_version_str', '?')} (0x{pp.get('sdk_version', 0):08X}) |")
        print(f"| original output path (PT_SCE_COMMENT) | `{comment}` |")
        print(f"| .text segment | vaddr 0x{text['vaddr']:X}, {text['filesz']:,} bytes |")
        print(f"| functions (FDEs) | {fn['count']:,} |")
        print(f"| bytes in functions | {fn['bytes']:,} ({100 * fn['bytes'] / text['filesz']:.1f}% of .text) |")
        print(f"| gaps between functions | {fn['gap_bytes']:,} bytes |")
        print(f"| function size min / median / max | {fn['min']} / {fn['median']} / {fn['max']:,} |")
        d = summary["dynamic"]
        print(f"| dynamic symbols | {d.get('symbols', 0):,} ({d.get('imports', 0):,} imports, "
              f"{d.get('import_funcs', 0):,} functions; {d.get('exports', 0):,} exports) |")
        print(f"| relocations | {d.get('rela_count', 0):,} RELA + {d.get('jmprel_count', 0):,} JMPREL |")
        print(f"| needed modules | {len(d.get('needed_modules', []))} |")
        print(f"| import libraries | {len(d.get('import_libs', []))} |")
        print(f"| source files named in strings | {sum(summary['source_roots'].values())} |")
        print("\n## Program headers\n\n| # | type | offset | vaddr | filesz | memsz | flags |\n|---|---|---|---|---|---|---|")
        for p in phdrs:
            print(f"| {p['index']} | {p['name']} | 0x{p['offset']:X} | 0x{p['vaddr']:X} | "
                  f"0x{p['filesz']:X} | 0x{p['memsz']:X} | {p['flags']} |")
        print("\n## Needed modules\n")
        for m in d.get("needed_modules", []):
            print(f"- `{m}`")
        print("\n## Import libraries\n")
        for m in d.get("import_libs", []):
            print(f"- `{m}`")
        print("\n## Exports\n")
        for e in exports:
            print(f"- `{e['name']}` at 0x{e['addr']:X} ({'func' if e['func'] else 'object'}, {e['size']} bytes)")
        print("\n## Linked libraries (PT_SCE_LIBVERSION)\n")
        for s in libver:
            print(f"- `{s}`")
        print("\n## Source roots named in strings\n\n| root | files |\n|---|---|")
        for k, v in sorted(summary["source_roots"].items(), key=lambda kv: -kv[1]):
            print(f"| `{k}` | {v} |")
        print("\n## Source files\n")
        for k in sorted(srcs):
            print(f"\n### `{k}`\n")
            for p in srcs[k]:
                print(f"- `{p}`")
    else:
        print(f"survey: {fn['count']} functions, {fn['bytes']} bytes of {text['filesz']} .text; "
              f"SDK {pp.get('sdk_version_str')}; {summary['dynamic'].get('imports', 0)} imports; "
              f"{sum(summary['source_roots'].values())} source files named")
    return 0


if __name__ == "__main__":
    sys.exit(main())
