/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 9 of TwoBaseAllocator's vtable (0x168c640), under the lock: the
 * allocator below's statistics, then each free list's and the fixed
 * allocator's last: the elements' blocks counted as in use below are not in
 * use here, their free bytes available; the largest element a list can still
 * hand out the largest block when it is larger; the peak this allocator's
 * own. */
void TwoBaseAllocator::getMemoryStatistics(MemoryStatistics &statistics) const
{
    criticalSection.enter();
    largeAllocator->getMemoryStatistics(statistics);
    s64 allocated = 0;
    s64 available = 0;
    s64 inUse = 0;
    for (int i = 0; i <= numFreeLists; i++) {
        MemoryStatistics listStatistics;
        const FreeList *list = (i == numFreeLists) ? &fixedAllocator.freeList : freeLists[i];
        list->FUN_00019440(listStatistics);
        if (list->freeHead || list->top < list->blockEnd) {
            if (list->elementSize > u32(statistics.largestBlock)) {
                statistics.largestBlock = list->elementSize;
            }
        }
        available += listStatistics.available;
        inUse += listStatistics.inUse;
        allocated += listStatistics.allocated;
    }
    statistics.available += available;
    statistics.inUse += inUse - allocated;
    statistics.peakInUse = peakBytes;
    criticalSection.leave();
}
