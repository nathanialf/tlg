/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpVehicleLinearCastWheelCollide::init(const hknpVehicleInstance *vehicle)
{
    const u8 numWheels = vehicle->data->numWheels;
    if (wheelStates.getSize() == 0) {
        wheelStates.setSize(numWheels);
        for (u8 i = 0; i < numWheels; i++) {
            const hknpVehicleDataWheelComponentParams &params = vehicle->data->wheelParams[i];
            wheelStates[i].shape = FUN_00178620(params.width, params.radius);
        }
    }
    for (u8 i = 0; i < numWheels; i++) {
        updateWheelState(vehicle, i);
    }
    chassisBody = vehicle->bodyId.value;
}
