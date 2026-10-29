/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 6 of hknpVehicleDefaultAnalogDriverInput's vtable
 * (address point 0x16a43d0), the accelerator input: the stick pulled back,
 * read the other way while the vehicle reverses with automatic reverse on;
 * full while it reverses without it. */
float hknpVehicleDefaultAnalogDriverInput::FUN_00151d90(
    float deltaTime, const hknpVehicleInstance *vehicle,
    const hknpVehicleDriverInputAnalogStatus *status, hknpVehicleFilteredDriverInput &output) const
{
    const bool reversing = vehicle->isReversing;
    float input;
    if (reversing && autoReverse) {
        input = -status->positionY;
    } else {
        input = status->positionY;
    }
    if (!autoReverse && reversing) {
        return 1.0f;
    }
    if (input <= 0.0f) {
        return -input;
    }
    return 0.0f;
}
