/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_algorithm.h"
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

/* The bodies of one leaf removed from it: their indices gathered from the
 * keys from first to last into a buffer of the thread's stack. derived
 * name. */
static inline void removeBodiesFromLeaf(BroadPhaseTree00142a40 *tree, const u32 *bodyIndices,
                                        const KeyIndex0013b870 *keys, int first, int last,
                                        const hknpBody *bodies, int nodeIndex) /* derived name */
{
    const int numInLeaf = last - first;
    LocalBuffer<u32> indices(numInLeaf);
    for (int i = 0; i < numInLeaf; i++) {
        indices.data[i] = bodyIndices[keys[first + i].index];
    }
    FUN_0013d110(indices.data, numInLeaf, bodies, tree, nodeIndex);
}

/* derived name: the bodies' boxes removed from the tree: each body's key (its broad phase id, the
 * leaf's node) gathered with its place in the list into a buffer of the thread's stack, the keys
 * sorted, and the bodies of each leaf removed from it together. */
// NONMATCHING: greedy's assignment (199 of 243 lines in place, 889 bytes as the base once the
// thread-local accesses are relaxed): the key count takes eax and the body count edi here where
// the base gives the count r8 and the body count eax; every later use of the count follows, and
// the key's compare then folds its load (`cmp [r12 + r13*8], ecx`) where the base loads it into
// the free eax first.
void BroadPhaseTree00142a40::FUN_0013db00(const u32 *bodyIndices, int numBodies,
                                          const hknpBody *bodies)
{
    if (numBodies == 0) {
        return;
    }
    LocalBuffer<KeyIndex0013b870> keys(numBodies);
    int numKeys = 0;
    for (int i = 0; i < numBodies; i++) {
        const u32 broadPhaseId = bodies[bodyIndices[i]].broadPhaseId;
        if (broadPhaseId != 0xffffffff) {
            keys.data[numKeys].key = broadPhaseId & 0x1fffffff;
            keys.data[numKeys].index = i;
            numKeys++;
        }
    }
    if (numKeys == 0) {
        return;
    }

    hkAlgorithm::quickSort(keys.data, numKeys, hkAlgorithm::less<KeyIndex0013b870>());
    int first = -1;
    u32 nodeIndex = 0xffffffff;
    for (int k = 0; k < numKeys; k++) {
        if (keys.data[k].key != nodeIndex) {
            if (nodeIndex != 0xffffffff) {
                removeBodiesFromLeaf(this, bodyIndices, keys.data, first, k, bodies, nodeIndex);
            }
            first = k;
            nodeIndex = keys.data[k].key;
        }
    }
    removeBodiesFromLeaf(this, bodyIndices, keys.data, first, numKeys, bodies, nodeIndex);
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
// NONMATCHING: 203 of 207, size equal: equal under LocalArray's SDK order (data, capacity, local
// copy: 0x14107a, 0x141087, 0x14108a, the fourth function that stores them, D41); the tree's
// order stores the local copy before the capacity. The header waits for 0x1707d0 (D41). The
// destructor's conditional size clear is the base's (0x141240 to 0x14124a), then the local
// block's free, then hkArray's.
void BroadPhaseLayers00142a40::FUN_00140ff0(const hknpBodyId *bodyIds, int numBodies,
                                            hknpBody *bodies)
{
    LocalArray<u8> bodyLayers(numBodies);
    bodyLayers.setSize(numBodies);
    config->FUN_00154e10(bodyIds, numBodies, bodies, bodyLayers.data);

    if (numBodies == 1) {
        const u8 layer = bodyLayers.data[0];
        hknpBody &body = bodies[bodyIds[0].value];
        body.broadPhaseId = (u32(layer) << 29) | (body.broadPhaseId & 0x1fffffff);
        trees[layer]->FUN_0013cf50(bodyIds[0].value, bodies);
        updatePending[layer] = true;
        return;
    }

    LocalArray<u32> indices(numBodies);
    for (u8 layer = 0; layer < numLayers; layer++) {
        int numInLayer = 0;
        for (int i = 0; i < numBodies; i++) {
            if (bodyLayers.data[i] == layer) {
                indices.data[numInLayer++] = bodyIds[i].value;
            }
        }
        if (numInLayer) {
            trees[layer]->FUN_0013d530(layer, indices.data, numInLayer, bodies);
            updatePending[layer] = true;
        }
    }
}

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
