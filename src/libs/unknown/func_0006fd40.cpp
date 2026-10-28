/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_lib_unknown.h"

void hknpCharacterStateOnGround::FUN_0006fd40(hknpCharacterContext &context,
                                              const hknpCharacterInput &input,
                                              hknpCharacterOutput &output)
{
    if (input.wantJump) {
        context.FUN_0003e9c0(1, input, output);
        return;
    }
    if (input.atLadder) {
        context.FUN_0003e9c0(3, input, output);
        return;
    }
    if (input.supportedState != 2) {
        if (killVelocityOnLaunch) {
            const Vec4 upVelocity = _mm_dp_ps(input.up, input.velocity, 0x7f);
            output.velocity = _mm_sub_ps(output.velocity, _mm_mul_ps(input.up, upVelocity));
        }
        context.FUN_0003e9c0(2, input, output);
    }
}
