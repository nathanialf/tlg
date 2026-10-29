/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpScaledConvexShapeBase::FUN_0016ae80(const u8 *indices, int numIndices,
                                             Vec4 *verticesOut) const
{
    const hknpConvexShape *convex = static_cast<const hknpConvexShape *>(coreShape);
    verticesByIndex(convex->vertices.begin(), indices, numIndices, verticesOut);
    for (int i = 0; i < numIndices; i++) {
        const Vec4 v = verticesOut[i];
        verticesOut[i] = _mm_blend_ps(_mm_add_ps(_mm_mul_ps(v, scale), translation), v, 8);
    }
}
