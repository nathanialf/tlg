/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* A vector scaled to unit length over x, y and z by the reciprocal square
 * root and one Newton step, with no test of its length (derived name). */
static inline Vec4 normalized3Unchecked(const Vec4 &v) /* derived name */
{
    const Vec4 lengthSquared = _mm_dp_ps(v, v, 0x7F);
    const Vec4 e = _mm_rsqrt_ps(lengthSquared);
    return _mm_mul_ps(
        v, _mm_mul_ps(_mm_mul_ps(e, D_14b4360),
                      _mm_sub_ps(D_14b4390, _mm_mul_ps(lengthSquared, _mm_mul_ps(e, e)))));
}

/* Slot 4: the hit's position scaled and transformed, its normal scaled,
 * rotated and renormalised, the hit added to the wrapped collector and its
 * early-out value taken. */
void hknpScaledQueryCollector::FUN_000cf8d0(const hknpCollisionResult &hit) /* derived name */
{
    hknpCollisionResult transformed = hit;
    transformed.position.quad = _mm_mul_ps(transformed.position.quad, positionScale);
    transformed.position.quad = transformPosition(*transform, transformed.position.quad);
    transformed.normal.quad = _mm_mul_ps(transformed.normal.quad, normalScale);
    const hkMatrix3 &rotation = transform->rotation;
    transformed.normal.quad = normalized3Unchecked(
        combineColumns(rotation.col0, rotation.col1, rotation.col2, transformed.normal.quad));
    childCollector->addHit(transformed);
    earlyOut = childCollector->earlyOut;
}
