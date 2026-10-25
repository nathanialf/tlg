/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: FUN_00017b20 inverts the 4x4 matrix m into out, failing
 * (HK_FAILURE, out untouched) when the determinant's magnitude is below the
 * tolerance (lane 0 of a 16-byte vector); hkgpConvexHull's callers at
 * 0xb5a54 and 0xb63ad test the result. */
hkResult FUN_00017b20(const Mat4 &m, Mat4 &out, const Vec4 &tolerance); /* derived name */

/* derived name: sets self to the inverse of m, the operands handed to the
 * inversion in its order. */
hkResult FUN_00013790(Mat4 *self, const Mat4 &m, const Vec4 &tolerance) /* derived name */
{
    return FUN_00017b20(m, *self, tolerance);
}
