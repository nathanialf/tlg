/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

hkBool hkpLimitedHingeConstraintData::unknownVirtual7() const
{
    if (atoms.ballSocket.solvingMethod == hkpConstraintAtom::METHOD_STABILIZED &&
        !atoms.setupStabilization.enabled) {
        return false;
    }
    return atoms.transforms.transformA.rotation.FUN_0000bde0() &&
           atoms.transforms.transformB.rotation.FUN_0000bde0() &&
           (!atoms.angMotor.isEnabled || atoms.angLimit.isEnabled);
}
