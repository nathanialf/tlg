/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: an active body (flags bit 3) taken off the body manager's
 * active list, the whole attached group when the body is alone in it. */
void hknpWorld::FUN_0004c720(const hknpBody *body)
{
    if (body->flags & 8) {
        const int bodyId = body->id;
        if (body->nextAttachedBodyId == static_cast<u32>(bodyId)) {
            bodyManager.FUN_00161630(bodyId);
        } else {
            bodyManager.FUN_001615a0(bodyId);
            bodyManager.bodies[bodyId].indexIntoActiveListOrDeactivatedIslandId = 0x7fffffff;
        }
    }
}
