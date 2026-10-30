/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: called by the step at 0x6d96e. */
void hknpWorldObject388::FUN_000f6a90(const hknpWorldStepContextf6a90 *context, void *argument1,
                                      void *argument2, void *argument3)
{
    hknpWorld *world = context->world;
    FUN_000c4cd0(world, &world->solverInfo, world->constraintManager.constraints,
                 world->constraintManager.peakConstraintId + 1, argument1, argument2, argument3);
}
