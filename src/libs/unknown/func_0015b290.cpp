/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void FUN_0015b290(const hknpBodyCinfo &bodyCinfo, hknpMotionCinfo &motionCinfo)
{
    const hknpMassDistribution *distribution =
        bodyCinfo.massDistribution ? &bodyCinfo.massDistribution->massDistribution : HK_NULL;
    hkDiagonalizedMassProperties properties;
    FUN_00161b40(bodyCinfo.shape, distribution, properties, bodyCinfo.mass);

    hkQTransform transform;
    transform.rotation.vec = bodyCinfo.orientation.vec;
    transform.translation = bodyCinfo.position;
    FUN_00010fe0(motionCinfo.centerOfMassWorld, transform, properties.centerOfMass);

    const Vec4 q0 = transform.rotation.vec;
    const Vec4 q1 = properties.majorAxisSpace.vec;
    const Vec4 real0 = _mm_shuffle_ps(q0, q0, _MM_SHUFFLE(3, 3, 3, 3));
    const Vec4 real1 = _mm_shuffle_ps(q1, q1, _MM_SHUFFLE(3, 3, 3, 3));
    Vec4 imag = cross3(q0, q1);
    imag = _mm_add_ps(imag, _mm_mul_ps(real0, q1));
    imag = _mm_add_ps(imag, _mm_mul_ps(q0, real1));
    const Vec4 real = _mm_sub_ps(_mm_mul_ps(real0, real1), _mm_dp_ps(q0, q1, 0x7f));
    motionCinfo.orientation.vec = _mm_blend_ps(imag, real, 8);

    float inverseMass = 0.0f;
    if (properties.mass != 0.0f) {
        inverseMass = 1.0f / properties.mass;
    }
    motionCinfo.inverseMass = inverseMass;
    motionCinfo.inverseInertiaLocal =
        _mm_blend_ps(reciprocalOrZero(properties.inertiaTensor), D_14b2060[3], 8);
    if (bodyCinfo.motionType == 1) {
        motionCinfo.inverseMass = 0.0f;
        motionCinfo.inverseInertiaLocal = _mm_setzero_ps();
    }

    motionCinfo.motionPropertiesId = bodyCinfo.motionPropertiesId;
    motionCinfo.linearVelocity = bodyCinfo.linearVelocity;
    motionCinfo.angularVelocity = bodyCinfo.angularVelocity;
}
