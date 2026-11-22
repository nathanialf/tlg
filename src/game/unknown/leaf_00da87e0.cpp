/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_scriptcode.h"

/* derived names: slot 78 of the vtable at 0x16bb0c0 (its pointer at 0x16bb340):
 * the expression on top popped and set to the string constant of the
 * argument (kind 4, type 4; Lua's codestring), handed to FUN_00da88a0 with
 * the one under it */
void FUN_00da87e0(CodeGen016bb0c0 *self, void *string) /* derived name */
{
    ScriptFunction016bb0c0 *fs = self->function;
    Expression016bb0c0 *e = fs->expressions.top;
    FUN_013bdca0(&fs->expressions);
    initExpression(e, 4, stringConstant(self, string), 4);
    FUN_00da88a0(self, self->function->expressions.top, e);
}
