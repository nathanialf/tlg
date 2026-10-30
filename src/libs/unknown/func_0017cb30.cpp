/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hkpWheelConstraintData::hkpWheelConstraintData()
{
    atoms.suspensionBase.type = hkpConstraintAtom::TYPE_SET_LOCAL_TRANSFORMS;
    atoms.lin0Limit.type = hkpConstraintAtom::TYPE_LIN_LIMIT;
    atoms.lin0Soft.type = hkpConstraintAtom::TYPE_LIN_SOFT;
    atoms.lin1.type = hkpConstraintAtom::TYPE_LIN;
    atoms.lin2.type = hkpConstraintAtom::TYPE_LIN;
    atoms.steeringBase.type = hkpConstraintAtom::TYPE_SET_LOCAL_ROTATIONS;
    atoms.ang2d.type = hkpConstraintAtom::TYPE_2D_ANG;
    atoms.lin0Limit.axisIndex = 0;
    atoms.lin0Soft.axisIndex = 0;
    atoms.lin1.axisIndex = 1;
    atoms.lin2.axisIndex = 2;
    atoms.lin0Limit.min = -0.5f;
    atoms.lin0Limit.max = 0.5f;
    atoms.lin0Soft.tau = 0.0f;
    atoms.lin0Soft.damping = 0.0f;
    atoms.steeringBase.rotationA.setIdentity();
    atoms.steeringBase.rotationB.setIdentity();
    atoms.suspensionBase.transformA.setIdentity();
    atoms.suspensionBase.transformB.setIdentity();
    atoms.ang2d.freeRotationAxis = 0;
}
