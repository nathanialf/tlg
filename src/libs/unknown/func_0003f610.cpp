/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the finish callback of hknpScaledConvexShape's type info (0x57c0c48):
 * construct the object in place from a loaded image through its out-of-line
 * finish constructor. */
void FUN_0003f610(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    FUN_0016ce90(static_cast<hknpScaledConvexShape *>(object), flag);
}
