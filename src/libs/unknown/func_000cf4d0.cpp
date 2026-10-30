/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The order of the reads is the base's: Reassociate ranks each product's
 * operands by the position of the loads and calls they come from (the step
 * after the linear bound's maximum and the angular speed, cookbook 280). */
void FUN_000cf4d0(const hknpBody &body, const hknpMotion &motion, const Vec4 &distance,
                  const hknpSolverInfo &solverInfo, Vec4 &linearStepOut, Vec4 &cageStepOut,
                  Vec4 &angularBoundOut, Vec4 &linearBoundOut)
{
    const Vec4 tolerance = _mm_set1_ps(1.01f);
    const Vec4 lookAhead = _mm_max_ps(simdFromFloat(lane(body.transform.translation, 3)),
                                      _mm_mul_ps(distance, D_14b2060[18]));
    const Vec4 linearSpeed = length3Fast(motion.linearVelocity);
    const Vec4 cage = loadHalves3(motion.linearVelocityCage);
    const Vec4 maxSpeed = _mm_max_ps(_mm_mul_ps(linearSpeed, tolerance), length3Fast(cage));
    const Vec4 angularSpeed = length3Fast(motion.angularVelocity);
    const Vec4 step = solverInfo.vector20;
    const Vec4 angle =
        _mm_min_ps(_mm_mul_ps(step, _mm_mul_ps(angularSpeed, tolerance)), D_14b2060[3]);
    const Vec4 radius = _mm_set1_ps(body.radiusOfComCenteredBoundingSphere.getReal());
    const Vec4 angularBound = _mm_add_ps(lookAhead, _mm_mul_ps(angle, radius));

    linearStepOut = _mm_mul_ps(motion.linearVelocity, step);
    cageStepOut = _mm_mul_ps(cage, step);
    angularBoundOut = angularBound;
    linearBoundOut = _mm_mul_ps(maxSpeed, step);
}
