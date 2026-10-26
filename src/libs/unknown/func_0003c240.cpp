/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The wrapped data finishes itself; the breakable data adds only its
 * vtable. */
hknpBreakableConstraintData::hknpBreakableConstraintData(hkFinishLoadedObjectFlag flag)
    : hkpWrappedConstraintData(flag)
{
}
