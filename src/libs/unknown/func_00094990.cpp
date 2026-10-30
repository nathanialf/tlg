/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

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

/* The stream emptied down to one new block (0x94880): nothing to do when it
 * already holds one empty block none of which was freed, else every block
 * back to the cache (0x94990, inline here) and a new one appended, its
 * statements written out as the setup's are (func_000947f0.cpp). */
// NONMATCHING: equal in its statements' order and every block's code but for the array's
// address (NOTES Round 64B): EarlyCSE gives the entry test's `blocks` member expression (this
// + 0x20) to the append's getSize and pushBack, so the address is kept in r14 from the entry
// (`lea r14, [rbx+0x20]`, r15 the cache), where the base forms it at the grow call only.
void hkBlockStream::FUN_00094880(BlockCache *cache)
{
    if (blocks.size) {
        if (numTotalElements == 0 && blocks.size == 1 && !partiallyFreed) {
            return;
        }
        FUN_00094990(cache);
    }
    hkBlockStreamBlock *block = cache->FUN_0008eec0();
    if (zeroNewBlocks) {
        hkString::FUN_00018250(block, sizeof(hkBlockStreamBlock));
    } else {
        hkString::memSet16(block, &D_14b2060[2], 2);
    }
    const int blockIndex = blocks.getSize();
    block->pointer10 = allocator;
    block->header.blockIndexInStream = blockIndex;
    blocks.pushBack(block);
}
