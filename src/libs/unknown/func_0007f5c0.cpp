/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the point at a parameter, interpolated between the points
 * on either side of it; past the last point, the last segment's start. */
void hkpLinearParametricCurve::FUN_0007f5c0(float t, Vec4 &pointOnCurve) const
{
    const int ia = hkMath::max2(0, int(t));
    const Vec4 &a = points[ia];
    const int ib = ia + 1;
    if (ib < points.getSize()) {
        const Vec4 diff = _mm_sub_ps(points[ib], a);
        const Vec4 fraction = _mm_sub_ps(simdFromFloat(t), simdFromFloat(float(ia)));
        pointOnCurve = _mm_add_ps(a, _mm_mul_ps(fraction, diff));
    } else {
        pointOnCurve = a;
    }
}

/* derived name: the tangent at a parameter, the direction of the segment
 * the parameter falls in, blended within the smoothing factor of either end
 * of the segment toward the neighbouring segment's direction (half way at
 * the end), the indices stepped to that segment; each blend is made and
 * normalized in the output (the base reads the half's constant again after
 * each store, so each product takes the estimate first). */
void hkpLinearParametricCurve::FUN_0007f870(float t, Vec4 &tangent) const
{
    const Vec4 tv = simdFromFloat(t);
    const Vec4 smoothing = _mm_set1_ps(smoothingFactor);
    const Vec4 r = _mm_rcp_ps(smoothing);
    const Vec4 invSmoothing =
        _mm_mul_ps(r, _mm_sub_ps(_mm_load_ps(D_14b4380), _mm_mul_ps(r, smoothing)));
    int ia = hkMath::max2(0, _mm_cvtsi128_si32(_mm_cvttps_epi32(tv)));
    int ib = ia + 1;
    if (ib >= points.getSize()) {
        ib = points.getSize() - 1;
        ia = points.getSize() - 2;
    }
    tangent = normalized3(_mm_sub_ps(points[ib], points[ia]));

    const Vec4 fromStart = _mm_sub_ps(tv, simdFromFloat(float(ia)));
    if (_mm_ucomilt_ss(fromStart, smoothing) && ia > 0) {
        ia--;
        ib--;
        const Vec4 previous = normalized3(_mm_sub_ps(points[ib], points[ia]));
        const Vec4 weight =
            _mm_mul_ps(invSmoothing, _mm_mul_ps(_mm_sub_ps(smoothing, fromStart), D_14b2060[18]));
        tangent = _mm_add_ps(tangent, _mm_mul_ps(weight, _mm_sub_ps(previous, tangent)));
        tangent = normalized3(tangent);
    }

    const Vec4 toEnd = _mm_sub_ps(simdFromFloat(float(ib)), tv);
    if (_mm_ucomilt_ss(toEnd, smoothing) && ib < points.getSize() - 1) {
        ia++;
        ib++;
        const Vec4 next = normalized3(_mm_sub_ps(points[ib], points[ia]));
        const Vec4 weight =
            _mm_mul_ps(invSmoothing, _mm_mul_ps(_mm_sub_ps(smoothing, toEnd), D_14b2060[18]));
        tangent = _mm_add_ps(tangent, _mm_mul_ps(weight, _mm_sub_ps(next, tangent)));
        tangent = normalized3(tangent);
    }
}
