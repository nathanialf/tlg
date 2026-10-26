/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: every cached block handed back to the allocator. */
void BlockCache::FUN_0008ef60()
{
    if (numBlocks) {
        allocator->blockFreeBatch(blocks, numBlocks);
        numBlocks = 0;
    }
}
