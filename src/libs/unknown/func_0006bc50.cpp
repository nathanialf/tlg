/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Over the world: room for 256 entries, and a word for each body the
 * world's array has room for, none of them set. */
RefArrays0005a230::RefArrays0005a230(hknpWorld *world_)
{
    world = world_;
    pointer18 = HK_NULL;
    pointer20 = HK_NULL;
    pointer28 = HK_NULL;
    freeHead = 0xffff;
    entries.reserve(hkContainerHeapAllocator::get(), 256);
    array48.setSize(hkContainerHeapAllocator::get(), world->bodyManager.bodies.getCapacity(),
                    0xffff);
    flag58 = false;
}
