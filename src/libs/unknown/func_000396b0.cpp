/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpMotionProperties::FUN_000396b0(Preset preset, float gravity, float unitScale)
{
    FUN_00018160(&flags, 0, sizeof(hknpMotionProperties) - sizeof(isExclusive));
    switch (preset) {
    case STATIC:
        gravityFactor = 0.0f;
        maxLinearSpeed = 0.0f;
        maxAngularSpeed = 0.0f;
        linearDamping = 0.0f;
        angularDamping = 0.0f;
        timeFactor = 1.0f;
        solverStabilizationSpeedThreshold = 0.0f;
        solverStabilizationSpeedReduction = 0.0f;
        break;
    case DYNAMIC:
        linearDamping = 0.0f;
        angularDamping = 0.0f;
        maxLinearSpeed = unitScale * 200.0f;
        maxAngularSpeed = 100.0f;
        gravityFactor = 1.0f;
        timeFactor = 1.0f;
        solverStabilizationSpeedThreshold = 0.0f;
        solverStabilizationSpeedReduction = 0.0f;
        break;
    case KEYFRAMED:
        linearDamping = 0.0f;
        angularDamping = 0.0f;
        maxLinearSpeed = unitScale * 200.0f;
        maxAngularSpeed = 100.0f;
        gravityFactor = 0.0f;
        timeFactor = 1.0f;
        solverStabilizationSpeedThreshold = 0.0f;
        solverStabilizationSpeedReduction = 0.0f;
        break;
    case FROZEN:
        linearDamping = 30.0f;
        angularDamping = 30.0f;
        maxLinearSpeed = 0.0f;
        maxAngularSpeed = 0.0f;
        gravityFactor = 0.0f;
        timeFactor = 1.0f;
        solverStabilizationSpeedThreshold = 0.0f;
        solverStabilizationSpeedReduction = 0.0f;
        break;
    case DEBRIS: {
        linearDamping = 0.01f;
        angularDamping = 0.5f;
        maxLinearSpeed = unitScale * 100.0f;
        maxAngularSpeed = 10.0f;
        gravityFactor = 1.0f;
        timeFactor = 1.0f;
        solverStabilizationSpeedThreshold = 0.2f;
        const float gravityMagnitude = hkMath::fabs(gravity);
        const float reduction = gravityMagnitude * 0.1f;
        solverStabilizationSpeedReduction = (gravityMagnitude == 0.0f) ? 1.0f : reduction;
        break;
    }
    }

    /* The deactivation's thresholds. */
    maxDistSqrd = 0.05f * 0.05f;
    const float maxRotation = hkMath::min2(0.05f, 0.6f);
    maxRotSqrd = maxRotation * maxRotation;
    invBlockSize = 1.0f;
    numDeactivationFrequencyPasses = 4;
    minimumPathingVelocityScaleSquare = 0x75;
    deactivationVelocityScaleSquare = 0x73;
    pathingUpperThreshold = 0x67ff;
    pathingLowerThreshold = 0;
    spikingVelocityScaleThresholdSquared = 6;
    minimumSpikingVelocityScaleSquared = 0x73;
}
