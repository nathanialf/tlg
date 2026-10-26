/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the finish callback of hkpLimitedHingeConstraintData::Atoms' type info (0x57c57f8):
 * construct the object in place from a loaded image through its
 * out-of-line finish constructor. */
void FUN_00081fd0(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpLimitedHingeConstraintData::Atoms(flag);
}
