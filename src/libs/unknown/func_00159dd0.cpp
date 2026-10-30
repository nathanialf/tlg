/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the handler of a subscribed world's constraint signal at
 * +0x5d8 (joined at 0x159d23): the constraint's two bodies stop colliding
 * with each other. */
void hknpConstraintCollisionFilter::FUN_00159dd0(hknpWorld *world, u32 constraintId)
{
    const hknpConstraint &constraint = world->constraintManager.constraints[constraintId];
    FUN_00167420(world, constraint.bodyIdA, constraint.bodyIdB);
}
