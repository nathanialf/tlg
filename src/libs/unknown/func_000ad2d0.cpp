/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 16 of hkMemoryMeshMaterial's vtable (address point
 * 0x16a3920): the four colors set. */
void hkMemoryMeshMaterial::FUN_000ad2d0(const Vec4 &diffuse, const Vec4 &ambient,
                                        const Vec4 &specular,
                                        const Vec4 &emissive) /* derived name */
{
    diffuseColor = diffuse;
    ambientColor = ambient;
    specularColor = specular;
    emissiveColor = emissive;
}
