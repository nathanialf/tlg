/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hkMemoryMeshVertexBuffer::hkMemoryMeshVertexBuffer(const hkVertexFormat &format, int numVertices)
{
    locked = false;
    FUN_000273c0(format);

    const int numBytes = vertexStride * numVertices;
    memory.setSize((numBytes + 15) & ~15);
    hkString::memSet16(memory.data, &D_14b2060[2], (numBytes + 15) >> 4);
    memory.setSizeUnchecked(numBytes);

    this->numVertices = numVertices;
    isBigEndian = false;
}

/* Slot 5 (0x277e0). */
// NONMATCHING: the base inlines the constructor above here; the inliner
// (debug opt, -debug-only=inline) prices it at 230 against the threshold
// of 225, one instruction too many, so it stays a call (NOTES "Round
// 75A"); the rest is the base's (198 bytes with the call).
hkMeshVertexBuffer *hkMemoryMeshVertexBuffer::FUN_00025590()
{
    if (isSharable) {
        addReference();
        return this;
    }
    hkMemoryMeshVertexBuffer *buffer = new hkMemoryMeshVertexBuffer(format, numVertices);
    const int numBytes = numVertices * vertexStride;
    hkString::memCpy16(buffer->memory.data, memory.data, (numBytes + 15) >> 4);
    buffer->memory.setSizeUnchecked(numBytes);
    return buffer;
}
