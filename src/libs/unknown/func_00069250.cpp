/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hknpVehicleData's type info
 * (0x57c22f8): construct the data in place from a loaded image, its
 * friction description with it. */
void FUN_00069250(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpVehicleData(flag);
}
