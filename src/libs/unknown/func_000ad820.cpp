/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

hkBool hkMemoryMeshTexture::FUN_000ad820(const hkMeshTexture *other) const /* derived name */
{
    const hkMemoryMeshTexture *texture = static_cast<const hkMemoryMeshTexture *>(other);
    return other && FUN_00185450(FUN_000247f0(), other->getClassType()) &&
           format == texture->format && hasMipMaps == texture->hasMipMaps &&
           filterMode == texture->filterMode && usageHint == texture->usageHint &&
           data.getSize() == texture->data.getSize() &&
           compareStrings(filename.cString(), texture->filename.cString()) == 0 &&
           textureCoordChannel == texture->textureCoordChannel &&
           FUN_00018180(data.data, texture->data.data, data.getSize()) == 0;
}
