/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_hk_reflect.h"

/* derived name: an element's values set from floats, four a vertex, for
 * every locked vertex: copied for floats (the values past the fourth
 * zeroed), packed into bytes scaled by 255 and clamped for colours; a
 * failure for the other types. */
hkResult
hkMeshVertexBufferUtil::FUN_000aae70(const hkMeshVertexBuffer::LockedVertices &lockedVertices,
                                     int elementIndex, const float *values)
{
    const hkMeshVertexBuffer::LockedVertices::Buffer &buffer = lockedVertices.buffers[elementIndex];
    const int numVertices = lockedVertices.numVertices;
    switch (buffer.element.dataType) {
    case hkVertexFormat::TYPE_ARGB32: {
        const Vec4 scale = D_14b2060[13];
        const Vec4 zero = _mm_setzero_ps();
        const int stride = buffer.stride;
        char *dst = static_cast<char *>(buffer.start);
        for (int i = 0; i < numVertices; i++) {
            const Vec4 v = _mm_castsi128_ps(
                _mm_lddqu_si128(reinterpret_cast<const __m128i *>(values + i * 4)));
            const Vec4 scaled = _mm_mul_ps(scale, v);
            const Vec4 clamped =
                _mm_max_ps(zero, _mm_blendv_ps(scale, scaled, _mm_cmplt_ps(scaled, scale)));
            const __m128i converted =
                _mm_castps_si128(_mm_xor_ps(_mm_castsi128_ps(_mm_cvttps_epi32(clamped)),
                                            _mm_cmple_ps(_mm_set1_ps(2147483648.0f), clamped)));
            *reinterpret_cast<u32 *>(dst) = u32(_mm_cvtsi128_si32(converted)) |
                                            (u32(_mm_extract_epi32(converted, 1)) << 8) |
                                            (u32(_mm_extract_epi32(converted, 2)) << 16) |
                                            (u32(_mm_extract_epi32(converted, 3)) << 24);
            dst += stride;
        }
        return HK_SUCCESS;
    }
    case hkVertexFormat::TYPE_FLOAT32: {
        const int numValues = buffer.element.numValues;
        const int numBytes = numValues * int(sizeof(float));
        if (numValues > 4) {
            FUN_000aafd0(static_cast<char *>(buffer.start) + 16, buffer.stride, numBytes - 16,
                         numVertices);
        }
        FUN_000aacb0(values, 16, buffer.start, buffer.stride, numBytes, numVertices);
        return HK_SUCCESS;
    }
    default:
        return HK_FAILURE;
    }
}
