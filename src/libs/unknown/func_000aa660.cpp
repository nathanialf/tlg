/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The bone arrays are left as loaded. */
hkSkinnedRefMeshShape::hkSkinnedRefMeshShape(hkFinishLoadedObjectFlag flag) : hkMeshShape(flag)
{
    FUN_0000e5c0(&name, flag);
}
