/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 4 of the adaptor: the buffer comes from the calling thread's router's
 * allocator at the same place, which may enlarge the request. */
void *RouterAllocator58::FUN_00008d70(int &numBytes)
{
    return D_16dc070->temp58->FUN_00008d70(numBytes);
}
