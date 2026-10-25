/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 13 of hkpLimitedHingeConstraintData's vtable (address
 * point 0x169bae0) returns the ball-socket atom's breach impulse; two game
 * vtables (0x16b6508, 0x16ba808) hold the same body. */
float hkpLimitedHingeConstraintData::FUN_000790c0() const /* derived name */
{
    return atoms.ballSocket.breachImpulse;
}
