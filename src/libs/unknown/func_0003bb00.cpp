/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the finish callback of hknpDummyShape's type info (0x57bfd60):
 * construct the object in place from a loaded image (the finish
 * constructor is out of line). */
void FUN_0003bb00(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpDummyShape(flag);
}
