/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 2 of the buffer allocator: none for no bytes, else
 * the size rounded up to 128 bytes, asked for exactly. */
void *BufferAllocator::blockAlloc(int numBytes)
{
    if (numBytes == 0) {
        return 0;
    }
    int size = (numBytes + 127) & ~127;
    return FUN_00090b70(size, true);
}
