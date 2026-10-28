/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpVehicleDefaultTransmission::FUN_000680b0(
    float deltaTime, const hknpVehicleInstance *vehicle,
    hknpVehicleTransmissionOutput &output) const /* derived name */
{
    output.gearChangeTimeLeft -= deltaTime;
    if (output.isInGearChange && output.gearChangeTimeLeft <= 0.0f) {
        output.isInGearChange = false;
    }
    if (!output.isReversing) {
        const float rpm = output.transmissionRPM;
        if (rpm < downshiftRPM && output.currentGear > 0) {
            output.currentGear--;
            output.gearChangeTimeLeft = clutchDelayTime;
            output.isInGearChange = true;
        }
        if (rpm > upshiftRPM && output.currentGear + 1 < gearsRatio.size) {
            output.currentGear++;
            output.gearChangeTimeLeft = clutchDelayTime;
            output.isInGearChange = true;
        }
    }
}
