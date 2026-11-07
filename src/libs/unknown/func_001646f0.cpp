/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* A direction taken through a rotation given by its columns. derived
 * name. */
static inline Vec4 rotated(const Vec4 *columns, const Vec4 &v)
{
    const Vec4 c0 = columns[0];
    const Vec4 c1 = columns[1];
    const Vec4 c2 = columns[2];
    return _mm_add_ps(_mm_add_ps(_mm_mul_ps(broadcast<0>(v), c0), _mm_mul_ps(broadcast<1>(v), c1)),
                      _mm_mul_ps(broadcast<2>(v), c2));
}

/* A body's velocities in its accumulator damped by its motion's properties
 * over the time (each scaled by one less the time times its damping, at
 * least zero), handed out, the angular one then taken through the
 * accumulator's rotation. derived name. */
static inline void dampVelocities(const hknpWorld *world, const hknpMotion &motion,
                                  hknpVehicleInstance::VelocityAccumulator *accumulator,
                                  const Vec4 &one, const Vec4 &dt, Vec4 &linearVelocityOut,
                                  Vec4 &angularVelocityOut)
{
    const hknpMotionProperties &properties =
        world->motionPropertiesLibrary->entries.elements[motion.motionPropertiesId];
    const Vec4 linearDamping = _mm_set1_ps(properties.linearDamping);
    const Vec4 angularDamping = _mm_set1_ps(properties.angularDamping);
    const Vec4 zero = _mm_setzero_ps();
    accumulator->linearVelocity =
        _mm_mul_ps(_mm_max_ps(zero, _mm_sub_ps(one, _mm_mul_ps(dt, linearDamping))),
                   accumulator->linearVelocity);
    accumulator->angularVelocity =
        _mm_mul_ps(_mm_max_ps(zero, _mm_sub_ps(one, _mm_mul_ps(dt, angularDamping))),
                   accumulator->angularVelocity);
    linearVelocityOut = accumulator->linearVelocity;
    angularVelocityOut = accumulator->angularVelocity;
    accumulator->angularVelocity = rotated(accumulator->rotation, accumulator->angularVelocity);
}

void hknpVehicleInstance::FUN_001646f0(const int *bodyIds, BodyEntry *entries,
                                       Vec4 *linearVelocitiesOut, Vec4 *angularVelocitiesOut,
                                       float deltaTime)
{
    const Vec4 one = D_14b2060[3];
    const Vec4 dt = _mm_set1_ps(deltaTime);

    /* The chassis, when its motion has a solver id. */
    if (bodyIds[0] != 0x7fffffff) {
        const hknpBody &body = world->bodyManager.bodies[bodyIds[0]];
        const hknpMotion &motion = world->motionManager.motions[body.motionId];
        if (motion.solverId != 0) {
            dampVelocities(world, motion, entries[0].accumulator, one, dt, linearVelocitiesOut[0],
                           angularVelocitiesOut[0]);
        }
    }

    /* The other body, when it moves and is not the chassis. */
    if (bodyIds[1] != 0x7fffffff) {
        const hknpBody &body = world->bodyManager.bodies[bodyIds[1]];
        if (!(body.flags & hknpBody::IS_STATIC) && bodyIds[1] != bodyIds[0]) {
            const hknpMotion &motion = world->motionManager.motions[body.motionId];
            dampVelocities(world, motion, entries[1].accumulator, one, dt, linearVelocitiesOut[1],
                           angularVelocitiesOut[1]);
        }
    }
}
