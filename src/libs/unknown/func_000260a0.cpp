/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 11 of hkMeshVertexBuffer's vtable, kept by
 * hkMultipleVertexBuffer and hkMemoryMeshVertexBuffer, reads an element's values as floats through the utility. */
hkResult hkMeshVertexBuffer::FUN_000260a0(const LockedVertices &lockedVertices, int elementIndex,
                                          float *values) /* derived name */
{
    return hkMeshVertexBufferUtil::FUN_000aaaf0(lockedVertices, elementIndex, values);
}
