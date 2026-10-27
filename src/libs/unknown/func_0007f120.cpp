/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hkpPointToPathConstraintData's type
 * info (registered at 0x7f3b2): construct the object in place from a loaded
 * image through its inline finish constructor, which hands the bridge atom
 * its data when finishing. */
void FUN_0007f120(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpPointToPathConstraintData(flag);
}
