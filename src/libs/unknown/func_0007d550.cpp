/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

hkpWrappedConstraintData::hkpWrappedConstraintData(hkpConstraintData *constraintData)
{
    if (constraintData) {
        constraintData->addReference();
    }
    this->constraintData = constraintData;
}
