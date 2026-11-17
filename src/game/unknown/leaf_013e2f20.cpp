/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_step00fb5c50.h"

/* derived names: slot 4 of the vtable at 0x16d49f8 (whose slot 7 is a step of
 * FUN_00fb5c50's form): the stepper's step over its owner's context, with
 * nothing returned: the state follows the input, the level slot 8 returns
 * is kept at +0x60, and unless both of the input's values are under the
 * threshold FUN_00fb47e0 runs, then FUN_00fb5780. FUN_013e2e70 is the same
 * over the other class of the pair. Class unknown. */
extern const float D_14db86c; /* 1e-5f: each copy reads its own */

void FUN_00fb47e0(Stepper00fb5c50 *self, StepContext00fb5c50 *context);
void FUN_00fb5780(Stepper00fb5c50 *self);

void FUN_013e2f20(Stepper00fb5c50 *self) /* derived name */
{
    StepContext00fb5c50 *context = &self->owner->context;
    StepInput00fb5c50 *input = context->input;
    self->follow(input);
    self->unknown60 = self->level(context);
    if (D_14db86c > input->records[0].value && D_14db86c > input->records[1].value)
        return;
    FUN_00fb47e0(self, context);
    FUN_00fb5780(self);
}
