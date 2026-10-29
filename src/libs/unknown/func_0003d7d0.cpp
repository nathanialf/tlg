/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpMotionWeldTOICommand::FUN_0003d7d0(const hknpWorld *world, Output0002b3b0 *out) const
{
    const int bodyA = FUN_00010650(record);
    const int bodyB = FUN_00034840(record);
    const hknpMotion *motionA = &world->motions[world->bodyManager.bodies[bodyA].motionId];
    const hknpMotion *motionB = &world->motions[world->bodyManager.bodies[bodyB].motionId];
    FUN_00034920(record, &world->solverInfo, motionA, motionB, out);
}
