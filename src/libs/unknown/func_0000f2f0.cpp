/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* A block freed out of order recorded among the freed blocks, kept by slab
 * and by address: the slab it sits in found from the last, the block
 * joined to a freed block of that slab it ends or starts, else inserted
 * before the first one above it; then the end of the last freed block kept
 * at +0x28, as 0xf1e0 keeps it. */
void Allocator0000ed40::FUN_0000f2f0(void *pointer, int numBytes)
{
    Impl *impl = pointer8;
    int slabIndex = -1;
    for (int i = impl->array10.size - 1; i >= 0; i--) {
        if (hkUlong(pointer) - hkUlong(impl->array10[i]) < hkUlong(slabSize)) {
            slabIndex = i;
            break;
        }
    }
    char *const start = static_cast<char *>(pointer);
    char *const blockEnd = start + numBytes;
    hkArray<Impl::FreeBlock> &freeBlocks = impl->freeBlocks;
    int insertIndex = 0;
    for (int i = freeBlocks.size - 1; i >= 0; i--) {
        Impl::FreeBlock &block = freeBlocks[i];
        if (block.slabIndex == slabIndex) {
            if (block.end == start) {
                block.end = blockEnd;
                goto done;
            }
            if (blockEnd == block.start) {
                block.start = start;
                goto done;
            }
            if (block.start < start) {
                insertIndex = i + 1;
                break;
            }
        } else if (block.slabIndex < slabIndex) {
            insertIndex = i + 1;
            break;
        }
    }
    {
        Impl::FreeBlock *block = freeBlocks.expandAt(*internalAllocator, insertIndex, 1);
        block->start = start;
        block->end = blockEnd;
        block->slabIndex = slabIndex;
    }
done:
    const int numFree = pointer8->freeBlocks.getSize();
    slabStart = numFree ? pointer8->freeBlocks[numFree - 1].end : HK_NULL;
}
