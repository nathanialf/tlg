/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hkxLight's type info (0x57c7b50):
 * construct the object in place from a loaded image through its inline
 * finish constructor, which has nothing to fix up but the vtable. */
void FUN_0008c380(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxLight(flag);
}
