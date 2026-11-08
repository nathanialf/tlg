/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Defined beside its callers in the world's file: the impulse below holds
 * it inline (0x5ede0 to 0x5ee22), 0x1562a0 calls it. */
void hknpWorld::FUN_0005b490(int firstBodyId, void *argument)
{
    const hknpBodyQualityLibrary *qualities = qualityLibrary;
    int bodyId = firstBodyId;
    do {
        hknpBody &body = bodyManager.bodies[bodyId];
        FUN_000cd040(&body, argument, &qualities->qualities[body.qualityId], &vector250,
                     &solverInfo, &intSpaceUtil);
        bodyId = body.nextAttachedBodyId;
    } while (bodyId != firstBodyId);
}

void hknpWorld::FUN_0005e780(int bodyId, const Vec4 &impulse)
{
    const hknpBody &body = bodyManager.bodies[bodyId];
    if (body.flags & 2) {
        if (!(body.flags & 9)) {
            FUN_0004e0c0(bodyId);
        }
        hknpMotion &motion = motionManager.motions[body.motionId];
        const Vec4 inverseInertia = loadHalves(motion.inverseInertia);
        const Vec4 inverseMass =
            _mm_shuffle_ps(inverseInertia, inverseInertia, _MM_SHUFFLE(3, 3, 3, 3));
        motion.linearVelocity = _mm_add_ps(_mm_mul_ps(inverseMass, impulse), motion.linearVelocity);
        FUN_0005b490(bodyId, &motion);
        signals.bodyChangedSignal.fire(this, bodyId);
    }
}

void hknpWorld::FUN_0005e910(int bodyId, const Vec4 &impulse)
{
    const hknpBody &body = bodyManager.bodies[bodyId];
    if (body.flags & 2) {
        if (!(body.flags & 9)) {
            FUN_0004e0c0(bodyId);
        }
        hknpMotion &motion = motionManager.motions[body.motionId];
        const Vec4 localImpulse = rotatedInverseDir(motion.orientation, impulse);
        motion.angularVelocity = _mm_add_ps(
            _mm_mul_ps(loadHalves(motion.inverseInertia), localImpulse), motion.angularVelocity);
        FUN_0005b490(bodyId, &motion);
        signals.bodyChangedSignal.fire(this, bodyId);
    }
}

void hknpWorld::FUN_0005ed40(int bodyId, const Vec4 &impulse, const Vec4 &position)
{
    const hknpBody &body = bodyManager.bodies[bodyId];
    if (body.flags & 2) {
        if (!(body.flags & 9)) {
            FUN_0004e0c0(bodyId);
        }
        hknpMotion &motion = motionManager.motions[body.motionId];
        motion.FUN_00157a20(impulse, position);
        FUN_0005b490(bodyId, &motion);
        signals.bodyChangedSignal.fire(this, bodyId);
    }
}

void hknpWorld::FUN_0005eb00(int bodyId, const Vec4 &impulse, const Vec4 &position)
{
    const hknpBody &body = bodyManager.bodies[bodyId];
    if (body.flags & 2) {
        if (!(body.flags & 9)) {
            FUN_0004e0c0(bodyId);
        }
        hknpMotion &motion = motionManager.motions[body.motionId];
        motion.applyPointImpulse(impulse, position);
        FUN_0005b490(bodyId, &motion);
        signals.bodyChangedSignal.fire(this, bodyId);
    }
}

/* Whether a comparison holds in x, y and z (hkVector4Comparison's
 * allAreSet on the three lanes). derived name. */
static inline bool allXYZ(const Vec4 &comparison) /* derived name */
{
    const __m128 xyz = _mm_blend_ps(_mm_setzero_ps(), _mm_castsi128_ps(_mm_set1_epi32(-1)), 7);
    return _mm_testc_si128(_mm_castps_si128(_mm_and_ps(comparison, xyz)), _mm_castps_si128(xyz));
}

void hknpWorld::FUN_0005dfc0(int bodyId, const Vec4 &velocity)
{
    const hknpBody &body = bodyManager.bodies[bodyId];
    if (body.flags & 2) {
        hknpMotion &motion = motionManager.motions[body.motionId];
        if (!allXYZ(_mm_cmple_ps(hkMath::quadFabs(_mm_sub_ps(velocity, motion.linearVelocity)),
                                 D_14b2060[35]))) {
            if (!(body.flags & 9)) {
                FUN_0004e0c0(bodyId);
            }
            motion.linearVelocity = velocity;
            FUN_0005b490(bodyId, &motion);
            signals.bodyChangedSignal.fire(this, bodyId);
        }
    }
}

/* NONMATCHING: 136 of 158, size equal: list-ilp's order in the entry block.
 * The base takes the real part's splat and the velocity's load at the top
 * with the constants (xmm4 and xmm1, eight vector registers live, xmm8 the
 * mask) and the cross product's two products after them; here the products
 * come first and the splat right before its product, the vector pressure
 * under the scheduler's limit (5 of 10 at the splat's pick, so
 * RegPressureDiff never decides). The velocity read after the rotation is
 * worse (135). The rotation alone matches as 0x5df30. */
void hknpWorld::FUN_0005e1a0(int bodyId, const Vec4 &angularVelocity)
{
    const hknpBody &body = bodyManager.bodies[bodyId];
    if (body.flags & 2) {
        hknpMotion &motion = motionManager.motions[body.motionId];
        if (!allXYZ(_mm_cmple_ps(
                hkMath::quadFabs(_mm_sub_ps(
                    angularVelocity, rotatedDir(motion.orientation, motion.angularVelocity))),
                D_14b2060[35]))) {
            if (!(body.flags & 9)) {
                FUN_0004e0c0(bodyId);
            }
            motion.angularVelocity = rotatedInverseDir(motion.orientation, angularVelocity);
            FUN_0005b490(bodyId, &motion);
            signals.bodyChangedSignal.fire(this, bodyId);
        }
    }
}

void hknpWorld::FUN_0005dc50(int bodyId, const Vec4 &linearVelocity, const Vec4 &angularVelocity)
{
    const hknpBody &body = bodyManager.bodies[bodyId];
    if (body.flags & 2) {
        hknpMotion &motion = motionManager.motions[body.motionId];
        if (!allXYZ(
                _mm_cmple_ps(hkMath::quadFabs(_mm_sub_ps(linearVelocity, motion.linearVelocity)),
                             D_14b2060[35])) ||
            !allXYZ(_mm_cmple_ps(
                hkMath::quadFabs(_mm_sub_ps(
                    angularVelocity, rotatedDir(motion.orientation, motion.angularVelocity))),
                D_14b2060[35]))) {
            if (!(body.flags & 9)) {
                FUN_0004e0c0(bodyId);
            }
            motion.linearVelocity = linearVelocity;
            motion.angularVelocity = rotatedInverseDir(motion.orientation, angularVelocity);
            FUN_0005b490(bodyId, &motion);
            signals.bodyChangedSignal.fire(this, bodyId);
        }
    }
}

// NONMATCHING: 153 of 192 (810 bytes, the size equal; 38 lines of the side by side differ),
// the blocks the base's. Left: the registers of the body array and its index (r13, r15 here,
// r15, rbx in the base, greedy's order); the look-ahead's store addressed from the
// translation, `lea rax, [r15+rbx+0x30]; vmovss [rax+0xc]` (0x5fe63), where this folds the
// whole offset; the cage's two shifts and the update's three addresses scheduled the other
// way (0x5feba to 0x5ff05); and in the sweep the box conversion's multiplies take the scale
// second (0x5ffee, 0x5fff6), Reassociate's rank order of the two operands (lower first) over
// this IR putting the scale's load below the sum.
void hknpWorld::FUN_0005fdd0(int bodyId, float distance, const Vec4 &tempExpansionVelocity)
{
    hknpBody &body = bodyManager.bodies[bodyId];
    if (distance == *body.lookAheadDistance()) {
        const Vec4 xyz = _mm_blend_ps(_mm_setzero_ps(), _mm_castsi128_ps(_mm_set1_epi32(-1)), 7);
        if (_mm_testc_si128(_mm_castps_si128(_mm_and_ps(
                                _mm_cmpeq_ps(tempExpansionVelocity, _mm_setzero_ps()), xyz)),
                            _mm_castps_si128(xyz))) {
            return;
        }
    }
    if (body.flags & hknpBody::IS_STATIC) {
        return;
    }
    if (!(body.flags & (hknpBody::IS_STATIC | hknpBody::IS_ACTIVE))) {
        FUN_0004e0c0(bodyId);
    }

    if (distance > 0.0f) {
        *body.lookAheadDistance() = distance;
        hknpMotion &motion = motionManager.motions[body.motionId];
        const float maxDistance = *bodyManager.bodies[bodyId].lookAheadDistance();
        hkHalf maxStep;
        if (maxDistance > 0.0f) {
            maxStep.setReal(hkMath::min2(maxDistance, 1.84467265e19f));
        } else {
            maxStep.value = 0x5f7f; /* the largest half */
        }
        motion.maxLinearAccelerationDistancePerStep = maxStep;
        const __m128i halves =
            _mm_packs_epi32(_mm_srai_epi32(_mm_castps_si128(tempExpansionVelocity), 16),
                            _mm_srai_epi32(_mm_castps_si128(tempExpansionVelocity), 16));
        const u64 cage = _mm_cvtsi128_si64(halves);
        motion.linearVelocityCage[0].value = s16(cage);
        motion.linearVelocityCage[1].value = s16(cage >> 16);
        motion.linearVelocityCage[2].value = s16(cage >> 32);
        FUN_0005b490(bodyId, &motion);
    } else {
        const Vec4 sweep = _mm_mul_ps(solverInfo.vector20, tempExpansionVelocity);
        int id = bodyId;
        do {
            hknpBody &attached = bodyManager.bodies[id];
            hkAabb aabb;
            intSpaceUtil.restoreAabb(attached.aabb, aabb);
            aabb.max = _mm_max_ps(_mm_add_ps(sweep, aabb.max), aabb.max);
            aabb.min = _mm_min_ps(_mm_add_ps(sweep, aabb.min), aabb.min);
            intSpaceUtil.convertAabb(aabb, attached.aabb);
            id = attached.nextAttachedBodyId;
        } while (id != bodyId);
    }
    signals.bodyChangedSignal.fire(this, bodyId);
}
