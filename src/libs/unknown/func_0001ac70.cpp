/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: every column multiplied by the vector; the vector is read
 * again for each, as it may be one of the columns. */
void hkMatrix3::FUN_0001ac70(const Vec4 &scale)
{
    col0 = _mm_mul_ps(scale, col0);
    col1 = _mm_mul_ps(scale, col1);
    col2 = _mm_mul_ps(scale, col2);
}
