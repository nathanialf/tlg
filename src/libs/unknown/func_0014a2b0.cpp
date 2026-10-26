/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the margins of inner inside outer at both corners, then the
 * smallest of their x, y and z, broadcast. */
Vec4 FUN_0014a2b0(const hkAabb &inner, const hkAabb &outer)
{
    const Vec4 maxMargin = _mm_sub_ps(outer.max, inner.max);
    const Vec4 minMargin = _mm_sub_ps(inner.min, outer.min);
    const Vec4 margin = _mm_min_ps(minMargin, maxMargin);
    const Vec4 x = _mm_shuffle_ps(margin, margin, _MM_SHUFFLE(0, 0, 0, 0));
    const Vec4 y = _mm_shuffle_ps(margin, margin, _MM_SHUFFLE(1, 1, 1, 1));
    const Vec4 z = _mm_shuffle_ps(margin, margin, _MM_SHUFFLE(2, 2, 2, 2));
    return _mm_min_ps(z, _mm_min_ps(y, x));
}
