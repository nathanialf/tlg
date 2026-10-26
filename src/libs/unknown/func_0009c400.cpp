/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkcdPlanarGeometryPlanesCollection's finish constructor: the unserialized
 * pointers start null, and a finished collection makes its critical
 * section. */
hkcdPlanarGeometryPlanesCollection::hkcdPlanarGeometryPlanesCollection(
    hkFinishLoadedObjectFlag flag)
    : hkReferencedObject(flag), planes(flag), cache(0), criticalAccess(0)
{
    if (flag.finishing) {
        FUN_0009c430();
    }
}
