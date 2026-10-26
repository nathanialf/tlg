/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: an element's values as floats for every locked vertex, from
 * the element's buffer description. */
hkResult
hkMeshVertexBufferUtil::FUN_000aaaf0(const hkMeshVertexBuffer::LockedVertices &lockedVertices,
                                     int elementIndex, float *values)
{
    return FUN_000aab10(lockedVertices.buffers[elementIndex], values, lockedVertices.numVertices);
}
