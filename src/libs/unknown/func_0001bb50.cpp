/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 5 of the Fios file system's vtable (address point
 * 0x168eaa0) opens the named file's native reader and hands it back as the
 * flags ask. */
StreamReader *FiosFileSystem::FUN_0001bb50(const char *name, int flags)
{
    return FUN_0001a7b0(FUN_00093180(name), flags);
}
