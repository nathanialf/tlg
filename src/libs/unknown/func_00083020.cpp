/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 20 of hkpDeformableFixedConstraintData's vtable (address
 * point 0x169fe00; also hkpWheelConstraintData's): 48 bytes of runtime and six
 * solver results when a runtime is wanted, else none. */
void hkpDeformableFixedConstraintData::FUN_00083020(hkBool wantRuntime,
                                                    ConstraintRuntimeInfo &infoOut) const
{
    if (wantRuntime) {
        infoOut.sizeOfExternalRuntime = 48;
        infoOut.numSolverResults = 6;
    } else {
        infoOut.sizeOfExternalRuntime = 0;
        infoOut.numSolverResults = 0;
    }
}
