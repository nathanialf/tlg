/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 12 of hknpVehicleRayCastWheelCollide's vtable: the
 * box around the wheels' rays. */
void hknpVehicleRayCastWheelCollide::FUN_00158a40(const hknpVehicleInstance *vehicle,
                                                  hkAabb &aabbOut) const
{
    aabbOut.min =
        _mm_min_ps(vehicle->wheelsInfo[0].hardPointWs, vehicle->wheelsInfo[0].rayEndPointWs);
    aabbOut.max =
        _mm_max_ps(vehicle->wheelsInfo[0].hardPointWs, vehicle->wheelsInfo[0].rayEndPointWs);
    for (int i = 1; i < vehicle->data->numWheels; i++) {
        const hknpVehicleInstance::WheelInfo &wheelInfo = vehicle->wheelsInfo[i];
        aabbOut.min = _mm_min_ps(aabbOut.min, wheelInfo.rayEndPointWs);
        aabbOut.min = _mm_min_ps(aabbOut.min, wheelInfo.hardPointWs);
        aabbOut.max = _mm_max_ps(aabbOut.max, wheelInfo.rayEndPointWs);
        aabbOut.max = _mm_max_ps(aabbOut.max, wheelInfo.hardPointWs);
    }
}
