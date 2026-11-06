/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpWorld::FUN_0005f390(int motionId, const Vec4 &centerOfMass)
{
    hknpMotion &motion = motionManager.motions[motionId];
    motion.centerOfMass = centerOfMass;
    const u32 firstBodyId = motion.firstAttachedBodyId;
    u32 bodyId = firstBodyId;
    do {
        hknpBody &body = bodyManager.bodies[bodyId];
        if (!(body.flags & 9)) {
            FUN_0004e0c0(bodyId);
        }
        const Vec4 centerOfMassLocal =
            transformInversePosition(body.transform, motion.centerOfMass);
        body.FUN_0003a670(centerOfMassLocal);
        body.FUN_0003a820(motion.centerOfMass);
        signals.bodyChangedSignal.fire(this, bodyId);
        bodyId = body.nextAttachedBodyId;
    } while (bodyId != firstBodyId);
}
