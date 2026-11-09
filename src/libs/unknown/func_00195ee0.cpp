/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

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
// NONMATCHING: 145 of 248 equal, everything to the centres' loop: the base keeps the box around
// the centres in six registers through the loop (LICM's promotion, the box stored after it),
// which needs 0x196720 defined in this file: FunctionAttrs then marks the box `nocapture` in
// it and the box no longer escapes (measured with a stand-in definition; the loop's 16-bit
// compares stay to be read, the base's are 32-bit over zero-extended values).
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
