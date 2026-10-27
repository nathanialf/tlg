/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 6 of hknpVehicleDefaultTransmission's vtable (address
 * point 0x1699ba0): the engine's torque through the current ratio, none
 * while the gear changes. */
float hknpVehicleDefaultTransmission::FUN_00067ff0(
    const hknpVehicleInstance *vehicle, const hknpVehicleTransmissionOutput &output) const
{
    if (output.isInGearChange) {
        return 0.0f;
    }
    return vehicle->torque * FUN_00067ef0(vehicle, output);
}
