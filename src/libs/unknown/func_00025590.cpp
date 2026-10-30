/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hkMeshVertexBuffer *hkMultipleVertexBuffer::FUN_00025590()
{
    if (isSharable) {
        addReference();
        return this;
    }
    hkMultipleVertexBuffer *buffer = new hkMultipleVertexBuffer(*this);
    buffer->isSharable = true;
    for (int i = 0; i < buffer->vertexBufferInfos.getSize(); i++) {
        if (!buffer->vertexBufferInfos[i].vertexBuffer->FUN_00024bd0()) {
            buffer->isSharable = false;
            break;
        }
    }
    buffer->constructionComplete = true;
    return buffer;
}
