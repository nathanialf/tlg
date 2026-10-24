/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the finish callback of hknpMalleableConstraintData's type info (0x57c18d8):
 * construct the object in place from a loaded image through its out-of-line
 * finish constructor. */
void FUN_000615c0(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    FUN_00067960(static_cast<hknpMalleableConstraintData *>(object), flag);
}
