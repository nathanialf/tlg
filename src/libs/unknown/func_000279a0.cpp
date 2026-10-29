/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

int hkMemoryMeshVertexBuffer::FUN_000279a0(const hkMeshVertexBuffer::LockInput &input,
                                           hkMeshVertexBuffer::LockedVertices &lockedVerticesOut)
{
    if (locked) {
        return 0;
    }
    const int startVertex = input.startVertex;
    int numLockedVertices = input.numVertices;
    if (numLockedVertices < 0) {
        numLockedVertices = numVertices - startVertex;
    }
    u8 *vertices = memory.data + startVertex * vertexStride;
    lockedVerticesOut.isInterleaved = true;
    lockedVerticesOut.numVertices = numLockedVertices;
    const int numElements = format.numElements;
    lockedVerticesOut.numBuffers = numElements;
    for (int i = 0; i < numElements; i++) {
        hkMeshVertexBuffer::LockedVertices::Buffer &buffer = lockedVerticesOut.buffers[i];
        buffer.start = vertices + elementOffsets[i];
        buffer.stride = vertexStride;
        buffer.element = format.elements[i];
    }
    locked = true;
    return 1;
}
