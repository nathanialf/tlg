/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The bodies removed, then each destroyed: its signals dropped, its id
 * taken off its shape's watcher when the shape has signals, the destroyed
 * signal fired, a body with a motion detached from it (the motion first out
 * of its cell's list when the body heads its group and the motion is in
 * one), and the body given back. */
void hknpWorld::FUN_0004e980(const hknpBodyId *bodyIds, int numBodyIds, int mode)
{
    FUN_0004e5d0(bodyIds, numBodyIds, mode);
    for (int i = 0; i < numBodyIds; i++) {
        const hknpBodyId bodyId = bodyIds[i];
        hknpBody &body = bodyManager.bodies[bodyId.value];
        eventDispatcher->FUN_0006c050(bodyId);
        if (body.shape->unknownVirtual8()) {
            shapeWatchers.FUN_00156110(&body);
        }
        if (untagSlotLink(signals.bodyDestroyedSignal.slots)) {
            ThreadBuffer &stream = *D_16dc078;
            stream.timerBegin("TtFireBodyDestroyed");
            signals.bodyDestroyedSignal.fire(this, bodyId.value);
            stream.timerEnd("Et");
        }
        const int motionId = body.motionId;
        if (motionId) {
            if (body.nextAttachedBodyId == bodyId.value) {
                hknpMotion &motion = motionManager.motions[motionId];
                if (motion.solverId != 0x7fffffff) {
                    motionManager.FUN_00047790(motion, motionId);
                }
            }
            FUN_0004c420(&body);
        }
        bodyManager.FUN_00160660(bodyId.value);
    }
}
