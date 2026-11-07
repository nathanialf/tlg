/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The planes, the polygons and the vertices released and cleared; the
 * vtable is emitted here, with the deleting destructor (0x9b170) before
 * this one. */
hkcdPlanarGeometry::~hkcdPlanarGeometry()
{
    planes = HK_NULL;
    polys = HK_NULL;
    if (vertices) {
        vertices->removeReference();
    }
    vertices = HK_NULL;
}
