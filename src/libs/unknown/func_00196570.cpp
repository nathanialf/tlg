/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void ElementPool00198a20::FUN_00196570(u32 numElements)
{
    const int oldSize = elements.getSize();
    if (oldSize < int(numElements)) {
        elements.setSize(numElements);
        freeIndices.reserve(hkContainerHeapAllocator::get(), numElements);
        for (int i = numElements - 1; i >= oldSize; i--) {
            freeIndices.pushBackUnchecked(i);
        }
    }
}
