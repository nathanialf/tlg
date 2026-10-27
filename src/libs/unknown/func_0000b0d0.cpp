/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 10 of the adaptor: the calling thread's router's allocator at the
 * same place answers. */
int RouterAllocator58::getAllocatedSize(const void *pointer, int numBytes) const
{
    return D_16dc070->temp58->getAllocatedSize(pointer, numBytes);
}
