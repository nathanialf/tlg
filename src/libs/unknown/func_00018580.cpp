/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

FreeList::FreeList(u64 newElementSize, u64 newAlignment, u64 newBlockSize,
                   AllocatorBase *newBlockAllocator, AllocatorBase *newElementAllocator)
{
    if (!newBlockAllocator) {
        newBlockAllocator = D_16dc070->temp58;
    }
    freeHead = 0;
    unknown18 = 0;
    freeBlocks = 0;
    blockSize = newBlockSize;
    unknown30 = newAlignment;
    top = blockEnd = 0;
    totalNumElements = numFreeElements = 0;
    blockAllocator = newBlockAllocator;
    elementAllocator = newElementAllocator;
    unknown10 = 0;
    elementSize = newElementSize < newAlignment
                      ? newAlignment
                      : (newElementSize + newAlignment - 1) & ~(newAlignment - 1);
    elementsPerBlock = newBlockSize / elementSize;
}
