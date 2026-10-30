/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: the free indices' loop keeps its guard as the base does (the
// loop after the growth test), but the guard compares n with the old size
// where the base compares n - 1 (InstCombine's `icmp sge (X + -1), Y` fold,
// 3.3 InstCombineCompares.cpp:2495, needs the add's nsw, which the base's
// compare lacks), and the free list's reserve takes the array's address
// after its doubled capacity, the base before (docs/NOTES.md, Round 58).
void ElementPool00198a20::FUN_00196570(int numElements)
{
    const int oldSize = elements.getSize();
    if (oldSize < numElements) {
        elements.setSize(numElements);
        freeIndices.reserve(hkContainerHeapAllocator::get(), numElements);
    }
    for (int i = numElements - 1; i >= oldSize; i--) {
        freeIndices.pushBackUnchecked(i);
    }
}
