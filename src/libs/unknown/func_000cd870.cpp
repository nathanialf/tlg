/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_hk_reflect.h"

/* One lane of a vector in every lane (derived name). */
template <int I> static inline Vec4 splat(const Vec4 &v) /* derived name */
{
    return _mm_shuffle_ps(v, v, _MM_SHUFFLE(I, I, I, I));
}

/* derived name: the motion moved on by a time step: its centre of mass
 * along the linear velocity, its orientation turned by the half-angle
 * quaternion of the angular velocity and renormalized. */
void FUN_000cd870(const Vec4 &linearVelocity, const Vec4 &angularVelocity, const Vec4 &deltaTime,
                  hknpMotion &motion) /* derived name */
{
    const Vec4 dt = deltaTime;
    const Vec4 turn =
        _mm_blend_ps(_mm_mul_ps(_mm_mul_ps(dt, D_14b2060[18]), angularVelocity), D_14b2060[3], 8);
    const Vec4 position = _mm_add_ps(_mm_mul_ps(dt, linearVelocity), motion.centerOfMass);
    const Vec4 q = motion.orientation.vec;
    const Vec4 turnW = splat<3>(turn);
    const Vec4 qW = splat<3>(q);
    const Vec4 real = _mm_sub_ps(_mm_mul_ps(turnW, qW), _mm_dp_ps(q, turn, 0x7f));
    const Vec4 imag =
        _mm_add_ps(_mm_mul_ps(turnW, q), _mm_add_ps(_mm_mul_ps(turn, qW), cross3(q, turn)));
    const Vec4 r = _mm_blend_ps(imag, real, 8);
    motion.orientation.vec =
        _mm_mul_ps(r, _mm_div_ps(D_14b2060[3], _mm_sqrt_ps(_mm_dp_ps(r, r, 0xff))));
    motion.centerOfMass = position;
}
