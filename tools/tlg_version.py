"""Shared target-slug detection and per-target paths for the TLG tooling.

The targets:

    slug   package                                        executable
    ----   --------------------------------------------   ----------
    base   EU retail base game 1.00, CUSA03745            eboot.bin
           (EP9000-CUSA03745_00-LASTGUARDIANEU00)

One tree may carry several targets. A target is configured in a tree when
config/sha256sums.<slug>.txt exists (configured_versions()). Its other
per-target files are config/<stem>.<slug>.<ext>; its extracted base files are
baserom/<slug>/ (`baserom/` is gitignored and holds every target's files side
by side); its build is under build/<slug>/; its progress files are under
docs/<slug>/.

An explicit `VERSION` environment variable wins; otherwise the slug is the
first configured one in VERSIONS order, and `base` when none is.

PKGS is the one table of what each target's package is called and how the
tools name it in messages: the file (or symlink) the user places under
baserom/, the content id, the region description, and the executable and
modules tools/extract_pkg.py pulls out of it.

tools/tlg_version.sh is the shell twin of this module (same detection order,
same paths, same package table). Keep the two in sync.
"""
from __future__ import annotations
import os
from pathlib import Path

# Detection order.
VERSIONS = ("base",)

# Per-target package.
#   region     : how messages describe the package
#   content_id : the content id in its param.sfo
#   title_id   : the title id in its param.sfo
#   app_ver    : APP_VER in its param.sfo
#   image      : the file (or symlink) the user places under baserom/
#   executable : the executable's path inside the extracted package
#   modules    : the modules extracted beside it (prx, converted to ELF too)
PKGS = {
    "base": {
        "region": "EU retail base game 1.00",
        "content_id": "EP9000-CUSA03745_00-LASTGUARDIANEU00",
        "title_id": "CUSA03745",
        "app_ver": "01.00",
        "image": "TLG_BASE.pkg",
        "executable": "eboot.bin",
        "modules": "sce_module",
    },
}


def configured_versions(repo_root: Path) -> list[str]:
    """The slugs this tree carries recorded hashes for, in VERSIONS order."""
    return [v for v in VERSIONS
            if (repo_root / "config" / f"sha256sums.{v}.txt").exists()]


def detect_version(repo_root: Path) -> str:
    v = os.environ.get("VERSION")
    if v:
        return v
    have = configured_versions(repo_root)
    return have[0] if have else VERSIONS[0]


def baserom_dir(repo_root: Path, version: str) -> Path:
    """Directory holding this target's extracted base files."""
    return repo_root / "baserom" / version


def app_dir(repo_root: Path, version: str) -> Path:
    """The extracted package's filesystem, baserom/<slug>/app/."""
    return baserom_dir(repo_root, version) / "app"


def baseself_path(repo_root: Path, version: str) -> Path:
    """The executable as the package ships it (a fake-signed SELF)."""
    return baserom_dir(repo_root, version) / "eboot.bin"


def baseelf_path(repo_root: Path, version: str) -> Path:
    """The executable converted to a plain ELF (tools/unfself.py)."""
    return baserom_dir(repo_root, version) / "eboot.elf"


def modules_dir(repo_root: Path, version: str) -> Path:
    """The package's sce_module/ prx files and their ELF conversions."""
    return baserom_dir(repo_root, version) / "modules"


def config_path(repo_root: Path, version: str, stem: str, ext: str) -> Path:
    """config/<stem>.<version>.<ext>, e.g. config/functions.base.txt."""
    return repo_root / "config" / f"{stem}.{version}.{ext}"


def build_dir(repo_root: Path, version: str) -> Path:
    """This target's build directory, build/<version>."""
    return repo_root / "build" / version


def sha256sums_path(repo_root: Path, version: str) -> Path:
    """The recorded SHA-256s of this target's base files,
    config/sha256sums.<version>.txt (keyed by basename)."""
    return repo_root / "config" / f"sha256sums.{version}.txt"


def docs_dir(repo_root: Path, version: str) -> Path:
    """This target's progress files, docs/<version>/ (PROGRESS.md,
    progress.json)."""
    return repo_root / "docs" / version


def pkg_name(version: str) -> str:
    """The package as messages name it, e.g.
    `EU retail base game 1.00 (CUSA03745)` ("" for a slug with no PKGS row)."""
    d = PKGS.get(version)
    if d is None:
        return ""
    return f"{d['region']} ({d['title_id']})"


def pkg_image(repo_root: Path, version: str) -> Path | None:
    """The package file the user places under baserom/ for this target."""
    d = PKGS.get(version)
    return repo_root / "baserom" / d["image"] if d else None


def _rel(p, root):
    return "" if p is None else p.relative_to(root)


_KEYS = {
    "version": lambda root, v: v,
    "baserom_dir": lambda root, v: baserom_dir(root, v).relative_to(root),
    "app_dir": lambda root, v: app_dir(root, v).relative_to(root),
    "baseself": lambda root, v: baseself_path(root, v).relative_to(root),
    "baseelf": lambda root, v: baseelf_path(root, v).relative_to(root),
    "modules_dir": lambda root, v: modules_dir(root, v).relative_to(root),
    "pkg": lambda root, v: _rel(pkg_image(root, v), root),
    "pkg_name": lambda root, v: pkg_name(v),
    "content_id": lambda root, v: PKGS[v]["content_id"] if v in PKGS else "",
    "build_dir": lambda root, v: build_dir(root, v).relative_to(root),
    "sha256sums": lambda root, v: sha256sums_path(root, v).relative_to(root),
    "docs_dir": lambda root, v: docs_dir(root, v).relative_to(root),
    "versions": lambda root, v: " ".join(configured_versions(root)),
}


def main(argv: list[str] | None = None) -> int:
    import sys
    argv = list(sys.argv[1:] if argv is None else argv)
    root = Path(__file__).resolve().parent.parent
    ver = detect_version(root)
    if not argv:
        for k, fn in _KEYS.items():
            print(f"TLG_{k.upper()}={fn(root, ver)}")
        return 0
    for key in argv:
        if key not in _KEYS:
            print(f"tlg_version: unknown key '{key}' (have: {', '.join(_KEYS)})",
                  file=sys.stderr)
            return 2
        print(_KEYS[key](root, ver))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
