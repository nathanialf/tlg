/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_hk_reflect.h"

void hkQuaternion::FUN_00019cf0(const Vec4 &axis, const Vec4 &angle)
{
    Vec4 s;
    Vec4 c;
    quadSinCos(_mm_mul_ps(D_14b2060[18], angle), s, c);
    vec = _mm_blend_ps(_mm_mul_ps(s, axis), c, 8);
}
