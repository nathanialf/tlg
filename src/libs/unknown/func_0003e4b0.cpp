/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpCharacterStateClimbing::FUN_0003e4b0(hknpCharacterContext &context,
                                              const hknpCharacterInput &input,
                                              hknpCharacterOutput &output)
{
    CharacterMovementInput movement;
    movement.gain = 1.0f;
    movement.forward = input.forward;
    movement.up = input.surfaceNormal;
    movement.surfaceNormal = input.surfaceNormal;
    movement.currentVelocity = input.velocity;
    movement.desiredVelocity =
        _mm_setr_ps(input.inputUD * 10.0f, input.inputLR * 10.0f, -0.1f, 0.0f);
    movement.maxVelocityDelta = 100.0f;
    movement.surfaceVelocity = input.surfaceVelocity;
    FUN_0003bc10(movement, output.velocity);
}
