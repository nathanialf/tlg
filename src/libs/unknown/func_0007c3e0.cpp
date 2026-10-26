/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 17 of hkpBallAndSocketConstraintData's vtable (address
 * point 0x169c7e0) sets the ball-socket atom's inertia stabilization factor,
 * clamped to [0, 1], beside slot 18, which hands it out. */
hkResult hkpBallAndSocketConstraintData::FUN_0007c3e0(float factor) /* derived name */
{
    atoms.ballSocket.inertiaStabilizationFactor = hkMath::clamp(factor, 0.0f, 1.0f);
    return HK_SUCCESS;
}
