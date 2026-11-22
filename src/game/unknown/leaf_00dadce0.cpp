/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_scriptcode.h"

/* derived names: slot 63 of the vtable at 0x16bb0c0 (its pointer at 0x16bb2c8):
 * the end of a local function (Lua's localfunc): the expression on
 * top popped and handed to FUN_00da61c0 with the one under it, the last
 * active local live from the current pc, the expression under it popped */
void FUN_00dadce0(CodeGen016bb0c0 *self) /* derived name */
{
    ScriptFunction016bb0c0 *fs = self->functions.top;
    Expression016bb0c0 *popped = fs->expressions.top;
    FUN_013bdca0(&fs->expressions);
    FUN_00da61c0(self, self->functions.top->expressions.top, popped);
    fs = self->functions.top;
    localVariable(fs, fs->activeCount - 1).startPc = fs->code.count;
    FUN_013bdca0(&self->functions.top->expressions);
}
