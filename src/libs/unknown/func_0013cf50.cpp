/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void BroadPhaseTree00142a40::FUN_0013cf50(u32 bodyIndex, const hknpBody *bodies)
{
    Entry entry;
    entry.key = bodyIndex;
    numEntries++;
    const hkAabb16 &aabb = bodies[bodyIndex].aabb;
    for (int i = 0; i < 3; i++) {
        entry.centre2[i] = (aabb.max[i] >> 1) + (aabb.min[i] >> 1);
    }

    int leafIndex;
    if (root == Node::NO_CHILD) {
        Node *node = nodes.FUN_00196630(&root);
        node->aabb.setEmpty();
        numLeaves++;
        const int bucketIndex = allocateBucket();
        node->children[1] = Node::NO_CHILD;
        node->children[0] = bucketIndex;
        buckets[bucketIndex].numEntries = 0;
        leafIndex = root;
    } else {
        leafIndex = FUN_001981e0(&nodes.elements[root], this, entry.centre2, -1);
    }
    FUN_0013bc20(&entry, 1, bodies, this, leafIndex);
    nodes.FUN_00197610(&nodes.elements[root]);
}
