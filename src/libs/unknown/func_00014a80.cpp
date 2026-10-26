/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the fixed-size allocator's set-up, its free list's with the
 * alignment raised to 32 and no element allocator. */
void FixedSizeAllocator::FUN_00014a80(u64 elementSize, u64 alignment, u64 blockSize,
                                      AllocatorBase *blockAllocator)
{
    freeList.FUN_000186a0(elementSize, alignment > 32 ? alignment : 32, blockSize, blockAllocator,
                          0);
}
