/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: nothing hit: the contact at the end of the wheel's ray,
 * its normal against the suspension (its w kept until the distance is
 * set), no body, the suspension at its full length. */
void hknpVehicleRayCastWheelCollide::FUN_00159010(const hknpVehicleInstance *vehicle, u8 wheelIndex,
                                                  WheelCollideOutput &output) const
{
    const float suspensionLength = vehicle->suspension->wheelParams[wheelIndex].length;
    const hknpVehicleInstance::WheelInfo &wheelInfo = vehicle->wheelsInfo[wheelIndex];
    output.contactBodyId.value = 0x7fffffff;
    output.currentSuspensionLength = suspensionLength;
    output.suspensionClosingSpeed = 0.0f;
    output.contactPoint.position = wheelInfo.rayEndPointWs;
    output.contactPoint.separatingNormal =
        _mm_blend_ps(_mm_xor_ps(wheelInfo.suspensionDirectionWs, _mm_set1_ps(-0.0f)),
                     output.contactPoint.separatingNormal, 8);
    output.contactFriction = 0.0f;
    output.suspensionScalingFactor = 1.0f;
    lane(output.contactPoint.separatingNormal, 3) = suspensionLength;
}
