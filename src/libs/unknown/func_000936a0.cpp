/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The w lane cleared (Havok's zeroComponent<3>). */
static inline Vec4 zeroW(const Vec4 &v)
{
    return _mm_blend_ps(v, _mm_setzero_ps(), 8);
}

/* The reciprocal, its estimate refined by one Newton step. */
static inline Vec4 reciprocal(const Vec4 &v)
{
    const Vec4 r = _mm_rcp_ps(v);
    return _mm_mul_ps(r, _mm_sub_ps(D_14b4380, _mm_mul_ps(v, r)));
}

void hkIntSpaceUtil::FUN_000936a0(const hkAabb &newAabb)
{
    aabb.min = newAabb.min;
    aabb.max = newAabb.max;
    const Vec4 span = _mm_sub_ps(newAabb.max, newAabb.min);
    const Vec4 spanInv = _mm_blend_ps(reciprocal(span), D_14b2060[3], 8);
    bitScale = _mm_mul_ps(spanInv, _mm_set1_ps(32767.0f));
    bitOffsetLow = _mm_xor_ps(newAabb.min, _mm_set1_ps(-0.0f));
    bitOffsetHigh = _mm_add_ps(_mm_mul_ps(span, _mm_set1_ps(1.0f / 32767.0f)), bitOffsetLow);
    bitScale = zeroW(bitScale);
    bitOffsetLow = zeroW(bitOffsetLow);
    bitOffsetHigh = zeroW(bitOffsetHigh);
    bitScaleInv = zeroW(reciprocal(bitScale));
}
