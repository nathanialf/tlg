/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* hkpPointToPlaneConstraintData's constructor: the atoms typed, both
 * frames the identity, the first axis constrained. */
hkpPointToPlaneConstraintData::hkpPointToPlaneConstraintData()
{
    atoms.transforms.type = hkpConstraintAtom::TYPE_SET_LOCAL_TRANSFORMS;
    atoms.lin.type = hkpConstraintAtom::TYPE_LIN;
    atoms.transforms.transformA.setIdentity();
    atoms.transforms.transformB.setIdentity();
    atoms.lin.axisIndex = 0;
}
