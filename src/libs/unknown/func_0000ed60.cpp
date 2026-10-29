/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void Allocator0000ed40::FUN_0000ed60(AllocatorBase *newSlabAllocator,
                                     AllocatorBase *newLargeAllocator,
                                     AllocatorBase *newInternalAllocator, int newSlabSize)
{
    pointer8 = new (newInternalAllocator->blockAlloc(sizeof(Impl))) Impl();
    pointer30 = 0;
    slabStart = 0;
    end = 0;
    cur = 0;
    slabAllocator = newSlabAllocator;
    largeAllocator = newLargeAllocator;
    internalAllocator = newInternalAllocator;
    slabSize = newSlabSize;
}
