/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The frames orthonormal and neither wheel's radius zero: each magnitude
 * compared on vectors, the radius negated before it is set into its vector,
 * as the rack and pinion's slot 7 does (0x83630, cookbook 142). */
hkBool hkpCogWheelConstraintData::unknownVirtual7() const
{
    if (!atoms.transforms.transformA.rotation.FUN_0000bde0() ||
        !atoms.transforms.transformB.rotation.FUN_0000bde0()) {
        return false;
    }
    const Vec4 radiusA = _mm_set_ss(-atoms.cogWheels.cogWheelRadiusA);
    if (!_mm_ucomigt_ss(hkMath::quadFabs(radiusA), _mm_set_ss(HK_REAL_EPSILON))) {
        return false;
    }
    const Vec4 radiusB = _mm_set_ss(-atoms.cogWheels.cogWheelRadiusB);
    return _mm_ucomigt_ss(hkMath::quadFabs(radiusB), _mm_set_ss(HK_REAL_EPSILON));
}
