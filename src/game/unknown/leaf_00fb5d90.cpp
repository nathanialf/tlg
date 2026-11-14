/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_step00fb5c50.h"

/* derived names: slot 7 of the vtable at 0x16ca710: a state object's step. The
 * state follows the input (Stepper00fb5c50::follow), the level slot 8
 * returns (FUN_013e21c0 here) is kept at +0x60, and with both of the input's
 * values under the threshold the step ends with 0; else FUN_00fb47e0 runs, then FUN_00fb5780,
 * and it returns 1. Class unknown. */
extern const float D_14db598; /* 1e-5f: each copy of the function reads its own */

void FUN_00fb47e0(Stepper00fb5c50 *self, StepContext00fb5c50 *context);
void FUN_00fb5780(Stepper00fb5c50 *self);

int FUN_00fb5d90(Stepper00fb5c50 *self, StepContext00fb5c50 *context) /* derived name */
{
    StepInput00fb5c50 *input = context->input;
    self->follow(input);
    self->unknown60 = self->level(context);
    if (D_14db598 > input->records[0].value && D_14db598 > input->records[1].value)
        return 0;
    FUN_00fb47e0(self, context);
    FUN_00fb5780(self);
    return 1;
}
