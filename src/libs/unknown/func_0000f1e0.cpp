/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void Allocator0000ed40::FUN_0000f1e0()
{
    char *top = cur;
    for (int i = pointer8->freeBlocks.getSize() - 1; i >= 0; i--) {
        const Impl::FreeBlock &block = pointer8->freeBlocks[i];
        if (block.end != top) {
            break;
        }
        top = block.start;
        pointer8->freeBlocks.popBack();
    }
    while (pointer8->array10.getSize() > 1) {
        const hkUlong used =
            top - static_cast<char *>(pointer8->array10[pointer8->array10.getSize() - 1]);
        if (used != 0 && used <= hkUlong(slabSize)) {
            break;
        }
        if (pointer30) {
            slabAllocator->blockFree(pointer30, slabSize);
            pointer8->numExternalAllocations--;
        }
        pointer30 = static_cast<char *>(pointer8->array10[pointer8->array10.getSize() - 1]);
        pointer8->array10.popBack();
    }
    cur = top;
    const int numSlabs = pointer8->array10.getSize();
    end = numSlabs ? static_cast<char *>(pointer8->array10[numSlabs - 1]) + slabSize : HK_NULL;
    const int numFree = pointer8->freeBlocks.getSize();
    slabStart = numFree ? pointer8->freeBlocks[numFree - 1].end : HK_NULL;
}
