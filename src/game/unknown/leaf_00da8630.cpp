/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_compiler00da5b20.h"

/* derived name: FUN_00da8700 given the compiler and its expression on top
 * (the body is not written) */
void FUN_00da8700(Compiler00da5b20 *self, u8 *expression);

/* derived names: slot 77 of the vtable at 0x16bb0c0 (FUN_00da8630 and
 * FUN_00daaae0, slots 77 and 118, have this one body): hands the expression
 * on top to FUN_00da8700, then pushes a new one */
void FUN_00da8630(Compiler00da5b20 *self) /* derived name */
{
    FUN_00da8700(self, self->funcState->top);
    pushExpression(self->funcState);
}
