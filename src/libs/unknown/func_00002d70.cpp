/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void TwoBaseAllocator::blockFreeBatch(void **blocks, int numBlocks, int blockSize)
{
    criticalSection.enter();
    if (blockSize <= 640) {
        FreeList *freeList = sizeToFreeList[(blockSize + 31) >> 5];
        const s64 numFreeBefore = freeList->numFreeElements;
        freeList->freeBatch(blocks, numBlocks);
        baseBytes += (freeList->numFreeElements - numFreeBefore) * freeList->elementSize;
    } else {
        for (int i = 0; i < numBlocks; i++) {
            if (blocks[i]) {
                largeAllocator->blockFree(blocks[i], blockSize);
            }
        }
    }
    criticalSection.leave();
}
