/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpCharacterStateClimbing::FUN_0003e430(hknpCharacterContext &context,
                                              const hknpCharacterInput &input,
                                              hknpCharacterOutput &output)
{
    if (!input.atLadder) {
        context.FUN_0003e9c0(2, input, output);
        return;
    }
    if (input.wantJump) {
        const Vec4 impulse = _mm_mul_ps(length3(input.gravity), input.surfaceNormal);
        output.velocity = _mm_add_ps(impulse, output.velocity);
        context.FUN_0003e9c0(2, input, output);
    }
}
