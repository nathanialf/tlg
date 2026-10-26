/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 2 of the slab allocator: bump the current slab's pointer when the
 * rounded request fits in a slab and in what is left of this one. */
void *Allocator0000ed40::blockAlloc(int numBytes)
{
    int size = (numBytes + 15) & ~15;
    char *block = cur;
    if (size <= slabSize) {
        char *blockEnd = block + size;
        if (blockEnd <= end) {
            cur = blockEnd;
            return block;
        }
    }
    return FUN_0000f090(size);
}
