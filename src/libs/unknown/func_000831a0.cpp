/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The vtable 0x169ffd0 (address point 0x169ffe0) is a derived row of
 * config/vtables.derived.base.txt (docs/DECISIONS.md D14, round 53). */
ConstraintData169ffe0::ConstraintData169ffe0()
{
    atoms.transforms.type = hkpConstraintAtom::TYPE_SET_LOCAL_TRANSFORMS;
    atoms.angFriction.type = hkpConstraintAtom::TYPE_ANG_FRICTION;
    atoms.angFriction.isEnabled = true;
    atoms.transforms.transformA.setIdentity();
    atoms.transforms.transformB.setIdentity();
    atoms.angFriction.firstFrictionAxis = 0;
    atoms.angFriction.numFrictionAxes = 3;
    atoms.angFriction.maxFrictionTorque = 0.0f;
}
