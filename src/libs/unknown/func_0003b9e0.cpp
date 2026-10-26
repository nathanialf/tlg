/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 7 of hknpDefaultExternMeshShapeGeometry's vtable
 * (address point 0x16959f0) returns a triangle's material as a 16-bit value
 * (the load narrowed to the half the return keeps). */
u16 hknpDefaultExternMeshShapeGeometry::FUN_0003b9e0(int triangleIndex) const
{
    return geometry->triangles.data[triangleIndex].material;
}
