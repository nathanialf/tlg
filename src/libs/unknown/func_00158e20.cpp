/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The reciprocal's factor negated across the subtraction (`vsubps (d*r) -
 * 2; vmulps r`): DAGCombiner under the library line's unsafe algebra
 * (docs/DECISIONS.md D40). */

/* derived name: the hit's normal and point (the hard point moved down the
 * suspension by the hit's share of the ray), the body and shape key, the
 * suspension's length less the wheel's radius as the contact's distance, the
 * hit body's material friction, and the suspension's closing speed and
 * scaling from the contact normal against the suspension's direction: the
 * chassis's velocity at the contact less the ground's, over the normal's
 * share, when the normal is within the clipping angle; none, and the
 * clipping angle's reciprocal, when not. */
void hknpVehicleRayCastWheelCollide::FUN_00158e20(const hknpVehicleInstance *vehicle, u8 wheelIndex,
                                                  const hknpClosestHitCollector &collector,
                                                  WheelCollideOutput &output,
                                                  const hknpWorld *world) const
{
    const float suspensionLength = vehicle->suspension->wheelParams[wheelIndex].length;
    const hknpVehicleInstance::WheelInfo &wheelInfo = vehicle->wheelsInfo[wheelIndex];
    output.contactPoint.separatingNormal =
        _mm_blend_ps(collector.hit.normal.quad, output.contactPoint.separatingNormal, 8);
    output.contactShapeKey = collector.hit.hitBodyInfo.shapeKey;
    output.contactBodyId = collector.hit.hitBodyInfo.bodyId;

    const float radius = vehicle->data->wheelParams[wheelIndex].radius;
    const float hitDistance = (suspensionLength + radius) * collector.hit.fraction;
    output.currentSuspensionLength = hitDistance - radius;
    output.contactPoint.position =
        _mm_add_ps(_mm_mul_ps(_mm_set1_ps(hitDistance), wheelInfo.suspensionDirectionWs),
                   wheelInfo.hardPointWs);
    lane(output.contactPoint.separatingNormal, 3) = output.currentSuspensionLength;

    const hknpBody &body = world->bodyManager.bodies[output.contactBodyId.value];
    output.contactFriction =
        world->materialLibrary->entries.elements[body.materialId.value].dynamicFriction.getReal();

    const Vec4 denominator =
        _mm_dp_ps(output.contactPoint.separatingNormal, wheelInfo.suspensionDirectionWs, 0x7f);
    const Vec4 clippingCos = _mm_set1_ps(vehicle->data->normalClippingAngleCos);
    if (_mm_ucomilt_ss(denominator, _mm_sub_ps(_mm_setzero_ps(), clippingCos))) {
        const hknpWorld *chassisWorld = vehicle->world;
        Vec4 chassisVelocity;
        chassisWorld->motionManager
            .motions[chassisWorld->bodyManager.bodies[vehicle->bodyId.value].motionId]
            .FUN_00157580(output.contactPoint.position, chassisVelocity);
        Vec4 groundVelocity;
        world->motionManager.motions[world->bodyManager.bodies[output.contactBodyId.value].motionId]
            .FUN_00157580(output.contactPoint.position, groundVelocity);
        const Vec4 projected = _mm_dp_ps(_mm_sub_ps(chassisVelocity, groundVelocity),
                                         output.contactPoint.separatingNormal, 0x7f);
        const Vec4 r = _mm_rcp_ps(denominator);
        const Vec4 inverse = _mm_mul_ps(r, _mm_sub_ps(D_14b4380, _mm_mul_ps(denominator, r)));
        const Vec4 scaling = _mm_sub_ps(_mm_setzero_ps(), inverse);
        output.suspensionClosingSpeed = _mm_cvtss_f32(_mm_mul_ps(projected, scaling));
        output.suspensionScalingFactor = _mm_cvtss_f32(scaling);
    } else {
        output.suspensionClosingSpeed = 0.0f;
        output.suspensionScalingFactor = 1.0f / vehicle->data->normalClippingAngleCos;
    }
}
