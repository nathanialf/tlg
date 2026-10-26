/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 18 of hkpLimitedHingeConstraintData's vtable (address
 * point 0x169bae0) hands out the ball-socket atom's inertia stabilization
 * factor; it always has one. */
hkResult hkpLimitedHingeConstraintData::FUN_000792d0(float &factorOut) const /* derived name */
{
    factorOut = atoms.ballSocket.inertiaStabilizationFactor;
    return HK_SUCCESS;
}
