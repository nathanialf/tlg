/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 21 (interface slot 10): under the lock, the allocator below
 * recorded first; when it is, a provider of this allocator's own under it,
 * every size class's free list recorded as in use and the fixed-size
 * allocator's list as not. The provider's index back, -1 when there is
 * none. Its this-adjusting thunk (0x3700) comes with it, a jump to the
 * body. */
int TwoBaseAllocator::addToSnapshot(void *snapshotOut, int parentId)
{
    MemorySnapshot00011280 &snapshot = *static_cast<MemorySnapshot00011280 *>(snapshotOut);
    criticalSection.enter();
    int id = -1;
    if (allocator38) {
        const int largeId = allocator38->addToSnapshot(snapshotOut, parentId);
        if (largeId != -1) {
            id = snapshot.FUN_00011170("hkFreeListAllocator", largeId);
            for (int i = 0; i < numFreeLists; i++) {
                freeLists[i]->FUN_00018fc0(snapshot, 1, id);
            }
            fixedAllocator.freeList.FUN_00018fc0(snapshot, 0, id);
        }
    }
    criticalSection.leave();
    return id;
}
