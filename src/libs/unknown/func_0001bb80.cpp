/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 6 of the Fios file system's vtable opens the named
 * file for writing (Fios open flags: write 2 and create 8, and truncate 16
 * when bit 1 of the flags is set) and hands the writer back as the flags
 * ask. */
hkStreamWriter *FiosFileSystem::FUN_0001bb80(const char *name, int flags)
{
    return FUN_0001a850(FUN_00091d50(name, flags, (flags & 2) ? 26 : 10), flags);
}
