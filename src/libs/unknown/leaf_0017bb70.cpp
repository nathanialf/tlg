/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 18 of hkp6DofConstraintData's vtable (address point
 * 0x16a5d30) hands out the ball-socket atom's inertia stabilization factor;
 * it always has one. */
hkResult hkp6DofConstraintData::FUN_0017bb70(float &factorOut) const /* derived name */
{
    factorOut = blueprints.ballSocket.inertiaStabilizationFactor;
    return HK_SUCCESS;
}
