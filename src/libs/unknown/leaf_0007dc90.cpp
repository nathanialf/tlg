/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 10 of hkpRagdollConstraintData's vtable (address point
 * 0x169d0e0) sets the ball-socket atom's breach impulse. */
void hkpRagdollConstraintData::FUN_0007dc90(float newBreachImpulse) /* derived name */
{
    atoms.ballSocket.breachImpulse = newBreachImpulse;
}
