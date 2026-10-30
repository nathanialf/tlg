/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hkTransform::FUN_00010d10(const hkTransform &a, const hkTransform &b)
{
    const Vec4 b0 = b.rotation.col0;
    const Vec4 b1 = b.rotation.col1;
    const Vec4 b2 = b.rotation.col2;
    const Vec4 a0 = a.rotation.col0;
    const Vec4 a1 = a.rotation.col1;
    const Vec4 a2 = a.rotation.col2;
    const Vec4 c0 =
        _mm_add_ps(_mm_mul_ps(broadcast<0>(b2), a2),
                   _mm_add_ps(_mm_mul_ps(broadcast<0>(b0), a0), _mm_mul_ps(broadcast<0>(b1), a1)));
    const Vec4 c1 =
        _mm_add_ps(_mm_mul_ps(broadcast<1>(b2), a2),
                   _mm_add_ps(_mm_mul_ps(broadcast<1>(b0), a0), _mm_mul_ps(broadcast<1>(b1), a1)));
    const Vec4 c2 =
        _mm_add_ps(_mm_mul_ps(broadcast<2>(b2), a2),
                   _mm_add_ps(_mm_mul_ps(broadcast<2>(b0), a0), _mm_mul_ps(broadcast<2>(b1), a1)));
    const Vec4 t = _mm_sub_ps(a.translation, combineColumns(c0, c1, c2, b.translation));
    rotation.col0 = c0;
    rotation.col1 = c1;
    rotation.col2 = c2;
    translation = t;
}
