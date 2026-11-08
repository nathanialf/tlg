/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

float hkpLinearParametricCurve::FUN_0007f650(float t, const Vec4 &nearPoint,
                                             Vec4 &pointOnCurve) const
{
    int ia = hkMath::max2(0, int(t));
    int ib = ia + 1;
    if (ib >= points.getSize()) {
        ib = points.getSize() - 1;
        ia = ib - 1;
    }

    Vec4 fraction;
    for (;;) {
        const Vec4 ab = _mm_sub_ps(points[ib], points[ia]);
        const Vec4 lengthSquared = _mm_dp_ps(ab, ab, 0x7f);
        const Vec4 projection = _mm_dp_ps(ab, _mm_sub_ps(nearPoint, points[ia]), 0x7f);
        const Vec4 r = _mm_rcp_ps(lengthSquared);
        fraction = _mm_mul_ps(projection, _mm_mul_ps(r, _mm_sub_ps(_mm_load_ps(D_14b4380),
                                                                   _mm_mul_ps(lengthSquared, r))));
        if (_mm_ucomilt_ss(fraction, _mm_setzero_ps())) {
            if (ia == 0) {
                break;
            }
            ia--;
            ib--;
            continue;
        }
        const Vec4 bp = _mm_sub_ps(nearPoint, points[ib]);
        if (!_mm_ucomigt_ss(_mm_dp_ps(ab, bp, 0x7f), _mm_setzero_ps())) {
            break;
        }
        const int ic = ib + 1;
        if (ic >= points.getSize()) {
            break;
        }
        const Vec4 bc = _mm_sub_ps(points[ic], points[ib]);
        if (_mm_ucomigt_ss(_mm_dp_ps(bc, bp, 0x7f), _mm_setzero_ps())) {
            ia++;
            ib = ic;
            continue;
        }
        const Vec4 alongAb = _mm_dp_ps(bp, normalized3(ab), 0x7f);
        const Vec4 alongBc = negateScalar(_mm_dp_ps(bp, normalized3(bc), 0x7f));
        const hkBool32 nearerAb = _mm_ucomigt_ss(alongBc, alongAb);
        fraction = nearerAb ? _mm_set1_ps(0.99f) : _mm_set1_ps(0.01f);
        if (!nearerAb) {
            ia++;
            ib = ic;
        }
        break;
    }

    const Vec4 a = points[ia];
    pointOnCurve = _mm_add_ps(a, _mm_mul_ps(fraction, _mm_sub_ps(points[ib], a)));
    const float result = _mm_cvtss_f32(fraction) + float(ia);
    if (closedLoop) {
        const float last = float(points.getSize() - 1);
        if (result < 0.25f) {
            return FUN_0007f650(last - (1.0f - result), nearPoint, pointOnCurve);
        }
        if (result > last + -0.25f) {
            return FUN_0007f650((result - last) + 1.0f, nearPoint, pointOnCurve);
        }
    }
    return result;
}
