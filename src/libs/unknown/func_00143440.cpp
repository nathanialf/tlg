/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void BroadPhaseLayers00142a40::FUN_00143440(hkAabb16 &aabbOut) const
{
    aabbOut.setEmpty();
    for (u8 i = 0; i < numLayers; i++) {
        if (const BroadPhaseTree00142a40::Node *root = trees[i]->getRoot()) {
            aabbOut.includeAabb(root->aabb);
        }
    }
}
