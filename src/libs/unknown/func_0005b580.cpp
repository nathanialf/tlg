/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpWorld::FUN_0005b580(int bodyId, float value, int mode)
{
    const hknpBody &body = bodyManager.bodies[bodyId];
    bodyManager.FUN_00160e40(bodyId, value);
    if (!(body.flags & 5) && mode != 2) {
        FUN_0004bcd0(body.motionId);
    }
    signals.bodyChangedSignal.fire(this, bodyId);
}
