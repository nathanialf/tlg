/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: 37 of 76: three residuals. The base zeroes 16 bytes of the
// parent box before the domain's copy (`vmovaps [rsp+0x50], xmm0` of zero), and
// keeps the nodes' pointer from the loop's head for the child's codes where this
// compile reloads it after the child's zeroing; and the base has no `vzeroupper`
// before the decode's call after the child's 32-byte `ymm` zero store, which
// 3.3's VZeroUpperInserter adds (the library region holds no `vzeroupper` at
// all against 604 `vmovaps ymm` and 356 `vxorps ymm`: a region question,
// docs/NOTES.md, Round 65A).
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
