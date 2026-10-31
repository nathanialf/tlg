/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpConstraintManager::FUN_0016df30(unsigned int constraintId)
{
    hknpConstraint &constraint = constraints[constraintId];
    hknpConstraint *const records = constraints;
    if (world) {
        lists.FUN_0017a2d0(constraintId, records, constraint.bodyIdA);
        lists.FUN_0017a2d0(constraintId, records, constraint.bodyIdB);
    }
    if (hkUlong(constraint.runtime) > 1) {
        D_16dc070->temp58->blockFree(constraint.runtime, constraint.runtimeSize);
    }
    constraint.data = HK_NULL;
    constraint.bodyIdA = 0x7fffffff;
    constraint.bodyIdB = firstFreeConstraintId;
    firstFreeConstraintId = constraintId;
    numUsedConstraints--;
}
