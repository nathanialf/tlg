/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void *FreeList::FUN_00019230()
{
    FreeListBlock *block = freeBlocks;
    if (block) {
        /* A free block taken back: its elements are counted free already. */
        freeBlocks = block->next;
        top = block->elements;
        blockEnd = block->elements + block->numElements * elementSize;
        block->next = activeBlocks;
        activeBlocks = block;
        numFreeElements--;
    } else {
        if (blockSize == 0) {
            /* A first block sized for about 256 bytes of elements, at least
             * one, with room for the header and the alignment. */
            u64 numElements = 256 / elementSize;
            if (numElements == 0) {
                numElements = 1;
            }
            const u64 elementsSize = numElements * elementSize;
            if (unknown30 <= 16) {
                blockSize = elementsSize + sizeof(FreeListBlock);
            } else {
                blockSize = elementsSize + unknown30 + 16;
            }
        }
        if (elementAllocator) {
            block =
                static_cast<FreeListBlock *>(elementAllocator->blockAlloc(sizeof(FreeListBlock)));
            if (!block) {
                return HK_NULL;
            }
            int numBytes = int(blockSize);
            char *memory = static_cast<char *>(blockAllocator->FUN_00008d70(numBytes));
            if (!memory) {
                elementAllocator->blockFree(block, sizeof(FreeListBlock));
                return HK_NULL;
            }
            block->memory = memory;
            char *start =
                reinterpret_cast<char *>((hkUlong(memory) + unknown30 - 1) & (0 - unknown30));
            if (start == memory && numBytes == int(blockSize)) {
                block->numElements = elementsPerBlock;
                block->elements = start;
            } else {
                block->numElements = (memory + numBytes - start) / elementSize;
                block->elements = start;
            }
        } else {
            int numBytes = int(blockSize);
            block = static_cast<FreeListBlock *>(blockAllocator->FUN_00008d70(numBytes));
            if (!block) {
                return HK_NULL;
            }
            char *start =
                reinterpret_cast<char *>((hkUlong(block + 1) + unknown30 - 1) & (0 - unknown30));
            block->memory = HK_NULL;
            block->numElements = (reinterpret_cast<char *>(block) + numBytes - start) / elementSize;
            block->elements = start;
        }
        top = block->elements;
        blockEnd = block->elements + block->numElements * elementSize;
        block->next = activeBlocks;
        activeBlocks = block;
        totalNumElements += block->numElements;
        numFreeElements += block->numElements - 1;
    }
    char *element = top;
    top = element + elementSize;
    return element;
}
