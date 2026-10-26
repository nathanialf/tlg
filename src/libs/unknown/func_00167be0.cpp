/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Slot 7: enabled unless the child filter, when there is one, says no. */
bool hknpPairCollisionFilter::FUN_00167be0(int queryType,
                                           const hknpCollisionFilterQueryInput &query,
                                           const hknpCollisionFilterTargetInput &target) const
{
    if (childFilter) {
        return childFilter->FUN_00167be0(queryType, query, target);
    }
    return true;
}
