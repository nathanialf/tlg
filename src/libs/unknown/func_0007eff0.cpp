/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 20 of hkpHingeConstraintData's vtable (address point
 * 0x169d500): 40 bytes of runtime and five solver results when a runtime
 * is wanted, else none. */
void hkpHingeConstraintData::FUN_0007eff0(hkBool wantRuntime, ConstraintRuntimeInfo &infoOut) const
{
    if (wantRuntime) {
        infoOut.sizeOfExternalRuntime = 40;
        infoOut.numSolverResults = 5;
    } else {
        infoOut.sizeOfExternalRuntime = 0;
        infoOut.numSolverResults = 0;
    }
}
