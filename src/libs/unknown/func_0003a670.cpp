/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the body keeps its center of mass, in its own space, in the
 * w lanes of its rotation's columns, each lane taken as a scalar and stored
 * as one (Havok's hkSimdReal store: inline, a lane past the first goes out
 * through a general register, `vpextrd eax; vmovd; vmovss`, 0x3a6df). */
void hknpBody::FUN_0003a670(const Vec4 &centerOfMassLocal)
{
    _mm_store_ss(&lane(transform.rotation.col0, 3), broadcast<0>(centerOfMassLocal));
    _mm_store_ss(&lane(transform.rotation.col1, 3), broadcast<1>(centerOfMassLocal));
    _mm_store_ss(&lane(transform.rotation.col2, 3), broadcast<2>(centerOfMassLocal));
}

/* The motion's frame from the transform: the rotation's inverse packed,
 * the inverse's translation kept as the centre of mass (the setter above,
 * inline). */
// NONMATCHING: 62 of 66 (size equal); the centre of mass's lanes go out as the base's since
// the setter stores scalars (above). Left: the rotation's products take their operands the
// other way round (`vmulps xmm3, xmm3, xmm1` and `vmulps xmm4, xmm0, xmm4` at 0x3a9a4, the dot
// product's and the sum's at 0x3a9e8 and 0x3a9fc): the base copies the translation into the
// local as an integer vector (`vmovdqa`, 0x3a948, the aggregate copy of an hkVector4) and
// Reassociate ranks its value as that load; here the copy is a float load. NOTES Round 64A
// and Round 80A.
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

/* The body placed in its motion's frame: the motion's centre of mass in the
 * body's space kept (the setter above, inline), then the rotation from the
 * body's orientation (the one given, else its rotation's) to the motion's
 * packed as 0x3a920 packs its own; the product written in each arm, its
 * blend sunk to the join (0x3a798). */
void hknpBody::FUN_0003a690(const hknpMotion &motion, const hkQuaternion *bodyOrientation)
{
    FUN_0003a670(transformInversePosition(transform, motion.centerOfMass));

    hkQuaternion motionToBody;
    if (bodyOrientation) {
        motionToBody.setInverseMul(*bodyOrientation, motion.orientation);
    } else {
        hkQuaternion orientation;
        orientation.FUN_0001a1c0(transform.rotation);
        motionToBody.setInverseMul(orientation, motion.orientation);
    }

    const Vec4 scaled = _mm_mul_ps(motionToBody.vec, D_14b2060[48]);
    const __m128 overflow = _mm_cmple_ps(_mm_set1_ps(2147483648.0f), scaled);
    const __m128i converted = _mm_add_epi32(
        _mm_castps_si128(_mm_xor_ps(_mm_castsi128_ps(_mm_cvttps_epi32(scaled)), overflow)),
        _mm_castps_si128(D_14b41d0));
    motionToBodyRotation[0] = s16(_mm_extract_epi16(converted, 1));
    motionToBodyRotation[1] = s16(_mm_extract_epi16(converted, 3));
    motionToBodyRotation[2] = s16(_mm_extract_epi16(converted, 5));
    motionToBodyRotation[3] = s16(_mm_extract_epi16(converted, 7));
}
