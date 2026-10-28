/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the first indexed vertex, then the second and third with
 * their indices masked by the table at the position after and at it. */
void hknpConvexShape::FUN_0003c4e0(const u8 *indices, int position, Vec4 *verticesOut) const
{
    const Vec4 *v = vertices.begin();
    const Vec4 v0 = v[indices[0]];
    const Vec4 v1 = v[indices[1] & D_16dc600[position + 1]];
    const Vec4 v2 = v[indices[2] & D_16dc600[position]];
    verticesOut[0] = v0;
    verticesOut[1] = v1;
    verticesOut[2] = v2;
}
