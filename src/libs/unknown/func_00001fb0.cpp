/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The class's key function (its first virtual not defined in the class):
 * the vtables, the deleting destructor 0x1f90 (before this one: an out of
 * line destructor emits D0 first) and the second base's thunks are emitted
 * here. Every distinct free list deleted, its room given back when it was
 * the last one handed out and its other entries cleared; the fixed-size
 * allocator's list emptied; then the members' destructors. */
TwoBaseAllocator::~TwoBaseAllocator()
{
    for (int i = 0; i < numFreeLists; i++) {
        FreeList *list = freeLists[i];
        if (list) {
            list->~FreeList();
            if (list + 1 == freeListStorageTop) {
                freeListStorageTop = list;
            }
            for (int j = i + 1; j < numFreeLists; j++) {
                if (freeLists[j] == list) {
                    freeLists[j] = HK_NULL;
                }
            }
        }
    }
    fixedAllocator.freeList.FUN_00018770();
}
