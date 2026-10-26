/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hknpPairCollisionFilter's finish constructor: the vtable is set and the
 * disabled pairs, which are not serialized, start as an empty map. */
hknpPairCollisionFilter::hknpPairCollisionFilter(hkFinishLoadedObjectFlag flag)
    : hknpCollisionFilter(flag)
{
}
