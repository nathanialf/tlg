/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 8 of hknpVehicleDefaultTransmission's vtable (address
 * point 0x1699ba0), whose answer slot 5 stores as the output's isReversing:
 * reversing when the driver tries to and no forward gear is in. */
// NONMATCHING: the base returns from two blocks (`cmpb; je 1f; cmpb; setle
// %al; ret; 1: xorb %al,%al; ret`); clang 3.3 gives every form of this test
// one return block, and the zero is then set before the first compare
// (`xorb %al,%al; cmpb; je 1f; cmpb; setle %al; 1: ret`). llc 3.3 gives the
// base's bytes only from IR with two `ret`s; docs/NOTES.md Round 21.
bool hknpVehicleDefaultTransmission::FUN_00068130(const hknpVehicleInstance *vehicle,
                                                  const hknpVehicleTransmissionOutput &output) const
{
    if (vehicle->tryingToReverse) {
        return output.currentGear <= 0;
    }
    return false;
}
