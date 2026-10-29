/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 9 of hkMemoryMeshMaterial's vtable (0x16a3920) sets
 * its name; slot 10 of hkMemoryMeshTexture's (0x16a39f0) holds the same
 * body for its filename. */
void hkMemoryMeshMaterial::FUN_000acf80(const char *newName) /* derived name */
{
    materialName = newName;
}
