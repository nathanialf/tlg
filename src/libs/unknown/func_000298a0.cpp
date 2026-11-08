/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The inertia of a mass shifted away from its centre by an offset, added
 * in (the parallel axis theorem): the mass times the offset's squared
 * length less its outer product (derived name). */
static inline void addShiftedInertia(const Vec4 &shift, const Vec4 &mass, hkMatrix3 &inertia)
{
    const Vec4 negativeMass = _mm_sub_ps(_mm_setzero_ps(), mass);
    const Vec4 squared = _mm_mul_ps(shift, shift);
    const Vec4 sums = _mm_add_ps(_mm_shuffle_ps(squared, squared, _MM_SHUFFLE(1, 0, 0, 1)),
                                 _mm_shuffle_ps(squared, squared, _MM_SHUFFLE(1, 1, 2, 2)));
    const Vec4 diagonal = _mm_blend_ps(
        _mm_xor_ps(_mm_mul_ps(sums, negativeMass), _mm_set1_ps(-0.0f)), _mm_setzero_ps(), 8);
    const Vec4 products = _mm_mul_ps(
        _mm_mul_ps(shift, _mm_shuffle_ps(shift, shift, _MM_SHUFFLE(3, 0, 2, 1))), negativeMass);
    inertia.col0 = _mm_add_ps(
        _mm_blend_ps(_mm_shuffle_ps(products, products, _MM_SHUFFLE(2, 2, 0, 0)), diagonal, 9),
        inertia.col0);
    inertia.col1 = _mm_add_ps(
        _mm_blend_ps(_mm_shuffle_ps(products, products, _MM_SHUFFLE(1, 1, 0, 0)), diagonal, 0xa),
        inertia.col1);
    inertia.col2 = _mm_add_ps(
        _mm_blend_ps(_mm_shuffle_ps(products, products, _MM_SHUFFLE(3, 2, 1, 2)), diagonal, 0xc),
        inertia.col2);
}

/* derived name: the mass properties of a group of elements, Havok's
 * hkInertiaTensorComputer::combineMassProperties by its shape: the masses,
 * the volumes and the centre of mass summed over the elements in the
 * group's frame, then each element's inertia turned into that frame and
 * shifted to the group's centre; a group without mass fails. */
// NONMATCHING: 121 of 139, size equal: (1) the first loop's sums in other registers (the base:
// zero xmm2, volume xmm0, mass xmm1, centre xmm3) and the volume's add before the mass's
// broadcast; (2) the shift's two products take the negated mass second in the base
// (`vmulps xmm0, xmm0, xmm2`), first here: Reassociate ranks the mass's load below the sums'
// expression (3.3 Reassociate.cpp:1837-1852); the base's mass operand ranks higher.
// NOTES Round 79A.
hkResult FUN_000298a0(const hkArray<hkMassElement> &elements, hkMassProperties &result)
{
    float groupVolume = 0.0f;
    Vec4 groupMass = _mm_setzero_ps();
    Vec4 groupCenterOfMass = _mm_setzero_ps();
    for (int i = 0; i < elements.getSize(); i++) {
        const hkMassElement &element = elements[i];
        const Vec4 centerOfMass =
            transformPosition(element.transform, element.properties.centerOfMass);
        groupVolume += element.properties.volume;
        const Vec4 mass = _mm_set1_ps(element.properties.mass);
        groupCenterOfMass = _mm_add_ps(groupCenterOfMass, _mm_mul_ps(centerOfMass, mass));
        groupMass = _mm_add_ps(groupMass, mass);
    }
    if (!_mm_ucomigt_ss(groupMass, _mm_setzero_ps())) {
        return HK_FAILURE;
    }
    groupCenterOfMass = _mm_mul_ps(groupCenterOfMass, _mm_div_ps(D_14b2060[3], groupMass));
    result.centerOfMass = groupCenterOfMass;
    result.mass = _mm_cvtss_f32(groupMass);
    result.volume = groupVolume;
    result.inertiaTensor.setZero();
    for (int i = 0; i < elements.getSize(); i++) {
        hkMatrix3 inertia;
        inertia = elements[i].properties.inertiaTensor;
        inertia.FUN_0001aaa0(elements[i].transform.rotation);
        const Vec4 shift = _mm_sub_ps(
            transformPosition(elements[i].transform, elements[i].properties.centerOfMass),
            groupCenterOfMass);
        addShiftedInertia(shift, _mm_set1_ps(elements[i].properties.mass), inertia);
        result.inertiaTensor.FUN_0001af70(inertia);
    }
    return HK_SUCCESS;
}
