/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkMultipleVertexBuffer's finish constructor: nothing loaded needs fixing
 * up, so only the vtable is set (called by the finish callback 0x238d0 and
 * by the reflection initializer at 0x23b6e). */
hkMultipleVertexBuffer::hkMultipleVertexBuffer(hkFinishLoadedObjectFlag flag)
    : hkMeshVertexBuffer(flag), lockedElements(flag), elementInfos(flag), vertexBufferInfos(flag)
{
}
