/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void BroadPhaseLayers00142a40::FUN_00142ea0(const BroadPhaseContext00142ea0 *context,
                                            void *pairsOut)
{
    D_16dc078->timerBegin("TtFindAllPairs");
    const int numIndices = layerPairs.getSize();
    hknpCollisionFilter *filter = context->world->modifierManager->collisionFilter.pntr;
    for (int i = 0; i < numIndices; i += 2) {
        FUN_00197c60(context, filter, trees[layerPairs[i]], trees[layerPairs[i + 1]], pairsOut, 0);
    }
    D_16dc078->timerEnd("Et");
}
