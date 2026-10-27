/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void ThreadMemory::getMemoryStatistics(MemoryStatistics &statistics) const
{
    statistics.allocated = -1;
    statistics.inUse = -1;
    statistics.peakInUse = -1;
    s64 available = 0;
    for (int i = 0; i < 16; i++) {
        available += freeLists[i].numElem * rowToSize[i];
    }
    statistics.available = available;
    statistics.totalAvailable = -1;
    statistics.largestBlock = -1;
}
