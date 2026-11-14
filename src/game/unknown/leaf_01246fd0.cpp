/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_step00fb5c50.h"

/* derived names: slot 7 of the vtable at 0x16caaf0: a state object's step. The
 * state follows the input (Stepper00fb5c50::follow), the level slot 8
 * returns (FUN_0147d7f0 here) is kept at +0x60, and with both of the input's
 * values under the threshold the step ends with 0; else FUN_01245b60 runs, then FUN_01246b00,
 * and it returns 1. Class unknown. */
extern const float D_14e1c60; /* 1e-5f: each copy of the function reads its own */

void FUN_01245b60(Stepper00fb5c50 *self, StepContext00fb5c50 *context);
void FUN_01246b00(Stepper00fb5c50 *self);

int FUN_01246fd0(Stepper00fb5c50 *self, StepContext00fb5c50 *context) /* derived name */
{
    StepInput00fb5c50 *input = context->input;
    self->follow(input);
    self->unknown60 = self->level(context);
    if (input->records[0].value < D_14e1c60 && input->records[1].value < D_14e1c60)
        return 0;
    FUN_01245b60(self, context);
    FUN_01246b00(self);
    return 1;
}
