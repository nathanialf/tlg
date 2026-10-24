#!/usr/bin/env bash
# Install the IP-safety scan and the match gate as git hooks (opt-in):
#   - pre-commit: refuses a local commit that breaks the gate
#   - pre-push:   refuses to push a ref whose tip fails the gate (the backstop
#                 for commits made with --no-verify)
# Re-run any time either hook body changes.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
GITDIR="$(cd "$ROOT" && git rev-parse --git-common-dir 2>/dev/null || true)"
case "$GITDIR" in "") GITDIR="$ROOT/.git" ;; /*) ;; *) GITDIR="$ROOT/$GITDIR" ;; esac
HOOK="$GITDIR/hooks/pre-commit"
PUSH_HOOK="$GITDIR/hooks/pre-push"

if [[ ! -d "$GITDIR" ]]; then
    echo "install_hooks: $ROOT is not a git repo (no git dir)" >&2
    exit 1
fi
mkdir -p "$GITDIR/hooks"

cat > "$HOOK" <<'EOF2'
#!/usr/bin/env bash
# Auto-installed by tools/install_hooks.sh. Runs, in order:
#   1. tools/check_no_rom.sh        IP-safety scan of the staged files
#   2. tools/check_dev_native.py    refuses crutches in the staged sources (inline
#                                   asm, register pins, codegen attributes and
#                                   pragmas, empty do-while, unexplained volatile)
#   3. tools/format.sh --check      staged C/C++ must be clang-formatted
#   4. tools/build.sh gate-all      for EVERY configured target: its base files
#                                   are required, then setup, ninja and the
#                                   match gate (tools/check_elf.py --gate)
#   5. tools/build.sh progress-all  refresh docs/<slug>/PROGRESS.md,
#                                   docs/<slug>/progress.json and README.md's
#                                   progress block, then `git add` them
#
# Steps 4 and 5 run only when a staged path can affect the build (src/,
# config/, tools/). Bypass with --no-verify only for a commit that cannot touch
# the build and when the build is known green.
set -e
ROOT="$(git rev-parse --show-toplevel)"

"$ROOT/tools/check_no_rom.sh"

# Staged sources must be developer-native: no construct that emits no bytes
# and exists to steer the compiler (CLAUDE.md, docs/MATCH.md "Crutches").
"$ROOT/.venv/bin/python" -I "$ROOT/tools/check_dev_native.py"

STAGED_SRC=$(git diff --cached --name-only --diff-filter=ACMR -z | tr '\0' '\n' |
    grep -E '^src/.*\.(c|cpp|cc|h|hpp|inl)$' || true)
if [[ -n "$STAGED_SRC" ]]; then
    # shellcheck disable=SC2086
    "$ROOT/tools/format.sh" --check $STAGED_SRC
fi

BUILD_SENSITIVE=$(git diff --cached --name-only -z | tr '\0' '\n' |
    grep -E '^(src/|config/|tools/)' || true)
if [[ -z "$BUILD_SENSITIVE" ]]; then
    exit 0
fi

echo "pre-commit: tools/build.sh gate-all ..."
if ! "$ROOT/tools/build.sh" gate-all; then
    echo "" >&2
    echo "pre-commit: GATE FAILED: a configured target's base files are missing," >&2
    echo "  or a function listed as matched no longer matches. Fix before committing;" >&2
    echo "  bypass with \`git commit --no-verify\` only if you understand why." >&2
    exit 1
fi

echo "pre-commit: tools/build.sh progress-all (refresh + stage progress) ..."
if "$ROOT/tools/build.sh" progress-all >/dev/null 2>&1; then
    (cd "$ROOT" && git add README.md docs/*/PROGRESS.md docs/*/progress.json) 2>/dev/null || true
else
    echo "pre-commit: progress regen failed (non-fatal): commit proceeds" >&2
fi
EOF2
chmod +x "$HOOK"
echo "Installed pre-commit hook at $HOOK"

cat > "$PUSH_HOOK" <<'EOF2'
#!/usr/bin/env bash
# Auto-installed by tools/install_hooks.sh. For each ref being pushed, check
# out its tip in a temporary worktree and run tools/build.sh gate-all there.
# `git push --no-verify` skips it.
set -e
ROOT="$(git rev-parse --show-toplevel)"
zero=0000000000000000000000000000000000000000
while read -r local_ref local_sha remote_ref remote_sha; do
    [[ "$local_sha" == "$zero" ]] && continue   # deleting a ref
    tmp="$(mktemp -d)"
    trap 'rm -rf "$tmp"; git -C "$ROOT" worktree prune' EXIT
    git -C "$ROOT" worktree add -q --detach "$tmp" "$local_sha"
    for d in .venv tools/cc tools/ext tools/ghidra baserom; do
        [[ -e "$ROOT/$d" ]] && ln -s "$ROOT/$d" "$tmp/$d"
    done
    echo "pre-push: gate-all on $local_ref ($local_sha)"
    if ! (cd "$tmp" && tools/build.sh gate-all); then
        echo "pre-push: GATE FAILED on $local_ref; refusing to push" >&2
        git -C "$ROOT" worktree remove --force "$tmp"
        exit 1
    fi
    git -C "$ROOT" worktree remove --force "$tmp"
done
EOF2
chmod +x "$PUSH_HOOK"
echo "Installed pre-push hook at $PUSH_HOOK"
