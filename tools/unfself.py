#!/usr/bin/env python3
"""
unfself.py: convert a fake-signed PS4 SELF (eboot.bin, *.prx, *.sprx) to a
plain ELF.

A fake-signed SELF ("fSELF", the form a homebrew-packaged game ships in) is
an ELF whose header, program headers and segments were rewrapped in the SELF
container without encryption: every segment entry has its Encrypted bit
clear. This tool unwraps that container and nothing more. A retail SELF has
its segments encrypted and is refused: no key material exists here, and none
is wanted.

Layout (little-endian), as documented by the public unfself tools (SocraticBliss
ps4_unfself, Znullptr SELFUtil, flatz make_fself):

    SELF header        32 bytes   magic 4F 15 3D 1D, version, mode, endian,
                                  attributes, content type, key type,
                                  header size, meta size, file size,
                                  entry count, flags
    SELF entries       32 bytes each: props, file offset, file size, memory size
                                  props bit 1 = encrypted, bit 2 = signed,
                                  bit 3 = compressed, bit 11 = has blocks
                                  (carries a segment), bits 20.. = segment index
    ELF header         64 bytes   e_type is an SCE value (0xFE10 ET_SCE_DYNEXEC,
                                  0xFE18 ET_SCE_DYNAMIC)
    ELF program headers
    SELF extended info 8 pad + auth id, program type, app version, fw version,
                                  32-byte digest

Each entry with the has-blocks bit holds the bytes of program header
[segment index]; they are written to the output at that header's p_offset.
The bytes after the last entry's data hold the PT_SCE_LIBVERSION segment,
written to its header's p_offset. Nothing is decrypted or decompressed.

    unfself.py <in.self> <out.elf> [--quiet]

Exit 0 on success, 2 when the input is not a SELF, 3 when it is encrypted or
compressed (a retail SELF), 1 on any other failure.
"""
from __future__ import annotations

import argparse
import struct
import sys
from pathlib import Path

SELF_MAGIC = b"\x4f\x15\x3d\x1d"
ELF_MAGIC = b"\x7fELF"

ET_NAMES = {0x0: "ET_NONE", 0x2: "ET_EXEC", 0x3: "ET_DYN", 0xFE00: "ET_SCE_EXEC",
            0xFE0C: "ET_SCE_STUBLIB", 0xFE10: "ET_SCE_DYNEXEC", 0xFE18: "ET_SCE_DYNAMIC"}
PT_NAMES = {0x1: "PT_LOAD", 0x2: "PT_DYNAMIC", 0x4: "PT_NOTE", 0x7: "PT_TLS",
            0x6474E550: "PT_GNU_EH_FRAME", 0x6474E551: "PT_GNU_STACK",
            0x6474E552: "PT_GNU_RELRO", 0x60000000: "PT_SCE_RELA",
            0x61000000: "PT_SCE_DYNLIBDATA", 0x61000001: "PT_SCE_PROCPARAM",
            0x61000002: "PT_SCE_MODULE_PARAM", 0x61000010: "PT_SCE_RELRO",
            0x6FFFFF00: "PT_SCE_COMMENT", 0x6FFFFF01: "PT_SCE_LIBVERSION"}
PROGRAM_TYPES = {0x1: "PT_FAKE", 0x4: "PT_NPDRM_EXEC", 0x5: "PT_NPDRM_DYNLIB",
                 0x8: "PT_SYSTEM_EXEC", 0x9: "PT_SYSTEM_DYNLIB"}

PROP_ENCRYPTED = 1 << 1
PROP_SIGNED = 1 << 2
PROP_COMPRESSED = 1 << 3
PROP_HAS_BLOCKS = 1 << 11


class NotASelf(Exception):
    pass


class EncryptedSelf(Exception):
    pass


def unfself(data: bytes, log=print) -> tuple[bytes, dict]:
    """Return (elf_bytes, info). Raises NotASelf / EncryptedSelf / ValueError."""
    if data[:4] != SELF_MAGIC:
        raise NotASelf(f"magic {data[:4].hex()} is not a SELF")
    (magic, version, mode, endian, attrs, content_type, key_type, header_size,
     meta_size, file_size, num_entries, flags) = struct.unpack_from("<4s4B2B2x2HQ2H4x", data, 0)
    if endian != 1:
        raise ValueError(f"big-endian SELF (endian={endian})")
    info = {"self_version": version, "self_mode": mode, "content_type": content_type,
            "key_type": key_type, "header_size": header_size, "meta_size": meta_size,
            "file_size": file_size, "num_entries": num_entries, "flags": flags}
    log(f"SELF: version {version}, mode 0x{mode:X}, content type 0x{content_type:X}, "
        f"key type 0x{key_type:X}, {num_entries} entries, file size {file_size}")

    entries = []
    off = 32
    for i in range(num_entries):
        props, foff, fsz, msz = struct.unpack_from("<4Q", data, off)
        off += 32
        enc = bool(props & PROP_ENCRYPTED)
        comp = bool(props & PROP_COMPRESSED)
        blocks = bool(props & PROP_HAS_BLOCKS)
        seg = props >> 20
        entries.append((props, foff, fsz, msz, enc, comp, blocks, seg))
        log(f"  entry {i}: props 0x{props:X} seg {seg} off 0x{foff:X} size 0x{fsz:X}"
            f"{' ENCRYPTED' if enc else ''}{' COMPRESSED' if comp else ''}"
            f"{' blocks' if blocks else ''}")
    if any(e[4] for e in entries):
        raise EncryptedSelf("a segment entry has the Encrypted bit set: retail SELF")
    if any(e[5] for e in entries):
        raise EncryptedSelf("a segment entry has the Compressed bit set")

    elf_start = off
    if data[elf_start:elf_start + 4] != ELF_MAGIC:
        raise ValueError(f"no ELF header at 0x{elf_start:X}")
    (e_type, e_machine, e_version, e_entry, e_phoff, e_shoff, e_flags, e_ehsize,
     e_phentsize, e_phnum, e_shentsize, e_shnum, e_shstrndx) = \
        struct.unpack_from("<2HI3QI6H", data, elf_start + 16)
    info.update({"e_type": e_type, "e_type_name": ET_NAMES.get(e_type, "?"),
                 "e_machine": e_machine, "e_entry": e_entry, "e_phnum": e_phnum,
                 "e_shnum": e_shnum})
    log(f"ELF: {ET_NAMES.get(e_type, hex(e_type))}, machine 0x{e_machine:X}, "
        f"entry 0x{e_entry:X}, {e_phnum} program headers, {e_shnum} section headers")
    if e_machine != 0x3E:
        raise ValueError(f"not x86-64 (e_machine 0x{e_machine:X})")

    phdrs = []
    for i in range(e_phnum):
        p = struct.unpack_from("<2I6Q", data, elf_start + e_phoff + i * e_phentsize)
        phdrs.append(p)
        p_type, p_flags, p_offset, p_vaddr, p_paddr, p_filesz, p_memsz, p_align = p
        log(f"  phdr {i}: {PT_NAMES.get(p_type, hex(p_type))} off 0x{p_offset:X} "
            f"vaddr 0x{p_vaddr:X} filesz 0x{p_filesz:X} memsz 0x{p_memsz:X} flags {p_flags}")

    headers_end = elf_start + e_phoff + e_phnum * e_phentsize
    if e_shnum:
        headers_end = max(headers_end, elf_start + e_shoff + e_shnum * e_shentsize)
    # SELF extended information follows the ELF headers: 8 bytes of padding,
    # then the five fields (the layout the reference ps4_unfself reads).
    ext_off = headers_end
    if ext_off + 72 <= len(data):
        _, auth_id, prog_type, app_ver, fw_ver, digest = \
            struct.unpack_from("<Q4Q32s", data, ext_off)
        info.update({"auth_id": auth_id, "program_type": prog_type,
                     "program_type_name": PROGRAM_TYPES.get(prog_type, "?"),
                     "app_version": app_ver, "fw_version": fw_ver,
                     "digest": digest.hex()})
        log(f"SELF ext: auth 0x{auth_id:X}, program type 0x{prog_type:X} "
            f"({PROGRAM_TYPES.get(prog_type, '?')}), fw 0x{fw_ver:X}")

    # The output: ELF header + program headers (+ section headers) verbatim,
    # then every segment at its p_offset.
    header_blob = data[elf_start:headers_end]
    out_size = len(header_blob)
    for p in phdrs:
        out_size = max(out_size, p[2] + p[5])
    out = bytearray(out_size)
    out[:len(header_blob)] = header_blob

    by_seg = {}
    last_end = 0
    for (props, foff, fsz, msz, enc, comp, blocks, seg) in entries:
        last_end = max(last_end, foff + fsz)
        if blocks:
            by_seg.setdefault(seg, []).append((foff, fsz))
    tail = data[last_end:] if last_end < len(data) else b""

    # First the segments the SELF carries, then the headers that only name a
    # sub-range of one of them (PT_DYNAMIC inside PT_SCE_DYNLIBDATA, PT_INTERP,
    # PT_TLS, PT_GNU_EH_FRAME and PT_SCE_PROCPARAM inside a PT_LOAD), which
    # need no data of their own.
    written: list[tuple[int, int]] = [(0, len(header_blob))]
    unsourced = []
    for i, p in enumerate(phdrs):
        p_type, p_flags, p_offset, p_vaddr, p_paddr, p_filesz, p_memsz, p_align = p
        if p_filesz == 0:
            continue
        if i in by_seg:
            foff, fsz = by_seg[i][0]
            if fsz != p_filesz:
                raise ValueError(f"phdr {i}: entry size 0x{fsz:X} != p_filesz 0x{p_filesz:X}")
            out[p_offset:p_offset + fsz] = data[foff:foff + fsz]
            written.append((p_offset, p_offset + fsz))
        elif p_type == 0x6FFFFF01 and len(tail) >= p_filesz:
            out[p_offset:p_offset + p_filesz] = tail[:p_filesz]
            written.append((p_offset, p_offset + p_filesz))
    for i, p in enumerate(phdrs):
        p_type, p_flags, p_offset, p_vaddr, p_paddr, p_filesz, p_memsz, p_align = p
        if p_filesz == 0 or i in by_seg or p_type == 0x6FFFFF01:
            continue
        if not any(lo <= p_offset and p_offset + p_filesz <= hi for lo, hi in written):
            unsourced.append(i)
    if unsourced:
        log(f"warning: no data for program header(s) {unsourced}; left zero")
    info["unsourced_phdrs"] = unsourced
    return bytes(out), info


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("input", type=Path)
    ap.add_argument("output", type=Path)
    ap.add_argument("--quiet", action="store_true")
    a = ap.parse_args(argv)
    log = (lambda *x, **k: None) if a.quiet else print
    data = a.input.read_bytes()
    try:
        elf, info = unfself(data, log)
    except NotASelf as e:
        print(f"unfself: {a.input}: {e}", file=sys.stderr)
        return 2
    except EncryptedSelf as e:
        print(f"unfself: {a.input}: {e}; cannot convert", file=sys.stderr)
        return 3
    except ValueError as e:
        print(f"unfself: {a.input}: {e}", file=sys.stderr)
        return 1
    a.output.parent.mkdir(parents=True, exist_ok=True)
    a.output.write_bytes(elf)
    log(f"wrote {a.output} ({len(elf)} bytes)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
