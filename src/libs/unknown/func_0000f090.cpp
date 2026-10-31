/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* A block larger than a slab from the large allocator, counted; any other at
 * the start of a new slab: the spare one kept at +0x30, else one from the
 * internal allocator while at most one slab is held, else one from the slab
 * allocator, counted. Once a slab is held, the top left behind is recorded
 * as a block ending at the new slab's start, which becomes the slab start;
 * the slab is the new top's home and joins the slabs. */
void *Allocator0000ed40::FUN_0000f090(int numBytes)
{
    if (slabSize < numBytes) {
        pointer8->numExternalAllocations++;
        return largeAllocator->blockAlloc(numBytes);
    }
    char *slab = pointer30;
    if (slab) {
        pointer30 = HK_NULL;
    } else if (pointer8->array10.getSize() <= 1) {
        slab = static_cast<char *>(internalAllocator->blockAlloc(slabSize));
    } else {
        pointer8->numExternalAllocations++;
        slab = static_cast<char *>(slabAllocator->blockAlloc(slabSize));
    }
    if (pointer8->array10.getSize()) {
        Impl::FreeBlock &block = pointer8->freeBlocks.expandOne(*internalAllocator);
        block.end = slab;
        block.start = cur;
        block.slabIndex = pointer8->array10.getSize() - 1;
        slabStart = slab;
    }
    end = slab + slabSize;
    cur = slab + numBytes;
    pointer8->array10.pushBack(*internalAllocator, slab);
    return slab;
}
