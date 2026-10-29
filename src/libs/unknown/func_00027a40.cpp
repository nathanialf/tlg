/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

int hkMemoryMeshVertexBuffer::FUN_00027a40(const hkMeshVertexBuffer::LockInput &input,
                                           const hkMeshVertexBuffer::PartialLockInput &partialInput,
                                           hkMeshVertexBuffer::LockedVertices &lockedVerticesOut)
{
    if (locked) {
        return 0;
    }
    int numLockedVertices = input.numVertices;
    if (numLockedVertices < 0) {
        numLockedVertices = numVertices - input.startVertex;
    }
    u8 *vertices = memory.data + input.startVertex * vertexStride;
    lockedVerticesOut.isInterleaved = true;
    lockedVerticesOut.numVertices = numLockedVertices;
    const int numElements = partialInput.numLockElements;
    lockedVerticesOut.numBuffers = numElements;
    for (int i = 0; i < numElements; i++) {
        const int elementIndex = partialInput.elementIndices[i];
        hkMeshVertexBuffer::LockedVertices::Buffer &buffer = lockedVerticesOut.buffers[i];
        buffer.start = vertices + elementOffsets[elementIndex];
        buffer.stride = vertexStride;
        buffer.element = format.elements[elementIndex];
    }
    locked = true;
    return 1;
}
