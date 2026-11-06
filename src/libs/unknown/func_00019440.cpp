/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void FreeList::FUN_00019440(MemoryStatistics &statistics) const
{
    statistics.allocated = blocksAllocatedSize(activeBlocks) + blocksAllocatedSize(freeBlocks);
    const u64 numUsedElements = totalNumElements - numFreeElements;
    statistics.available = numFreeElements * elementSize;
    statistics.inUse = numUsedElements * elementSize;
    statistics.largestBlock = elementSize;
    statistics.totalAvailable = statistics.available;
}
