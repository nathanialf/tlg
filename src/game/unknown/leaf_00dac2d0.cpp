/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_scriptcode.h"

/* derived names: slot 82 of the vtable at 0x16bb0c0 (its pointer at 0x16bb360):
 * the end of a call's arguments (Lua's funcargs): the arguments'
 * expression popped; unless it leaves open results (kinds 14 and 15) it is
 * put in the next register (when there is one) and the arguments counted
 * from the function's register; the call coded by the function's type (10
 * opcode 3, 9 opcode 2, else 0x1e) and the function's expression made the
 * call (kind 14); the line given stored where the pointer at +0xc20
 * points and the registers above the function's given back */
// NONMATCHING: instruction order only: the base loads the function's pointer at +0x7dc8 before the
// line's reload from its spill slot, the build after
void FUN_00dac2d0(CodeGen016bb0c0 *self, int line) /* derived name */
{
    ScriptFunction016bb0c0 *fs = self->function;
    Expression016bb0c0 *args = fs->expressions.top;
    FUN_013bdca0(&fs->expressions);
    Expression016bb0c0 *f = self->function->expressions.top;
    u32 base = f->info;
    int count;
    if ((args->kind & ~1) == 14) {
        count = -1;
    } else {
        if (args->kind != 0)
            toNextRegister(self, args);
        count = self->function->freeRegister - (base + 1);
    }
    int pc;
    if (f->type == 9)
        pc = code(self, SCRIPT_ABC(2, base, count + 1, 2));
    else if (f->type == 10)
        pc = code(self, SCRIPT_ABC(3, base, count + 1, 2));
    else
        pc = code(self, SCRIPT_ABC(0x1e, base, count + 1, 2));
    initExpression(f, 14, pc, -1);
    *self->function->unknownc20 = line;
    self->function->freeRegister = base + 1;
}
