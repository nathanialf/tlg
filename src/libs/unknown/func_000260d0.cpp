/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 14 of hkMeshVertexBuffer's vtable, kept by
 * hkMultipleVertexBuffer and hkMemoryMeshVertexBuffer, writes an element's values from ints through the utility. */
hkResult hkMeshVertexBuffer::FUN_000260d0(const LockedVertices &lockedVertices, int elementIndex,
                                          const int *values) /* derived name */
{
    return hkMeshVertexBufferUtil::FUN_000ab4f0(lockedVertices, elementIndex, values);
}
