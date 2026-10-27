/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"

/* derived name: the task's name for the dumps, its timer's (by the int at
 * +0x18), in the first state's fill colour. The interface's thunk of it
 * (0x155150, slot 6 of the second vtable) is emitted beside it with the body
 * inlined. */
void hknpBuildConstraintsTask::getName(hkStringBuf *name, hkStringBuf *description) const
{
    FUN_000116c0(name, unknown18 ? "Build Activated Constraints" : "Constraints/Build Active");
    if (description) {
        FUN_000116c0(description, FUN_00091b30(0));
    }
}
