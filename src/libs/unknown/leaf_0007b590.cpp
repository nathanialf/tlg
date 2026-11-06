/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Slot 20 of hkpCogWheelConstraintData's vtable (address point 0x169c2c0): 32 bytes of runtime and
 * 1 solver result. */
void hkpCogWheelConstraintData::unknownVirtual20(hkBool wantRuntime,
                                                 ConstraintRuntimeInfo &infoOut) const
{
    infoOut.sizeOfExternalRuntime = 32;
    infoOut.numSolverResults = 1;
}
