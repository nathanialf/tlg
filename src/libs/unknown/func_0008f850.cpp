/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hkResult UnionFind::FUN_0008f850(hkArray<int> &groupSizes)
{
    const int numGroups = collapseTree();
    if (groupSizes.reserve(hkContainerHeapAllocator::get(), numGroups) != HK_SUCCESS) {
        return HK_FAILURE;
    }
    int groupId = 0;
    for (int i = 0; i < numNodes; i++) {
        const int parent = parents->data[i];
        if (parent < 0) {
            groupSizes.pushBackUnchecked(-parent);
            parents->data[i] = groupId;
            groupId++;
        } else {
            parents->data[i] = parents->data[parent];
        }
    }
    return HK_SUCCESS;
}
