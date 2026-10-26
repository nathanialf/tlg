/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_hk_reflect.h"

/* derived name: v rotated by the inverse of the rotation m: each column's
 * three-lane dot product with v into its own lane. */
void FUN_00010f20(Vec4 &out, const hkMatrix3 &m, const Vec4 &v)
{
    out = _mm_or_ps(_mm_or_ps(_mm_dp_ps(v, m.col0, 0x71), _mm_dp_ps(v, m.col1, 0x72)),
                    _mm_dp_ps(v, m.col2, 0x74));
}
