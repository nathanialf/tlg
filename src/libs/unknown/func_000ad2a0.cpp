/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 15 of hkMemoryMeshMaterial's vtable (address point
 * 0x16a3920): the four colors copied out. */
void hkMemoryMeshMaterial::FUN_000ad2a0(Vec4 &diffuse, Vec4 &ambient, Vec4 &specular,
                                        Vec4 &emissive) const /* derived name */
{
    diffuse = diffuseColor;
    ambient = ambientColor;
    specular = specularColor;
    emissive = emissiveColor;
}
