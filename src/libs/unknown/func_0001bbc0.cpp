/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"
#include "tlg_sce_fios.h"

/* derived name: slot 7 of the Fios file system's vtable (address point
 * 0x168eaa0) removes a file with the default attributes; any error is a
 * failure. */
hkResult FiosFileSystem::FUN_0001bbc0(const char *path)
{
    return sceFiosFileDeleteSync(0, path) != 0 ? HK_FAILURE : HK_SUCCESS;
}
