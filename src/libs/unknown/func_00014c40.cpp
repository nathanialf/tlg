/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: slot 9 of the fixed-size allocator's vtable (0x168e5c0):
 * its statistics are its free list's. */
void FixedSizeAllocator::FUN_00014c40(MemoryStatistics &statistics) const /* derived name */
{
    FUN_00019440(&freeList, statistics);
}
