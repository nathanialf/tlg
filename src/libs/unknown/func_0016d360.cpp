/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: everything empty, then the set-up. */
hknpConstraintManager::hknpConstraintManager(hknpWorld *world_, void *argument2, int argument3)
    : world(world_), constraints(0), capacity(0), firstFreeConstraintId(0), numUsedConstraints(0),
      peakConstraintId(0x7fffffff)
{
    FUN_0016d3f0(argument2, argument3);
}
