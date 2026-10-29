/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void FUN_0001a360(Vec4 &perpendicularOut, const Vec4 &v) /* derived name */
{
    const Vec4 xyz = setXYZ_0(v);
    const Vec4 yx00 = _mm_shuffle_ps(xyz, xyz, _MM_SHUFFLE(3, 3, 0, 1));
    const Vec4 z0x0 = _mm_shuffle_ps(xyz, xyz, _MM_SHUFFLE(3, 0, 3, 2));
    const Vec4 flipX = _mm_castsi128_ps(_mm_setr_epi32(int(0x80000000), 0, 0, 0));
    const Vec4 a = _mm_xor_ps(yx00, flipX);
    const Vec4 b = _mm_xor_ps(z0x0, flipX);
    const Vec4 lengthA = _mm_dp_ps(v, v, 0x3f);
    const Vec4 lengthB = _mm_dp_ps(z0x0, z0x0, 0xff);
    const Vec4 perpendicular = _mm_blendv_ps(a, b, _mm_cmplt_ps(lengthA, lengthB));
    perpendicularOut = _mm_blend_ps(normalized3(perpendicular), _mm_setzero_ps(), 8);
}
