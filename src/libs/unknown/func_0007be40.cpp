/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the pivot frames stored in the transforms atom. */
void hkpFixedConstraintData::FUN_0007be40(const hkTransform &pivotA, const hkTransform &pivotB)
{
    atoms.transforms.transformA = pivotA;
    atoms.transforms.transformB = pivotB;
}
