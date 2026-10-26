/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hknpStaticCompoundShapeInternals'
 * type info (0x57bde70): construct the object in place from a loaded image
 * (its finish constructor is inline over hknpStaticCompoundShape's). */
void FUN_00033fb0(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpStaticCompoundShapeInternals(flag);
}
