/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_hk_reflect.h"

/* a's columns combined by the lanes of one of b's (derived name). */
static inline Vec4 combineColumns(const Vec4 &c0, const Vec4 &c1, const Vec4 &c2,
                                  const Vec4 &v) /* derived name */
{
    const Vec4 x = _mm_shuffle_ps(v, v, _MM_SHUFFLE(0, 0, 0, 0));
    const Vec4 y = _mm_shuffle_ps(v, v, _MM_SHUFFLE(1, 1, 1, 1));
    const Vec4 z = _mm_shuffle_ps(v, v, _MM_SHUFFLE(2, 2, 2, 2));
    return _mm_add_ps(_mm_mul_ps(c2, z), _mm_add_ps(_mm_mul_ps(c0, x), _mm_mul_ps(c1, y)));
}

/* derived name: a's columns read once, then b's columns transformed from
 * the last, each stored before the next is read. */
void hkMatrix3::FUN_0001a9f0(const hkMatrix3 &a, const hkMatrix3 &b)
{
    const Vec4 c0 = a.col0;
    const Vec4 c1 = a.col1;
    const Vec4 c2 = a.col2;
    col2 = combineColumns(c0, c1, c2, b.col2);
    col1 = combineColumns(c0, c1, c2, b.col1);
    col0 = combineColumns(c0, c1, c2, b.col0);
}
