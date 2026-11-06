/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* A value's bytes reversed in place, two or four of them. derived names. */
static inline void swapBytes2(u8 *data)
{
    const u8 t = data[0];
    data[0] = data[1];
    data[1] = t;
}

static inline void swapBytes4(u8 *data)
{
    u8 t = data[0];
    data[0] = data[3];
    data[3] = t;
    t = data[1];
    data[1] = data[2];
    data[2] = t;
}

/* Each vertex's elements, value by value, in the other byte order. The
 * vector case comes first in the switch: its end pointer is then made by a
 * lea beside the swaps (0x275dd), as two-address lowering cannot sink it
 * (cookbook 420). */
void hkMemoryMeshVertexBuffer::FUN_00027520()
{
    u8 *vertex = memory.data;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < format.numElements; j++) {
            const hkVertexFormat::Element &element = format.elements[j];
            u8 *data = hkAddByteOffset(vertex, elementOffsets[j]);
            for (int k = 0; k < element.numValues; k++) {
                switch (element.dataType) {
                case hkVertexFormat::TYPE_VECTOR4:
                    swapBytes4(data);
                    swapBytes4(data + 4);
                    swapBytes4(data + 8);
                    swapBytes4(data + 12);
                    data += 16;
                    break;
                case hkVertexFormat::TYPE_INT16:
                case hkVertexFormat::TYPE_UINT16:
                    swapBytes2(data);
                    data += 2;
                    break;
                case hkVertexFormat::TYPE_INT32:
                case hkVertexFormat::TYPE_UINT32:
                    swapBytes4(data);
                    data += 4;
                    break;
                case hkVertexFormat::TYPE_UINT8_DWORD:
                case hkVertexFormat::TYPE_ARGB32:
                    swapBytes4(data);
                    data += 4;
                    break;
                case hkVertexFormat::TYPE_FLOAT16:
                    swapBytes2(data);
                    data += 2;
                    break;
                case hkVertexFormat::TYPE_FLOAT32:
                    swapBytes4(data);
                    data += 4;
                    break;
                default:
                    break;
                }
            }
        }
        vertex += vertexStride;
    }
}
