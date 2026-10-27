/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 6 of hknpVehicleDefaultAnalogDriverInput's vtable
 * (address point 0x16a43d0), the accelerator input: the stick pulled back,
 * read the other way while the vehicle reverses with automatic reverse on;
 * full while it reverses without it. */
// NONMATCHING: 69 bytes against 72. The base tests isReversing once into al
// and tests al again in the block reached on (reversing, no automatic
// reverse), where it returns 1.0; the other two paths reach the compare
// directly. This form (docs/NOTES.md Round 36) leaves that block testing
// autoReverse again, reloaded, instead.
float hknpVehicleDefaultAnalogDriverInput::FUN_00151d90(
    const hknpVehicleInstance *vehicle, const hknpVehicleDriverInputAnalogStatus *status) const
{
    float input;
    if (vehicle->isReversing && autoReverse) {
        input = -status->positionY;
    } else {
        input = status->positionY;
    }
    if (vehicle->isReversing && !autoReverse) {
        return 1.0f;
    }
    if (input <= 0.0f) {
        return -input;
    }
    return 0.0f;
}
