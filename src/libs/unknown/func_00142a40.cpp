/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_algorithm.h"
#include "tlg_lib_unknown.h"

/* The box made empty (the minima the largest, the maxima and the keys zero)
 * and grown by another box or by a point, as the rebuild's bounds are
 * (derived names). */
static inline void setEmpty(hkAabb16 &aabb)
{
    aabb.min[0] = aabb.min[1] = aabb.min[2] = 0xffff;
    aabb.key = 0;
    aabb.max[0] = aabb.max[1] = aabb.max[2] = 0;
    aabb.key1 = 0;
}

static inline void includeAabb(hkAabb16 &aabb, const hkAabb16 &other)
{
    for (int i = 0; i < 3; i++) {
        aabb.max[i] = hkMath::max2(aabb.max[i], other.max[i]);
    }
    for (int i = 0; i < 3; i++) {
        aabb.min[i] = hkMath::min2(aabb.min[i], other.min[i]);
    }
}

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

    TempArray<LeafJob> leafJobs;
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
        setEmpty(childAabbs[0]);
        for (int i = 0; i < numLeft; i++) {
            const int leafIndex = leaves.leafOfBucket[walk.leaves[firstLeaf + i]->children[0]];
            if (!leaves.removed[leafIndex]) {
                includeAabb(childAabbs[0], leaves.aabbs[leafIndex]);
            }
        }
        setEmpty(childAabbs[1]);
        int numRightEntries = 0;
        for (int i = 0; i < numRight; i++) {
            const int bucketIndex = walk.leaves[firstLeaf + numLeft + i]->children[0];
            const int leafIndex = leaves.leafOfBucket[bucketIndex];
            if (!leaves.removed[leafIndex]) {
                numRightEntries += tree->buckets[bucketIndex].numEntries;
                includeAabb(childAabbs[1], leaves.aabbs[leafIndex]);
            }
        }
        hkAabb16 aabb = childAabbs[0];
        includeAabb(aabb, childAabbs[1]);
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
        FUN_001985d0(droppedNodes[i], tree, innerNodes, leafNodes);
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
        setEmpty(centres);
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
        TempArray<int> keys(leafJob.numInherited);
        keys.reserve(hkContainerTempAllocator::get(), leafJob.count);
        for (int i = 0; i < leafJob.numInherited; i++) {
            keys[i] = leafJob.inherited[i].key;
        }
        int numKeys = leafJob.numInherited;
        for (int child = 0; child < 2; child++) {
            if (node.children[1] != Node::NO_CHILD) {
                FUN_001985d0(node.children[child], tree, innerNodes, leafNodes);
            }
            for (int i = 0; i < leafNodes.size; i++) {
                const int bucketIndex = tree->nodes.elements[leafNodes[i]].children[0];
                const int leafIndex = leaves.leafOfBucket[bucketIndex];
                if (!leaves.removed[leafIndex]) {
                    if (split) {
                        includeAabb(centres, leaves.aabbs[leafIndex]);
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
