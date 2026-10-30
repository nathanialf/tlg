/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 6 of hkpWrappedConstraintData's vtable (address point
 * 0x169cef0) forwards to the same slot of the constraint data it wraps. */
void hkpWrappedConstraintData::unknownVirtual6(ConstraintInfo &infoOut) const
{
    constraintData->unknownVirtual6(infoOut);
}
