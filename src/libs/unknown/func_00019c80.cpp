/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the page allocator's statistics, each figure asked of its
 * own slot; what is not in use is available, in blocks of one page. */
void PageAllocator::FUN_00019c80(MemoryStatistics &statistics) const
{
    statistics.allocated = FUN_00019b50();
    statistics.inUse = FUN_00019b30();
    statistics.peakInUse = FUN_0000b670();
    statistics.available = statistics.allocated - FUN_00019b30();
    statistics.totalAvailable = statistics.available;
    statistics.largestBlock = PAGE_SIZE;
}
