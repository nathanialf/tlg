/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: an allocation recorded, the array grown from the
 * snapshot's own allocator when full. */
int MemorySnapshot00011280::FUN_00011280(int sourceId, u8 status, const void *address, int size)
{
    const int index = allocations.getSize();
    if (index == allocations.getCapacity()) {
        FUN_00000b40(*allocator, &allocations, sizeof(Allocation));
    }
    Allocation &allocation = *allocations.expandByUnchecked(1);
    allocation.start = address;
    allocation.size = size;
    allocation.sourceId = sourceId;
    allocation.traceId = -1;
    allocation.status = status;
    return index;
}
