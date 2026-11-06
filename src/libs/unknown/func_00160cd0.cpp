/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpBodyManager::FUN_00160cd0(u32 bodyId, const char *name)
{
    if (name && u32(bodyNames.getSize()) <= bodyId) {
        bodyNames.setSize(hkContainerHeapAllocator::get(), bodies.getCapacity(),
                          hkStringPtr(HK_NULL));
    }
    if (bodyId < u32(bodyNames.getSize())) {
        bodyNames[bodyId] = name;
    }
}
