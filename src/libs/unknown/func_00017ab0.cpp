/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the memory setup undone (the game at 0xe99bcc): the memory
 * system taken down and destroyed in place, the instance cleared, then the
 * allocators' quit function run and forgotten. */
hkResult FUN_00017ab0()
{
    hkResult result = HK_SUCCESS;
    if (D_57b99e0) {
        result = D_57b99e0->mainQuit(3);
        D_57b99e0->~hkMemorySystem();
        D_57b99e0 = 0;
        FUN_00006c40(0);
    }
    if (D_57b99e8) {
        D_57b99e8();
        D_57b99e8 = 0;
    }
    return result;
}
