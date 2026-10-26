/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 18 of hkpRagdollConstraintData's vtable (address
 * point 0x169d0e0) hands out the ball-socket atom's inertia stabilization
 * factor; it always has one. */
hkResult hkpRagdollConstraintData::FUN_0007e2e0(float &factorOut) const /* derived name */
{
    factorOut = atoms.ballSocket.inertiaStabilizationFactor;
    return HK_SUCCESS;
}
