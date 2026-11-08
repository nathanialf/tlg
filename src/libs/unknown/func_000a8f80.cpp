/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* A child's box decoded from its code inside the parent's: each byte's high
 * nibble moves the minimum in and its low nibble the maximum, by the nibble
 * squared in 255ths of the parent's extent (given). derived name. */
static inline void decodeChildAabb(const hkAabb &parent, const Vec4 &extent, __m128i code,
                                   hkAabb &aabbOut)
{
    const __m128i zero = _mm_setzero_si128();
    const __m128i values = _mm_unpacklo_epi16(_mm_unpacklo_epi8(code, zero), zero);
    const Vec4 high = _mm_cvtepi32_ps(_mm_srli_epi32(values, 4));
    const Vec4 low = _mm_cvtepi32_ps(_mm_and_si128(values, _mm_castps_si128(D_57c87c0)));
    aabbOut.min = _mm_add_ps(parent.min, _mm_mul_ps(extent, _mm_mul_ps(high, high)));
    aabbOut.max = _mm_sub_ps(parent.max, _mm_mul_ps(extent, _mm_mul_ps(low, low)));
}

/* A node is a leaf while the top bit of its fourth byte is clear; an inner
 * node's left child follows it and its right child is twice the skip (the
 * fourth byte's low seven bits over the fifth byte) further on, each
 * child's box coded in its first three bytes. */
bool hknpCompressedMeshShapeTree::FUN_000a8f80(const TreeSlot &slot, u32 *sectionBits) const
{
    const u8 *code = slot.node->xyz;
    if (code[3] < 0x80) {
        return (sectionBits[slot.index / 32] >> (slot.index % 32)) & 1;
    }

    TreeSlot children[2];
    children[0].index = slot.index + 1;
    const int skip = ((code[3] & 0x7f) << 8) | code[4];
    children[1].index = slot.index + 2 * skip;
    children[0].node = &nodes.data[children[0].index];
    children[1].node = &nodes.data[children[1].index];
    const __m128i leftCode =
        _mm_castps_si128(_mm_load_ss(reinterpret_cast<const float *>(children[0].node->xyz)));
    const __m128i rightCode =
        _mm_castps_si128(_mm_load_ss(reinterpret_cast<const float *>(children[1].node->xyz)));
    const Vec4 extent = _mm_mul_ps(slot.aabb.getExtents(), D_14b2060[27]);
    decodeChildAabb(slot.aabb, extent, leftCode, children[0].aabb);
    decodeChildAabb(slot.aabb, extent, rightCode, children[1].aabb);

    const bool enabled =
        FUN_000a8f80(children[0], sectionBits) | FUN_000a8f80(children[1], sectionBits);
    u32 &word = sectionBits[slot.index / 32];
    word = (word & ~(1 << (slot.index % 32))) | (u32(enabled) << (slot.index % 32));
    return enabled;
}
