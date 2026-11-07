/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

hkpLimitedHingeConstraintData::hkpLimitedHingeConstraintData()
{
    atoms.transforms.type = hkpConstraintAtom::TYPE_SET_LOCAL_TRANSFORMS;
    atoms.setupStabilization.type = hkpConstraintAtom::TYPE_SETUP_STABILIZATION;
    atoms.setupStabilization.enabled = false;
    atoms.setupStabilization.maxLinImpulse = HK_REAL_MAX;
    atoms.setupStabilization.maxAngImpulse = HK_REAL_MAX;
    atoms.setupStabilization.maxAngle = HK_REAL_HIGH;
    atoms.angMotor.type = hkpConstraintAtom::TYPE_ANG_MOTOR;
    atoms.angMotor.isEnabled = true;
    atoms.angMotor.initializedOffset = -1;
    atoms.angMotor.previousTargetAngleOffset = -1;
    atoms.angMotor.correspondingAngLimitSolverResultOffset = -1;
    atoms.angFriction.type = hkpConstraintAtom::TYPE_ANG_FRICTION;
    atoms.angFriction.isEnabled = true;
    atoms.angFriction.numFrictionAxes = 1;
    atoms.angLimit.type = hkpConstraintAtom::TYPE_ANG_LIMIT;
    atoms.angLimit.isEnabled = true;
    atoms.twoDAng.type = hkpConstraintAtom::TYPE_2D_ANG;
    atoms.ballSocket.type = hkpConstraintAtom::TYPE_BALL_SOCKET;
    atoms.ballSocket.solvingMethod = hkpConstraintAtom::METHOD_OLD;
    atoms.ballSocket.bodiesToNotify = 0;
    atoms.ballSocket.velocityStabilizationFactor = 1.0f;
    atoms.ballSocket.enableLinearImpulseLimit = false;
    atoms.ballSocket.breachImpulse = HK_REAL_MAX;
    atoms.ballSocket.inertiaStabilizationFactor = 0.0f;

    atoms.transforms.transformA.setIdentity();
    atoms.transforms.transformB.setIdentity();
    atoms.twoDAng.freeRotationAxis = 0;
    atoms.angLimit.limitAxis = 0;
    atoms.angLimit.cosineAxis = 1;
    atoms.angLimit.minAngle = -HK_REAL_PI;
    atoms.angLimit.maxAngle = HK_REAL_PI;
    atoms.angLimit.angularLimitsTauFactor = 1.0f;
    atoms.angLimit.angularLimitsDampFactor = 1.0f;
    atoms.angFriction.firstFrictionAxis = 0;
    atoms.angFriction.numFrictionAxes = 1;
    atoms.angFriction.maxFrictionTorque = 0.0f;
    atoms.angMotor.initializedOffset = HK_OFFSET_OF(Runtime, initialized);
    atoms.angMotor.previousTargetAngleOffset = HK_OFFSET_OF(Runtime, previousTargetAngle);
    atoms.angMotor.correspondingAngLimitSolverResultOffset =
        SOLVER_RESULT_LIMIT * sizeof(hkpSolverResults);
    atoms.angMotor.isEnabled = false;
    atoms.angMotor.targetAngle = 0.0f;
    atoms.angMotor.motor = HK_NULL;
    atoms.angMotor.motorAxis = 0;
}
