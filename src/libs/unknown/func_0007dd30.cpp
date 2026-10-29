/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

hkBool hkpRagdollConstraintData::unknownVirtual7() const
{
    if (atoms.ballSocket.solvingMethod == hkpConstraintAtom::METHOD_STABILIZED &&
        !atoms.setupStabilization.enabled) {
        return false;
    }
    if (!atoms.transforms.transformA.rotation.FUN_0000bde0() ||
        !atoms.transforms.transformB.rotation.FUN_0000bde0()) {
        return false;
    }
    if (atoms.coneLimit.minAngle != -100.0f) {
        return false;
    }
    if (atoms.coneLimit.maxAngle < 0.0f || atoms.coneLimit.maxAngle > HK_REAL_PI) {
        return false;
    }
    if (atoms.planesLimit.minAngle > atoms.planesLimit.maxAngle) {
        return false;
    }
    return atoms.twistLimit.minAngle <= atoms.twistLimit.maxAngle;
}
