/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: v as a point under t: rotated as FUN_00010ef0 rotates it,
 * then moved by the translation. */
void FUN_00010f50(Vec4 &out, const hkTransform &t, const Vec4 &v)
{
    const Vec4 x = _mm_shuffle_ps(v, v, _MM_SHUFFLE(0, 0, 0, 0));
    const Vec4 y = _mm_shuffle_ps(v, v, _MM_SHUFFLE(1, 1, 1, 1));
    const Vec4 z = _mm_shuffle_ps(v, v, _MM_SHUFFLE(2, 2, 2, 2));
    const Vec4 rotated =
        _mm_add_ps(_mm_mul_ps(z, t.rotation.col2),
                   _mm_add_ps(_mm_mul_ps(x, t.rotation.col0), _mm_mul_ps(y, t.rotation.col1)));
    out = _mm_add_ps(rotated, t.translation);
}
