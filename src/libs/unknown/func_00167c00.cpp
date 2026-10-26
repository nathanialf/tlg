/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Slot 9: enabled unless the child filter, when there is one, says no. */
bool hknpPairCollisionFilter::FUN_00167c00(int queryType, bool targetIsB,
                                           const hknpCollisionFilterShapeInput &a,
                                           const hknpCollisionFilterShapeInput &b) const
{
    if (childFilter) {
        return childFilter->FUN_00167c00(queryType, targetIsB, a, b);
    }
    return true;
}
