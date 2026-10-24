/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the finish callback of hkRefCountedProperties' type info
 * (0x57b85e8): construct the object in place from a loaded image through
 * its out-of-line finish constructor. */
void FUN_0000d370(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    FUN_0001c1e0(static_cast<hkRefCountedProperties *>(object), flag);
}
