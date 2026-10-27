/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"

/* derived name: the task's name for the dumps, in the third state's fill
 * colour. */
void hknpPostCollideTask::getName(hkStringBuf *name, hkStringBuf *description) const
{
    FUN_000116c0(name, "Post Collide");
    if (description) {
        FUN_000116c0(description, FUN_00091b30(2));
    }
}
