/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 3 of the adaptor: the block goes back to the calling thread's
 * router's allocator at the same place. */
void RouterAllocator58::blockFree(void *pointer, int numBytes)
{
    D_16dc070->temp58->blockFree(pointer, numBytes);
}
