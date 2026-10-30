/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpMotion::FUN_00157420(const hkDiagonalizedMassProperties &properties,
                              const hkQTransform &transform)
{
    FUN_00010fe0(centerOfMass, transform, properties.centerOfMass);

    const Vec4 q0 = transform.rotation.vec;
    const Vec4 q1 = properties.majorAxisSpace.vec;
    const Vec4 real0 = _mm_shuffle_ps(q0, q0, _MM_SHUFFLE(3, 3, 3, 3));
    const Vec4 real1 = _mm_shuffle_ps(q1, q1, _MM_SHUFFLE(3, 3, 3, 3));
    Vec4 imag = cross3(q0, q1);
    imag = _mm_add_ps(imag, _mm_mul_ps(real0, q1));
    imag = _mm_add_ps(imag, _mm_mul_ps(q0, real1));
    const Vec4 real = _mm_sub_ps(_mm_mul_ps(real0, real1), _mm_dp_ps(q0, q1, 0x7f));
    orientation.vec = _mm_blend_ps(imag, real, 8);

    const Vec4 inertia = _mm_blend_ps(properties.inertiaTensor, _mm_set1_ps(properties.mass), 8);
    storeHalves(inverseInertia, reciprocalOrZero(inertia));
}
