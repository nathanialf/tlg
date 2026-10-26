/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 19 of hkpWrappedConstraintData's vtable (address point
 * 0x169cef0, kept by hknpBreakableConstraintData and
 * hknpMalleableConstraintData) forwards to the wrapped data's slot 19. */
void hkpWrappedConstraintData::FUN_0007d600(const void *argument1, const void *argument2,
                                            const void *argument3,
                                            Vec4 &out) const /* derived name */
{
    constraintData->FUN_0007b5a0(argument1, argument2, argument3, out);
}
