/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 18 of hkMemoryMeshTexture's vtable (0x16a39f0) sets
 * its texture coordinate channel. */
void hkMemoryMeshTexture::FUN_000ad780(int newTextureCoordChannel) /* derived name */
{
    textureCoordChannel = newTextureCoordChannel;
}
