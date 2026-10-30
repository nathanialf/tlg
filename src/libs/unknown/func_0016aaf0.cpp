/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

int hknpScaledConvexShapeBase::FUN_0016aaf0(int faceIndex, Vec4 *planeOut, Vec4 *verticesOut) const
{
    const int numVertices = coreShape->unknownVirtual15(faceIndex, planeOut, verticesOut);
    Vec4 plane = *planeOut;
    for (int i = 0; i < numVertices; i++) {
        const Vec4 v = verticesOut[i];
        verticesOut[i] = _mm_blend_ps(_mm_add_ps(_mm_mul_ps(v, scale), translation), v, 8);
    }
    if (reinterpret_cast<const u32 *>(&scale)[3] & 0xc0ffffff) {
        plane = _mm_blend_ps(plane, _mm_mul_ps(plane, broadcast<0>(scale)), 8);
    } else {
        const Vec4 distance = broadcast<3>(plane);
        const Vec4 r = _mm_rcp_ps(scale);
        const Vec4 invScale = _mm_mul_ps(r, _mm_sub_ps(D_14b4380, _mm_mul_ps(scale, r)));
        const Vec4 normal = _mm_mul_ps(plane, invScale);
        const Vec4 lengthSquared = _mm_dp_ps(normal, normal, 0x7F);
        const Vec4 e = _mm_rsqrt_ps(lengthSquared);
        const Vec4 invLength =
            _mm_mul_ps(_mm_mul_ps(e, D_14b4360),
                       _mm_sub_ps(D_14b4390, _mm_mul_ps(lengthSquared, _mm_mul_ps(e, e))));
        plane = _mm_mul_ps(_mm_blend_ps(normal, distance, 8), invLength);
    }
    const Vec4 distance = _mm_sub_ps(broadcast<3>(plane), _mm_dp_ps(plane, translation, 0x7F));
    *planeOut = _mm_blend_ps(plane, distance, 8);
    return numVertices;
}
