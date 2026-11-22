/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_scriptcode.h"

/* derived names: slot 49 of the vtable at 0x16bb0c0 (its pointer at 0x16bb258):
 * pops the expression on top, hands it to FUN_00da61c0 with the one
 * under it, stores the argument where the pointer at +0xc20 points and pops
 * again */
void FUN_00dadf60(CodeGen016bb0c0 *self, int value) /* derived name */
{
    ScriptFunction016bb0c0 *fs = self->function;
    Expression016bb0c0 *popped = fs->expressions.top;
    FUN_013bdca0(&fs->expressions);
    FUN_00da61c0(self, self->function->expressions.top, popped);
    *self->function->unknownc20 = value;
    FUN_013bdca0(&self->function->expressions);
}
