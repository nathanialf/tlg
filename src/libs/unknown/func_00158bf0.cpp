/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpVehicleRayCastWheelCollide::collideWheels(float deltaTime,
                                                   const hknpVehicleInstance *vehicle,
                                                   WheelCollideOutput *outputs,
                                                   const hknpWorld *world)
{
    const u8 numWheels = vehicle->data->numWheels;
    for (u8 i = 0; i < numWheels; i++) {
        const hknpVehicleInstance::WheelInfo &wheelInfo = vehicle->wheelsInfo[i];
        hknpClosestHitCollector collector;
        FUN_00158ae0(wheelInfo, world, &collector);
        WheelCollideOutput &output = outputs[i];
        if (collector.hasHit) {
            FUN_00158e20(vehicle, i, collector, output, world);
        } else {
            FUN_00159010(vehicle, i, output);
        }
        wheelCollideCallback(vehicle, i, output);
    }
}
