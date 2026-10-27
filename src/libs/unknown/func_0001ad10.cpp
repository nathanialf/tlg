/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <xmmintrin.h>

#include "tlg_hk_reflect.h"

void hkMatrix3::FUN_0001ad10(const Vec4 &scale, const hkMatrix3 &m)
{
    col0 = _mm_add_ps(_mm_mul_ps(scale, m.col0), col0);
    col1 = _mm_add_ps(_mm_mul_ps(scale, m.col1), col1);
    col2 = _mm_add_ps(_mm_mul_ps(scale, m.col2), col2);
}
