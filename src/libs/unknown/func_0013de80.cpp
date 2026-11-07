/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_algorithm.h"
#include "tlg_lib_unknown.h"

/* A node made one leaf over the bodies of the keys: a bucket taken for it,
 * each body's box copied in with its key and the body's broad phase id
 * pointed at the node, the node's box the union of the boxes, two empty
 * boxes past the last, then the boxes sorted by their minimum x. */
void FUN_0013de80(BroadPhaseTree00142a40 *tree, int nodeIndex, hknpBody *bodies, const u32 *keys,
                  int numKeys)
{
    BroadPhaseTree00142a40::Node &node = tree->nodes.elements[nodeIndex];
    tree->numLeaves++;
    const int bucketIndex = tree->allocateBucket();
    node.children[1] = BroadPhaseTree00142a40::Node::NO_CHILD;
    node.children[0] = bucketIndex;
    BroadPhaseTree00142a40::Bucket &bucket = tree->buckets[bucketIndex];
    bucket.numEntries = numKeys;
    for (int i = 0; i < bucket.numEntries; i++) {
        const u32 key = keys[i];
        hknpBody &body = bodies[key];
        hkAabb16 &entry = bucket.entries[i];
        entry = body.aabb;
        entry.key = u16(key);
        entry.key1 = u16(key >> 16);
        body.broadPhaseId = (body.broadPhaseId & 0xe0000000) | nodeIndex;
    }
    FUN_00185460(&node.aabb, bucket.entries, bucket.numEntries);
    for (int i = 0; i < 2; i++) {
        hkAabb16 &end = bucket.entries[bucket.numEntries + i];
        end.min[0] = 0xffff;
        end.min[1] = end.min[2] = 0x7fff;
        end.max[0] = end.max[1] = end.max[2] = 0;
    }
    hkAlgorithm::quickSort(bucket.entries, bucket.numEntries, hkAlgorithm::less<hkAabb16>());
}
