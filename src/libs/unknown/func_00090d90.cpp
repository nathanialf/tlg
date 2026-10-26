/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 3 of the buffer allocator's vtable (address point
 * 0x16a3470): a block is given back through slot 5 at its size rounded up
 * to the allocator's 128-byte granule; a null block or a size of 0 is
 * nothing to free. */
void BufferAllocator::blockFree(void *pointer, int numBytes) /* derived name */
{
    if (pointer && numBytes) {
        FUN_00008d80(pointer, (numBytes + 127) & ~127);
    }
}
