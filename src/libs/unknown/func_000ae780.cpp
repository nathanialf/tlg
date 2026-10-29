/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the list emptied, then the set's run of the bone buffer
 * appended. */
void hkStorageSkinnedMeshShape::FUN_000ae780(hkSkinnedMeshShape::BoneSetId boneSetId,
                                             hkArray<s16> &bonesOut) const
{
    const hkSkinnedMeshShape::BoneSet &boneSet = boneSets[boneSetId.value];
    bonesOut.clear();
    bonesOut.append(&bonesBuffer[boneSet.boneBufferOffset], boneSet.numBones);
}
