/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the body marked active and appended to the active list,
 * its motion's cell kept beside it. */
void hknpBodyManager::FUN_00161490(int bodyId)
{
    hknpBody &body = bodies[bodyId];
    const hknpMotion &motion = motionManager->motions[body.motionId];
    body.flags |= 0x1008;
    body.indexIntoActiveListOrDeactivatedIslandId = activeBodyIds.getSize();
    activeBodyIds.pushBackUnchecked(bodyId);
    activeBodyCellIndices[bodyId] = motion.cellIndex;
}
