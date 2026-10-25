/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 11 of the block-list allocator's vtable (address point
 * 0x16a3230) resets the peak to the bytes now in use. */
void BlockListAllocator::FUN_0008f560() /* derived name */
{
    statistics.peakInUse = statistics.inUse;
}
