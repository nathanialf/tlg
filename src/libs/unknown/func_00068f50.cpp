/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The tyremarks' update for a step (derived reading): each wheel's point
 * pair, its strength in the w lanes, from the contact point lifted along the
 * normal and spread half the wheel's width along the chassis's right axis,
 * moved by the chassis's travel over the step. The contact normal is a named
 * value, so its load stays apart from the product (D30); the width is read
 * after the strength's branch and before the start point, so the product
 * takes it first (Reassociate's rank). */
void hknpTyremarksInfo::FUN_00068f50(const hknpVehicleInstance *vehicle, float deltaTime)
{
    const hknpWorld *world = vehicle->world;
    const hknpBody &chassis = world->bodyManager.bodies[vehicle->bodyId.value];
    const hknpMotion &motion = world->motionManager.motions[chassis.motionId];
    const Vec4 step = _mm_mul_ps(_mm_set1_ps(deltaTime), motion.linearVelocity);
    Vec4 right;
    FUN_00010ef0(right, chassis.transform.rotation, vehicle->data->chassisOrientation.col2);

    for (int i = 0; i < vehicle->data->numWheels; i++) {
        const hknpVehicleInstance::WheelInfo &wheel = vehicle->wheelsInfo[i];

        const Vec4 energy =
            _mm_sub_ps(_mm_set1_ps(wheel.skidEnergyDensity), _mm_set1_ps(minTyremarkEnergy));
        Vec4 strength = _mm_setzero_ps();
        if (_mm_ucomigt_ss(energy, _mm_setzero_ps())) {
            const Vec4 range =
                _mm_sub_ps(_mm_set1_ps(maxTyremarkEnergy), _mm_set1_ps(minTyremarkEnergy));
            const Vec4 r = _mm_rcp_ps(range);
            const Vec4 invRange =
                _mm_mul_ps(r, _mm_sub_ps(_mm_load_ps(D_14b4380), _mm_mul_ps(r, range)));
            strength =
                _mm_max_ps(_mm_mul_ps(_mm_mul_ps(energy, D_14b2060[13]), invRange), D_14b2060[13]);
        }

        const Vec4 width = simdFromFloat(vehicle->data->wheelParams[i].width);
        const Vec4 normal = wheel.contactPoint.separatingNormal;
        const Vec4 start =
            _mm_add_ps(_mm_mul_ps(normal, _mm_set1_ps(0.05f)), wheel.contactPoint.position);
        const Vec4 offset = _mm_mul_ps(_mm_mul_ps(width, D_14b2060[18]), right);
        const Vec4 left = _mm_blend_ps(_mm_add_ps(step, _mm_sub_ps(start, offset)), strength, 8);
        const Vec4 rightPoint =
            _mm_blend_ps(_mm_add_ps(step, _mm_add_ps(start, offset)), strength, 8);
        tyremarksWheel[i]->addTyremarkPoint(left, rightPoint);
    }
}
