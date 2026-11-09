/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: an element set from ints for every locked vertex, its value count a vertex:
 * narrowed to the integer types, packed four a vertex into the packed bytes, converted to floats;
 * a failure for half floats and the other types (hkMeshVertexBuffer's slot 0x260d0 jumps here). */
// NONMATCHING: 0xab150's class, 924 bytes as the base, 23 lines apart side by side: the base
// tests the value count once before the vertex loop for INT8 and UINT8 only (`test dil; je` to
// the return, the inner loop a bare do-while, the advance `shl r9, 2; add rdx, r9`) and keeps it
// in the loop for the five other counted cases, as this compile does for all seven. The packed
// case's shifts (a loop of four, unrolled) are the base's. The start's load sits two places
// earlier here.
hkResult
hkMeshVertexBufferUtil::FUN_000ab4f0(const hkMeshVertexBuffer::LockedVertices &lockedVertices,
                                     int elementIndex, const int *values)
{
    const hkMeshVertexBuffer::LockedVertices::Buffer &buffer = lockedVertices.buffers[elementIndex];
    const int numVertices = lockedVertices.numVertices;
    const int numValues = buffer.element.numValues;
    const int stride = buffer.stride;
    char *dst = static_cast<char *>(buffer.start);
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
