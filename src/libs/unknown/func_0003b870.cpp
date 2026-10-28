/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 0 of its vtable (0x16959e0): the geometry's reference released. */
hknpDefaultExternMeshShapeGeometry::~hknpDefaultExternMeshShapeGeometry()
{
    if (geometry) {
        geometry->removeReference();
    }
    geometry = 0;
}
