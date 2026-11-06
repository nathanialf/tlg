/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpVehicleInstance::FUN_00162fb0(float deltaTime,
                                       const hknpVehicleFilteredDriverInput &filteredDriverInput)
{
    hknpVehicleSteering::SteeringAnglesOutput steeringOutput;
    steeringOutput.mainSteeringAngle = mainSteeringAngle;
    steeringOutput.mainSteeringAngleAssumingNoReduction = mainSteeringAngleAssumingNoReduction;
    steeringOutput.wheelsSteeringAngle.setSize(wheelsSteeringAngle.getSize());
    for (int i = 0; i < wheelsSteeringAngle.getSize(); i++) {
        steeringOutput.wheelsSteeringAngle[i] = wheelsSteeringAngle[i];
    }
    steering->calcSteering(deltaTime, this, filteredDriverInput, steeringOutput);
    mainSteeringAngle = steeringOutput.mainSteeringAngle;
    mainSteeringAngleAssumingNoReduction = steeringOutput.mainSteeringAngleAssumingNoReduction;
    for (int i = 0; i < wheelsSteeringAngle.getSize(); i++) {
        wheelsSteeringAngle[i] = steeringOutput.wheelsSteeringAngle[i];
    }
}
