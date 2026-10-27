/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name (the interface slot's name, after TwoBaseAllocator's
 * overrider): a block of the size is allocated and given straight back. */
bool LargeBlockAllocator::FUN_00002230(int numBytes)
{
    void *block = blockAlloc(numBytes);
    if (block) {
        blockFree(block, numBytes);
        return true;
    }
    return false;
}
