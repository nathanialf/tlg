/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 8 of hkpBallAndSocketConstraintData's vtable (address
 * point 0x169c7e0) sets the stabilization's linear impulse limit, and the
 * ball-socket atom limits the impulse unless it is the largest float Havok
 * uses (the bytes test `>=` and invert: unordered counts as a limit). */
void hkpBallAndSocketConstraintData::FUN_0007c2e0(float newMaxImpulse)
{
    atoms.setupStabilization.maxLinImpulse = newMaxImpulse;
    if (newMaxImpulse >= HK_REAL_MAX) {
        atoms.ballSocket.enableLinearImpulseLimit = false;
    } else {
        atoms.ballSocket.enableLinearImpulseLimit = true;
    }
}
