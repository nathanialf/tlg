/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: a block from the cache; when the cache is empty, six are
 * fetched from the allocator first and the last of them handed out. */
void *BlockCache::FUN_0008eec0()
{
    if (numBlocks > 0) {
        numBlocks--;
        return blocks[numBlocks];
    }
    allocator->blockAllocBatch(blocks, 6);
    numBlocks = 5;
    return blocks[5];
}
