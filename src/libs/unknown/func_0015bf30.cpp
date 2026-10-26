/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The arrays are left as loaded; the world info's finish constructor is
 * out of line. */
hknpWorldSnapshot::hknpWorldSnapshot(hkFinishLoadedObjectFlag flag)
    : hkReferencedObject(flag), bodies(flag), bodyNames(flag), motions(flag), constraints(flag)
{
    FUN_0003b640(&worldCinfo, flag);
}
