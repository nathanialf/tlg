/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hknpBreakableConstraintData's constructor: the wrapped data's, then a
 * threshold of 10. */
hknpBreakableConstraintData::hknpBreakableConstraintData(hkpConstraintData *constraintData)
    : hkpWrappedConstraintData(constraintData), threshold(10.0f)
{
}
