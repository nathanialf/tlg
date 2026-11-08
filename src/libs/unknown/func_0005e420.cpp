/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: list-ilp order (one load, 189 of 190 instructions in place, 861 bytes as the base):
// after the rotation's quaternion the base loads the table's one before zeroing the register the
// normalization compares with; here the zero comes first. The zero is also the phi's incoming value
// for a rotation without an axis, so its CopyToReg (priority 0, scheduled last bottom-up) lifts the
// zero's height to 40 against the load's 11 and the ILP height rule (ScheduleDAGRRList.cpp:2655)
// takes the load first (a85/e420.sched). Setting the velocities in each arm removes this order but
// duplicates the tail (876 bytes); the lead is a form whose zero sits in its own block.
void hknpWorld::FUN_0005e420(int bodyId, const Vec4 &targetPosition,
                             const hkQuaternion &targetOrientation, float deltaTime)
{
    const hknpBody &body = bodyManager.bodies[bodyId];
    const hknpMotion &motion = motionManager.motions[body.motionId];

    const Vec4 dt = _mm_set1_ps(deltaTime);
    const Vec4 r = _mm_rcp_ps(dt);
    const Vec4 invDeltaTime = _mm_mul_ps(r, _mm_sub_ps(_mm_load_ps(D_14b4380), _mm_mul_ps(dt, r)));

    /* The centre of mass in the body's space, kept in the w lanes of the
     * rotation's columns. */
    const Vec4 centerOfMassLocal = setFromScalars(
        broadcast<3>(body.transform.rotation.col0), broadcast<3>(body.transform.rotation.col1),
        broadcast<3>(body.transform.rotation.col2), broadcast<3>(body.transform.rotation.col2));
    const Vec4 targetCenterOfMass =
        _mm_add_ps(rotatedDir(targetOrientation, centerOfMassLocal), targetPosition);
    Vec4 linearVelocity;
    Vec4 angularVelocity;
    linearVelocity = _mm_mul_ps(invDeltaTime, _mm_sub_ps(targetCenterOfMass, motion.centerOfMass));
    linearVelocity = _mm_blend_ps(linearVelocity, D_14b2060[2], 8);

    hkQuaternion currentOrientation;
    currentOrientation.FUN_0001a1c0(body.transform.rotation);
    hkQuaternion quatDif;
    {
        const Vec4 a = targetOrientation.vec;
        const Vec4 b = currentOrientation.vec;
        const Vec4 xyz = _mm_add_ps(_mm_mul_ps(a, broadcast<3>(b)),
                                    _mm_sub_ps(cross3(b, a), _mm_mul_ps(broadcast<3>(a), b)));
        const Vec4 q = _mm_blend_ps(xyz, _mm_dp_ps(a, b, 0xff), 8);
        const Vec4 lengthSquared = _mm_dp_ps(q, q, 0xff);
        const Vec4 invLength = _mm_div_ps(D_14b2060[3], _mm_sqrt_ps(lengthSquared));
        const Vec4 lengthIsZero = _mm_cmple_ps(lengthSquared, _mm_setzero_ps());
        quatDif.vec = _mm_mul_ps(q, _mm_andnot_ps(lengthIsZero, invLength));
    }

    if (_mm_cvtss_f32(_mm_dp_ps(quatDif.vec, quatDif.vec, 0x7f)) > _mm_cvtss_f32(D_14b2060[36])) {
        float angle = quatDif.FUN_0001a0a0();
        if (angle < 0.244f) {
            angle = 2.0f * hkMath::asin(_mm_cvtss_f32(length3(quatDif.vec)));
            if (angle < 1.7453292e-5f) {
                angle = 0.0f;
            }
        }
        const Vec4 axis =
            _mm_xor_ps(normalized3(quatDif.vec),
                       _mm_castsi128_ps(_mm_slli_epi32(
                           _mm_srli_epi32(_mm_castps_si128(_mm_cmplt_ps(broadcast<3>(quatDif.vec),
                                                                        _mm_setzero_ps())),
                                          31),
                           31)));
        angularVelocity = _mm_mul_ps(_mm_mul_ps(invDeltaTime, _mm_set1_ps(angle)), axis);
    } else {
        angularVelocity = _mm_setzero_ps();
    }
    FUN_0005dc50(bodyId, linearVelocity, angularVelocity);
}
