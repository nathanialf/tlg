/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 8 of hknpVehicleDefaultTransmission's vtable (address
 * point 0x1699ba0), whose answer slot 5 stores as the output's isReversing:
 * reversing when the driver tries to and no forward gear is in. */
bool hknpVehicleDefaultTransmission::FUN_00068130(const hknpVehicleInstance *vehicle,
                                                  const hknpVehicleTransmissionOutput &output) const
{
    bool reversing = false;
    if (vehicle->tryingToReverse) {
        if (output.currentGear <= 0) {
            reversing = true;
        }
    }
    return reversing;
}
