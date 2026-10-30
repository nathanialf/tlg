/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_algorithm.h"
#include "tlg_lib_unknown.h"

MemoryWalkFilter000015c0::MemoryWalkFilter000015c0(AllocatorBase *allocator,
                                                   FreeList *const *freeLists, int numFreeLists,
                                                   MemoryWalkCallback callback, void *param)
    : allocator(allocator), ownBlocks(0), numOwnBlocks(0), callback(callback), callbackParam(param)
{
    for (int i = 0; i < numFreeLists; i++) {
        const FreeList *freeList = freeLists[i];
        numOwnBlocks += FUN_000188a0(freeList->activeBlocks);
        numOwnBlocks += FUN_000188a0(freeList->freeBlocks);
    }
    ownBlocks = static_cast<void **>(allocator->blockAlloc(numOwnBlocks * int(sizeof(void *))));
    if (!ownBlocks) {
        return;
    }
    void **out = ownBlocks;
    for (int i = 0; i < numFreeLists; i++) {
        for (FreeListBlock *block = freeLists[i]->activeBlocks; block; block = block->next) {
            *out++ = block->memory ? block->memory : block;
        }
        for (FreeListBlock *block = freeLists[i]->freeBlocks; block; block = block->next) {
            *out++ = block->memory ? block->memory : block;
        }
    }
    if (numOwnBlocks > 1) {
        hkAlgorithm::quickSortRecursive(ownBlocks, 0, numOwnBlocks - 1,
                                        hkAlgorithm::less<void *>());
    }
}
