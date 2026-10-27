/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Nothing to destroy; the deleting destructor (0x691d0, slot 1 of the vtable
 * 0x169a0d0 and of hkpFixedConstraintData's and hkpHingeConstraintData's)
 * is the one emitted with it. */
hkpVehicleFrictionDescription::~hkpVehicleFrictionDescription() {}
