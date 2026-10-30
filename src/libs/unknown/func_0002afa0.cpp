/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the cell index of the motion of the record's first body. */
u8 FUN_0002afa0(const hknpWorld *world, const Pair08Owner *self) /* derived name */
{
    return world->motionManager.motions[world->bodyManager.bodies[self->first].motionId].cellIndex;
}
