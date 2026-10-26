/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the linear velocity of a body, its motion's. */
const Vec4 &hknpWorld::FUN_0005df00(int bodyId) const /* derived name */
{
    return motions[bodies[bodyId].motionId].linearVelocity;
}
