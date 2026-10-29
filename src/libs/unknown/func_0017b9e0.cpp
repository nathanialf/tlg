/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Valid when a stabilized ball and socket has its stabilization set up,
 * both frames are orthonormal, the elliptical limit's angles lie within
 * [0, pi] and the twist's range is not reversed. */
hkBool hkp6DofConstraintData::FUN_0017b9e0() const
{
    if (blueprints.ballSocket.solvingMethod == 0 && !blueprints.setupStabilization.enabled) {
        return false;
    }
    if (!blueprints.transforms.transformA.rotation.FUN_0000bde0() ||
        !blueprints.transforms.transformB.rotation.FUN_0000bde0()) {
        return false;
    }
    const hkpEllipticalLimitConstraintAtom &limit = blueprints.ellipticalLimit;
    if (limit.maxAngle0 < 0.0f || limit.maxAngle0 > HK_REAL_PI || limit.maxAngle1 < 0.0f ||
        limit.maxAngle1 > HK_REAL_PI) {
        return false;
    }
    return blueprints.twistLimit.minAngle <= blueprints.twistLimit.maxAngle;
}
