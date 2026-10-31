/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_hk_reflect.h"

void hknpScaledConvexShapeBase::FUN_0016a9c0(const Vec4 &direction, Vec4 *vertexOut) const
{
    const Vec4 s = scale;
    const Vec4 dir = _mm_mul_ps(s, direction);
    const hknpConvexShape *convex = static_cast<const hknpConvexShape *>(coreShape);
    const Vec4 *v = reinterpret_cast<const Vec4 *>(
        reinterpret_cast<const char *>(&convex->vertices) + convex->vertices.offset);
    Vec4 best3 = v[3];
    Vec4 best2 = v[2];
    Vec4 best1 = v[1];
    Vec4 best0 = v[0];
    Vec4 dot0 = _mm_dp_ps(dir, best0, 0x7f);
    Vec4 dot1 = _mm_dp_ps(dir, best1, 0x7f);
    Vec4 dot2 = _mm_dp_ps(dir, best2, 0x7f);
    Vec4 dot3 = _mm_dp_ps(dir, best3, 0x7f);
    v += 4;
    for (int i = convex->vertices.size - 4; i > 0; i -= 4) {
        const Vec4 d0 = _mm_dp_ps(dir, v[0], 0x7f);
        const Vec4 d1 = _mm_dp_ps(dir, v[1], 0x7f);
        const Vec4 d2 = _mm_dp_ps(dir, v[2], 0x7f);
        const Vec4 d3 = _mm_dp_ps(dir, v[3], 0x7f);
        const Vec4 better0 = _mm_cmplt_ps(dot0, d0);
        const Vec4 better1 = _mm_cmplt_ps(dot1, d1);
        const Vec4 better2 = _mm_cmplt_ps(dot2, d2);
        const Vec4 better3 = _mm_cmplt_ps(dot3, d3);
        dot0 = _mm_blendv_ps(dot0, d0, better0);
        dot1 = _mm_blendv_ps(dot1, d1, better1);
        dot2 = _mm_blendv_ps(dot2, d2, better2);
        dot3 = _mm_blendv_ps(dot3, d3, better3);
        best0 = _mm_blendv_ps(best0, v[0], better0);
        best1 = _mm_blendv_ps(best1, v[1], better1);
        best2 = _mm_blendv_ps(best2, v[2], better2);
        best3 = _mm_blendv_ps(best3, v[3], better3);
        v += 4;
    }
    const Vec4 better01 = _mm_cmplt_ps(dot0, dot1);
    const Vec4 dot01 = _mm_blendv_ps(dot0, dot1, better01);
    const Vec4 better23 = _mm_cmplt_ps(dot2, dot3);
    const Vec4 dot23 = _mm_blendv_ps(dot2, dot3, better23);
    const Vec4 best01 = _mm_blendv_ps(best0, best1, better01);
    const Vec4 best23 = _mm_blendv_ps(best2, best3, better23);
    const Vec4 best = _mm_blendv_ps(best23, best01, _mm_cmplt_ps(dot23, dot01));
    *vertexOut = _mm_blend_ps(_mm_add_ps(_mm_mul_ps(best, scale), translation), best, 8);
}
