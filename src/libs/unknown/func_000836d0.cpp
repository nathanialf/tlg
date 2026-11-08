/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The motor's off state is written twice, before its target and again with
 * its axis, as in the prismatic data's constructor (0x7e3d0): the three
 * zero stores into the motor's flag and axis make MemCpyOpt's two-byte
 * memset, one 16-bit store at the end of the zero run (0x8383d); written
 * once, the flag and the axis stay two byte stores (47 of 53). */
hkpLinearClearanceConstraintData::hkpLinearClearanceConstraintData()
{
    atoms.transforms.type = hkpConstraintAtom::TYPE_SET_LOCAL_TRANSFORMS;
    atoms.motor.type = hkpConstraintAtom::TYPE_LIN_MOTOR;
    atoms.friction0.type = hkpConstraintAtom::TYPE_LIN_FRICTION;
    atoms.friction0.isEnabled = true;
    atoms.friction1.type = hkpConstraintAtom::TYPE_LIN_FRICTION;
    atoms.friction1.isEnabled = true;
    atoms.friction2.type = hkpConstraintAtom::TYPE_LIN_FRICTION;
    atoms.friction2.isEnabled = true;
    atoms.ang.type = hkpConstraintAtom::TYPE_ANG;
    atoms.linLimit0.type = hkpConstraintAtom::TYPE_LIN_LIMIT;
    atoms.linLimit1.type = hkpConstraintAtom::TYPE_LIN_LIMIT;
    atoms.linLimit2.type = hkpConstraintAtom::TYPE_LIN_LIMIT;
    atoms.transforms.transformA.setIdentity();
    atoms.transforms.transformB.setIdentity();
    atoms.linLimit0.min = 0.0f;
    atoms.linLimit0.max = 0.0f;
    atoms.linLimit0.axisIndex = 0;
    atoms.linLimit1.min = 0.0f;
    atoms.linLimit1.max = 0.0f;
    atoms.linLimit1.axisIndex = 1;
    atoms.linLimit2.min = 0.0f;
    atoms.linLimit2.max = 0.0f;
    atoms.linLimit2.axisIndex = 2;
    atoms.friction0.maxFrictionForce = 0.0f;
    atoms.friction0.frictionAxis = 0;
    atoms.friction1.maxFrictionForce = 0.0f;
    atoms.friction1.frictionAxis = 1;
    atoms.friction2.maxFrictionForce = 0.0f;
    atoms.friction2.frictionAxis = 2;
    atoms.motor.isEnabled = false;
    atoms.motor.targetPosition = 0.0f;
    atoms.motor.motor = HK_NULL;
    atoms.motor.isEnabled = false;
    atoms.motor.motorAxis = 0;
    atoms.motor.initializedOffset = 0x70;
    atoms.motor.previousTargetPositionOffset = 0x74;
    atoms.ang.constrainedAxes[0] = 0;
    atoms.ang.constrainedAxes[1] = 1;
    atoms.ang.constrainedAxes[2] = 2;
    atoms.ang.numConstrainedAxes = 3;
}
