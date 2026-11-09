/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_hk_algorithm.h"
#include "tlg_lib_unknown.h"

/* derived name: no root yet, so the reset finds no nodes to drop. */
BroadPhaseTree00142a40::BroadPhaseTree00142a40(int maxLeafEntries) : maxLeafEntries(maxLeafEntries)
{
    root = Node::NO_CHILD;
    reset();
}

/* derived names: BroadPhaseTree00142a40's complete destructor (its row is
 * the D1 since the layers' destructor 0x140e70, which deletes each layer's
 * tree with it, became the compiler's): it runs the base destructor
 * FUN_00195ff0, which resets the tree and frees its arrays at +0x40, +0x30,
 * +0x10 and +0. Two functions because the destructor was inline where the
 * linker kept it (3.3 aliases D1 to D2 only for a strong definition,
 * CGCXX.cpp TryEmitDefinitionAsAlias); still written as a call over a
 * stand-in until the base destructor's body is. */
struct Object00195ff0; /* derived name */

void FUN_00195ff0(Object00195ff0 *self); /* derived name */

void FUN_00195fe0(Object00195ff0 *self) /* derived name */
{
    FUN_00195ff0(self);
}

/* derived name: the tree built over boxes: emptied, the nodes grown to
 * room for twice as many leaves as the boxes fill at a quarter of the leaf
 * size, the root taken, the indices of the boxes and the box around their
 * centres made, the root's subtree built (0x196720) and refitted. */
// NONMATCHING: 149 of 248 by a listing with 0x196720's draft defined in this file (145 before):
// the base keeps the box around the centres in six registers through the loop (LICM's
// promotion, the box stored after it); the draft's callee copies the box into its first job,
// and the loop's 16-bit compares stay to be read (the base's are 32-bit over zero-extended
// values).
void BroadPhaseTree00142a40::FUN_00196190(const hkAabb16 *aabbs, const u32 *bodyIndices,
                                          int numAabbs)
{
    if (numAabbs == 0) {
        return;
    }
    reset();
    numEntries = numAabbs;
    nodes.growTo(2 * (numAabbs / (maxLeafEntries >> 2)) + 1);
    nodes.FUN_00196630(&root);

    hkArray<int>::Temp indices(numAabbs);
    indices.setSize(numAabbs);
    hkAabb16 centres;
    centres.setEmpty();
    for (int i = 0; i < numAabbs; i++) {
        indices[i] = i;
        u16 centre[3];
        for (int j = 0; j < 3; j++) {
            centre[j] = u16((aabbs[i].min[j] >> 1) + (aabbs[i].max[j] >> 1));
        }
        for (int j = 0; j < 3; j++) {
            centres.min[j] = hkMath::min2(centres.min[j], centre[j]);
        }
        for (int j = 0; j < 3; j++) {
            centres.max[j] = hkMath::max2(centres.max[j], centre[j]);
        }
    }
    FUN_00196720(root, centres, aabbs, bodyIndices, indices.data, numAabbs);
    nodes.FUN_00197610(&nodes.elements[root]);
}

/* A subtree waiting to be built (derived names), 32 bytes: the box around
 * its boxes' centres, its run of the indices and the node it becomes. */
struct BuildJob00196720 /* derived name */
{
    hkAabb16 centres;
    int start;
    int count;
    int nodeIndex;
};

/* A box's centre, each axis's halves summed. derived name. */
static inline void getCentre2(const hkAabb16 &aabb, u32 (&centre2)[3])
{
    for (int i = 0; i < 3; i++) {
        centre2[i] = (aabb.max[i] >> 1) + (aabb.min[i] >> 1);
    }
}

/* A box grown by a centre. derived name. */
static inline void includeCentre(hkAabb16 &aabb, const u32 (&centre2)[3])
{
    for (int i = 0; i < 3; i++) {
        aabb.min[i] = hkMath::min2(aabb.min[i], u16(centre2[i]));
    }
    for (int i = 0; i < 3; i++) {
        aabb.max[i] = hkMath::max2(aabb.max[i], u16(centre2[i]));
    }
}

/* The subtree under a node built over the boxes the indices name, from a
 * stack of jobs: a job of fewer boxes than a leaf holds kept for the end,
 * else its indices split at the centre of the longest axis of its centres'
 * box (in half when that axis is shorter than 2), the two halves' centres'
 * boxes grown as they are sorted, two nodes taken for them; then each kept
 * job made one leaf, its boxes copied into a new bucket with their bodies'
 * keys, the node's box their union, two empty boxes past the last and the
 * boxes sorted. The number of leaves made back. */
// NONMATCHING: draft (round 96A), 3822 bytes as the base, 33 of 788 by quick_diff: the
// base's first pass enters the job loop with the index known (no empty test; the first job's
// stores rbp-relative and the size not reloaded) and holds the centre and extent arrays and the
// two leaf-job arrays 0x40 bytes deeper in a larger frame; the partition's order not yet walked.
int BroadPhaseTree00142a40::FUN_00196720(int nodeIndex, const hkAabb16 &centres,
                                         const hkAabb16 *aabbs, const u32 *bodyIndices,
                                         int *indices, int numIndices)
{
    hkInplaceArray<BuildJob00196720, 64> leafJobs;
    hkInplaceArray<BuildJob00196720, 64> jobs;
    BuildJob00196720 &first = jobs.expandOne();
    first.centres = centres;
    first.start = 0;
    first.count = numIndices;
    first.nodeIndex = nodeIndex;
    while (jobs.getSize()) {
        const BuildJob00196720 job = jobs[jobs.getSize() - 1];
        jobs.popBack();
        if (job.count < maxLeafEntries) {
            leafJobs.pushBack(job);
            continue;
        }
        u32 centre2[3];
        u32 extent[3];
        for (int i = 0; i < 3; i++) {
            centre2[i] = (job.centres.min[i] >> 1) + (job.centres.max[i] >> 1);
            extent[i] = job.centres.max[i] - job.centres.min[i];
        }
        int axis = extent[0] < extent[1] ? 1 : 0;
        if (extent[axis] < extent[2]) {
            axis = 2;
        }
        hkAabb16 centresA;
        hkAabb16 centresB;
        int mid;
        if (extent[axis] < 2) {
            centresA = job.centres;
            centresB = job.centres;
            mid = job.start + job.count / 2;
        } else {
            const u32 split = centre2[axis];
            centresA.setEmpty();
            centresB.setEmpty();
            int i = job.start;
            int j = job.start + job.count - 1;
            while (true) {
                u32 centreI[3];
                getCentre2(aabbs[indices[i]], centreI);
                while (centreI[axis] <= split) {
                    includeCentre(centresA, centreI);
                    i++;
                    getCentre2(aabbs[indices[i]], centreI);
                }
                u32 centreJ[3];
                getCentre2(aabbs[indices[j]], centreJ);
                while (centreJ[axis] > split) {
                    includeCentre(centresB, centreJ);
                    j--;
                    getCentre2(aabbs[indices[j]], centreJ);
                }
                if (i >= j) {
                    break;
                }
                const int index = indices[i];
                indices[i] = indices[j];
                indices[j] = index;
                includeCentre(centresA, centreJ);
                includeCentre(centresB, centreI);
                i++;
                j--;
                if (i > j) {
                    break;
                }
            }
            mid = i;
        }
        int indexA;
        nodes.FUN_00196630(&indexA);
        nodes.elements[job.nodeIndex].children[0] = indexA;
        int indexB;
        nodes.FUN_00196630(&indexB);
        nodes.elements[job.nodeIndex].children[1] = indexB;
        const int countA = mid - job.start;
        const int countB = job.count - countA;

        BuildJob00196720 jobB;
        jobB.centres = centresB;
        jobB.start = mid;
        jobB.count = countB;
        jobB.nodeIndex = indexB;
        if (countB < maxLeafEntries) {
            leafJobs.pushBack(jobB);
        } else {
            jobs.pushBack(jobB);
        }
        BuildJob00196720 jobA;
        jobA.centres = centresA;
        jobA.start = job.start;
        jobA.count = countA;
        jobA.nodeIndex = indexA;
        if (countA < maxLeafEntries) {
            leafJobs.pushBack(jobA);
        } else {
            jobs.pushBack(jobA);
        }
    }

    for (int i = 0; i < leafJobs.getSize(); i++) {
        const BuildJob00196720 &job = leafJobs[i];
        numLeaves++;
        const int bucketIndex = allocateBucket();
        Node &node = nodes.elements[job.nodeIndex];
        node.children[1] = Node::NO_CHILD;
        node.children[0] = bucketIndex;
        Bucket &bucket = buckets[bucketIndex];
        bucket.numEntries = job.count;
        for (int j = 0; j < bucket.numEntries; j++) {
            const int index = indices[job.start + j];
            hkAabb16 &entry = bucket.entries[j];
            entry = aabbs[index];
            entry.key = u16(bodyIndices[index]);
            entry.key1 = u16(bodyIndices[index] >> 16);
        }
        FUN_00185460(&nodes.elements[job.nodeIndex].aabb, bucket.entries, bucket.numEntries);
        for (int j = 0; j < 2; j++) {
            hkAabb16 &end = bucket.entries[bucket.numEntries + j];
            end.min[0] = 0xffff;
            end.min[1] = end.min[2] = 0x7fff;
            end.max[0] = end.max[1] = end.max[2] = 0;
        }
        hkAlgorithm::quickSort(bucket.entries, bucket.numEntries, hkAlgorithm::less<hkAabb16>());
    }
    return leafJobs.getSize();
}

inline void ElementPool00198a20::growTo(u32 numElements)
{
    const int oldSize = elements.getSize();
    if (oldSize < int(numElements)) {
        elements.setSize(numElements);
        freeIndices.reserve(hkContainerHeapAllocator::get(), numElements);
        for (int i = numElements - 1; i >= oldSize; i--) {
            freeIndices.pushBackUnchecked(i);
        }
    }
}

void ElementPool00198a20::FUN_00196570(u32 numElements)
{
    growTo(numElements);
}

ElementPool00198a20::Element *ElementPool00198a20::FUN_00196630(int *indexOut)
{
    if (freeIndices.getSize() == 0) {
        growTo(elements.getSize() + 128);
    }
    *indexOut = freeIndices[freeIndices.getSize() - 1];
    freeIndices.setSizeUnchecked(freeIndices.getSize() - 1);
    return &elements[*indexOut];
}

/* A leaf counts one; an inner node's count is its children's, its box the
 * first child's grown by the second's. */
// NONMATCHING: equal but for the leaf's return: the base keeps `mov eax, 1; jmp` in a block of
// its own on the leaf edge (`jne body` first), this compile sets eax before the compare and
// jumps to the shared epilogue (`je`), one byte shorter (NOTES Round 63B).
int ElementPool00198a20::FUN_00197610(Element *node)
{
    if (node->children[1] == Element::NO_CHILD) {
        return 1;
    }
    Element *const nodes = elements.data;
    Element &a = nodes[node->children[0]];
    Element &b = nodes[node->children[1]];
    node->numLeaves = FUN_00197610(&a) + FUN_00197610(&b);
    node->aabb = a.aabb;
    for (int i = 0; i < 3; i++) {
        node->aabb.max[i] = hkMath::max2(node->aabb.max[i], b.aabb.max[i]);
    }
    for (int i = 0; i < 3; i++) {
        node->aabb.min[i] = hkMath::min2(node->aabb.min[i], b.aabb.min[i]);
    }
    return node->numLeaves;
}

/* A node of a tree by its index, its cache line prefetched for the walk's
 * next step. derived name. */
static inline const BroadPhaseTree00142a40::Node *prefetchNode(const BroadPhaseTree00142a40 *tree,
                                                               int index)
{
    const BroadPhaseTree00142a40::Node *node = &tree->nodes.elements[index];
    _mm_prefetch(reinterpret_cast<const char *>(node), _MM_HINT_NTA);
    return node;
}

/* A pair of leaves appended to the list. derived name. */
static inline void addLeafPair(hkArray<LeafPair00197710> &pairsOut,
                               const BroadPhaseTree00142a40::Node *leafA,
                               const BroadPhaseTree00142a40::Node *leafB)
{
    pairsOut.expandOne().set(leafA, leafB);
}

/* The two trees walked against each other on a stack of node pairs, 128
 * in place and doubled when fewer than three slots are left: a pair whose
 * boxes are disjoint dropped, two leaves appended, a node against itself
 * split into its children's pairs, else the inner node's (or both nodes')
 * children paired, one pair walked on and the others pushed. */
void FUN_00197710(const BroadPhaseTree00142a40 *treeA, const BroadPhaseTree00142a40 *treeB,
                  hkArray<LeafPair00197710> &pairsOut)
{
    typedef BroadPhaseTree00142a40::Node Node;
    const Node *rootA = treeA->getRoot();
    const Node *rootB = treeB->getRoot();
    if (!rootA || !rootB) {
        return;
    }
    if (rootA == rootB && rootA->children[1] == Node::NO_CHILD) {
        addLeafPair(pairsOut, rootA, rootA);
        return;
    }
    hkInplaceArray<LeafPair00197710, 128> stack;
    stack.setSize(128);
    stack[0].set(rootA, rootB);
    int numPairs = 1;
    int stackSize = stack.getSize();
    do {
        numPairs--;
        const Node *a = stack[numPairs].leafA;
        const Node *b = stack[numPairs].leafB;
        while (!a->aabb.disjoint(b->aabb)) {
            if (numPairs >= stackSize - 3) {
                stackSize *= 2;
                stack.setSize(stackSize);
            }
            if (a == b) {
                const Node *node = a;
                while (true) {
                    const Node *child0 = prefetchNode(treeA, node->children[0]);
                    const Node *child1 = prefetchNode(treeA, node->children[1]);
                    if (child1->children[1] == Node::NO_CHILD) {
                        addLeafPair(pairsOut, child1, child1);
                    } else {
                        stack[numPairs].set(child1, child1);
                        numPairs++;
                    }
                    stack[numPairs].set(child0, child1);
                    numPairs++;
                    if (child0->children[1] == Node::NO_CHILD) {
                        addLeafPair(pairsOut, child0, child0);
                        break;
                    }
                    node = child0;
                }
                break;
            }
            const bool aIsLeaf = a->children[1] == Node::NO_CHILD;
            const bool bIsLeaf = b->children[1] == Node::NO_CHILD;
            if (aIsLeaf) {
                if (bIsLeaf) {
                    addLeafPair(pairsOut, a, b);
                    break;
                }
                const Node *b0 = prefetchNode(treeB, b->children[0]);
                const Node *b1 = prefetchNode(treeB, b->children[1]);
                stack[numPairs].set(a, b0);
                numPairs++;
                b = b1;
            } else {
                const Node *a0 = prefetchNode(treeA, a->children[0]);
                if (bIsLeaf) {
                    const Node *a1 = prefetchNode(treeA, a->children[1]);
                    stack[numPairs].set(a0, b);
                    numPairs++;
                    a = a1;
                } else {
                    const Node *b0 = prefetchNode(treeB, b->children[0]);
                    const Node *a1 = prefetchNode(treeA, a->children[1]);
                    const Node *b1 = prefetchNode(treeB, b->children[1]);
                    stack[numPairs].set(a1, b1);
                    stack[numPairs + 1].set(a0, b1);
                    stack[numPairs + 2].set(a1, b0);
                    numPairs += 3;
                    a = a0;
                    b = b0;
                }
            }
        }
    } while (numPairs);
}

/* The pairs found are held in place and handed on when the next leaves'
 * pairs might not fit, and after the last leaves; within one call of the
 * buckets' sweep they stay under its room. derived names. */
enum {
    MAX_PAIRS_00197c60 = 3364,  /* derived name */
    FLUSH_PAIRS_00197c60 = 2522 /* derived name */
};

/* derived name: the new pairs of two trees' boxes: the pairs of
 * overlapping leaves gathered, each pair's buckets swept, a pair dropped
 * when its two boxes overlapped already in the previous step's boxes; when
 * the held pairs fill up or the last leaves are done, a pair of bodies of
 * one motion or of a body flagged 0x100 dropped, the rest through the
 * collision filter and written to the stream. */
void FUN_00197c60(const hknpWorldContextPool::Context *context, hknpCollisionFilter *filter,
                  const BroadPhaseTree00142a40 *treeA, const BroadPhaseTree00142a40 *treeB,
                  hkBlockStreamWriter *pairsOut, const hkAabb16 *previousAabbs)
{
    hkInplaceArray<LeafPair00197710, 128> leafPairs;
    FUN_00197710(treeA, treeB, leafPairs);
    const int numLeafPairs = leafPairs.getSize();
    hknpBodyIdPair pairs[MAX_PAIRS_00197c60];
    int numPairs = 0;
    const hknpWorld *world = context->world;
    for (int i = 0; i < numLeafPairs; i++) {
        const LeafPair00197710 &leaves = leafPairs[i];
        hknpBodyIdPair *const newPairs = &pairs[numPairs];
        int numNewPairs =
            FUN_00198030(&treeA->buckets[leaves.leafA->children[0]],
                         &treeB->buckets[leaves.leafB->children[0]], leaves.leafA, leaves.leafB,
                         reinterpret_cast<hkKeyPair *>(newPairs), MAX_PAIRS_00197c60);
        if (previousAabbs) {
            hknpBodyIdPair *out = newPairs;
            for (int j = 0; j < numNewPairs; j++) {
                const hknpBodyIdPair &pair = newPairs[j];
                if (previousAabbs[pair.bodyIdA.value].disjoint(previousAabbs[pair.bodyIdB.value])) {
                    *out++ = pair;
                }
            }
            numNewPairs = int(out - newPairs);
        }
        numPairs += numNewPairs;
        if (numPairs > FLUSH_PAIRS_00197c60 || i == numLeafPairs - 1) {
            hknpBodyIdPair *out = pairs;
            for (int j = 0; j < numPairs; j++) {
                const hknpBodyIdPair pair = pairs[j];
                const hknpBody &bodyA = world->bodyManager.bodies[pair.bodyIdA.value];
                const hknpBody &bodyB = world->bodyManager.bodies[pair.bodyIdB.value];
                if (bodyA.motionId != bodyB.motionId &&
                    ((bodyA.flags | bodyB.flags) & 0x100) == 0) {
                    *out++ = pair;
                }
            }
            int numKept = int(out - pairs);
            if (numKept && filter) {
                numKept = filter->FUN_001679a0(*context->world, pairs, numKept);
            }
            numPairs = 0;
            for (int j = 0; j < numKept; j++) {
                *static_cast<hknpBodyIdPair *>(pairsOut->reserve(8)) = pairs[j];
                pairsOut->advance(8);
            }
        }
    }
}

/* Whether a box overlaps a range in y and z: both packed pairs of 16-bit
 * coordinates subtracted as one word each, the signs of the four
 * differences tested at once (as 0x19f550 tests them). derived name. */
static inline bool overlapsYZ(const hkAabb16 &box, const hkAabb16 &range)
{
    const u32 boxMin = *reinterpret_cast<const u32 *>(&box.min[1]);
    const u32 boxMax = *reinterpret_cast<const u32 *>(&box.max[1]);
    const u32 rangeMin = *reinterpret_cast<const u32 *>(&range.min[1]);
    const u32 rangeMax = *reinterpret_cast<const u32 *>(&range.max[1]);
    return (((rangeMax - boxMin) | (boxMax - rangeMin)) & 0x80008000) == 0;
}

// NONMATCHING: 93 of 104 equal: the base takes the maxima's low half (`vmovq r10`) in the
// leaves' block, computed before the minima, and the minima's high half after the first skip;
// this draft blends the two (`vmovsd`) and extracts both after the skip. The base's two skip
// counters sit at -0x408 and -0x410 in a frame 16 bytes larger (here -0x404 and -0x408).
/* The overlapping pairs of two leaves' buckets (0x198030; the new pairs
 * between two trees, 0x197d79): within one bucket the sweep of its own
 * boxes; between two, each bucket's boxes inside the two leaves' common box
 * gathered, the first from where the second's start, each list closed by
 * two boxes no other reaches, then the sweep of the two lists. derived
 * name. */
int FUN_00198030(const BroadPhaseTree00142a40::Bucket *bucketA,
                 const BroadPhaseTree00142a40::Bucket *bucketB,
                 const BroadPhaseTree00142a40::Node *leafA,
                 const BroadPhaseTree00142a40::Node *leafB, hkKeyPair *pairsOut, int maxNumPairs)
{
    if (leafA != leafB) {
        /* The two leaves' common box: the larger minima, the smaller
         * maxima, taken from the two vectors in one. */
        const __m128i a = _mm_load_si128(reinterpret_cast<const __m128i *>(&leafA->aabb));
        const __m128i b = _mm_load_si128(reinterpret_cast<const __m128i *>(&leafB->aabb));
        hkAabb16 common;
        _mm_store_si128(reinterpret_cast<__m128i *>(&common),
                        _mm_castpd_si128(_mm_move_sd(_mm_castsi128_pd(_mm_min_epi16(a, b)),
                                                     _mm_castsi128_pd(_mm_max_epi16(a, b)))));
        hkAabb16 boxesA[31];
        const hkAabb16 *boxA = bucketA->entries;
        while (boxA->max[0] < bucketB->entries[0].min[0]) {
            boxA++;
        }
        hkAabb16 *endA = boxesA;
        while (boxA->min[0] <= common.max[0]) {
            if (overlapsYZ(*boxA, common)) {
                *endA++ = *boxA;
            }
            boxA++;
        }
        endA[0].min[0] = 0xffff;
        endA[0].max[0] = 0;
        endA[1].min[0] = 0xffff;
        const int numBoxesA = int(endA - boxesA);

        hkAabb16 boxesB[31];
        const hkAabb16 *boxB = bucketB->entries;
        while (boxB->max[0] < common.min[0]) {
            boxB++;
        }
        hkAabb16 *endB = boxesB;
        while (boxB->min[0] <= common.max[0]) {
            if (overlapsYZ(*boxB, common)) {
                *endB++ = *boxB;
            }
            boxB++;
        }
        endB[0].min[0] = 0xffff;
        endB[1].min[0] = 0xffff;
        const int numBoxesB = int(endB - boxesB);

        int numPairsSkipped = 0;
        return FUN_0019f310(boxesA, numBoxesA, boxesB, numBoxesB, pairsOut, maxNumPairs,
                            numPairsSkipped);
    }
    int numPairsSkipped = 0;
    return FUN_0019f550(bucketA->entries, bucketA->numEntries, pairsOut, maxNumPairs,
                        numPairsSkipped);
}

/* The squared distance from a node's box's centre (each axis's halves
 * summed, as the entries' centres are) to a point. derived name. */
static inline u32 centreDistanceSquared(const BroadPhaseTree00142a40::Node &node,
                                        const u32 (&point)[3])
{
    u32 centre2[3];
    for (int i = 0; i < 3; i++) {
        centre2[i] = (node.aabb.max[i] >> 1) + (node.aabb.min[i] >> 1);
    }
    u32 distance = 0;
    for (int i = 0; i < 3; i++) {
        const u32 delta = centre2[i] - point[i];
        distance += delta * delta;
    }
    return distance;
}

/* The leaf whose centre is nearest a point, from a walk of the tree on a
 * stack of 128 in place: an inner node's children pushed while nearer than
 * the nearest leaf so far, the farther first; none for no node. derived
 * name. */
int FUN_001981e0(BroadPhaseTree00142a40::Node *node, BroadPhaseTree00142a40 *tree,
                 const u32 (&centre2)[3], u32 maxDistance)
{
    int nearest = BroadPhaseTree00142a40::Node::NO_CHILD;
    if (node) {
        hkInplaceArray<int, 128> stack;
        stack.pushBack(tree->root);
        while (stack.getSize()) {
            const int index = stack[stack.getSize() - 1];
            stack.popBack();
            const BroadPhaseTree00142a40::Node &current = tree->nodes.elements[index];
            if (current.children[1] == BroadPhaseTree00142a40::Node::NO_CHILD) {
                const u32 distance = centreDistanceSquared(current, centre2);
                if (distance < maxDistance) {
                    maxDistance = distance;
                    nearest = index;
                }
            } else {
                const u32 distance0 =
                    centreDistanceSquared(tree->nodes.elements[current.children[0]], centre2);
                const u32 distance1 =
                    centreDistanceSquared(tree->nodes.elements[current.children[1]], centre2);
                if (distance0 < distance1) {
                    if (distance1 < maxDistance) {
                        stack.pushBack(current.getChild(1));
                    }
                    if (distance0 < maxDistance) {
                        stack.pushBack(current.getChild(0));
                    }
                } else {
                    if (distance1 < maxDistance) {
                        stack.pushBack(current.getChild(0));
                    }
                    if (distance0 < maxDistance) {
                        stack.pushBack(current.getChild(1));
                    }
                }
            }
        }
    }
    return nearest;
}

/* derived name: the subtree under a node walked from an inplace stack of
 * 128, each leaf onto the leaves' list and each inner node, after its two
 * children are pushed, onto the inner nodes' list, a list left out when
 * none is given. */
void FUN_001985d0(int nodeIndex, const BroadPhaseTree00142a40 *tree, hkArray<int> *innerNodesOut,
                  hkArray<int> *leavesOut)
{
    if (nodeIndex != BroadPhaseTree00142a40::Node::NO_CHILD) {
        hkInplaceArray<int, 128> stack;
        stack.pushBack(nodeIndex);
        while (stack.getSize()) {
            const int index = stack[stack.getSize() - 1];
            stack.popBack();
            const BroadPhaseTree00142a40::Node &node = tree->nodes.elements[index];
            if (node.children[1] == BroadPhaseTree00142a40::Node::NO_CHILD) {
                if (leavesOut) {
                    leavesOut->pushBack(index);
                }
            } else {
                stack.pushBack(node.getChild(0));
                stack.pushBack(node.getChild(1));
                if (innerNodesOut) {
                    innerNodesOut->pushBack(index);
                }
            }
        }
    }
}
