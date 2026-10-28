/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: v rotated by the quaternion q (the header's rotatedDir). */
void FUN_00011060(Vec4 &out, const hkQuaternion &q, const Vec4 &v)
{
    out = rotatedDir(q, v);
}
