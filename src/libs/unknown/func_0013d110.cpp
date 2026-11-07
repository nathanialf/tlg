/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* NONMATCHING: draft; defined here because the layers' removal below
 * passes it nothing in its unused third argument (dead argument
 * elimination replaces the argument with undef at the call sites of a
 * function defined in the same file). */
void FUN_0013d110(const u32 *keys, int numKeys, const hknpBody *bodies,
                  BroadPhaseTree00142a40 *tree, int nodeIndex)
{
    BroadPhaseTree00142a40::Node &node = tree->nodes.elements[nodeIndex];
    BroadPhaseTree00142a40::Bucket &bucket = tree->buckets[node.children[0]];
    tree->numEntries -= numKeys;
    if (bucket.numEntries == numKeys) {
        bucket.numEntries = 0;
        node.aabb.setEmpty();
        return;
    }
    for (int k = 0; k < numKeys; k++) {
        const u32 key = keys[k];
        int index = -1;
        for (int i = 0; i < bucket.numEntries; i++) {
            if (bucket.entries[i].getKey() == key) {
                index = i;
                break;
            }
        }
        const hkAabb16 removed = bucket.entries[index];
        const hkAabb16 nodeAabb = node.aabb;
        bucket.numEntries--;
        for (int i = index; i < bucket.numEntries; i++) {
            bucket.entries[i] = bucket.entries[i + 1];
        }
        hkAabb16 &freed = bucket.entries[bucket.numEntries];
        freed.min[0] = 0xffff;
        freed.min[1] = freed.min[2] = 0x7fff;
        freed.max[0] = freed.max[1] = freed.max[2] = 0;
        const int onEdge =
            (nodeAabb.max[0] - removed.max[0] - 1) | (nodeAabb.max[1] - removed.max[1] - 1) |
            (nodeAabb.max[2] - removed.max[2] - 1) | (removed.min[0] - nodeAabb.min[0] - 1) |
            (removed.min[1] - nodeAabb.min[1] - 1) | (removed.min[2] - nodeAabb.min[2] - 1);
        if (onEdge & 0x8000) {
            hkAabb16 aabb = bucket.entries[0];
            for (int i = 1; i < bucket.numEntries; i++) {
                aabb.includeAabb(bucket.entries[i]);
            }
            node.aabb = aabb;
        }
    }
}

/* One body's box removed from a leaf (the removal of several with one
 * key). derived name. */
static inline void removeBodyFromLeaf(BroadPhaseTree00142a40 *tree, hknpBodyId bodyId,
                                      const hknpBody *bodies, int nodeIndex) /* derived name */
{
    FUN_0013d110(&bodyId.value, 1, bodies, tree, nodeIndex);
}

/* derived name: one body is taken straight from its leaf; several are
 * gathered layer by layer (the layers counted in a byte) into a buffer of
 * the thread's stack and removed from each layer's tree that holds some of
 * them; each removed body's mark cleared. */
void BroadPhaseLayers00142a40::FUN_001412e0(const hknpBodyId *bodyIds, int numBodies,
                                            const hknpBody *bodies)
{
    if (numBodies == 1) {
        const u32 broadPhaseId = bodies[bodyIds[0].value].broadPhaseId;
        if (broadPhaseId != u32(-1)) {
            const int layer = broadPhaseId >> 29;
            removeBodyFromLeaf(trees[layer], bodyIds[0], bodies, broadPhaseId & 0x1fffffff);
            updatePending[layer] = true;
            const u32 index = bodyIds[0].value;
            if (index < u32(markedBodies.storage.numBits)) {
                markedBodies.clear(index);
            }
        }
        return;
    }

    LocalArray<u32> indices(numBodies);
    for (u8 layer = 0; layer < numLayers; layer++) {
        int numInLayer = 0;
        for (int i = 0; i < numBodies; i++) {
            const u32 index = bodyIds[i].value;
            const u32 broadPhaseId = bodies[index].broadPhaseId;
            if ((broadPhaseId & 0x1fffffff) != 0x1fffffff && (broadPhaseId >> 29) == layer) {
                indices.data[numInLayer++] = index;
                if (bodyIds[i].value < u32(markedBodies.storage.numBits)) {
                    markedBodies.clear(bodyIds[i].value);
                }
            }
        }
        if (numInLayer) {
            trees[layer]->FUN_0013db00(indices.data, numInLayer, bodies);
            updatePending[layer] = true;
        }
    }
}
