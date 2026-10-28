/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 5 of the analog status's vtable: its copy. */
hknpVehicleDriverInputAnalogStatus *hknpVehicleDriverInputAnalogStatus::FUN_00151d30() const
{
    return new hknpVehicleDriverInputAnalogStatus(*this);
}
