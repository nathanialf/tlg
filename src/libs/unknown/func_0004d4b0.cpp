/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpWorld::FUN_0004d4b0(const u32 *constraintIds, int numConstraintIds) /* derived name */
{
    for (int i = 0; i < numConstraintIds; i++) {
        const u32 constraintId = constraintIds[i];
        if (!(constraintManager.constraints[constraintId].flags & 4)) {
            signals.constraintRemovedSignal.fire(this, constraintId);
        }
        signals.constraintDestroyedSignal.fire(this, constraintId);
        constraintManager.FUN_0016df30(constraintId);
    }
}
