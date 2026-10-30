/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void Allocator0000ed40::FUN_0000ee00(AllocatorBase **allocatorsOut)
{
    if (cur) {
        internalAllocator->blockFree(pointer8->array10[0], slabSize);
    }
    if (pointer30) {
        internalAllocator->blockFree(pointer30, slabSize);
    }
    pointer8->array10.clearAndDeallocate(*internalAllocator);
    pointer8->freeBlocks.clearAndDeallocate(*internalAllocator);
    internalAllocator->blockFree(pointer8, sizeof(Impl));
    pointer8 = 0;
    if (allocatorsOut) {
        allocatorsOut[0] = slabAllocator;
        allocatorsOut[1] = largeAllocator;
        allocatorsOut[2] = internalAllocator;
    }
}
