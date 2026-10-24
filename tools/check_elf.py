#!/usr/bin/env python3
"""
check_elf.py: the match gate and the progress files.

  --gate      Every row of config/matched.<slug>.txt (`<function> <tu> [<symbol>]`)
              is compiled (tools/compile_cpp.sh, or the object ninja built under
              build/<slug>/obj/) and compared with the base executable at the
              function's address (tools/match_check.py): every instruction
              equal, the linker-filled fields masked and then checked for real
              where the base can place the symbol. Then the whole text segment
              is rebuilt (tools/layout_link.py): the claimed functions laid out
              at their addresses with relocations resolved, the rest from the
              base, and compared with the base byte for byte. Any row below
              1.0, any wrong target, any differing byte, any row naming an
              unknown function or symbol fails the gate. Exit 1 on failure.

  --progress  The same comparison, then docs/<slug>/progress.json (the
              dashboard's data, schema 2), the table between the
              `<!-- progress:begin -->` / `<!-- progress:end -->` markers in
              docs/<slug>/PROGRESS.md and README.md's badge row.

Progress counts functions and their bytes: config/functions.<slug>.txt lists
every function of the executable (tools/survey_elf.py); a function is matched
when a matched.<slug>.txt row for it scores 1.0. The dashboard tree groups the
claimed functions by the top-level directory of their TU under src/, and the
unclaimed ones under `unassigned`, in 1 MiB address ranges.
"""
from __future__ import annotations

import argparse
import json
import re
import subprocess
import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(Path(__file__).resolve().parent))
from tlg_version import (PKGS, VERSIONS, baseelf_path, build_dir, config_path, detect_version,  # noqa: E402
                         docs_dir, pkg_name)
from survey_elf import read_phdrs, vaddr_to_off, PT_LOAD  # noqa: E402
from base_elf import BaseElf  # noqa: E402
import match_check as mc  # noqa: E402
import layout_link  # noqa: E402

VERSION = detect_version(REPO_ROOT)
DASHBOARD = "https://nathanialf.github.io/tlg/"
README = REPO_ROOT / "README.md"
PROGRESS_DOC = docs_dir(REPO_ROOT, VERSION) / "PROGRESS.md"
PROGRESS_JSON = docs_dir(REPO_ROOT, VERSION) / "progress.json"
BUCKET = 1 << 20


def load_matched() -> list[tuple[str, str, str]]:
    p = config_path(REPO_ROOT, VERSION, "matched", "txt")
    rows = []
    if p.exists():
        for line in p.read_text().splitlines():
            s = line.split("#", 1)[0].split()
            if len(s) >= 2:
                rows.append((s[0], s[1], s[2] if len(s) > 2 else s[0]))
    return rows


def load_functions_ordered() -> list[tuple[int, int, str]]:
    p = config_path(REPO_ROOT, VERSION, "functions", "txt")
    out = []
    for line in p.read_text().splitlines():
        s = line.split("#", 1)[0].split()
        if len(s) >= 3:
            out.append((int(s[0], 16), int(s[1], 16), s[2]))
    return out


def check_all() -> tuple[dict[str, dict], bool]:
    """Compile and compare every matched row. Returns ({func: result}, all_ok)."""
    funcs = {n: (a, s) for a, s, n in load_functions_ordered()}
    base = BaseElf(REPO_ROOT, VERSION)
    data, phdrs = base.data, base.phdrs
    rows = load_matched()
    by_tu: dict[str, list[tuple[str, str]]] = {}
    for fn, tu, sym in rows:
        by_tu.setdefault(tu, []).append((fn, sym))
    results: dict[str, dict] = {}
    ok = True
    for tu, pairs in sorted(by_tu.items()):
        if not (REPO_ROOT / tu).exists():
            print(f"check_elf: {tu} does not exist (claimed by {', '.join(f for f, _ in pairs)})",
                  file=sys.stderr)
            ok = False
            continue
        try:
            obj = mc.compile_tu(tu, VERSION)
        except subprocess.CalledProcessError:
            print(f"check_elf: {tu} failed to compile", file=sys.stderr)
            ok = False
            continue
        objfuncs = mc.object_functions(obj)
        for fn, sym in pairs:
            if fn not in funcs:
                print(f"check_elf: {fn} is not a row of config/functions.{VERSION}.txt", file=sys.stderr)
                ok = False
                continue
            sym = mc.resolve_symbol(objfuncs, sym and sym or fn, sym) or sym
            if sym not in objfuncs:
                print(f"check_elf: {tu} does not define {sym} (for {fn})", file=sys.stderr)
                ok = False
                continue
            addr, size = funcs[fn]
            off = vaddr_to_off(phdrs, addr)
            r = mc.compare(*objfuncs[sym], data[off:off + size], addr, base)
            results[fn] = {"tu": tu, "symbol": sym, "score": r["score"], "equal": r["equal"],
                           "insns": max(r["obj_insns"], r["base_insns"]), "size": size,
                           "targets_ok": r["targets_ok"], "bad_targets": r["bad_targets"]}
            if r["score"] < 1.0 or not r["targets_ok"]:
                ok = False
    return results, ok


def run_gate(_args) -> int:
    results, ok = check_all()
    print(f"gate ({VERSION}): {len(results)} claimed function(s)")
    for fn, r in sorted(results.items(), key=lambda kv: kv[1]["tu"]):
        if r["score"] == 1.0 and r["targets_ok"]:
            flag = "equal"
        elif r["score"] == 1.0:
            flag = "WRONG TARGET " + "; ".join(r["bad_targets"])
        else:
            flag = f"DIFFERS {r['equal']}/{r['insns']} ({r['score']:.4f})"
        print(f"  {fn:<40} {r['tu']:<48} {flag}")
    # the whole-text gate: every claimed function laid out at its address with
    # its relocations resolved, the rest of the segment from the base, and the
    # image compared with the base byte for byte (tools/layout_link.py)
    lay = layout_link.build_image(VERSION)
    for fn, why in sorted(lay["errors"].items()):
        print(f"  LAYOUT ERROR {fn}: {why}")
    for name, sg in lay["segments"].items():
        for d in sg["differing"]:
            print(f"  LAYOUT DIFFERS {name} {d['name']}: {d['bytes']} byte(s)")
        if sg["gap_bytes_differing"]:
            print(f"  LAYOUT DIFFERS {name} outside claimed objects: {sg['gap_bytes_differing']} byte(s)")
        print(f"  {name:<7} {sg['filesz']:>12,} bytes, {sg['from_source']:,} from source"
              + (f", NOBITS {sg['nobits']:,} ({sg['owned_nobits']:,} owned)" if sg["nobits"] else "")
              + f": {'IDENTICAL to the base' if sg['identical'] else 'DIFFERS'}")
    print(f"  {len(lay['data'])} data object(s), "
          f"{sum(f['relocs'] for f in list(lay['functions'].values()) + list(lay['data'].values()))} relocation(s) resolved")
    if not ok or not lay["identical"]:
        print("gate: FAILED", file=sys.stderr)
        return 1
    print("gate: OK")
    return 0


# ----- --progress ------------------------------------------------------------

def build_tree(results: dict[str, dict]) -> dict:
    funcs = load_functions_ordered()
    data = baseelf_path(REPO_ROOT, VERSION).read_bytes()
    phdrs = read_phdrs(data)
    text = next(p for p in phdrs if p["type"] == PT_LOAD and p["flags"] & 1)
    matched_rows = {fn: (tu, sym) for fn, tu, sym in load_matched()}

    groups: dict[str, dict[str, dict]] = {}
    for addr, size, name in funcs:
        matched = name in results and results[name]["score"] == 1.0 and results[name]["targets_ok"]
        if name in matched_rows:
            tu = matched_rows[name][0]
            parts = tu.split("/")
            grp = parts[1] if len(parts) > 2 else parts[0]
            tu_name = "/".join(parts[2:]) if len(parts) > 2 else tu
            tu_path = tu
        else:
            lo = addr - addr % BUCKET
            grp = "unassigned"
            tu_name = f"0x{lo:08x}-0x{lo + BUCKET - 1:08x}"
            tu_path = f"unassigned/{tu_name}"
        node = groups.setdefault(grp, {}).setdefault(
            tu_path, {"name": tu_name, "path": tu_path, "funcs": []})
        node["funcs"].append({"name": name, "addr": f"0x{addr:08X}", "size": size,
                              "section": ".text", "matched": matched})

    prog_list = []
    tot_mf = tot_f = tot_mb = tot_b = 0
    for grp in sorted(groups, key=lambda g: (g == "unassigned", g)):
        tus = []
        pmf = pf = pmb = pb = 0
        for t in sorted(groups[grp].values(), key=lambda t: t["path"]):
            fs = sorted(t["funcs"], key=lambda f: f["addr"])
            mf = sum(1 for f in fs if f["matched"])
            mb = sum(f["size"] for f in fs if f["matched"])
            b = sum(f["size"] for f in fs)
            tus.append({"name": t["name"], "path": t["path"], "matched_funcs": mf,
                        "total_funcs": len(fs), "matched_bytes": mb, "total_bytes": b,
                        "funcs": fs})
            pmf += mf; pf += len(fs); pmb += mb; pb += b
        entry = {"name": grp, "matched_funcs": pmf, "total_funcs": pf,
                 "matched_bytes": pmb, "total_bytes": pb, "tus": tus}
        if grp == "unassigned":
            entry["note"] = ("functions no source file claims yet, in 1 MiB address ranges; "
                             "a function moves to its TU's group when it is matched")
        prog_list.append(entry)
        tot_mf += pmf; tot_f += pf; tot_mb += pmb; tot_b += pb

    lay = layout_link.build_image(VERSION, log=lambda *a, **k: None)
    sections: dict[str, list[int]] = {}
    extracted: dict[str, int] = {}
    for name, sg in lay["segments"].items():
        # from source / total; the rest of the segment is taken from the user's
        # own executable at build time, the "extracted" share of ico's schema
        sections[name] = [sg["from_source"], sg["filesz"]]
        extracted[name] = sg["from_base"]
        if sg["nobits"] and name == ".data":   # the RELRO's tail is padding, not .bss
            sections[".bss"] = [sg["owned_nobits"], sg["nobits"]]
            extracted[".bss"] = 0
    return {
        "schema": 2,
        "version": VERSION,
        "totals": {
            "matched_funcs": tot_mf, "total_funcs": tot_f, "stub_funcs": 0,
            "matched_bytes": tot_mb, "total_bytes": text["filesz"],
            "sections": sections,
            "extracted": extracted,
            "nobits_sections": [".bss"] if ".bss" in sections else [],
            "sections_from_symbols": {".text": [tot_mb, tot_b]},
            "segments_identical": lay["identical"],
            "data_objects": len(lay["data"]),
        },
        "programmers": prog_list,
    }


def _fmt_pct(m: int, t: int) -> str:
    return "-" if t == 0 else f"{100.0 * m / t:.2f} %"


def _badge_color(m: int, t: int) -> str:
    if t == 0:
        return "lightgrey"
    pct = 100.0 * m / t
    for floor, color in ((100.0, "brightgreen"), (75.0, "green"),
                         (50.0, "yellowgreen"), (25.0, "yellow")):
        if pct >= floor:
            return color
    return "orange" if pct > 0.0 else "red"


def _badge(label: str, m: int, t: int) -> str:
    from urllib.parse import quote
    msg = quote(_fmt_pct(m, t), safe="").replace("-", "%2D")
    url = f"https://img.shields.io/badge/{label}-{msg}-{_badge_color(m, t)}.svg"
    return f"![{label} progress]({url})"


def _badges(t: dict) -> str:
    out = [_badge("functions", t["matched_funcs"], t["total_funcs"])]
    for sec, (m, tot) in t["sections"].items():
        if tot:
            out.append(_badge(sec.lstrip("."), m, tot))
    return " ".join(out)


def _table(tree: dict) -> str:
    t = tree["totals"]
    text = t["sections"][".text"]
    fb = t["sections_from_symbols"][".text"]
    lines = ["| Measure | From source | Total | % |", "| --- | ---: | ---: | ---: |",
             f"| functions | {t['matched_funcs']} | {t['total_funcs']} | "
             f"{_fmt_pct(t['matched_funcs'], t['total_funcs'])} |",
             f"| bytes in functions | {fb[0]} | {fb[1]} | {_fmt_pct(fb[0], fb[1])} |"]
    for sec, (m, tot) in t["sections"].items():
        kind = " (owned)" if sec in t.get("nobits_sections", []) else ""
        lines.append(f"| `{sec}` segment bytes{kind} | {m} | {tot} | {_fmt_pct(m, tot)} |")
    lines += ["",
             "Every loaded segment of the executable is rebuilt (`tools/layout_link.py`): the bytes "
             "**from source** are the claimed functions and data objects laid out at their addresses "
             "with relocations resolved; the rest is taken from the user's own executable at build "
             "time, and the whole must equal the base byte for byte, which the gate requires. "
             "`.bss` holds no file bytes, so its figure is ownership: how much of it a claimed object "
             "defines.",
             "",
             "A function is **matched** when its compiled instructions equal the base "
             "executable's at its address, with only the fields the linker fills (RIP-relative "
             "displacements, call targets, GOT and PLT slots) masked (`tools/match_check.py`). "
             "The function list and sizes come from the executable's own unwind tables "
             "(`tools/survey_elf.py`, `config/functions.base.txt`); the `.text` row's total is "
             "the whole executable segment, including the bytes between functions.",
             "", "| Group | Matched functions | Total | Matched bytes | Total bytes |",
             "| --- | ---: | ---: | ---: | ---: |"]
    for p in tree["programmers"]:
        lines.append(f"| `{p['name']}` | {p['matched_funcs']} | {p['total_funcs']} | "
                     f"{p['matched_bytes']} | {p['total_bytes']} |")
    return "\n".join(lines)


BEGIN, END = "<!-- progress:begin -->", "<!-- progress:end -->"

PROGRESS_SKELETON = """# Progress: {name}

How much of the executable is rebuilt from source and matches. Generated by
`tools/check_elf.py --progress`; the dashboard is `docs/index.html`.

<!-- progress:begin -->
<!-- progress:end -->
"""


def _readme_block(tree: dict) -> str:
    rows = {}
    for js in sorted((REPO_ROOT / "docs").glob("*/progress.json")):
        slug = js.parent.name
        if slug == VERSION:
            continue
        try:
            rows[slug] = json.loads(js.read_text())["totals"]
        except (OSError, ValueError, KeyError):
            continue
    rows[VERSION] = tree["totals"]
    order = sorted(rows, key=lambda v: (VERSIONS.index(v) if v in VERSIONS else len(VERSIONS), v))
    lines = ["| Target | Matched |", "| --- | --- |"]
    for slug in order:
        lines.append(f"| [{pkg_name(slug) or slug}]({DASHBOARD}#{slug}) | {_badges(rows[slug])} |")
    return "\n".join(lines)


def _splice(path: Path, body: str) -> bool:
    text = path.read_text()
    if BEGIN not in text or END not in text:
        sys.exit(f"check_elf: {path} has no {BEGIN} / {END} markers")
    pat = re.compile(re.escape(BEGIN) + r".*?" + re.escape(END), re.DOTALL)
    new = pat.sub(lambda _: BEGIN + "\n" + body + "\n" + END, text)
    if new == text:
        return False
    path.write_text(new)
    return True


def run_progress(args) -> int:
    results, _ok = check_all()
    tree = build_tree(results)
    t = tree["totals"]
    print(f"progress ({VERSION}): {t['matched_funcs']}/{t['total_funcs']} functions, "
          f"{t['matched_bytes']}/{t['total_bytes']} .text bytes "
          f"({_fmt_pct(t['matched_bytes'], t['total_bytes'])})")
    out = Path(args.out_dir) if args.out_dir else None
    readme = (out / "README.md") if out else README
    doc = (out / "PROGRESS.md") if out else PROGRESS_DOC
    js = (out / "progress.json") if out else PROGRESS_JSON
    if out:
        out.mkdir(parents=True, exist_ok=True)
        readme.write_text(README.read_text())
        doc.write_text(PROGRESS_DOC.read_text() if PROGRESS_DOC.exists()
                       else PROGRESS_SKELETON.format(name=pkg_name(VERSION)))
    elif not doc.exists():
        doc.parent.mkdir(parents=True, exist_ok=True)
        doc.write_text(PROGRESS_SKELETON.format(name=pkg_name(VERSION)))
    for path, body in ((readme, _readme_block(tree)), (doc, _table(tree))):
        print(f"check_elf: {'rewrote' if _splice(path, body) else 'unchanged'} {path.relative_to(REPO_ROOT) if path.is_relative_to(REPO_ROOT) else path}")
    js.write_text(json.dumps(tree, separators=(",", ":")) + "\n")
    print(f"check_elf: wrote {js.relative_to(REPO_ROOT) if js.is_relative_to(REPO_ROOT) else js}")
    return 0


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    mode = ap.add_mutually_exclusive_group(required=True)
    mode.add_argument("--gate", action="store_true")
    mode.add_argument("--progress", action="store_true")
    ap.add_argument("--out-dir", help="--progress: write the three files here instead")
    args = ap.parse_args()
    if not baseelf_path(REPO_ROOT, VERSION).exists():
        sys.exit(f"check_elf: {baseelf_path(REPO_ROOT, VERSION)} not found; run ./build.sh")
    return run_gate(args) if args.gate else run_progress(args)


if __name__ == "__main__":
    sys.exit(main())
