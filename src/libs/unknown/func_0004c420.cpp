/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

// NONMATCHING: the walks, the signal's fire and the stores are the base's;
// the motion manager's address (`this+0x110`, the two calls' this) is one
// GEP in the entry here, CSEd from the motions' access (EarlyCSE) and
// spilled, where the base computes it in each arm (`add r15, 0x110`), and
// the fire's signal address is likewise kept in a register (NOTES "Round
// 75A").
void hknpWorld::FUN_0004c420(hknpBody *body)
{
    hknpMotion &motion = motionManager.motions[body->motionId];
    const int motionId = body->motionId;
    const int bodyId = body->id;
    if (body->nextAttachedBodyId == u32(bodyId)) {
        signals.motionDestroyedSignal.fire(this, motionId);
        motion.firstAttachedBodyId = 0x7fffffff;
        motionManager.FUN_000476a0(motionId);
    } else {
        hkArray<hknpBody> &bodies = bodyManager.bodies;
        int prevId = body->nextAttachedBodyId;
        while (bodies[prevId].nextAttachedBodyId != u32(bodyId)) {
            prevId = bodies[prevId].nextAttachedBodyId;
        }
        hknpBody &prev = bodies[prevId];
        if (&prev == body) {
            motion.firstAttachedBodyId = 0x7fffffff;
        } else {
            prev.nextAttachedBodyId = body->nextAttachedBodyId;
            motion.firstAttachedBodyId = prevId;
        }
        body->nextAttachedBodyId = bodyId;

        if (body->motionId != 0) {
            hknpMotion &oldMotion = motionManager.motions[body->motionId];
            if (oldMotion.solverId != 0x7fffffff) {
                const int firstId = oldMotion.firstAttachedBodyId;
                int id = firstId;
                do {
                    if (bodies[id].broadPhaseId != 0xffffffff) {
                        goto done;
                    }
                    id = bodies[id].nextAttachedBodyId;
                } while (id != firstId);
                motionManager.FUN_00047790(oldMotion, body->motionId);
            }
        }
    }
done:
    body->motionId = 0x7fffffff;
}
