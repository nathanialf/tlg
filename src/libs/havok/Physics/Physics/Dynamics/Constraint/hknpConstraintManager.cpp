/* src/libs/havok/Physics/Physics/Dynamics/Constraint/hknpConstraintManager.cpp:
 * the file its report names (config/homes.base.txt, FUN_0016db90). */
#include "tlg_lib_unknown.h"

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

/* A constraint's name kept: the names grown to the capacity first, each new
 * one null, when the id is past them. derived name. */
void hknpConstraintManager::FUN_0016ddd0(unsigned int constraintId, const char *name)
{
    if (name && u32(names.getSize()) <= constraintId) {
        names.setSize(hkContainerHeapAllocator::get(), capacity, hkStringPtr(HK_NULL));
    }
    if (constraintId < u32(names.getSize())) {
        names[constraintId] = name;
    }
}
