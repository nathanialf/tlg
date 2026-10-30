/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpWorld::FUN_0005f9c0(int bodyId, u16 motionPropertiesId)
{
    bodyManager.FUN_00160f30(bodyId, motionPropertiesId);
    const hknpBody &body = bodyManager.bodies[bodyId];
    if (!(body.flags & hknpBody::IS_STATIC)) {
        motionManager.motions[body.motionId].motionPropertiesId = motionPropertiesId;
    }
    signals.bodyChangedSignal.fire(this, bodyId);
}
