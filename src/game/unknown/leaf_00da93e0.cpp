/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_scriptcode.h"

/* derived names: slot 108 of the vtable at 0x16bb0c0 (its pointer at 0x16bb430):
 * the vararg expression (Lua's simpleexp on TK_DOTS; the message is a
 * fact): an error outside a vararg function, then the expression on top
 * becomes kind 15 over the instruction coded (opcode 0x43, B 1) and the
 * flag for the implicit "arg" is cleared */
void FUN_00da93e0(CodeGen016bb0c0 *self) /* derived name */
{
    if (!self->functions.top->vararg)
        self->lexer->error("cannot use '...' outside a vararg function");
    Expression016bb0c0 *e = self->functions.top->expressions.top;
    initExpression(e, 15, code(self, SCRIPT_ABC(0x43, 0, 1, 0)), -1);
    self->functions.top->vararg &= ~4;
}
