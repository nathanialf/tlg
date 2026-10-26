/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 8 of hkpFixedConstraintData's vtable (address point
 * 0x169c630) sets the stabilization's linear impulse limit, and the
 * ball-socket atom limits the impulse unless it is the largest float Havok
 * uses, as hkpBallAndSocketConstraintData's slot 8 (0x7c2e0) does. */
void hkpFixedConstraintData::FUN_0007bea0(float newMaxImpulse) /* derived name */
{
    atoms.setupStabilization.maxLinImpulse = newMaxImpulse;
    if (newMaxImpulse >= 3.40282e+38f) {
        atoms.ballSocket.enableLinearImpulseLimit = false;
    } else {
        atoms.ballSocket.enableLinearImpulseLimit = true;
    }
}
