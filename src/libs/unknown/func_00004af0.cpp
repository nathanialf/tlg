/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_libc.h"
#include "tlg_lib_unknown.h"

/* derived name: slot 3 of the system heap allocator's vtable (0x168ca00)
 * frees a block: the size leaves the bytes in use (an atomic subtraction,
 * since any thread may free), then the C library frees the memory. */
void hkMallocAllocator::blockFree(void *pointer, int numBytes)
{
    __sync_fetch_and_sub(&bytesInUse, numBytes);
    free(pointer);
}
