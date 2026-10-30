/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 12 of hkMemoryMeshMaterial's vtable (address point
 * 0x16a3920) returns one of its textures by index. */
hkMeshTexture *hkMemoryMeshMaterial::FUN_000acfb0(int index) const /* derived name */
{
    return textures[index];
}
