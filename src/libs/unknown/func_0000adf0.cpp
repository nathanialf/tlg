/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 2 of the adaptor: the block comes from the calling thread's router's
 * allocator at the same place. */
void *RouterAllocator60::blockAlloc(int numBytes)
{
    return D_16dc070->allocator60->blockAlloc(numBytes);
}
