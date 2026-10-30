/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void BroadPhaseLayers00142a40::FUN_00142fa0(const SimulationContext00142fa0 *context, void *,
                                            void *argument3, void *argument4)
{
    D_16dc078->timerBegin("TtFindNewPairs");
    const int numEntries = layerPairs.getSize();
    if (numEntries > 0) {
        hknpCollisionFilter *const filter = context->world->modifierManager->collisionFilter.pntr;
        for (int i = 0; i < numEntries; i += 2) {
            BroadPhaseTree00142a40 *treeA = trees[layerPairs[i]];
            if (treeA->numEntries > 0) {
                BroadPhaseTree00142a40 *treeB = trees[layerPairs[i + 1]];
                if (treeB->numEntries > 0) {
                    FUN_00197c60(context, filter, treeA, treeB, argument4, argument3);
                }
            }
        }
    }
    D_16dc078->timerEnd("Et");
}
