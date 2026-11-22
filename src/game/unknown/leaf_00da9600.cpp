/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_scriptcode.h"

/* derived names: slot 109 of the vtable at 0x16bb0c0 (its pointer at 0x16bb438):
 * an item of an expression list: the expression on top put in the next
 * register, handed to FUN_00da9860, then its declared type pushed on the
 * first stack of the record on top of +0x17c0 (none for -1, a structure's
 * with the structure for 12) */
void FUN_00da9600(CodeGen016bb0c0 *self) /* derived name */
{
    toNextRegister(self, self->functions.top->expressions.top);
    FUN_00da9860(self, self->functions.top->expressions.top);
    ScriptFunction016bb0c0 *fs = self->functions.top;
    Expression016bb0c0 *e = fs->expressions.top;
    if (e->type == -1)
        fs->pending.top->first.push(Slot016bb0c0(-1, 0, 0));
    else if (e->type == 12)
        fs->pending.top->first.push(Slot016bb0c0(12, e->structure, 1));
    else
        fs->pending.top->first.push(Slot016bb0c0(e->type, 0, 1));
}
