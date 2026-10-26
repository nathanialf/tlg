/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 8 of hknpVehicleInstance's vtable (address point
 * 0x16a50a0) passes the pointer at +0x10 of its argument on to the same slot
 * of its wheel collide. */
void hknpVehicleInstance::FUN_00165990(
    const hknpVehicleInstanceSlot8Argument *argument) /* derived name */
{
    wheelCollide->unknownVirtual8(argument->unknown10);
}
