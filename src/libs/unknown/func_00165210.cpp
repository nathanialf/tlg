/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpVehicleInstance::FUN_00165210(float deltaTime, const WheelCollideOutput *collideOutputs,
                                       hknpVehicleJobResults &vehicleResults)
{
    D_16dc078->timerBegin("TtDoVehicle");
    hknpVehicleAerodynamics::AerodynamicsDragOutput aerodynamicsDragInfo;
    hkInplaceArray<float, 16> suspensionForceAtWheel(data->numWheels);
    hkInplaceArray<float, 16> totalLinearForceAtWheel(data->numWheels);
    FUN_001640f0(deltaTime, collideOutputs, aerodynamicsDragInfo, suspensionForceAtWheel,
                 totalLinearForceAtWheel);
    FUN_001648c0(deltaTime, aerodynamicsDragInfo, suspensionForceAtWheel, totalLinearForceAtWheel,
                 vehicleResults);
    D_16dc078->timerEnd("Et");
}
