/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 7 of hknpVehicleDefaultAnalogDriverInput's vtable
 * (address point 0x16a43d0), the brake input: the stick's forward position,
 * pulled back instead while the vehicle reverses with automatic reverse on,
 * never below zero. */
float hknpVehicleDefaultAnalogDriverInput::FUN_00151de0(
    float deltaTime, const hknpVehicleInstance *vehicle,
    const hknpVehicleDriverInputAnalogStatus *status, hknpVehicleFilteredDriverInput &output) const
{
    float brakeInput;
    if (vehicle->isReversing && autoReverse) {
        brakeInput = -status->positionY;
    } else {
        brakeInput = status->positionY;
    }
    return hkMath::max2(0.0f, brakeInput);
}
