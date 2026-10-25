/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 20 of hkMemoryMeshMaterial's vtable (0x16a3920) sets
 * its tesselation factor. */
void hkMemoryMeshMaterial::FUN_000acb10(float factor) /* derived name */
{
    tesselationFactor = factor;
}
