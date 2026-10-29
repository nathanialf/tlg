/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the first indexed vertex, then the second and third with
 * their indices masked by the table at the position after and at it. */
void hknpConvexShape::FUN_0003c4e0(const u8 *indices, int position, Vec4 *verticesOut) const
{
    verticesByIndex(vertices.begin(), indices, position, verticesOut);
}
