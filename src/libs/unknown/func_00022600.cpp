/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: the grow, the result in r14 and the clear are the base's; left: the base keeps
// the first free node in r15 and sets the result to zero before the clear's call (this compile
// reuses r14 for the first node and zeroes the result at the end), and its link loop is
// unrotated under the guard (`cmp r15d, eax; jg` then a header test), its last link stored
// through the loop's own offset, where LoopRotate rotates this one behind a second guard
// (NOTES Round 62B).
hkResult hkcdDynamicTree::DynamicStorage32::FUN_00022600(int numNodes)
{
    if (numNodes == 0) {
        return HK_SUCCESS;
    }
    const int oldSize = nodes.getSize();
    // Node 0 is never free: the new nodes start at 1 at the least.
    const int first = hkMath::max2(1, oldSize);
    const int needed = numNodes + oldSize + 1;
    const int capacity = nodes.getCapacity();
    if (capacity < needed) {
        const int doubled = 2 * capacity;
        if (FUN_00000a70(hkContainerHeapAllocator::get(), &nodes,
                         doubled < needed ? needed : doubled, sizeof(CodecRawUint)) != HK_SUCCESS) {
            return HK_FAILURE;
        }
    }
    // Every node the storage now has is in use or free, the new ones cleared.
    const int numOld = nodes.getSize();
    const int newSize = nodes.getCapacity();
    nodes.setSizeUnchecked(newSize);
    FUN_00018160(&nodes.data[numOld], 0, (newSize - numOld) * int(sizeof(CodecRawUint)));
    const int last = nodes.getSize() - 1;
    if (first <= last) {
        for (int i = first; i < last; i++) {
            nodes.data[i].setNextFree(i + 1);
        }
        nodes.data[last].setNextFree(firstFree);
    }
    firstFree = first;
    return HK_SUCCESS;
}
