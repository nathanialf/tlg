/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hkpLinearParametricCurve::addPoint(const Vec4 &point)
{
    points.pushBack(point);
    if (points.getSize() != 1) {
        const Vec4 step = _mm_sub_ps(point, points[points.getSize() - 2]);
        const float d = lane(length3(step), 0) + distance[distance.getSize() - 1];
        distance.pushBack(d);
    } else {
        distance.pushBack(0.0f);
    }
}
