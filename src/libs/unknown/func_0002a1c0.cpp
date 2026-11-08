/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The lane of a vector an index selects, in every lane (SSSE3's byte
 * shuffle, as hkVector4's getComponent of a run-time index). derived
 * name. */
static inline Vec4 componentAt(const Vec4 &v, int i) /* derived name */
{
    return _mm_castsi128_ps(
        _mm_shuffle_epi8(_mm_castps_si128(v), _mm_set1_epi32(i * 0x04040404 + 0x03020100)));
}

/* The lanes of a vector taken from the projection's order (A, B, C) into
 * x, y and z. derived name. */
static inline Vec4 fromProjection(const Vec4 &v, int c) /* derived name */
{
    if (c == 0) {
        return _mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 1, 0, 2));
    }
    if (c == 1) {
        return _mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 0, 2, 1));
    }
    return v;
}

// NONMATCHING: the preheader's zero (177 instructions against 178, 867 bytes as the base, the loop's
// alignment nop four bytes longer): MachineLICM hoists the axis mask's blend and its zero out of the loop
// and merges that zero with the one the three accumulators' phis start from (one V_SET0, a85/2b.pass),
// which the blend then shares with the products' accumulator in xmm2; the base zeroes a register of its
// own for the blend and three more for the phis. Everything else is the base's.
void VolumeIntegrator00029b60::FUN_0002a1c0(const hkGeometry &geometry, const Vec4 &offset)
{
    const int numTriangles = geometry.triangles.getSize();
    t1 = _mm_setzero_ps();
    t0 = _mm_setzero_ps();
    tp = _mm_setzero_ps();
    t2 = _mm_setzero_ps();
    for (int i = 0; i < numTriangles; i++) {
        const Vec4 *positions = geometry.vertices.begin();
        const hkGeometry::Triangle &triangle = geometry.triangles[i];
        Vec4 vertices[3];
        vertices[0] = _mm_add_ps(offset, positions[triangle.a]);
        vertices[1] = _mm_add_ps(offset, positions[triangle.b]);
        vertices[2] = _mm_add_ps(offset, positions[triangle.c]);
        Vec4 normal =
            cross3(_mm_sub_ps(vertices[1], vertices[0]), _mm_sub_ps(vertices[2], vertices[0]));
        const Vec4 lengthSquared = _mm_dp_ps(normal, normal, 0x7f);
        if (!(_mm_cvtss_f32(lengthSquared) > 0.0f)) {
            continue;
        }
        normal = _mm_mul_ps(normal, _mm_div_ps(D_14b2060[3], _mm_sqrt_ps(lengthSquared)));

        /* The projection axis: the normal's largest component. */
        const Vec4 magnitude = hkMath::quadFabs(normal);
        const Vec4 maxMagnitude = _mm_max_ps(
            broadcast<2>(magnitude), _mm_max_ps(broadcast<1>(magnitude), broadcast<0>(magnitude)));
        const Vec4 xyz = _mm_blend_ps(_mm_setzero_ps(), _mm_castsi128_ps(_mm_set1_epi32(-1)), 7);
        axisC = D_14c4160[_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(maxMagnitude, magnitude), xyz))];
        FUN_00029f00(vertices, normal);

        /* The face integrals by power: Fa, Fb, Fc; their squares; their
         * cubes. */
        const Vec4 a = fa;
        const Vec4 b = fb;
        const Vec4 c3 = fc;
        const Vec4 lo = _mm_unpacklo_ps(a, b);
        const Vec4 power1 = _mm_movelh_ps(lo, c3);
        const Vec4 power2 = _mm_shuffle_ps(_mm_movehl_ps(lo, lo), c3, _MM_SHUFFLE(3, 1, 1, 0));
        const Vec4 power3 = _mm_shuffle_ps(_mm_unpackhi_ps(a, b), c3, _MM_SHUFFLE(3, 2, 1, 0));
        fa = power1;
        fb = power2;
        fc = power3;

        t0 = _mm_add_ps(_mm_mul_ps(broadcast<0>(normal), componentAt(power1, 2 - axisC)), t0);
        t1 = _mm_add_ps(_mm_mul_ps(fromProjection(power2, axisC), normal), t1);
        t2 = _mm_add_ps(_mm_mul_ps(fromProjection(power3, axisC), normal), t2);
        Vec4 products;
        if (axisC == 0) {
            products = _mm_movelh_ps(_mm_unpacklo_ps(fcca, faab), broadcast<0>(fbbc));
        } else if (axisC == 1) {
            products = _mm_movelh_ps(_mm_unpacklo_ps(fbbc, fcca), broadcast<0>(faab));
        } else {
            products = _mm_movelh_ps(_mm_unpacklo_ps(faab, fbbc), broadcast<0>(fcca));
        }
        tp = _mm_add_ps(_mm_mul_ps(products, normal), tp);
    }
    t1 = _mm_mul_ps(D_14b2060[18], t1);
    t2 = _mm_mul_ps(t2, D_14b2060[19]);
    tp = _mm_mul_ps(D_14b2060[18], tp);
}
