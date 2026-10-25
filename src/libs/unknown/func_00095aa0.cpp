/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: hkcdPlanarGeometryPrimitives::Plane's finish constructor
 * (run by its finish callback FUN_0001d900): when finishing a loaded image,
 * it rebuilds what the plane derives from its stored coefficients. */
void FUN_00095aa0(hkcdPlanarGeometryPrimitivesPlane *self,
                  hkFinishLoadedObjectFlag flag) /* derived name */
{
    if (flag.finishing) {
        FUN_00095ab0(self);
    }
}
