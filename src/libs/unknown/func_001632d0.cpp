/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* An impulse applied to an accumulator's linear velocity, scaled by the
 * motion's inverse mass (derived name). */
static inline void applyLinearImpulse(hknpVehicleInstance::VelocityAccumulator &accumulator,
                                      const hknpMotion &motion, const Vec4 &impulse)
{
    const Vec4 inverseMass = broadcast<3>(loadHalves(motion.inverseInertia));
    accumulator.linearVelocity =
        _mm_add_ps(accumulator.linearVelocity, _mm_mul_ps(impulse, inverseMass));
}

/* An impulse at a point applied to an accumulator's angular velocity
 * (derived name): its moment about the motion's centre of mass taken into
 * the body's frame, scaled by the inverse inertia and taken back. */
static inline void applyAngularImpulse(hknpVehicleInstance::VelocityAccumulator &accumulator,
                                       const hknpBody &body, const hknpMotion &motion,
                                       const Vec4 &impulse, const Vec4 &position)
{
    const hkMatrix3 &rotation = body.transform.rotation;
    const Vec4 c0 = rotation.getColumn(0);
    const Vec4 c1 = rotation.getColumn(1);
    const Vec4 c2 = rotation.getColumn(2);
    const Vec4 moment = cross3(_mm_sub_ps(position, motion.centerOfMass), impulse);
    const Vec4 local =
        _mm_or_ps(_mm_or_ps(_mm_dp_ps(c0, moment, 0x71), _mm_dp_ps(c1, moment, 0x72)),
                  _mm_dp_ps(c2, moment, 0x74));
    const Vec4 scaled = _mm_mul_ps(local, loadHalves(motion.inverseInertia));
    const Vec4 world = _mm_add_ps(
        _mm_mul_ps(broadcast<2>(scaled), c2),
        _mm_add_ps(_mm_mul_ps(broadcast<0>(scaled), c0), _mm_mul_ps(broadcast<1>(scaled), c1)));
    accumulator.angularVelocity = _mm_add_ps(world, accumulator.angularVelocity);
}

// NONMATCHING: Reassociate's rank order, 132 of 188, 875 bytes as the base: the ground's force
// feedback product is (impulse, broadcast) where the base multiplies (broadcast, impulse), the
// loop-top impulse ranked below the ground block's load; the mass block's list-ilp order, the
// ground angular part's registers, the chassis splat's register (xmm2 for xmm3, instruction 35)
// and the latch's increments (r8 after rbx) follow.
void hknpVehicleInstance::FUN_001632d0(float deltaTime,
                                       const hkArray<float> &suspensionForceAtWheel,
                                       const u32 *groundBodyIds,
                                       hknpVehicleFrictionSolverParams &params,
                                       Vec4 *suspensionForcesAtWheel)
{
    const hknpBody &chassis = world->bodyManager.bodies[bodyId.value];
    const hknpMotion &chassisMotion = world->motionManager.motions[chassis.motionId];

    for (int i = 0; i < getNumWheels(); i++) {
        const WheelInfo &wheel = wheelsInfo[i];
        const float force = suspensionForceAtWheel[i];
        Vec4 impulse =
            _mm_mul_ps(_mm_set1_ps(force * deltaTime), wheel.contactPoint.separatingNormal);
        const hknpBodyId groundId = wheel.contactBodyId;

        /* The chassis pushed up at the hard point. */
        if (force > 0.0f) {
            applyLinearImpulse(params.chassis, chassisMotion, impulse);
            applyAngularImpulse(params.chassis, chassis, chassisMotion, impulse, wheel.hardPointWs);
        }

        if (groundId.value != 0x7fffffff) {
            const hknpBody &ground = world->bodyManager.bodies[groundId.value];
            const hknpMotion &groundMotion = world->motionManager.motions[ground.motionId];
            if (groundMotion.solverId == 0) {
                continue;
            }

            /* The ground pushed down, its impulse limited by its mass and
             * the wheel's maximum acceleration of it. */
            const Vec4 mass =
                simdReciprocalOrZero(broadcast<3>(loadHalves(groundMotion.inverseInertia)));
            const hknpVehicleDataWheelComponentParams &wheelParams = data->wheelParams[i];
            const int axle = wheelParams.axle;
            impulse =
                _mm_xor_ps(_mm_mul_ps(_mm_set1_ps(wheelParams.forceFeedbackMultiplier), impulse),
                           _mm_set1_ps(-0.0f));
            const Vec4 maxImpulse = _mm_set1_ps(_mm_cvtss_f32(mass) *
                                                wheelParams.maxContactBodyAcceleration * deltaTime);
            const Vec4 lengthSquared = _mm_dp_ps(impulse, impulse, 0x7f);
            if (_mm_ucomilt_ss(_mm_mul_ps(maxImpulse, maxImpulse), lengthSquared)) {
                impulse = _mm_mul_ps(impulse, _mm_mul_ps(maxImpulse, lengthInverse3(impulse)));
            }

            if (groundId.value != groundBodyIds[axle]) {
                suspensionForcesAtWheel[i] = impulse;
                continue;
            }
            applyLinearImpulse(*params.axleParams[axle].groundObject, groundMotion, impulse);
            applyAngularImpulse(*params.axleParams[axle].groundObject,
                                world->bodyManager.bodies[groundId.value], groundMotion, impulse,
                                wheel.hardPointWs);
        }
        suspensionForcesAtWheel[i] = _mm_setzero_ps();
    }
}
