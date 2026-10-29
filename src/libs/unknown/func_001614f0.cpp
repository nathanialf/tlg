/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpBodyManager::FUN_001614f0(int bodyId)
{
    const int motionId = bodies[bodyId].motionId;
    hknpMotion &motion = motionManager->motions[motionId];
    int id = bodyId;
    do {
        hknpBody &body = bodies[id];
        if (body.broadPhaseId != 0xffffffff ||
            body.indexIntoActiveListOrDeactivatedIslandId != 0x7fffffff) {
            body.flags |= 8;
            body.indexIntoActiveListOrDeactivatedIslandId = activeBodyIds.getSize();
            activeBodyIds.pushBackUnchecked(id);
            activeBodyCellIndices[id] = motion.cellIndex;
        }
        id = body.nextAttachedBodyId;
    } while (id != bodyId);
    motionManager->FUN_00047720(motion, motionId);
}
