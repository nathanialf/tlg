/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpBroadPhaseUpdateLayerTask::FUN_0018d130()
{
    ThreadBuffer &stream = *D_16dc078;
    stream.timerBeginList("Lt/Physics", "StCollide");
    stream.timerBegin("TtBroadPhase");
    BroadPhaseLayers00142a40 *layers = owner->layers;
    if (layers->trees[layer]->numEntries > 0) {
        if (layers->flag50[layer]) {
            FUN_00142a40(layers, owner->bodyManager->bodies.data, layer);
        } else if (layers->updatePending[layer]) {
            FUN_00142af0(layers, owner->bodyManager->bodies.data, layer, false);
        }
    }
    stream.timerEnd("Et");
    stream.timerEndList("lt");
}
