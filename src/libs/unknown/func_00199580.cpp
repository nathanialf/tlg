/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void ShortKeyMap::FUN_00199580(AllocatorBase &allocator) /* derived name */
{
    clear();
    if ((numElems & DONT_DEALLOCATE_FLAG) == 0) {
        allocator.blockFree(elems, sizeof(Pair) * (hashMod + 1));
    }
    elems = 0;
    numElems = 0;
    hashMod = -1;
}
