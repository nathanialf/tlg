/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"
#include "tlg_libc.h"

/* derived name: room for one more element at least: the capacity doubled
 * (one when empty), the storage reallocated in place by the allocator when
 * the array owns it, else new storage with the elements copied over; the
 * allocator may round the size up, and the capacity is what it gave. */
void FUN_00000b40(AllocatorBase &allocator, void *array, int elementSize)
{
    hkArray<char> &a = *static_cast<hkArray<char> *>(array);
    int numBytes = (a.size ? a.size * 2 : 1) * elementSize;
    if (a.capacityAndFlags & hkArray<char>::DONT_DEALLOCATE_FLAG) {
        char *p = static_cast<char *>(allocator.FUN_00008d70(numBytes));
        memcpy(p, a.data, a.size * elementSize);
        a.data = p;
    } else {
        a.data = static_cast<char *>(
            allocator.FUN_00008d90(a.data, a.getCapacity() * elementSize, numBytes));
    }
    a.capacityAndFlags = numBytes / elementSize;
}
