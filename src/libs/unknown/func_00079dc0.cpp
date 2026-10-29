/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

hkpPointToPathConstraintData::hkpPointToPathConstraintData()
{
    path = 0;
    maxFrictionForce = 0.0f;
    angularConstrainedDOF = CONSTRAIN_ORIENTATION_NONE;
    transform_OS_KS[0].setIdentity();
    transform_OS_KS[1].setIdentity();
    FUN_0007d030(&atoms.bridgeAtom, this);
}
