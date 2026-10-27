/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The byte counts are ints, widened as they are stored. */
void SingleBlockAllocator::getMemoryStatistics(MemoryStatistics &statistics) const
{
    const int used = int(top - start);
    statistics.allocated = used;
    statistics.inUse = used;
    statistics.peakInUse = used;
    const int available = int(limit - top);
    statistics.available = available;
    statistics.totalAvailable = available;
    statistics.largestBlock = int(limit - start);
}
