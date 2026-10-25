/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 16 of hkMemoryMeshTexture's vtable (0x16a39f0) sets
 * its usage hint. */
void hkMemoryMeshTexture::FUN_000ad760(TextureUsageType newUsageHint) /* derived name */
{
    usageHint = newUsageHint;
}
