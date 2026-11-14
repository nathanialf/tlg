/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_step00fb5c50.h"

/* derived names: slot 7 of the vtable at 0x16ca6b8: a state object's step. The
 * state follows the input (Stepper00fb5c50::follow), the level slot 8
 * returns (FUN_013e2120 here) is kept at +0x60, and with both of the input's
 * values under the threshold the step ends with 0; else FUN_00fb47e0 runs
 * and it returns 1. Class unknown. */
extern const float D_14db594; /* 1e-5f: each copy of the function reads its own */

void FUN_00fb47e0(Stepper00fb5c50 *self, StepContext00fb5c50 *context);

int FUN_00fb5cf0(Stepper00fb5c50 *self, StepContext00fb5c50 *context) /* derived name */
{
    StepInput00fb5c50 *input = context->input;
    self->follow(input);
    self->unknown60 = self->level(context);
    if (input->records[0].value < D_14db594 && input->records[1].value < D_14db594)
        return 0;
    FUN_00fb47e0(self, context);
    return 1;
}
