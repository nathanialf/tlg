/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Another geometry's vertices and triangles appended (Havok's
 * hkGeometry::appendGeometry): both arrays reserved first, a failure given
 * back; the new vertices moved by the transform when there is one (their w
 * kept), the new triangles' indices offset by the vertices there were.
 * derived name. */
hkResult hkGeometry::FUN_00093c90(const hkGeometry &geometry, const hkMatrix4 *transform)
{
    const int baseVertex = vertices.getSize();
    const int baseTriangle = triangles.getSize();
    if (vertices.reserve(hkContainerHeapAllocator::get(),
                         baseVertex + geometry.vertices.getSize()) != HK_SUCCESS) {
        return HK_FAILURE;
    }
    if (triangles.reserve(hkContainerHeapAllocator::get(),
                          baseTriangle + geometry.triangles.getSize()) != HK_SUCCESS) {
        return HK_FAILURE;
    }
    vertices.append(geometry.vertices.data, geometry.vertices.getSize());
    triangles.append(geometry.triangles.data, geometry.triangles.getSize());
    if (transform) {
        for (int i = baseVertex; i < vertices.getSize(); i++) {
            const Vec4 v = vertices[i];
            const Vec4 x = _mm_shuffle_ps(v, v, _MM_SHUFFLE(0, 0, 0, 0));
            const Vec4 y = _mm_shuffle_ps(v, v, _MM_SHUFFLE(1, 1, 1, 1));
            const Vec4 z = _mm_shuffle_ps(v, v, _MM_SHUFFLE(2, 2, 2, 2));
            Vec4 p = _mm_add_ps(_mm_mul_ps(x, transform->col0), transform->col3);
            p = _mm_add_ps(p, _mm_mul_ps(y, transform->col1));
            p = _mm_add_ps(p, _mm_mul_ps(z, transform->col2));
            vertices[i] = _mm_blend_ps(p, v, 8);
        }
    }
    if (baseVertex > 0) {
        for (int i = baseTriangle; i < triangles.getSize(); i++) {
            triangles[i].a += baseVertex;
            triangles[i].b += baseVertex;
            triangles[i].c += baseVertex;
        }
    }
    return HK_SUCCESS;
}
