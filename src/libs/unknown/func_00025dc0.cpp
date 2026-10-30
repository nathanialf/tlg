/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

int hkMultipleVertexBuffer::FUN_00025dc0(const LockInput &input,
                                         const PartialLockInput &partialInput,
                                         LockedVertices &lockedVerticesOut)
{
    if (isLocked) {
        return 0;
    }
    const int numElements = partialInput.numLockElements;
    lockedElements.setSizeUnchecked(numElements);
    u8 allFlags = 0;
    for (int i = 0; i < numElements; i++) {
        LockedElement &element = lockedElements[i];
        const ElementInfo &info = elementInfos[partialInput.elementIndices[i]];
        element.vertexBufferIndex = info.vertexBufferIndex;
        element.elementIndex = info.elementIndex;
        const u8 flags = partialInput.lockFlags[i];
        element.lockFlags = flags;
        element.outputBufferIndex = u8(i);
        allFlags |= flags;
        element.vertexFormatIndex = u8(partialInput.elementIndices[i]);
    }
    writeLock = (allFlags & hkVertexFormat::FLAG_WRITE) != 0;
    return FUN_00025700(input, lockedVerticesOut);
}
