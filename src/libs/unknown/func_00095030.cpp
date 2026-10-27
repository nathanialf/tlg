/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

hkBlockStreamBlock *hkBlockStream::FUN_00095030(BlockCache *cache) /* derived name */
{
    hkBlockStreamBlock *last = blocks[blocks.size - 2];
    cache->FUN_0008ef10(blocks[blocks.size - 1]);
    last->next = 0;
    blocks.size--;
    return last;
}
