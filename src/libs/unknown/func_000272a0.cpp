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
