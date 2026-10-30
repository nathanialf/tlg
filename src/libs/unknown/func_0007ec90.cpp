/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hkpHingeConstraintData::hkpHingeConstraintData()
{
    atoms.transforms.type = hkpConstraintAtom::TYPE_SET_LOCAL_TRANSFORMS;
    atoms.setupStabilization.type = hkpConstraintAtom::TYPE_SETUP_STABILIZATION;
    atoms.setupStabilization.enabled = false;
    atoms.setupStabilization.maxLinImpulse = HK_REAL_MAX;
    atoms.setupStabilization.maxAngImpulse = HK_REAL_MAX;
    atoms.setupStabilization.maxAngle = HK_REAL_HIGH;
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
}
