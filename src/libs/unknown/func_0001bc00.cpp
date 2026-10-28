/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"
#include "tlg_sce_fios.h"

hkResult FiosFileSystem::FUN_0001bc00(const char *path, FileSystemEntry &entry)
{
    SceFiosStat stat;
    if (sceFiosStatSync(0, path, &stat) != 0) {
        return HK_FAILURE;
    }
    entry.FUN_0001a700(this, path, (stat.statFlags & 1) + 1, stat.modificationDate, stat.fileSize);
    return HK_SUCCESS;
}
