/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The angle and distance the bodies' times of impact widen by are the clamped
 * products of a zero (row 2 of the constant table): 255 over a right angle
 * rounded up, and the settings' vector at +0x60. */
void hknpWorld::FUN_0005da80(int motionId, float factor)
{
    if (motionId == 0) {
        return;
    }
    hknpMotion &motion = motionManager.motions[motionId];
    const Vec4 factors = _mm_set1_ps(factor);
    FUN_00157be0(motion, factors, solverInfo.vector20);

    const Vec4 zero = D_14b2060[2];
    const int angle = int(lane(zero, 0) * (255.0f / (HK_REAL_PI * 0.5f)) + 0.9999f);
    const u8 angleBits = u8(hkMath::clamp(angle, 0, 255));
    Vec4 distance = _mm_mul_ps(zero, solverInfo.vector60);
    distance = _mm_min_ps(_mm_max_ps(distance, _mm_setzero_ps()), _mm_set1_ps(65535.0f));
    const u16 timDistance = u16(_mm_extract_epi16(_mm_cvttps_epi32(distance), 0));

    const int firstBodyId = motion.firstAttachedBodyId;
    int bodyId = firstBodyId;
    do {
        FUN_000ce880(bodyId);
        hknpBody &body = bodyManager.bodies[bodyId];
        body.maxTimDistance += timDistance;
        body.timAngle = u8(hkMath::min2(body.timAngle + angleBits, 255));
        body.flags |= 0x2000;
        bodyId = body.nextAttachedBodyId;
    } while (bodyId != firstBodyId);
}
