/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slots 0 and 1 of its vtable (0x16a3770): the critical section and the
 * cache deleted, then the planes by the array's destructor. The class's
 * key function: the deleting destructor (0x9c910) comes first, then the
 * complete one (0x9c960). */
hkcdPlanarGeometryPlanesCollection::~hkcdPlanarGeometryPlanesCollection()
{
    delete criticalAccess;
    if (cache) {
        delete cache;
        cache = HK_NULL;
    }
}
