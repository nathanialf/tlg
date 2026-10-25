/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 11 of hkpBallAndSocketConstraintData's vtable (address
 * point 0x169c7e0) returns the stabilization atom's linear impulse limit,
 * which slot 8 (0x7c2e0) sets together with enableLinearImpulseLimit. */
float hkpBallAndSocketConstraintData::FUN_0007c300() const /* derived name */
{
    return atoms.setupStabilization.maxLinImpulse;
}
