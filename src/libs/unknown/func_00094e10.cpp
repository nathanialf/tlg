/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the blocks the range's elements lie in, counted from its
 * first block, are appended to the stream's list and removed from where
 * they were; every block from there on takes its new index, the block
 * before the moved ones and the last block before the end are linked to
 * their successors, and the new last block ends the list. */
void hkBlockStream::FUN_00094e10(BlockCache *cache, const hkBlockStreamRange *range)
{
    if (range->numElements == 0) {
        return;
    }
    const hkBlockStreamBlock::Header first = range->startBlock->getHeader();
    int numBlocks = 1;
    {
        u32 numElementsLeft = range->numElements;
        const hkBlockStreamBlock *block = range->startBlock;
        while (numElementsLeft > block->header.numElements) {
            numElementsLeft -= block->header.numElements;
            numBlocks++;
            block = block->next;
        }
    }

    blocks.reserve(hkContainerHeapAllocator::get(), blocks.getSize() + numBlocks);
    const int firstIndex = first.blockIndexInStream;
    blocks.insertAt(blocks.getSize(), &blocks.data[firstIndex], numBlocks);
    blocks.removeAtAndCopy(firstIndex, numBlocks);
    for (int i = firstIndex; i < blocks.getSize(); i++) {
        blocks.data[i]->header.blockIndexInStream = i;
    }
    if (firstIndex > 0) {
        blocks.data[firstIndex - 1]->next = blocks.data[firstIndex];
    }
    const int firstMoved = blocks.getSize() - numBlocks;
    if (firstMoved > 0) {
        blocks.data[firstMoved - 1]->next = blocks.data[firstMoved];
    }
    blocks.data[blocks.getSize() - 1]->next = HK_NULL;
}
