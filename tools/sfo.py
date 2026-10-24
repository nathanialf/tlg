#!/usr/bin/env python3
"""
sfo.py: read a PS4 param.sfo and print its fields (KEY=VALUE, one per line,
or --json). The format is public (PSDevWiki, "Param.sfo"): a header, an index
table of (key offset, format, length, max length, data offset), a key table
and a data table. Formats: 0x0004 utf8 special, 0x0204 utf8, 0x0404 uint32.
"""
from __future__ import annotations

import json
import struct
import sys
from pathlib import Path


def read_sfo(data: bytes) -> dict:
    magic, version, key_off, data_off, count = struct.unpack_from("<4sIIII", data, 0)
    if magic != b"\x00PSF":
        raise ValueError(f"not a PSF/SFO file (magic {magic!r})")
    out = {}
    for i in range(count):
        k_off, fmt, length, max_len, d_off = struct.unpack_from("<HHIII", data, 20 + 16 * i)
        key_end = data.index(b"\x00", key_off + k_off)
        key = data[key_off + k_off:key_end].decode("ascii")
        raw = data[data_off + d_off:data_off + d_off + length]
        if fmt == 0x0404:
            out[key] = struct.unpack("<I", raw[:4])[0]
        else:
            out[key] = raw.split(b"\x00", 1)[0].decode("utf-8", "replace")
    return out


def main(argv=None) -> int:
    argv = sys.argv[1:] if argv is None else argv
    as_json = "--json" in argv
    paths = [a for a in argv if a != "--json"]
    if len(paths) != 1 or paths[0] in ("-h", "--help"):
        print("usage: sfo.py <param.sfo> [--json]", file=sys.stderr)
        return 2
    d = read_sfo(Path(paths[0]).read_bytes())
    if as_json:
        print(json.dumps(d, indent=2, sort_keys=True))
    else:
        for k in sorted(d):
            v = d[k]
            print(f"{k}={v if not isinstance(v, int) else '0x%08X' % v}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
