/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 8 of hkMemoryMeshBody's vtable (address point
 * 0x1691610) returns one of its vertex buffers by index. */
hkMeshVertexBuffer *hkMemoryMeshBody::FUN_000230e0(int index) const /* derived name */
{
    return vertexBuffers.data[index];
}
