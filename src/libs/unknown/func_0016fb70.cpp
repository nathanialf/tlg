/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the main steering angle, then every wheel's. */
void hknpVehicleDefaultSteering::calcSteering(
    float deltaTime, const hknpVehicleInstance *vehicle,
    const hknpVehicleFilteredDriverInput &filteredInfoOutput,
    SteeringAnglesOutput &steeringOutput) const
{
    calcMainSteeringAngle(deltaTime, vehicle, filteredInfoOutput, steeringOutput);
    for (int i = 0; i < doesWheelSteer.getSize(); i++) {
        if (doesWheelSteer[i]) {
            steeringOutput.wheelsSteeringAngle[i] = steeringOutput.mainSteeringAngle;
        } else {
            steeringOutput.wheelsSteeringAngle[i] = 0.0f;
        }
    }
}
