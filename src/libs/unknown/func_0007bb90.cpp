/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 20 of hkpPointToPlaneConstraintData's vtable (address
 * point 0x169c540): 8 bytes of runtime and one solver result when a runtime
 * is wanted, else none. */
void hkpPointToPlaneConstraintData::FUN_0007bb90(hkBool wantRuntime,
                                                 ConstraintRuntimeInfo &infoOut) const
{
    if (wantRuntime) {
        infoOut.sizeOfExternalRuntime = 8;
        infoOut.numSolverResults = 1;
    } else {
        infoOut.sizeOfExternalRuntime = 0;
        infoOut.numSolverResults = 0;
    }
}
