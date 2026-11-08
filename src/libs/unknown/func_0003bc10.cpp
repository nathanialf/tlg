/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The velocity relative to the surface steered toward the desired one in a
 * frame of the surface (the tangent across the forward and up directions,
 * the binormal, the normal), the change limited by the gain and the
 * largest change allowed; nothing when forward and up are parallel. With
 * the flag, the desired velocity is taken from the forward and right
 * directions into the surface's plane at its own speed. */
void FUN_0003bc10(const CharacterMovementInput &input, Vec4 &velocityOut)
{
    hkMatrix3 surfaceFrame;
    {
        Vec4 binormal = cross3(input.forward, input.up);
        if (_mm_cvtss_f32(_mm_dp_ps(binormal, binormal, 0x7f)) < _mm_cvtss_f32(D_14b2060[35])) {
            return;
        }
        binormal = normalized3(binormal);
        const Vec4 tangent = normalized3(cross3(binormal, input.surfaceNormal));
        binormal = normalized3(cross3(tangent, input.surfaceNormal));
        surfaceFrame.col0 = tangent;
        surfaceFrame.col1 = binormal;
        surfaceFrame.col2 = input.surfaceNormal;
    }

    Vec4 relative = _mm_sub_ps(input.currentVelocity, input.surfaceVelocity);
    FUN_00010f20(relative, surfaceFrame, relative);

    Vec4 diff;
    if (input.flag68) {
        const Vec4 right = cross3(input.up, input.forward);
        const Vec4 desired = input.desiredVelocity;
        const Vec4 local =
            setFromScalars(negateScalar(_mm_dp_ps(desired, input.forward, 0x7f)),
                           _mm_dp_ps(desired, right, 0x7f), D_14b2060[2], D_14b2060[2]);
        diff = _mm_sub_ps(_mm_mul_ps(length3(desired), normalized3(local)), relative);
    } else {
        diff = _mm_sub_ps(input.desiredVelocity, relative);
    }

    const Vec4 lengthSquared = _mm_dp_ps(diff, diff, 0x7f);
    const float gain = input.gain;
    const float maxVelocityDelta = input.maxVelocityDelta;
    Vec4 scale;
    if (_mm_cvtss_f32(lengthSquared) * (gain * gain) > maxVelocityDelta * maxVelocityDelta) {
        scale = _mm_mul_ps(_mm_set1_ps(maxVelocityDelta), lengthInverse3(diff));
    } else {
        scale = _mm_set1_ps(gain);
    }
    relative = _mm_add_ps(relative, _mm_mul_ps(diff, scale));

    FUN_00010ef0(velocityOut, surfaceFrame, relative);
    velocityOut = _mm_add_ps(velocityOut, input.surfaceVelocity);
}
