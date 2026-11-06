/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hkResult UnionFind::FUN_0008f980(const hkArray<int> &groupSizes, hkArray<int> &order) const
{
    hkResult result = order.trySetSize(hkContainerHeapAllocator::get(), numNodes);
    if (result != HK_SUCCESS) {
        return result;
    }
    const int numGroups = groupSizes.getSize();
    if (numGroups > 0) {
        hkArray<int>::Temp groupStarts;
        result = groupStarts.trySetSize(hkContainerTempAllocator::get(), numGroups);
        if (result == HK_SUCCESS) {
            int *const starts = groupStarts.data;
            int start = 0;
            for (int i = 0; i < numGroups; i++) {
                starts[i] = start;
                start += groupSizes[i];
            }
            const int *const groups = parents->data;
            int *const ordered = order.data;
            for (int i = 0; i < numNodes; i++) {
                ordered[starts[groups[i]]++] = i;
            }
        }
    }
    return result;
}
