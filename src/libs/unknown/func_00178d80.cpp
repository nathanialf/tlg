/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* hknpVehicleLinearCastWheelCollide's destructor (0x178d80, slot 0; the
 * deleting destructor 0x178c80 beside it): each wheel state's shape
 * released, then the states' storage given back. */
hknpVehicleLinearCastWheelCollide::~hknpVehicleLinearCastWheelCollide()
{
    const int numWheels = wheelStates.getSize();
    for (int i = 0; i < numWheels; i++) {
        wheelStates[i].shape->removeReference();
    }
}
