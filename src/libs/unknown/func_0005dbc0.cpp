/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpWorld::FUN_0005dbc0(int bodyId, Vec4 &linearVelocityOut, Vec4 &angularVelocityOut) const
{
    const hknpMotion &motion = motions[bodyManager.bodies[bodyId].motionId];
    linearVelocityOut = motion.linearVelocity;
    angularVelocityOut = rotatedDir(motion.orientation, motion.angularVelocity);
}
