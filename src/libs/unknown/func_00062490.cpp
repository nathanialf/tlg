/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpWorldObject4f8::FUN_00062490(const hknpBodyId *bodyIds, int numBodyIds,
                                      int islandId) /* derived name */
{
    const hkAabb16 *previousAabbs = world->bodyManager.previousAabbs;
    for (int i = 0; i < numBodyIds; i++) {
        const u32 bodyId = bodyIds[i].value;
        hknpBody &body = world->bodyManager.bodies[bodyId];
        if (body.flags & hknpBody::IS_ACTIVE) {
            hknpMotion &motion = world->motionManager.motions[body.motionId];
            _mm_prefetch(reinterpret_cast<const char *>(&motion), _MM_HINT_NTA);
            world->bodyManager.FUN_00161630(bodyId);
            MotionRecord &record = motionRecords[body.motionId];
            if (record.byteB != 0xff) {
                record.byteB = 0;
            }
            motion.linearVelocity = _mm_setzero_ps();
            motion.angularVelocity = _mm_setzero_ps();
        }
        body.indexIntoActiveListOrDeactivatedIslandId = islandId;
        const hkAabb16 &previous = previousAabbs[bodyId];
        if (!previous.isEmpty()) {
            body.aabb = previous;
        }
    }
    world->object1e0->unknownVirtual4(bodyIds, numBodyIds, sizeof(hknpBodyId));
}
