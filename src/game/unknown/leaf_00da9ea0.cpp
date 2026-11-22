/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_scriptcode.h"

/* derived names: slot 93 of the vtable at 0x16bb0c0 (its pointer at 0x16bb3b8):
 * closes a list item of the table constructor (Lua's
 * closelistfield): the item put in the next register and cleared, the
 * pending items stored by FUN_00da9f90 when there are 50 of them */
void FUN_00da9ea0(CodeGen016bb0c0 *self) /* derived name */
{
    Constructor016bb0c0 *cc = self->constructors.top;
    if (cc->item.kind == 0)
        return;
    toNextRegister(self, &cc->item);
    cc->item.kind = 0;
    if (cc->toStore == 50) {
        FUN_00da9f90(self, cc->table->info, cc->listItems, 50);
        cc->toStore = 0;
    }
}
