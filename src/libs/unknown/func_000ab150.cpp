/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

// NONMATCHING: 908 bytes as the base, 30 lines apart side by side: the base tests the
// value count once before the vertex loop for INT8, UINT8 and INT16 (`test
// dil; je` after the count's guard, the inner loop then a bare do-while, the
// advance `shl r9, 2; add rdx, r9`), the shape of LoopUnswitch's trivial
// unswitch, and keeps the test inside the loop for UINT16, INT32, UINT32 and
// FLOAT32 as this compile does for all seven. Trivial needs the header's
// false edge to reach the exit without passing the header again
// (LoopUnswitch.cpp:507-536, isTrivialLoopExitBlockHelper), which the rotated
// nest here never offers: the source shape of the first three is the lead.
// The start's load sits one place earlier here (instruction 7).

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
    const int stride = buffer.stride;
    const char *src = static_cast<const char *>(buffer.start);
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
