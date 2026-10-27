/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: a block taken back into the cache; when the cache is full,
 * six of its blocks go back to the allocator. */
void BlockCache::FUN_0008ef10(void *block)
{
    blocks[numBlocks] = block;
    numBlocks++;
    if (numBlocks < 8) {
        return;
    }
    int first = numBlocks - 6;
    allocator->blockFreeBatch(&blocks[first], 6);
    numBlocks = first;
}
