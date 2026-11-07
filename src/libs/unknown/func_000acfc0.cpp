/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: 257 bytes against 507: the array's setSize for the counted
// textures (reserve, the lost elements released from the last, the gained
// ones cleared) stays a call: the inliner prices it at 330 against the
// hinted threshold of 325 (opt -debug-only=inline), where the base inlines
// it (0xad096 to 0xad18f). Everything before it is the base's
// (docs/NOTES.md, Round 75B).
int hkMemoryMeshMaterial::FUN_000acfc0(hkMeshTexture *texture)
{
    const hkMeshTexture::TextureUsageType usage = texture->unknownVirtual15();
    const int numTextures = textures.getSize();
    int i = 0;
    for (; i < numTextures; i++) {
        if (textures[i]->unknownVirtual15() > usage) {
            const hkRefPtr<hkMeshTexture> none;
            textures.spliceInto(hkContainerHeapAllocator::get(), i, 0, &none, 1);
            return i;
        }
    }
    textures.setSize(i + 1);
    return i;
}
