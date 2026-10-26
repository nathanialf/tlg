/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_hk_reflect.h"

/* derived name: v by the inverse of the transform t: the translation
 * subtracted, then each rotation column's three-lane dot product with the
 * difference into its own lane, as FUN_00010f20 rotates. */
void FUN_00010f90(Vec4 &out, const hkTransform &t, const Vec4 &v)
{
    const Vec4 d = _mm_sub_ps(v, t.translation);
    out = _mm_or_ps(
        _mm_or_ps(_mm_dp_ps(d, t.rotation.col0, 0x71), _mm_dp_ps(d, t.rotation.col1, 0x72)),
        _mm_dp_ps(d, t.rotation.col2, 0x74));
}
