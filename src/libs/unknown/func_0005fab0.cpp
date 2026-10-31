/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpWorld::FUN_0005fab0(int bodyId)
{
    hknpBody &body = bodyManager.bodies[bodyId];
    if (body.flags & 2) {
        if ((body.flags & 9) == 0 && body.broadPhaseId != u32(-1)) {
            FUN_0004e0c0(bodyId);
        } else {
            hknpWorldObject4f8::MotionRecord &record = object4f8->motionRecords[body.motionId];
            if (record.byteB != 0xff) {
                record.byteB = 0;
            }
        }
    } else {
        FUN_0004e0f0(&body.aabb);
    }
    if (body.flags & 1) {
        int &index = bodyManager.scheduledBodyChangeIndices[bodyId];
        hknpBodyManager::ScheduledBodyChange *change;
        if (index == 0x7fffffff) {
            index = bodyManager.scheduledBodyChanges.getSize();
            change = new (&bodyManager.scheduledBodyChanges.expandOneUnconstructed())
                hknpBodyManager::ScheduledBodyChange();
            change->bodyId = bodyId;
        } else {
            change = &bodyManager.scheduledBodyChanges[index];
        }
        change->flags |= 4;
    }
    body.maxTimDistance = 0xffff;
    body.timAngle = 0xff;
    body.flags |= 0x1000;
}
