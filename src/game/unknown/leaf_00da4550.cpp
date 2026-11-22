/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_scriptcode.h"

/* derived names: slot 2 of the vtable at 0x16bb0c0 (its pointer at 0x16bb0e0):
 * opens the main function (as Lua's luaY_parser and open_func): a state
 * pushed on the stack of functions and made (FUN_00da3370) with the name
 * "(main chunk)", made vararg (2), a table pushed on its script state and
 * its object kept at +0x10, then the instruction 0x12020000 when +0x34 is
 * set */
void FUN_00da4550(CodeGen016bb0c0 *self) /* derived name */
{
    Name016bb0c0 *name =
        FUN_00dd0a60(&self->state->allocator->names, self->state, "(main chunk)", 12);
    FUN_00da3370(self->functions.push(), self->state, self, name);
    self->functions.top->vararg = 2;
    ScriptFunction016bb0c0 *fs = self->functions.top;
    hksi_lua_checkstack(fs->state, 1);
    FUN_00d91880(fs->state, 0, 16);
    fs->unknown10 = topPointer(fs->state);
    if (self->unknown34)
        code(self, 0x12020000);
}
