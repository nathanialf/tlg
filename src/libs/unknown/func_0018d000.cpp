/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"

/* derived name: slot 3 of the task: its name, and the second state's fill
 * colour as its description when one is asked for. */
void hknpBroadPhaseUpdateFinishedTask::FUN_0018d000(
    hkStringBuf *name, hkStringBuf *description) const /* derived name */
{
    FUN_000116c0(name, "BroadPhase/UpdateFinished");
    if (description) {
        FUN_000116c0(description, FUN_00091b30(1));
    }
}
