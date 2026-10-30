/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: 33 of 44, every store the base's but one pair: the base stores
// the motor's isEnabled and motorAxis (+0xb2, +0xb3) as one zero word, in its
// place in the chain; 3.3's MergeConsecutiveStores (patched by D27 or not, the
// unpatched llc measured) only walks up from the end of a store sequence
// (DAGCombiner.cpp:7888-7891) and merges nothing here, the byte run +0xe2 to
// +0xe5 (0, 1, 2, 3) not merged in either. For the supervisor: D27's reading
// of the base's merge rule (docs/NOTES.md, Round 65A).
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
