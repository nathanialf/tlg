/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 13 of hkMeshVertexBuffer's vtable, kept by
 * hkMultipleVertexBuffer and hkMemoryMeshVertexBuffer, reads an element's values as ints through the utility. */
hkResult hkMeshVertexBuffer::FUN_000260c0(const LockedVertices &lockedVertices, int elementIndex,
                                          int *values) /* derived name */
{
    return hkMeshVertexBufferUtil::FUN_000ab150(lockedVertices, elementIndex, values);
}
