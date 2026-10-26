/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 9 of the buffer allocator: the buffer's size, what is left after the
 * used part, the used part and its peak. */
void BufferAllocator::getMemoryStatistics(MemoryStatistics &statistics) const
{
    statistics.allocated = bufferEnd - bufferStart;
    statistics.available = bufferEnd - currentEnd;
    statistics.inUse = currentEnd - bufferStart;
    statistics.peakInUse = peakUse;
}
