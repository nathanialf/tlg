/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The bone and part arrays are left as loaded. */
hkStorageSkinnedMeshShape::hkStorageSkinnedMeshShape(hkFinishLoadedObjectFlag flag)
    : hkSkinnedMeshShape(flag), boneSets(flag)
{
    FUN_0000e5c0(&name, flag);
}
