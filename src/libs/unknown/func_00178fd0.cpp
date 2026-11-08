/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpVehicleLinearCastWheelCollide::updateBeforeCollisionDetection(
    const hknpVehicleInstance *vehicle)
{
    const int numWheels = wheelStates.size;
    for (u8 i = 0; i < numWheels; i++) {
        updateWheelState(vehicle, i);
    }
}
