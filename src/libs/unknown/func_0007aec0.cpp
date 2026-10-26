/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkpPulleyConstraintData's finish constructor: the constraint data finishes itself, the
 * atoms need nothing, and the vtable is set. */
hkpPulleyConstraintData::hkpPulleyConstraintData(hkFinishLoadedObjectFlag flag)
    : hkpConstraintData(flag)
{
}
