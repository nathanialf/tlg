/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 18 (interface slot 7): without an allocator below there is nothing
 * to walk. Under the lock, the allocator below is walked through a filter
 * that leaves out the blocks the free lists hold from it (every size
 * class's list and the fixed-size allocator's, gathered with the default
 * allocator); the gathered blocks are given back on either way out of the
 * walk, a failed walk being the answer, else each free list walks its own
 * blocks as pool 1 on, the fixed-size allocator's last. Its this-adjusting
 * thunk (0x3130) comes with it, a jump to the body. */
int TwoBaseAllocator::FUN_00002f10(MemoryWalkCallback callback, void *param)
{
    if (!allocator38) {
        return HK_FAILURE;
    }
    hkCriticalSectionLock lock(&criticalSection);
    FreeList *lists[22];
    FUN_00017e70(lists, freeLists, numFreeLists * sizeof(FreeList *));
    lists[numFreeLists] = &fixedAllocator.freeList;
    MemoryWalkFilter000015c0 filter(D_16dc138, lists, numFreeLists + 1, callback, param);
    const int result = allocator38->FUN_00002f10(FUN_000015c0, &filter);
    if (result != HK_SUCCESS) {
        if (filter.ownBlocks) {
            filter.allocator->blockFree(filter.ownBlocks,
                                        filter.numOwnBlocks * int(sizeof(void *)));
        }
        return result;
    }
    if (filter.ownBlocks) {
        filter.allocator->blockFree(filter.ownBlocks, filter.numOwnBlocks * int(sizeof(void *)));
    }
    for (int i = 0; i < numFreeLists; i++) {
        freeLists[i]->FUN_00018df0(callback, i + 1, param);
    }
    fixedAllocator.freeList.FUN_00018df0(callback, numFreeLists + 1, param);
    return HK_SUCCESS;
}
