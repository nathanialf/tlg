/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 11 of hkpFixedConstraintData's vtable (address point
 * 0x169c630) returns the stabilization atom's linear impulse limit. */
float hkpFixedConstraintData::FUN_0007bed0() const /* derived name */
{
    return atoms.setupStabilization.maxLinImpulse;
}
