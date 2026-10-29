/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

hknpMalleableConstraintData::hknpMalleableConstraintData(hkpConstraintData *constraintData_,
                                                         bool wantRuntime)
    : hkpWrappedConstraintData(constraintData_)
{
    atom.type = hkpConstraintAtom::TYPE_BRIDGE;
    wantsRuntime = wantRuntime;
    strength = 0.01f;
    bridgeAtom(wantRuntime);
}
