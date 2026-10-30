/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hkStorageSkinnedMeshShape::FUN_000ae6b0(int sectionIndex,
                                             hkSkinnedMeshShape::BoneSection &sectionOut) const
{
    sectionOut = boneSections[sectionIndex];
}
