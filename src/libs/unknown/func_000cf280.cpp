/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The box a body's shape will have after a step (derived reading; 0x148720
 * calls it twice): the motion's centre moved by its velocity and its
 * orientation turned by half the step's angular velocity, normalized; the
 * body's own rotation in the motion (a packed quaternion, normalized) put
 * after it; the body's frame placed so that its centre of mass lands on the
 * moved centre; the shape's box under that frame. derived name. */
// NONMATCHING: 9 of 132, the size equal (584 bytes) and every value the
// base computes computed: the order is list-ilp's over one block of about
// 120 vector instructions (the base reads the motion's linear velocity
// first and keeps its centre unfolded in xmm9, loads the body's centre of
// mass words before the packed quaternion); NOTES "Round 78A".
void FUN_000cf280(const hknpBody &body, const hknpShape *shape, const hknpMotion &motion,
                  const Vec4 &deltaTime, hkAabb &aabbOut) /* derived name */
{
    const Vec4 center =
        _mm_add_ps(motion.centerOfMass, _mm_mul_ps(deltaTime, motion.linearVelocity));

    hkQuaternion turn;
    turn.vec = _mm_blend_ps(
        _mm_mul_ps(_mm_mul_ps(deltaTime, D_14b2060[18]), motion.angularVelocity), D_14b2060[3], 8);
    hkQuaternion orientation;
    orientation.setMul(motion.orientation, turn);
    orientation.normalize();

    const __m128i packed =
        _mm_loadl_epi64(reinterpret_cast<const __m128i *>(body.motionToBodyRotation));
    const __m128i bits =
        _mm_add_epi32(_mm_unpacklo_epi16(_mm_setzero_si128(), packed), _mm_castps_si128(D_14b41d0));
    hkQuaternion motionToBody;
    motionToBody.vec = _mm_mul_ps(_mm_cvtepi32_ps(bits), D_14b2060[49]);
    motionToBody.normalize();

    hkQuaternion bodyOrientation;
    bodyOrientation.setMul(orientation, motionToBody);

    hkTransform transform;
    transform.rotation.setRotation(bodyOrientation);
    const Vec4 centerOfMassLocal =
        _mm_setr_ps(lane(body.transform.rotation.col0, 3), lane(body.transform.rotation.col1, 3),
                    lane(body.transform.rotation.col2, 3), 0.0f);
    const Vec4 offset =
        _mm_add_ps(_mm_add_ps(_mm_mul_ps(broadcast<0>(centerOfMassLocal), transform.rotation.col0),
                              _mm_mul_ps(broadcast<1>(centerOfMassLocal), transform.rotation.col1)),
                   _mm_mul_ps(broadcast<2>(centerOfMassLocal), transform.rotation.col2));
    transform.translation = _mm_sub_ps(center, offset);
    shape->unknownVirtual7(reinterpret_cast<const Mat4 &>(transform), aabbOut);
}
