/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

#define SPLAT(v, i) _mm_shuffle_ps((v), (v), _MM_SHUFFLE(i, i, i, i))

/* The next vertex of a triangle's edge (derived name). */
static const int D_14b8610[3] = {1, 2, 0};

/* A vertex's coordinates in the order A, B, C for the projection axis C (derived name). */
static inline Vec4 projectedAxes(const Vec4 &v, int axisC)
{
    if (axisC == 0) {
        return _mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 0, 2, 1));
    } else if (axisC == 1) {
        return _mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 1, 0, 2));
    }
    return v;
}

/* The projection integrals of a triangle (Mirtich's compProjectionIntegrals): over its three
 * edges, the vertices' coordinates taken in the order A, B (C the projection axis), the sums
 * kept in the members four to a vector, then scaled by Mirtich's divisors. */
// NONMATCHING: the axis selection's blocks (925 bytes against 919): the base tests axisC against 1
// first, then 0, and each of its three blocks reads the next vertex's index from D_14b8610 and both
// vertices itself (the next one with its permutation folded, the first one's A and B lanes splatted
// there); this compile reads the index once before the tests, tests 0 first and splats after the
// join. The arithmetic is Mirtich's term for term, grouped as the base groups it (a0_4 and b0_4 as
// squares of squares, Cabb and Kabb left to right), unmeasured past the blocks; 0x29f00 (its
// caller) is held at list-ilp's order.
void VolumeIntegrator00029b60::FUN_00029b60(const Vec4 *vertices)
{
    p1 = _mm_setzero_ps();
    pab = _mm_setzero_ps();
    paab = _mm_setzero_ps();
    pabb = _mm_setzero_ps();
    pa = _mm_setzero_ps();
    pb = _mm_setzero_ps();
    const Vec4 two = D_14b2060[4];
    const Vec4 three = D_14b2060[5];
    const Vec4 four = D_14b2060[6];
    for (int i = 0; i < 3; i++) {
        const Vec4 v1 = projectedAxes(vertices[D_14b8610[i]], axisC);
        const Vec4 v0 = projectedAxes(vertices[i], axisC);
        const Vec4 a0 = SPLAT(v0, 0);
        const Vec4 b0 = SPLAT(v0, 1);
        const Vec4 a1 = SPLAT(v1, 0);
        const Vec4 b1 = SPLAT(v1, 1);
        const Vec4 da = _mm_sub_ps(a1, a0);
        const Vec4 db = _mm_sub_ps(b1, b0);
        const Vec4 a0_2 = _mm_mul_ps(a0, a0);
        const Vec4 a0_3 = _mm_mul_ps(a0_2, a0);
        const Vec4 a0_4 = _mm_mul_ps(a0_2, a0_2);
        const Vec4 b0_2 = _mm_mul_ps(b0, b0);
        const Vec4 b0_3 = _mm_mul_ps(b0_2, b0);
        const Vec4 b0_4 = _mm_mul_ps(b0_2, b0_2);
        const Vec4 a1_2 = _mm_mul_ps(a1, a1);
        const Vec4 a1_3 = _mm_mul_ps(a1_2, a1);
        const Vec4 b1_2 = _mm_mul_ps(b1, b1);
        const Vec4 b1_3 = _mm_mul_ps(b1_2, b1);

        const Vec4 c1 = _mm_add_ps(a1, a0);
        const Vec4 ca = _mm_add_ps(_mm_mul_ps(a1, c1), a0_2);
        const Vec4 caa = _mm_add_ps(_mm_mul_ps(a1, ca), a0_3);
        const Vec4 caaa = _mm_add_ps(_mm_mul_ps(a1, caa), a0_4);
        const Vec4 cb = _mm_add_ps(_mm_mul_ps(b1, _mm_add_ps(b1, b0)), b0_2);
        const Vec4 cbb = _mm_add_ps(_mm_mul_ps(b1, cb), b0_3);
        const Vec4 cbbb = _mm_add_ps(_mm_mul_ps(b1, cbb), b0_4);
        const Vec4 cab = _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(three, a1_2), _mm_mul_ps(_mm_mul_ps(two, a1), a0)), a0_2);
        const Vec4 kab = _mm_add_ps(_mm_add_ps(a1_2, _mm_mul_ps(_mm_mul_ps(two, a1), a0)),
                                    _mm_mul_ps(three, a0_2));
        const Vec4 caab = _mm_add_ps(_mm_mul_ps(a0, cab), _mm_mul_ps(four, a1_3));
        const Vec4 kaab = _mm_add_ps(_mm_mul_ps(a1, kab), _mm_mul_ps(four, a0_3));
        const Vec4 cabb = _mm_add_ps(
            _mm_add_ps(_mm_add_ps(_mm_mul_ps(four, b1_3), _mm_mul_ps(_mm_mul_ps(three, b1_2), b0)),
                       _mm_mul_ps(_mm_mul_ps(two, b1), b0_2)),
            b0_3);
        const Vec4 kabb =
            _mm_add_ps(_mm_add_ps(_mm_add_ps(b1_3, _mm_mul_ps(_mm_mul_ps(two, b1_2), b0)),
                                  _mm_mul_ps(_mm_mul_ps(three, b1), b0_2)),
                       _mm_mul_ps(four, b0_3));

        p1 = _mm_add_ps(p1, _mm_mul_ps(db, c1));
        pa = _mm_add_ps(pa, _mm_mul_ps(db, _mm_movelh_ps(_mm_unpacklo_ps(ca, caa),
                                                         _mm_unpacklo_ps(caaa, two))));
        pb = _mm_add_ps(pb, _mm_mul_ps(da, _mm_movelh_ps(_mm_unpacklo_ps(cb, cbb),
                                                         _mm_unpacklo_ps(cbbb, two))));
        pab = _mm_add_ps(pab, _mm_mul_ps(db, _mm_add_ps(_mm_mul_ps(b1, cab), _mm_mul_ps(b0, kab))));
        paab = _mm_add_ps(paab,
                          _mm_mul_ps(db, _mm_add_ps(_mm_mul_ps(b1, caab), _mm_mul_ps(b0, kaab))));
        pabb = _mm_add_ps(pabb,
                          _mm_mul_ps(da, _mm_add_ps(_mm_mul_ps(a1, cabb), _mm_mul_ps(a0, kabb))));
    }
    p1 = _mm_mul_ps(p1, D_14b2060[18]);
    pa = _mm_mul_ps(pa, _mm_setr_ps(1.0f / 6.0f, 1.0f / 12.0f, 1.0f / 20.0f, 2.0f));
    pb = _mm_mul_ps(pb, _mm_setr_ps(-1.0f / 6.0f, -1.0f / 12.0f, -1.0f / 20.0f, -2.0f));
    pab = _mm_mul_ps(pab, _mm_set1_ps(1.0f / 24.0f));
    paab = _mm_mul_ps(paab, _mm_set1_ps(1.0f / 60.0f));
    pabb = _mm_mul_ps(pabb, _mm_set1_ps(-1.0f / 60.0f));
}
