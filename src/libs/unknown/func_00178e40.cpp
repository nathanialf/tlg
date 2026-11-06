/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpVehicleLinearCastWheelCollide::collideWheels(float deltaTime,
                                                      const hknpVehicleInstance *vehicle,
                                                      WheelCollideOutput *outputs,
                                                      const hknpWorld *world)
{
    const u8 numWheels = vehicle->data->numWheels;
    for (u8 i = 0; i < numWheels; i++) {
        hknpCollisionResult result;
        result.clear();
        result.unknown5c = 0;
        WheelCollideOutput &output = outputs[i];
        if (FUN_00179210(vehicle, i, world, result)) {
            FUN_001794e0(vehicle, i, result, world, output);
        } else {
            FUN_00179700(vehicle, i, output);
        }
        wheelCollideCallback(vehicle, i, output);
    }
}
