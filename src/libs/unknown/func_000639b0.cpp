/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: an active body (flags bit 3) clears its motion record's
 * byte; any other body walks the entries from its entry's first id, running
 * 0x63a40 once for each. */
void hknpWorldObject4f8::FUN_000639b0(int bodyId)
{
    const hknpBody &body = world->bodyManager.bodies[bodyId];
    if (body.flags & 8) {
        MotionRecord &record = motionRecords[body.motionId];
        if (record.byteB != 0xff) {
            record.byteB = 0;
        }
        return;
    }
    const Entry18 *entry = unknown18[body.indexIntoActiveListOrDeactivatedIslandId];
    if (entry) {
        int id = entry->firstId;
        do {
            Entry18 *current = unknown18[id];
            const int nextId = current->nextId;
            if (!current->flag61) {
                current->flag61 = true;
                FUN_00063a40(id);
            }
            id = nextId;
        } while (id != 0x7fffffff);
    }
}
