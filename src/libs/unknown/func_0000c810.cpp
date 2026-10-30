/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hkFreeListMemorySystem::threadQuit(hkMemoryRouter &router, int flags)
{
    ThreadData &thread = threads[router.threadIndex];
    if (flags & FLAG_TEMPORARY) {
        router.stack.FUN_0000ee00(0);
        thread.memory.FUN_00014690();
        router.allocator50 = 0;
        router.pointer68 = 0;
    }
    if (flags & FLAG_ROUTER) {
        thread.memory.FUN_00014690();
        thread.pointer198 = 0;
        thread.inUse = false;
        FUN_00018160(&router, 0, sizeof(hkMemoryRouter));
    }
}
