/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the finish callback of hkcdPlanarGeometryPrimitives::Plane's type info (0x57ba4e0):
 * construct the object in place from a loaded image through its out-of-line
 * finish constructor. */
void FUN_0001d900(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    FUN_00095aa0(static_cast<hkcdPlanarGeometryPrimitivesPlane *>(object), flag);
}
