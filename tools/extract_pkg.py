#!/usr/bin/env python3
"""
extract_pkg.py: pull the target's executable, modules and param.sfo out of
the user's own PKG and record their SHA-256s.

    baserom/TLG_BASE.pkg (file or symlink)
      -> baserom/base/app/uroot/      the package's filesystem (PkgTool.Core
                                      pkg_extract; skipped when eboot.bin is
                                      already there; 25 GB for this title)
      -> baserom/base/eboot.bin       the executable as shipped (fake-signed SELF)
      -> baserom/base/eboot.elf       converted to a plain ELF (tools/unfself.py)
      -> baserom/base/param.sfo       the package's metadata, and param.sfo.txt
      -> baserom/base/modules/*.prx   sce_module/, and each one's .elf
      -> config/sha256sums.base.txt   recorded on first run, verified after

The PKG extractor is LibOrbisPkg's PkgTool.Core (MIT; tools/setup.sh fetches
the pinned framework-dependent build into tools/ext/pkgtool/ and a .NET 8
runtime into tools/ext/dotnet/ to run it on). It handles packages signed
with the public debug keys, which is what a homebrew-packaged dump is. A
retail-signed package, or an executable whose segments are encrypted, stops
this script: no key material exists here and none is wanted.

Reads no copyrighted material into the repository: everything it writes but
the hashes lives under baserom/, which is gitignored. The hashes identify the
files; they are not the files.

Options:
    --no-pkg-hash   skip hashing the 12 GB package itself (the executable,
                    modules and param.sfo are still hashed)
    --force-extract rerun pkg_extract even if app/eboot.bin exists
"""
from __future__ import annotations

import argparse
import hashlib
import os
import shutil
import subprocess
import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(Path(__file__).resolve().parent))
from tlg_version import (PKGS, app_dir, baseelf_path, baserom_dir, baseself_path,  # noqa: E402
                         detect_version, modules_dir, pkg_image, pkg_name,
                         sha256sums_path)
from unfself import EncryptedSelf, NotASelf, unfself  # noqa: E402
from sfo import read_sfo  # noqa: E402

DOTNET = REPO_ROOT / "tools" / "ext" / "dotnet" / "dotnet"
PKGTOOL = REPO_ROOT / "tools" / "ext" / "pkgtool" / "PkgTool.Core.dll"
SELF_MAGIC = b"\x4f\x15\x3d\x1d"
ELF_MAGIC = b"\x7fELF"


def sha256_of(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as f:
        for chunk in iter(lambda: f.read(1 << 22), b""):
            h.update(chunk)
    return h.hexdigest()


def load_sums(path: Path) -> dict[str, str]:
    out = {}
    if path.exists():
        for line in path.read_text().splitlines():
            s = line.strip()
            if s and not s.startswith("#"):
                parts = s.split()
                if len(parts) >= 2:
                    out[parts[1]] = parts[0]
    return out


def record_or_verify(sums_path: Path, name: str, actual: str, created: list[str]) -> bool:
    """Append `actual  name` when unrecorded; compare when recorded. False on
    mismatch."""
    sums = load_sums(sums_path)
    if name in sums:
        if sums[name] != actual:
            print(f"extract_pkg: SHA-256 MISMATCH for {name}\n"
                  f"  recorded: {sums[name]}\n  actual:   {actual}\n"
                  f"  The recorded hashes are never edited. Is this the same package "
                  f"({sums_path.relative_to(REPO_ROOT)})?", file=sys.stderr)
            return False
        print(f"  {name}: OK ({actual[:16]}...)")
        return True
    if not sums_path.exists():
        sums_path.parent.mkdir(parents=True, exist_ok=True)
        sums_path.write_text(
            "# SHA-256 of the target's base files, keyed by basename. Written once by\n"
            "# tools/extract_pkg.py from the user's own package; verified by\n"
            "# tools/verify_elf.py. NEVER EDIT: a mismatch means a different package\n"
            "# or a changed tool, and either is a finding, not a typo.\n")
    with sums_path.open("a") as f:
        f.write(f"{actual}  {name}\n")
    created.append(name)
    print(f"  {name}: recorded {actual[:16]}...")
    return True


def convert(src: Path, dst: Path) -> str:
    """fSELF -> ELF, or copy when already an ELF. Returns 'self', 'elf'."""
    with src.open("rb") as f:
        magic = f.read(4)
    if magic == ELF_MAGIC:
        shutil.copyfile(src, dst)
        return "elf"
    if magic != SELF_MAGIC:
        raise SystemExit(f"extract_pkg: {src}: magic {magic.hex()} is neither SELF nor ELF")
    try:
        elf, info = unfself(src.read_bytes(), log=lambda *a, **k: None)
    except EncryptedSelf as e:
        raise SystemExit(
            f"extract_pkg: {src}: {e}.\n"
            "  This is a retail-signed executable. The project needs a package whose\n"
            "  executable is fake-signed (unencrypted). Stopping.") from e
    except (NotASelf, ValueError) as e:
        raise SystemExit(f"extract_pkg: {src}: {e}") from e
    if info.get("unsourced_phdrs"):
        print(f"  warning: {src.name}: program headers {info['unsourced_phdrs']} had no data")
    dst.write_bytes(elf)
    return "self"


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--no-pkg-hash", action="store_true")
    ap.add_argument("--force-extract", action="store_true")
    a = ap.parse_args(argv)

    ver = detect_version(REPO_ROOT)
    if ver not in PKGS:
        print(f"extract_pkg: target '{ver}' has no package recipe in tools/tlg_version.py",
              file=sys.stderr)
        return 2
    pkg = pkg_image(REPO_ROOT, ver)
    base = baserom_dir(REPO_ROOT, ver)
    app = app_dir(REPO_ROOT, ver)
    sums_path = sha256sums_path(REPO_ROOT, ver)
    rel = lambda p: p.relative_to(REPO_ROOT)  # noqa: E731

    if not pkg.exists():
        print(f"extract_pkg: {rel(pkg)} is missing.\n"
              f"  Point it at your own copy of the {pkg_name(ver)} package:\n"
              f"    mkdir -p baserom\n"
              f"    ln -s \"/path/to/your/{PKGS[ver]['title_id']}.pkg\" {rel(pkg)}\n"
              f"  Nothing under baserom/ is ever committed.", file=sys.stderr)
        return 1

    # PkgTool writes the PFS tree under <out>/uroot/.
    root = app / "uroot"
    exe_in_app = root / PKGS[ver]["executable"]
    env = dict(os.environ, DOTNET_ROLL_FORWARD="Major", DOTNET_CLI_TELEMETRY_OPTOUT="1",
               DOTNET_NOLOGO="1")
    if a.force_extract or not exe_in_app.exists():
        if not PKGTOOL.exists() or not DOTNET.exists():
            print(f"extract_pkg: {rel(PKGTOOL)} or {rel(DOTNET)} is missing; run tools/setup.sh",
                  file=sys.stderr)
            return 1
        app.mkdir(parents=True, exist_ok=True)
        print(f"==> extracting {rel(pkg)} to {rel(app)} (PkgTool.Core pkg_extract; "
              f"this is the whole package, several minutes)")
        # PkgTool.Core targets netcoreapp3.0; it runs on the .NET 8 runtime
        # tools/setup.sh installs under tools/ext/dotnet/ with roll-forward.
        r = subprocess.run([str(DOTNET), str(PKGTOOL), "pkg_extract",
                            str(pkg.resolve()), str(app)], cwd=REPO_ROOT, env=env)
        if r.returncode != 0:
            print(f"extract_pkg: pkg_extract failed (exit {r.returncode})", file=sys.stderr)
            return 1
        if not exe_in_app.exists():
            print(f"extract_pkg: pkg_extract finished but {rel(exe_in_app)} is missing",
                  file=sys.stderr)
            return 1
    else:
        print(f"==> {rel(app)} already extracted (--force-extract to redo)")

    base.mkdir(parents=True, exist_ok=True)
    mods = modules_dir(REPO_ROOT, ver)
    mods.mkdir(exist_ok=True)

    # The executable, as shipped and as a plain ELF.
    bself = baseself_path(REPO_ROOT, ver)
    belf = baseelf_path(REPO_ROOT, ver)
    shutil.copyfile(exe_in_app, bself)
    kind = convert(bself, belf)
    print(f"==> {rel(bself)}: {'fake-signed SELF, converted' if kind == 'self' else 'already an ELF, copied'}"
          f" -> {rel(belf)} ({belf.stat().st_size} bytes)")

    # param.sfo is a PKG entry (PARAM_SFO, index 11 in a pkg_listentries
    # listing), not a PFS file; pull it with pkg_extractentry.
    sfo = base / "param.sfo"
    if not sfo.exists():
        r = subprocess.run([str(DOTNET), str(PKGTOOL), "pkg_extractentry", str(pkg.resolve()),
                            "11", str(sfo)], cwd=REPO_ROOT, env=env, capture_output=True)
        if r.returncode != 0 or not sfo.exists() or sfo.read_bytes()[:4] != b"\x00PSF":
            print("  warning: could not extract PARAM_SFO entry from the package")
            sfo.unlink(missing_ok=True)
    if sfo.exists():
        fields = read_sfo(sfo.read_bytes())
        (base / "param.sfo.txt").write_text(
            "".join(f"{k}={fields[k] if not isinstance(fields[k], int) else '0x%08X' % fields[k]}\n"
                    for k in sorted(fields)))
        want = PKGS[ver]
        got = (fields.get("CONTENT_ID"), fields.get("APP_VER"))
        print(f"==> param.sfo: CONTENT_ID={got[0]} TITLE_ID={fields.get('TITLE_ID')} "
              f"APP_VER={got[1]} VERSION={fields.get('VERSION')} "
              f"SYSTEM_VER=0x{fields.get('SYSTEM_VER', 0):08X}")
        if got != (want["content_id"], want["app_ver"]):
            print(f"extract_pkg: this package is not the {pkg_name(ver)} target "
                  f"(expected CONTENT_ID {want['content_id']} APP_VER {want['app_ver']})",
                  file=sys.stderr)
            return 1

    # Modules.
    mod_src = root / PKGS[ver]["modules"]
    prx_files = sorted(mod_src.glob("*.prx")) + sorted(mod_src.glob("*.sprx")) \
        if mod_src.is_dir() else []
    for p in prx_files:
        dst = mods / p.name
        shutil.copyfile(p, dst)
        try:
            convert(dst, dst.with_suffix(".elf"))
        except SystemExit as e:
            print(f"  warning: {p.name}: {e}")
    print(f"==> {len(prx_files)} module(s) in {rel(mods)}")

    # Hashes: record on first run, verify after.
    print(f"==> hashes ({rel(sums_path)})")
    created: list[str] = []
    ok = True
    if not a.no_pkg_hash:
        ok &= record_or_verify(sums_path, PKGS[ver]["image"], sha256_of(pkg), created)
    for f in [bself, belf] + ([sfo] if sfo.exists() else []):
        ok &= record_or_verify(sums_path, f.name, sha256_of(f), created)
    for p in prx_files:
        for f in (mods / p.name, (mods / p.name).with_suffix(".elf")):
            if f.exists():
                ok &= record_or_verify(sums_path, f.name, sha256_of(f), created)
    if created:
        print(f"==> recorded {len(created)} new hash(es); commit {rel(sums_path)}")
    if not ok:
        return 1
    print("extract_pkg: done")
    return 0


if __name__ == "__main__":
    sys.exit(main())
