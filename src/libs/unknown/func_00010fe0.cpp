/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The point copied, rotated in place and moved, as the scaled transform's
 * form without the scale: v is read before the quaternion (cookbook 133). */
void FUN_00010fe0(Vec4 &out, const hkQTransform &t, const Vec4 &v)
{
    Vec4 point = v;
    point = rotatedDir(t.rotation, point);
    out = _mm_add_ps(point, t.translation);
}
