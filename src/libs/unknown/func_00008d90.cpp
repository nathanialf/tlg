/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: a buffer resized by moving it: a new one from slot 4, as
 * much of the old copied as both hold, the old one freed through slot 5. */
void *AllocatorBase::FUN_00008d90(void *pointer, int oldNumBytes, int &numBytesInOut)
{
    void *newPointer = FUN_00008d70(numBytesInOut);
    if (newPointer) {
        FUN_000910e0(newPointer, pointer, hkMath::min2(oldNumBytes, numBytesInOut));
    }
    FUN_00008d80(pointer, oldNumBytes);
    return newPointer;
}
