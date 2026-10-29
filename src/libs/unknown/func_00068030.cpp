/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

float hknpVehicleDefaultTransmission::FUN_00068030(
    const hknpVehicleInstance *vehicle, const hknpVehicleTransmissionOutput &output) const
{
    float rpm = 0.0f;
    for (int i = 0; i < vehicle->data->numWheels; i++) {
        rpm += (60.0f / (2.0f * HK_REAL_PI)) * vehicle->wheelsInfo.data[i].noSlipIdealSpinVelocity *
               wheelsTorqueRatio.data[i];
    }
    return hkMath::max2(0.0f, rpm * FUN_00067ef0(vehicle, output));
}
