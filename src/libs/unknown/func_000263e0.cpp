/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Four 16-bit values into the upper halves of the lanes. */
static inline __m128i loadUpperHalves(const s16 *values)
{
    const __m128i packed = _mm_loadl_epi64(reinterpret_cast<const __m128i *>(values));
    return _mm_unpacklo_epi16(_mm_setzero_si128(), packed);
}

/* A packed vector: each lane converted and scaled by the fourth lane's
 * bits taken as a float. */
static inline Vec4 unpackVector(const s16 *values)
{
    const __m128i bits = loadUpperHalves(values);
    const Vec4 exponent = _mm_castsi128_ps(_mm_shuffle_epi32(bits, 0xff));
    return _mm_mul_ps(_mm_cvtepi32_ps(bits), exponent);
}

void hkCompressedMassProperties::FUN_000263e0(hkDiagonalizedMassProperties &properties) const
{
    const __m128i axes = loadUpperHalves(majorAxisSpace);
    properties.inertiaTensor = unpackVector(inertia);
    properties.centerOfMass = unpackVector(centerOfMass);
    properties.volume = volume;
    properties.mass = mass;

    /* The quaternion: the sign bit flipped back, the lanes over 30000 in
     * the upper half, normalized by one refined reciprocal square root. */
    const __m128i bits = _mm_add_epi32(axes, _mm_castps_si128(D_14b41d0));
    const Vec4 q = _mm_mul_ps(_mm_cvtepi32_ps(bits), D_14b2060[49]);
    const Vec4 lengthSquared = _mm_dp_ps(q, q, 0xFF);
    const Vec4 e = _mm_rsqrt_ps(lengthSquared);
    const Vec4 invLength =
        _mm_mul_ps(_mm_mul_ps(e, D_14b4360),
                   _mm_sub_ps(D_14b4390, _mm_mul_ps(lengthSquared, _mm_mul_ps(e, e))));
    properties.majorAxisSpace.vec = _mm_mul_ps(q, invLength);
}
