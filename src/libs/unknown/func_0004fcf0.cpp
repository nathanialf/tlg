/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpWorld::FUN_0004fcf0(u32 constraintId)
{
    hknpConstraint &constraint = constraintManager.constraints[constraintId];
    if ((constraint.flags & 4) == 0) {
        constraint.flags |= 4;
        signals.constraintRemovedSignal.fire(this, constraintId);
    }
}
