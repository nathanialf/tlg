/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hkCompressedMassProperties::FUN_00026100(const hkDiagonalizedMassProperties &properties)
{
    reinterpret_cast<hkPackedVector3 *>(centerOfMass)->FUN_00092ef0(properties.centerOfMass);
    reinterpret_cast<hkPackedVector3 *>(inertia)->FUN_00092ef0(properties.inertiaTensor);

    /* Each lane times 30000 in the upper half, converted with saturation,
     * the sign bit flipped, the upper half kept. */
    const Vec4 scaled = _mm_mul_ps(D_14b2060[48], properties.majorAxisSpace.vec);
    const __m128 overflow = _mm_cmple_ps(_mm_set1_ps(2147483648.0f), scaled);
    const __m128i converted = _mm_add_epi32(
        _mm_castps_si128(_mm_xor_ps(_mm_castsi128_ps(_mm_cvttps_epi32(scaled)), overflow)),
        _mm_castps_si128(D_14b41d0));
    majorAxisSpace[0] = s16(_mm_extract_epi16(converted, 1));
    majorAxisSpace[1] = s16(_mm_extract_epi16(converted, 3));
    majorAxisSpace[2] = s16(_mm_extract_epi16(converted, 5));
    majorAxisSpace[3] = s16(_mm_extract_epi16(converted, 7));
    mass = properties.mass;
    volume = properties.volume;
}
