/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hkpWheelFrictionConstraintData's type
 * info (registered at 0x7b375): construct the object in place from a loaded
 * image through its inline finish constructor, which resets the friction
 * atom's impulses when finishing. */
void FUN_0007b110(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpWheelFrictionConstraintData(flag);
}
