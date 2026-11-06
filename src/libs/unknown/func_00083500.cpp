/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Slot 20 of hkpRotationalConstraintData's vtable (address point
 * 0x16a0120): 24 bytes of runtime and three solver results when a runtime is
 * wanted, else none. */
void hkpRotationalConstraintData::unknownVirtual20(hkBool wantRuntime,
                                                   ConstraintRuntimeInfo &infoOut) const
{
    if (wantRuntime) {
        infoOut.sizeOfExternalRuntime = 24;
        infoOut.numSolverResults = 3;
    } else {
        infoOut.sizeOfExternalRuntime = 0;
        infoOut.numSolverResults = 0;
    }
}
