/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

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
