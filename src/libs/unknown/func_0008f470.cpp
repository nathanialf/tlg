/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void BlockListAllocator::getMemoryStatistics(MemoryStatistics &statisticsOut) const
{
    lock.enter();
    statisticsOut = statistics;
    lock.leave();
}
