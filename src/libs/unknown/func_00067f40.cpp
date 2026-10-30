/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpVehicleDefaultTransmission::FUN_00067f40(float deltaTime,
                                                  const hknpVehicleInstance *vehicle,
                                                  hknpVehicleTransmissionOutput &output) const
{
    output.isReversing = FUN_00068130(vehicle, output);
    output.mainTransmittedTorque = FUN_00067ff0(vehicle, output);
    output.transmissionRPM = FUN_00068030(vehicle, output);
    for (int i = 0; i < wheelsTorqueRatio.getSize(); i++) {
        output.wheelsTransmittedTorque[i] = output.mainTransmittedTorque * wheelsTorqueRatio[i];
    }
    FUN_000680b0(deltaTime, vehicle, output);
}
