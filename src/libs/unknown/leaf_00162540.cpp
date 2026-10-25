/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 5 of hknpVehicleInstance's vtable (address point
 * 0x16a50a0), hknpUnaryAction's: the bodies the action works on are its one
 * bodyId. */
void hknpVehicleInstance::FUN_00162540(hknpBodyId *&bodiesOut, int &numBodiesOut) /* derived name */
{
    bodiesOut = &bodyId;
    numBodiesOut = 1;
}
