/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hkMultipleVertexBuffer::FUN_00025e70(LockedVertices *lockedVertices)
{
    if (!isLocked) {
        return;
    }
    if (lockedBuffer.pntr) {
        const int numLockedVertices = lockedBuffer.pntr->unknownVirtual8();
        const int numLockedElements = lockedElements.getSize();
        for (int i = 0; i < numLockedElements; i++) {
            const LockedElement &element = lockedElements[i];
            if ((element.lockFlags & hkVertexFormat::FLAG_WRITE) && element.emulatedIndex >= 0) {
                LockedVertices::Buffer emulated;
                static_cast<hkMemoryMeshVertexBuffer *>(lockedBuffer.pntr)
                    ->FUN_00027ae0(element.emulatedIndex, emulated);
                const LockedVertices &locked =
                    *vertexBufferInfos[element.vertexBufferIndex].lockedVertices;
                hkMeshVertexBufferUtil::FUN_000ab8d0(
                    emulated, locked.buffers[element.lockedBufferIndex], numLockedVertices);
            }
        }
        lockedBuffer = HK_NULL;
    }
    const int numVertexBuffers = vertexBufferInfos.getSize();
    for (int i = 0; i < numVertexBuffers; i++) {
        VertexBufferInfo &info = vertexBufferInfos[i];
        if (info.isLocked) {
            info.vertexBuffer.pntr->unknownVirtual15(info.lockedVertices);
            info.isLocked = false;
        }
        if (info.lockedVertices) {
            D_16dc070->temp58->blockFree(info.lockedVertices, sizeof(LockedVertices));
            info.lockedVertices = HK_NULL;
        }
    }
    if (writeLock) {
        updateCount++;
        if (updateCount == 0) {
            updateCount++;
        }
    }
    isLocked = false;
}
