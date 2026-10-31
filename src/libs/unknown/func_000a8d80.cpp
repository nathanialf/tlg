/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_lib_unknown.h"

Vec4 SupportQuery000a8ef0::FUN_000a8d80(const Vec4 &direction, const Vec4 &point,
                                        SupportPoint000a8ef0 &pointOut) const
{
    const Vec4 opposite = _mm_xor_ps(direction, _mm_set1_ps(-0.0f));
    SupportPoint000a8ef0 alongDirection;
    support->getSupportPoint(shapeA, direction, shapeB, this, alongDirection);
    support->getSupportPoint(shapeA, opposite, shapeB, this, pointOut);
    const Vec4 distance = _mm_dp_ps(_mm_sub_ps(alongDirection.difference, point), direction, 0x7f);
    const Vec4 oppositeDistance = _mm_dp_ps(_mm_sub_ps(pointOut.difference, point), opposite, 0x7f);
    if (_mm_ucomilt_ss(oppositeDistance, distance)) {
        pointOut = alongDirection;
    }
    return _mm_max_ps(distance, oppositeDistance);
}
