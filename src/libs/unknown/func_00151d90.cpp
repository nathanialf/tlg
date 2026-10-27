/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 6 of hknpVehicleDefaultAnalogDriverInput's vtable
 * (address point 0x16a43d0), the accelerator input: the stick pulled back,
 * read the other way while the vehicle reverses with automatic reverse on;
 * full while it reverses without it. */
// NONMATCHING: 70 bytes against 72. The base loads isReversing into al,
// branches on it, tests autoReverse on the reversing path and tests al again
// on (reversing, no automatic reverse) before returning 1.0. This form
// gives that retest of a hoisted load, but with autoReverse tested first at
// the entry (docs/NOTES.md Round 36).
float hknpVehicleDefaultAnalogDriverInput::FUN_00151d90(
    const hknpVehicleInstance *vehicle, const hknpVehicleDriverInputAnalogStatus *status) const
{
    float input;
    if (autoReverse && vehicle->isReversing) {
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
