/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: slot 7 of hkpFixedConstraintData's vtable (address point
 * 0x169c630): whether the ball-socket atom has a solving method set or the
 * stabilization atom is enabled, written as hkpBallAndSocketConstraintData's
 * slot 7 is (FUN_0007c380, cookbook 30). */
hkBool hkpFixedConstraintData::FUN_0007bf70() const /* derived name */
{
    bool stabilized = false;
    if (atoms.ballSocket.solvingMethod != 0 || atoms.setupStabilization.enabled) {
        stabilized = true;
    }
    return stabilized;
}
