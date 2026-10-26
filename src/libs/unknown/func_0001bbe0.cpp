/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"
#include "tlg_sce_fios.h"

/* derived name: slot 8 of the Fios file system's vtable (address point
 * 0x168eaa0) creates a directory with the default attributes; any error is a
 * failure. */
hkResult FiosFileSystem::FUN_0001bbe0(const char *path)
{
    return sceFiosDirectoryCreate(0, path) != 0 ? HK_FAILURE : HK_SUCCESS;
}
