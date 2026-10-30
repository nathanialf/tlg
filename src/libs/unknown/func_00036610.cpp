/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpCharacterStateInAir::FUN_00036610(hknpCharacterContext &, const hknpCharacterInput &input,
                                           hknpCharacterOutput &output)
{
    CharacterMovementInput movement;
    movement.gain = gain;
    movement.forward = input.forward;
    movement.up = input.up;
    movement.surfaceNormal = input.up;
    movement.currentVelocity = input.velocity;
    movement.desiredVelocity =
        _mm_setr_ps(input.inputUD * airSpeed, input.inputLR * airSpeed, 0.0f, 0.0f);
    movement.maxVelocityDelta = maxLinearAcceleration * input.deltaTime;
    movement.surfaceVelocity = _mm_setzero_ps();
    FUN_0003bc10(movement, output.velocity);
    output.velocity = _mm_sub_ps(output.velocity,
                                 _mm_mul_ps(input.up, _mm_dp_ps(output.velocity, input.up, 0x7F)));
    output.velocity = _mm_add_ps(output.velocity,
                                 _mm_mul_ps(input.up, _mm_dp_ps(input.up, input.velocity, 0x7F)));
    output.velocity =
        _mm_add_ps(output.velocity, _mm_mul_ps(_mm_set1_ps(input.deltaTime), input.gravity));
}
