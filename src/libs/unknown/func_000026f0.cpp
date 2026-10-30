/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

bool TwoBaseAllocator::FUN_000026f0()
{
    criticalSection.enter();
    bool ok = true;
    for (int i = 0; i < numFreeLists; i++) {
        if (!freeLists[i]->FUN_000188c0()) {
            ok = false;
            break;
        }
    }
    criticalSection.leave();
    return ok;
}
