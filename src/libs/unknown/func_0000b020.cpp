/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 5 of the adaptor: the buffer goes back to the calling thread's
 * router's allocator at the same place. */
void RouterAllocator58::FUN_00008d80(void *pointer, int numBytes)
{
    D_16dc070->temp58->FUN_00008d80(pointer, numBytes);
}
