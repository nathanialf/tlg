/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpVehicleInstance::FUN_00163640(int wheelIndex, hknpVehicleFrictionSolverAxleParams &axle,
                                       float forwardForce, float wheelDownForce,
                                       float slipFactor) const
{
    const WheelInfo &wheelInfo = wheelsInfo[wheelIndex];
    const int axleIndex = data->wheelParams[wheelIndex].axle;

    Vec4 forward = cross3(wheelInfo.contactPoint.separatingNormal, wheelInfo.spinAxisWs);
    if (_mm_cvtss_f32(_mm_dp_ps(forward, forward, 0x7F)) < _mm_cvtss_f32(D_14b2060[35])) {
        forward = cross3(wheelInfo.spinAxisWs, wheelInfo.suspensionDirectionWs);
    }
    forward = normalized3(forward);
    const Vec4 constraintNormal = cross3(forward, wheelInfo.contactPoint.separatingNormal);

    const float invNumWheelsOnAxle = 1.0f / float(data->numWheelsPerAxle[axleIndex]);
    const float frictionShare = invNumWheelsOnAxle * wheelInfo.contactFriction;
    axle.contactPointWs =
        _mm_add_ps(_mm_mul_ps(_mm_set1_ps(invNumWheelsOnAxle), wheelInfo.contactPoint.position),
                   axle.contactPointWs);
    axle.constraintNormalWs = _mm_add_ps(constraintNormal, axle.constraintNormalWs);
    axle.forwardDirWs = _mm_add_ps(forward, axle.forwardDirWs);
    axle.frictionCoefficient += frictionShare * data->wheelParams[wheelIndex].friction;
    axle.viscosityFrictionCoefficient +=
        frictionShare * data->wheelParams[wheelIndex].viscosityFriction;
    axle.maxFrictionCoefficient += frictionShare * data->wheelParams[wheelIndex].maxFriction;
    axle.wheelDownForce += wheelDownForce;
    axle.forwardForce += forwardForce;
    axle.wheelFixed = axle.wheelFixed || isFixed[wheelIndex];
    axle.slipVelocityFactor +=
        invNumWheelsOnAxle * data->wheelParams[wheelIndex].slipAngle * slipFactor;
}
