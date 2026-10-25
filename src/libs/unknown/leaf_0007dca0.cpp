/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 13 of hkpRagdollConstraintData's vtable (address point
 * 0x169d0e0) returns the ball-socket atom's breach impulse; a game vtable
 * (0x16b6508, slot 12) holds the same body. */
float hkpRagdollConstraintData::FUN_0007dca0() const /* derived name */
{
    return atoms.ballSocket.breachImpulse;
}
