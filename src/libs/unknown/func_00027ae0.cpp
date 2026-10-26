/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: an element's buffer description over the vertex memory. */
void hkMemoryMeshVertexBuffer::FUN_00027ae0(int elementIndex,
                                            hkMeshVertexBuffer::LockedVertices::Buffer &buffer)
{
    buffer.start = memory.data + elementOffsets[elementIndex];
    buffer.stride = vertexStride;
    buffer.element = format.elements[elementIndex];
}
