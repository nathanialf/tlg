/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hkpRagdollLimitsData's type info:
 * construct the object in place from a loaded image through its inline
 * finish constructor, which turns the cone's stabilization back on when the
 * loaded atoms had it. */
void FUN_000788f0(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpRagdollLimitsData(flag);
}
