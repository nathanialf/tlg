/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 10 of hkpLimitedHingeConstraintData's vtable (address
 * point 0x169bae0) sets the ball-socket atom's breach impulse. */
void hkpLimitedHingeConstraintData::FUN_000790b0(float newBreachImpulse) /* derived name */
{
    atoms.ballSocket.breachImpulse = newBreachImpulse;
}
