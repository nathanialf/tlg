/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 6 of hknpDefaultExternMeshShapeGeometry's vtable
 * (address point 0x16959f0): a triangle's three vertices copied out, the
 * geometry's vertex and triangle storage read once. */
void hknpDefaultExternMeshShapeGeometry::FUN_0003b990(int triangleIndex, Vec4 *verticesOut) const
{
    const Vec4 *vertices = geometry->vertices.data;
    const hkGeometry::Triangle &triangle = geometry->triangles.data[triangleIndex];
    verticesOut[0] = vertices[triangle.a];
    verticesOut[1] = vertices[triangle.b];
    verticesOut[2] = vertices[triangle.c];
}
