/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING (NOTES Round 64B): the array's address kept across the new block's calls (`lea
// r15, [r14+0x20]` at the append's head, the grow's argument), as in 0x94880; the count read as
// a 16-bit load where the base reads the header's word and narrows it, and the scan's registers.
void hkBlockStream::FUN_00094c60(BlockCache *cache)
{
    if (!partiallyFreed) {
        return;
    }
    hkBlockStreamBlock *const *block = blocks.data;
    hkBlockStreamBlock **kept = blocks.data;
    const int numBlocks = blocks.size;
    int numElements = 0;
    int blockIndex = 0;
    hkBlockStreamBlock *previous = HK_NULL;
    for (int i = 0; i < numBlocks; i++, block++) {
        hkBlockStreamBlock *const current = *block;
        if (current) {
            if (previous) {
                previous->next = current;
            }
            *kept = current;
            numElements += current->header.numElements;
            current->header.blockIndexInStream = blockIndex;
            blockIndex++;
            kept++;
            previous = current;
        }
    }
    if (previous) {
        previous->next = HK_NULL;
    }
    numTotalElements = numElements;
    blocks.size = int(kept - blocks.data);
    if (blocks.size == 0) {
        hkBlockStreamBlock *newBlock = cache->FUN_0008eec0();
        if (zeroNewBlocks) {
            hkString::FUN_00018250(newBlock, sizeof(hkBlockStreamBlock));
        } else {
            hkString::memSet16(newBlock, &D_14b2060[2], 2);
        }
        const int newIndex = blocks.getSize();
        newBlock->pointer10 = allocator;
        newBlock->header.blockIndexInStream = newIndex;
        blocks.pushBack(newBlock);
    }
    partiallyFreed = false;
}
