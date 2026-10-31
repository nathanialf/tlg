/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

bool hknpCompressedMeshShapeTree::FUN_000a92c0(hkArray<u32> &filter) const
{
    u32 *words = filter.data;
    u32 *sectionBits = words + sections.getSize() * 8;
    for (int i = 0; i < sections.getSize(); i++) {
        const u16 leaf = sections[i].leafIndex;
        u32 used = 0;
        for (int j = 0; j < 8; j++) {
            used |= filter[i * 8 + j];
        }
        u32 &word = sectionBits[leaf >> 5];
        const u32 shift = leaf & 31;
        word = (word & ~(1u << shift)) | (u32(used != 0) << shift);
    }
    if (nodes.size == 0) {
        return false;
    }
    TreeSlot root;
    root.aabb.min = domain.min;
    root.aabb.max = domain.max;
    root.node = nodes.data;
    root.index = 0;
    return FUN_000a8f80(root, sectionBits);
}
