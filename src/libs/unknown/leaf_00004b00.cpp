/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 9 of the system heap allocator's vtable (0x168ca00)
 * reports the bytes in use and the peak, widened to the statistics' 64-bit
 * counts; the other counts are left as the caller set them. */
void hkMallocAllocator::FUN_00004b00(MemoryStatistics &statistics) const /* derived name */
{
    statistics.allocated = bytesInUse;
    statistics.peakInUse = peakInUse;
}
