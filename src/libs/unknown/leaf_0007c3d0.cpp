/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 18 of hkpBallAndSocketConstraintData's vtable (address
 * point 0x169c7e0) hands out the ball-socket atom's inertia stabilization
 * factor; it always has one. */
hkResult hkpBallAndSocketConstraintData::FUN_0007c3d0(float &factorOut) const /* derived name */
{
    factorOut = atoms.ballSocket.inertiaStabilizationFactor;
    return HK_SUCCESS;
}
