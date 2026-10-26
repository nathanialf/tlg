/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 20 of hkpWheelFrictionConstraintData's vtable (address
 * point 0x16a5f10): no solver results, and one byte of runtime only when a
 * runtime is wanted. */
void hkpWheelFrictionConstraintData::FUN_0017cf30(hkBool wantRuntime,
                                                  ConstraintRuntimeInfo &infoOut) const
{
    infoOut.numSolverResults = 0;
    infoOut.sizeOfExternalRuntime = wantRuntime ? 1 : 0;
}
