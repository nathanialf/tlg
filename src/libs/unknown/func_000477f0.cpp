/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void IndexLists000477f0::FUN_000477f0(hkArray<IndexRange000477f0> &ranges,
                                      hkArray<int> &indices) const
{
    const int n = numLists;
    int numExtra = 0;
    for (int i = 0; i < n; i++) {
        numExtra += lists[i].numIndices - 1;
    }
    indices.reserve(hkContainerHeapAllocator::get(), numExtra + n * 4);
    int start = 0;
    for (int i = 0; i < n; i++) {
        const IndexList000477f0 &list = lists[i];
        const int count = list.numIndices;
        if (count >= 2) {
            const int padded = (count + 3) & ~3;
            ranges[i] = IndexRange000477f0(start, count);
            const int first = indices.size;
            indices.size = first + padded;
            int *dst = indices.data + first;
            dst[0] = 0;
            int j = 1;
            for (; j < count; j++) {
                dst[j] = list.indices[j];
            }
            for (; j < padded; j++) {
                dst[j] = 0;
            }
            start += padded;
        } else {
            ranges[i] = IndexRange000477f0(start, 0);
        }
    }
}
