/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 7 of hkMemoryMeshMaterial's vtable (0x16a3958): whether
 * a vertex buffer suits the material, which is when it is a memory vertex
 * buffer (its class against hkMemoryMeshVertexBuffer's). */
hkBool hkMemoryMeshMaterial::FUN_000acf40(hkMeshVertexBuffer *buffer)
{
    const bool isMemoryBuffer =
        FUN_00185450(hkMemoryMeshVertexBuffer::FUN_0002ae00(), buffer->getClassType());
    return buffer && isMemoryBuffer;
}
