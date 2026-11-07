/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

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
