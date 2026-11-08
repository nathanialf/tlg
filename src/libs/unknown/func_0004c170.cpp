/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Eight zero bytes (rodata at 0x14bd980), the inverse inertia of a motion
 * of infinite mass. derived name. */
extern const hkHalf D_14bd980[4];

void hknpWorld::FUN_0004c170(int bodyId, int motionId, const hkQuaternion *motionOrientation)
{
    hknpBody &body = bodyManager.bodies[bodyId];
    hknpMotion &motion = motionManager.motions[motionId];
    body.motionId = motionId;
    if (motion.firstAttachedBodyId == 0x7fffffff) {
        motion.firstAttachedBodyId = bodyId;
        body.nextAttachedBodyId = bodyId;
    } else {
        hknpBody &first = bodyManager.bodies[motion.firstAttachedBodyId];
        body.nextAttachedBodyId = first.nextAttachedBodyId;
        first.nextAttachedBodyId = bodyId;
    }
    body.motionId = motionId;
    body.flags =
        (body.flags & ~(hknpBody::IS_STATIC | hknpBody::IS_DYNAMIC)) | hknpBody::IS_DYNAMIC;
    if (motion.solverId != 0 && FUN_00018180(motion.inverseInertia, D_14bd980, 8) == 0) {
        body.flags |= hknpBody::IS_KEYFRAMED;
    } else {
        body.flags &= ~hknpBody::IS_KEYFRAMED;
    }
    const hknpBodyQuality &quality = qualityLibrary->qualities[body.qualityId];
    if ((quality.requestedFlags & 0x10000) && (body.shape->flags & 2) && body.shape) {
        const float maxRotation = hkMath::max2(body.shape->unknownVirtual17() * 0.5f, 0.05f);
        motion.maxRotationPerStep.setReal(
            hkMath::min2(maxRotation, motion.maxRotationPerStep.getReal()));
    }
    const float lookAhead = lane(body.transform.translation, 3);
    if (lookAhead > 0.0f) {
        motion.maxLinearAccelerationDistancePerStep.setReal(
            _mm_min_ps(_mm_set1_ps(motion.maxLinearAccelerationDistancePerStep.getReal()),
                       _mm_set1_ps(lookAhead)));
    }
    if (motionOrientation) {
        body.FUN_0003a690(motion, motionOrientation);
    } else {
        hkQuaternion orientation;
        orientation.FUN_0001a1c0(body.transform.rotation);
        body.FUN_0003a690(motion, &orientation);
    }
    if (body.broadPhaseId != 0xffffffff) {
        FUN_000cd040(&body, &motion, &quality, &vector250, &solverInfo, &intSpaceUtil);
    }
    body.FUN_0003a820(motion.centerOfMass);
    const Vec4 lengthSquared = _mm_dp_ps(motion.linearVelocity, motion.linearVelocity, 0x7f);
    const Vec4 length = _mm_andnot_ps(_mm_cmple_ps(lengthSquared, _mm_setzero_ps()),
                                      _mm_mul_ps(lengthSquared, _mm_rsqrt_ps(lengthSquared)));
    const Vec4 distance = _mm_mul_ps(_mm_mul_ps(solverInfo.vector20, solverInfo.vector60), length);
    body.maxTimDistance = u16(_mm_cvtsi128_si32(_mm_cvttps_epi32(
        _mm_min_ps(_mm_max_ps(distance, _mm_setzero_ps()), _mm_set1_ps(65535.0f)))));
}
