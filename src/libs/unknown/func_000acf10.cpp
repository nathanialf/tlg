/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 6 of hkMemoryMeshMaterial's vtable (0x16a3950): the
 * material takes any vertex buffer as it is, so the compatible buffer is the
 * one given, with a reference for the caller. */
hkMeshVertexBuffer *hkMemoryMeshMaterial::FUN_000acf10(hkMeshVertexBuffer *buffer)
{
    buffer->addReference();
    return buffer;
}
