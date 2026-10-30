/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpWorld::FUN_0004fc10(u32 constraintId, hkBool32 keepInactive) /* derived name */
{
    hknpConstraint &constraint = constraints[constraintId];
    if (constraint.flags & 4) {
        constraint.flags &= ~4;
        FUN_0004d400(&constraint, keepInactive);
        signals.constraintAddedSignal.fire(this, constraintId);
    }
}
