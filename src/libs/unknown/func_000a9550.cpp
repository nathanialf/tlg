/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Whether a key is enabled in the filter: its primitive's two bits (two per
 * primitive, 128 primitives to a section's eight words) tested with the
 * bits the primitive's type uses, none for an unused one, both for a
 * triangle or a custom primitive, and for a quad the key's own triangle's
 * (the key's low bit). */
bool hknpCompressedMeshShapeTree::FUN_000a9550(const hkArray<u32> &filter, u32 key) const
{
    const u32 sectionIndex = key >> 8;
    const u32 primitiveIndex = (key >> 1) & 0x7f;
    const Primitive &primitive =
        primitives[sections[sectionIndex].primitives.getStart() + primitiveIndex];
    const u32 *const words = filter.data;
    const u32 typeBits[Primitive::NUM_TYPES] = {0, 3, 1u << (key & 1), 3};
    const u32 word = words[(sectionIndex << 3) | (primitiveIndex >> 4)];
    const u32 bits = (word >> ((primitiveIndex << 1) & 31)) & 3;
    return (bits & typeBits[primitive.getType()]) != 0;
}
