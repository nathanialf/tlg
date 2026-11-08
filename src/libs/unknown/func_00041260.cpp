/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The compound shape description's constructor: everything empty. */
hknpCompoundShapeCinfo::hknpCompoundShapeCinfo()
    : instances(0), numInstances(0), instanceCapacity(0), isMutable(false), massConfig(0),
      instanceIdsOut(0)
{
}
