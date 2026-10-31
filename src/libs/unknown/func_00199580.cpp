/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void U16PointerMap::FUN_00199580(AllocatorBase &allocator) /* derived name */
{
    clear();
    if ((numEntries & DONT_DEALLOCATE_FLAG) == 0) {
        allocator.blockFree(entries, sizeof(Pair) * (hashMod + 1));
    }
    entries = 0;
    numEntries = 0;
    hashMod = -1;
}
