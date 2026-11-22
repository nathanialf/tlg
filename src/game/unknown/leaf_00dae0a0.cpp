/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_scriptcode.h"

/* derived names: slot 51 of the vtable at 0x16bb0c0 (its pointer at 0x16bb268):
 * the field name of the argument: an entry pushed for it, the
 * expression on top handed to FUN_00da8700, then a string constant key
 * for the name handed to FUN_00da88a0 with it (as Lua's field, checkname
 * and luaK_indexed) */
void FUN_00dae0a0(CodeGen016bb0c0 *self, void *name) /* derived name */
{
    Entry016bb0c0 *entry = self->entries.push();
    entry->value = name;
    entry->unknown8 = 1;
    Expression016bb0c0 *top = self->functions.top->expressions.top;
    FUN_00da8700(self, top);
    Expression016bb0c0 key;
    initExpression(&key, 4, stringConstant(self, name), 4);
    FUN_00da88a0(self, top, &key);
}
