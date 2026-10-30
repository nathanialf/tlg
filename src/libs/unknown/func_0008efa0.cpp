/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void BlockCache::FUN_0008efa0(hkBlockStreamBlock **blocksIn, int numBlocksIn)
{
    if (numBlocksIn >= 6) {
        allocator->blockFreeBatch(blocksIn, numBlocksIn);
        return;
    }
    if (numBlocks + numBlocksIn >= 8) {
        const int numFreed = hkMath::min2(6, numBlocks);
        const int first = numBlocks - numFreed;
        allocator->blockFreeBatch(&blocks[first], numFreed);
        numBlocks = first;
    }
    for (int i = 0; i < numBlocksIn; i++) {
        blocks[numBlocks + i] = blocksIn[i];
    }
    numBlocks += numBlocksIn;
}
