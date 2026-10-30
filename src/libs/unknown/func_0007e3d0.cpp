/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: 33 of 44, every store the base's but one pair: the base stores
// the motor's isEnabled and motorAxis (+0xb2, +0xb3) as one zero word, in its
// place in the chain. Measured (round 66A): MergeConsecutiveStores is tried
// only from a store that ends a store sequence (its chain not used by a
// single store, DAGCombiner.cpp:7888-7891), walks up over stores of the same
// width only, and places the merged store at the run's earliest member. With
// the pair written last it merges into the word but lands at the end; at any
// of the other 25 positions nothing merges. The base's chain therefore ended
// a sequence at motorAxis with isEnabled directly above it (a load or a
// memory intrinsic after it at selection time, which leaves no bytes of its
// own), or the pair was one 16-bit store from the start (docs/NOTES.md,
// Round 66A).
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
