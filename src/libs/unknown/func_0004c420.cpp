/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

// NONMATCHING: equal but for the registers of the attached bodies' walk
// (the bodies' storage in rsi and the next id in edx in the base, the other
// way round here). The motion read through the world's getMotion, inlined
// after its own InstCombine merged its GEP chain, leaves the motion
// manager's address to each arm as the base computes it (`add r15, 0x110`;
// round 75A's EarlyCSE residual, NOTES "Round 76A").
void hknpWorld::FUN_0004c420(hknpBody *body)
{
    hknpMotion &motion = getMotion(body->motionId);
    const int motionId = body->motionId;
    const int bodyId = body->id;
    if (body->nextAttachedBodyId == u32(bodyId)) {
        signals.motionDestroyedSignal.fire(this, motionId);
        motion.firstAttachedBodyId = 0x7fffffff;
        motionManager.FUN_000476a0(motionId);
    } else {
        int prevId = body->nextAttachedBodyId;
        hkArray<hknpBody> &bodies = bodyManager.bodies;
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
