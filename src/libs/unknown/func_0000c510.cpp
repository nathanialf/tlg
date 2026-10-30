/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hkResult hkFreeListMemorySystem::mainQuit(int flags)
{
    if (flags & FLAG_TEMPORARY) {
        const int bufferSize = int(bufferAllocator.bufferEnd - bufferAllocator.bufferStart);
        if (bufferSize) {
            baseAllocator->blockFree(bufferAllocator.bufferStart, bufferSize);
        }
    }
    if (flags & FLAG_ROUTER) {
        threadQuit(mainRouter, flags);
        bufferAllocator.FUN_00090a10(0, 0);
        if (extended20) {
            extended20->FUN_00003140();
        }
    }
    baseAllocator = 0;
    return HK_SUCCESS;
}
