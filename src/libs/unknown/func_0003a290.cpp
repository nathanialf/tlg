/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the query's filter info against the body's (idB and
 * dontCollideA extracted with `bextr`, D29). */
bool hknpGroupCollisionFilterBasehknpGroupCollisionFilterTypesConfig55516::FUN_0003a290(
    int queryType, const hknpQueryFilterData &filterData, const hknpBody &body) const
{
    return isCollisionEnabled(filterData.collisionFilterInfo, body.collisionFilterInfo) != 0;
}
