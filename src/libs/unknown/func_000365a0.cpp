/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: equal; its vtable 0x1693610 has no row (a D14 ruling).
hknpCharacterStateInAir::hknpCharacterStateInAir()
    : gain(0.05f), airSpeed(10.0f), maxLinearAcceleration(50.0f)
{
}
