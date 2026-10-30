/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hkMemoryRouter *hkFreeListMemorySystem::FUN_0000c490(const SizePair00006c30 &sizes,
                                                     int flags) /* derived name */
{
    frameInfo = sizes;
    if (flags & FLAG_ROUTER) {
        threadInit(mainRouter, "main", flags);
    }
    if ((flags & FLAG_TEMPORARY) && sizes.first) {
        bufferAllocator.FUN_00090a10(baseAllocator->blockAlloc(sizes.first), sizes.first);
    }
    return &mainRouter;
}
