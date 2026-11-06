/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

hkBool hkMemoryMeshMaterial::FUN_000ad300(const hkMeshMaterial *other)
{
    const bool isMemoryMaterial = FUN_00185450(FUN_000246c0(), other->getClassType());
    if (!other || !isMemoryMaterial) {
        return false;
    }
    const hkMemoryMeshMaterial *material = static_cast<const hkMemoryMeshMaterial *>(other);
    if (displacementAmount != other->unknownVirtual21() ||
        tesselationFactor != other->unknownVirtual19()) {
        return false;
    }
    if (compareStrings(materialName.cString(), material->materialName.cString()) != 0) {
        return false;
    }
    if (textures.getSize() != material->textures.getSize()) {
        return false;
    }
    for (int i = textures.getSize() - 1; i >= 0; i--) {
        if (textures[i] && textures[i]->unknownVirtual15() == hkMeshTexture::DOMINANTS) {
            continue;
        }
        if (!textures[i]->unknownVirtual20(material->textures[i])) {
            return false;
        }
    }
    const Vec4 sameDiffuse = _mm_cmpeq_ps(diffuseColor, material->diffuseColor);
    const Vec4 sameAmbient = _mm_cmpeq_ps(ambientColor, material->ambientColor);
    const Vec4 sameSpecular = _mm_cmpeq_ps(specularColor, material->specularColor);
    const Vec4 sameEmissive = _mm_cmpeq_ps(emissiveColor, material->emissiveColor);
    const Vec4 same =
        _mm_and_ps(_mm_and_ps(sameDiffuse, sameAmbient), _mm_and_ps(sameSpecular, sameEmissive));
    return _mm_testc_si128(_mm_castps_si128(same), _mm_set1_epi32(-1));
}
