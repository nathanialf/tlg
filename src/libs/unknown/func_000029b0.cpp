/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void *TwoBaseAllocator::blockAlloc(int numBytes)
{
    return FUN_00008d70(numBytes);
}
