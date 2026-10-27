/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 6 of the adaptor: the buffer resized by the calling thread's router's
 * allocator at the same place. */
void *RouterAllocator58::FUN_00008d90(void *pointer, int oldNumBytes, int &numBytesInOut)
{
    return D_16dc070->temp58->FUN_00008d90(pointer, oldNumBytes, numBytesInOut);
}
