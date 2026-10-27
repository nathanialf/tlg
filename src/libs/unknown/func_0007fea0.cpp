/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hkpLinearParametricCurve::FUN_0007fea0(const hkTransform &transform) /* derived name */
{
    const int numPoints = points.getSize();
    for (int i = 0; i < numPoints; i++) {
        points[i] = transformPosition(transform, points[i]);
    }
}
