/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* A layer's tree rebuilt over the bodies its leaves hold: the leaves
 * gathered, each leaf bucket's bodies listed, the tree rebuilt over them
 * (0x13b940). A helper of this file, inlined into its one caller: the
 * inliner marks the arrays' lifetimes (InlineFunction's lifetime markers
 * for a callee's static allocas), so dead store elimination drops
 * hkArray's reset of the leaves' data and capacity at the marker's end
 * (none after the free at 0x14334d), which the 32-byte array of the loop's
 * own scope would keep (no marker, clang 3.3 CGDecl.cpp:792-805). derived
 * name. */
static void rebuildTree(BroadPhaseTree00142a40 *tree, hknpBody *bodies) /* derived name */
{
    LocalArray<int> leaves(tree->numLeaves);
    FUN_00198830(tree->root, tree, leaves);
    LocalArray<u32> bodyIndices(leaves.getSize() * tree->maxLeafEntries);
    int numBodies = 0;
    for (int i = 0; i < leaves.getSize(); i++) {
        const int bucketIndex = tree->nodes.elements[leaves[i]].children[0];
        for (int j = 0; j < tree->buckets[bucketIndex].numEntries; j++) {
            bodyIndices.data[numBodies++] = tree->buckets[bucketIndex].entries[j].getKey();
        }
    }
    tree->FUN_0013b940(bodies, bodyIndices.data, numBodies);
}

// NONMATCHING: 187 of 189, the size equal (725 bytes): list-ilp's place of a null
// data (the phi's constant, `xor r12d, r12d` at 0x143131) after the store of the initial
// capacity (0x14312e), where ours schedules it before; nothing else differs. Round 105A.
void BroadPhaseLayers00142a40::FUN_001430b0(hknpBody *bodies)
{
    for (u8 layer = 0; layer < numLayers; layer++) {
        if (!flag50[layer]) {
            rebuildTree(trees[layer], bodies);
        }
    }
}
