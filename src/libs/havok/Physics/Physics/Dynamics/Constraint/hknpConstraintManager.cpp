/* src/libs/havok/Physics/Physics/Dynamics/Constraint/hknpConstraintManager.cpp:
 * the file its report names (config/homes.base.txt, FUN_0016db90). */
#include "tlg_lib_unknown.h"

// NONMATCHING: one byte short of equal: the base adds the slot's address (`add rdi, rax`) right
// after the free link's load, so the peak's test takes eax (`cmp eax, imm32`); this compile adds
// it before the clear's call and the test takes ecx (NOTES Round 63B).
u32 hknpConstraintManager::FUN_0016db90()
{
    const u32 constraintId = firstFreeConstraintId;
    if (constraintId == 0x7fffffff) {
        HK_ERROR(0x606609a5, HK_NP_CONSTRAINT_MANAGER_CPP, 241, "Constraint buffer is full.");
        return 0x7fffffff;
    }
    hknpConstraint &constraint = constraints[constraintId];
    /* A free constraint's second body id links the next free one. */
    firstFreeConstraintId = constraint.bodyIdB;
    const u32 peak = u32(peakConstraintId);
    peakConstraintId =
        peak == 0x7fffffff ? constraintId : (peak > constraintId ? peak : constraintId);
    numUsedConstraints++;
    FUN_00018160(&constraint, 0, sizeof(hknpConstraint));
    fieldMap.FUN_001997d0(constraintId);
    return constraintId;
}
