/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* NONMATCHING: equal but for one store's place (190 instructions, 710
 * bytes): the leaves' local array stores its data, its capacity and then
 * its local copy of the data in the base (Havok's hkLocalArray order,
 * 0x13bab4 after 0x13bab1), where the tree's LocalArray stores the copy
 * before the capacity. Measured with the constructor in Havok's order:
 * this function, 0x1412e0, 0x142a40, 0x142af0 and 0x142bb0 all equal,
 * only 0x1707d0 off (its first instruction 0x1707ee). The supervisor's
 * LocalArray question; NOTES Round 81A. */
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
