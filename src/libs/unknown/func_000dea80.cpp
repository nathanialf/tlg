/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* NONMATCHING: 669 bytes against 683, 84 of 164 by position, every block
 * but the loop's counter equal in form: the base computes the counter's
 * increment in the loop's first block (`lea rax, [r15 + 1]` after the
 * decode, before the leaf test) and copies it back at the latch (`mov r15,
 * rax`), its numNodes spilled at its definition (0xdeb28); here the
 * increment is in the latch (IndVarSimplify's widened increment where the
 * for statement puts it), and the data and counter registers trade places.
 * The output nodes are indexed from a pointer read before the loop: walked
 * by a pointer of their own, their stores alias the boxes' data field for
 * BasicAA (a pointer phi has no underlying object), GVN keeps the field's
 * load in the loop and the boxes' array stays in memory. */
/* The tree emptied, then, from a copy of the dynamic tree laid out from its
 * root, each node's box coded inside its parent's decoded box (each decoded
 * box kept for its children), a leaf's data or an inner node's offset to its
 * child after the codes; the domain the root's box (as 0xcf5d0 for the
 * 64-byte nodes). */
void FUN_000dea80(hkcdStaticTree::DefaultTreeStorage6 *self,
                  const hkcdDynamicTree::DefaultTree48Storage &tree)
{
    self->nodes.setSizeUnchecked(0);
    self->domain.setEmpty();
    if (tree.numLeaves) {
        hkcdDynamicTree::DefaultTree48Storage copy;
        tree.FUN_000bd460(copy);
        const int numNodes = 2 * copy.numLeaves - 1;
        hkArray<hkAabb> boxes(2 * copy.numLeaves);
        const hkcdDynamicTree::CodecRawUint &root = copy.nodes[1];
        boxes[0].min = root.aabb.min;
        boxes[0].max = root.aabb.max;
        self->nodes.setSize(numNodes);
        self->domain.min = boxes[0].min;
        self->domain.max = boxes[0].max;
        const hkcdDynamicTree::CodecRawUint *node = &copy.nodes[1];
        hkcdStaticTree::Codec3Axis6 *nodes = self->nodes.data;
        hkAabb *decoded = &boxes[1];
        for (int i = 0; i < numNodes; i++) {
            hkcdStaticTree::Codec3Axis6 &out = nodes[i];
            const u32 data = node->children[1];
            hkAabb box = hkAabb();
            box.min = node->aabb.min;
            box.max = node->aabb.max;
            const hkAabb &parentBox = boxes[int(node->parent)];
            FUN_000a9da0(parentBox, box, out.xyz);
            FUN_000a9f10(parentBox, out.xyz, *decoded);
            if (node->children[0] == 0) {
                out.hiData = u8((data >> 16) & 0x7f);
                out.loData = u16(data);
            } else {
                const u32 offset = data - u32(i + 1);
                out.hiData = u8((offset >> 17) | 0x80);
                out.loData = u16(offset >> 1);
            }
            node++;
            decoded++;
        }
    }
}
