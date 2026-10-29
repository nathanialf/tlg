/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"
#include "tlg_libc.h"

/* derived name: the storage set to a capacity, reallocated in place by the
 * allocator when the array owns it, else new storage with the elements
 * copied over; on failure the array keeps no storage. */
hkResult FUN_00000a70(AllocatorBase &allocator, void *array, int numElements, int elementSize)
{
    hkArray<char> &a = *static_cast<hkArray<char> *>(array);
    int numBytes = numElements * elementSize;
    char *p;
    if (a.capacityAndFlags & hkArray<char>::DONT_DEALLOCATE_FLAG) {
        p = static_cast<char *>(allocator.FUN_00008d70(numBytes));
        if (p) {
            memcpy(p, a.data, a.size * elementSize);
        }
    } else {
        p = static_cast<char *>(
            allocator.FUN_00008d90(a.data, a.getCapacity() * elementSize, numBytes));
    }
    a.data = p;
    a.capacityAndFlags = p ? numBytes / elementSize : 0;
    return p ? HK_SUCCESS : HK_FAILURE;
}
