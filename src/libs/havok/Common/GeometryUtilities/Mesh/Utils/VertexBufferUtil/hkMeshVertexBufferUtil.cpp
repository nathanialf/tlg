/* src/libs/havok/Common/GeometryUtilities/Mesh/Utils/VertexBufferUtil/hkMeshVertexBufferUtil.cpp:
 * the file whose path FUN_000ab8d0 loads (config/homes.base.txt); 0xab8d0 has no source yet.
 * The functions in the base's address order, one unit: the compile's unswitch budget is spent
 * by the element conversions before 0xac810 (docs/DECISIONS.md D42). */
#include <smmintrin.h>

#include "tlg_hk_reflect.h"

/* derived name: an element's values as floats for every locked vertex, from
 * the element's buffer description. */
hkResult
hkMeshVertexBufferUtil::FUN_000aaaf0(const hkMeshVertexBuffer::LockedVertices &lockedVertices,
                                     int elementIndex, float *values)
{
    return FUN_000aab10(lockedVertices.buffers[elementIndex], values, lockedVertices.numVertices);
}

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

/* numBytes of each of count items copied from one stride to another: one
 * memcpy when both strides are the item's size, else item by item, in
 * words for items of one to four words. The walk stops at count source
 * strides from the start. */
void FUN_000aacb0(const void *src, int srcStride, void *dst, int dstStride, int numBytes, int count)
{
    if (numBytes == 0) {
        return;
    }
    if (srcStride == dstStride && srcStride == numBytes) {
        FUN_00017e70(dst, src, numBytes * count);
        return;
    }
    const char *in = static_cast<const char *>(src);
    const char *end = in + srcStride * count;
    char *out = static_cast<char *>(dst);
    if ((numBytes & 3) == 0) {
        switch (numBytes >> 2) {
        case 1:
            for (; in != end; in += srcStride, out += dstStride) {
                const u32 *from = reinterpret_cast<const u32 *>(in);
                u32 *to = reinterpret_cast<u32 *>(out);
                to[0] = from[0];
            }
            return;
        case 2:
            for (; in != end; in += srcStride, out += dstStride) {
                const u32 *from = reinterpret_cast<const u32 *>(in);
                u32 *to = reinterpret_cast<u32 *>(out);
                to[0] = from[0];
                to[1] = from[1];
            }
            return;
        case 3:
            for (; in != end; in += srcStride, out += dstStride) {
                const u32 *from = reinterpret_cast<const u32 *>(in);
                u32 *to = reinterpret_cast<u32 *>(out);
                to[0] = from[0];
                to[1] = from[1];
                to[2] = from[2];
            }
            return;
        case 4:
            for (; in != end; in += srcStride, out += dstStride) {
                const u32 *from = reinterpret_cast<const u32 *>(in);
                u32 *to = reinterpret_cast<u32 *>(out);
                to[0] = from[0];
                to[1] = from[1];
                to[2] = from[2];
                to[3] = from[3];
            }
            return;
        }
    }
    for (; in != end; in += srcStride, out += dstStride) {
        FUN_00017e70(out, in, numBytes);
    }
}

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

/* numBytes of each of count items zeroed: one memset when the items are
 * packed, else item by item, in words for items of one to four words. The
 * walk stops at numBytes * count bytes from the start, as the base does,
 * not at count strides. */
void FUN_000aafd0(void *dst, int stride, int numBytes, int count)
{
    if (numBytes == 0) {
        return;
    }
    const int totalBytes = numBytes * count;
    if (stride == numBytes) {
        FUN_00018160(dst, 0, totalBytes);
        return;
    }
    char *start = static_cast<char *>(dst);
    char *end = start + totalBytes;
    if ((numBytes & 3) == 0) {
        switch (numBytes >> 2) {
        case 1:
            for (char *p = start; p != end; p += stride) {
                u32 *words = reinterpret_cast<u32 *>(p);
                words[0] = 0;
            }
            return;
        case 2:
            for (char *p = start; p != end; p += stride) {
                u32 *words = reinterpret_cast<u32 *>(p);
                words[0] = 0;
                words[1] = 0;
            }
            return;
        case 3:
            for (char *p = start; p != end; p += stride) {
                u32 *words = reinterpret_cast<u32 *>(p);
                words[0] = 0;
                words[1] = 0;
                words[2] = 0;
            }
            return;
        case 4:
            for (char *p = start; p != end; p += stride) {
                u32 *words = reinterpret_cast<u32 *>(p);
                words[0] = 0;
                words[1] = 0;
                words[2] = 0;
                words[3] = 0;
            }
            return;
        }
    }
    for (char *p = start; p != end; p += stride) {
        FUN_00018160(p, 0, numBytes);
    }
}

// NONMATCHING: equal under D42's compiler; claimed when the patch lands. The value count's test
// leaves the vertex loop for INT8, UINT8 and INT16 only: the non-trivial unswitch of
// docs/DECISIONS.md D42, its compile-wide budget spent by the first three loops; the gate's
// compiler keeps it in all seven (908 bytes as the base, 19 of 243).

/* derived name: an element's values as ints for every locked vertex, its
 * value count a vertex: widened from the integer types, unpacked from the
 * packed bytes four a vertex, truncated from floats; a failure for half
 * floats and the other types. */
hkResult
hkMeshVertexBufferUtil::FUN_000ab150(const hkMeshVertexBuffer::LockedVertices &lockedVertices,
                                     int elementIndex, int *values)
{
    const hkMeshVertexBuffer::LockedVertices::Buffer &buffer = lockedVertices.buffers[elementIndex];
    const int numVertices = lockedVertices.numVertices;
    const int numValues = buffer.element.numValues;
    const char *src = static_cast<const char *>(buffer.start);
    const int stride = buffer.stride;
    switch (buffer.element.dataType) {
    case hkVertexFormat::TYPE_INT8:
        for (int i = 0; i < numVertices; i++) {
            const s8 *v = reinterpret_cast<const s8 *>(src);
            for (int j = 0; j < numValues; j++) {
                *values++ = v[j];
            }
            src += stride;
        }
        return HK_SUCCESS;
    case hkVertexFormat::TYPE_UINT8:
        for (int i = 0; i < numVertices; i++) {
            const u8 *v = reinterpret_cast<const u8 *>(src);
            for (int j = 0; j < numValues; j++) {
                *values++ = v[j];
            }
            src += stride;
        }
        return HK_SUCCESS;
    case hkVertexFormat::TYPE_INT16:
        for (int i = 0; i < numVertices; i++) {
            const s16 *v = reinterpret_cast<const s16 *>(src);
            for (int j = 0; j < numValues; j++) {
                *values++ = v[j];
            }
            src += stride;
        }
        return HK_SUCCESS;
    case hkVertexFormat::TYPE_UINT16:
        for (int i = 0; i < numVertices; i++) {
            const u16 *v = reinterpret_cast<const u16 *>(src);
            for (int j = 0; j < numValues; j++) {
                *values++ = v[j];
            }
            src += stride;
        }
        return HK_SUCCESS;
    case hkVertexFormat::TYPE_INT32:
        for (int i = 0; i < numVertices; i++) {
            const s32 *v = reinterpret_cast<const s32 *>(src);
            for (int j = 0; j < numValues; j++) {
                *values++ = v[j];
            }
            src += stride;
        }
        return HK_SUCCESS;
    case hkVertexFormat::TYPE_UINT32:
        for (int i = 0; i < numVertices; i++) {
            const u32 *v = reinterpret_cast<const u32 *>(src);
            for (int j = 0; j < numValues; j++) {
                *values++ = int(v[j]);
            }
            src += stride;
        }
        return HK_SUCCESS;
    case hkVertexFormat::TYPE_UINT8_DWORD:
        for (int i = 0; i < numVertices; i++) {
            const u32 v = *reinterpret_cast<const u32 *>(src);
            values[0] = v & 0xff;
            values[1] = (v >> 8) & 0xff;
            values[2] = (v >> 16) & 0xff;
            values[3] = v >> 24;
            values += 4;
            src += stride;
        }
        return HK_SUCCESS;
    case hkVertexFormat::TYPE_ARGB32:
        for (int i = 0; i < numVertices; i++) {
            const u8 *v = reinterpret_cast<const u8 *>(src);
            values[0] = v[0];
            values[1] = v[1];
            values[2] = v[2];
            values[3] = v[3];
            values += 4;
            src += stride;
        }
        return HK_SUCCESS;
    case hkVertexFormat::TYPE_FLOAT32:
        for (int i = 0; i < numVertices; i++) {
            const float *v = reinterpret_cast<const float *>(src);
            for (int j = 0; j < numValues; j++) {
                *values++ = int(v[j]);
            }
            src += stride;
        }
        return HK_SUCCESS;
    default:
        return HK_FAILURE;
    }
}

/* derived name: an element set from ints for every locked vertex, its value count a vertex:
 * narrowed to the integer types, packed four a vertex into the packed bytes, converted to floats;
 * a failure for half floats and the other types (hkMeshVertexBuffer's slot 0x260d0 jumps here). */
// NONMATCHING: equal under D42's compiler; claimed when the patch lands. As 0xab150: the
// count's test leaves the loop for INT8 and UINT8 only, the budget then spent; the packed
// case's shifts (a loop of four, unrolled) are the base's. Under the gate's compiler 924 bytes
// as the base, 25 of 247.
hkResult
hkMeshVertexBufferUtil::FUN_000ab4f0(const hkMeshVertexBuffer::LockedVertices &lockedVertices,
                                     int elementIndex, const int *values)
{
    const hkMeshVertexBuffer::LockedVertices::Buffer &buffer = lockedVertices.buffers[elementIndex];
    const int numVertices = lockedVertices.numVertices;
    const int numValues = buffer.element.numValues;
    char *dst = static_cast<char *>(buffer.start);
    const int stride = buffer.stride;
    switch (buffer.element.dataType) {
    case hkVertexFormat::TYPE_INT8:
        for (int i = 0; i < numVertices; i++) {
            s8 *v = reinterpret_cast<s8 *>(dst);
            for (int j = 0; j < numValues; j++) {
                v[j] = s8(*values++);
            }
            dst += stride;
        }
        return HK_SUCCESS;
    case hkVertexFormat::TYPE_UINT8:
        for (int i = 0; i < numVertices; i++) {
            u8 *v = reinterpret_cast<u8 *>(dst);
            for (int j = 0; j < numValues; j++) {
                v[j] = u8(*values++);
            }
            dst += stride;
        }
        return HK_SUCCESS;
    case hkVertexFormat::TYPE_INT16:
        for (int i = 0; i < numVertices; i++) {
            s16 *v = reinterpret_cast<s16 *>(dst);
            for (int j = 0; j < numValues; j++) {
                v[j] = s16(*values++);
            }
            dst += stride;
        }
        return HK_SUCCESS;
    case hkVertexFormat::TYPE_UINT16:
        for (int i = 0; i < numVertices; i++) {
            u16 *v = reinterpret_cast<u16 *>(dst);
            for (int j = 0; j < numValues; j++) {
                v[j] = u16(*values++);
            }
            dst += stride;
        }
        return HK_SUCCESS;
    case hkVertexFormat::TYPE_INT32:
        for (int i = 0; i < numVertices; i++) {
            s32 *v = reinterpret_cast<s32 *>(dst);
            for (int j = 0; j < numValues; j++) {
                v[j] = s32(*values++);
            }
            dst += stride;
        }
        return HK_SUCCESS;
    case hkVertexFormat::TYPE_UINT32:
        for (int i = 0; i < numVertices; i++) {
            u32 *v = reinterpret_cast<u32 *>(dst);
            for (int j = 0; j < numValues; j++) {
                v[j] = u32(*values++);
            }
            dst += stride;
        }
        return HK_SUCCESS;
    case hkVertexFormat::TYPE_UINT8_DWORD:
        for (int i = 0; i < numVertices; i++) {
            u32 packed = 0;
            for (int j = 0; j < 4; j++) {
                packed = (packed << 8) | (values[j] & 0xff);
            }
            *reinterpret_cast<u32 *>(dst) = packed;
            values += 4;
            dst += stride;
        }
        return HK_SUCCESS;
    case hkVertexFormat::TYPE_ARGB32:
        for (int i = 0; i < numVertices; i++) {
            u8 *v = reinterpret_cast<u8 *>(dst);
            v[0] = u8(values[0]);
            v[1] = u8(values[1]);
            v[2] = u8(values[2]);
            v[3] = u8(values[3]);
            values += 4;
            dst += stride;
        }
        return HK_SUCCESS;
    case hkVertexFormat::TYPE_FLOAT32:
        for (int i = 0; i < numVertices; i++) {
            float *v = reinterpret_cast<float *>(dst);
            for (int j = 0; j < numValues; j++) {
                v[j] = float(*values++);
            }
            dst += stride;
        }
        return HK_SUCCESS;
    default:
        return HK_FAILURE;
    }
}

/* derived name: one to four values a vertex copied byte by byte from their
 * word, each buffer stepped by its stride; more values copied word by word
 * and then the bytes left, on the first vertex's place for every vertex (the
 * strides are not applied). */
void hkMeshVertexBufferUtil::FUN_000ac810(const hkMeshVertexBuffer::LockedVertices::Buffer &src,
                                          const hkMeshVertexBuffer::LockedVertices::Buffer &dst,
                                          int numVertices)
{
    const int numValues = src.element.numValues;
    if (numValues != dst.element.numValues) {
        return;
    }
    if ((src.element.dataType != hkVertexFormat::TYPE_UINT8_DWORD &&
         src.element.dataType != hkVertexFormat::TYPE_ARGB32) ||
        dst.element.dataType != hkVertexFormat::TYPE_UINT8) {
        return;
    }
    u8 *dstData = static_cast<u8 *>(dst.start);
    const char *srcData = static_cast<const char *>(src.start);
    const int srcStride = src.stride;
    const int dstStride = dst.stride;
    switch (numValues) {
    case 1:
        for (int i = 0; i < numVertices; i++) {
            const u32 v = *reinterpret_cast<const u32 *>(srcData);
            dstData[0] = u8(v);
            srcData += srcStride;
            dstData += dstStride;
        }
        break;
    case 2:
        for (int i = 0; i < numVertices; i++) {
            const u32 v = *reinterpret_cast<const u32 *>(srcData);
            dstData[0] = u8(v);
            dstData[1] = u8(v >> 8);
            srcData += srcStride;
            dstData += dstStride;
        }
        break;
    case 3:
        for (int i = 0; i < numVertices; i++) {
            const u32 v = *reinterpret_cast<const u32 *>(srcData);
            dstData[0] = u8(v);
            dstData[1] = u8(v >> 8);
            dstData[2] = u8(v >> 16);
            srcData += srcStride;
            dstData += dstStride;
        }
        break;
    case 4:
        for (int i = 0; i < numVertices; i++) {
            const u32 v = *reinterpret_cast<const u32 *>(srcData);
            dstData[0] = u8(v);
            dstData[1] = u8(v >> 8);
            dstData[2] = u8(v >> 16);
            dstData[3] = u8(v >> 24);
            srcData += srcStride;
            dstData += dstStride;
        }
        break;
    default: {
        const int numWords = numValues >> 2;
        const int numLeft = numValues & 3;
        for (int i = 0; i < numVertices; i++) {
            const u32 *s = reinterpret_cast<const u32 *>(srcData);
            u8 *d = dstData;
            for (int j = 0; j < numWords; j++) {
                const u32 v = *s++;
                d[0] = u8(v);
                d[1] = u8(v >> 8);
                d[2] = u8(v >> 16);
                d[3] = u8(v >> 24);
                d += 4;
            }
            switch (numLeft) {
            case 3: {
                const u32 v = *s;
                d[0] = u8(v);
                d[1] = u8(v >> 8);
                d[2] = u8(v >> 16);
                break;
            }
            case 2: {
                const u32 v = *s;
                d[0] = u8(v);
                d[1] = u8(v >> 8);
                break;
            }
            case 1:
                d[0] = u8(*s);
                break;
            }
        }
        break;
    }
    }
}
