/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the finish callback of hknpCompositeShape's type info
 * (stored at 0x71777): construct the shape in place from a loaded image
 * through its inline finish constructor. */
void FUN_00071690(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpCompositeShape(flag);
}
