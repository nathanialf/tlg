/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 10 of TwoBaseAllocator's vtable (address point 0x168c640). */
int TwoBaseAllocator::getAllocatedSize(const void *pointer, int numBytes) const
{
    if (numBytes <= 640) {
        if (numBytes == 0) {
            return 0;
        }
        const FreeList *freeList = sizeToFreeList[(numBytes + 31) >> 5];
        if (freeList) {
            return int(freeList->elementSize);
        }
    }
    return largeAllocator->getAllocatedSize(pointer, numBytes);
}
