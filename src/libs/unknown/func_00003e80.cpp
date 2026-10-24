/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the finish callback of hkUuid's type info (0x57b7a60):
 * construct the uuid in place from a loaded image through its out-of-line
 * finish constructor. */
void FUN_00003e80(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    FUN_0000dbc0(static_cast<hkUuid *>(object), flag);
}
