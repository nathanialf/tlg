/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: a solid box's mass properties over bounds (hknpShape's
 * slot 28 default, 0x6fc70, hands it the shape's own): the half extents,
 * an epsilon on a flat axis, the box at unit mass, the centre the bounds'
 * middle, no rotation, then the mass set as the capsule's is (0x1683d0). */
hkResult FUN_00168230(const MassConfig00168340 &config, const hkAabb &aabb,
                      hkDiagonalizedMassProperties &propertiesOut)
{
    Vec4 halfExtents = _mm_mul_ps(_mm_sub_ps(aabb.max, aabb.min), D_14b2060[18]);
    const Vec4 flat = _mm_cmpeq_ps(halfExtents, _mm_setzero_ps());
    halfExtents =
        _mm_add_ps(halfExtents, _mm_and_ps(flat, _mm_mul_ps(D_14b2060[35], D_14b2060[6])));
    FUN_00028ac0(halfExtents, 1.0f, propertiesOut.inertiaTensor, propertiesOut.volume);
    propertiesOut.centerOfMass =
        _mm_add_ps(aabb.max, _mm_mul_ps(D_14b2060[18], _mm_sub_ps(aabb.min, aabb.max)));
    propertiesOut.majorAxisSpace.vec = D_14b2060[32];
    float mass = config.massOrNegativeDensity;
    if (mass < 0.0f) {
        mass = -(mass * propertiesOut.volume);
    }
    propertiesOut.inertiaTensor =
        _mm_mul_ps(_mm_set1_ps(mass * config.inertiaFactor), propertiesOut.inertiaTensor);
    propertiesOut.mass = mass;
    return HK_SUCCESS;
}
