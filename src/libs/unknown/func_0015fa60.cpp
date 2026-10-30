/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The cross product of two vectors' first three lanes, the products in
 * Havok's order: a by b's rotated lanes, b by a's (derived name). */
static inline Vec4 cross(Vec4 a, Vec4 b)
{
    const Vec4 c0 = _mm_mul_ps(a, _mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 0, 2, 1)));
    const Vec4 c1 = _mm_mul_ps(b, _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 0, 2, 1)));
    const Vec4 d = _mm_sub_ps(c0, c1);
    return _mm_shuffle_ps(d, d, _MM_SHUFFLE(3, 0, 2, 1));
}

/* Slot 5 of hknpCircularSurfaceVelocity's vtable (address point
 * 0x16a4f60): the angular velocity handed out, and its cross product with
 * the point's offset from the pivot. */
void hknpCircularSurfaceVelocity::calcVelocities(const hkVector4 &position, const hkVector4 &,
                                                 const hknpBody &,
                                                 hkVector4 *HK_RESTRICT linearVelocityOut,
                                                 hkVector4 *HK_RESTRICT angularVelocityOut) const
{
    angularVelocityOut->quad = angularVelocity.quad;
    const Vec4 offset = _mm_sub_ps(position.quad, pivot.quad);
    linearVelocityOut->quad = cross(angularVelocity.quad, offset);
}
