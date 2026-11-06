/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Slot 20 of hkpRackAndPinionConstraintData's vtable (address point 0x16a0210): 20 bytes of runtime and
 * 1 solver result. */
void hkpRackAndPinionConstraintData::unknownVirtual20(hkBool wantRuntime,
                                                      ConstraintRuntimeInfo &infoOut) const
{
    infoOut.sizeOfExternalRuntime = 20;
    infoOut.numSolverResults = 1;
}
