/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The setup the constructor at 0x18580 does, after what the list held is
 * given back. */
void FreeList::FUN_000186a0(u64 newElementSize, u64 newAlignment, u64 newBlockSize,
                            AllocatorBase *newBlockAllocator, AllocatorBase *newElementAllocator)
{
    FUN_00018770();
    if (!newBlockAllocator) {
        newBlockAllocator = D_16dc070->temp58;
    }
    freeHead = 0;
    activeBlocks = 0;
    freeBlocks = 0;
    blockSize = newBlockSize;
    unknown30 = newAlignment;
    top = blockEnd = 0;
    totalNumElements = numFreeElements = 0;
    blockAllocator = newBlockAllocator;
    elementAllocator = newElementAllocator;
    cursor = 0;
    elementSize = newElementSize < newAlignment
                      ? newAlignment
                      : (newElementSize + newAlignment - 1) & ~(newAlignment - 1);
    elementsPerBlock = newBlockSize / elementSize;
}
