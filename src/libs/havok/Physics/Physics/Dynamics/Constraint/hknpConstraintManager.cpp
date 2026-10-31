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

// NONMATCHING: the base inlines a setSize with a fill that destroys the
// names past n from the last and copy-constructs the new ones; written
// that way (Havok's form, the inline hint on the in-class declaration) this
// function reaches 92 of 98 (the destruct loop's n sign-extended before the
// storage is loaded in the base), but 0x16dc90's u32 fill then loads the
// storage after the extension where the base loads it first: the two forms
// are not yet one source (docs/NOTES.md, Round 68A). setSize is left as it
// was.
void hknpConstraintManager::FUN_0016ddd0(unsigned int constraintId, const char *name)
{
    if (name && u32(names.getSize()) <= constraintId) {
        names.setSize(hkContainerHeapAllocator::get(), capacity, hkStringPtr(HK_NULL));
    }
    if (constraintId < u32(names.getSize())) {
        names[constraintId] = name;
    }
}
