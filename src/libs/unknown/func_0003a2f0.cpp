/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: two query filter datas' infos against each other (slot 7's
 * test, the ids extracted with `bextr`, D29). */
bool hknpGroupCollisionFilterBasehknpGroupCollisionFilterTypesConfig55516::FUN_0003a2f0(
    int queryType, bool argument2, const hknpQueryFilterData &filterDataA,
    const hknpQueryFilterData &filterDataB) const
{
    return isCollisionEnabled(filterDataA.collisionFilterInfo, filterDataB.collisionFilterInfo) !=
           0;
}
