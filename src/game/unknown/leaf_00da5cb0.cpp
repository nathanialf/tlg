/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_scriptcode.h"

/* derived names: slot 123 of the vtable at 0x16bb0c0 (its pointer at 0x16bb4a8):
 * an assignment's variable (the message is a fact): the first one (1) is
 * the expression on top, an error unless it is a variable, copied to the
 * stack of variables at +0x1138 and an expression pushed for the next; for
 * the others the variable on top of that stack is checked */
void FUN_00da5cb0(CodeGen016bb0c0 *self, int first) /* derived name */
{
    if (first == 1) {
        if (!isVariable(self->functions.top->expressions.top))
            self->lexer->error(
                "syntax error (non-variable on the right hand side of an assignment)");
        ScriptFunction016bb0c0 *fs = self->functions.top;
        fs->targets.push(*fs->expressions.top);
        self->functions.top->expressions.push();
    } else if (!isVariable(self->functions.top->targets.top)) {
        self->lexer->error("syntax error (non-variable on the right hand side of an assignment)");
    }
}
