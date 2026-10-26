/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 13 of hkMemoryMeshMaterial's vtable adds a texture: a
 * slot is opened for it in order, and the texture is put there through
 * slot 14. */
void hkMemoryMeshMaterial::FUN_000ad1c0(hkMeshTexture *texture) /* derived name */
{
    int index = FUN_000acfc0(texture);
    unknownVirtual14(index, texture);
}
