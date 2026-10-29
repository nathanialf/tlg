/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_hk_reflect.h"

/* out = a transposed times b: each of b's columns dotted with a's three
 * columns, read once. derived name. */
static inline void setTransposeMul(hkMatrix3 &out, const hkMatrix3 &a,
                                   const hkMatrix3 &b) /* derived name */
{
    const Vec4 a0 = a.col0;
    const Vec4 a1 = a.col1;
    const Vec4 a2 = a.col2;
    out.col0 = _mm_or_ps(_mm_or_ps(_mm_dp_ps(a0, b.col0, 0x71), _mm_dp_ps(a1, b.col0, 0x72)),
                         _mm_dp_ps(a2, b.col0, 0x74));
    out.col1 = _mm_or_ps(_mm_or_ps(_mm_dp_ps(a0, b.col1, 0x71), _mm_dp_ps(a1, b.col1, 0x72)),
                         _mm_dp_ps(a2, b.col1, 0x74));
    out.col2 = _mm_or_ps(_mm_or_ps(_mm_dp_ps(a0, b.col2, 0x71), _mm_dp_ps(a1, b.col2, 0x72)),
                         _mm_dp_ps(a2, b.col2, 0x74));
}

void hkTransform::FUN_00010c30(const hkTransform &a, const hkTransform &b)
{
    setTransposeMul(rotation, a.rotation, b.rotation);
    const Vec4 d = _mm_sub_ps(b.translation, a.translation);
    translation = _mm_or_ps(
        _mm_or_ps(_mm_dp_ps(d, a.rotation.col0, 0x71), _mm_dp_ps(d, a.rotation.col1, 0x72)),
        _mm_dp_ps(d, a.rotation.col2, 0x74));
}
