/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Unsigned 32-bit lanes to floats: the high halves times 65536 plus the low
 * halves, each half converted as a signed value. derived name. */
static inline Vec4 convertUint32ToFloat(__m128i values) /* derived name */
{
    const Vec4 high = _mm_cvtepi32_ps(_mm_srli_epi32(values, 16));
    const Vec4 low = _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(values, 16), 16));
    return _mm_add_ps(_mm_mul_ps(high, _mm_set1_ps(65536.0f)), low);
}

void hknpHeightFieldShape::FUN_0012b670(int level, int x, int z, Vec4 *minOut, Vec4 *maxOut) const
{
    const hknpMinMaxQuadTree::MinMaxLevel &minMaxLevel =
        minMaxTree.coarseTreeData[level - minMaxTreeCoarseness];
    if (x < minMaxLevel.xRes && z < minMaxLevel.zRes) {
        const __m128i packed = _mm_loadu_si128(reinterpret_cast<const __m128i *>(
            &minMaxLevel.minMaxData[(x * minMaxLevel.zRes + z) * 4]));
        const __m128i zero = _mm_setzero_si128();
        const Vec4 offset = minMaxTree.offset;
        const Vec4 multiplier = _mm_set1_ps(minMaxTree.multiplier);
        *minOut = _mm_add_ps(
            offset, _mm_mul_ps(multiplier, convertUint32ToFloat(_mm_unpacklo_epi16(packed, zero))));
        *maxOut = _mm_add_ps(
            offset, _mm_mul_ps(multiplier, convertUint32ToFloat(_mm_unpackhi_epi16(packed, zero))));
    }
}

// NONMATCHING: 8 of 180 by the comparer (777 against 803 bytes; 121 lines of the side by side
// differ, most of them register names): the code is the base's but greedy's assignment across
// the quad's virtual call, where the base keeps the output in r14 and spills the shape twice
// (0x12b35a, 0x12b415: two slots for one value, a split's), and this compile keeps the shape in
// r15 and spills the output; the base's frame is 0x20 bytes larger. The corners' order of
// definition changes nothing (all 24 orders compiled).
void hknpHeightFieldShape::FUN_0012b340(const u32 *keys, int numKeys,
                                        hknpShapeSlot22Output *output) const
{
    const Vec4 scale = output->scale;
    output->leafShape = this;
    const int numTriangles = hkMath::min2(numKeys, 10);
    output->convexRadius = 0.0f;
    output->scale = D_14b2060[3];
    output->flags = (output->flags & ~0x18) | 0x10;

    int first = 0;
    u32 key = keys[0] >> (32 - numShapeKeyBits);
    for (;;) {
        const int x = (key >> 1) & ((1 << numBitsX) - 1);
        const int z = key >> (numBitsX + 1);
        int triangleFlip;
        u16 shapeTag;
        Vec4 heights;
        getQuadInfoAt(x, z, &heights, &shapeTag, &triangleFlip);

        const Vec4 position = convertUint32ToFloat(_mm_setr_epi32(x, 0, z, 0));
        const Vec4 corner00 =
            _mm_blend_ps(position, _mm_shuffle_ps(heights, heights, _MM_SHUFFLE(0, 0, 0, 0)), 2);
        const Vec4 corner10 =
            _mm_blend_ps(_mm_add_ps(position, D_14b2060[29]),
                         _mm_shuffle_ps(heights, heights, _MM_SHUFFLE(1, 1, 1, 1)), 2);
        const Vec4 corner01 =
            _mm_blend_ps(_mm_add_ps(position, D_14b2060[31]),
                         _mm_shuffle_ps(heights, heights, _MM_SHUFFLE(2, 2, 2, 2)), 2);
        const Vec4 corner11 =
            _mm_blend_ps(_mm_add_ps(position, D_14b2060[42]),
                         _mm_shuffle_ps(heights, heights, _MM_SHUFFLE(3, 3, 3, 3)), 2);
        const Vec4 diagonalA = triangleFlip ? corner00 : corner01;
        const Vec4 diagonalB = triangleFlip ? corner11 : corner10;

        bool firstTriangle = (key & 1) == 0;
        int i = first;
        for (;;) {
            const Vec4 vertex0 =
                _mm_mul_ps(scale, _mm_mul_ps(firstTriangle ? corner00 : corner11, intToFloatScale));
            const Vec4 vertex1 =
                _mm_mul_ps(scale, _mm_mul_ps(firstTriangle ? corner01 : corner10, intToFloatScale));
            const Vec4 vertex2 = _mm_mul_ps(
                scale, _mm_mul_ps(firstTriangle ? diagonalB : diagonalA, intToFloatScale));
            Vec4 *triangle = &output->quadVertices[i * 4];
            triangle[0] = vertex0;
            triangle[1] = vertex1;
            triangle[2] = vertex2;
            output->quadFlags[i] = 0x9c3;
            output->quadShapeTags[i] = shapeTag;
            if (i == numTriangles - 1) {
                output->value = i + 1;
                return;
            }
            const u32 nextKey = keys[i + 1] >> (32 - numShapeKeyBits);
            i++;
            firstTriangle = false;
            const bool sameQuad = (nextKey ^ key) < 2;
            key = nextKey;
            if (!sameQuad) {
                break;
            }
        }
        first = i;
    }
}
