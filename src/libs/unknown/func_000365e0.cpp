/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the in-air state's transition: a supported character is on
 * the ground again, one at a ladder starts climbing. */
void hknpCharacterStateInAir::FUN_000365e0(Class16969d0 &context, const hknpCharacterInput &input,
                                           hknpCharacterOutput &output)
{
    if (input.supportedState == 2) {
        context.FUN_0003e9c0(0, input, output);
        return;
    }
    if (input.atLadder) {
        context.FUN_0003e9c0(3, input, output);
    }
}
