/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: every block before the reader's current one is freed out
 * of the stream, then the stream's blocks are put back in order. */
void hkBlockStream::FUN_00094d90(BlockCache *cache, const hkBlockStreamReader *reader)
{
    for (int i = 0; i < reader->currentBlock->header.blockIndexInStream; i++) {
        FUN_00094df0(cache, blocks.data[i], i);
    }
    FUN_00094c60(cache);
}

/* derived name: a block is freed out of the stream while it is read: its
 * slot is cleared, the stream marked, and the block given to the cache. */
void hkBlockStream::FUN_00094df0(BlockCache *cache, void *block, int index)
{
    blocks.data[index] = 0;
    partiallyFreed = true;
    cache->FUN_0008ef10(block);
}
