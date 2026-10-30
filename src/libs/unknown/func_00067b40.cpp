/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpMalleableConstraintData::buildJacobianCallback(const void *input, void *output)
{
    ConstraintQueryIn query = *static_cast<const ConstraintQueryIn *>(input);
    query.factor24 = query.factor24 * strength;
    ConstraintInfo info;
    constraintData->unknownVirtual6(info);
    FUN_000c8710(info.atoms, info.sizeOfAllAtoms, query, output);
}
