/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Slot 6: enabled unless the child filter, when there is one, says no; the
 * bool is widened again on its way (cookbook 17). */
bool hknpPairCollisionFilter::FUN_00167ad0(int queryType, bool flag) const
{
    if (childFilter) {
        return childFilter->FUN_00167ad0(queryType, flag);
    }
    return true;
}
