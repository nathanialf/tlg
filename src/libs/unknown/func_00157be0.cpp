/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void FUN_00157be0(hknpMotion &motion, const Vec4 &factor, const Vec4 &deltaTime) /* derived name */
{
    motion.integrationFactor.setReal(
        _mm_mul_ps(_mm_set1_ps(motion.integrationFactor.getReal()), factor));
    const hkVector4 linearVelocity = motion.previousLinearVelocity;
    const hkVector4 angularVelocity = motion.previousAngularVelocity;
    const Vec4 f = factor;
    const Vec4 step = _mm_sub_ps(_mm_mul_ps(f, deltaTime), deltaTime);
    motion.previousLinearVelocity.quad = _mm_mul_ps(f, linearVelocity.quad);
    motion.previousAngularVelocity.quad = _mm_mul_ps(f, angularVelocity.quad);
    FUN_000cd870(linearVelocity.quad, angularVelocity.quad, step, motion);
}
