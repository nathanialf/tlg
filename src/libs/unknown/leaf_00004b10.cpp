/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: resets the system heap allocator's peak to the current use
 * (tlg_lib_unknown.h). */
void hkMallocAllocator::FUN_00004b10() /* derived name */
{
    peakInUse = bytesInUse;
}
