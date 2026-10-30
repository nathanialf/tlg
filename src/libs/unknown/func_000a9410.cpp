/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* A key's bits in the filter set or cleared: of its primitive's two bits
 * (two per primitive, 128 primitives to a section's eight words), the ones
 * the primitive's type uses take the new value (none for an unused one,
 * both for a triangle or a custom primitive, for a quad the key's own
 * triangle's), the others keep theirs. */
void hknpCompressedMeshShapeTree::FUN_000a9410(hkArray<u32> &filter, u32 key, bool enabled) const
{
    const u32 sectionIndex = key >> 8;
    const u32 primitiveIndex = (key >> 1) & 0x7f;
    const Primitive &primitive =
        primitives[sections[sectionIndex].primitives.getStart() + primitiveIndex];
    u32 *const words = filter.data;
    const u32 typeBits[Primitive::NUM_TYPES] = {0, 3, 1u << (key & 1), 3};
    u32 &word = words[(sectionIndex << 3) | (primitiveIndex >> 4)];
    const u32 shift = (primitiveIndex << 1) & 31;
    const u32 bits = (word >> shift) & 3;
    const u32 mask = typeBits[primitive.getType()];
    const u32 newBits = (bits & ~mask) | (u32(enabled) * 3 & mask);
    word = (word & ~(3u << shift)) | (newBits << shift);
}
