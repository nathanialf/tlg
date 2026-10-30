/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: the finish callback of hknpBreakableConstraintData's type info (0x57c23f8):
 * construct the object in place from a loaded image through its out-of-line
 * finish constructor. */
void FUN_00069770(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpBreakableConstraintData(flag);
}
