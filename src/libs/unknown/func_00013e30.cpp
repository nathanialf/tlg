/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the pointer map's reserve: the table stays at most half
 * full, so the capacity is the first power of two from 8 that holds twice
 * the number of entries. */
void PointerMap::FUN_00013e30(AllocatorBase &allocator, int numElements) /* derived name */
{
    int minCapacity = numElements * 2;
    int capacity = 8;
    while (capacity < minCapacity) {
        capacity *= 2;
    }
    FUN_00013940(allocator, capacity);
}
