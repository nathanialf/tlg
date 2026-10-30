/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void FUN_00184d50(hkAabbUint32 *aabbs, int numAabbs, hkArray<hkRadixSort::SortData32> &sortArray,
                  hkArray<hkAabbUint32> &sortedAabbs)
{
    const int numAabbs4 = (numAabbs + 3) & ~3;
    for (int i = 0; i < numAabbs4; i++) {
        hkRadixSort::SortData32 &item = sortArray[i];
        item.key = aabbs[i].min[0];
        item.userData = i;
    }
    hkRadixSort::SortData32 *buffer = reinterpret_cast<hkRadixSort::SortData32 *>(sortedAabbs.data);
    hkRadixSort::FUN_00184770(sortArray.data, numAabbs4, buffer);
    for (int i = 0; i < numAabbs; i++) {
        sortedAabbs[i] = aabbs[sortArray[i].userData];
    }
    hkString::memCpy16(aabbs, sortedAabbs.data, numAabbs * (sizeof(hkAabbUint32) / 16));
}
