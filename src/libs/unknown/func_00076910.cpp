/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void Elements000760c0::FUN_00076910(BlockCache *cacheA, BlockCache *cacheB)
{
    const int numElements = elements.size;
    for (int i = 0; i < numElements; i++) {
        Element &element = elements[i];
        element.slots[1].stream.FUN_00094990(cacheA);
        element.slots[2].stream.FUN_00094990(cacheA);
        element.slots[0].stream.FUN_00094990(cacheB);
        element.slots[3].stream.FUN_00094990(cacheB);
        element.slots[4].stream.FUN_00094990(cacheB);
    }
    stream40.FUN_00094990(cacheB);
}
