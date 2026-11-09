/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void BroadPhaseTree00142a40::FUN_0013b940(hknpBody *bodies, const u32 *bodyIndices, int numBodies)
{
    {
        LocalBuffer<hkAabb16> aabbs(numBodies);
        for (int i = 0; i < numBodies; i++) {
            aabbs.data[i] = bodies[bodyIndices[i]].aabb;
        }
        FUN_00196190(aabbs.data, bodyIndices, numBodies);
    }
    LocalArray<int> leaves(numBodies);
    FUN_00198830(root, this, leaves);
    for (int i = 0; i < leaves.getSize(); i++) {
        const int bucketIndex = nodes.elements[leaves[i]].children[0];
        for (int j = 0; j < buckets[bucketIndex].numEntries; j++) {
            hknpBody &body = bodies[buckets[bucketIndex].entries[j].getKey()];
            body.broadPhaseId = (body.broadPhaseId & 0xe0000000) | leaves[i];
        }
    }
}
