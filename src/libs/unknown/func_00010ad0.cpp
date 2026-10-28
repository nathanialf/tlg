/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the inverse of a rigid transform: the rotation transposed
 * (as hkMatrix3's FUN_0001a980 transposes in place), the translation
 * negated and carried back through it. */
void hkTransform::FUN_00010ad0(const hkTransform &t)
{
    const Vec4 lo = _mm_unpacklo_ps(t.rotation.col0, t.rotation.col1);
    const Vec4 hi = _mm_unpackhi_ps(t.rotation.col0, t.rotation.col1);
    const Vec4 c = t.rotation.col2;
    const Vec4 col0 = _mm_movelh_ps(lo, c);
    rotation.col0 = col0;
    const Vec4 col1 = _mm_shuffle_ps(_mm_movehl_ps(lo, lo), c, _MM_SHUFFLE(3, 1, 1, 0));
    rotation.col1 = col1;
    const Vec4 col2 = _mm_shuffle_ps(hi, c, _MM_SHUFFLE(3, 2, 1, 0));
    rotation.col2 = col2;
    const Vec4 negated = _mm_xor_ps(t.translation, _mm_set1_ps(-0.0f));
    const Vec4 x = _mm_shuffle_ps(negated, negated, _MM_SHUFFLE(0, 0, 0, 0));
    const Vec4 y = _mm_shuffle_ps(negated, negated, _MM_SHUFFLE(1, 1, 1, 1));
    const Vec4 z = _mm_shuffle_ps(negated, negated, _MM_SHUFFLE(2, 2, 2, 2));
    translation =
        _mm_add_ps(_mm_mul_ps(col2, z), _mm_add_ps(_mm_mul_ps(col0, x), _mm_mul_ps(col1, y)));
}
