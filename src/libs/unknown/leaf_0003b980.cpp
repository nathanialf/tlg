/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 5 of hknpDefaultExternMeshShapeGeometry's vtable
 * returns the number of triangles of its geometry. */
int hknpDefaultExternMeshShapeGeometry::FUN_0003b980() const /* derived name */
{
    return geometry->triangles.size;
}
