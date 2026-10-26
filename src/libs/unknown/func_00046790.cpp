/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hknpPhysicsSceneData's finish constructor: nothing loaded needs fixing up
 * (its arrays and reference pointers keep their loaded values), so only the
 * vtable is set. */
hknpPhysicsSceneData::hknpPhysicsSceneData(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag)
{
}
