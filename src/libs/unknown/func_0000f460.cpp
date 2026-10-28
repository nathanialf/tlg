/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void Allocator0000ed40::FUN_0000f460(void *pointer, int numBytes)
{
    if (!pointer) {
        return;
    }
    if (numBytes > slabSize) {
        pointer8->numExternalAllocations--;
        largeAllocator->blockFree(pointer, numBytes);
        return;
    }
    const int rounded = (numBytes + 15) & ~15;
    if (static_cast<char *>(pointer) + rounded == cur) {
        cur = static_cast<char *>(pointer);
        FUN_0000f1e0();
    } else {
        FUN_0000f2f0(pointer, rounded);
    }
}

/* Slot 3, in the slow path's file: the slow path inline (0xef70). */
void Allocator0000ed40::blockFree(void *pointer, int numBytes)
{
    const int rounded = (numBytes + 15) & ~15;
    if (numBytes <= slabSize && static_cast<char *>(pointer) + rounded == cur &&
        pointer != slabStart) {
        cur = static_cast<char *>(pointer);
        return;
    }
    FUN_0000f460(pointer, rounded);
}
