/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

hkpBallAndSocketConstraintData::hkpBallAndSocketConstraintData()
{
    atoms.pivots.type = hkpConstraintAtom::TYPE_SET_LOCAL_TRANSLATIONS;
    atoms.setupStabilization.type = hkpConstraintAtom::TYPE_SETUP_STABILIZATION;
    atoms.setupStabilization.enabled = false;
    atoms.setupStabilization.maxLinImpulse = HK_REAL_MAX;
    atoms.setupStabilization.maxAngImpulse = HK_REAL_MAX;
    atoms.setupStabilization.maxAngle = HK_REAL_HIGH;
    atoms.ballSocket.type = hkpConstraintAtom::TYPE_BALL_SOCKET;
    atoms.ballSocket.solvingMethod = hkpConstraintAtom::METHOD_OLD;
    atoms.ballSocket.bodiesToNotify = 0;
    atoms.ballSocket.velocityStabilizationFactor = 1.0f;
    atoms.ballSocket.enableLinearImpulseLimit = false;
    atoms.ballSocket.breachImpulse = HK_REAL_MAX;
    atoms.ballSocket.inertiaStabilizationFactor = 0.0f;
    atoms.pivots.translationA = _mm_setzero_ps();
    atoms.pivots.translationB = _mm_setzero_ps();
}
