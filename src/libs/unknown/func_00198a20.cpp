/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: an element's index handed back to the free list. */
void ElementPool00198a20::FUN_00198a20(int index)
{
    freeIndices.pushBack(index);
}

/* derived name: room for numFree free elements: the elements grown by what
 * the free list lacks, as the growth 0x196570 grows them (the new size
 * unsigned as its count is). */
void ElementPool00198a20::FUN_00198a70(u32 numFree)
{
    if (freeIndices.getSize() < numFree) {
        const int oldSize = elements.getSize();
        const u32 numElements = numFree - freeIndices.getSize() + oldSize;
        if (oldSize < int(numElements)) {
            elements.setSize(numElements);
            freeIndices.reserve(hkContainerHeapAllocator::get(), numElements);
            for (int i = numElements - 1; i >= oldSize; i--) {
                freeIndices.pushBackUnchecked(i);
            }
        }
    }
}
