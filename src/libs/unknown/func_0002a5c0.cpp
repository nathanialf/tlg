/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hkMassProperties::FUN_0002a5c0(const Vec4 &scale)
{
    /* The volume and the mass grow with the magnitude of the scales'
     * product, the centre moves with the scale. */
    const Vec4 product =
        _mm_mul_ps(_mm_mul_ps(broadcast<1>(scale), broadcast<0>(scale)), broadcast<2>(scale));
    const Vec4 volumeScale = hkMath::quadFabs(product);
    mass *= _mm_cvtss_f32(volumeScale);
    volume *= _mm_cvtss_f32(volumeScale);
    centerOfMass = _mm_mul_ps(centerOfMass, scale);

    const Vec4 sx = broadcast<0>(scale);
    const Vec4 sy = broadcast<1>(scale);
    const Vec4 sz = broadcast<2>(scale);
    const Vec4 minScale = _mm_min_ps(sz, _mm_min_ps(sy, sx));
    const Vec4 maxScale = _mm_max_ps(sz, _mm_max_ps(sy, sx));
    if (_mm_cvtss_f32(maxScale) == _mm_cvtss_f32(minScale)) {
        /* A uniform scale: the inertia by the mass's growth and the square
         * of the scale. */
        const Vec4 inertiaScale = _mm_mul_ps(_mm_mul_ps(sx, sx), volumeScale);
        inertiaTensor.FUN_0001ac70(inertiaScale);
        return;
    }

    /* Otherwise through the second moments the diagonal holds, each scaled
     * by its axis's square; the products of inertia by the two axes'
     * scales. */
    const Vec4 i0 = broadcast<0>(inertiaTensor.col0);
    const Vec4 i1 = broadcast<1>(inertiaTensor.col1);
    const Vec4 i2 = broadcast<2>(inertiaTensor.col2);
    const Vec4 half = D_14b2060[18];
    const Vec4 xx = _mm_mul_ps(half, _mm_sub_ps(_mm_add_ps(i1, i2), i0));
    const Vec4 yy = _mm_mul_ps(half, _mm_sub_ps(_mm_add_ps(i0, i2), i1));
    const Vec4 zz = _mm_mul_ps(half, _mm_sub_ps(_mm_add_ps(i0, i1), i2));
    const Vec4 scale2 = _mm_mul_ps(scale, scale);
    const Vec4 sxx = _mm_mul_ps(broadcast<0>(scale2), xx);
    const Vec4 syy = _mm_mul_ps(broadcast<1>(scale2), yy);
    const Vec4 szz = _mm_mul_ps(broadcast<2>(scale2), zz);
    inertiaTensor.col0 =
        _mm_move_ss(inertiaTensor.col0, _mm_mul_ps(volumeScale, _mm_add_ps(syy, szz)));
    inertiaTensor.col1 =
        _mm_blend_ps(inertiaTensor.col1, _mm_mul_ps(volumeScale, _mm_add_ps(sxx, szz)), 2);
    inertiaTensor.col2 =
        _mm_blend_ps(inertiaTensor.col2, _mm_mul_ps(volumeScale, _mm_add_ps(sxx, syy)), 4);

    const Vec4 s = scale;
    const Vec4 fx = _mm_mul_ps(volumeScale, broadcast<0>(s));
    const Vec4 xy = _mm_mul_ps(broadcast<0>(inertiaTensor.col1), _mm_mul_ps(broadcast<1>(s), fx));
    const Vec4 xz = _mm_mul_ps(broadcast<0>(inertiaTensor.col2), _mm_mul_ps(broadcast<2>(s), fx));
    const Vec4 yz =
        _mm_mul_ps(broadcast<1>(inertiaTensor.col2),
                   _mm_mul_ps(broadcast<2>(s), _mm_mul_ps(volumeScale, broadcast<1>(s))));
    inertiaTensor.col0 = _mm_blend_ps(_mm_blend_ps(inertiaTensor.col0, xy, 2), xz, 4);
    inertiaTensor.col2 = _mm_blend_ps(_mm_move_ss(inertiaTensor.col2, xz), yz, 2);
    inertiaTensor.col1 = _mm_blend_ps(_mm_move_ss(inertiaTensor.col1, xy), yz, 4);
}
