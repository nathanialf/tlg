/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the body taken off the active list, the last active body
 * moved into its slot; its flags marked inactive, its index reset. */
void hknpBodyManager::FUN_001615a0(int bodyId)
{
    hknpBody &body = bodies[bodyId];
    const int index = body.indexIntoActiveListOrDeactivatedIslandId;
    const int last = activeBodyIds.getSize() - 1;
    if (index < last) {
        const u32 movedBodyId = activeBodyIds[last];
        bodies[movedBodyId].indexIntoActiveListOrDeactivatedIslandId = index;
        activeBodyIds[index] = movedBodyId;
    }
    activeBodyIds.setSizeUnchecked(activeBodyIds.getSize() - 1);
    activeBodyCellIndices[bodyId] = 0xff;
    body.flags = (body.flags & ~0x1008) | 0x1000;
    body.indexIntoActiveListOrDeactivatedIslandId = 0x7fffffff;
}

/* derived name: every body of the attached group bodyId starts that is in
 * the broad phase taken off the active list as above, then the group's
 * motion handed to the motion manager. */
void hknpBodyManager::FUN_00161630(int bodyId)
{
    int id = bodyId;
    do {
        const hknpBody &body = bodies[id];
        if (body.broadPhaseId != 0xffffffff) {
            FUN_001615a0(id);
        }
        id = body.nextAttachedBodyId;
    } while (id != bodyId);
    const int motionId = bodies[bodyId].motionId;
    hknpMotion *motions = motionManager->motions.data;
    motionManager->FUN_00047790(motions[motionId], motionId);
}
