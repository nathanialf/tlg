/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

#include <smmintrin.h>

/* derived name: the transform's columns read, then stored with w zero for
 * the rotation and one for the translation. */
void hkMatrix4::FUN_00010a70(const hkTransform &transform)
{
    const Vec4 c0 = transform.rotation.col0;
    const Vec4 c1 = transform.rotation.col1;
    const Vec4 c2 = transform.rotation.col2;
    const Vec4 c3 = transform.translation;
    const Vec4 zero = _mm_setzero_ps();
    col0 = _mm_blend_ps(c0, zero, 8);
    col1 = _mm_blend_ps(c1, zero, 8);
    col2 = _mm_blend_ps(c2, zero, 8);
    col3 = _mm_blend_ps(c3, D_14b2060[3], 8);
}
