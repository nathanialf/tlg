/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

int TreeWalk0013b790::FUN_0013b790(BroadPhaseTree00142a40::Node *node, int &numItems,
                                   int firstLeaf) /* derived name */
{
    const int secondChild = node->children[1]; /* NO_CHILD for a leaf */
    Item &item = items[numItems];
    item.firstLeaf = firstLeaf;
    if (secondChild == BroadPhaseTree00142a40::Node::NO_CHILD) {
        item.numLeft = 0;
        item.numRight = 0;
        numItems++;
        leaves[firstLeaf] = node;
        return firstLeaf + 1;
    }
    item.leftItem = ++numItems;
    const int afterLeft =
        FUN_0013b790(&tree->nodes.elements[node->children[0]], numItems, firstLeaf);
    item.numLeft = afterLeft - firstLeaf;
    item.rightItem = numItems;
    const int afterRight =
        FUN_0013b790(&tree->nodes.elements[node->children[1]], numItems, afterLeft);
    item.numRight = afterRight - afterLeft;
    return afterRight;
}
