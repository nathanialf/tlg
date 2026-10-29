/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The default suspension's destructor (slot 0 of its vtable): the springs'
 * parameters given back, then the wheels' (the base's destructor inline). */
hknpVehicleDefaultSuspension::~hknpVehicleDefaultSuspension() {}
