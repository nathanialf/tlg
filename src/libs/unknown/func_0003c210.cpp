/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* hknpBreakableConstraintData's constructor: the wrapped data's, then a
 * threshold of 10. */
hknpBreakableConstraintData::hknpBreakableConstraintData(hkpConstraintData *constraintData)
    : hkpWrappedConstraintData(constraintData), threshold(10.0f)
{
}

/* Slot 29: a new breakable data over a deep copy of the wrapped data, whose
 * reference the new data holds, with this one's threshold. */
hkpConstraintData *hknpBreakableConstraintData::clone() const
{
    hkpConstraintData *childClone = FUN_000794c0(getWrappedConstraintData());
    hknpBreakableConstraintData *copy = new hknpBreakableConstraintData(childClone);
    childClone->removeReference();
    copy->threshold = threshold;
    return copy;
}
