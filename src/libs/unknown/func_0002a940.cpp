/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Out of line: the finish callback 0x23df0 jumps here. The arrays at +0x10
 * to +0x30 are left as loaded. */
hkMemoryMeshShape::hkMemoryMeshShape(hkFinishLoadedObjectFlag flag) : hkMeshShape(flag)
{
    FUN_0000e5c0(&name, flag);
}
