/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hknpVehicleLinearCastWheelCollide's type info (registered at
 * 0x708de): construct the object in place from a loaded image through its
 * inline finish constructor. */
void FUN_00070750(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpVehicleLinearCastWheelCollide(flag);
}
