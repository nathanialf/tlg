/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the blocks still held packed to the front when some were
 * freed out of the list (their slots null), then all of them back to the
 * cache at once. */
void hkBlockStream::FUN_00094990(BlockCache *cache)
{
    int numBlocks = blocks.size;
    if (partiallyFreed) {
        hkBlockStreamBlock *const *block = blocks.data;
        hkBlockStreamBlock **kept = blocks.data;
        for (int i = 0; i < numBlocks; i++, block++) {
            if (*block) {
                *kept = *block;
                kept++;
            }
        }
        numBlocks = int(kept - blocks.data);
        partiallyFreed = false;
    }
    if (numBlocks) {
        cache->FUN_0008efa0(blocks.data, numBlocks);
    }
    blocks.size = 0;
    numTotalElements = 0;
}
