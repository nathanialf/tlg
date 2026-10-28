/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 10 of the scaled convex shapes: every vertex of the
 * core shape as translation + v * scale in x, y and z, its own w kept. The
 * buffer's size is not checked; the buffer is not the shape's memory
 * (HK_RESTRICT, D9: the scale and the translation are read once, before
 * the loop's stores, 0x16ae35). */
const Vec4 *hknpScaledConvexShapeBase::FUN_0016ae20(Vec4 *HK_RESTRICT buffer, int bufferSize) const
{
    const hknpConvexShape *convex = static_cast<const hknpConvexShape *>(coreShape);
    const int numVertices = convex->vertices.getSize();
    const Vec4 *vertices = convex->vertices.begin();
    for (int i = 0; i < numVertices; i++) {
        const Vec4 v = vertices[i];
        buffer[i] = _mm_blend_ps(_mm_add_ps(translation, _mm_mul_ps(v, scale)), v, 8);
    }
    return buffer;
}
