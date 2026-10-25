/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 12 of hkMeshVertexBuffer's vtable, kept by
 * hkMultipleVertexBuffer and hkMemoryMeshVertexBuffer, writes an element's values from floats through the utility. */
hkResult hkMeshVertexBuffer::FUN_000260b0(const LockedVertices &lockedVertices, int elementIndex,
                                          const float *values) /* derived name */
{
    return hkMeshVertexBufferUtil::FUN_000aae70(lockedVertices, elementIndex, values);
}
