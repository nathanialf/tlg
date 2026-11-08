/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 2, the class's key function: the vtable and the inline destructors
 * are emitted here (0x14a50, slots 0 and 1, one body after the linker's
 * folding). */
void *FixedSizeAllocator::blockAlloc(int numBytes)
{
    return freeList.alloc();
}
