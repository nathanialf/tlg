/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpMotion::FUN_00157a20(const Vec4 &velocity, const Vec4 &position)
{
    hkMatrix3 massMatrix;
    FUN_00157690(position, massMatrix);

    const Vec4 worldAngularVelocity = rotatedDir(orientation, angularVelocity);
    const Vec4 offset = _mm_sub_ps(position, centerOfMass);
    const Vec4 pointVelocity = _mm_add_ps(linearVelocity, cross3(worldAngularVelocity, offset));
    const Vec4 change = _mm_sub_ps(velocity, pointVelocity);
    const Vec4 impulse = _mm_add_ps(
        _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(change, change, _MM_SHUFFLE(0, 0, 0, 0)), massMatrix.col0),
            _mm_mul_ps(_mm_shuffle_ps(change, change, _MM_SHUFFLE(1, 1, 1, 1)), massMatrix.col1)),
        _mm_mul_ps(_mm_shuffle_ps(change, change, _MM_SHUFFLE(2, 2, 2, 2)), massMatrix.col2));

    const Vec4 inverseInertiaAndMass = loadHalves(inverseInertia);
    const Vec4 inverseMass =
        _mm_shuffle_ps(inverseInertiaAndMass, inverseInertiaAndMass, _MM_SHUFFLE(3, 3, 3, 3));
    linearVelocity = setXYZ_0(_mm_add_ps(linearVelocity, _mm_mul_ps(inverseMass, impulse)));
    const Vec4 angularImpulse = rotatedInverseDir(orientation, cross3(offset, impulse));
    angularVelocity =
        setXYZ_0(_mm_add_ps(angularVelocity, _mm_mul_ps(inverseInertiaAndMass, angularImpulse)));
}
