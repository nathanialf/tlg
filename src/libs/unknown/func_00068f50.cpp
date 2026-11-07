/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

// NONMATCHING: 494 bytes against 502. The base keeps the load of the Newton
// step's two (0x14b4380) inside the strength's branch, only its address
// hoisted (`lea r8` before the loop, `vmovaps xmm7, [r8]` at 0x69049), where
// LICM hoists the load here: 3.3's isSafeToSpeculativelyExecute takes a load
// of a global of known size as dereferenceable (the table D_14b2060's rows 13
// and 18 are hoisted in the base as here), so the base's two is not a sized
// global in its compile (an unsized table or another declaration); the
// register assignment of the loop follows. A literal `_mm_set1_ps(2.0f)`
// stays a constant-pool load MachineLICM hoists (docs/NOTES.md, Round 75B).
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
        if (_mm_cvtss_f32(energy) > 0.0f) {
            const Vec4 range =
                _mm_sub_ps(_mm_set1_ps(maxTyremarkEnergy), _mm_set1_ps(minTyremarkEnergy));
            const Vec4 r = _mm_rcp_ps(range);
            const Vec4 invRange = _mm_mul_ps(r, _mm_sub_ps(D_14b4380, _mm_mul_ps(r, range)));
            strength =
                _mm_max_ps(_mm_mul_ps(_mm_mul_ps(energy, D_14b2060[13]), invRange), D_14b2060[13]);
        }

        const Vec4 start =
            _mm_add_ps(_mm_mul_ps(wheel.contactPoint.separatingNormal, _mm_set1_ps(0.05f)),
                       wheel.contactPoint.position);
        const Vec4 offset = _mm_mul_ps(
            _mm_mul_ps(_mm_set1_ps(vehicle->data->wheelParams[i].width), D_14b2060[18]), right);
        const Vec4 left = _mm_blend_ps(_mm_add_ps(step, _mm_sub_ps(start, offset)), strength, 8);
        const Vec4 rightPoint =
            _mm_blend_ps(_mm_add_ps(step, _mm_add_ps(start, offset)), strength, 8);
        tyremarksWheel[i]->addTyremarkPoint(left, rightPoint);
    }
}
