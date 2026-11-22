/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_scriptcode.h"

/* derived names: slot 104 of the vtable at 0x16bb0c0 (its pointer at 0x16bb410):
 * an integer literal of the token type given (the messages are facts):
 * 0x400020 an int literal, an error when the options do not enable them,
 * then a constant of type 2; 0x400021 a 60-bit literal, an error always;
 * the expression on top set to the constant (kind 4), nil for the
 * others */
void FUN_00da9020(CodeGen016bb0c0 *self, u64 value, int token) /* derived name */
{
    Constant016bb0c0 constant;
    constant.type = 0;
    constant.integer = 0;
    int type = 0;
    if (token == 0x400020) {
        if (!(self->options & 1))
            self->lexer->error("int literals not enabled in compiler options");
        constant.integer = value;
        constant.type = 2;
        type = 2;
    } else if (token == 0x400021) {
        if (!(self->options & 2))
            self->lexer->error("int literals not enabled in compiler options");
        self->lexer->error("60-bit literal not supported without HKS_UI64API");
    }
    Expression016bb0c0 *e = self->functions.top->expressions.top;
    initExpression(e, 4, FUN_00da9130(self, &constant), type);
}
