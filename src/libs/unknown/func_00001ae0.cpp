/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void TwoBaseAllocator::FUN_00001ae0(const TwoBaseAllocatorCinfo *cinfo)
{
    incrementalFreeListIndex = 0;
    peakBytes = 0;
    baseBytes = 0;
    FUN_000034a0(0x7fffffff);
    TwoBaseAllocatorCinfo defaultCinfo;
    if (!cinfo) {
        FUN_00001d70(0x2000, defaultCinfo);
        cinfo = &defaultCinfo;
    }
    fixedAllocator.FUN_00014a80(32, 8, cinfo->preferredBlockSize ? cinfo->preferredBlockSize : 1024,
                                largeAllocator);
    freeListStorageTop = freeListStorage;
    freeListStorageEnd = freeListStorage + 21;
    memset(sizeToFreeList, 0, sizeof(sizeToFreeList));
    for (int i = 0; i < cinfo->numInfos; i++) {
        const TwoBaseAllocatorCinfo::Info &info = cinfo->infos[i];
        FreeList *list = newFreeList(info.elementSize, info.alignment, info.blockSize);
        bool found = false;
        for (int j = 0; j < numFreeLists; j++) {
            if (freeLists[j]->elementSize == list->elementSize) {
                deleteFreeList(list);
                list = freeLists[j];
                found = true;
                break;
            }
        }
        if (!found) {
            freeLists[numFreeLists++] = list;
        }
        sizeToFreeList[info.elementSize >> 5] = list;
    }
    FreeList *list = sizeToFreeList[20];
    for (int i = 20; i >= 0; i--) {
        if (sizeToFreeList[i]) {
            list = sizeToFreeList[i];
        } else {
            sizeToFreeList[i] = list;
        }
    }
}
