/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: v rotated by m: each of v's x, y and z broadcast and
 * multiplied into its column, the three products summed. */
void FUN_00010ef0(Vec4 &out, const hkMatrix3 &m, const Vec4 &v)
{
    const Vec4 x = _mm_shuffle_ps(v, v, _MM_SHUFFLE(0, 0, 0, 0));
    const Vec4 y = _mm_shuffle_ps(v, v, _MM_SHUFFLE(1, 1, 1, 1));
    const Vec4 z = _mm_shuffle_ps(v, v, _MM_SHUFFLE(2, 2, 2, 2));
    out =
        _mm_add_ps(_mm_mul_ps(z, m.col2), _mm_add_ps(_mm_mul_ps(x, m.col0), _mm_mul_ps(y, m.col1)));
}
