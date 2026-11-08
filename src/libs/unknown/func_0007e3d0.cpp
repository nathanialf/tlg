/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The motor's off state is written twice, before its target and again with
 * its axis, as in the linear clearance data's constructor (0x836d0): the
 * three zero stores into the motor's flag and axis make MemCpyOpt's
 * two-byte memset, one 16-bit store at the end of the zero run (0x7e4c5);
 * written once, the flag and the axis stay two byte stores. */
hkpPrismaticConstraintData::hkpPrismaticConstraintData()
{
    atoms.transforms.type = hkpConstraintAtom::TYPE_SET_LOCAL_TRANSFORMS;
    atoms.motor.type = hkpConstraintAtom::TYPE_LIN_MOTOR;
    atoms.friction.type = hkpConstraintAtom::TYPE_LIN_FRICTION;
    atoms.friction.isEnabled = true;
    atoms.ang.type = hkpConstraintAtom::TYPE_ANG;
    atoms.lin0.type = hkpConstraintAtom::TYPE_LIN;
    atoms.lin1.type = hkpConstraintAtom::TYPE_LIN;
    atoms.linLimit.type = hkpConstraintAtom::TYPE_LIN_LIMIT;
    atoms.transforms.transformA.setIdentity();
    atoms.transforms.transformB.setIdentity();
    atoms.linLimit.min = -HK_REAL_MAX;
    atoms.linLimit.max = HK_REAL_MAX;
    atoms.linLimit.axisIndex = 0;
    atoms.friction.maxFrictionForce = 0.0f;
    atoms.friction.frictionAxis = 0;
    atoms.motor.isEnabled = false;
    atoms.motor.targetPosition = 0.0f;
    atoms.motor.motor = HK_NULL;
    atoms.motor.isEnabled = false;
    atoms.motor.motorAxis = 0;
    atoms.motor.initializedOffset = 80;
    atoms.motor.previousTargetPositionOffset = 84;
    atoms.ang.constrainedAxes[0] = 0;
    atoms.ang.constrainedAxes[1] = 1;
    atoms.ang.constrainedAxes[2] = 2;
    atoms.ang.numConstrainedAxes = 3;
    atoms.lin0.axisIndex = 1;
    atoms.lin1.axisIndex = 2;
}
