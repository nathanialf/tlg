/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: 63 of 76, same size, every frame offset the base's. Two
// residuals (docs/NOTES.md, Round 67A): the stack guard's GOT address is
// CSE'd from the entry into the exit block by MachineCSE and takes r12
// before the tree, key and child pointers are allocated, which permutes
// rbx/r12/r13 (with -disable-machine-cse as a diagnostic the registers are
// the base's, 73 of 76); and the zero vector of the domain's copy is
// scheduled before the key's `and` (the zero store's chain is a token factor
// of the three pending loads, which list-ilp takes before the zero).
/* Slot 32: an instance's AABB, decoded from the tree's root down to the
 * instance's leaf, each node's box inside its parent's. */
void hknpStaticCompoundShape::unknownVirtual32(hknpShapeInstanceId instanceId,
                                               hkAabb &aabbOut) const
{
    const int key = instances.elements[instanceId.value].getIndex();
    const hknpStaticCompoundShapeTree &tree = boundingVolumeData->aabbTree;
    hkAabb aabb = tree.getDomain();
    int i = 0;
    while (i != key) {
        const u8 *node = tree.nodes.data[i].unknown0;
        int children[2];
        children[0] = i + 1;
        children[1] = i + 2 * (((node[3] & 0x7f) << 16) | *reinterpret_cast<const u16 *>(node + 4));
        i = children[children[1] <= key];
        const u8 *codes = tree.nodes.data[i].unknown0;
        hkAabb child = hkAabb();
        FUN_000a9f10(aabb, codes, child);
        aabb.min = child.min;
        aabb.max = child.max;
    }
    aabbOut.min = aabb.min;
    aabbOut.max = aabb.max;
}
