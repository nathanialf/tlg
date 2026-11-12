/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_compiler00da5b20.h"

/* derived names: slot 64 of the vtable at 0x16bb0c0 (its pointer at
 * 0x16bb2d0): pushes an expression and clears the int at +0x17b0 */
void FUN_00dad190(Compiler00da5b20 *self) /* derived name */
{
    pushExpression(self->funcState);
    self->funcState->unknown17b0 = 0;
}
