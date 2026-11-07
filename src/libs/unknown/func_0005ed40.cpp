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

/* The magnitude of each lane (hkMath::fabs's form, cookbook 70). derived
 * name. */
static inline Vec4 absLanes(const Vec4 &v) /* derived name */
{
    const __m128i bits = _mm_castps_si128(v);
    return _mm_castsi128_ps(_mm_srli_epi32(_mm_add_epi32(bits, bits), 1));
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
        if (!allXYZ(_mm_cmple_ps(absLanes(_mm_sub_ps(velocity, motion.linearVelocity)),
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
