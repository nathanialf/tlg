/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_scriptcode.h"

/* derived names: slot 34 of the vtable at 0x16bb0c0 (its pointer at 0x16bb1e0):
 * the numeric for's default step (Lua's fornum): the constant 1
 * loaded into the next register (opcode 0x19), the register taken, the
 * loop's hidden variables counted from 1 */
/* derived name: the constant set with its value before its type, as Lua's
 * setnvalue */
int numberConstant(CodeGen016bb0c0 *self, float number)
{
    Constant016bb0c0 constant;
    constant.number = number;
    constant.type = 3;
    return FUN_00da9130(self, &constant);
}

/* derived name: as setsvalue */
int stringConstant(CodeGen016bb0c0 *self, void *string)
{
    Constant016bb0c0 constant;
    constant.object = string;
    constant.type = 4;
    return FUN_00da9130(self, &constant);
}

void FUN_00daf320(CodeGen016bb0c0 *self) /* derived name */
{
    codeABx(self, 0x19, self->functions.top->freeRegister, numberConstant(self, 1.0f));
    reserveRegisters(self, 1);
    self->functions.top->loops.top->hidden = 1;
}
