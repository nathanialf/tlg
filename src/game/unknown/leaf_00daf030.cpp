/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_scriptcode.h"

/* derived names: slot 41 of the vtable at 0x16bb0c0 (its pointer at 0x16bb218):
 * FUN_00da7410 with 3 and the argument, room checked for three
 * registers, the loop's three hidden variables taken off its count, then
 * the expression and the record of the stack at +0x17c0 popped, the record
 * handed to FUN_013be1a0 */
void FUN_00daf030(CodeGen016bb0c0 *self, int count) /* derived name */
{
    FUN_00da7410(self, 3, count);
    checkStack(self, 3);
    self->functions.top->loops.top->hidden -= 3;
    FUN_013bdca0(&self->functions.top->expressions);
    ScriptFunction016bb0c0 *fs = self->functions.top;
    Pending016bb0c0 *pending = fs->pending.top;
    FUN_013bdfe0(&fs->pending);
    FUN_013be1a0(pending);
}
