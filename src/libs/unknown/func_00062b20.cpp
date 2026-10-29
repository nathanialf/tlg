/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: a body with flags bit 1 marks its motion record: with the
 * flag set, a record marked 0xff is cleared; without it the record is
 * marked 0xff and, for a body in the broad phase that is neither active nor
 * bit 0, the entries from its entry's first id are walked, 0x63a40 run once
 * for each, as 0x639b0 walks them. */
void hknpWorldObject4f8::FUN_00062b20(int bodyId, bool flag)
{
    const hknpBody &body = world->bodyManager.bodies[bodyId];
    if (body.flags & 2) {
        MotionRecord &record = motionRecords[body.motionId];
        if (flag) {
            if (record.byteB == 0xff) {
                record.byteB = 0;
            }
        } else {
            record.byteB = 0xff;
            if ((body.flags & 9) == 0 && body.broadPhaseId != u32(-1)) {
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
        }
    }
}
