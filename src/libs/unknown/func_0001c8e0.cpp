/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the finish callback of hkcdPlanarGeometryPrimitivesCollection28's
 * type info (0x57b9e40): construct the collection in place from a loaded
 * image through its inline finish constructor, which has nothing to fix up
 * but the vtable. The collection's destructors (0x1c8e0, 0x1c930), inline
 * in its class, are emitted here with its vtable. */
void FUN_0001c990(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkcdPlanarGeometryPrimitivesCollection28(flag);
}
