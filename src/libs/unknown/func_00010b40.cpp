/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hkTransform::FUN_00010b40(const hkTransform &a, const hkTransform &b)
{
    const Vec4 c0 = a.rotation.col0;
    const Vec4 c1 = a.rotation.col1;
    const Vec4 c2 = a.rotation.col2;
    translation = combineColumns(c0, c1, c2, b.translation);
    rotation.col2 = combineColumns(c0, c1, c2, b.rotation.col2);
    rotation.col1 = combineColumns(c0, c1, c2, b.rotation.col1);
    rotation.col0 = combineColumns(c0, c1, c2, b.rotation.col0);
    translation = _mm_add_ps(translation, a.translation);
}
