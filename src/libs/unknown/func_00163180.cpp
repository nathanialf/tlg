/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpVehicleInstance::FUN_00163180(float deltaTime,
                                       const hknpVehicleFilteredDriverInput &filteredDriverInput,
                                       hknpVehicleBrake::WheelBreakingOutput &breakingInfo)
{
    const int numWheels = isFixed.getSize();
    breakingInfo.isFixed.setSize(numWheels);
    breakingInfo.brakingTorque.setSize(numWheels);
    for (int i = 0; i < numWheels; i++) {
        breakingInfo.isFixed[i] = isFixed[i];
    }
    breakingInfo.wheelsTimeSinceMaxPedalInput = wheelsTimeSinceMaxPedalInput;
    brake->calcBreakingInfo(deltaTime, this, filteredDriverInput, breakingInfo);
    for (int i = 0; i < numWheels; i++) {
        isFixed[i] = breakingInfo.isFixed[i];
    }
    wheelsTimeSinceMaxPedalInput = breakingInfo.wheelsTimeSinceMaxPedalInput;
}
