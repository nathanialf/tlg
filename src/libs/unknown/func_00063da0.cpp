/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpWorldObject4f8::FUN_00063da0(int bodyId) /* derived name */
{
    const hknpBody &first = world->bodyManager.bodies[bodyId];
    world->bodyManager.FUN_001614f0(bodyId);
    MotionRecord &motionRecord = motionRecords[first.motionId];
    if (motionRecord.byteB != 0xff) {
        motionRecord.byteB = 0;
    }

    const int firstRecord = activatedBodies.getSize();
    int id = bodyId;
    do {
        const hknpBody &body = world->bodyManager.bodies[id];
        BodyRecord record;
        record.bodyId = hknpBodyId(body.id);
        record.byte7f = body.byte7f;
        activatedBodies.pushBack(record);
        id = body.nextAttachedBodyId;
    } while (id != bodyId);

    world->object1e0->unknownVirtual4(&activatedBodies[firstRecord].bodyId,
                                      activatedBodies.getSize() - firstRecord, sizeof(BodyRecord));
}
