/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_compiler00da5b20.h"

/* derived name: copies the function state's int at +0xc44 into the
 * compiler's record at +0x4b8, then pushes an expression
 * (tlg_game_compiler00da5b20.h) */
void FUN_00daa830(Compiler00da5b20 *self) /* derived name */
{
    self->record4b8->unknown84 = self->funcState->unknownc44;
    pushExpression(self->funcState);
}
