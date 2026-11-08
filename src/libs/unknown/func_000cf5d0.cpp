/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* NONMATCHING: 715 bytes against 675 (27 of 168 by position, most of the
 * difference the loop's layout): the boxes' storage pointer stays in its
 * alloca and GVN's load PRE reloads it on the back edge, which here splits
 * the latch (the pointers' steps in a block of their own above the body,
 * the exit test in the join); the base keeps the steps, the counter's
 * decrement, the test and the reload in the join (0xcf7ee to 0xcf807).
 * The node, output and box are walked by pointers in both. */
/* The tree emptied, then, from a copy of the dynamic tree laid out from its
 * root, each node's box coded inside its parent's decoded box (each decoded
 * box kept for its children), a leaf's data or an inner node's offset to its
 * child after the codes; the domain the root's box. */
void FUN_000cf5d0(hkcdStaticTree::DefaultTreeStorage6 *self,
                  const DefaultTree64Storage00cf5d0 &tree)
{
    self->nodes.setSizeUnchecked(0);
    self->domain.setEmpty();
    if (tree.numLeaves) {
        DefaultTree64Storage00cf5d0 copy;
        tree.FUN_000bfe20(copy);
        const int numNodes = 2 * copy.numLeaves - 1;
        hkArray<hkAabb> boxes(2 * copy.numLeaves);
        boxes[0] = copy.nodes[1].aabb;
        self->nodes.setSize(numNodes);
        self->domain.min = boxes[0].min;
        self->domain.max = boxes[0].max;
        const hkcdDynamicTree::CodecRawUlong *node = &copy.nodes[1];
        hkcdStaticTree::Codec3Axis6 *out = self->nodes.data;
        hkAabb *decoded = &boxes[1];
        for (int i = 0; i < numNodes; i++) {
            const hkUlong data = node->children[1];
            hkAabb box = hkAabb();
            box.min = node->aabb.min;
            box.max = node->aabb.max;
            const hkAabb &parentBox = boxes[int(node->parent)];
            FUN_000a9da0(parentBox, box, out->xyz);
            FUN_000a9f10(parentBox, out->xyz, *decoded);
            if (int(node->children[0]) == 0) {
                out->hiData = u8((u32(data) >> 16) & 0x7f);
                out->loData = u16(data);
            } else {
                const u32 offset = u32(data) - u32(i + 1);
                out->hiData = u8((offset >> 17) | 0x80);
                out->loData = u16(offset >> 1);
            }
            node++;
            out++;
            decoded++;
        }
    }
}
