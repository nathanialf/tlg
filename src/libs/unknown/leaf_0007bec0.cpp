/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 9 of hkpFixedConstraintData's vtable (address point
 * 0x169c630) sets the stabilization atom's angular impulse limit. */
void hkpFixedConstraintData::FUN_0007bec0(float newMaxAngImpulse) /* derived name */
{
    atoms.setupStabilization.maxAngImpulse = newMaxAngImpulse;
}
