/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 15 of hkMemoryMeshTexture's vtable (0x16a39f0) returns
 * its usage hint. */
hkMeshTexture::TextureUsageType hkMemoryMeshTexture::FUN_000ad750() const /* derived name */
{
    return usageHint;
}
