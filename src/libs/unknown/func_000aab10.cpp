/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_hk_reflect.h"

/* derived name: an element's values as floats, four a vertex: copied for
 * floats (the lanes past the element's values zero), unpacked and scaled by
 * 1/255 for colours, a failure for the other types; blend weights whose
 * last is implied get it as one less the others' sum, not below zero. */
hkResult
hkMeshVertexBufferUtil::FUN_000aab10(const hkMeshVertexBuffer::LockedVertices::Buffer &buffer,
                                     float *values, int numVertices)
{
    switch (buffer.element.dataType) {
    case hkVertexFormat::TYPE_ARGB32: {
        const int stride = buffer.stride;
        const char *src = static_cast<const char *>(buffer.start);
        for (int i = 0; i < numVertices; i++) {
            const u32 color = *reinterpret_cast<const u32 *>(src);
            const __m128i channels = _mm_setr_epi32(color & 0xff, (color >> 8) & 0xff,
                                                    (color >> 16) & 0xff, color >> 24);
            _mm_storeu_ps(values + i * 4, _mm_mul_ps(_mm_cvtepi32_ps(channels), D_14b2060[28]));
            src += stride;
        }
        break;
    }
    case hkVertexFormat::TYPE_FLOAT32: {
        const int numValues = buffer.element.numValues;
        if (numValues < 4) {
            hkString::memSet16(values, &D_14b2060[2], numVertices);
        }
        int numBytes = numValues * int(sizeof(float));
        if (numValues > 4) {
            numBytes = 16;
        }
        FUN_000aacb0(buffer.start, buffer.stride, values, 16, numBytes, numVertices);
        break;
    }
    default:
        return HK_FAILURE;
    }

    /* The usage as stored, a byte the compare reads (0xaac14). */
    const u8 usage = buffer.element.usage.m_storage;
    if (usage == hkVertexFormat::USAGE_BLEND_WEIGHTS_LAST_IMPLIED) {
        for (int i = numVertices - 1; i >= 0; i--) {
            const Vec4 one = D_14b2060[3];
            const Vec4 zero = _mm_setzero_ps();
            float *weights = values + i * 4;
            const Vec4 w =
                _mm_movelh_ps(_mm_castpd_ps(_mm_load_sd(reinterpret_cast<const double *>(weights))),
                              _mm_load_ss(weights + 2));
            const Vec4 last = _mm_max_ps(_mm_sub_ps(one, _mm_dp_ps(w, one, 0x7f)), zero);
            _mm_storeu_ps(weights, _mm_blend_ps(w, last, 8));
        }
    }
    return HK_SUCCESS;
}
