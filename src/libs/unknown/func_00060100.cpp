/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpWorld::FUN_00060100(int bodyId, u32 collisionFilterInfo, int rebuildMode)
{
    hknpBody &body = bodyManager.bodies[bodyId];
    if (body.collisionFilterInfo != collisionFilterInfo) {
        body.collisionFilterInfo = collisionFilterInfo;
        if (rebuildMode == 0) {
            FUN_0005bf80(bodyId);
        }
        signals.bodyChangedSignal.fire(this, bodyId);
    }
}
