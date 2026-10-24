/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_types.h"
#include "tlg_simd.h"

/* derived name: a -= b over the four rows of a 4x4 matrix. Unknown owner. */
void FUN_000137c0(Mat4 *a, const Mat4 *b) /* derived name */
{
    for (int i = 0; i < 4; i++) {
        a->r[i] = _mm_sub_ps(a->r[i], b->r[i]);
    }
}
