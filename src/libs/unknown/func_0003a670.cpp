/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the body keeps its center of mass, in its own space, in the
 * w lanes of its rotation's columns. */
void hknpBody::FUN_0003a670(const Vec4 &centerOfMassLocal)
{
    lane(transform.rotation.col0, 3) = lane(centerOfMassLocal, 0);
    lane(transform.rotation.col1, 3) = lane(centerOfMassLocal, 1);
    lane(transform.rotation.col2, 3) = lane(centerOfMassLocal, 2);
}

/* The motion's frame from the transform: the rotation's inverse packed,
 * the inverse's translation kept as the centre of mass (the setter above,
 * inline). */
// NONMATCHING: 46 of 66 (docs/NOTES.md, Round 64A): the base stores the
// centre of mass's lanes 1 and 2 through a general register (`vpextrd eax;
// vmovd xmm1, eax; vmovss`, as 0x3a690 does), the lanes of a local SROA
// widened to an integer, where this compile extracts them straight to memory;
// and the rotation's products and sums come out with their operands the
// other way round.
void hknpBody::FUN_0003a920()
{
    hkQTransformf bodyTransform;
    bodyTransform.rotation.FUN_0001a1c0(transform.rotation);
    bodyTransform.translation = transform.translation;

    hkQuaternion inverse;
    inverse.vec = _mm_xor_ps(bodyTransform.rotation.vec, _mm_setr_ps(-0.0f, -0.0f, -0.0f, 0.0f));

    /* Each lane times 30000 in the upper half, converted with saturation,
     * the sign bit flipped, the upper half kept. */
    const Vec4 scaled = _mm_mul_ps(inverse.vec, D_14b2060[48]);
    const __m128 overflow = _mm_cmple_ps(_mm_set1_ps(2147483648.0f), scaled);
    const __m128i converted = _mm_add_epi32(
        _mm_castps_si128(_mm_xor_ps(_mm_castsi128_ps(_mm_cvttps_epi32(scaled)), overflow)),
        _mm_castps_si128(D_14b41d0));
    motionToBodyRotation[0] = s16(_mm_extract_epi16(converted, 1));
    motionToBodyRotation[1] = s16(_mm_extract_epi16(converted, 3));
    motionToBodyRotation[2] = s16(_mm_extract_epi16(converted, 5));
    motionToBodyRotation[3] = s16(_mm_extract_epi16(converted, 7));

    hkVector4 centerOfMassLocal;
    centerOfMassLocal.quad =
        _mm_xor_ps(rotatedDir(inverse, bodyTransform.translation), _mm_set1_ps(-0.0f));
    FUN_0003a670(centerOfMassLocal.quad);
}
