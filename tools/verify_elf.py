#!/usr/bin/env python3
"""
verify_elf.py: confirm the SHA-256 of an extracted or built artifact matches
the value recorded in config/sha256sums.<ver>.txt.

tools/build.sh verify runs it on the base executable and its ELF conversion.
Exits 0 on match, non-zero on mismatch or missing target.

Each target records its own hashes in config/sha256sums.<ver>.txt, keyed by
BASENAME (eboot.bin / eboot.elf / param.sfo / <module>.prx / <module>.elf), so
the same lookup works for every target's baserom/<ver>/ (tools/tlg_version.py;
<ver> is VERSION, or the first configured target). The hashes are written once
by tools/extract_pkg.py and never edited.

    verify_elf.py --target baserom/<ver>/eboot.elf
"""

from __future__ import annotations

import argparse
import hashlib
import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(Path(__file__).resolve().parent))
from tlg_version import detect_version, sha256sums_path  # noqa: E402

VERSION = detect_version(REPO_ROOT)
SHA256SUMS = sha256sums_path(REPO_ROOT, VERSION)


def load_recorded(name: str, sums: Path = SHA256SUMS) -> str | None:
    if not sums.exists():
        return None
    for line in sums.read_text().splitlines():
        line = line.strip()
        if not line or line.startswith("#"):
            continue
        parts = line.split()
        if len(parts) >= 2 and parts[1] == name:
            return parts[0]
    return None


def sha256_of(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as f:
        for chunk in iter(lambda: f.read(1 << 22), b""):
            h.update(chunk)
    return h.hexdigest()


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--target", required=True, type=Path,
                    help="path to artifact to verify")
    args = ap.parse_args(argv)

    target: Path = args.target
    if not target.exists():
        print(f"verify_elf: target not found: {target}", file=sys.stderr)
        return 2

    name = target.name
    recorded = load_recorded(name)
    if recorded is None:
        print(
            f"verify_elf: no recorded SHA-256 for '{name}' in "
            f"{SHA256SUMS.relative_to(REPO_ROOT)}.\n"
            "  Run tools/extract_pkg.sh first to record it.",
            file=sys.stderr,
        )
        return 3

    actual = sha256_of(target)
    if actual == recorded:
        print(f"verify_elf: OK ({target} sha256={actual})")
        return 0

    print(
        f"verify_elf: MISMATCH\n"
        f"  target:   {target}\n"
        f"  expected: {recorded}\n"
        f"  actual:   {actual}\n"
        f"  The recorded hashes are never edited; re-extract from the package.",
        file=sys.stderr,
    )
    return 1


if __name__ == "__main__":
    sys.exit(main())
