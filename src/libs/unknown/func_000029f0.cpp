/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void TwoBaseAllocator::blockAllocBatch(void **blocksOut, int numBlocks, int blockSize)
{
    criticalSection.enter();
    if (blockSize <= 640) {
        FreeList *freeList = sizeToFreeList[(blockSize + 31) >> 5];
        const s64 numFreeBefore = freeList->numFreeElements;
        freeList->allocBatch(blocksOut, numBlocks);
        baseBytes += (freeList->numFreeElements - numFreeBefore) * freeList->elementSize;
    } else {
        for (int i = 0; i < numBlocks; i++) {
            blocksOut[i] = largeAllocator->blockAlloc(blockSize);
        }
    }
    if (allocator38) {
        const u64 allocated = allocator38->allocatedBytes() - baseBytes;
        peakBytes = hkMath::max2(allocated, peakBytes);
        if (allocated >= limitB50) {
            FUN_00006640(1);
        }
    }
    criticalSection.leave();
}
