/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"

/* derived name: slot 3 of the task: its name with its layer, and the first
 * state's fill colour as its description when one is asked for. */
void hknpBroadPhaseUpdateLayerTask::FUN_0018ce30(hkStringBuf *name,
                                                 hkStringBuf *description) const /* derived name */
{
    FUN_00011900(name, "BroadPhase/Update layer %i", layer);
    if (description) {
        FUN_000116c0(description, FUN_00091b30(0));
    }
}
