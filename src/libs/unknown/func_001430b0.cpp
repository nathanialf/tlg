/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* NONMATCHING: 742 bytes against 725, the LocalArray question twice over:
 * (1) the leaves' array stores its local copy after its capacity in the
 * base (0x14318d), Havok's hkLocalArray order, as 0x13b940; (2) at the end
 * of each layer's pass the base's array destructor clears the size and
 * frees, with no data or capacity store after the free (0x14332a to
 * 0x14334d), where the tree's hkArray destructor (clearAndDeallocate)
 * stores both; at a function's end dead store elimination removes them,
 * in this loop it cannot (the 32-byte object gets no lifetime markers,
 * clang 3.3 CGDecl.cpp:792-805 marks only objects over 32 bytes). Left
 * besides: `this` kept in rbx in the base. NOTES Round 81A. */
void BroadPhaseLayers00142a40::FUN_001430b0(hknpBody *bodies)
{
    for (u8 layer = 0; layer < numLayers; layer++) {
        if (!flag50[layer]) {
            BroadPhaseTree00142a40 *tree = trees[layer];
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
    }
}
