/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

TwoBaseAllocator::TwoBaseAllocator(AllocatorBase *large, AllocatorInterface *largeInterface,
                                   const TwoBaseAllocatorCinfo *cinfo)
    : criticalSection(4000), largeAllocator(large), allocator38(largeInterface), numFreeLists(0)
{
    FUN_00001ae0(cinfo);
}
