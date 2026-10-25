/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 19 of hkpConstraintData's vtable (address point
 * 0x169fad0) by default writes a zero vector. */
void hkpConstraintData::FUN_0007b5a0(const void *argument1, const void *argument2,
                                     const void *argument3, Vec4 &out) const /* derived name */
{
    out = _mm_setzero_ps();
}
