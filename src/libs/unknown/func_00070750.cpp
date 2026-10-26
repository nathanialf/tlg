/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hknpVehicleLinearCastWheelCollide's type info (registered at
 * 0x708de): construct the object in place from a loaded image through its
 * inline finish constructor. */
// NONMATCHING: equal, but hknpVehicleWheelCollide's vtable 0x169af50 has no row (no type info;
// the name is its hkClass string, a D14 ruling)
void FUN_00070750(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpVehicleLinearCastWheelCollide(flag);
}
