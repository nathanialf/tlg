/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"

/* derived name: slot 3 of the task: its name with the two layers of its
 * pair, and the first state's fill colour as its description when one is
 * asked for. */
void BroadPhaseCollideTask::getName(hkStringBuf *name, hkStringBuf *description) const
{
    const int *pair = &owner->layers->layerPairs[2 * index];
    FUN_00011900(name, "BroadPhase/Collide %i vs %i", pair[0], pair[1]);
    if (description) {
        FUN_000116c0(description, FUN_00091b30(0));
    }
}
