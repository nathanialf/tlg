/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hkxNodeSelectionSet's type info
 * (registered at 0x8b00e): construct the object in place from a loaded image. */
void FUN_0008af30(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxNodeSelectionSet(flag);
}
