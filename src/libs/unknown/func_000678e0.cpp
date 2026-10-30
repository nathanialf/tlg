/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hknpMalleableConstraintData::hknpMalleableConstraintData(hkpConstraintData *constraintData_,
                                                         bool wantRuntime)
    : hkpWrappedConstraintData(constraintData_)
{
    atom.type = hkpConstraintAtom::TYPE_BRIDGE;
    wantsRuntime = wantRuntime;
    strength = 0.01f;
    bridgeAtom(wantRuntime);
}

/* Slot 29: a new malleable data over a deep copy of the wrapped data, whose
 * reference the new data holds, with this one's runtime wish and strength. */
hkpConstraintData *hknpMalleableConstraintData::clone() const
{
    hkpConstraintData *childClone = FUN_000794c0(getWrappedConstraintData());
    hknpMalleableConstraintData *copy = new hknpMalleableConstraintData(childClone, wantsRuntime);
    childClone->removeReference();
    copy->strength = strength;
    return copy;
}
