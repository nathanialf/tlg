/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"

/* derived name: the task's name for the dumps, its timer's (by the kind at
 * +0xd0), in the first state's fill colour. The interface's thunk of it
 * (0x15e850, slot 3 of the second vtable) is emitted beside it with the body
 * inlined. */
void hknpCollidePairsTask::getName(hkStringBuf *name, hkStringBuf *description) const
{
    FUN_000116c0(name, pairsKind == 1 ? "Collide/Existing Pairs" : "Collide/New Pairs");
    if (description) {
        FUN_000116c0(description, FUN_00091b30(0));
    }
}
