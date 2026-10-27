/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: equal but for the vtable 0x169ae30 (address point 0x169ae40),
// which has no row (docs/NOTES.md, Round 31).
hknpCharacterStateOnGround::hknpCharacterStateOnGround()
    : gain(0.95f), walkSpeed(10.0f), maxLinearAcceleration(200.0f), killVelocityOnLaunch(true),
      limitVerticalVelocity(false), disableHorizontalProjection(false)
{
}
