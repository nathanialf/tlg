/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

int hkStorageSkinnedMeshShape::FUN_000aea40(const s16 *HK_RESTRICT bones,
                                            int numBones) /* derived name */
{
    const int boneSetIndex = boneSets.getSize();
    hkSkinnedMeshShape::BoneSet &boneSet = boneSets.expandOne();
    boneSet.boneBufferOffset = u16(bonesBuffer.getSize());
    boneSet.numBones = u16(numBones);
    bonesBuffer.append(bones, numBones);
    return boneSetIndex;
}
