/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 10 of hknpVehicleDefaultTransmission's vtable (address
 * point 0x1699ba0): the ratio of the gear the output is in, through the
 * primary transmission, negative in reverse. */
float hknpVehicleDefaultTransmission::FUN_00067ef0(
    const hknpVehicleInstance *vehicle, const hknpVehicleTransmissionOutput &output) const
{
    float ratio;
    if (output.isReversing) {
        ratio = -reverseGearRatio;
    } else {
        ratio = gearsRatio.data[output.currentGear];
    }
    return ratio * primaryTransmissionRatio;
}
