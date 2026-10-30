/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpWorld::FUN_0005df30(int bodyId, Vec4 &angularVelocityOut) const
{
    const hknpMotion &motion = motionManager.motions[bodyManager.bodies[bodyId].motionId];
    angularVelocityOut = rotatedDir(motion.orientation, motion.angularVelocity);
}
