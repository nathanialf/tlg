/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

hkpRotationalConstraintData::hkpRotationalConstraintData()
{
    atoms.rotations.type = hkpConstraintAtom::TYPE_SET_LOCAL_ROTATIONS;
    atoms.ang.type = hkpConstraintAtom::TYPE_ANG;
    atoms.rotations.rotationA.setIdentity();
    atoms.rotations.rotationB.setIdentity();
    atoms.ang.constrainedAxes[0] = 0;
    atoms.ang.constrainedAxes[1] = 1;
    atoms.ang.constrainedAxes[2] = 2;
    atoms.ang.numConstrainedAxes = 3;
}
