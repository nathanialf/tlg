/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 4 of the slab allocator: the request rounded up to 16 for the
 * caller, then cut from the current slab when it fits. */
void *Allocator0000ed40::FUN_00008d70(int &numBytes)
{
    numBytes = (numBytes + 15) & ~15;
    int size = numBytes;
    if (size <= slabSize) {
        char *block = cur;
        char *blockEnd = block + size;
        if (blockEnd <= end) {
            cur = blockEnd;
            return block;
        }
    }
    return FUN_0000f090(size);
}
