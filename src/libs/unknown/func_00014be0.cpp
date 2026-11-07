/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 8 of the fixed-size allocator: every block counted free, each
 * non-null one linked at the head of the free list, a null one taken off
 * the count again. The block size is the list's own. */
void FixedSizeAllocator::blockFreeBatch(void **blocks, int numBlocks, int blockSize)
{
    freeList.numFreeElements += numBlocks;
    FreeList::Element *head = freeList.freeHead;
    while (numBlocks > 0) {
        FreeList::Element *block = static_cast<FreeList::Element *>(*blocks++);
        numBlocks--;
        if (block) {
            block->next = head;
            head = block;
        } else {
            freeList.numFreeElements--;
        }
    }
    freeList.freeHead = head;
}
