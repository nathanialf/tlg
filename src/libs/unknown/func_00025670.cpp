/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 9 of hkMultipleVertexBuffer's vtable, the lock of
 * every element: each element locked from its vertex buffer into the output
 * buffer of its own index, under the input's flags. */
int hkMultipleVertexBuffer::FUN_00025670(const LockInput &input, LockedVertices &lockedVerticesOut)
{
    if (isLocked) {
        return 0;
    }
    writeLock = (input.lockFlags & hkVertexFormat::FLAG_WRITE) != 0;
    const int numElements = vertexFormat.numElements;
    lockedElements.setSizeUnchecked(numElements);
    for (int i = 0; i < numElements; i++) {
        LockedElement &element = lockedElements[i];
        const ElementInfo &info = elementInfos[i];
        element.vertexBufferIndex = info.vertexBufferIndex;
        element.elementIndex = info.elementIndex;
        element.lockFlags = u8(input.lockFlags);
        element.outputBufferIndex = u8(i);
        element.vertexFormatIndex = u8(i);
    }
    return FUN_00025700(input, lockedVerticesOut);
}
