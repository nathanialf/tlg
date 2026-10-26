/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 20 of hkpFixedConstraintData's vtable (address point
 * 0x169c630): 48 bytes of runtime and six solver results when a runtime is
 * wanted or the ball socket can breach, else none. */
void hkpFixedConstraintData::FUN_0007bf40(hkBool wantRuntime, ConstraintRuntimeInfo &infoOut) const
{
    if (wantRuntime || atoms.ballSocket.breachImpulse != HK_REAL_MAX) {
        infoOut.sizeOfExternalRuntime = 48;
        infoOut.numSolverResults = 6;
    } else {
        infoOut.sizeOfExternalRuntime = 0;
        infoOut.numSolverResults = 0;
    }
}
