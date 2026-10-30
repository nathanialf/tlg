/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the cell index of the motion of the record's second body. */
u8 FUN_0002afd0(const hknpWorld *world, const Pair08Owner *self) /* derived name */
{
    return world->motionManager.motions[world->bodyManager.bodies[self->second].motionId].cellIndex;
}
