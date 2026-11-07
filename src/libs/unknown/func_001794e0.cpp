/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The reciprocal's factor negated across the subtraction (`vsubps (d*r) -
 * 2; vmulps r`): DAGCombiner under the library line's unsafe algebra
 * (docs/DECISIONS.md D40). */

/* derived name: the hit body's material found, the cast's contact point
 * taken as the output's, its distance cleared; the material's friction, the body and shape
 * key; the hard point moved down the suspension by the hit's share of the
 * cast as the contact's position, the suspension's length less the wheel's
 * radius as its distance; then the suspension's closing speed and scaling
 * from the contact normal against the suspension's direction, as the ray
 * cast's (0x158e20), except that a normal facing away from the suspension
 * within the clipping angle is treated as no hit (slot 14). */
void hknpVehicleLinearCastWheelCollide::FUN_001794e0(const hknpVehicleInstance *vehicle,
                                                     u8 wheelIndex,
                                                     const hknpCollisionResult &result,
                                                     const hknpWorld *world,
                                                     WheelCollideOutput &output) const
{
    const float suspensionLength = vehicle->suspension->wheelParams[wheelIndex].length;
    const hknpVehicleInstance::WheelInfo &wheelInfo = vehicle->wheelsInfo[wheelIndex];
    const hknpBody &body = world->bodyManager.bodies[result.hitBodyInfo.bodyId.value];
    const hknpMaterial &material = world->materialLibrary->entries.elements[body.materialId.value];
    output.contactPoint.position = result.position.quad;
    output.contactPoint.separatingNormal = result.normal.quad;
    lane(output.contactPoint.separatingNormal, 3) = 0.0f;

    output.contactFriction = material.dynamicFriction.getReal();
    output.contactBodyId = result.hitBodyInfo.bodyId;
    output.contactShapeKey = result.hitBodyInfo.shapeKey;

    const float radius = vehicle->data->wheelParams[wheelIndex].radius;
    const float hitDistance = (suspensionLength + radius) * result.fraction;
    output.currentSuspensionLength = hitDistance - radius;
    output.contactPoint.position =
        _mm_add_ps(_mm_mul_ps(_mm_set1_ps(hitDistance), wheelInfo.suspensionDirectionWs),
                   wheelInfo.hardPointWs);
    lane(output.contactPoint.separatingNormal, 3) = output.currentSuspensionLength;

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
    } else if (_mm_ucomilt_ss(denominator, _mm_setzero_ps())) {
        FUN_00179700(vehicle, wheelIndex, output);
    } else {
        output.suspensionClosingSpeed = 0.0f;
        output.suspensionScalingFactor = 1.0f / vehicle->data->normalClippingAngleCos;
    }
}
