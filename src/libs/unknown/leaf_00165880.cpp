/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 13 of hknpVehicleInstance's vtable (address point
 * 0x16a50a0) returns the engine's rpm (hkReal at +0xfc, from the record
 * table at 0x1698a70). */
float hknpVehicleInstance::FUN_00165880() const
{
    return rpm;
}
