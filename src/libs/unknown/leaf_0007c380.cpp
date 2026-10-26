/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: slot 7 of hkpBallAndSocketConstraintData's vtable (address
 * point 0x169c7e0): whether the ball-socket atom has a solving method set
 * or the stabilization atom is enabled. The answer is a flag set in a
 * branch and returned after it: the second test stays a branch to the
 * shared `movb $1` (cookbook 30), where `return a || b;` makes it a setne. */
hkBool hkpBallAndSocketConstraintData::FUN_0007c380() const /* derived name */
{
    bool stabilized = false;
    if (atoms.ballSocket.solvingMethod != 0 || atoms.setupStabilization.enabled) {
        stabilized = true;
    }
    return stabilized;
}
