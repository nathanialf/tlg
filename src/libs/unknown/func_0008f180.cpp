/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* BlockListAllocator's constructor (derived name): nothing drawn yet. */
BlockListAllocator::BlockListAllocator(AllocatorBase *parent)
    : lock(1000), parent(parent), blocks(0)
{
    statistics.allocated = 0;
    statistics.inUse = 0;
    statistics.peakInUse = 0;
}
