/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

int hknpExternMeshShape::FUN_001666e0(const hknpShapeSlot29Input &input,
                                      hkGeometry *geometryOut) const
{
    const int numTriangles = geometry->unknownVirtual5();
    int vertexIndex = geometryOut->vertices.getSize();
    Vec4 *vertices = geometryOut->vertices.expandBy(numTriangles * 3);
    hkGeometry::Triangle *triangles = geometryOut->triangles.expandBy(numTriangles);
    for (int i = 0; i < numTriangles; i++) {
        geometry->unknownVirtual6(i, vertices);
        for (int j = 0; j < 3; j++) {
            vertices[j] = _mm_mul_ps(vertices[j], input.scale);
            vertices[j] = _mm_add_ps(vertices[j], input.offset);
        }
        vertices += 3;
        const int material = geometry->unknownVirtual7(i);
        triangles->a = vertexIndex;
        triangles->b = vertexIndex + 1;
        triangles->c = vertexIndex + 2;
        triangles->material = material;
        triangles++;
        vertexIndex += 3;
    }
    return 0;
}
