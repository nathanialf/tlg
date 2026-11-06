/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Each wheel fixed when the handbrake is on and the wheel is connected to
 * it; its torque the pedal's share of its maximum, at most what stops the
 * wheel's spin in the step; the wheels blocked once the pedal has passed a
 * wheel's blocking input for long enough. The driver's input is read
 * once, before the wheels; the properties are indexed at each use, read
 * again after the store of the wheel's fixed flag. */
void hknpVehicleDefaultBrake::calcBreakingInfo(
    float deltaTime, const hknpVehicleInstance *vehicle,
    const hknpVehicleFilteredDriverInput &filteredInfoOutput, WheelBreakingOutput &breakingInfo)
{
    const float brakePedalInput = filteredInfoOutput.brakePedalInput;
    const hkBool handbrakeOn = filteredInfoOutput.handbrakeOn;
    hkBool someWheelsBlocking = false;
    for (int i = 0; i < vehicle->data->numWheels; i++) {
        breakingInfo.isFixed[i] = wheelBrakingProperties[i].isConnectedToHandbrake && handbrakeOn;
        if (brakePedalInput > wheelBrakingProperties[i].minPedalInputToBlock) {
            someWheelsBlocking = true;
        }
        const float brakeTorque = brakePedalInput * wheelBrakingProperties[i].maxBreakingTorque;
        const hknpVehicleDataWheelComponentParams &wheel = vehicle->data->wheelParams[i];
        const float maxTorque =
            -(wheel.radius * (wheel.radius * vehicle->wheelsInfo[i].spinVelocity *
                              ((1.0f / deltaTime) * wheel.mass)));
        float torque = maxTorque;
        if (hkMath::fabs(maxTorque) > brakeTorque) {
            torque = maxTorque > 0.0f ? brakeTorque : -brakeTorque;
        }
        breakingInfo.brakingTorque[i] = torque;
    }

    if (someWheelsBlocking) {
        if (breakingInfo.wheelsTimeSinceMaxPedalInput >= wheelsMinTimeToBlock) {
            for (int i = 0; i < vehicle->data->numWheels; i++) {
                if (brakePedalInput > wheelBrakingProperties[i].minPedalInputToBlock) {
                    breakingInfo.isFixed[i] = true;
                }
            }
        } else {
            breakingInfo.wheelsTimeSinceMaxPedalInput += deltaTime;
        }
    } else {
        breakingInfo.wheelsTimeSinceMaxPedalInput = 0.0f;
    }
}
