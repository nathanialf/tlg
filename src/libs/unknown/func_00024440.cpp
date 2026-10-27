/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: the cleanup callback of hkMeshBoneIndexMapping's type info
 * (registered by 0x24490): destroy the mapping in place, which frees its
 * indices. */
void hkMeshBoneIndexMapping::FUN_00024440(void *object)
{
    static_cast<hkMeshBoneIndexMapping *>(object)->mapping.clearAndDeallocate();
}
