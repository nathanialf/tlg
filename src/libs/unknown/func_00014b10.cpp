/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 7 of the fixed-size allocator: the blocks are the free list's
 * elements, the block size the list's own. The freed elements first, then
 * the current block's, the list's slow path for each one past the block's
 * end (it counts its own). */
void FixedSizeAllocator::blockAllocBatch(void **blocksOut, int numBlocks, int blockSize)
{
    void **out = blocksOut;
    void **end = blocksOut + numBlocks;
    void **element = static_cast<void **>(freeList.freeHead);
    for (; out < end && element; out++) {
        *out = element;
        element = static_cast<void **>(*element);
    }
    freeList.freeHead = element;
    freeList.numFreeElements -= out - blocksOut;
    while (out < end) {
        if (freeList.top < freeList.blockEnd) {
            void **first = out;
            for (; freeList.top < freeList.blockEnd && out < end; out++) {
                *out = freeList.top;
                freeList.top += freeList.elementSize;
            }
            freeList.numFreeElements -= out - first;
        } else {
            *out++ = freeList.FUN_00019230();
        }
    }
}
