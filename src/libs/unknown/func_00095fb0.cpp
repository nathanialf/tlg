/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* hkcdPlanarGeometryPolygonCollection's finish constructor: nothing loaded
 * needs fixing up, so only the vtable is set. */
hkcdPlanarGeometryPolygonCollection::hkcdPlanarGeometryPolygonCollection(
    hkFinishLoadedObjectFlag flag)
    : hkcdPlanarGeometryPrimitivesCollection28(flag)
{
}

/* Its destructor adds nothing to the collection's. */
hkcdPlanarGeometryPolygonCollection::~hkcdPlanarGeometryPolygonCollection() {}
