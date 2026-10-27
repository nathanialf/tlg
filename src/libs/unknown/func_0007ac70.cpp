/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkpLinearClearanceConstraintData's finish constructor: the constraint
 * data finishes itself, the vtable is set, then the atoms finish
 * themselves (their constructor is out of line). */
hkpLinearClearanceConstraintData::hkpLinearClearanceConstraintData(hkFinishLoadedObjectFlag flag)
    : hkpConstraintData(flag), atoms(flag)
{
}
