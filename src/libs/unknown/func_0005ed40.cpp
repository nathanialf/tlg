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
