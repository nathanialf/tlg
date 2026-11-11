/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
/* The broad phase trees and layers, one unit in the base's address order (0x13cf50 to
 * 0x142bb0): 0x13e090's unswitched gather loop spends the compile's unswitch budget before
 * the layers' removals (docs/DECISIONS.md D42). */
#include "tlg_hk_algorithm.h"
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

/* The box grown by a point, as the rebuild's bounds are (derived name; the
 * box's own setEmpty and includeAabb are in the header). */
static inline void includeCentre(hkAabb16 &aabb, const BroadPhaseTree00142a40::Entry &entry)
{
    for (int i = 0; i < 3; i++) {
        const u16 centre = u16(entry.centre2[i] >> 1);
        aabb.max[i] = aabb.max[i] <= centre ? centre : aabb.max[i];
    }
    for (int i = 0; i < 3; i++) {
        const u16 centre = u16(entry.centre2[i] >> 1);
        aabb.min[i] = aabb.min[i] >= centre ? centre : aabb.min[i];
    }
}

/* The sort's order: by the minimum x (derived name). */
static inline bool lessMinX(const hkAabb16 &a, const hkAabb16 &b)
{
    return a.min[0] < b.min[0];
}

/* Boxes sorted by their minimum x, by insertion (the bucket's boxes and
 * their count handed over once, 0x13e3f0 reads the count before the walk),
 * the order a function of the two boxes (the entry's copy reaches it by
 * reference, so it is split only after the inliner, cookbook 191). */
static inline void sortEntries(hkAabb16 *entries, int numEntries)
{
    for (int i = 0; i < numEntries; i++) {
        int j = i;
        const hkAabb16 entry = entries[i];
        while (j > 0 && lessMinX(entry, entries[j - 1])) {
            entries[j] = entries[j - 1];
            j--;
        }
        entries[j] = entry;
    }
}

/* A box's key: its body's index, split over the box's two key words. */
static inline u32 entryKey(const hkAabb16 &entry)
{
    return (u32(entry.key1) << 16) | entry.key;
}

/* A bucket's boxes onto a rebuild list, each as its key and its centres. */
static inline void appendEntries(BroadPhaseTree00142a40::Entry *list,
                                 const BroadPhaseTree00142a40::Bucket &bucket)
{
    for (int i = 0; i < bucket.numEntries; i++) {
        const hkAabb16 &entry = bucket.entries[i];
        list[i].key = entryKey(entry);
        list[i].centre2[0] = entry.min[0] + entry.max[0];
        list[i].centre2[1] = entry.min[1] + entry.max[1];
        list[i].centre2[2] = entry.min[2] + entry.max[2];
    }
}

// NONMATCHING: written as the function the program has, for its callers'
// sake (its first and fourth arguments are not read, so 3.3's
// DeadArgumentElimination passes neither from a caller in this unit); in
// progress (docs/NOTES.md, Rounds 56 to 58). The frame is the base's under
// D35. Classified (Round 58): the leaf jobs' gather loop is unswitched on
// the split test in the base (two copies, the loop's guard before the
// test), the shape D21 parks for 0x187750, which 3.3 makes only with the
// non-trivial unswitch -O2 does not run. Open beside it: the centres box is
// promoted across the gather loop's calls in the base, which needs
// FUN_0013c340 defined in this unit (its centres argument then nocapture,
// so the box does not escape); the two dissolve loops' block order and the
// extent's reload after the left one; the jobs' size reload.
void FUN_0013e090(BroadPhaseLayers00142a40 *layers, BroadPhaseTree00142a40 *tree,
                  const hknpBody *bodies, int layer, bool keepAabbs, int maxAgedLeaves)
{
    typedef BroadPhaseTree00142a40::Node Node;
    typedef BroadPhaseTree00142a40::Bucket Bucket;
    typedef BroadPhaseTree00142a40::Entry Entry;

    if (tree->root == Node::NO_CHILD || tree->numEntries == 0) {
        return;
    }
    tree->nodes.FUN_00196570(tree->numLeaves * 4);

    /* The tree walked into items and leaves. */
    TreeWalk0013b790 walk(tree, tree->numLeaves, &tree->nodes.elements[tree->root]);

    /* Each bucket's leaf, and each leaf's box and whether it went. */
    u32 maxBucket = 0;
    for (int i = 0; i < walk.leaves.size; i++) {
        const u32 bucket = u32(walk.leaves[i]->children[0]);
        maxBucket = hkMath::max2(maxBucket, bucket);
    }
    const int numLeaves = tree->numLeaves;

    /* One object (0xa40 bytes): built in this order as the base builds
     * them, laid out in ascending order of address, and the walk's item
     * counter, dead before it is built, shares its first bytes. */
    struct Leaves /* derived name */ {
        TempInplaceArray<int, 128> leafOfBucket;
        TempInplaceArray<bool, 1024> removed;
        hkInplaceArrayAligned16<hkAabb16, 64> aabbs;
    } leaves;

    leaves.leafOfBucket.setSize(hkContainerTempAllocator::get(), int(maxBucket) + 1);
    leaves.aabbs.setSize(numLeaves);
    leaves.removed.setSize(hkContainerTempAllocator::get(), numLeaves);
    for (int i = 0; i < walk.leaves.size; i++) {
        leaves.leafOfBucket[walk.leaves[i]->children[0]] = i;
    }
    for (int i = 0; i < numLeaves; i++) {
        leaves.removed[i] = false;
    }

    /* The boxes refreshed from their bodies, two at a time. */
    if (!keepAabbs) {
        for (int i = 0; i < tree->numLeaves; i++) {
            Bucket &bucket = tree->buckets[walk.leaves[i]->children[0]];
            const int numEntries = bucket.numEntries;
            const int numPairs = numEntries & ~1;
            int j = 0;
            for (; j < numPairs; j += 2) {
                hkAabb16 &first = bucket.entries[j];
                hkAabb16 &second = bucket.entries[j + 1];
                const u16 firstKey = first.key;
                const u16 firstKey1 = first.key1;
                const u16 secondKey = second.key;
                const u16 secondKey1 = second.key1;
                first = bodies[entryKey(first)].aabb;
                second = bodies[entryKey(second)].aabb;
                first.key = firstKey;
                first.key1 = firstKey1;
                second.key = secondKey;
                second.key1 = secondKey1;
            }
            for (; j < numEntries; j++) {
                hkAabb16 &entry = bucket.entries[j];
                const u16 key = entry.key;
                const u16 key1 = entry.key1;
                entry = bodies[entryKey(entry)].aabb;
                entry.key = key;
                entry.key1 = key1;
            }
        }
    }

    /* Beyond the number given, every bucket ages and the youngest of that
     * many restart. */
    if (tree->numLeaves > maxAgedLeaves) {
        LocalArray<LeafAge0013b6c0> ages(walk.leaves.size);
        ages.setSize(walk.leaves.size);
        for (int i = 0; i < walk.leaves.size; i++) {
            Bucket &bucket = tree->buckets[walk.leaves[i]->children[0]];
            ages[i].age = bucket.age;
            ages[i].leaf = i;
            bucket.age++;
        }
        if (ages.size >= 2) {
            hkAlgorithm::quickSortRecursive(ages.data, 0, ages.size - 1,
                                            hkAlgorithm::less<LeafAge0013b6c0>());
        }
        for (int i = walk.leaves.size - maxAgedLeaves; i < walk.leaves.size; i++) {
            tree->buckets[walk.leaves[ages[i].leaf]->children[0]].age = 0;
        }
    }

    /* Empty buckets freed, the others' boxes of their centres; a leaf whose
     * bucket aged gets its box and its sort back. */
    for (int i = 0; i < walk.leaves.size; i++) {
        Node *leaf = walk.leaves[i];
        const int bucketIndex = leaf->children[0];
        Bucket *const buckets = tree->buckets.data;
        Bucket &bucket = buckets[u32(bucketIndex)];
        const int leafIndex = leaves.leafOfBucket[bucketIndex];
        if (bucket.numEntries == 0) {
            bool &leafRemoved = leaves.removed[leafIndex];
            tree->freeBuckets.pushBack(bucketIndex);
            tree->numLeaves--;
            leafRemoved = true;
        } else {
            hkAabb16 &leafAabb = leaves.aabbs[leafIndex];
            FUN_001854b0(&leafAabb, bucket.entries, bucket.numEntries);
            leafAabb.key = 0;
        }
        if (!keepAabbs) {
            Bucket &aged = buckets[bucketIndex];
            if (aged.age != 0) {
                FUN_00185460(&leaf->aabb, aged.entries, aged.numEntries);
                sortEntries(aged.entries, aged.numEntries);
            }
        }
    }

    /* The rebuild: a node's job splits its leaves' boxes and the boxes it
     * inherited at the middle of their bounds on the longest axis. */
    struct Job {
        int node;
        int start;
        int numInherited;
        int count;
        int buffer;
        int item;
    };

    struct LeafJob {
        int node;
        Entry *inherited;
        int numInherited;
        int count;
    };

    hkArray<LeafJob>::Temp leafJobs;
    leafJobs.reserve(hkContainerTempAllocator::get(), tree->numLeaves);
    LocalBuffer<Entry> buffers[2] = {tree->numEntries, tree->numEntries};
    TempInplaceArray<Job, 64> jobs;
    {
        Job &job = jobs.expandOne(hkContainerTempAllocator::get());
        job.node = tree->root;
        job.start = 0;
        job.numInherited = 0;
        job.count = tree->numEntries;
        job.buffer = 0;
        job.item = 0;
    }
    TempInplaceArray<int, 64> droppedNodes;
    do {
        const Job job = jobs[jobs.size - 1];
        jobs.size--;
        const int other = job.buffer ^ 1;
        Node *node = &tree->nodes.elements[job.node];
        if (node->children[1] == Node::NO_CHILD || job.count <= tree->maxLeafEntries) {
            LeafJob &leafJob = leafJobs.expandOne(hkContainerTempAllocator::get());
            leafJob.node = job.node;
            leafJob.inherited = buffers[other].data + job.start;
            leafJob.numInherited = job.numInherited;
            leafJob.count = job.count;
            continue;
        }

        /* The bounds of each side's leaves and of the inherited centres. */
        const TreeWalk0013b790::Item &item = walk.items[job.item];
        const int numLeft = item.numLeft;
        const int numRight = item.numRight;
        const int firstLeaf = item.firstLeaf;
        hkAabb16 childAabbs[2];
        childAabbs[0].setEmpty();
        for (int i = 0; i < numLeft; i++) {
            const int leafIndex = leaves.leafOfBucket[walk.leaves[firstLeaf + i]->children[0]];
            if (!leaves.removed[leafIndex]) {
                childAabbs[0].includeAabb(leaves.aabbs[leafIndex]);
            }
        }
        childAabbs[1].setEmpty();
        int numRightEntries = 0;
        for (int i = 0; i < numRight; i++) {
            const int bucketIndex = walk.leaves[firstLeaf + numLeft + i]->children[0];
            const int leafIndex = leaves.leafOfBucket[bucketIndex];
            if (!leaves.removed[leafIndex]) {
                numRightEntries += tree->buckets[bucketIndex].numEntries;
                childAabbs[1].includeAabb(leaves.aabbs[leafIndex]);
            }
        }
        hkAabb16 aabb = childAabbs[0];
        aabb.includeAabb(childAabbs[1]);
        int numInherited = job.numInherited;
        for (int i = 0; i < numInherited; i++) {
            includeCentre(aabb, buffers[other].data[job.start + i]);
        }

        int extent[3];
        for (int i = 0; i < 3; i++) {
            extent[i] = aabb.max[i] - aabb.min[i];
        }
        int axis = u32(extent[0]) < u32(extent[1]) ? 1 : 0;
        if (u32(extent[axis]) < u32(extent[2])) {
            axis = 2;
        }
        const u32 middle = (aabb.max[axis] >> 1) + (aabb.min[axis] >> 1);
        const u32 slack = u32(extent[axis]) >> 4;

        /* A leaf that reaches well past the middle on the other side, and
         * has not aged, is dissolved into the boxes the children inherit. */
        const u32 upper = middle + slack;
        if (childAabbs[0].max[axis] > upper) {
            for (int i = 0; i < numLeft; i++) {
                const int bucketIndex = walk.leaves[firstLeaf + i]->children[0];
                Bucket &bucket = tree->buckets[bucketIndex];
                if (bucket.age != 0) {
                    continue;
                }
                const int leafIndex = leaves.leafOfBucket[bucketIndex];
                if (leaves.removed[leafIndex] || leaves.aabbs[leafIndex].max[axis] <= upper) {
                    continue;
                }
                appendEntries(buffers[other].data + job.start + numInherited, bucket);
                tree->freeBuckets.pushBack(bucketIndex);
                numInherited += bucket.numEntries;
                tree->numLeaves--;
                leaves.removed[leafIndex] = true;
            }
        }
        const u32 lower = middle - slack;
        if (childAabbs[1].min[axis] < lower) {
            for (int i = 0; i < numRight; i++) {
                const int bucketIndex = walk.leaves[firstLeaf + numLeft + i]->children[0];
                Bucket &bucket = tree->buckets[bucketIndex];
                if (bucket.age != 0) {
                    continue;
                }
                const int leafIndex = leaves.leafOfBucket[bucketIndex];
                if (leaves.removed[leafIndex] || leaves.aabbs[leafIndex].min[axis] >= lower) {
                    continue;
                }
                appendEntries(buffers[other].data + job.start + numInherited, bucket);
                tree->freeBuckets.pushBack(bucketIndex);
                numInherited += bucket.numEntries;
                tree->numLeaves--;
                leaves.removed[leafIndex] = true;
                numRightEntries -= bucket.numEntries;
            }
        }

        /* The inherited boxes partitioned into this job's buffer: the left
         * ones from the start, the right ones down from the end of the
         * right side's room. */
        Entry *const leftStart = buffers[job.buffer].data + job.start;
        Entry *const rightStart =
            buffers[job.buffer].data + (job.start + job.count - 1 - numRightEntries);
        Entry *left = leftStart;
        Entry *right = rightStart;
        for (int i = 0; i < numInherited; i++) {
            const Entry entry = buffers[other].data[job.start + i];
            if (entry.centre2[axis] > 2 * middle) {
                *right-- = entry;
            } else {
                *left++ = entry;
            }
        }
        const int split = job.start + int(right - leftStart) + 1;
        const int numLeftEntries = split - job.start;

        /* A side left with nothing gives its node up: the other child moves
         * into this node, and the empty side's subtree is dropped. */
        Node *nodes = tree->nodes.elements.data;
        const int leftChild = node->children[0];
        const int rightChild = node->children[1];
        const int leftItem = item.leftItem;
        const int rightItem = item.rightItem;
        int leftNode = leftChild;
        int rightNode = rightChild;
        if (numLeftEntries == 0) {
            *node = nodes[rightChild];
            tree->nodes.FUN_00198a20(rightChild);
            droppedNodes.expandOne(hkContainerTempAllocator::get()) = leftChild;
            rightNode = job.node;
        }
        if (job.count == numLeftEntries) {
            *node = nodes[leftChild];
            tree->nodes.FUN_00198a20(leftChild);
            droppedNodes.expandOne(hkContainerTempAllocator::get()) = rightChild;
            leftNode = job.node;
        }
        if (numLeftEntries != 0) {
            Job &leftJob = jobs.expandOne(hkContainerTempAllocator::get());
            leftJob.node = leftNode;
            leftJob.start = job.start;
            leftJob.numInherited = int(left - leftStart);
            leftJob.count = numLeftEntries;
            leftJob.buffer = other;
            leftJob.item = leftItem;
        }
        if (job.count != numLeftEntries) {
            Job &rightJob = jobs.expandOne(hkContainerTempAllocator::get());
            rightJob.node = rightNode;
            rightJob.start = split;
            rightJob.numInherited = int(rightStart - right);
            rightJob.count = job.count - numLeftEntries;
            rightJob.buffer = other;
            rightJob.item = rightItem;
        }
    } while (jobs.size != 0);

    /* The dropped subtrees' nodes back to the pool. */
    for (int i = 0; i < droppedNodes.size; i++) {
        LocalArray<int> innerNodes(tree->numLeaves);
        LocalArray<int> leafNodes(tree->numLeaves);
        FUN_001985d0(droppedNodes[i], tree, &innerNodes, &leafNodes);
        for (int j = 0; j < leafNodes.size; j++) {
            tree->nodes.FUN_00198a20(leafNodes[j]);
        }
        for (int j = 0; j < innerNodes.size; j++) {
            tree->nodes.FUN_00198a20(innerNodes[j]);
        }
    }

    /* Each leaf job: a leaf that inherited nothing keeps its bucket (its
     * box and sort back unless its bucket aged); any other gathers the
     * keys of its subtree's buckets and the inherited ones and is rebuilt
     * over them. */
    while (leafJobs.size != 0) {
        const LeafJob leafJob = leafJobs[leafJobs.size - 1];
        leafJobs.size--;
        Node *nodes = tree->nodes.elements.data;
        Node &node = nodes[leafJob.node];
        if (leafJob.numInherited == 0 && node.children[1] == Node::NO_CHILD) {
            if (!keepAabbs) {
                Bucket &bucket = tree->buckets[node.children[0]];
                if (bucket.age == 0) {
                    FUN_00185460(&node.aabb, bucket.entries, bucket.numEntries);
                    sortEntries(bucket.entries, bucket.numEntries);
                }
            }
            continue;
        }

        const bool split = leafJob.count > tree->maxLeafEntries;
        hkAabb16 centres;
        centres.setEmpty();
        if (split) {
            for (int i = 0; i < leafJob.numInherited; i++) {
                includeCentre(centres, leafJob.inherited[i]);
            }
        }
        LocalArray<int> leafNodes(tree->numLeaves + 1);
        LocalArray<int> innerNodes(tree->numLeaves);
        if (node.children[1] == Node::NO_CHILD) {
            leafNodes.pushBackUnchecked(leafJob.node);
        }
        hkArray<int>::Temp keys(leafJob.numInherited);
        keys.reserve(hkContainerTempAllocator::get(), leafJob.count);
        for (int i = 0; i < leafJob.numInherited; i++) {
            keys[i] = leafJob.inherited[i].key;
        }
        int numKeys = leafJob.numInherited;
        for (int child = 0; child < 2; child++) {
            if (node.children[1] != Node::NO_CHILD) {
                FUN_001985d0(node.children[child], tree, &innerNodes, &leafNodes);
            }
            for (int i = 0; i < leafNodes.size; i++) {
                const int bucketIndex = tree->nodes.elements[leafNodes[i]].children[0];
                const int leafIndex = leaves.leafOfBucket[bucketIndex];
                if (!leaves.removed[leafIndex]) {
                    if (split) {
                        centres.includeAabb(leaves.aabbs[leafIndex]);
                    }
                    const Bucket &bucket = tree->buckets[bucketIndex];
                    for (int j = 0; j < bucket.numEntries; j++) {
                        keys.pushBackUnchecked(int(entryKey(bucket.entries[j])));
                    }
                    tree->freeBuckets.pushBack(bucketIndex);
                    numKeys += bucket.numEntries;
                    tree->numLeaves--;
                }
                if (leafNodes[i] != leafJob.node) {
                    tree->nodes.FUN_00198a20(leafNodes[i]);
                }
            }
            for (int i = 0; i < innerNodes.size; i++) {
                tree->nodes.FUN_00198a20(innerNodes[i]);
            }
            leafNodes.size = 0;
            innerNodes.size = 0;
        }
        if (split) {
            FUN_0013c340(tree, leafJob.node, &centres, bodies, keys.data, numKeys);
        } else {
            FUN_0013de80(tree, leafJob.node, bodies, keys.data, numKeys);
        }
    }

    tree->nodes.FUN_00197610(&tree->nodes.elements[tree->root]);
}

// NONMATCHING: round 142C, 150 of 246 by sequence, 992 bytes for 955; the bit field's and the
// reference's code in the base's shape. Residuals: (1) greedy's assignment from the first
// instruction (this in r12, the capacity in ebx, where the base has rbx and r15d); (2) the words'
// pointer for the fill's memset is read before the size store and the guard, where the base reads
// it in the guarded block (the loop's preheader); an in-loop read is not hoisted at all (measured);
// (3) the layer index is copied to rsi as 64 bits (`mov rsi, r15`) where the base copies 32
// (`mov esi, r14d`): its index is an i32 zero-extended at the call, the u8 counter widened once.
BroadPhaseLayers00142a40::BroadPhaseLayers00142a40(int bodyCapacity, hknpBroadPhaseConfig *config_)
    : markedBodies(bodyCapacity, 0), lowestMarkedId(0xffffffff), highestMarkedId(0), tasks(HK_NULL)
{
    config = config_;
    numLayers = config_->getNumLayers();
    for (u8 i = 0; i < numLayers; i++) {
        const hknpBroadPhaseConfig::Layer *layer = config_->FUN_00154e00(i);
        trees[i] = new BroadPhaseTree00142a40(0x1d);
        flag50[i] = layer->isVolatile;
        updatePending[i] = false;
    }
    for (u8 i = u8(numLayers); i < 8; i++) {
        trees[i] = HK_NULL;
    }
    for (u8 i = 0; i < numLayers; i++) {
        const hknpBroadPhaseConfig::Layer *layerA = config_->FUN_00154e00(i);
        for (u8 j = i; j < numLayers; j++) {
            const hknpBroadPhaseConfig::Layer *layerB = config_->FUN_00154e00(j);
            if ((layerA->collideWithLayerMask & (1 << j)) ||
                (layerB->collideWithLayerMask & (1 << i))) {
                layerPairs.pushBack(i);
                layerPairs.pushBack(j);
            }
        }
    }
}

/* The broad phase's trees by layer destroyed (the compiler's D0 at 0x140e20
 * and D1 at 0x140e70): each layer's tree and the tasks deleted, then the
 * marked bodies, the layer pairs and the configuration's reference. */
BroadPhaseLayers00142a40::~BroadPhaseLayers00142a40()
{
    for (int i = 0; i < numLayers; i++) {
        delete trees[i];
    }
    delete tasks;
}

/* derived name: one body is taken straight from its leaf; several are
 * gathered layer by layer (the layers counted in a byte) into a buffer of
 * the thread's stack and removed from each layer's tree that holds some of
 * them; each removed body's mark cleared. */
// The array's destructor: the conditional size clear is the base's (0x141240 to 0x14124a), then the local
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

/* A layer's volatile tree updated, its boxes refreshed from the bodies and
 * no bucket's age reset beyond the tree's own leaves, then the layer's
 * pending flag cleared. */
void FUN_00142a40(BroadPhaseLayers00142a40 *layers, const hknpBody *bodies, int layer)
{
    D_16dc078->timerBegin("TtUpdateVolatileTree");
    BroadPhaseTree00142a40 *tree = layers->trees[layer];
    FUN_0013e090(layers, tree, bodies, layer, false, tree->numLeaves);
    layers->updatePending[layer] = false;
    D_16dc078->timerEnd("Et");
}

/* A layer's non-volatile tree updated, its boxes refreshed from the bodies
 * only when asked (0x142af0, from the layer task at 0x18d1da). */
void FUN_00142af0(BroadPhaseLayers00142a40 *layers, const hknpBody *bodies, int layer,
                  bool refreshAabbs)
{
    D_16dc078->timerBegin("TtUpdateNonVolatileTree");
    BroadPhaseTree00142a40 *tree = layers->trees[layer];
    FUN_0013e090(layers, tree, bodies, layer, !refreshAabbs, tree->numLeaves);
    layers->updatePending[layer] = false;
    D_16dc078->timerEnd("Et");
}

/* The two layer updates' timer ends keep their own counter reads (the
 * tail merge stops at the asm, docs/DECISIONS.md D34). */
void FUN_00142bb0(BroadPhaseLayers00142a40 *layers, const hknpBody *bodies, int mode)
{
    D_16dc078->timerBegin("TtUpdateBroadPhase");
    if (layers->lowestMarkedId <= layers->highestMarkedId) {
        FUN_00141500(layers, bodies);
    }
    for (int i = 0; i < layers->numLayers; i++) {
        if (layers->trees[i]->numEntries > 0) {
            if (layers->flag50[i]) {
                FUN_00142a40(layers, bodies, i);
            } else if (layers->updatePending[i] || mode == 1) {
                FUN_00142af0(layers, bodies, i, mode == 1);
            }
        }
        layers->updatePending[i] = false;
    }
    D_16dc078->timerEnd("Et");
}
