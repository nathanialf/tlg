/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hknpConstraintCollisionFilter's finish constructor: the pair filter
 * finishes itself and the vtable is set. */
hknpConstraintCollisionFilter::hknpConstraintCollisionFilter(hkFinishLoadedObjectFlag flag)
    : hknpPairCollisionFilter(flag)
{
}
