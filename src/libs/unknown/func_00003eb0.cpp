/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the finish callback of hkUuidObject's type info
 * (0x57b7ae0): construct the object in place from a loaded image through its
 * out-of-line finish constructor. */
void FUN_00003eb0(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    FUN_0000dc40(static_cast<hkUuidObject *>(object), flag);
}
