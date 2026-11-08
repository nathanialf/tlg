/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpCharacterStateOnGround::FUN_0006fdb0(hknpCharacterContext &context,
                                              const hknpCharacterInput &input,
                                              hknpCharacterOutput &output)
{
    const Vec4 &previousSurfaceVelocity = context.FUN_0003ea80();
    output.inputVelocity = _mm_sub_ps(input.velocity, previousSurfaceVelocity);
    output.inputVelocity = _mm_add_ps(output.inputVelocity, input.surfaceVelocity);

    CharacterMovementInput movement;
    movement.gain = gain;
    movement.forward = input.forward;
    movement.up = input.up;
    movement.surfaceNormal = input.surfaceNormal;
    movement.currentVelocity = output.inputVelocity;
    movement.desiredVelocity =
        _mm_setr_ps(input.inputUD * walkSpeed, input.inputLR * walkSpeed, 0.0f, 0.0f);
    movement.maxVelocityDelta = maxLinearAcceleration * input.deltaTime;
    movement.surfaceVelocity = input.surfaceVelocity;
    FUN_0003bc10(movement, output.velocity);

    const Vec4 deltaTime = _mm_set1_ps(input.deltaTime);
    if (input.surfaceDistanceExcess > 0.0f) {
        const Vec4 normal = input.surfaceNormal;
        const Vec4 pull = _mm_mul_ps(deltaTime, _mm_dp_ps(normal, input.gravity, 0x7f));
        output.velocity = _mm_add_ps(output.velocity, _mm_mul_ps(normal, pull));
    }

    if (limitVerticalVelocity) {
        const Vec4 up = input.up;
        const Vec4 velocity = output.velocity;
        const Vec4 upSpeed = _mm_dp_ps(velocity, up, 0x7f);
        if (_mm_ucomilt_ss(upSpeed, _mm_setzero_ps())) {
            const Vec4 gravityStep = _mm_mul_ps(deltaTime, _mm_dp_ps(up, input.gravity, 0x7f));
            const Vec4 relativeUpSpeed = _mm_sub_ps(upSpeed, _mm_dp_ps(up, input.velocity, 0x7f));
            if (_mm_ucomilt_ss(relativeUpSpeed, gravityStep)) {
                output.velocity =
                    _mm_add_ps(velocity, _mm_mul_ps(up, _mm_sub_ps(gravityStep, relativeUpSpeed)));
            }
        }
    }

    if (!disableHorizontalProjection) {
        output.velocity = _mm_sub_ps(output.velocity, input.surfaceVelocity);
        if (_mm_cvtss_f32(_mm_dp_ps(output.velocity, input.up, 0x7f)) > 0.001f) {
            const Vec4 lengthSquared = _mm_dp_ps(output.velocity, output.velocity, 0x7f);
            const Vec4 e = _mm_rsqrt_ps(lengthSquared);
            const Vec4 invLength =
                _mm_andnot_ps(_mm_cmple_ps(lengthSquared, _mm_setzero_ps()),
                              _mm_mul_ps(_mm_mul_ps(e, _mm_load_ps(D_14b4360)),
                                         _mm_sub_ps(_mm_load_ps(D_14b4390),
                                                    _mm_mul_ps(lengthSquared, _mm_mul_ps(e, e)))));
            output.velocity = _mm_mul_ps(output.velocity, invLength);
            const Vec4 length = _mm_mul_ps(lengthSquared, invLength);
            const Vec4 c = cross3(input.surfaceNormal, output.velocity);
            const Vec4 horizontal = cross3(c, input.up);
            const Vec4 normalUp = _mm_dp_ps(input.surfaceNormal, input.up, 0x7f);
            const Vec4 r = _mm_rcp_ps(normalUp);
            const Vec4 invNormalUp =
                _mm_mul_ps(r, _mm_sub_ps(_mm_load_ps(D_14b4380), _mm_mul_ps(normalUp, r)));
            output.velocity = _mm_mul_ps(_mm_mul_ps(length, invNormalUp), horizontal);
        }
        output.velocity = _mm_add_ps(output.velocity, input.surfaceVelocity);
    }
}
