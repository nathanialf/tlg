/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 12 of the vtable at 0x16a57a0 (the slot FUN_00171180
 * fills in 0x16a5870): a breakable constraint's solver results checked
 * against its threshold, the sum of the impulses' squares against the
 * threshold's square; past it, the constraint's command executed. */
void FUN_0016fbe0(void *self, CommandOwner00171180 *owner, const u32 &constraintId,
                  const hkpSolverResults *results)
{
    const ConstraintRecord0016fbe0 &constraint = owner->constraintTable->constraints[constraintId];
    const hknpBreakableConstraintData *data = constraint.data;
    float sumOfSquares = 0.0f;
    for (int i = 0; i < constraint.numSolverResults; i++) {
        sumOfSquares += results[i].impulseApplied * results[i].impulseApplied;
    }
    const float threshold = data->FUN_0003c270();
    if (sumOfSquares > threshold * threshold) {
        ConstraintCommand0016fbe0 command(constraintId);
        owner->dispatcher->exec(command);
    }
}
