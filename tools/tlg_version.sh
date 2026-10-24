# tools/tlg_version.sh: shell twin of tools/tlg_version.py.
#
# Source it and call `tlg_version_init [repo_root]`; it exports:
#   TLG_VERSION      target slug (base)
#   TLG_BASEROM_DIR  baserom/<slug>
#   TLG_APP_DIR      baserom/<slug>/app, the extracted package filesystem
#   TLG_BASESELF     baserom/<slug>/eboot.bin, the executable as shipped
#   TLG_BASEELF      baserom/<slug>/eboot.elf, converted to a plain ELF
#   TLG_MODULES_DIR  baserom/<slug>/modules, the prx files and their ELFs
#   TLG_PKG          the package the user places under baserom/
#   TLG_PKG_NAME     the package as messages name it
#   TLG_CONTENT_ID   its content id
#   TLG_BUILD_DIR    build/<slug>
#   TLG_SHA256SUMS   config/sha256sums.<slug>.txt
#   TLG_DOCS_DIR     docs/<slug>
#   TLG_VERSIONS     every configured slug (a config/sha256sums.<slug>.txt
#                    exists), space-separated, in detection order
# All paths are repo-root-relative. An explicit VERSION environment variable
# wins, otherwise the slug is the first configured one, and `base` when none
# is. No python and no .venv dependency, so the shell tools can source it
# before the venv exists. Keep in sync with tools/tlg_version.py.

tlg_version_configured() {
    local root="${1:-.}" v
    for v in base; do
        if [ -f "$root/config/sha256sums.$v.txt" ]; then printf '%s\n' "$v"; fi
    done
}

tlg_version_detect() {
    local root="${1:-.}" v
    if [ -n "${VERSION:-}" ]; then printf '%s\n' "$VERSION"; return 0; fi
    v="$(tlg_version_configured "$root" | head -n 1)"
    printf '%s\n' "${v:-base}"
}

# tlg_version_pkg <version>: sets TLG_PKG, TLG_PKG_NAME and TLG_CONTENT_ID
# (all empty for a slug with no package recipe).
tlg_version_pkg() {
    local region="" title="" image=""
    TLG_CONTENT_ID=""
    case "$1" in
        base) region="EU retail base game 1.00"; title="CUSA03745"
              TLG_CONTENT_ID="EP9000-CUSA03745_00-LASTGUARDIANEU00"
              image="TLG_BASE.pkg" ;;
    esac
    TLG_PKG="${image:+baserom/$image}"
    TLG_PKG_NAME="${region:+$region}${title:+ ($title)}"
}

tlg_version_init() {
    local root="${1:-$PWD}"
    TLG_VERSION="$(tlg_version_detect "$root")"
    TLG_BASEROM_DIR="baserom/${TLG_VERSION}"
    TLG_APP_DIR="${TLG_BASEROM_DIR}/app"
    TLG_BASESELF="${TLG_BASEROM_DIR}/eboot.bin"
    TLG_BASEELF="${TLG_BASEROM_DIR}/eboot.elf"
    TLG_MODULES_DIR="${TLG_BASEROM_DIR}/modules"
    TLG_BUILD_DIR="build/${TLG_VERSION}"
    TLG_SHA256SUMS="config/sha256sums.${TLG_VERSION}.txt"
    TLG_DOCS_DIR="docs/${TLG_VERSION}"
    TLG_VERSIONS="$(tlg_version_configured "$root" | tr '\n' ' ')"
    TLG_VERSIONS="${TLG_VERSIONS% }"
    tlg_version_pkg "$TLG_VERSION"
    export TLG_VERSION TLG_BASEROM_DIR TLG_APP_DIR TLG_BASESELF TLG_BASEELF TLG_MODULES_DIR
    export TLG_PKG TLG_PKG_NAME TLG_CONTENT_ID
    export TLG_BUILD_DIR TLG_SHA256SUMS TLG_DOCS_DIR TLG_VERSIONS
}
