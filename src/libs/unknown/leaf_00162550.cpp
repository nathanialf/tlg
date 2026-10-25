/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 6 of hknpVehicleInstance's vtable (address point
 * 0x16a50a0), hknpUnaryAction's: when the removed body is the action's own,
 * its id becomes the invalid one. */
void hknpVehicleInstance::FUN_00162550(hknpBodyId removedId) /* derived name */
{
    if (bodyId.value == removedId.value) {
        bodyId.value = 0x7fffffff;
    }
}
