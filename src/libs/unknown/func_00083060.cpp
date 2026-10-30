/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

hkpHingeLimitsData::hkpHingeLimitsData()
{
    atoms.rotations.type = hkpConstraintAtom::TYPE_SET_LOCAL_ROTATIONS;
    atoms.angLimit.type = hkpConstraintAtom::TYPE_ANG_LIMIT;
    atoms.angLimit.isEnabled = 1;
    atoms.twoDAng.type = hkpConstraintAtom::TYPE_2D_ANG;
    atoms.rotations.rotationA.setIdentity();
    atoms.rotations.rotationB.setIdentity();
    atoms.twoDAng.freeRotationAxis = 0;
    atoms.angLimit.limitAxis = 0;
    atoms.angLimit.cosineAxis = 1;
    atoms.angLimit.minAngle = -HK_REAL_PI;
    atoms.angLimit.maxAngle = HK_REAL_PI;
    atoms.angLimit.angularLimitsTauFactor = 1.0f;
    atoms.angLimit.angularLimitsDampFactor = 1.0f;
}
