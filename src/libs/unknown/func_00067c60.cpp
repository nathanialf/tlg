/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 7 of hkpWrappedConstraintData's vtable (address point
 * 0x169cef0) forwards to the same slot of the constraint data it wraps. */
hkBool hkpWrappedConstraintData::unknownVirtual7() const
{
    return constraintData->unknownVirtual7();
}
