/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_hk_reflect.h"

float hkpLinearParametricCurve::FUN_0007fae0(float t) const /* derived name */
{
    int index = hkMath::max2(0, int(t));
    const int lastIndex = points.getSize() - 1;
    float start;
    float delta;
    if (index >= lastIndex) {
        index = lastIndex;
        start = distance[index];
        delta = start - distance[index - 1];
    } else {
        start = distance[index];
        delta = distance[index + 1] - start;
    }
    return start + delta * (t - float(index));
}
