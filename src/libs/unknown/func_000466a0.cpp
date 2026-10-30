/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpConvexShape::FUN_000466a0(int faceIndex, Vec4 *planeOut,
                                   hknpFaceAngle *angleOut) const /* derived name */
{
    const Vec4 *faceVertices = vertices.begin(); /* derived name */
    const u32 indices = u32(faceIndex);          /* derived name */
    const Vec4 v0 = faceVertices[indices >> 24];
    const Vec4 v1 = faceVertices[(indices >> 16) & 0xff];
    const Vec4 v2 = faceVertices[(indices >> 8) & 0xff];
    const Vec4 v3 = faceVertices[indices & 0xff];
    const Vec4 normal = normalizedIfNotZero3(cross3(_mm_sub_ps(v2, v0), _mm_sub_ps(v3, v1)));
    const Vec4 distance = _mm_sub_ps(_mm_setzero_ps(), _mm_dp_ps(normal, v0, 0x7F));
    *planeOut = _mm_blend_ps(normal, distance, 8);
    angleOut->value = 0;
}
