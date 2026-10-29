/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void *Allocator0000ed40::FUN_00008d90(void *pointer, int oldNumBytes, int &numBytesInOut)
{
    const int oldSize = (oldNumBytes + 15) & ~15;
    numBytesInOut = (numBytesInOut + 15) & ~15;
    char *block = static_cast<char *>(pointer);
    if (block + oldSize == cur && block + numBytesInOut <= end) {
        cur = block + numBytesInOut;
        return pointer;
    }
    void *newBlock = blockAlloc(numBytesInOut);
    FUN_000910e0(newBlock, pointer, hkMath::min2(oldSize, numBytesInOut));
    blockFree(pointer, oldSize);
    return newBlock;
}
