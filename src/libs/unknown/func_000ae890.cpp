/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hkStorageSkinnedMeshShape::FUN_000ae890(hkMeshShape *meshBuffer,
                                             hkSkinnedMeshShape::BoneSetId startBoneSetId,
                                             int numBoneSets) /* derived name */
{
    hkSkinnedMeshShape::BoneSection &section = boneSections.expandOne();
    section.meshBuffer = meshBuffer;
    section.startBoneSetId = startBoneSetId;
    section.numBoneSets = s16(numBoneSets);
}
