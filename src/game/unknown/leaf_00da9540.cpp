/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_scriptcode.h"

/* derived names: slot 111 of the vtable at 0x16bb0c0 (its pointer at 0x16bb448):
 * the expression on top put in the next free register, then popped */
void FUN_00da9540(CodeGen016bb0c0 *self) /* derived name */
{
    toNextRegister(self, self->functions.top->expressions.top);
    FUN_013bdca0(&self->functions.top->expressions);
}
