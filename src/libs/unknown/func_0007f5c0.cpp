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
