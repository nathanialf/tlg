/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The atoms' types and the defaults they start from (the ball and socket's
 * velocity stabilization through hkUFloat8's assignment, out of line, which
 * sees the object), then the ragdoll's own values; the cone's stabilization
 * turned on through the switch below, which this file defines and so
 * inlines. */
hkpRagdollConstraintData::hkpRagdollConstraintData()
{
    atoms.transforms.type = hkpConstraintAtom::TYPE_SET_LOCAL_TRANSFORMS;
    atoms.setupStabilization.type = hkpConstraintAtom::TYPE_SETUP_STABILIZATION;
    atoms.setupStabilization.enabled = false;
    atoms.setupStabilization.maxLinImpulse = HK_REAL_MAX;
    atoms.setupStabilization.maxAngImpulse = HK_REAL_MAX;
    atoms.setupStabilization.maxAngle = HK_REAL_HIGH;
    atoms.ragdollMotors.type = hkpConstraintAtom::TYPE_RAGDOLL_MOTOR;
    atoms.ragdollMotors.isEnabled = true;
    atoms.ragdollMotors.initializedOffset = -1;
    atoms.ragdollMotors.previousTargetAnglesOffset = -1;
    atoms.angFriction.type = hkpConstraintAtom::TYPE_ANG_FRICTION;
    atoms.angFriction.isEnabled = true;
    atoms.angFriction.numFrictionAxes = 1;
    atoms.twistLimit.type = hkpConstraintAtom::TYPE_TWIST_LIMIT;
    atoms.twistLimit.isEnabled = true;
    atoms.coneLimit.type = hkpConstraintAtom::TYPE_CONE_LIMIT;
    atoms.coneLimit.isEnabled = true;
    atoms.coneLimit.memOffsetToAngleOffset = 0;
    atoms.planesLimit.type = hkpConstraintAtom::TYPE_CONE_LIMIT;
    atoms.planesLimit.isEnabled = true;
    atoms.planesLimit.memOffsetToAngleOffset = 0;
    atoms.ballSocket.type = hkpConstraintAtom::TYPE_BALL_SOCKET;
    atoms.ballSocket.solvingMethod = hkpConstraintAtom::METHOD_OLD;
    atoms.ballSocket.bodiesToNotify = 0;
    atoms.ballSocket.velocityStabilizationFactor = 1.0f;
    atoms.ballSocket.enableLinearImpulseLimit = false;
    atoms.ballSocket.breachImpulse = HK_REAL_MAX;
    atoms.ballSocket.inertiaStabilizationFactor = 0.0f;

    atoms.transforms.transformA.setIdentity();
    atoms.transforms.transformB.setIdentity();

    atoms.angFriction.firstFrictionAxis = 0;
    atoms.angFriction.numFrictionAxes = 3;
    atoms.angFriction.maxFrictionTorque = 0.0f;

    atoms.ragdollMotors.isEnabled = false;
    atoms.ragdollMotors.initializedOffset = 144;
    atoms.ragdollMotors.previousTargetAnglesOffset = 148;
    atoms.ragdollMotors.target_bRca.setIdentity();
    atoms.ragdollMotors.motors[0] = HK_NULL;
    atoms.ragdollMotors.motors[1] = HK_NULL;
    atoms.ragdollMotors.motors[2] = HK_NULL;

    atoms.twistLimit.twistAxis = 0;
    atoms.twistLimit.refAxis = 1;
    atoms.twistLimit.minAngle = -0.5236f;
    atoms.twistLimit.maxAngle = 0.5236f;
    atoms.twistLimit.angularLimitsTauFactor = 0.8f;
    atoms.twistLimit.angularLimitsDampFactor = 1.0f;

    atoms.coneLimit.twistAxisInA = 0;
    atoms.coneLimit.refAxisInB = 0;
    atoms.coneLimit.angleMeasurementMode = 0;
    atoms.coneLimit.minAngle = -100.0f;
    atoms.coneLimit.maxAngle = 1.0f;
    atoms.coneLimit.angularLimitsTauFactor = 0.8f;
    atoms.coneLimit.angularLimitsDampFactor = 1.0f;
    FUN_0007dad0(true);

    atoms.planesLimit.twistAxisInA = 0;
    atoms.planesLimit.refAxisInB = 1;
    atoms.planesLimit.angleMeasurementMode = 1;
    atoms.planesLimit.minAngle = -0.025f;
    atoms.planesLimit.maxAngle = 0.025f;
    atoms.planesLimit.angularLimitsTauFactor = 0.8f;
    atoms.planesLimit.angularLimitsDampFactor = 1.0f;
}

/* Turn the cone limit's stabilization on or off: when on, the cone keeps its
 * angle offset 56 bytes into the constraint's runtime. Run by the finish
 * callback (0x82cb6) when the loaded offset is nonzero. */
void hkpRagdollConstraintData::FUN_0007dad0(hkBool enable) /* derived name */
{
    atoms.coneLimit.memOffsetToAngleOffset = enable ? 56 : 0;
}
