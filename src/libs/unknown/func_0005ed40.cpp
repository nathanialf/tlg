/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Defined beside its callers in the world's file: the impulse below holds
 * it inline (0x5ede0 to 0x5ee22), 0x1562a0 calls it. */
void hknpWorld::FUN_0005b490(int firstBodyId, void *argument)
{
    const hknpBodyQualityLibrary *qualities = qualityLibrary;
    int bodyId = firstBodyId;
    do {
        hknpBody &body = bodyManager.bodies[bodyId];
        FUN_000cd040(&body, argument, &qualities->qualities[body.qualityId], &vector250,
                     &solverInfo, &intSpaceUtil);
        bodyId = body.nextAttachedBodyId;
    } while (bodyId != firstBodyId);
}

void hknpWorld::FUN_0005ed40(int bodyId, const Vec4 &impulse, const Vec4 &position)
{
    const hknpBody &body = bodyManager.bodies[bodyId];
    if (body.flags & 2) {
        if (!(body.flags & 9)) {
            FUN_0004e0c0(bodyId);
        }
        hknpMotion &motion = motionManager.motions[body.motionId];
        motion.FUN_00157a20(impulse, position);
        FUN_0005b490(bodyId, &motion);
        signals.bodyChangedSignal.fire(this, bodyId);
    }
}
