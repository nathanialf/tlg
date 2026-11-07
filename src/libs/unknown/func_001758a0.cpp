/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

// NONMATCHING: 104 of 116, two scheduling residuals (docs/NOTES.md, Round 73A): the info's
// address for slot 6 formed after its word's clear (the base forms it first), and the stack
// guard's GOT reload placed before the tail stores in the base, after them here.
void hknpConstraint::FUN_001758a0(u64 bodyUidA, u64 bodyUidB, hkpConstraintData *constraintData,
                                  hknpImmediateConstraintId constraintImmediateId)
{
    data = constraintData;
    unknown0 = u32(bodyUidA);
    bodyIdA = u32(bodyUidA >> 32);
    unknown8 = u32(bodyUidB);
    bodyIdB = u32(bodyUidB >> 32);

    hkpConstraintData::ConstraintInfo info;
    constraintData->unknownVirtual6(info);
    atoms = const_cast<void *>(info.atoms);
    if (constraintData->unknownVirtual5() == hkpConstraintData::CONSTRAINT_TYPE_BREAKABLE ||
        constraintData->unknownVirtual5() == hkpConstraintData::CONSTRAINT_TYPE_MALLEABLE) {
        type = u8(static_cast<const hkpWrappedConstraintData *>(constraintData)
                      ->getWrappedConstraintData()
                      ->unknownVirtual5());
    } else {
        type = u8(constraintData->unknownVirtual5());
    }
    sizeOfAtoms = u16(info.sizeOfAllAtoms);
    sizeOfSchemas = u16(info.sizeOfSchemas + info.unknown1c);
    numSolverElemTemps = u8(info.numSolverElemTemps);
    id = 0x7fffffff;
    immediateId = constraintImmediateId.value;
    flags = 3;
    numSolverResults = 0;
    runtimeSize = 0;
    /* 1: a runtime to be made; the destructor frees only a pointer above
     * it (tlg_lib_unknown.h). */
    runtime = reinterpret_cast<void *>(1);
}
