/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 3 of TwoBaseAllocator's vtable (address point 0x168c640): under the
 * lock, a small block back on its size's free list, the bytes it frees
 * counted from the list's free count before and after; a larger one back
 * to the allocator below. */
void TwoBaseAllocator::blockFree(void *pointer, int numBytes)
{
    if (pointer) {
        criticalSection.enter();
        if (numBytes <= 640) {
            FreeList *freeList = sizeToFreeList[(numBytes + 31) >> 5];
            const s64 numFreeBefore = freeList->numFreeElements;
            freeList->free(pointer);
            baseBytes += (freeList->numFreeElements - numFreeBefore) * freeList->elementSize;
        } else {
            largeAllocator->blockFree(pointer, numBytes);
        }
        criticalSection.leave();
    }
}
