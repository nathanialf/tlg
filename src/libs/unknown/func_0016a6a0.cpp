/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_hk_reflect.h"

hknpScaledConvexShapeBase::hknpScaledConvexShapeBase(const hknpConvexShape *childShape,
                                                     const Vec4 &scale_, int scaleMode)
    : hknpDecoratorShape(childShape)
{
    coreShape = childShape;
    coreShapeSize = 0;
    flags |= childShape->flags & (USE_SINGLE_POINT_MANIFOLD | USE_SMALL_FACE_INDICES);
    scale = scale_;
    convexRadius = childShape->convexRadius;
    FUN_00169c90(childShape->unknownVirtual5(), childShape->vertices.beginBytes(),
                 childShape->vertices.getSize(), scaleMode, scale, convexRadius, translation);

    const __m128i all = _mm_set1_epi32(-1);
    const __m128 xyz = _mm_blend_ps(_mm_setzero_ps(), _mm_castsi128_ps(all), 7);
    const Vec4 s = scale;
    const Vec4 equal = _mm_cmpeq_ps(s, _mm_shuffle_ps(s, s, _MM_SHUFFLE(0, 0, 0, 0)));
    const int uniform =
        _mm_testc_si128(_mm_castps_si128(_mm_and_ps(equal, xyz)), _mm_castps_si128(xyz));
    reinterpret_cast<int *>(&scale)[3] = uniform | 0x3f000000;

    if (unknownVirtual8()) {
        unknownVirtual8()->shapeMutated.fire(3);
    }
}
