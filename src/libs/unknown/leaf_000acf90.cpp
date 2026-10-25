/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 10 of hkMemoryMeshMaterial's vtable (0x16a3920)
 * returns its name; the same body is slot 9 of hkMemoryMeshTexture's
 * (0x16a39f0, its filename) and of four other vtables (0x16a47f0, 0x16a48e0,
 * 0x16a4b40, 0x16a5290), and slot 6 of 0x16a6310. */
const char *hkMemoryMeshMaterial::FUN_000acf90() const /* derived name */
{
    return materialName.cString();
}
