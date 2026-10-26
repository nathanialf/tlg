/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hknpVehicleInstance's type info
 * (registered at 0x47b06): construct the vehicle in place from a loaded
 * image. */
void FUN_00047990(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpVehicleInstance(flag);
}
