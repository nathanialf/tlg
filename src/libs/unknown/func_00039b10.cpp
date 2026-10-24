/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the finish callback of hknpConvexPolytopeShape's type info (0x57bf760):
 * construct the object in place from a loaded image through its out-of-line
 * finish constructor. */
void FUN_00039b10(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    FUN_001520b0(static_cast<hknpConvexPolytopeShape *>(object), flag);
}
