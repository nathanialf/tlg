/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 8 of the fixed-size allocator: every block counted free, each
 * non-null one linked at the head of the free list, a null one taken off
 * the count again. The block size is the list's own. */
void FixedSizeAllocator::blockFreeBatch(void **blocks, int numBlocks, int blockSize)
{
    freeList.numFreeElements += numBlocks;
    void *head = freeList.freeHead;
    while (numBlocks > 0) {
        void **block = static_cast<void **>(*blocks++);
        numBlocks--;
        if (block) {
            *block = head;
            head = block;
        } else {
            freeList.numFreeElements--;
        }
    }
    freeList.freeHead = head;
}
