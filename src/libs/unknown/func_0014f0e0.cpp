/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"

/* derived name: the task's name for the dumps, its timer's, in the second
 * state's fill colour. */
void hknpCleanInactiveCachesTask::getName(hkStringBuf *name, hkStringBuf *description) const
{
    FUN_000116c0(name, "Deactivation/Clean Inactive Caches");
    if (description) {
        FUN_000116c0(description, FUN_00091b30(1));
    }
}
