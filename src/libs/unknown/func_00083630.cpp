/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The frames orthonormal and the radius (or pitch) not zero: its
 * magnitude compared on vectors (`vucomiss` of two registers, the
 * epsilon's load kept apart, cookbook 101), the radius negated before it
 * is set into its vector, as the bytes have it. */
hkBool hkpRackAndPinionConstraintData::unknownVirtual7() const
{
    if (!atoms.transforms.transformA.rotation.FUN_0000bde0() ||
        !atoms.transforms.transformB.rotation.FUN_0000bde0()) {
        return false;
    }
    const Vec4 radius = _mm_set_ss(-atoms.rackAndPinion.pinionRadiusOrScrewPitch);
    return _mm_ucomigt_ss(hkMath::quadFabs(radius), _mm_set_ss(HK_REAL_EPSILON));
}
