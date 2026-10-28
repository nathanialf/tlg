/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpWorldObject4f8::FUN_00063930(int bodyId) /* derived name */
{
    const hknpBody &body = world->bodyManager.bodies[bodyId];
    if (body.flags & 8) {
        BodyRecord record;
        record.bodyId = hknpBodyId(body.id);
        record.byte7f = body.byte7f;
        bodyRecords.pushBack(record);
    }
}
