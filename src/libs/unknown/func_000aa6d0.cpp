/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 0's body (0xaa6d0; the deleting destructor 0xaa680 calls it): the
 * skinned mesh's reference released and the bones given back, then the
 * members' own destructors. */
hkSkinnedRefMeshShape::~hkSkinnedRefMeshShape()
{
    skinnedMeshShape = HK_NULL;
    bones.clearAndDeallocate();
}
