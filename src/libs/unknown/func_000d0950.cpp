/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: the parent box's 16-byte zero store before the domain's copy
// and the nodes' pointer kept for the child's codes both say the decoder
// (FUN_000a9f10) was known not to capture its boxes: with its definition in
// this file and not inlined, FunctionAttrs marks its parameters nocapture,
// the boxes do not escape, `hkAabb aabb = hkAabb();` is trimmed by DSE to its
// first 16 bytes (DeadStoreElimination.cpp:585, the end overwritten by the
// max's store) and GVN keeps the nodes' load across the child's zeroing.
// Measured with a throwaway noinline on an inline definition here: 63 of 76,
// only rbx/r12/r13 permuted (tree, key, child). Without the definition the
// decoder captures both boxes; with it and no barrier, the inliner takes it.
// A ruling is asked (docs/NOTES.md, Round 66A).
/* Slot 32: an instance's AABB, decoded from the tree's root down to the
 * instance's leaf, each node's box inside its parent's. */
void hknpStaticCompoundShape::unknownVirtual32(hknpShapeInstanceId instanceId,
                                               hkAabb &aabbOut) const
{
    const int key = instances.elements[instanceId.value].getIndex();
    const hknpStaticCompoundShapeTree &tree = boundingVolumeData->aabbTree;
    hkAabb aabb;
    aabb.min = tree.domain.min;
    aabb.max = tree.domain.max;
    int i = 0;
    while (i != key) {
        const u8 *node = tree.nodes.data[i].unknown0;
        int children[2];
        children[0] = i + 1;
        children[1] = i + 2 * (((node[3] & 0x7f) << 16) | *reinterpret_cast<const u16 *>(node + 4));
        i = children[children[1] <= key];
        hkAabb child = hkAabb();
        FUN_000a9f10(aabb, tree.nodes.data[i].unknown0, child);
        aabb.min = child.min;
        aabb.max = child.max;
    }
    aabbOut.min = aabb.min;
    aabbOut.max = aabb.max;
}
