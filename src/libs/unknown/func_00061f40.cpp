/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING (NOTES Round 64B): every operation and operand is the base's; the schedule
// differs: this compile loads the reciprocal square root's constant first (before the input's
// vectors) and keeps up in xmm9 and the velocity in xmm1, where the base loads the input first
// and holds them the other way.
void Object00061f00::FUN_00061f40(hknpCharacterContext &context, const hknpCharacterInput &input,
                                  hknpCharacterOutput &output)
{
    if (context.FUN_0000b670() != 1) {
        context.FUN_0003e9c0(2, input, output);
        return;
    }
    const Vec4 up = input.up;
    const Vec4 velocity = input.velocity;
    const Vec4 gravitySquared = _mm_dp_ps(input.gravity, input.gravity, 0x7F);
    const Vec4 e = _mm_rsqrt_ps(gravitySquared);
    const Vec4 invLength = _mm_andnot_ps(
        _mm_cmple_ps(gravitySquared, _mm_setzero_ps()),
        _mm_mul_ps(_mm_mul_ps(e, D_14b4360),
                   _mm_sub_ps(D_14b4390, _mm_mul_ps(gravitySquared, _mm_mul_ps(e, e)))));
    const Vec4 gravityLength = _mm_mul_ps(gravitySquared, invLength);
    const Vec4 speedSquared =
        _mm_mul_ps(_mm_mul_ps(gravityLength, D_14b2060[4]), simdFromFloat(hkMath::fabs(valueC)));
    const Vec4 r = _mm_rsqrt_ps(speedSquared);
    const Vec4 jumpSpeed = _mm_andnot_ps(
        _mm_cmple_ps(speedSquared, _mm_setzero_ps()),
        _mm_mul_ps(speedSquared,
                   _mm_mul_ps(_mm_mul_ps(D_14b4360, r),
                              _mm_sub_ps(D_14b4390, _mm_mul_ps(_mm_mul_ps(r, r), speedSquared)))));
    const Vec4 currentSpeed = _mm_dp_ps(_mm_sub_ps(velocity, input.surfaceVelocity), up, 0x7F);
    if (_mm_cvtss_f32(currentSpeed) < _mm_cvtss_f32(jumpSpeed)) {
        output.velocity = _mm_add_ps(velocity, _mm_mul_ps(up, _mm_sub_ps(jumpSpeed, currentSpeed)));
    }
}
