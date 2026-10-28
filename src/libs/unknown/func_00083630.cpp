/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The magnitude of each lane, as FUN_0001add0's file spells it (cookbook
 * 70). derived name. */
static inline Vec4 absLanes(const Vec4 &v) /* derived name */
{
    const __m128i bits = _mm_castps_si128(v);
    return _mm_castsi128_ps(_mm_srli_epi32(_mm_add_epi32(bits, bits), 1));
}

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
    return _mm_ucomigt_ss(absLanes(radius), _mm_set_ss(HK_REAL_EPSILON));
}
