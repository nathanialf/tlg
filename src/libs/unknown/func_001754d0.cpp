/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: 157 of 159, the residual of its siblings 0x175710 and 0x1758a0 (docs/NOTES.md,
// Round 76B): list-ilp's BURRSort orders the info's address (`lea rsi, [rbp-0x50]`, its frame
// index created at the constructor's GEP) after the constructor's clear of +0x1c, where the base
// forms the address first.
void hknpConstraint::FUN_001754d0(BodyKey0016e040 keyA, BodyKey0016e040 keyB,
                                  hkpConstraintData *constraintData, u32 constraintId,
                                  u8 constraintFlags)
{
    data = constraintData;
    unknown0 = u32(keyA.key);
    bodyIdA = u32(keyA.key >> 32);
    unknown8 = u32(keyB.key);
    bodyIdB = u32(keyB.key >> 32);

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
    id = constraintId;
    immediateId = 0xffff;
    flags = constraintFlags & ~2;
    if (constraintData->unknownVirtual5() == hkpConstraintData::CONSTRAINT_TYPE_BREAKABLE) {
        flags |= 0x81;
    }

    ConstraintRuntimeInfo runtimeInfo;
    constraintData->unknownVirtual20(flags & 1, runtimeInfo);
    numSolverResults = u8(runtimeInfo.numSolverResults);
    runtime = HK_NULL;
    const int size = runtimeInfo.sizeOfExternalRuntime;
    if (size) {
        runtime = D_16dc070->temp58->blockAlloc(size);
        hkString::memSet4(runtime, 0, u32(size) >> 2);
    }
    runtimeSize = u16(size);
}
