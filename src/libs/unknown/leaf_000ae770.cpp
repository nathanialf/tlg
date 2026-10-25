/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 7 of hkStorageSkinnedMeshShape's vtable (0x16a3b00)
 * copies out one of its bone sets by id. */
void hkStorageSkinnedMeshShape::FUN_000ae770(
    hkSkinnedMeshShape::BoneSetId boneSetId,
    hkSkinnedMeshShape::BoneSet &boneSetOut) const /* derived name */
{
    boneSetOut = boneSets.data[boneSetId.value];
}
