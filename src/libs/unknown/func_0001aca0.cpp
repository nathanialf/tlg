/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the columns (0, z, -y), (-z, 0, x) and (y, -x, 0), each set
 * from four broadcast scalars. */
void hkMatrix3::FUN_0001aca0(const Vec4 &r) /* derived name */
{
    const Vec4 zero = _mm_setzero_ps();
    const Vec4 x = broadcast<0>(r);
    const Vec4 y = broadcast<1>(r);
    const Vec4 z = broadcast<2>(r);
    col0 = setFromScalars(zero, z, negateScalar(y), zero);
    col1 = setFromScalars(negateScalar(z), zero, x, zero);
    col2 = setFromScalars(y, negateScalar(x), zero, zero);
}
