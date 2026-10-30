/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the handler of a subscribed world's constraint signal at
 * +0x5e0 (joined at 0x159d73): the constraint's two bodies are handed back
 * to the pair filter. */
void hknpConstraintCollisionFilter::FUN_00159df0(hknpWorld *world, u32 constraintId)
{
    const hknpConstraint &constraint = world->constraintManager.constraints[constraintId];
    FUN_00167660(world, constraint.bodyIdA, constraint.bodyIdB, 1);
}
