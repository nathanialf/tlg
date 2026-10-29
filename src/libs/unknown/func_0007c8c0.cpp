/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Slot 7: both frames' rotations orthonormal, the cone's minimum the
 * unused -100, its maximum in [0, pi), and each of the planes' and the
 * twist's ranges ordered. */
hkBool hkpRagdollLimitsData::unknownVirtual7() const
{
    if (!atoms.rotations.rotationA.FUN_0000bde0() || !atoms.rotations.rotationB.FUN_0000bde0()) {
        return false;
    }
    if (atoms.coneLimit.minAngle != -100.0f) {
        return false;
    }
    if (atoms.coneLimit.maxAngle < 0.0f || atoms.coneLimit.maxAngle >= HK_REAL_PI) {
        return false;
    }
    if (atoms.planesLimit.minAngle > atoms.planesLimit.maxAngle) {
        return false;
    }
    return atoms.twistLimit.minAngle <= atoms.twistLimit.maxAngle;
}
