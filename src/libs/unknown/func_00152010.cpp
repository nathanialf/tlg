/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The driver's input filtered for the step: the pedals and the steering
 * from slots 6, 7 and 9, the handbrake as the status holds it, and whether
 * the driver is trying to reverse from slot 8. */
void hknpVehicleDefaultAnalogDriverInput::FUN_00152010(
    float deltaTime, const hknpVehicleInstance *vehicle,
    const hknpVehicleDriverInputAnalogStatus *status, hknpVehicleFilteredDriverInput &output)
{
    output.acceleratorPedalInput = FUN_00151d90(deltaTime, vehicle, status, output);
    output.brakePedalInput = FUN_00151de0(deltaTime, vehicle, status, output);
    output.steeringWheelInput = FUN_00151e10(deltaTime, vehicle, status, output);
    output.handbrakeOn = status->handbrakeButtonPressed;
    output.tryingToReverse = FUN_00151ea0(deltaTime, vehicle, status, output);
}
