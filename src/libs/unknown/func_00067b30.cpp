/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 20 of hkpWrappedConstraintData's vtable (address point
 * 0x169cef0, kept by hknpBreakableConstraintData and
 * hknpMalleableConstraintData) forwards to the wrapped data's slot 20. Emitted in hknpMalleableConstraintData's file, like slot 7. */
void hkpWrappedConstraintData::FUN_00067b30(hkBool wantRuntime,
                                            ConstraintRuntimeInfo &infoOut) const /* derived name */
{
    constraintData->unknownVirtual20(wantRuntime, infoOut);
}
