"""Summarise match_check.py --json lines: `<equal>/<n> equal  <func>=<score> ...`."""
import json
import sys

rows = [json.loads(l) for l in sys.stdin if l.strip()]
eq = sum(1 for r in rows if r["score"] == 1.0)
print(f"{eq}/{len(rows)} equal  " + " ".join(f"{r['func'][-5:]}={r['score']:.2f}" for r in rows))
