/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkpWrappedConstraintData's finish constructor: the constraint data finishes itself, the
 * wrapped pointer is left as loaded, and the vtable is set. */
hkpWrappedConstraintData::hkpWrappedConstraintData(hkFinishLoadedObjectFlag flag)
    : hkpConstraintData(flag)
{
}
