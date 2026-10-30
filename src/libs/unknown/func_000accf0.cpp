/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hkMemoryMeshMaterial::hkMemoryMeshMaterial(hkFinishLoadedObjectFlag flag)
    : hkMeshMaterial(flag), textures(flag), materialName(flag)
{
}

/* The class's key function: its vtable and deleting destructor (0xacd10)
 * are emitted with it. */
inline hkMemoryMeshMaterial::~hkMemoryMeshMaterial() {}
