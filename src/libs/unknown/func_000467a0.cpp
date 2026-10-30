/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slots 0 and 1 of its vtable (0x1697ea0): the world's info released, then
 * the systems' reference pointers by the array's destructor. The class's
 * key function: the deleting destructor (0x467a0) comes first, then the
 * complete one (0x467f0). */
hknpPhysicsSceneData::~hknpPhysicsSceneData()
{
    if (worldCinfo) {
        worldCinfo->removeReference();
        worldCinfo = HK_NULL;
    }
}
