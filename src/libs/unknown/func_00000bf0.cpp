/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"
#include "tlg_libc.h"

/* derived name: the storage reduced to a capacity: into the caller's
 * buffer when there is one and the elements fit (the old storage freed,
 * the buffer not owned), else reallocated by the allocator, which may
 * round the size up; the capacity is what it gave. */
void FUN_00000bf0(AllocatorBase &allocator, void *array, int elementSize, void *buffer,
                  int numElements)
{
    hkArray<char> &a = *static_cast<hkArray<char> *>(array);
    if (buffer && a.size < numElements) {
        memcpy(buffer, a.data, a.size * elementSize);
        allocator.FUN_00008d80(a.data, a.getCapacity() * elementSize);
        a.data = static_cast<char *>(buffer);
        a.capacityAndFlags = numElements | hkArray<char>::DONT_DEALLOCATE_FLAG;
    } else {
        int numBytes = numElements * elementSize;
        a.data = static_cast<char *>(
            allocator.FUN_00008d90(a.data, a.capacityAndFlags * elementSize, numBytes));
        a.capacityAndFlags = numBytes / elementSize;
    }
}
