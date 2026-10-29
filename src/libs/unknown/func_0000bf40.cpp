/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

// NONMATCHING: the base inlines setFromRotation (its array on the stack under
// the canary the inliner's lifetime markers bring); 3.3 refuses it under -g at
// cost 330 against 325: its vector bonus counts the callee's debug intrinsics
// among the instructions (InlineCost.cpp:806-839), which 3.5 stopped doing.
// Without -g the function compiles equal (docs/NOTES.md, Round 52).
void hkMatrix3::FUN_0000bf40() /* derived name */
{
    hkQuaternion q;
    q.setFromRotation(*this);
    q.normalize();
    setRotation(q);
}
