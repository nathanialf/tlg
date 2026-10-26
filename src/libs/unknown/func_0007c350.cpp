/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 20 of hkpBallAndSocketConstraintData's vtable (address
 * point 0x169c7e0): 24 bytes of runtime and three solver results when a
 * runtime is wanted or the ball socket can breach, else none. */
// NONMATCHING: the base tests `!=` with one `je` (fcmp one/ueq, no parity branch); our compile
// of `!=` gives `jne; jnp` (une). The library region has no parity branch at all; docs/NOTES.md
// Round 28.
void hkpBallAndSocketConstraintData::FUN_0007c350(hkBool wantRuntime,
                                                  ConstraintRuntimeInfo &infoOut) const
{
    if (wantRuntime || atoms.ballSocket.breachImpulse != 3.40282e+38f) {
        infoOut.sizeOfExternalRuntime = 24;
        infoOut.numSolverResults = 3;
    } else {
        infoOut.sizeOfExternalRuntime = 0;
        infoOut.numSolverResults = 0;
    }
}
