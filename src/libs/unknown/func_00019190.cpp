/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

int FreeList::FUN_00019190()
{
    int numFreed = 0;
    FreeListBlock *block = freeBlocks;
    while (block) {
        totalNumElements -= block->numElements;
        numFreeElements -= block->numElements;
        numFreed++;
        FreeListBlock *next = block->next;
        if (!elementAllocator) {
            blockAllocator->FUN_00008d80(block, int(blockSize));
        } else {
            blockAllocator->FUN_00008d80(block->memory, int(blockSize));
            elementAllocator->blockFree(block, sizeof(FreeListBlock));
        }
        block = next;
    }
    freeBlocks = 0;
    return numFreed;
}
